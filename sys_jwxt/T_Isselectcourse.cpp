// T_Isselectcourse.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "T_Isselectcourse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// T_Isselectcourse

T_Isselectcourse::T_Isselectcourse()
{
	theAdo.OnInitDBConnect("root","ming19910701");
}

T_Isselectcourse::~T_Isselectcourse()
{
	theAdo.ExitConnect();
}


BEGIN_MESSAGE_MAP(T_Isselectcourse, CWnd)
	//{{AFX_MSG_MAP(T_Isselectcourse)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// T_Isselectcourse message handlers

bool T_Isselectcourse::open()
{
	return isselectcourse_update("open");
}

_RecordsetPtr T_Isselectcourse::isselectcourse_select()
{
	CString SQL;
	SQL.Format("SELECT * FROM isselectcourse");
	theAdo.GetRecordset(_bstr_t(SQL));
	return theAdo.m_pRecordset;
}

bool T_Isselectcourse::close()
{
	return isselectcourse_update("close");
}

bool T_Isselectcourse::isopen()
{
	_RecordsetPtr rst;
	rst=isselectcourse_select();
	if((_bstr_t)rst->GetCollect("state")==_bstr_t("open"))
		return true;
	else
		return false;
}

bool T_Isselectcourse::isselectcourse_update(CString str)
{
	CString SQL;
	if(str=="close")
	{
		SQL.Format("UPDATE isselectcourse SET state='%s'",str);
	}
	else if(str=="open")
	{
		SQL.Format("UPDATE isselectcourse SET state='%s'",str);
	}
	if(theAdo.ExecuteSQL((_bstr_t)SQL))
		return true;
	else
		return false;
}

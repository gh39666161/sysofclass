// T_Publish.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "T_Publish.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// T_Publish

T_Publish::T_Publish()
{
	theAdo.OnInitDBConnect("root","ming19910701");
}

T_Publish::~T_Publish()
{
	theAdo.ExitConnect();
}


BEGIN_MESSAGE_MAP(T_Publish, CWnd)
	//{{AFX_MSG_MAP(T_Publish)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// T_Publish message handlers

bool T_Publish::publish_insert(CString text)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	CString time;
	time.Format("%d-%d-%d %d:%d:%d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond);
	CString SQL;
	SQL.Format("INSERT INTO publish (text,time)VALUES('%s','%s')",text,time);
	if(theAdo.ExecuteSQL((_bstr_t)SQL))
	{
		MessageBox("发布成功");
		return true;
	}
	return false;
}

_RecordsetPtr T_Publish::publish_select()
{
	CString SQL;
	SQL.Format("SELECT * FROM publish ORDER BY time DESC");
	theAdo.GetRecordset((_bstr_t)SQL);
	return theAdo.m_pRecordset;
}

bool T_Publish::publish_del()
{
	CString SQL;
	SQL.Format("DELETE FROM publish");
	if(theAdo.ExecuteSQL((_bstr_t)SQL))
	{
		return true;
	}
	else
	{
		return false;
	}
}

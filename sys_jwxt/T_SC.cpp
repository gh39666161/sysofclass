// T_SC.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "T_SC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// T_SC

T_SC::T_SC()
{
	theAdo.OnInitDBConnect("root","ming19910701");
}

T_SC::~T_SC()
{
	theAdo.ExitConnect();
}


BEGIN_MESSAGE_MAP(T_SC, CWnd)
	//{{AFX_MSG_MAP(T_SC)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// T_SC message handlers

_RecordsetPtr T_SC::sc_select(CString col)
{
	CString SQL;
	SQL.Format("SELECT %s FROM sc",col);
	theAdo.GetRecordset(_bstr_t(SQL));
	return theAdo.m_pRecordset;
}

bool T_SC::sc_update(CString c_id, CString s_id, CString score)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString SQL;
	SQL.Format("UPDATE sc SET score=%s WHERE c_id='%s' AND s_id='%s'",score,c_id,s_id);
	rst=sc_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("c_id")==c_id&&(_bstr_t)rst->GetCollect("s_id")==s_id)
		{
			Is_exist=true;
			break;
		}
		rst->MoveNext();
	}
	if(Is_exist)
	{
		if(theAdo.ExecuteSQL(_bstr_t(SQL)))
		{
			return true;
		}
		else
		{
			MessageBox("修改出现错误！","提示",MB_OK);
			return false;
		}
	}
	else
	{
		MessageBox("该记录不存在！","提示",MB_OK);
		return false;
	}
}

bool T_SC::sc_insert(CString c_id, CString s_id, CString score)
{
	_RecordsetPtr rst;
	rst=sc_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("c_id")==c_id&&(_bstr_t)rst->GetCollect("s_id")==s_id)
		{
			MessageBox("该条记录已经存在！","添加失败",MB_OK|MB_ICONSTOP);
			return false;
		}
		rst->MoveNext();
	}
	CString SQL;
	SQL.Format("INSERT INTO sc (c_id,s_id)VALUES('%s','%s')",c_id,s_id);
	if(theAdo.ExecuteSQL(_bstr_t(SQL)))
	{
		return true;
	}
	else
	{
		MessageBox("添加出现错误！","提示",MB_OK);
		return false;
	}
}

bool T_SC::sc_del(CString c_id, CString s_id)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString SQL;
	SQL.Format("DELETE FROM sc WHERE c_id='%s' AND s_id='%s'",c_id,s_id);
	rst=sc_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("c_id")==c_id&&(_bstr_t)rst->GetCollect("s_id")==s_id)
		{
			Is_exist=true;
			break;
		}
		rst->MoveNext();
	}
	if(Is_exist)
	{
		if(theAdo.ExecuteSQL(_bstr_t(SQL)))
		{
			return true;
		}
		else
		{
			MessageBox("删除出现错误！","提示",MB_OK);
			return false;
		}
	}
	else
	{
		MessageBox("该记录不存在！","提示",MB_OK);
		return false;
	}
}

// T_Course.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "T_Course.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// T_Course

T_Course::T_Course()
{
	theAdo.OnInitDBConnect("root","ming19910701");
}

T_Course::~T_Course()
{
	theAdo.ExitConnect();
}


BEGIN_MESSAGE_MAP(T_Course, CWnd)
	//{{AFX_MSG_MAP(T_Course)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// T_Course message handlers

_RecordsetPtr T_Course::course_select(CString col)
{
	CString SQL;
	SQL.Format("SELECT %s FROM course",col);
	theAdo.GetRecordset((_bstr_t)SQL);
	return theAdo.m_pRecordset;
}

bool T_Course::course_insert(CString name, CString tid, CString credit)
{
	CString SQL;
	SQL.Format("INSERT INTO course (name,t_id,credit)VALUES('%s','%s',%s)",name,tid,credit);
	if(theAdo.ExecuteSQL(_bstr_t(SQL)))
	{
		MessageBox("添加排课信息成功！","提示",MB_OK|MB_ICONASTERISK);
		return true;
	}
	else
	{
		MessageBox("添加排课信息失败！","提示",MB_OK|MB_ICONSTOP);
		return false;
	}
}

bool T_Course::course_del(CString id)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString SQL;
	SQL.Format("DELETE FROM course WHERE id='%s'",id);
	rst=course_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("id")==id)
		{
			Is_exist=true;
			break;
		}
		rst->MoveNext();
	}
	if(Is_exist)
	{
		if(theAdo.ExecuteSQL((_bstr_t)SQL))
		{
			MessageBox("删除排课("+id+")信息成功！","提示",MB_OK|MB_ICONASTERISK);
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
		MessageBox("该排课("+id+")信息不存在！","提示",MB_OK);
		return false;
	}
}

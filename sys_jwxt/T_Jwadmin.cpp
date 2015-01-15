// T_Jwadmin.cpp: implementation of the T_Jwadmin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "sys_jwxt.h"
#include "T_Jwadmin.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

T_Jwadmin::T_Jwadmin()
{
	theAdo.OnInitDBConnect("root","ming19910701");
}

T_Jwadmin::~T_Jwadmin()
{
	theAdo.ExitConnect();
}

void T_Jwadmin::jwadmin_insert(CString name,CString pwd)
{
	_RecordsetPtr rst;
	rst=jwadmin_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("name")==name)
		{
			MessageBox("该教务人员id已经存在！","添加失败",MB_OK|MB_ICONSTOP);
			return;
		}
		rst->MoveNext();
	}
	CString SQL;
	SQL.Format("INSERT INTO jwadmin (name,password)VALUES('%s','%s')",name,pwd);
	theAdo.ExecuteSQL(_bstr_t(SQL));
	MessageBox("添加教务人员成功！","提示",MB_OK|MB_ICONASTERISK);
}

_RecordsetPtr T_Jwadmin::jwadmin_select(CString col)
{
	CString SQL;
	SQL.Format("SELECT %s FROM jwadmin",col);
	theAdo.GetRecordset(_bstr_t(SQL));
	return theAdo.m_pRecordset;
}

bool T_Jwadmin::jwadmin_del(CString name)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString SQL;
	SQL.Format("DELETE FROM jwadmin WHERE name='%s'",name);
	rst=jwadmin_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("name")==name)
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
			MessageBox("删除教务人员信息成功！","提示",MB_OK|MB_ICONASTERISK);
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
		MessageBox("该教务人员信息不存在！","提示",MB_OK);
		return false;
	}
}

bool T_Jwadmin::jwadmin_update(CString row,CString name, CString pwd)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString SQL;
	SQL.Format("UPDATE jwadmin SET name='%s',password='%s'WHERE name='%s'",name,pwd,row);
	rst=jwadmin_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("name")==name)
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
			MessageBox("修改教务人员信息成功！","提示",MB_OK|MB_ICONASTERISK);
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
		MessageBox("该教务人员信息不存在！","提示",MB_OK);
		return false;
	}
}

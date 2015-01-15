// T_Teacher.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "T_Teacher.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// T_Teacher

T_Teacher::T_Teacher()
{
	theAdo.OnInitDBConnect("root","ming19910701");
}

T_Teacher::~T_Teacher()
{
	theAdo.ExitConnect();
}


BEGIN_MESSAGE_MAP(T_Teacher, CWnd)
	//{{AFX_MSG_MAP(T_Teacher)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// T_Teacher message handlers

_RecordsetPtr T_Teacher::teacher_select(CString col)
{
	CString SQL;
	SQL.Format("SELECT %s FROM teacher",col);
	theAdo.GetRecordset(_bstr_t(SQL));
	return theAdo.m_pRecordset;
}

bool T_Teacher::teacher_insert(CString id, CString pwd, CString name, CString sex, CString age)
{
	_RecordsetPtr rst;
	rst=teacher_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("id")==id)
		{
			MessageBox("�ý�ʦ("+id+")��Ϣ�Ѿ����ڣ�","���ʧ��",MB_OK|MB_ICONSTOP);
			return false;
		}
		rst->MoveNext();
	}
	CString SQL;
	SQL.Format("INSERT INTO teacher (id,name,password,sex,age)VALUES('%s','%s','%s','%s',%s)",id,name,pwd,sex,age);
	if(theAdo.ExecuteSQL(_bstr_t(SQL)))
	{
		MessageBox("��ӽ�ʦ("+id+")��Ϣ�ɹ���","��ʾ",MB_OK|MB_ICONASTERISK);
		return true;
	}
	else
	{
		MessageBox("��ӳ��ִ���","��ʾ",MB_OK);
		return false;
	}
}

bool T_Teacher::teacher_del(CString row, CString col)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString SQL;
	SQL.Format("DELETE FROM teacher WHERE %s='%s'",col,row);
	rst=teacher_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect((_variant_t)col)==row)
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
			MessageBox("ɾ����ʦ��Ϣ�ɹ���","��ʾ",MB_OK|MB_ICONASTERISK);
			return true;
		}
		else
		{
			MessageBox("ɾ�����ִ���","��ʾ",MB_OK);
			return false;
		}
	}
	else
	{
		MessageBox("�ý�ʦ��Ϣ�����ڣ�","��ʾ",MB_OK);
		return false;
	}
}

bool T_Teacher::teacher_update(CString row, CString col, CString id, CString pwd, CString name, CString sex, CString age)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString change_style;
	CString SQL;
	if(name==""&&sex==""&&age=="")
	{
		SQL.Format("UPDATE teacher SET id='%s',password='%s' WHERE %s='%s'",id,pwd,col,row);
		change_style="password";
	}
	else
	{
		SQL.Format("UPDATE teacher SET id='%s',name='%s',password='%s',sex='%s',age=%s WHERE %s='%s'",id,name,pwd,sex,age,col,row);
		change_style="all";
	}
	rst=teacher_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect((_variant_t)col)==row)
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
			if(change_style=="all")
			{
				MessageBox("�޸Ľ�ʦ��Ϣ�ɹ���","��ʾ",MB_OK|MB_ICONASTERISK);
			}
			else
			{
				MessageBox("�޸�����ɹ���","��ʾ",MB_OK|MB_ICONASTERISK);
			}
			return true;
		}
		else
		{
			MessageBox("�޸ĳ��ִ���","��ʾ",MB_OK);
			return false;
		}
	}
	else
	{
		MessageBox("�ý�ʦ��Ϣ�����ڣ�","��ʾ",MB_OK);
		return false;
	}
}

_RecordsetPtr T_Teacher::teacher_select( _bstr_t id,CString col)
{
	CString SQL;
	SQL.Format("SELECT %s FROM teacher ",col);
	theAdo.GetRecordset(_bstr_t(SQL)+"WHERE id='"+id+"'");
	return theAdo.m_pRecordset;
}

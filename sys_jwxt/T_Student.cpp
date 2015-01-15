// T_Student.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "T_Student.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// T_Student

T_Student::T_Student()
{
	theAdo.OnInitDBConnect("root","ming19910701");
}

T_Student::~T_Student()
{
	theAdo.ExitConnect();
}


BEGIN_MESSAGE_MAP(T_Student, CWnd)
	//{{AFX_MSG_MAP(T_Student)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// T_Student message handlers

bool T_Student::student_insert(CString id, CString pwd, CString name, CString sex, CString age)
{
	_RecordsetPtr rst;
	rst=student_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("id")==id)
		{
			MessageBox("��ѧ��("+id+")��Ϣ�Ѿ����ڣ�","���ʧ��",MB_OK|MB_ICONSTOP);
			return false;
		}
		rst->MoveNext();
	}
	CString SQL;
	SQL.Format("INSERT INTO student (id,password,name,sex,age)VALUES('%s','%s','%s','%s',%s)",id,pwd,name,sex,age);
	if(theAdo.ExecuteSQL(_bstr_t(SQL)))
	{
		MessageBox("���ѧ��("+id+")��Ϣ�ɹ���","��ʾ",MB_OK|MB_ICONASTERISK);
		return true;
	}
	else
	{
		MessageBox("��ӳ��ִ���","��ʾ",MB_OK);
		return false;
	}
}

_RecordsetPtr T_Student::student_select(CString col)
{
	CString SQL;
	SQL.Format("SELECT %s FROM student",col);
	theAdo.GetRecordset(_bstr_t(SQL));
	return theAdo.m_pRecordset;
}

bool T_Student::student_del(CString row, CString col)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString SQL;
	SQL.Format("DELETE FROM student WHERE %s='%s'",col,row);
	rst=student_select();
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
			MessageBox("ɾ��ѧ����Ϣ�ɹ���","��ʾ",MB_OK|MB_ICONASTERISK);
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
		MessageBox("��ѧ����Ϣ�����ڣ�","��ʾ",MB_OK);
		return false;
	}
}

bool T_Student::student_update(CString row, CString col, CString id, CString pwd, CString name, CString sex, CString age)
{
	_RecordsetPtr rst;
	bool Is_exist=false;
	CString SQL;
	CString change_style;
	if(name==""&&sex==""&&age=="")
	{
		change_style="password";
		SQL.Format("UPDATE student SET id='%s',password='%s' WHERE %s='%s'",id,pwd,col,row);
	}
	else
	{
		change_style="all";
		SQL.Format("UPDATE student SET id='%s',password='%s',name='%s',sex='%s',age=%s WHERE %s='%s'",id,pwd,name,sex,age,col,row);
	}
	rst=student_select();
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
				MessageBox("�޸�ѧ����Ϣ�ɹ���","��ʾ",MB_OK|MB_ICONASTERISK);
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
		MessageBox("��ѧ����Ϣ�����ڣ�","��ʾ",MB_OK);
		return false;
	}
}

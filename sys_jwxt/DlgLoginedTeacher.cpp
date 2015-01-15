// DlgLoginedTeacher.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgLoginedTeacher.h"
#include "DlgChangepwd.h"
#include "DlgTchInputscore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedTeacher dialog

extern CString LoginedName;

CDlgLoginedTeacher::CDlgLoginedTeacher(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLoginedTeacher::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLoginedTeacher)
	m_LoginedMessage = _T("");
	//}}AFX_DATA_INIT
}


void CDlgLoginedTeacher::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLoginedTeacher)
	DDX_Control(pDX, IDC_TCH_LIST_COURSE, m_list_course);
	DDX_Text(pDX, IDC_LOGINEDMESSAGE, m_LoginedMessage);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLoginedTeacher, CDialog)
	//{{AFX_MSG_MAP(CDlgLoginedTeacher)
	ON_BN_CLICKED(IDC_BTN_TCH_EXIT, OnBtnTchExit)
	ON_BN_CLICKED(IDC_BTN_TCH_PERSON, OnBtnTchPerson)
	ON_BN_CLICKED(IDC_BTN_TCH_CHANGEPWD, OnBtnTchChangepwd)
	ON_BN_CLICKED(IDC_BTN_TCH_INPUTSCORE, OnBtnTchInputscore)
	ON_LBN_DBLCLK(IDC_TCH_LIST_COURSE, OnDblclkTchListCourse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedTeacher message handlers

void CDlgLoginedTeacher::OnBtnTchExit() 
{
	// TODO: Add your control notification handler code here
	if(MessageBox("是否注销退出系统？","提示",MB_YESNO|MB_ICONQUESTION)==IDYES)
	{
		EndDialog(0);
	}
}

BOOL CDlgLoginedTeacher::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_LoginedMessage=LoginedName+"登录成功";
	UpdateData(false);
	/////////////OUTPUT PUBLISH//////////////////////
	_RecordsetPtr rst;
	t_publish=new T_Publish;
	rst=t_publish->publish_select();
	if(!rst->adoEOF)
	{
		SetDlgItemText(IDC_TCH_SHOWPUB,(_bstr_t)rst->GetCollect("text"));
		SetDlgItemText(IDC_TCH_SHOWPUBTIME,(_bstr_t)rst->GetCollect("time"));
	}
	else
	{
		SetDlgItemText(IDC_TCH_SHOWPUB,"暂时没有公告信息!");
		SetDlgItemText(IDC_TCH_SHOWPUBTIME,"");
	}
	rst=NULL;
	delete t_publish;
	t_publish=NULL;
	//////////////////Table Init///////////////
	t_student=NULL;
	t_teacher=NULL;
	t_course=NULL;
	//////////////////Static Init//////////////
	GetDlgItem(IDC_TCH_PERSON)->ShowWindow(false);
	GetDlgItem(IDC_TCH_ID)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SHOWID)->ShowWindow(false);
	GetDlgItem(IDC_TCH_NAME)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SHOWNAME)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SEX)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SHOWSEX)->ShowWindow(false);
	GetDlgItem(IDC_TCH_AGE)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SHOWAGE)->ShowWindow(false);
	GetDlgItem(IDC_TCH_LIST_COURSE)->ShowWindow(false);
	GetDlgItem(IDC_TCH_HEADER)->ShowWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgLoginedTeacher::OnBtnTchPerson() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_TCH_PERSON)->ShowWindow(true);
	GetDlgItem(IDC_TCH_ID)->ShowWindow(true);
	GetDlgItem(IDC_TCH_SHOWID)->ShowWindow(true);
	GetDlgItem(IDC_TCH_NAME)->ShowWindow(true);
	GetDlgItem(IDC_TCH_SHOWNAME)->ShowWindow(true);
	GetDlgItem(IDC_TCH_SEX)->ShowWindow(true);
	GetDlgItem(IDC_TCH_SHOWSEX)->ShowWindow(true);
	GetDlgItem(IDC_TCH_AGE)->ShowWindow(true);
	GetDlgItem(IDC_TCH_SHOWAGE)->ShowWindow(true);
	GetDlgItem(IDC_TCH_LIST_COURSE)->ShowWindow(false);
	GetDlgItem(IDC_TCH_HEADER)->ShowWindow(false);
	t_teacher=new T_Teacher;
	_RecordsetPtr rst;
	rst=t_teacher->teacher_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("id")==LoginedName)
		{
			SetDlgItemText(IDC_TCH_SHOWID,(_bstr_t)rst->GetCollect("id"));
			SetDlgItemText(IDC_TCH_SHOWNAME,(_bstr_t)rst->GetCollect("name"));
			SetDlgItemText(IDC_TCH_SHOWSEX,(_bstr_t)rst->GetCollect("sex"));
			SetDlgItemText(IDC_TCH_SHOWAGE,(_bstr_t)rst->GetCollect("age"));
			break;
		}
		rst->MoveNext();
	}
	rst=NULL;
	delete t_teacher;
	t_teacher=NULL;
}

void CDlgLoginedTeacher::OnBtnTchChangepwd() 
{
	// TODO: Add your control notification handler code here
	CDlgChangepwd dlg;
	_RecordsetPtr rst;
	bool isright=false;
	if(dlg.DoModal()==IDOK)
	{
		t_teacher=new T_Teacher;
		rst=t_teacher->teacher_select();
		while(!rst->adoEOF)
		{
			if((_bstr_t)rst->GetCollect("id")==LoginedName)
			{
				if((_bstr_t)rst->GetCollect("password")==dlg.m_orginpwd)
				{
					isright=true;
					break;
				}
			}
			rst->MoveNext();
		}
		if(isright)
		{
			t_teacher->teacher_update(LoginedName,"id",LoginedName,dlg.m_newpwd);
		}
		else
		{
			MessageBox("原密码输入错误!","错误",MB_OK|MB_ICONSTOP);
		}
		rst=NULL;
		delete t_teacher;
		t_teacher=NULL;
	}
}

void CDlgLoginedTeacher::OnBtnTchInputscore() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_TCH_PERSON)->ShowWindow(false);
	GetDlgItem(IDC_TCH_ID)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SHOWID)->ShowWindow(false);
	GetDlgItem(IDC_TCH_NAME)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SHOWNAME)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SEX)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SHOWSEX)->ShowWindow(false);
	GetDlgItem(IDC_TCH_AGE)->ShowWindow(false);
	GetDlgItem(IDC_TCH_SHOWAGE)->ShowWindow(false);
	GetDlgItem(IDC_TCH_LIST_COURSE)->ShowWindow(true);
	GetDlgItem(IDC_TCH_HEADER)->ShowWindow(true);
	m_list_course.ResetContent();
	t_course=new T_Course;
	_RecordsetPtr rst;
	rst=t_course->course_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("t_id")==LoginedName)
		{
			m_list_course.AddString((_bstr_t)rst->GetCollect("id")+"-----"+(_bstr_t)rst->GetCollect("name"));
		}
		rst->MoveNext();
	}
	rst=NULL;
	delete t_course;
	t_course=NULL;
}

void CDlgLoginedTeacher::OnDblclkTchListCourse() 
{
	// TODO: Add your control notification handler code here
	int nIndex;
	CString courseid;
	nIndex=m_list_course.GetCurSel();
	m_list_course.GetText(nIndex,courseid);
	courseid=courseid.Left(courseid.Find('-'));
	m_courseselect=courseid;
	CDlgTchInputscore dlg;
	dlg.DoModal();
}

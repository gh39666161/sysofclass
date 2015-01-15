// DlgLoginedStudent.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgLoginedStudent.h"
#include "DlgChangepwd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedStudent dialog

extern CString LoginedName;

CDlgLoginedStudent::CDlgLoginedStudent(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLoginedStudent::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLoginedStudent)
	m_LoginedMessage = _T("");
	//}}AFX_DATA_INIT
}


void CDlgLoginedStudent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLoginedStudent)
	DDX_Control(pDX, IDC_LIST_SCORE, m_list_score);
	DDX_Control(pDX, IDC_LIST_SELECTED, m_list_selected);
	DDX_Control(pDX, IDC_LIST_PRESELECT, m_list_preselect);
	DDX_Text(pDX, IDC_LOGINEDMESSAGE, m_LoginedMessage);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLoginedStudent, CDialog)
	//{{AFX_MSG_MAP(CDlgLoginedStudent)
	ON_BN_CLICKED(IDC_BTN_STU_EXIT, OnBtnStuExit)
	ON_BN_CLICKED(IDC_BTN_STU_PERSON, OnBtnStuPerson)
	ON_BN_CLICKED(IDC_BTN_STU_CHANGEPWD, OnBtnStuChangepwd)
	ON_BN_CLICKED(IDC_BTN_STU_SC, OnBtnStuSc)
	ON_BN_CLICKED(IDC_BTN_ADDCOURSE, OnBtnAddcourse)
	ON_BN_CLICKED(IDC_BTN_DELCOURSE, OnBtnDelcourse)
	ON_BN_CLICKED(IDC_BTN_STU_GETSCORE, OnBtnStuGetscore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedStudent message handlers

void CDlgLoginedStudent::OnBtnStuExit() 
{
	// TODO: Add your control notification handler code here
	if(MessageBox("是否注销退出系统？","提示",MB_YESNO|MB_ICONQUESTION)==IDYES)
	{
		EndDialog(0);
	}
}

BOOL CDlgLoginedStudent::OnInitDialog() 
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
		SetDlgItemText(IDC_STU_SHOWPUB,(_bstr_t)rst->GetCollect("text"));
		SetDlgItemText(IDC_STU_SHOWPUBTIME,(_bstr_t)rst->GetCollect("time"));
	}
	else
	{
		SetDlgItemText(IDC_STU_SHOWPUB,"暂时没有公告信息!");
		SetDlgItemText(IDC_STU_SHOWPUBTIME,"");
	}
	rst=NULL;
	delete t_publish;
	t_publish=NULL;
	//////////////////Table Init///////////////
	t_student=NULL;
	t_sc=NULL;
	t_course=NULL;
	t_teacher=NULL;
	t_isselectcourse=NULL;
	//////////////////Static Init//////////////
	GetDlgItem(IDC_STU_PERSON)->ShowWindow(false);
	GetDlgItem(IDC_STU_ID)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWID)->ShowWindow(false);
	GetDlgItem(IDC_STU_NAME)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWNAME)->ShowWindow(false);
	GetDlgItem(IDC_STU_SEX)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWSEX)->ShowWindow(false);
	GetDlgItem(IDC_STU_AGE)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWAGE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER_ONE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER_TWO)->ShowWindow(false);
	GetDlgItem(IDC_LIST_PRESELECT)->ShowWindow(false);
	GetDlgItem(IDC_LIST_SELECTED)->ShowWindow(false);
	GetDlgItem(IDC_BTN_ADDCOURSE)->ShowWindow(false);
	GetDlgItem(IDC_BTN_DELCOURSE)->ShowWindow(false);
	GetDlgItem(IDC_LIST_SCORE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER)->ShowWindow(false);
	m_list_score.InsertColumn(0,"空",LVCFMT_LEFT,100);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgLoginedStudent::OnBtnStuPerson() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STU_PERSON)->ShowWindow(true);
	GetDlgItem(IDC_STU_ID)->ShowWindow(true);
	GetDlgItem(IDC_STU_SHOWID)->ShowWindow(true);
	GetDlgItem(IDC_STU_NAME)->ShowWindow(true);
	GetDlgItem(IDC_STU_SHOWNAME)->ShowWindow(true);
	GetDlgItem(IDC_STU_SEX)->ShowWindow(true);
	GetDlgItem(IDC_STU_SHOWSEX)->ShowWindow(true);
	GetDlgItem(IDC_STU_AGE)->ShowWindow(true);
	GetDlgItem(IDC_STU_SHOWAGE)->ShowWindow(true);
	GetDlgItem(IDC_STU_HEADER_ONE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER_TWO)->ShowWindow(false);
	GetDlgItem(IDC_LIST_PRESELECT)->ShowWindow(false);
	GetDlgItem(IDC_LIST_SELECTED)->ShowWindow(false);
	GetDlgItem(IDC_BTN_ADDCOURSE)->ShowWindow(false);
	GetDlgItem(IDC_BTN_DELCOURSE)->ShowWindow(false);
	GetDlgItem(IDC_LIST_SCORE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER)->ShowWindow(false);
	/////////////////////////////////////////////////
	t_student=new T_Student;
	_RecordsetPtr rst;
	rst=t_student->student_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("id")==LoginedName)
		{
			SetDlgItemText(IDC_STU_SHOWID,(_bstr_t)rst->GetCollect("id"));
			SetDlgItemText(IDC_STU_SHOWNAME,(_bstr_t)rst->GetCollect("name"));
			SetDlgItemText(IDC_STU_SHOWSEX,(_bstr_t)rst->GetCollect("sex"));
			SetDlgItemText(IDC_STU_SHOWAGE,(_bstr_t)rst->GetCollect("age"));
			break;
		}
		rst->MoveNext();
	}
	rst=NULL;
	delete t_student;
	t_student=NULL;
}

void CDlgLoginedStudent::OnBtnStuChangepwd() 
{
	// TODO: Add your control notification handler code here
	CDlgChangepwd dlg;
	_RecordsetPtr rst;
	bool isright=false;
	if(dlg.DoModal()==IDOK)
	{
		t_student=new T_Student;
		rst=t_student->student_select();
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
			t_student->student_update(LoginedName,"id",LoginedName,dlg.m_newpwd);
		}
		else
		{
			MessageBox("原密码输入错误!","错误",MB_OK|MB_ICONSTOP);
		}
		rst=NULL;
		delete t_student;
		t_student=NULL;
	}
}

void CDlgLoginedStudent::OnBtnStuSc() 
{
	// TODO: Add your control notification handler code here
	t_isselectcourse=new T_Isselectcourse;
	if(!t_isselectcourse->isopen())
	{
		MessageBox("教务人员未开启选课!","提示",MB_OK|MB_ICONWARNING);
		delete t_isselectcourse;
		t_isselectcourse=NULL;
		return;
	}
	GetDlgItem(IDC_STU_PERSON)->ShowWindow(false);
	GetDlgItem(IDC_STU_ID)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWID)->ShowWindow(false);
	GetDlgItem(IDC_STU_NAME)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWNAME)->ShowWindow(false);
	GetDlgItem(IDC_STU_SEX)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWSEX)->ShowWindow(false);
	GetDlgItem(IDC_STU_AGE)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWAGE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER_ONE)->ShowWindow(true);
	GetDlgItem(IDC_STU_HEADER_TWO)->ShowWindow(true);
	GetDlgItem(IDC_LIST_PRESELECT)->ShowWindow(true);
	GetDlgItem(IDC_LIST_SELECTED)->ShowWindow(true);
	GetDlgItem(IDC_BTN_ADDCOURSE)->ShowWindow(true);
	GetDlgItem(IDC_BTN_DELCOURSE)->ShowWindow(true);
	GetDlgItem(IDC_LIST_SCORE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER)->ShowWindow(false);
	///////////////////////////////////////////////////
	m_list_preselect.ResetContent();
	m_list_selected.ResetContent();
	bool isselect=false;
	bool isempty=false;
	t_course=new T_Course;
	t_sc=new T_SC;
	t_teacher=new T_Teacher;
	_RecordsetPtr rst_course,rst_sc,rst_teacher;
	rst_course=t_course->course_select();
	rst_sc=t_sc->sc_select();
	if(rst_sc->adoEOF)
		isempty=true;
	rst_teacher=t_teacher->teacher_select();
	while(!rst_course->adoEOF)
	{
		if(!isempty)
			rst_sc->MoveFirst();
		while(!rst_sc->adoEOF)
		{
			if((_bstr_t)rst_sc->GetCollect("s_id")==LoginedName)
			{
				if((_bstr_t)rst_sc->GetCollect("c_id")==(_bstr_t)rst_course->GetCollect("id"))
				{
					isselect=true;
				}
			}
			rst_sc->MoveNext();
		}
		if(isselect==false)
		{
			while(!rst_teacher->adoEOF)
			{
				if((_bstr_t)rst_teacher->GetCollect("id")==(_bstr_t)rst_course->GetCollect("t_id"))
				{
					m_list_preselect.AddString((_bstr_t)rst_course->GetCollect("id")+"-"+(_bstr_t)rst_course->GetCollect("name")+"-"+(_bstr_t)rst_teacher->GetCollect("name"));
					break;
				}
				rst_teacher->MoveNext();
			}
			rst_teacher->MoveFirst();
			
		}
		else
		{
			while(!rst_teacher->adoEOF)
			{
				if((_bstr_t)rst_teacher->GetCollect("id")==(_bstr_t)rst_course->GetCollect("t_id"))
				{
					m_list_selected.AddString((_bstr_t)rst_course->GetCollect("id")+"-"+(_bstr_t)rst_course->GetCollect("name")+"-"+(_bstr_t)rst_teacher->GetCollect("name"));
					break;
				}
				rst_teacher->MoveNext();
			}
			rst_teacher->MoveFirst();
		}
		isselect=false;
		rst_course->MoveNext();
	}
	rst_course=NULL;
	rst_sc=NULL;
	rst_teacher=NULL;
	delete t_course;
	delete t_sc;
	delete t_teacher;
	t_course=NULL;
	t_sc=NULL;
	t_teacher=NULL;
}

void CDlgLoginedStudent::OnBtnAddcourse() 
{
	// TODO: Add your control notification handler code here
	int index;
	CString courseid;
	index=m_list_preselect.GetCurSel();
	if(index==LB_ERR)
		return;
	m_list_preselect.GetText(index,courseid);
	courseid=courseid.Left(courseid.Find('-'));
	t_sc=new T_SC;
	t_course=new T_Course;
	t_teacher=new T_Teacher;
	bool isselect=false;
	_RecordsetPtr rst_course,rst_sc,rst_teacher;
	t_sc->sc_insert(courseid,LoginedName);
	///////////////////////////////////////
	m_list_preselect.ResetContent();
	m_list_selected.ResetContent();
	///////////////////////////////////////
	bool isempty=false;
	rst_course=t_course->course_select();
	rst_sc=t_sc->sc_select();
	rst_teacher=t_teacher->teacher_select();
	if(rst_sc->adoEOF)
		isempty=true;
	while(!rst_course->adoEOF)
	{
		if(!isempty)
			rst_sc->MoveFirst();
		while(!rst_sc->adoEOF)
		{
			if((_bstr_t)rst_sc->GetCollect("s_id")==LoginedName)
			{
				if((_bstr_t)rst_sc->GetCollect("c_id")==(_bstr_t)rst_course->GetCollect("id"))
				{
					isselect=true;
				}
			}
			rst_sc->MoveNext();
		}
		if(isselect==false)
		{
			while(!rst_teacher->adoEOF)
			{
				if((_bstr_t)rst_teacher->GetCollect("id")==(_bstr_t)rst_course->GetCollect("t_id"))
				{
					m_list_preselect.AddString((_bstr_t)rst_course->GetCollect("id")+"-"+(_bstr_t)rst_course->GetCollect("name")+"-"+(_bstr_t)rst_teacher->GetCollect("name"));
					break;
				}
				rst_teacher->MoveNext();
			}
			rst_teacher->MoveFirst();
			
		}
		else
		{
			while(!rst_teacher->adoEOF)
			{
				if((_bstr_t)rst_teacher->GetCollect("id")==(_bstr_t)rst_course->GetCollect("t_id"))
				{
					m_list_selected.AddString((_bstr_t)rst_course->GetCollect("id")+"-"+(_bstr_t)rst_course->GetCollect("name")+"-"+(_bstr_t)rst_teacher->GetCollect("name"));
					break;
				}
				rst_teacher->MoveNext();
			}
			rst_teacher->MoveFirst();
		}
		isselect=false;
		rst_course->MoveNext();
	}
	rst_course=NULL;
	rst_sc=NULL;
	rst_teacher=NULL;
	delete t_course;
	delete t_sc;
	delete t_teacher;
	t_course=NULL;
	t_sc=NULL;
	t_teacher=NULL;
}

void CDlgLoginedStudent::OnBtnDelcourse() 
{
	// TODO: Add your control notification handler code here
	int index;
	CString courseid;
	index=m_list_selected.GetCurSel();
	if(index==LB_ERR)
		return;
	m_list_selected.GetText(index,courseid);
	courseid=courseid.Left(courseid.Find('-'));
	t_sc=new T_SC;
	t_course=new T_Course;
	t_teacher=new T_Teacher;
	bool isselect=false;
	_RecordsetPtr rst_course,rst_sc,rst_teacher;
	t_sc->sc_del(courseid,LoginedName);
	///////////////////////////////////////
	m_list_preselect.ResetContent();
	m_list_selected.ResetContent();
	///////////////////////////////////////
	bool isempty=false;
	rst_course=t_course->course_select();
	rst_sc=t_sc->sc_select();
	rst_teacher=t_teacher->teacher_select();
	if(rst_sc->adoEOF)
		isempty=true;
	while(!rst_course->adoEOF)
	{
		if(!isempty)
			rst_sc->MoveFirst();
		while(!rst_sc->adoEOF)
		{
			if((_bstr_t)rst_sc->GetCollect("s_id")==LoginedName)
			{
				if((_bstr_t)rst_sc->GetCollect("c_id")==(_bstr_t)rst_course->GetCollect("id"))
				{
					isselect=true;
				}
			}
			rst_sc->MoveNext();
		}
		if(isselect==false)
		{
			while(!rst_teacher->adoEOF)
			{
				if((_bstr_t)rst_teacher->GetCollect("id")==(_bstr_t)rst_course->GetCollect("t_id"))
				{
					m_list_preselect.AddString((_bstr_t)rst_course->GetCollect("id")+"-"+(_bstr_t)rst_course->GetCollect("name")+"-"+(_bstr_t)rst_teacher->GetCollect("name"));
					break;
				}
				rst_teacher->MoveNext();
			}
			rst_teacher->MoveFirst();
			
		}
		else
		{
			while(!rst_teacher->adoEOF)
			{
				if((_bstr_t)rst_teacher->GetCollect("id")==(_bstr_t)rst_course->GetCollect("t_id"))
				{
					m_list_selected.AddString((_bstr_t)rst_course->GetCollect("id")+"-"+(_bstr_t)rst_course->GetCollect("name")+"-"+(_bstr_t)rst_teacher->GetCollect("name"));
					break;
				}
				rst_teacher->MoveNext();
			}
			rst_teacher->MoveFirst();
		}
		isselect=false;
		rst_course->MoveNext();
	}
	rst_course=NULL;
	rst_sc=NULL;
	rst_teacher=NULL;
	delete t_course;
	delete t_sc;
	delete t_teacher;
	t_course=NULL;
	t_sc=NULL;
	t_teacher=NULL;
}

void CDlgLoginedStudent::OnBtnStuGetscore() 
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_STU_PERSON)->ShowWindow(false);
	GetDlgItem(IDC_STU_ID)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWID)->ShowWindow(false);
	GetDlgItem(IDC_STU_NAME)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWNAME)->ShowWindow(false);
	GetDlgItem(IDC_STU_SEX)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWSEX)->ShowWindow(false);
	GetDlgItem(IDC_STU_AGE)->ShowWindow(false);
	GetDlgItem(IDC_STU_SHOWAGE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER_ONE)->ShowWindow(false);
	GetDlgItem(IDC_STU_HEADER_TWO)->ShowWindow(false);
	GetDlgItem(IDC_LIST_PRESELECT)->ShowWindow(false);
	GetDlgItem(IDC_LIST_SELECTED)->ShowWindow(false);
	GetDlgItem(IDC_BTN_ADDCOURSE)->ShowWindow(false);
	GetDlgItem(IDC_BTN_DELCOURSE)->ShowWindow(false);
	GetDlgItem(IDC_LIST_SCORE)->ShowWindow(true);
	GetDlgItem(IDC_STU_HEADER)->ShowWindow(true);
	/////////////////////////////////////////////////
	int index=0,subindex=1;
	int nColumnCount =m_list_score.GetHeaderCtrl()->GetItemCount();
	if(nColumnCount>0)
	{
		m_list_score.DeleteAllItems();
		for (int i=0;i < nColumnCount;i++)
		{
			m_list_score.DeleteColumn(0);
		}
	}
	m_list_score.InsertColumn(0,"课程号",LVCFMT_LEFT,100);
	m_list_score.InsertColumn(1,"课程名",LVCFMT_LEFT,100);
	m_list_score.InsertColumn(2,"成绩",LVCFMT_LEFT,100);
	t_sc=new T_SC;
	t_course=new T_Course;
	_RecordsetPtr rst_sc,rst_course;
	rst_sc=t_sc->sc_select();
	while(!rst_sc->adoEOF)
	{
		rst_course=t_course->course_select();
		while(!rst_course->adoEOF)
		{
			if((_bstr_t)rst_sc->GetCollect("c_id")==(_bstr_t)rst_course->GetCollect("id")&&(_bstr_t)rst_sc->GetCollect("s_id")==LoginedName)
			{
				m_list_score.InsertItem(index,(_bstr_t)rst_sc->GetCollect("c_id"));
				subindex=1;
				m_list_score.SetItemText(index,subindex,(_bstr_t)rst_course->GetCollect("name"));
				subindex++;
				if(rst_sc->GetCollect("score").vt!=VT_NULL)
				{
					m_list_score.SetItemText(index,subindex,(_bstr_t)rst_sc->GetCollect("score"));
				}
				else
				{
					m_list_score.SetItemText(index,subindex,"无成绩");
				}
				index++;
			}
			rst_course->MoveNext();
		}
		rst_sc->MoveNext();
	}
	rst_sc=NULL;
	rst_course=NULL;
	delete t_course;
	delete t_sc;
	t_course=NULL;
	t_sc=NULL;
}

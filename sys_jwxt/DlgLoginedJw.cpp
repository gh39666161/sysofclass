// DlgLoginedJw.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgLoginedJw.h"
#include "DlgJwPublish.h"
#include "DlgSystemUpdatetch.h"
#include "DlgSystemUpdatestu.h"
#include "DlgJwAddcourse.h"
#include "DlgJwDelcourse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedJw dialog
extern CString LoginedName;

CDlgLoginedJw::CDlgLoginedJw(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLoginedJw::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLoginedJw)
	m_loginedmessage = _T("");
	//}}AFX_DATA_INIT
}


void CDlgLoginedJw::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLoginedJw)
	DDX_Control(pDX, IDC_LIST_IMPT, m_list_impt);
	DDX_Text(pDX, IDC_LOGINEDMESSAGE, m_loginedmessage);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLoginedJw, CDialog)
	//{{AFX_MSG_MAP(CDlgLoginedJw)
	ON_BN_CLICKED(IDC_BTN_JW_EXIT, OnBtnJwExit)
	ON_BN_CLICKED(IDC_BTN_JW_IMPT_STUDENT, OnBtnJwImptStudent)
	ON_BN_CLICKED(IDC_BTN_JW_IMPT_TEACHER, OnBtnJwImptTeacher)
	ON_BN_CLICKED(IDC_BTN_JW_PUB, OnBtnJwPub)
	ON_BN_CLICKED(IDC_BTN_JW_SETCOURSE, OnBtnJwSetcourse)
	ON_BN_CLICKED(IDC_BTN_JW_UPDATESTU, OnBtnJwUpdatestu)
	ON_BN_CLICKED(IDC_BTN_JW_UPDATETCH, OnBtnJwUpdatetch)
	ON_BN_CLICKED(IDC_BTN_JW_SWITCH, OnBtnJwSwitch)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_JW_IMPTSTU,OnBtnJwImptstu)
	ON_BN_CLICKED(IDC_BTN_JW_IMPTTCH,OnBtnJwImpttch)
	ON_BN_CLICKED(IDC_BTN_JW_ADDCOURSE,OnBtnJwAddcourse)
	ON_BN_CLICKED(IDC_BTN_JW_DELCOURSE,OnBtnJwDelcourse)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedJw message handlers

void CDlgLoginedJw::OnBtnJwExit() 
{
	// TODO: Add your control notification handler code here
	if(MessageBox("是否注销退出系统？","提示",MB_YESNO|MB_ICONQUESTION)==IDYES)
	{
		EndDialog(0);
	}
}

BOOL CDlgLoginedJw::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	/////////////OUTPUT LOGINMESSAGE/////////////////
	m_loginedmessage=LoginedName+"登录成功";
	UpdateData(false);
	/////////////OUTPUT PUBLISH//////////////////////
	_RecordsetPtr rst;
	t_publish=new T_Publish;
	rst=t_publish->publish_select();
	if(!rst->adoEOF)
	{
		SetDlgItemText(IDC_JW_SHOWPUB,(_bstr_t)rst->GetCollect("text"));
		SetDlgItemText(IDC_JW_SHOWPUBTIME,(_bstr_t)rst->GetCollect("time"));
	}
	else
	{
		SetDlgItemText(IDC_JW_SHOWPUB,"暂时没有公告信息!");
		SetDlgItemText(IDC_JW_SHOWPUBTIME,"");
	}
	rst=NULL;
	delete t_publish;
	t_publish=NULL;
	///////////////Table Init//////////////////////////
	t_teacher=NULL;
	t_student=NULL;
	t_course=NULL;
	t_isselectcourse=NULL;
	///////////////Button Init/////////////////////////
	m_prich_pub=NULL;
	m_pb_imptstu=NULL;
	m_pb_impttch=NULL;
	m_pb_addcourse=NULL;
	m_pb_delcourse=NULL;
	//////////////Other Init///////////////////////////
	SetDlgItemText(IDC_HEADER,"");
	m_list_impt.InsertColumn(0,"init",LVCFMT_LEFT,100);
	m_font=GetFont();
	t_isselectcourse=new T_Isselectcourse;
	CString state;
	if(t_isselectcourse->isopen())
	{
		state="关闭学生选课";
	}
	else
	{
		state="打开学生选课";
	}
	SetDlgItemText(IDC_BTN_JW_SWITCH,state);
	delete t_isselectcourse;
	t_isselectcourse=NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgLoginedJw::OnBtnJwImptStudent() 
{
	// TODO: Add your control notification handler code here
	CFileDialog file(true);
	file.m_ofn.lpstrFilter="TextFiles(*.txt)\0*.txt\0\0";
	file.m_ofn.lpstrDefExt="txt";
	if(IDOK==file.DoModal())
	{
		// Delete all of the columns.
		int nColumnCount =m_list_impt.GetHeaderCtrl()->GetItemCount();
		if(nColumnCount>0)
		{
			m_list_impt.DeleteAllItems();
			for (int i=0;i < nColumnCount;i++)
			{
				m_list_impt.DeleteColumn(0);
			}
		}
		m_list_impt.InsertColumn(0,"学号",LVCFMT_LEFT,100);
		m_list_impt.InsertColumn(1,"密码",LVCFMT_LEFT,90);
		m_list_impt.InsertColumn(2,"姓名",LVCFMT_LEFT,90);
		m_list_impt.InsertColumn(3,"性别",LVCFMT_LEFT,80);
		m_list_impt.InsertColumn(4,"年龄",LVCFMT_LEFT,50);
		CFile stufile(file.GetPathName(),CFile::shareDenyRead|CFile::modeRead);
		char *pBuf;
		DWORD dwFileLen;
		dwFileLen=stufile.GetLength();
		pBuf=new char[100];
		memset(pBuf,0,100);
		for(int i=0,j=0,index=0,cls=0;i<int(dwFileLen);i++)
		{
			stufile.Read(&pBuf[j],1);
			j++;
			if(pBuf[j-1]=='\r')
			{
				pBuf[j-1]='\0';
				m_list_impt.SetItemText(index-1,cls,pBuf);
				cls=0;
				memset(pBuf,0,100);
				j=0;
			}
			if(pBuf[j-1]=='\n')
			{
				memset(pBuf,0,100);
				j=0;
			}
			if(i==int(dwFileLen-1))
			{
				m_list_impt.SetItemText(index-1,cls,pBuf);
				cls=0;
				memset(pBuf,0,100);
				j=0;
			}
			if(pBuf[j-1]==32)
			{
				pBuf[j-1]='\0';
				if(j-1!=0)
				{
					if(cls==0)
					{
						m_list_impt.InsertItem(index,pBuf);
						index++;
						cls++;
					}
					else
					{
						m_list_impt.SetItemText(index-1,cls,pBuf);
						cls++;
					}
				}
				memset(pBuf,0,100);
				j=0;
			}
		}//for
		stufile.Close();
		m_list_impt.ShowWindow(true);
		SetDlgItemText(IDC_HEADER,"批量录入学生信息");
		if(m_pb_impttch)
		{
			m_pb_impttch->DestroyWindow();
			m_pb_impttch=NULL;
		}
		if(m_pb_imptstu)
		{
			m_pb_imptstu->DestroyWindow();
			m_pb_imptstu=NULL;
		}
		if(m_pb_addcourse)
		{
			m_pb_addcourse->DestroyWindow();
			m_pb_addcourse=NULL;
		}
		if(m_pb_delcourse)
		{
			m_pb_delcourse->DestroyWindow();
			m_pb_delcourse=NULL;
		}
		CString imptstu;
		imptstu.LoadString(IDC_BTN_JW_IMPTSTU);
		if(m_pb_imptstu==NULL)
		{
			m_pb_imptstu=new CButton;
			m_pb_imptstu->Create(imptstu,BS_PUSHBUTTON|WS_VISIBLE,CRect(560,404,625,424),this,IDC_BTN_JW_IMPTSTU);
			m_pb_imptstu->SetFont(m_font);
		}
	}
}

void CDlgLoginedJw::OnBtnJwImptTeacher() 
{
	// TODO: Add your control notification handler code here
	CFileDialog file(true);
	file.m_ofn.lpstrFilter="TextFiles(*.txt)\0*.txt\0\0";
	file.m_ofn.lpstrDefExt="txt";
	if(IDOK==file.DoModal())
	{
		// Delete all of the columns.
		int nColumnCount =m_list_impt.GetHeaderCtrl()->GetItemCount();
		if(nColumnCount>0)
		{
			m_list_impt.DeleteAllItems();
			for (int i=0;i < nColumnCount;i++)
			{
				m_list_impt.DeleteColumn(0);
			}
		}
		m_list_impt.InsertColumn(0,"教师号",LVCFMT_LEFT,100);
		m_list_impt.InsertColumn(1,"密码",LVCFMT_LEFT,90);
		m_list_impt.InsertColumn(2,"姓名",LVCFMT_LEFT,90);
		m_list_impt.InsertColumn(3,"性别",LVCFMT_LEFT,80);
		m_list_impt.InsertColumn(4,"年龄",LVCFMT_LEFT,50);
		CFile tchfile(file.GetPathName(),CFile::shareDenyRead|CFile::modeRead);
		char *pBuf;
		DWORD dwFileLen;
		dwFileLen=tchfile.GetLength();
		pBuf=new char[100];
		memset(pBuf,0,100);
		for(int i=0,j=0,index=0,cls=0;i<int(dwFileLen);i++)
		{
			tchfile.Read(&pBuf[j],1);
			j++;
			if(pBuf[j-1]=='\r')
			{
				pBuf[j-1]='\0';
				m_list_impt.SetItemText(index-1,cls,pBuf);
				cls=0;
				memset(pBuf,0,100);
				j=0;
			}
			if(pBuf[j-1]=='\n')
			{
				memset(pBuf,0,100);
				j=0;
			}
			if(i==int(dwFileLen-1))
			{
				m_list_impt.SetItemText(index-1,cls,pBuf);
				cls=0;
				memset(pBuf,0,100);
				j=0;
			}
			if(pBuf[j-1]==32)
			{
				pBuf[j-1]='\0';
				if(j-1!=0)
				{
					if(cls==0)
					{
						m_list_impt.InsertItem(index,pBuf);
						index++;
						cls++;
					}
					else
					{
						m_list_impt.SetItemText(index-1,cls,pBuf);
						cls++;
					}
				}
				memset(pBuf,0,100);
				j=0;
			}
		}//for
		tchfile.Close();
		m_list_impt.ShowWindow(true);
		SetDlgItemText(IDC_HEADER,"批量录入教师信息");
		if(m_pb_impttch)
		{
			m_pb_impttch->DestroyWindow();
			m_pb_impttch=NULL;
		}
		if(m_pb_imptstu)
		{
			m_pb_imptstu->DestroyWindow();
			m_pb_imptstu=NULL;
		}
		if(m_pb_addcourse)
		{
			m_pb_addcourse->DestroyWindow();
			m_pb_addcourse=NULL;
		}
		if(m_pb_delcourse)
		{
			m_pb_delcourse->DestroyWindow();
			m_pb_delcourse=NULL;
		}
		CString impttch;
		impttch.LoadString(IDC_BTN_JW_IMPTTCH);
		if(m_pb_impttch==NULL)
		{
			m_pb_impttch=new CButton;
			m_pb_impttch->Create(impttch,BS_PUSHBUTTON|WS_VISIBLE,CRect(560,404,625,424),this,IDC_BTN_JW_IMPTTCH);
			m_pb_impttch->SetFont(m_font);
		}
	}
}

void CDlgLoginedJw::OnBtnJwPub() 
{
	// TODO: Add your control notification handler code here
	CDlgJwPublish dlg;
	CString text;
	_RecordsetPtr rst;
	if(dlg.DoModal()==IDOK)
	{
		text=dlg.m_richedit_pub;
		t_publish=new T_Publish;
		t_publish->publish_insert(text);
		rst=t_publish->publish_select();
		SetDlgItemText(IDC_JW_SHOWPUB,(_bstr_t)rst->GetCollect("text"));
		SetDlgItemText(IDC_JW_SHOWPUBTIME,(_bstr_t)rst->GetCollect("time"));
		rst=NULL;
		delete t_publish;
		t_publish=NULL;
	}
}

void CDlgLoginedJw::OnBtnJwSetcourse() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_HEADER,"已完成的排课信息");
	if(m_pb_impttch)
	{
		m_pb_impttch->DestroyWindow();
		m_pb_impttch=NULL;
	}
	if(m_pb_imptstu)
	{
		m_pb_imptstu->DestroyWindow();
		m_pb_imptstu=NULL;
	}
	if(m_pb_addcourse)
	{
		m_pb_addcourse->DestroyWindow();
		m_pb_addcourse=NULL;
	}
	if(m_pb_delcourse)
	{
		m_pb_delcourse->DestroyWindow();
		m_pb_delcourse=NULL;
	}
	int nColumnCount =m_list_impt.GetHeaderCtrl()->GetItemCount();
	if(nColumnCount>0)
	{
		m_list_impt.DeleteAllItems();
		for (int i=0;i < nColumnCount;i++)
		{
			m_list_impt.DeleteColumn(0);
		}
	}
	m_list_impt.InsertColumn(0,"课程号",LVCFMT_LEFT,100);
	m_list_impt.InsertColumn(1,"课程名字",LVCFMT_LEFT,90);
	m_list_impt.InsertColumn(2,"教师号",LVCFMT_LEFT,90);
	m_list_impt.InsertColumn(3,"教师名",LVCFMT_LEFT,80);
	m_list_impt.InsertColumn(4,"学分",LVCFMT_LEFT,50);
	m_list_impt.ShowWindow(true);
	t_course=new T_Course;
	t_teacher=new T_Teacher;
	_RecordsetPtr rst_course,rst_teacher;
	int index=0,cls=1;
	rst_course=t_course->course_select();
	while(!rst_course->adoEOF)
	{
		m_list_impt.InsertItem(index,(_bstr_t)rst_course->GetCollect("id"));
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("name"));
		cls++;
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("t_id"));
		cls++;
		rst_teacher=t_teacher->teacher_select((_bstr_t)rst_course->GetCollect("t_id"),"name");
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst_teacher->GetCollect("name"));
		cls++;
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("credit"));
		cls=1;
		index++;
		rst_course->MoveNext();
	}
	rst_course=NULL;
	rst_teacher=NULL;
	delete t_course;
	delete t_teacher;
	t_course=NULL;
	t_teacher=NULL;
	CString addcourse,delcourse;
	addcourse.LoadString(IDC_BTN_JW_ADDCOURSE);
	delcourse.LoadString(IDC_BTN_JW_DELCOURSE);
	if(m_pb_addcourse==NULL)
	{
		m_pb_addcourse=new CButton;
		m_pb_addcourse->Create(addcourse,BS_PUSHBUTTON|WS_VISIBLE,CRect(270,404,400,424),this,IDC_BTN_JW_ADDCOURSE);
		m_pb_addcourse->SetFont(m_font);
	}
	if(m_pb_delcourse==NULL)
	{
		m_pb_delcourse=new CButton;
		m_pb_delcourse->Create(delcourse,BS_PUSHBUTTON|WS_VISIBLE,CRect(480,404,600,424),this,IDC_BTN_JW_DELCOURSE);
		m_pb_delcourse->SetFont(m_font);
	}
}

void CDlgLoginedJw::OnBtnJwAddcourse()
{
	CDlgJwAddcourse dlg;
	_RecordsetPtr rst;
	CString tid,name,credit;
	bool isexist=false;
	bool isexisttid=false;
	if(dlg.DoModal()==IDOK)
	{
		tid=dlg.m_tid;
		name=dlg.m_name;
		credit=dlg.m_credit;
		t_teacher=new T_Teacher;
		rst=t_teacher->teacher_select();
		while(!rst->adoEOF)
		{
			if((_bstr_t)rst->GetCollect("id")==tid)
			{
				isexisttid=true;
				break;
			}
			rst->MoveNext();
		}
		if(!isexisttid)
		{
			MessageBox("教师信息不存在!","添加失败",MB_OK|MB_ICONSTOP);
			rst=NULL;
			delete t_teacher;
			t_teacher=NULL;
			return;
		}
		else
		{
			t_course=new T_Course;
			rst=t_course->course_select();
			while(!rst->adoEOF)
			{
				if((_bstr_t)rst->GetCollect("name")==name&&(_bstr_t)rst->GetCollect("t_id")==tid)
				{
					MessageBox("该条排课记录已经存在!","提示",MB_OK|MB_ICONINFORMATION);
					isexist=true;
					break;
				}
				rst->MoveNext();
			}
			if(!isexist)
			{
				t_course->course_insert(name,tid,credit);
				m_list_impt.DeleteAllItems();
				_RecordsetPtr rst_course,rst_teacher;
				int index=0,cls=1;
				rst_course=t_course->course_select();
				while(!rst_course->adoEOF)
				{
					m_list_impt.InsertItem(index,(_bstr_t)rst_course->GetCollect("id"));
					m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("name"));
					cls++;
					m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("t_id"));
					cls++;
					rst_teacher=t_teacher->teacher_select((_bstr_t)rst_course->GetCollect("t_id"),"name");
					m_list_impt.SetItemText(index,cls,(_bstr_t)rst_teacher->GetCollect("name"));
					cls++;
					m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("credit"));
					cls=1;
					index++;
					rst_course->MoveNext();
				}
				rst_course=NULL;
				rst_teacher=NULL;
			}	
			delete t_course;
			delete t_teacher;
			t_course=NULL;
			t_teacher=NULL;
			rst=NULL;
		}
	}
}

void CDlgLoginedJw::OnBtnJwDelcourse()
{
	CDlgJwDelcourse dlg;
	CString id;
	if(dlg.DoModal()==IDOK)
	{
		id=dlg.m_id;
		t_course=new T_Course;
		t_teacher=new T_Teacher;
		t_course->course_del(id);
		m_list_impt.DeleteAllItems();
		_RecordsetPtr rst_course,rst_teacher;
		int index=0,cls=1;
		rst_course=t_course->course_select();
		while(!rst_course->adoEOF)
		{
			m_list_impt.InsertItem(index,(_bstr_t)rst_course->GetCollect("id"));
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("name"));
			cls++;
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("t_id"));
			cls++;
			rst_teacher=t_teacher->teacher_select((_bstr_t)rst_course->GetCollect("t_id"),"name");
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst_teacher->GetCollect("name"));
			cls++;
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst_course->GetCollect("credit"));
			cls=1;
			index++;
			rst_course->MoveNext();
		}
		rst_course=NULL;
		rst_teacher=NULL;
		delete t_course;
		delete t_teacher;
		t_course=NULL;
		t_teacher=NULL;
	}
}

void CDlgLoginedJw::OnBtnJwUpdatestu() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_HEADER,"修改学生信息");
	if(m_pb_impttch)
	{
		m_pb_impttch->DestroyWindow();
		m_pb_impttch=NULL;
	}
	if(m_pb_imptstu)
	{
		m_pb_imptstu->DestroyWindow();
		m_pb_imptstu=NULL;
	}
	if(m_pb_addcourse)
	{
		m_pb_addcourse->DestroyWindow();
		m_pb_addcourse=NULL;
	}
	if(m_pb_delcourse)
	{
		m_pb_delcourse->DestroyWindow();
		m_pb_delcourse=NULL;
	}
	int nColumnCount =m_list_impt.GetHeaderCtrl()->GetItemCount();
	if(nColumnCount>0)
	{
		m_list_impt.DeleteAllItems();
		for (int i=0;i < nColumnCount;i++)
		{
			m_list_impt.DeleteColumn(0);
		}
	}
	m_list_impt.InsertColumn(0,"学号",LVCFMT_LEFT,100);
	m_list_impt.InsertColumn(1,"密码",LVCFMT_LEFT,90);
	m_list_impt.InsertColumn(2,"姓名",LVCFMT_LEFT,90);
	m_list_impt.InsertColumn(3,"性别",LVCFMT_LEFT,80);
	m_list_impt.InsertColumn(4,"年龄",LVCFMT_LEFT,50);
	m_list_impt.ShowWindow(true);
	t_student=new T_Student;
	_RecordsetPtr rst;
	int index=0,cls=1;
	rst=t_student->student_select();
	while(!rst->adoEOF)
	{
		m_list_impt.InsertItem(index,(_bstr_t)rst->GetCollect("id"));
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("password"));
		cls++;
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("name"));
		cls++;
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("sex"));
		cls++;
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("age"));
		cls=1;
		index++;
		rst->MoveNext();
	}
	CDlgSystemUpdatestu dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_list_impt.DeleteAllItems();
		index=0;
		rst=t_student->student_select();
		while(!rst->adoEOF)
		{
			m_list_impt.InsertItem(index,(_bstr_t)rst->GetCollect("id"));
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("password"));
			cls++;
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("name"));
			cls++;
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("sex"));
			cls++;
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("age"));
			cls=1;
			index++;
			rst->MoveNext();
		}
	}
	rst=NULL;
	delete t_student;
	t_student=NULL;
}

void CDlgLoginedJw::OnBtnJwUpdatetch() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_HEADER,"修改教师信息");
	if(m_pb_impttch)
	{
		m_pb_impttch->DestroyWindow();
		m_pb_impttch=NULL;
	}
	if(m_pb_imptstu)
	{
		m_pb_imptstu->DestroyWindow();
		m_pb_imptstu=NULL;
	}
	if(m_pb_addcourse)
	{
		m_pb_addcourse->DestroyWindow();
		m_pb_addcourse=NULL;
	}
	if(m_pb_delcourse)
	{
		m_pb_delcourse->DestroyWindow();
		m_pb_delcourse=NULL;
	}
	int nColumnCount =m_list_impt.GetHeaderCtrl()->GetItemCount();
	if(nColumnCount>0)
	{
		m_list_impt.DeleteAllItems();
		for (int i=0;i < nColumnCount;i++)
		{
			m_list_impt.DeleteColumn(0);
		}
	}
	m_list_impt.InsertColumn(0,"教师号",LVCFMT_LEFT,100);
	m_list_impt.InsertColumn(1,"密码",LVCFMT_LEFT,90);
	m_list_impt.InsertColumn(2,"姓名",LVCFMT_LEFT,90);
	m_list_impt.InsertColumn(3,"性别",LVCFMT_LEFT,80);
	m_list_impt.InsertColumn(4,"年龄",LVCFMT_LEFT,50);
	m_list_impt.ShowWindow(true);
	t_teacher=new T_Teacher;
	_RecordsetPtr rst;
	int index=0,cls=1;
	rst=t_teacher->teacher_select();
	while(!rst->adoEOF)
	{
		m_list_impt.InsertItem(index,(_bstr_t)rst->GetCollect("id"));
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("password"));
		cls++;
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("name"));
		cls++;
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("sex"));
		cls++;
		m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("age"));
		cls=1;
		index++;
		rst->MoveNext();
	}
	CDlgSystemUpdatetch dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_list_impt.DeleteAllItems();
		index=0;
		rst=t_teacher->teacher_select();
		while(!rst->adoEOF)
		{
			m_list_impt.InsertItem(index,(_bstr_t)rst->GetCollect("id"));
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("password"));
			cls++;
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("name"));
			cls++;
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("sex"));
			cls++;
			m_list_impt.SetItemText(index,cls,(_bstr_t)rst->GetCollect("age"));
			cls=1;
			index++;
			rst->MoveNext();
		}
	}
	rst=NULL;
	delete t_teacher;
	t_teacher=NULL;
}

void CDlgLoginedJw::OnBtnJwImptstu()
{
	t_student=new T_Student;
	int index=0,count;
	CString id,name,pwd,sex,age;
	count=m_list_impt.GetItemCount();
	for(index=0;index<count;index++)
	{
		id=m_list_impt.GetItemText(index,0);
		pwd=m_list_impt.GetItemText(index,1);
		name=m_list_impt.GetItemText(index,2);
		sex=m_list_impt.GetItemText(index,3);
		age=m_list_impt.GetItemText(index,4);
		t_student->student_insert(id,pwd,name,sex,age);
	}
	delete t_student;
	t_student=NULL;
}

void CDlgLoginedJw::OnBtnJwImpttch()
{
	t_teacher=new T_Teacher;
	int index=0,count;
	CString id,name,pwd,sex,age;
	count=m_list_impt.GetItemCount();
	for(index=0;index<count;index++)
	{
		id=m_list_impt.GetItemText(index,0);
		pwd=m_list_impt.GetItemText(index,1);
		name=m_list_impt.GetItemText(index,2);
		sex=m_list_impt.GetItemText(index,3);
		age=m_list_impt.GetItemText(index,4);
		t_teacher->teacher_insert(id,pwd,name,sex,age);
	}
	delete t_teacher;
	t_teacher=NULL;
}

void CDlgLoginedJw::OnBtnJwSwitch() 
{
	// TODO: Add your control notification handler code here
	t_isselectcourse=new T_Isselectcourse;
	if(t_isselectcourse->isopen())
	{
		t_isselectcourse->close();
		SetDlgItemText(IDC_BTN_JW_SWITCH,"打开学生选课");
	}
	else
	{
		t_isselectcourse->open();
		SetDlgItemText(IDC_BTN_JW_SWITCH,"关闭学生选课");
	}
	delete t_isselectcourse;
	t_isselectcourse=NULL;
}

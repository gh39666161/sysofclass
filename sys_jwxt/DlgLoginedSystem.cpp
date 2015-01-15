// DlgLoginedSystem.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgLoginedSystem.h"
#include "DlgSystemAddjw.h"
#include "DlgSystemDeljw.h"
#include "DlgSystemUpdatejw.h"
#include "DlgSystemAddtch.h"
#include "DlgSystemDeltch.h"
#include "DlgSystemUpdatetch.h"
#include "DlgSystemAddstu.h"
#include "DlgSystemDelstu.h"
#include "DlgSystemUpdatestu.h"
#include "DlgJwPublish.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedSystem dialog

extern CString LoginedName;
CDlgLoginedSystem::CDlgLoginedSystem(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLoginedSystem::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLoginedSystem)
	m_LoginedMessage = _T("");
	//}}AFX_DATA_INIT
}


void CDlgLoginedSystem::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLoginedSystem)
	DDX_Text(pDX, IDC_LOGINEDMESSAGE, m_LoginedMessage);
	DDX_Control(pDX, IDC_DATAGRID_MESG, m_datagrid_mesg);
	DDX_Control(pDX, IDC_SYS_ADODC, m_sys_adodc);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLoginedSystem, CDialog)
	//{{AFX_MSG_MAP(CDlgLoginedSystem)
	ON_BN_CLICKED(IDC_BTN_SYS_EXIT, OnBtnSysExit)
	ON_BN_CLICKED(IDC_BTN_SYS_JW, OnBtnSysJw)
	ON_BN_CLICKED(IDC_BTN_SYS_TCH, OnBtnSysTch)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_SYS_PUB, OnBtnSysPub)
	ON_BN_CLICKED(IDC_BTN_SYS_STU, OnBtnSysStu)
	ON_BN_CLICKED(IDC_BTN_SYS_DELPUBLOG, OnBtnSysDelpublog)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_SYS_ADDJW,OnBtnSysAddjw)
	ON_BN_CLICKED(IDC_BTN_SYS_UPDATEJW,OnBtnSysUpdatejw)
	ON_BN_CLICKED(IDC_BTN_SYS_DELJW,OnBtnSysDeljw)
	ON_BN_CLICKED(IDC_BTN_SYS_ADDTCH,OnBtnSysAddtch)
	ON_BN_CLICKED(IDC_BTN_SYS_UPDATETCH,OnBtnSysUpdatetch)
	ON_BN_CLICKED(IDC_BTN_SYS_DELTCH,OnBtnSysDeltch)
	ON_BN_CLICKED(IDC_BTN_SYS_ADDSTU,OnBtnSysAddstu)
	ON_BN_CLICKED(IDC_BTN_SYS_UPDATESTU,OnBtnSysUpdatestu)
	ON_BN_CLICKED(IDC_BTN_SYS_DELSTU,OnBtnSysDelstu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedSystem message handlers

void CDlgLoginedSystem::OnBtnSysExit() 
{
	// TODO: Add your control notification handler code here
	if(MessageBox("是否注销退出系统？","提示",MB_YESNO|MB_ICONQUESTION)==IDYES)
	{
		EndDialog(0);
	}
}

BOOL CDlgLoginedSystem::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_LoginedMessage=LoginedName+"登录成功";
	UpdateData(false);
	GetDlgItem(IDC_DATAGRID_MESG)->ShowWindow(false);
	/////////////OUTPUT PUBLISH//////////////////////
	_RecordsetPtr rst;
	t_publish=new T_Publish;
	rst=t_publish->publish_select();
	if(!rst->adoEOF)
	{
		SetDlgItemText(IDC_SYS_SHOWPUB,(_bstr_t)rst->GetCollect("text"));
		SetDlgItemText(IDC_SYS_SHOWPUBTIME,(_bstr_t)rst->GetCollect("time"));
	}
	else
	{
		SetDlgItemText(IDC_SYS_SHOWPUB,"没有公告信息");
		SetDlgItemText(IDC_SYS_SHOWPUBTIME,"");
	}
	rst=NULL;
	delete t_publish;
	t_publish=NULL;
	////////////Button Init//////////////////////////
	m_pb_addjw=NULL;
	m_pb_updatejw=NULL;
	m_pb_deljw=NULL;
	m_pb_addtch=NULL;
	m_pb_updatetch=NULL;
	m_pb_deltch=NULL;
	m_pb_addstu=NULL;
	m_pb_updatestu=NULL;
	m_pb_delstu=NULL;
	m_font=GetFont();
	////////////////Table Init///////////////////////
	t_student=NULL;
	t_teacher=NULL;
	t_jwadmin=NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgLoginedSystem::OnBtnSysAddjw()
{
	CDlgSystemAddjw dlg;
	CString name(""),pwd("");
	if(dlg.DoModal()==IDOK)
	{
		name=dlg.m_id;
		pwd=dlg.m_pwd;
		t_jwadmin=new T_Jwadmin;
		t_jwadmin->jwadmin_insert(name,pwd);
		delete t_jwadmin;
		t_jwadmin=NULL;
		m_sys_adodc.Refresh();
	}
	_variant_t index=long(0);
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(187);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(200);
}

void CDlgLoginedSystem::OnBtnSysUpdatejw()
{
	CDlgSystemUpdatejw dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_sys_adodc.Refresh();
	}
	_variant_t index=long(0);
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(187);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(200);
}

void CDlgLoginedSystem::OnBtnSysDeljw()
{
	CDlgSystemDeljw dlg;
	CString name("");
	if(dlg.DoModal()==IDOK)
	{
		name=dlg.m_id;
		t_jwadmin=new T_Jwadmin;
		t_jwadmin->jwadmin_del(name);
		delete t_jwadmin;
		t_jwadmin=NULL;
		m_sys_adodc.Refresh();
	}
	_variant_t index=long(0);
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(187);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(200);
}

void CDlgLoginedSystem::OnBtnSysAddtch()
{
	_variant_t index=long(0);
	CDlgSystemAddtch dlg;
	CString id(""),name(""),password(""),sex(""),age("");
	if(dlg.DoModal()==IDOK)
	{
		id=dlg.m_id;
		name=dlg.m_name;
		password=dlg.m_pwd;
		sex=dlg.m_sex;
		age=dlg.m_age;
		t_teacher=new T_Teacher;
		t_teacher->teacher_insert(id,password,name,sex,age);
		delete t_teacher;
		t_teacher=NULL;
		m_sys_adodc.Refresh();
	}
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(87);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(2);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(3);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	index=long(4);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
}

void CDlgLoginedSystem::OnBtnSysUpdatetch()
{
	CDlgSystemUpdatetch dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_sys_adodc.Refresh();
	}
	_variant_t index=long(0);
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(87);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(2);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(3);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	index=long(4);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
}

void CDlgLoginedSystem::OnBtnSysDeltch()
{
	_variant_t index=long(0);
	CDlgSystemDeltch dlg;
	CString delitem(""),delmsg("");
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_delitem=="按教师号")
		{
			delitem="id";
		}
		else
			delitem="name";
		delmsg=dlg.m_delmsg;
		t_teacher=new T_Teacher;
		t_teacher->teacher_del(delmsg,delitem);
		delete t_teacher;
		t_teacher=NULL;
		m_sys_adodc.Refresh();
	}
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(87);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(2);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(3);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	index=long(4);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
}

void CDlgLoginedSystem::OnBtnSysAddstu()
{
	_variant_t index=long(0);
	CDlgSystemAddstu dlg;
	CString id(""),name(""),password(""),sex(""),age("");
	if(dlg.DoModal()==IDOK)
	{
		id=dlg.m_id;
		name=dlg.m_name;
		password=dlg.m_pwd;
		sex=dlg.m_sex;
		age=dlg.m_age;
		t_student=new T_Student;
		t_student->student_insert(id,password,name,sex,age);
		delete t_student;
		t_student=NULL;
		m_sys_adodc.Refresh();
	}
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(87);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(2);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(3);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	index=long(4);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
}

void CDlgLoginedSystem::OnBtnSysUpdatestu()
{
	CDlgSystemUpdatestu dlg;
	if(dlg.DoModal()==IDOK)
	{
		m_sys_adodc.Refresh();
	}
	_variant_t index=long(0);
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(87);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(2);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(3);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	index=long(4);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
}

void CDlgLoginedSystem::OnBtnSysDelstu()
{
	_variant_t index=long(0);
	CDlgSystemDelstu dlg;
	CString delitem(""),delmsg("");
	if(dlg.DoModal()==IDOK)
	{
		if(dlg.m_delitem=="按学号")
		{
			delitem="id";
		}
		else
			delitem="name";
		delmsg=dlg.m_delmsg;
		t_student=new T_Student;
		t_student->student_del(delmsg,delitem);
		delete t_student;
		t_student=NULL;
		m_sys_adodc.Refresh();
	}
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(87);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(2);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(3);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	index=long(4);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
}

void CDlgLoginedSystem::OnBtnSysJw() 
{
	// TODO: Add your control notification handler code here
	m_sys_adodc.SetRecordSource("select name AS '帐号',password AS '密码' from jwadmin");
	m_sys_adodc.Refresh();
	_variant_t index=long(0);
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(187);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(200);
	GetDlgItem(IDC_DATAGRID_MESG)->ShowWindow(true);
////////////////////////////////////////////////
//            对按钮的操作                    //
////////////////////////////////////////////////
	if(m_pb_addtch)
	{
		m_pb_addtch->DestroyWindow();
		m_pb_addtch=NULL;
	}
	if(m_pb_deltch)
	{
		m_pb_deltch->DestroyWindow();
		m_pb_deltch=NULL;
	}
	if(m_pb_updatetch)
	{
		m_pb_updatetch->DestroyWindow();
		m_pb_updatetch=NULL;
	}
	if(m_pb_addstu)
	{
		m_pb_addstu->DestroyWindow();
		m_pb_addstu=NULL;
	}
	if(m_pb_delstu)
	{
		m_pb_delstu->DestroyWindow();
		m_pb_delstu=NULL;
	}
	if(m_pb_updatestu)
	{
		m_pb_updatestu->DestroyWindow();
		m_pb_updatestu=NULL;
	}
	CString addjw,updatejw,deljw;
	addjw.LoadString(IDC_BTN_SYS_ADDJW);
	updatejw.LoadString(IDC_BTN_SYS_UPDATEJW);
	deljw.LoadString(IDC_BTN_SYS_DELJW);
	m_pb_addjw=new CButton;
	m_pb_updatejw=new CButton;
	m_pb_deljw=new CButton;
	m_pb_addjw->Create(addjw,BS_PUSHBUTTON|WS_VISIBLE,CRect(230,420,350,450),this,IDC_BTN_SYS_ADDJW);
	m_pb_addjw->SetFont(m_font);
	m_pb_updatejw->Create(updatejw,BS_PUSHBUTTON|WS_VISIBLE,CRect(410,420,530,450),this,IDC_BTN_SYS_UPDATEJW);
	m_pb_updatejw->SetFont(m_font);
	m_pb_deljw->Create(deljw,BS_PUSHBUTTON|WS_VISIBLE,CRect(590,420,710,450),this,IDC_BTN_SYS_DELJW);
	m_pb_deljw->SetFont(m_font);
}

void CDlgLoginedSystem::OnBtnSysTch() 
{
	// TODO: Add your control notification handler code here
	_variant_t index=long(0);
	m_sys_adodc.SetRecordSource("select id AS '教师号',name AS '姓名',password AS '密码',sex AS '性别',age AS '年龄' from teacher");
	m_sys_adodc.Refresh();
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(87);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(2);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(3);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	index=long(4);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	GetDlgItem(IDC_DATAGRID_MESG)->ShowWindow(true);
////////////////////////////////////////////////
//            对按钮的操作                    //
////////////////////////////////////////////////
	if(m_pb_addjw)
	{
		m_pb_addjw->DestroyWindow();
		m_pb_addjw=NULL;
	}
	if(m_pb_deljw)
	{
		m_pb_deljw->DestroyWindow();
		m_pb_deljw=NULL;
	}
	if(m_pb_updatejw)
	{
		m_pb_updatejw->DestroyWindow();
		m_pb_updatejw=NULL;
	}
	if(m_pb_addstu)
	{
		m_pb_addstu->DestroyWindow();
		m_pb_addstu=NULL;
	}
	if(m_pb_delstu)
	{
		m_pb_delstu->DestroyWindow();
		m_pb_delstu=NULL;
	}
	if(m_pb_updatestu)
	{
		m_pb_updatestu->DestroyWindow();
		m_pb_updatestu=NULL;
	}
	m_pb_addtch=new CButton;
	m_pb_updatetch=new CButton;
	m_pb_deltch=new CButton;
	CString addtch,updatetch,deltch;
	addtch.LoadString(IDC_BTN_SYS_ADDTCH);
	updatetch.LoadString(IDC_BTN_SYS_UPDATETCH);
	deltch.LoadString(IDC_BTN_SYS_DELTCH);
	m_pb_addtch->Create(addtch,BS_PUSHBUTTON|WS_VISIBLE,CRect(230,420,350,450),this,IDC_BTN_SYS_ADDTCH);
	m_pb_addtch->SetFont(m_font);
	m_pb_updatetch->Create(updatetch,BS_PUSHBUTTON|WS_VISIBLE,CRect(410,420,530,450),this,IDC_BTN_SYS_UPDATETCH);
	m_pb_updatetch->SetFont(m_font);
	m_pb_deltch->Create(deltch,BS_PUSHBUTTON|WS_VISIBLE,CRect(590,420,710,450),this,IDC_BTN_SYS_DELTCH);
	m_pb_deltch->SetFont(m_font);
}

int CDlgLoginedSystem::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	return 0;
}

void CDlgLoginedSystem::OnBtnSysPub() 
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
		SetDlgItemText(IDC_SYS_SHOWPUB,(_bstr_t)rst->GetCollect("text"));
		SetDlgItemText(IDC_SYS_SHOWPUBTIME,(_bstr_t)rst->GetCollect("time"));
		rst=NULL;
		delete t_publish;
		t_publish=NULL;
	}
}

void CDlgLoginedSystem::OnBtnSysStu() 
{
	// TODO: Add your control notification handler code here
	_variant_t index=long(0);
	m_sys_adodc.SetRecordSource("select id AS '学号',name AS '姓名',password AS '密码',sex AS '性别',age AS '年龄' from student");
	m_sys_adodc.Refresh();
	CColumns cols=m_datagrid_mesg.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(87);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(2);
	Item=cols.GetItem(index);
	Item.SetWidth(105);
	index=long(3);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	index=long(4);
	Item=cols.GetItem(index);
	Item.SetWidth(45);
	GetDlgItem(IDC_DATAGRID_MESG)->ShowWindow(true);
////////////////////////////////////////////////
//            对按钮的操作                    //
////////////////////////////////////////////////
	if(m_pb_addjw)
	{
		m_pb_addjw->DestroyWindow();
		m_pb_addjw=NULL;
	}
	if(m_pb_deljw)
	{
		m_pb_deljw->DestroyWindow();
		m_pb_deljw=NULL;
	}
	if(m_pb_updatejw)
	{
		m_pb_updatejw->DestroyWindow();
		m_pb_updatejw=NULL;
	}
	if(m_pb_addtch)
	{
		m_pb_addtch->DestroyWindow();
		m_pb_addtch=NULL;
	}
	if(m_pb_deltch)
	{
		m_pb_deltch->DestroyWindow();
		m_pb_deltch=NULL;
	}
	if(m_pb_updatetch)
	{
		m_pb_updatetch->DestroyWindow();
		m_pb_updatetch=NULL;
	}
	m_pb_addstu=new CButton;
	m_pb_updatestu=new CButton;
	m_pb_delstu=new CButton;
	CString addstu,updatestu,delstu;
	addstu.LoadString(IDC_BTN_SYS_ADDSTU);
	updatestu.LoadString(IDC_BTN_SYS_UPDATESTU);
	delstu.LoadString(IDC_BTN_SYS_DELSTU);
	m_pb_addstu->Create(addstu,BS_PUSHBUTTON|WS_VISIBLE,CRect(230,420,350,450),this,IDC_BTN_SYS_ADDSTU);
	m_pb_addstu->SetFont(m_font);
	m_pb_updatestu->Create(updatestu,BS_PUSHBUTTON|WS_VISIBLE,CRect(410,420,530,450),this,IDC_BTN_SYS_UPDATESTU);
	m_pb_updatestu->SetFont(m_font);
	m_pb_delstu->Create(delstu,BS_PUSHBUTTON|WS_VISIBLE,CRect(590,420,710,450),this,IDC_BTN_SYS_DELSTU);
	m_pb_delstu->SetFont(m_font);
}

void CDlgLoginedSystem::OnBtnSysDelpublog() 
{
	// TODO: Add your control notification handler code here
	t_publish=new T_Publish;
	if(t_publish->publish_del())
	{
		MessageBox("删除历史公告信息完成!","提示",MB_OK|MB_ICONINFORMATION);
		SetDlgItemText(IDC_SYS_SHOWPUB,"没有公告信息");
		SetDlgItemText(IDC_SYS_SHOWPUBTIME,"");
	}
	else
	{
		MessageBox("删除历史公告失败!","错误",MB_OK|MB_ICONSTOP);
	}
	delete t_publish;
	t_publish=NULL;
}

// sys_jwxtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "sys_jwxtDlg.h"
#include "DlgSysWelcome.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSys_jwxtDlg dialog
extern CString LoginedName;
CSys_jwxtDlg::CSys_jwxtDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSys_jwxtDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSys_jwxtDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAIN);
}

void CSys_jwxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSys_jwxtDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSys_jwxtDlg, CDialog)
	//{{AFX_MSG_MAP(CSys_jwxtDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDR_USER_STUDENT, OnUserStudent)
	ON_BN_CLICKED(IDR_USER_SYSTEM, OnUserSystem)
	ON_BN_CLICKED(IDR_USER_TEACHER, OnUserTeacher)
	ON_BN_CLICKED(IDR_USER_JW, OnUserJw)
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)
	ON_BN_CLICKED(IDC_BTN_LOGIN, OnBtnLogin)
	ON_BN_CLICKED(IDC_BTN_SKIN, OnBtnSkin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSys_jwxtDlg message handlers

BOOL CSys_jwxtDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CDlgSysWelcome dlg;
	dlg.DoModal();
	m_user="";
	t_teacher=NULL;
	t_admin=NULL;
	t_jwadmin=NULL;
	t_student=NULL;
	m_pDlgJw=NULL;
	m_pDlgStudent=NULL;
	m_pDlgSystem=NULL;
	m_pDlgTeacher=NULL;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSys_jwxtDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSys_jwxtDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSys_jwxtDlg::OnUserStudent() 
{
	// TODO: Add your control notification handler code here
	m_user="student";
}

void CSys_jwxtDlg::OnUserSystem() 
{
	// TODO: Add your control notification handler code here
	m_user="system";
}

void CSys_jwxtDlg::OnUserTeacher() 
{
	// TODO: Add your control notification handler code here
	m_user="teacher";
}

void CSys_jwxtDlg::OnUserJw() 
{
	// TODO: Add your control notification handler code here
	m_user="jw";
}

void CSys_jwxtDlg::OnBtnExit() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}

void CSys_jwxtDlg::OnBtnLogin() 
{
	// TODO: Add your control notification handler code here
	int logined=0;
	_RecordsetPtr rst;
	CString name,pwd;
	UpdateData(true);
	if(m_user=="jw")
	{
		GetDlgItemText(IDC_EDIT_LOGINID,name);
		GetDlgItemText(IDC_EDIT_LOGINPWD,pwd);
		t_jwadmin=new T_Jwadmin;
		rst=t_jwadmin->jwadmin_select();
		while(!rst->adoEOF)
		{
			if((_bstr_t)rst->GetCollect("name")==name&&(_bstr_t)rst->GetCollect("password")==pwd)
			{
				logined=1;
				LoginedName=name;
				break;
			}
			rst->MoveNext();
		}
		rst=NULL;
		delete t_jwadmin;
		if(logined==1)
		{
			ShowWindow(SW_HIDE);
			m_pDlgJw=new CDlgLoginedJw;
			m_pDlgJw->DoModal();
			ShowWindow(SW_SHOW);
		}
		else
		{
			MessageBox("’ ∫≈≤ª¥Ê‘⁄£°","µ«¬º¥ÌŒÛ",MB_OK|MB_ICONSTOP);
		}
	}
	if(m_user=="teacher")
	{
		GetDlgItemText(IDC_EDIT_LOGINID,name);
		GetDlgItemText(IDC_EDIT_LOGINPWD,pwd);
		t_teacher=new T_Teacher;
		rst=t_teacher->teacher_select();
		while(!rst->adoEOF)
		{
			if((_bstr_t)rst->GetCollect("id")==name&&(_bstr_t)rst->GetCollect("password")==pwd)
			{
				logined=1;
				LoginedName=name;
				break;
			}
			rst->MoveNext();
		}
		rst=NULL;
		delete t_teacher;
		if(logined==1)
		{
			ShowWindow(SW_HIDE);
			m_pDlgTeacher=new CDlgLoginedTeacher;
			m_pDlgTeacher->DoModal();
			ShowWindow(SW_SHOW);
		}
		else
		{
			MessageBox("’ ∫≈≤ª¥Ê‘⁄£°","µ«¬º¥ÌŒÛ",MB_OK|MB_ICONSTOP);
		}
	}
	if(m_user=="system")
	{
		GetDlgItemText(IDC_EDIT_LOGINID,name);
		GetDlgItemText(IDC_EDIT_LOGINPWD,pwd);
		t_admin=new T_Admin;
		rst=t_admin->admin_select();
		while(!rst->adoEOF)
		{
			if((_bstr_t)rst->GetCollect("name")==name&&(_bstr_t)rst->GetCollect("password")==pwd)
			{
				logined=1;
				LoginedName=name;
				break;
			}
			rst->MoveNext();
		}
		rst=NULL;
		delete t_admin;
		if(logined==1)
		{
			ShowWindow(SW_HIDE);
			m_pDlgSystem=new CDlgLoginedSystem;
			m_pDlgSystem->DoModal();
			ShowWindow(SW_SHOW);
		}
		else
		{
			MessageBox("’ ∫≈≤ª¥Ê‘⁄£°","µ«¬º¥ÌŒÛ",MB_OK|MB_ICONSTOP);
		}
	}
	if(m_user=="student")
	{
		GetDlgItemText(IDC_EDIT_LOGINID,name);
		GetDlgItemText(IDC_EDIT_LOGINPWD,pwd);
		t_student=new T_Student;
		rst=t_student->student_select();
		while(!rst->adoEOF)
		{
			if((_bstr_t)rst->GetCollect("id")==name&&(_bstr_t)rst->GetCollect("password")==pwd)
			{
				logined=1;
				LoginedName=name;
				break;
			}
			rst->MoveNext();
		}
		rst=NULL;
		delete t_student;
		if(logined==1)
		{
			ShowWindow(SW_HIDE);
			m_pDlgStudent=new CDlgLoginedStudent;
			m_pDlgStudent->DoModal();
			ShowWindow(SW_SHOW);
		}
		else
		{
			MessageBox("’ ∫≈≤ª¥Ê‘⁄£°","µ«¬º¥ÌŒÛ",MB_OK|MB_ICONSTOP);
		}
	}
	if(m_user=="")
	{
		MessageBox("«Î—°‘Ò”√ªß¿‡–Õ£°","µ«¬º¥ÌŒÛ",MB_OK|MB_ICONWARNING);
	}
}

void CSys_jwxtDlg::OnBtnSkin() 
{
	// TODO: Add your control notification handler code here
	static int i=1;
	i++;
	if(i%2==0)
	{
		VERIFY( 1 == LoadSkinFromResource(NULL,"IDR_SKIN_DEVIOR","skin"));
	}
	else
	{
		VERIFY( 1 == LoadSkinFromResource(NULL,"IDR_SKIN_KROMOBLUE","skin"));
	}
	ShowWindow(SW_NORMAL);
}

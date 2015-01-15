// DlgChangepwd.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgChangepwd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgChangepwd dialog


CDlgChangepwd::CDlgChangepwd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgChangepwd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgChangepwd)
	m_newpwd = _T("");
	m_orginpwd = _T("");
	m_repeatpwd = _T("");
	//}}AFX_DATA_INIT
}


void CDlgChangepwd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgChangepwd)
	DDX_Text(pDX, IDC_EDIT_NEWPWD, m_newpwd);
	DDV_MaxChars(pDX, m_newpwd, 12);
	DDX_Text(pDX, IDC_EDIT_ORGINPWD, m_orginpwd);
	DDV_MaxChars(pDX, m_orginpwd, 12);
	DDX_Text(pDX, IDC_EDIT_REPEATPWD, m_repeatpwd);
	DDV_MaxChars(pDX, m_repeatpwd, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgChangepwd, CDialog)
	//{{AFX_MSG_MAP(CDlgChangepwd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgChangepwd message handlers

void CDlgChangepwd::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_orginpwd==""||m_newpwd==""||m_repeatpwd=="")
	{
		MessageBox("密码不能为空!","提示",MB_OK|MB_ICONWARNING);
		return;
	}
	if(m_newpwd!=m_repeatpwd)
	{
		MessageBox("新密码两次输入不同，重新输入!","提示",MB_OK|MB_ICONWARNING);
		return;
	}
	CDialog::OnOK();
}

void CDlgChangepwd::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

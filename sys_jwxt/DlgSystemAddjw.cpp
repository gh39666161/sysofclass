// DlgSystemAddjw.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgSystemAddjw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemAddjw dialog


CDlgSystemAddjw::CDlgSystemAddjw(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSystemAddjw::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSystemAddjw)
	m_id = _T("");
	m_pwd = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSystemAddjw::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSystemAddjw)
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDV_MaxChars(pDX, m_id, 12);
	DDX_Text(pDX, IDC_EDIT_PWD, m_pwd);
	DDV_MaxChars(pDX, m_pwd, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSystemAddjw, CDialog)
	//{{AFX_MSG_MAP(CDlgSystemAddjw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemAddjw message handlers

void CDlgSystemAddjw::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDlgSystemAddjw::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_id==""||m_pwd=="")
	{
		MessageBox("填写信息有误!","提示");
		return;
	}
	CDialog::OnOK();
}

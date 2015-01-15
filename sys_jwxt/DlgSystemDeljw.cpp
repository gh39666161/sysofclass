// DlgSystemDeljw.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgSystemDeljw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDeljw dialog


CDlgSystemDeljw::CDlgSystemDeljw(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSystemDeljw::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSystemDeljw)
	m_id = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSystemDeljw::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSystemDeljw)
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDV_MaxChars(pDX, m_id, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSystemDeljw, CDialog)
	//{{AFX_MSG_MAP(CDlgSystemDeljw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDeljw message handlers

void CDlgSystemDeljw::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDlgSystemDeljw::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_id=="")
	{
		MessageBox("输入有误!","提示");
		return;
	}
	CDialog::OnOK();
}

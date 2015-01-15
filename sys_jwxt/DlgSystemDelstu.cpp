// DlgSystemDelstu.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgSystemDelstu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDelstu dialog


CDlgSystemDelstu::CDlgSystemDelstu(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSystemDelstu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSystemDelstu)
	m_delmsg = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSystemDelstu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSystemDelstu)
	DDX_Control(pDX, IDC_COMBO_DELITEM, m_combo_delitem);
	DDX_Text(pDX, IDC_EDIT_DELMSG, m_delmsg);
	DDV_MaxChars(pDX, m_delmsg, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSystemDelstu, CDialog)
	//{{AFX_MSG_MAP(CDlgSystemDelstu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDelstu message handlers

BOOL CDlgSystemDelstu::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO_DELITEM))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSystemDelstu::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDlgSystemDelstu::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	int index=m_combo_delitem.GetCurSel();
	m_combo_delitem.GetLBText(index,m_delitem);
	if(m_delitem=="")
	{
		MessageBox("«Î—°‘Ò…æ≥˝œÓ£°","¥ÌŒÛ",MB_OK);
	}
	if(m_delmsg=="")
	{
		MessageBox("«Î ‰»Î…æ≥˝–≈œ¢£°","¥ÌŒÛ",MB_OK);
	}
	CDialog::OnOK();
}

// DlgSystemDeltch.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgSystemDeltch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDeltch dialog


CDlgSystemDeltch::CDlgSystemDeltch(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSystemDeltch::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSystemDeltch)
	m_delmsg = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSystemDeltch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSystemDeltch)
	DDX_Control(pDX, IDC_COMBO_DELITEM, m_combo_delitem);
	DDX_Text(pDX, IDC_EDIT_DELMSG, m_delmsg);
	DDV_MaxChars(pDX, m_delmsg, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSystemDeltch, CDialog)
	//{{AFX_MSG_MAP(CDlgSystemDeltch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDeltch message handlers

void CDlgSystemDeltch::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDlgSystemDeltch::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	int index=m_combo_delitem.GetCurSel();
	m_combo_delitem.GetLBText(index,m_delitem);
	if(m_delitem=="")
	{
		MessageBox("ÇëÑ¡ÔñÉ¾³ýÏî£¡","´íÎó",MB_OK);
	}
	if(m_delmsg=="")
	{
		MessageBox("ÇëÊäÈëÉ¾³ýÐÅÏ¢£¡","´íÎó",MB_OK);
	}
	CDialog::OnOK();
}

BOOL CDlgSystemDeltch::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	((CComboBox*)GetDlgItem(IDC_COMBO_DELITEM))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

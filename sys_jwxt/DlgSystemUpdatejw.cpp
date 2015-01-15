// DlgSystemUpdatejw.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgSystemUpdatejw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemUpdatejw dialog


CDlgSystemUpdatejw::CDlgSystemUpdatejw(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSystemUpdatejw::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSystemUpdatejw)
	m_change = _T("");
	m_id = _T("");
	m_pwd = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSystemUpdatejw::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSystemUpdatejw)
	DDX_Control(pDX, IDOK, m_btn_ok);
	DDX_Control(pDX, IDC_BTN_CHANGE, m_btn_change);
	DDX_Text(pDX, IDC_EDIT_CHANGE, m_change);
	DDV_MaxChars(pDX, m_change, 12);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDV_MaxChars(pDX, m_id, 12);
	DDX_Text(pDX, IDC_EDIT_PWD, m_pwd);
	DDV_MaxChars(pDX, m_pwd, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSystemUpdatejw, CDialog)
	//{{AFX_MSG_MAP(CDlgSystemUpdatejw)
	ON_BN_CLICKED(IDC_BTN_CHANGE, OnBtnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemUpdatejw message handlers

void CDlgSystemUpdatejw::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDlgSystemUpdatejw::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_id==""||m_pwd=="")
	{
		MessageBox("输入有误!","错误!",MB_OK);
		return;
	}
	if(!t_jwadmin.jwadmin_update(m_change,m_id,m_pwd))
	{
		return;
	}
	CDialog::OnOK();
}

void CDlgSystemUpdatejw::OnBtnChange() 
{
	// TODO: Add your control notification handler code here
	CString str;
	_RecordsetPtr rst;
	UpdateData(true);
	if(GetDlgItemText(IDC_BTN_CHANGE,str),str=="修改>>")
	{
		SetDlgItemText(IDC_BTN_CHANGE,"取消<<");
		m_btn_ok.EnableWindow(true);
		SetWindowPos(NULL,0,0,m_large.Width(),m_large.Height(),SWP_NOMOVE|SWP_NOZORDER);
		GetDlgItem(IDC_EDIT_CHANGE)->EnableWindow(false);
		rst=t_jwadmin.jwadmin_select();
		while(!rst->adoEOF)
		{
			if((_bstr_t)rst->GetCollect("name")==m_change)
			{
				SetDlgItemText(IDC_EDIT_ID,(_bstr_t)rst->GetCollect("name"));
				SetDlgItemText(IDC_EDIT_PWD,(_bstr_t)rst->GetCollect("password"));
				break;
			}
			rst->MoveNext();
		}
	}
	else
	{
		SetDlgItemText(IDC_BTN_CHANGE,"修改>>");
		m_btn_ok.EnableWindow(false);
		SetWindowPos(NULL,0,0,m_small.Width(),m_small.Height(),SWP_NOMOVE|SWP_NOZORDER);
		GetDlgItem(IDC_EDIT_CHANGE)->EnableWindow(true);
	}
}

BOOL CDlgSystemUpdatejw::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect broken;
	m_btn_ok.EnableWindow(false);
	GetWindowRect(&m_large);
	GetDlgItem(IDC_STATIC_BROKEN)->GetWindowRect(&broken);
	m_small.top=m_large.top;
	m_small.left=m_large.left;
	m_small.bottom=m_large.bottom;
	m_small.right=broken.right;
	SetWindowPos(NULL,0,0,m_small.Width(),m_small.Height(),SWP_NOMOVE|SWP_NOZORDER);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

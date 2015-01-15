// DlgSystemUpdatestu.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgSystemUpdatestu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemUpdatestu dialog


CDlgSystemUpdatestu::CDlgSystemUpdatestu(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSystemUpdatestu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSystemUpdatestu)
	m_age = _T("");
	m_changemsg = _T("");
	m_id = _T("");
	m_name = _T("");
	m_pwd = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSystemUpdatestu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSystemUpdatestu)
	DDX_Control(pDX, IDOK, m_b_ok);
	DDX_Control(pDX, IDC_COMBO_SEX, m_combo_sex);
	DDX_Control(pDX, IDC_COMBO_CHANGEITEM, m_combo_changeitem);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDV_MaxChars(pDX, m_age, 3);
	DDX_Text(pDX, IDC_EDIT_CHANGEMSG, m_changemsg);
	DDV_MaxChars(pDX, m_changemsg, 12);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDV_MaxChars(pDX, m_id, 12);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 12);
	DDX_Text(pDX, IDC_EDIT_PWD, m_pwd);
	DDV_MaxChars(pDX, m_pwd, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSystemUpdatestu, CDialog)
	//{{AFX_MSG_MAP(CDlgSystemUpdatestu)
	ON_BN_CLICKED(IDC_BTN_CHANGE, OnBtnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemUpdatestu message handlers

BOOL CDlgSystemUpdatestu::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rectbroken;
	GetWindowRect(&m_large);
	GetDlgItem(IDC_BROKEN)->GetWindowRect(&rectbroken);
	m_small.top=m_large.top;
	m_small.left=m_large.left;
	m_small.bottom=m_large.bottom;
	m_small.right=rectbroken.right;
	SetWindowPos(NULL,0,0,m_small.Width(),m_small.Height(),SWP_NOMOVE|SWP_NOZORDER);
	((CComboBox*)GetDlgItem(IDC_COMBO_CHANGEITEM))->SetCurSel(0);
	((CComboBox*)GetDlgItem(IDC_COMBO_SEX))->SetCurSel(0);
	m_b_ok.EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSystemUpdatestu::OnBtnChange() 
{
	// TODO: Add your control notification handler code here
	CString str;
	CString changeitem;
	GetDlgItemText(IDC_BTN_CHANGE,str);
	_RecordsetPtr rst;
	if(str=="修改>>")
	{
		SetDlgItemText(IDC_BTN_CHANGE,"取消<<");
		SetWindowPos(NULL,0,0,m_large.Width(),m_large.Height(),SWP_NOMOVE|SWP_NOZORDER);
		m_b_ok.EnableWindow(true);
		UpdateData();
		m_combo_changeitem.EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_CHANGEMSG))->EnableWindow(false);
		m_combo_changeitem.GetLBText(m_combo_changeitem.GetCurSel(),changeitem);
		if(changeitem=="按学号")
		{
			changeitem="id";
		}
		else
		{
			changeitem="name";
		}
		rst=t_student.student_select();
		while(!rst->adoEOF)
		{
			if((_bstr_t)rst->GetCollect((_variant_t)changeitem)==m_changemsg)
			{
				SetDlgItemText(IDC_EDIT_ID,(_bstr_t)rst->GetCollect("id"));
				SetDlgItemText(IDC_EDIT_PWD,(_bstr_t)rst->GetCollect("password"));
				SetDlgItemText(IDC_EDIT_NAME,(_bstr_t)rst->GetCollect("name"));
				SetDlgItemText(IDC_EDIT_AGE,(_bstr_t)rst->GetCollect("age"));
				if((_bstr_t)rst->GetCollect("sex")==_bstr_t("男"))
				{
					m_combo_sex.SetCurSel(0);
				}
				else
				{
					m_combo_sex.SetCurSel(1);
				}
				break;
			}
			rst->MoveNext();
		}
	}
	else
	{
		SetDlgItemText(IDC_BTN_CHANGE,"修改>>");
		SetWindowPos(NULL,0,0,m_small.Width(),m_small.Height(),SWP_NOMOVE|SWP_NOZORDER);
		m_b_ok.EnableWindow(false);
		((CEdit*)GetDlgItem(IDC_EDIT_CHANGEMSG))->EnableWindow(true);
		m_combo_changeitem.EnableWindow(true);
	}
}

void CDlgSystemUpdatestu::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CString changeitem,sex;
	m_combo_changeitem.GetLBText(m_combo_changeitem.GetCurSel(),changeitem);
	m_combo_sex.GetLBText(m_combo_sex.GetCurSel(),sex);
	if(changeitem=="按学号")
	{
		changeitem="id";
	}
	else
	{
		changeitem="name";
	}
	if(m_id==""||m_name==""||m_pwd==""||sex==""||m_age=="")
	{
		MessageBox("输入有误!","错误!",MB_OK);
		return;
	}
	if(!t_student.student_update(m_changemsg,changeitem,m_id,m_pwd,m_name,sex,m_age))
	{
		return;
	}
	CDialog::OnOK();
}

void CDlgSystemUpdatestu::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

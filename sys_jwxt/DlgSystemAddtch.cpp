// DlgSystemAddtch.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgSystemAddtch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemAddtch dialog


CDlgSystemAddtch::CDlgSystemAddtch(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSystemAddtch::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSystemAddtch)
	m_age = _T("");
	m_id = _T("");
	m_name = _T("");
	m_pwd = _T("");
	//}}AFX_DATA_INIT
	m_sex="";
}


void CDlgSystemAddtch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSystemAddtch)
	DDX_Control(pDX, IDC_COMBO_SEX, m_combox_sex);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDV_MaxChars(pDX, m_age, 3);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDV_MaxChars(pDX, m_id, 12);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 12);
	DDX_Text(pDX, IDC_EDIT_PWD, m_pwd);
	DDV_MaxChars(pDX, m_pwd, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSystemAddtch, CDialog)
	//{{AFX_MSG_MAP(CDlgSystemAddtch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemAddtch message handlers

void CDlgSystemAddtch::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	int index=m_combox_sex.GetCurSel();
	m_combox_sex.GetLBText(index,m_sex);
	CString str;
	str=m_age;
	bool isnum=true;
	for(int i=0;i<str.GetLength();i++)
	{
		if(!isdigit(str.GetAt(i)))
			isnum=false;
	}
	if(!isnum)
	{
		MessageBox("ÄêÁäÌîÐ´´íÎó£¡","ÌîÐ´´íÎó");
		return;
	}
	if(m_id=="")
	{
		MessageBox("½ÌÊ¦ºÅÌîÐ´´íÎó£¡","ÌîÐ´´íÎó");
		return;
	}
	if(m_name=="")
	{
		MessageBox("½ÌÊ¦ÐÕÃûÌîÐ´´íÎó£¡","ÌîÐ´´íÎó");
		return;
	}
	if(m_sex=="")
	{
		MessageBox("½ÌÊ¦ÐÔ±ðÌîÐ´´íÎó£¡","ÌîÐ´´íÎó");
		return;
	}
	CDialog::OnOK();
}

void CDlgSystemAddtch::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

BOOL CDlgSystemAddtch::OnInitDialog() 
{
	CDialog::OnInitDialog();
	((CComboBox*)GetDlgItem(IDC_COMBO_SEX))->SetCurSel(0);
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

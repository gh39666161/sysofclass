// DlgJwAddcourse.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgJwAddcourse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgJwAddcourse dialog


CDlgJwAddcourse::CDlgJwAddcourse(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgJwAddcourse::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgJwAddcourse)
	m_credit = _T("");
	m_name = _T("");
	m_tid = _T("");
	//}}AFX_DATA_INIT
}


void CDlgJwAddcourse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgJwAddcourse)
	DDX_Text(pDX, IDC_EDIT_CREDIT, m_credit);
	DDV_MaxChars(pDX, m_credit, 2);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 12);
	DDX_Text(pDX, IDC_EDIT_TID, m_tid);
	DDV_MaxChars(pDX, m_tid, 12);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgJwAddcourse, CDialog)
	//{{AFX_MSG_MAP(CDlgJwAddcourse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgJwAddcourse message handlers

void CDlgJwAddcourse::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_name==""||m_tid==""||m_credit=="")
	{
		MessageBox("课程名,教师号或学分不能为空!","错误",MB_OK|MB_ICONWARNING);
		return;
	}
	CString str;
	str=m_credit;
	bool isnum=true;
	for(int i=0;i<str.GetLength();i++)
	{
		if(!isdigit(str.GetAt(i)))
			isnum=false;
	}
	if(!isnum)
	{
		MessageBox("学分必须是数字!","填写错误",MB_OK|MB_ICONWARNING);
		return;
	}
	CDialog::OnOK();
}

void CDlgJwAddcourse::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

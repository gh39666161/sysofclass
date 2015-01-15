// DlgJwDelcourse.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgJwDelcourse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgJwDelcourse dialog


CDlgJwDelcourse::CDlgJwDelcourse(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgJwDelcourse::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgJwDelcourse)
	m_id = _T("");
	//}}AFX_DATA_INIT
}


void CDlgJwDelcourse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgJwDelcourse)
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDV_MaxChars(pDX, m_id, 3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgJwDelcourse, CDialog)
	//{{AFX_MSG_MAP(CDlgJwDelcourse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgJwDelcourse message handlers

void CDlgJwDelcourse::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CString str;
	str=m_id;
	bool isnum=true;
	for(int i=0;i<str.GetLength();i++)
	{
		if(!isdigit(str.GetAt(i)))
			isnum=false;
	}
	if(!isnum)
	{
		MessageBox("¿Î³ÌºÅ±ØÐëÊÇÊý×Ö!","ÌîÐ´´íÎó",MB_OK|MB_ICONWARNING);
		return;
	}
	CDialog::OnOK();
}

void CDlgJwDelcourse::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

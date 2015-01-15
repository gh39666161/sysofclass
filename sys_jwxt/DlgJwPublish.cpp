// DlgJwPublish.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgJwPublish.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgJwPublish dialog


CDlgJwPublish::CDlgJwPublish(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgJwPublish::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgJwPublish)
	m_richedit_pub = _T("");
	//}}AFX_DATA_INIT
}


void CDlgJwPublish::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgJwPublish)
	DDX_Text(pDX, IDC_RICHEDIT_PUB, m_richedit_pub);
	DDV_MaxChars(pDX, m_richedit_pub, 200);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgJwPublish, CDialog)
	//{{AFX_MSG_MAP(CDlgJwPublish)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgJwPublish message handlers


void CDlgJwPublish::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
	if(m_richedit_pub=="")
	{
		MessageBox("Œ¥ÃÓ–¥ƒ⁄»›!","Ã· æ",MB_OK|MB_ICONWARNING);
		return;
	}
	CDialog::OnOK();
}

void CDlgJwPublish::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}


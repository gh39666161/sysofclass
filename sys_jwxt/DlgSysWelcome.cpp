// DlgSysWelcome.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgSysWelcome.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSysWelcome dialog


CDlgSysWelcome::CDlgSysWelcome(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSysWelcome::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSysWelcome)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgSysWelcome::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSysWelcome)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSysWelcome, CDialog)
	//{{AFX_MSG_MAP(CDlgSysWelcome)
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSysWelcome message handlers

BOOL CDlgSysWelcome::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetTimer(1,2000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSysWelcome::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)
	{
		EndDialog(0);
	}
	CDialog::OnTimer(nIDEvent);
}

void CDlgSysWelcome::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CBitmap background;
	background.LoadBitmap(IDB_WELCOME);
	CBrush brush(&background);
	CRect window;
	GetClientRect(&window);
	dc.FillRect(window,&brush);
	// Do not call CDialog::OnPaint() for painting messages
}

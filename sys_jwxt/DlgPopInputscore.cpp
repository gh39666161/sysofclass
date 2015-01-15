// DlgPopInputscore.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgPopInputscore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPopInputscore dialog


CDlgPopInputscore::CDlgPopInputscore(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPopInputscore::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPopInputscore)
	m_score = _T("");
	//}}AFX_DATA_INIT
}


void CDlgPopInputscore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPopInputscore)
	DDX_Text(pDX, IDC_EDIT_SOCRE, m_score);
	DDV_MaxChars(pDX, m_score, 3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPopInputscore, CDialog)
	//{{AFX_MSG_MAP(CDlgPopInputscore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPopInputscore message handlers

void CDlgPopInputscore::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_score=="")
	{
		MessageBox("«Î ‰»Î≥…º®!","Ã· æ",MB_OK|MB_ICONWARNING);
		return;
	}
	CString str;
	str=m_score;
	bool isnum=true;
	for(int i=0;i<str.GetLength();i++)
	{
		if(!isdigit(str.GetAt(i)))
			isnum=false;
	}
	if(!isnum)
	{
		MessageBox("±ÿ–ÎÃÓ–¥ ˝◊÷£°","ÃÓ–¥¥ÌŒÛ",MB_OK|MB_ICONWARNING);
		return;
	}
	CDialog::OnOK();
}

void CDlgPopInputscore::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

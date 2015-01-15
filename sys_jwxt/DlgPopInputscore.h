#if !defined(AFX_DLGPOPINPUTSCORE_H__C836D759_9B82_4854_A2D9_D423146A1431__INCLUDED_)
#define AFX_DLGPOPINPUTSCORE_H__C836D759_9B82_4854_A2D9_D423146A1431__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPopInputscore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPopInputscore dialog

class CDlgPopInputscore : public CDialog
{
// Construction
public:
	CDlgPopInputscore(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgPopInputscore)
	enum { IDD = IDD_POP_INPUTSCORE };
	CString	m_score;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPopInputscore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPopInputscore)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPOPINPUTSCORE_H__C836D759_9B82_4854_A2D9_D423146A1431__INCLUDED_)

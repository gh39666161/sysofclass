#if !defined(AFX_DLGSYSWELCOME_H__8926957F_D542_46BB_A78F_5CFCD0322732__INCLUDED_)
#define AFX_DLGSYSWELCOME_H__8926957F_D542_46BB_A78F_5CFCD0322732__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSysWelcome.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSysWelcome dialog

class CDlgSysWelcome : public CDialog
{
// Construction
public:
	CDlgSysWelcome(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSysWelcome)
	enum { IDD = IDD_SYS_JWXT_WELCOME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSysWelcome)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSysWelcome)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSWELCOME_H__8926957F_D542_46BB_A78F_5CFCD0322732__INCLUDED_)

#if !defined(AFX_DLGJWPUBLISH_H__C394146C_6AF9_4076_94AE_6AAE1855D751__INCLUDED_)
#define AFX_DLGJWPUBLISH_H__C394146C_6AF9_4076_94AE_6AAE1855D751__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgJwPublish.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgJwPublish dialog

class CDlgJwPublish : public CDialog
{
// Construction
public:
	CDlgJwPublish(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgJwPublish)
	enum { IDD = IDD_JW_PUBLISH };
	CString	m_richedit_pub;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgJwPublish)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgJwPublish)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGJWPUBLISH_H__C394146C_6AF9_4076_94AE_6AAE1855D751__INCLUDED_)

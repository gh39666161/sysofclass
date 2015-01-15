#if !defined(AFX_DLGSYSTEMDELJW_H__730748AD_0D6B_490F_AC0F_A1136C1F0375__INCLUDED_)
#define AFX_DLGSYSTEMDELJW_H__730748AD_0D6B_490F_AC0F_A1136C1F0375__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemDeljw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDeljw dialog

class CDlgSystemDeljw : public CDialog
{
// Construction
public:
	CDlgSystemDeljw(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemDeljw)
	enum { IDD = IDD_SYSTEM_DELJW };
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemDeljw)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemDeljw)
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMDELJW_H__730748AD_0D6B_490F_AC0F_A1136C1F0375__INCLUDED_)

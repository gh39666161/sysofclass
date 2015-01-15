#if !defined(AFX_DLGSYSTEMUPDATEJW_H__137D6D37_F2A7_43D6_AC92_343A79EC129B__INCLUDED_)
#define AFX_DLGSYSTEMUPDATEJW_H__137D6D37_F2A7_43D6_AC92_343A79EC129B__INCLUDED_

#include "T_Jwadmin.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemUpdatejw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemUpdatejw dialog

class CDlgSystemUpdatejw : public CDialog
{
// Construction
public:
	CDlgSystemUpdatejw(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemUpdatejw)
	enum { IDD = IDD_SYSTEM_UPDATEJW };
	CButton	m_btn_ok;
	CButton	m_btn_change;
	CString	m_change;
	CString	m_id;
	CString	m_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemUpdatejw)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemUpdatejw)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnBtnChange();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	T_Jwadmin t_jwadmin;
	CRect m_small;
	CRect m_large;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMUPDATEJW_H__137D6D37_F2A7_43D6_AC92_343A79EC129B__INCLUDED_)

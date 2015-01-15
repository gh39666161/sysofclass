#if !defined(AFX_DLGSYSTEMDELTCH_H__EFAC0FFE_3A71_487E_9931_5309B5C9EFEE__INCLUDED_)
#define AFX_DLGSYSTEMDELTCH_H__EFAC0FFE_3A71_487E_9931_5309B5C9EFEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemDeltch.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDeltch dialog

class CDlgSystemDeltch : public CDialog
{
// Construction
public:
	CString m_delitem;
	CDlgSystemDeltch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemDeltch)
	enum { IDD = IDD_SYSTEM_DELTCH };
	CComboBox	m_combo_delitem;
	CString	m_delmsg;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemDeltch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemDeltch)
	virtual void OnCancel();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMDELTCH_H__EFAC0FFE_3A71_487E_9931_5309B5C9EFEE__INCLUDED_)

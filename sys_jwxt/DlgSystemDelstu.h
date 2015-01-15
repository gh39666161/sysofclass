#if !defined(AFX_DLGSYSTEMDELSTU_H__A36B8449_7BE3_44C7_9737_8667E9D9F8B1__INCLUDED_)
#define AFX_DLGSYSTEMDELSTU_H__A36B8449_7BE3_44C7_9737_8667E9D9F8B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemDelstu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemDelstu dialog

class CDlgSystemDelstu : public CDialog
{
// Construction
public:
	CString m_delitem;
	CDlgSystemDelstu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemDelstu)
	enum { IDD = IDD_SYSTEM_DELSTU };
	CComboBox	m_combo_delitem;
	CString	m_delmsg;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemDelstu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemDelstu)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMDELSTU_H__A36B8449_7BE3_44C7_9737_8667E9D9F8B1__INCLUDED_)

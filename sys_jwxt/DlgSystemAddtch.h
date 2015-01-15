#if !defined(AFX_DLGSYSTEMADDTCH_H__6CA8FD62_7E67_46B5_B31F_084AEBB9C339__INCLUDED_)
#define AFX_DLGSYSTEMADDTCH_H__6CA8FD62_7E67_46B5_B31F_084AEBB9C339__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemAddtch.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemAddtch dialog

class CDlgSystemAddtch : public CDialog
{
// Construction
public:
	CString m_sex;
	CDlgSystemAddtch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemAddtch)
	enum { IDD = IDD_SYSTEM_ADDTCH };
	CComboBox	m_combox_sex;
	CString	m_age;
	CString	m_id;
	CString	m_name;
	CString	m_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemAddtch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemAddtch)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMADDTCH_H__6CA8FD62_7E67_46B5_B31F_084AEBB9C339__INCLUDED_)

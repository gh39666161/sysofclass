#if !defined(AFX_DLGSYSTEMADDSTU_H__B6DEFAFD_6B77_4335_9BB4_72EDE0EE6FF8__INCLUDED_)
#define AFX_DLGSYSTEMADDSTU_H__B6DEFAFD_6B77_4335_9BB4_72EDE0EE6FF8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemAddstu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemAddstu dialog

class CDlgSystemAddstu : public CDialog
{
// Construction
public:
	CString m_sex;
	CDlgSystemAddstu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemAddstu)
	enum { IDD = IDD_SYSTEM_ADDSTU };
	CComboBox	m_combox_sex;
	CString	m_age;
	CString	m_id;
	CString	m_name;
	CString	m_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemAddstu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemAddstu)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMADDSTU_H__B6DEFAFD_6B77_4335_9BB4_72EDE0EE6FF8__INCLUDED_)

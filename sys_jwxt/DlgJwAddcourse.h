#if !defined(AFX_DLGJWADDCOURSE_H__A4418E15_43DB_4C68_8317_AB920770ABD7__INCLUDED_)
#define AFX_DLGJWADDCOURSE_H__A4418E15_43DB_4C68_8317_AB920770ABD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgJwAddcourse.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgJwAddcourse dialog

class CDlgJwAddcourse : public CDialog
{
// Construction
public:
	CDlgJwAddcourse(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgJwAddcourse)
	enum { IDD = IDD_JW_ADDCOURSE };
	CString	m_credit;
	CString	m_name;
	CString	m_tid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgJwAddcourse)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgJwAddcourse)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGJWADDCOURSE_H__A4418E15_43DB_4C68_8317_AB920770ABD7__INCLUDED_)

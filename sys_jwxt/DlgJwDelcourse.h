#if !defined(AFX_DLGJWDELCOURSE_H__53507CC5_D15A_42CC_B1FA_F682F9280C31__INCLUDED_)
#define AFX_DLGJWDELCOURSE_H__53507CC5_D15A_42CC_B1FA_F682F9280C31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgJwDelcourse.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgJwDelcourse dialog

class CDlgJwDelcourse : public CDialog
{
// Construction
public:
	CDlgJwDelcourse(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgJwDelcourse)
	enum { IDD = IDD_JW_DELCOURSE };
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgJwDelcourse)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgJwDelcourse)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGJWDELCOURSE_H__53507CC5_D15A_42CC_B1FA_F682F9280C31__INCLUDED_)

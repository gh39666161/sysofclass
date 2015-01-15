#if !defined(AFX_DLGSYSTEMADDJW_H__10152E70_F20C_4FBE_9189_36404B0421CE__INCLUDED_)
#define AFX_DLGSYSTEMADDJW_H__10152E70_F20C_4FBE_9189_36404B0421CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemAddjw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemAddjw dialog

class CDlgSystemAddjw : public CDialog
{
// Construction
public:
	CDlgSystemAddjw(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemAddjw)
	enum { IDD = IDD_SYSTEM_ADDJW };
	CString	m_id;
	CString	m_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemAddjw)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemAddjw)
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMADDJW_H__10152E70_F20C_4FBE_9189_36404B0421CE__INCLUDED_)

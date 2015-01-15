#if !defined(AFX_DLGCHANGEPWD_H__EAB3E0A3_4C8B_4268_B401_43D3EC7E28E1__INCLUDED_)
#define AFX_DLGCHANGEPWD_H__EAB3E0A3_4C8B_4268_B401_43D3EC7E28E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChangepwd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChangepwd dialog

class CDlgChangepwd : public CDialog
{
// Construction
public:
	CDlgChangepwd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChangepwd)
	enum { IDD = IDD_CHANGEPWD };
	CString	m_newpwd;
	CString	m_orginpwd;
	CString	m_repeatpwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChangepwd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgChangepwd)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHANGEPWD_H__EAB3E0A3_4C8B_4268_B401_43D3EC7E28E1__INCLUDED_)

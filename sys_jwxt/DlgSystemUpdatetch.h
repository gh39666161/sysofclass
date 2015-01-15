#if !defined(AFX_DLGSYSTEMUPDATETCH_H__1B34CECB_560D_453C_9136_BE4733A19F65__INCLUDED_)
#define AFX_DLGSYSTEMUPDATETCH_H__1B34CECB_560D_453C_9136_BE4733A19F65__INCLUDED_

#include "T_Teacher.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemUpdatetch.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemUpdatetch dialog

class CDlgSystemUpdatetch : public CDialog
{
// Construction
public:
	CDlgSystemUpdatetch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemUpdatetch)
	enum { IDD = IDD_SYSTEM_UPDATETCH };
	CComboBox	m_combo_sex;
	CButton	m_b_ok;
	CComboBox	m_combo_changeitem;
	CString	m_changemsg;
	CString	m_age;
	CString	m_id;
	CString	m_name;
	CString	m_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemUpdatetch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemUpdatetch)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnBtnChange();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	T_Teacher t_teacher;
	CRect m_small;
	CRect m_large;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMUPDATETCH_H__1B34CECB_560D_453C_9136_BE4733A19F65__INCLUDED_)

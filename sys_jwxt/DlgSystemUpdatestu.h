#if !defined(AFX_DLGSYSTEMUPDATESTU_H__BB0CBC29_60AC_4F2D_AF04_EF185C67ADAC__INCLUDED_)
#define AFX_DLGSYSTEMUPDATESTU_H__BB0CBC29_60AC_4F2D_AF04_EF185C67ADAC__INCLUDED_

#include "T_Student.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSystemUpdatestu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSystemUpdatestu dialog

class CDlgSystemUpdatestu : public CDialog
{
// Construction
public:
	CDlgSystemUpdatestu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSystemUpdatestu)
	enum { IDD = IDD_SYSTEM_UPDATESTU };
	CButton	m_b_ok;
	CComboBox	m_combo_sex;
	CComboBox	m_combo_changeitem;
	CString	m_age;
	CString	m_changemsg;
	CString	m_id;
	CString	m_name;
	CString	m_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSystemUpdatestu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSystemUpdatestu)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnChange();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	T_Student t_student;
	CRect m_small;
	CRect m_large;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSTEMUPDATESTU_H__BB0CBC29_60AC_4F2D_AF04_EF185C67ADAC__INCLUDED_)

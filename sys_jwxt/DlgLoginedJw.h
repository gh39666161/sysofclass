#if !defined(AFX_DLGLOGINEDJW_H__F36B6AAA_6E2A_4700_B499_8072B27720D3__INCLUDED_)
#define AFX_DLGLOGINEDJW_H__F36B6AAA_6E2A_4700_B499_8072B27720D3__INCLUDED_

#include "T_Course.h"	// Added by ClassView
#include "T_Teacher.h"	// Added by ClassView
#include "T_Publish.h"	// Added by ClassView
#include "T_Student.h"	// Added by ClassView
#include "T_Isselectcourse.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLoginedJw.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedJw dialog

class CDlgLoginedJw : public CDialog
{
// Construction
public:
	CDlgLoginedJw(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLoginedJw)
	enum { IDD = IDD_LOGINED_JW };
	CListCtrl	m_list_impt;
	CString	m_loginedmessage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLoginedJw)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLoginedJw)
	afx_msg void OnBtnJwExit();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnJwImptStudent();
	afx_msg void OnBtnJwImptTeacher();
	afx_msg void OnBtnJwPub();
	afx_msg void OnBtnJwSetcourse();
	afx_msg void OnBtnJwUpdatestu();
	afx_msg void OnBtnJwUpdatetch();
	afx_msg void OnBtnJwSwitch();
	//}}AFX_MSG
	afx_msg void OnBtnJwImptstu();
	afx_msg void OnBtnJwImpttch();
	afx_msg void OnBtnJwAddcourse();
	afx_msg void OnBtnJwDelcourse();
	DECLARE_MESSAGE_MAP()
private:
	T_Isselectcourse *t_isselectcourse;
	CButton *m_pb_delcourse;
	CButton *m_pb_addcourse;
	T_Course *t_course;
	T_Student *t_student;
	CFont *m_font;
	CRichEditCtrl *m_prich_pub;
	T_Publish *t_publish;
	T_Teacher *t_teacher;
	CButton *m_pb_impttch;
	CButton *m_pb_imptstu;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLOGINEDJW_H__F36B6AAA_6E2A_4700_B499_8072B27720D3__INCLUDED_)

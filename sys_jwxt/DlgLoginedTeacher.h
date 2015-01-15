#if !defined(AFX_DLGLOGINEDTEACHER_H__45B9CD15_14D5_4245_A39D_F52A4B7176F7__INCLUDED_)
#define AFX_DLGLOGINEDTEACHER_H__45B9CD15_14D5_4245_A39D_F52A4B7176F7__INCLUDED_

#include "T_Publish.h"	// Added by ClassView
#include "T_Student.h"	// Added by ClassView
#include "T_Teacher.h"	// Added by ClassView
#include "T_Course.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLoginedTeacher.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedTeacher dialog

class CDlgLoginedTeacher : public CDialog
{
// Construction
public:
	CString m_courseselect;
	CDlgLoginedTeacher(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLoginedTeacher)
	enum { IDD = IDD_LOGINED_TEACHER };
	CListBox	m_list_course;
	CString	m_LoginedMessage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLoginedTeacher)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLoginedTeacher)
	afx_msg void OnBtnTchExit();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnTchPerson();
	afx_msg void OnBtnTchChangepwd();
	afx_msg void OnBtnTchInputscore();
	afx_msg void OnDblclkTchListCourse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	T_Course *t_course;
	T_Teacher *t_teacher;
	T_Student *t_student;
	T_Publish *t_publish;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLOGINEDTEACHER_H__45B9CD15_14D5_4245_A39D_F52A4B7176F7__INCLUDED_)

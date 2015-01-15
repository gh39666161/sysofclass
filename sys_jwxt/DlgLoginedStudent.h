#if !defined(AFX_DLGLOGINEDSTUDENT_H__C4423679_B7DB_4ACD_BF77_E75B8FA6DDA1__INCLUDED_)
#define AFX_DLGLOGINEDSTUDENT_H__C4423679_B7DB_4ACD_BF77_E75B8FA6DDA1__INCLUDED_

#include "T_Publish.h"	// Added by ClassView
#include "T_Student.h"	// Added by ClassView
#include "T_SC.h"	// Added by ClassView
#include "T_Course.h"	// Added by ClassView
#include "T_Teacher.h"	// Added by ClassView
#include "T_Isselectcourse.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLoginedStudent.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedStudent dialog

class CDlgLoginedStudent : public CDialog
{
// Construction
public:
	CDlgLoginedStudent(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLoginedStudent)
	enum { IDD = IDD_LOGINED_STUDENT };
	CListCtrl	m_list_score;
	CListBox	m_list_selected;
	CListBox	m_list_preselect;
	CString	m_LoginedMessage;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLoginedStudent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLoginedStudent)
	afx_msg void OnBtnStuExit();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnStuPerson();
	afx_msg void OnBtnStuChangepwd();
	afx_msg void OnBtnStuSc();
	afx_msg void OnBtnAddcourse();
	afx_msg void OnBtnDelcourse();
	afx_msg void OnBtnStuGetscore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	T_Isselectcourse *t_isselectcourse;
	T_Teacher *t_teacher;
	T_Course *t_course;
	T_SC *t_sc;
	T_Student *t_student;
	T_Publish *t_publish;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLOGINEDSTUDENT_H__C4423679_B7DB_4ACD_BF77_E75B8FA6DDA1__INCLUDED_)

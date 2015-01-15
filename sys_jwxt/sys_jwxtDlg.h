// sys_jwxtDlg.h : header file
//

#if !defined(AFX_SYS_JWXTDLG_H__0D214945_F62E_4648_B2C6_92826EF02744__INCLUDED_)
#define AFX_SYS_JWXTDLG_H__0D214945_F62E_4648_B2C6_92826EF02744__INCLUDED_

#include "T_Admin.h"
#include "DlgLoginedJw.h"	// Added by ClassView
#include "DlgLoginedSystem.h"	// Added by ClassView
#include "T_Teacher.h"	// Added by ClassView
#include "DlgLoginedTeacher.h"	// Added by ClassView
#include "T_Jwadmin.h"	// Added by ClassView
#include "T_Student.h"	// Added by ClassView
#include "DlgLoginedStudent.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSys_jwxtDlg dialog

class CSys_jwxtDlg : public CDialog
{
// Construction
public:
	CDlgLoginedStudent *m_pDlgStudent;
	CDlgLoginedTeacher *m_pDlgTeacher;
	CDlgLoginedJw *m_pDlgJw;
	CDlgLoginedSystem *m_pDlgSystem;
	CString m_user;
	CSys_jwxtDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSys_jwxtDlg)
	enum { IDD = IDD_SYS_JWXT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSys_jwxtDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSys_jwxtDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnUserStudent();
	afx_msg void OnUserSystem();
	afx_msg void OnUserTeacher();
	afx_msg void OnUserJw();
	afx_msg void OnBtnExit();
	afx_msg void OnBtnLogin();
	afx_msg void OnBtnSkin();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	T_Student *t_student;
	T_Jwadmin *t_jwadmin;
	T_Teacher *t_teacher;
	T_Admin *t_admin;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYS_JWXTDLG_H__0D214945_F62E_4648_B2C6_92826EF02744__INCLUDED_)

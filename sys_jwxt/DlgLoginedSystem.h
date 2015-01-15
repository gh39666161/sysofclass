//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_DLGLOGINEDSYSTEM_H__8DFD623B_EDF8_4D11_BA41_E4EC34F54409__INCLUDED_)
#define AFX_DLGLOGINEDSYSTEM_H__8DFD623B_EDF8_4D11_BA41_E4EC34F54409__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLoginedSystem.h : header file
//
#include "column.h"
#include "columns.h"
#include "COMDEF.H"
/////////////////////////////////////////////////////////////////////////////
// CDlgLoginedSystem dialog

#include "T_Teacher.h"	// Added by ClassView
#include "T_Jwadmin.h"	// Added by ClassView
#include "T_Publish.h"	// Added by ClassView
#include "T_Student.h"	// Added by ClassView
class CDlgLoginedSystem : public CDialog
{
// Construction
public:
	CDlgLoginedSystem(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgLoginedSystem)
	enum { IDD = IDD_LOGINED_SYSTEM };
	CString	m_LoginedMessage;
	CDataGrid	m_datagrid_mesg;
	CAdodc	m_sys_adodc;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLoginedSystem)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLoginedSystem)
	afx_msg void OnBtnSysExit();
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnSysJw();
	afx_msg void OnBtnSysTch();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBtnSysPub();
	afx_msg void OnBtnSysStu();
	afx_msg void OnBtnSysDelpublog();
	//}}AFX_MSG
	afx_msg void OnBtnSysAddjw();
	afx_msg void OnBtnSysUpdatejw();
	afx_msg void OnBtnSysDeljw();
	afx_msg void OnBtnSysAddtch();
	afx_msg void OnBtnSysUpdatetch();
	afx_msg void OnBtnSysDeltch();
	afx_msg void OnBtnSysAddstu();
	afx_msg void OnBtnSysUpdatestu();
	afx_msg void OnBtnSysDelstu();
	DECLARE_MESSAGE_MAP()
private:
	T_Student *t_student;
	T_Publish *t_publish;
	CFont *m_font;
	T_Jwadmin *t_jwadmin;
	T_Teacher *t_teacher;
	CButton *m_pb_deljw;
	CButton *m_pb_updatejw;
	CButton *m_pb_addjw;
	CButton *m_pb_deltch;
	CButton *m_pb_updatetch;
	CButton *m_pb_addtch;
	CButton *m_pb_delstu;
	CButton *m_pb_updatestu;
	CButton *m_pb_addstu;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLOGINEDSYSTEM_H__8DFD623B_EDF8_4D11_BA41_E4EC34F54409__INCLUDED_)

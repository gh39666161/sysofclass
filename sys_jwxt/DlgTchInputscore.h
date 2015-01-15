//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
//}}AFX_INCLUDES
#if !defined(AFX_DLGTCHINPUTSCORE_H__3FE545E2_03E9_46FF_824B_F038357B6C56__INCLUDED_)
#define AFX_DLGTCHINPUTSCORE_H__3FE545E2_03E9_46FF_824B_F038357B6C56__INCLUDED_

#include "T_Course.h"	// Added by ClassView
#include "T_SC.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTchInputscore.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgTchInputscore dialog


class CDlgTchInputscore : public CDialog
{
// Construction
public:
	CString m_courseid;
	CDlgTchInputscore(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgTchInputscore)
	enum { IDD = IDD_TCH_INPUTSCORE };
	CAdodc	m_adoc_sc;
	CDataGrid	m_datagrid_inputscore;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTchInputscore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgTchInputscore)
	virtual BOOL OnInitDialog();
	afx_msg void OnDblClickDatagridInputscore();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	T_SC *t_sc;
	T_Course *t_course;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTCHINPUTSCORE_H__3FE545E2_03E9_46FF_824B_F038357B6C56__INCLUDED_)

#if !defined(AFX_T_TEACHER_H__2D5E1B4C_D22E_41FD_95F4_AE095F5B7054__INCLUDED_)
#define AFX_T_TEACHER_H__2D5E1B4C_D22E_41FD_95F4_AE095F5B7054__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// T_Teacher.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// T_Teacher window

class T_Teacher : public CWnd
{
// Construction
public:
	T_Teacher();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(T_Teacher)
	//}}AFX_VIRTUAL

// Implementation
public:
	_RecordsetPtr teacher_select(_bstr_t id,CString col="*");
	bool teacher_update(CString row,CString col,CString id="",CString pwd="",CString name="",CString sex="",CString age="");
	bool teacher_del(CString row,CString col);
	bool teacher_insert(CString id,CString pwd,CString name="",CString sex="",CString age="");
	_RecordsetPtr teacher_select(CString col="*");
	virtual ~T_Teacher();

	// Generated message map functions
protected:
	//{{AFX_MSG(T_Teacher)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	ADOC theAdo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_T_TEACHER_H__2D5E1B4C_D22E_41FD_95F4_AE095F5B7054__INCLUDED_)

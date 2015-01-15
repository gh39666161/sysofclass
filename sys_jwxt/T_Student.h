#if !defined(AFX_T_STUDENT_H__66A7975E_09C8_40DD_BD38_A6DDE8B2A3D0__INCLUDED_)
#define AFX_T_STUDENT_H__66A7975E_09C8_40DD_BD38_A6DDE8B2A3D0__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// T_Student.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// T_Student window

class T_Student : public CWnd
{
// Construction
public:
	T_Student();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(T_Student)
	//}}AFX_VIRTUAL

// Implementation
public:
	bool student_update(CString row,CString col,CString id,CString pwd,CString name="",CString sex="",CString age="");
	bool student_del(CString row,CString col);
	_RecordsetPtr student_select(CString col="*");
	bool student_insert(CString id,CString pwd,CString name,CString sex,CString age);
	virtual ~T_Student();

	// Generated message map functions
protected:
	//{{AFX_MSG(T_Student)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	ADOC theAdo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_T_STUDENT_H__66A7975E_09C8_40DD_BD38_A6DDE8B2A3D0__INCLUDED_)

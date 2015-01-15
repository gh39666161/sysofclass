#if !defined(AFX_T_COURSE_H__D3219059_B2A4_4FB1_83C8_69AD2BA60231__INCLUDED_)
#define AFX_T_COURSE_H__D3219059_B2A4_4FB1_83C8_69AD2BA60231__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// T_Course.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// T_Course window

class T_Course : public CWnd
{
// Construction
public:
	T_Course();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(T_Course)
	//}}AFX_VIRTUAL

// Implementation
public:
	bool course_del(CString id);
	bool course_insert(CString name,CString tid,CString credit);
	_RecordsetPtr course_select(CString col="*");
	virtual ~T_Course();

	// Generated message map functions
protected:
	//{{AFX_MSG(T_Course)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	ADOC theAdo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_T_COURSE_H__D3219059_B2A4_4FB1_83C8_69AD2BA60231__INCLUDED_)

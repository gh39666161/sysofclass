#if !defined(AFX_T_ISSELECTCOURSE_H__5F350AAF_71A4_4CA1_B218_06A2569F89AB__INCLUDED_)
#define AFX_T_ISSELECTCOURSE_H__5F350AAF_71A4_4CA1_B218_06A2569F89AB__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// T_Isselectcourse.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// T_Isselectcourse window

class T_Isselectcourse : public CWnd
{
// Construction
public:
	T_Isselectcourse();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(T_Isselectcourse)
	//}}AFX_VIRTUAL

// Implementation
public:
	bool isselectcourse_update(CString str);
	bool isopen();
	bool close();
	_RecordsetPtr isselectcourse_select();
	bool open();
	virtual ~T_Isselectcourse();

	// Generated message map functions
protected:
	//{{AFX_MSG(T_Isselectcourse)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	ADOC theAdo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_T_ISSELECTCOURSE_H__5F350AAF_71A4_4CA1_B218_06A2569F89AB__INCLUDED_)

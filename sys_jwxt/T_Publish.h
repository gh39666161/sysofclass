#if !defined(AFX_T_PUBLISH_H__8457210C_E07C_496F_AC39_F8B5421FC157__INCLUDED_)
#define AFX_T_PUBLISH_H__8457210C_E07C_496F_AC39_F8B5421FC157__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// T_Publish.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// T_Publish window

class T_Publish : public CWnd
{
// Construction
public:
	T_Publish();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(T_Publish)
	//}}AFX_VIRTUAL

// Implementation
public:
	bool publish_del();
	_RecordsetPtr publish_select();
	bool publish_insert(CString text);
	virtual ~T_Publish();

	// Generated message map functions
protected:
	//{{AFX_MSG(T_Publish)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	ADOC theAdo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_T_PUBLISH_H__8457210C_E07C_496F_AC39_F8B5421FC157__INCLUDED_)

#if !defined(AFX_T_SC_H__AF79ED83_AF4B_4E91_A474_B7D09176F07D__INCLUDED_)
#define AFX_T_SC_H__AF79ED83_AF4B_4E91_A474_B7D09176F07D__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// T_SC.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// T_SC window

class T_SC : public CWnd
{
// Construction
public:
	T_SC();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(T_SC)
	//}}AFX_VIRTUAL

// Implementation
public:
	bool sc_del(CString c_id,CString s_id);
	bool sc_insert(CString c_id,CString s_id,CString score="");
	bool sc_update(CString c_id,CString s_id,CString score);
	_RecordsetPtr sc_select(CString col="*");
	virtual ~T_SC();

	// Generated message map functions
protected:
	//{{AFX_MSG(T_SC)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	ADOC theAdo;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_T_SC_H__AF79ED83_AF4B_4E91_A474_B7D09176F07D__INCLUDED_)

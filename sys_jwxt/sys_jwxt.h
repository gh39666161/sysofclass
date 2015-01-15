// sys_jwxt.h : main header file for the SYS_JWXT application
//

#if !defined(AFX_SYS_JWXT_H__24DFB4FB_2EEC_461C_9ACE_BBF704EEB244__INCLUDED_)
#define AFX_SYS_JWXT_H__24DFB4FB_2EEC_461C_9ACE_BBF704EEB244__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSys_jwxtApp:
// See sys_jwxt.cpp for the implementation of this class
//

class CSys_jwxtApp : public CWinApp
{
public:
	CSys_jwxtApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSys_jwxtApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSys_jwxtApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYS_JWXT_H__24DFB4FB_2EEC_461C_9ACE_BBF704EEB244__INCLUDED_)

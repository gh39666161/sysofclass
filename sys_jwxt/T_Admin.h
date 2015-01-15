// T_Admin.h: interface for the T_Admin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_T_ADMIN_H__34394F99_4E9E_449A_AC48_0E3F0865AA5E__INCLUDED_)
#define AFX_T_ADMIN_H__34394F99_4E9E_449A_AC48_0E3F0865AA5E__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class T_Admin :public CWnd
{
public:
	_RecordsetPtr admin_select(CString col="*");
	T_Admin();
	virtual ~T_Admin();

private:
	ADOC theAdo;
};

#endif // !defined(AFX_T_ADMIN_H__34394F99_4E9E_449A_AC48_0E3F0865AA5E__INCLUDED_)

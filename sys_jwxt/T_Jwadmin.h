// T_Jwadmin.h: interface for the T_Jwadmin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_T_JWADMIN_H__1CA59A5B_36DD_4368_B372_8AF79A001B9C__INCLUDED_)
#define AFX_T_JWADMIN_H__1CA59A5B_36DD_4368_B372_8AF79A001B9C__INCLUDED_

#include "ADOConn.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class T_Jwadmin : public CWnd
{
public:
	bool jwadmin_update(CString row,CString name,CString pwd);
	bool jwadmin_del(CString name);
	_RecordsetPtr jwadmin_select(CString col="*");
	void jwadmin_insert(CString name,CString pwd);
	T_Jwadmin();
	virtual ~T_Jwadmin();

private:
	ADOC theAdo;
};

#endif // !defined(AFX_T_JWADMIN_H__1CA59A5B_36DD_4368_B372_8AF79A001B9C__INCLUDED_)

// T_Admin.cpp: implementation of the T_Admin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "sys_jwxt.h"
#include "T_Admin.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

T_Admin::T_Admin()
{
	theAdo.OnInitDBConnect("root","ming19910701");
}

T_Admin::~T_Admin()
{
	theAdo.ExitConnect();
}

_RecordsetPtr T_Admin::admin_select(CString col)
{
	CString SQL;
	SQL.Format("SELECT %s FROM admin",col);
	theAdo.GetRecordset(_bstr_t(SQL));
	return theAdo.m_pRecordset;
}

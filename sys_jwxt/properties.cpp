// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "properties.h"

// Dispatch interfaces referenced by this interface
#include "Property.h"


/////////////////////////////////////////////////////////////////////////////
// CProperties properties

/////////////////////////////////////////////////////////////////////////////
// CProperties operations

long CProperties::GetCount()
{
	long result;
	InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void CProperties::Refresh()
{
	InvokeHelper(0x60020002, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CProperty CProperties::GetItem(const VARIANT& Index)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, parms,
		&Index);
	return CProperty(pDispatch);
}

// ADOConn.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>
#define DLL _declspec(dllexport)
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static AFX_EXTENSION_MODULE ADOConnDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("ADOCONN.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(ADOConnDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(ADOConnDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("ADOCONN.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(ADOConnDLL);
	}
	return 1;   // ok
}

void ADOC::OnInitDBConnect(CString uid,CString pwd)
{
	//Init OLE/COM
	CoInitialize(NULL);
	CString strConnect;
	strConnect="Provider=MSDASQL.1;Password="+pwd+";Persist Security Info=True;User ID="+uid+";Data Source=mysqlsource";
	try
	{
		//����connection ����
		m_pConnection.CreateInstance(__uuidof(Connection));
		//�������ݿ�
		m_pConnection->Open(_bstr_t(strConnect),"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}
void ADOC::ExitConnect()
{
	//�رռ�¼��������
	if(m_pRecordset!=NULL)
	{
		m_pRecordset->Close();
	}
	if(m_pConnection!=NULL)
	{
		m_pConnection->Close();
	}
	//�ͷŻ���
	CoUninitialize();
}

void ADOC::GetRecordset(_bstr_t SQL)
{
	try
	{
		//�ж��Ƿ��������ݿ�
		if(m_pConnection==NULL)
			AfxMessageBox("û���������ݿ⣡");
		else
		{
			//������¼������
			m_pRecordset.CreateInstance(__uuidof(Recordset));
			//��ȡ���еļ�¼
			m_pRecordset->Open(SQL,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
		}
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

BOOL ADOC::ExecuteSQL(_bstr_t SQL)
{
	try
	{
		//�Ƿ��Ѿ��������ݿ�
		if(m_pConnection==NULL)
			AfxMessageBox("û���������ݿ⣡");
		else
		{
			m_pConnection->Execute(SQL,NULL,adCmdText);
			return true;
		}
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
}

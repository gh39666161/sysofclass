#ifndef DLL
#define DLL _declspec(dllimport)
#endif

#ifndef _ADOC_H_
#define _ADOC_H_
#pragma comment(lib,"ADOConn.lib")
class ADOC
{
public:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
public:
	BOOL ExecuteSQL(_bstr_t SQL);
	void GetRecordset(_bstr_t SQL);
	void OnInitDBConnect(CString uid,CString pwd);
	void ExitConnect();
};
#endif
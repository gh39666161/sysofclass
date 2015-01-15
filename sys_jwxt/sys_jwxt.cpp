// sys_jwxt.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "sys_jwxtDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSys_jwxtApp

BEGIN_MESSAGE_MAP(CSys_jwxtApp, CWinApp)
	//{{AFX_MSG_MAP(CSys_jwxtApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSys_jwxtApp construction
CString LoginedName;
CSys_jwxtApp::CSys_jwxtApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSys_jwxtApp object

CSys_jwxtApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSys_jwxtApp initialization

BOOL CSys_jwxtApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	VERIFY( 1 == InitSkinMagicLib(AfxGetInstanceHandle(), NULL, NULL, NULL));
	VERIFY( 1 == LoadSkinFromResource(NULL,"IDR_SKIN_KROMOBLUE","skin"));
	AfxInitRichEdit();
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CSys_jwxtDlg dlg;
	m_pMainWnd = &dlg;
	VERIFY( 1 == SetWindowSkin( m_pMainWnd->m_hWnd,"MainFrame"));
    VERIFY( 1 == SetDialogSkin( "Dialog" ) );
	int nResponse = dlg.DoModal();
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CSys_jwxtApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	ExitSkinMagicLib();
	return CWinApp::ExitInstance();
}

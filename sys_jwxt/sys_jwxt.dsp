# Microsoft Developer Studio Project File - Name="sys_jwxt" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=sys_jwxt - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "sys_jwxt.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "sys_jwxt.mak" CFG="sys_jwxt - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "sys_jwxt - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "sys_jwxt - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "sys_jwxt - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "sys_jwxt - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ADOConn.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "sys_jwxt - Win32 Release"
# Name "sys_jwxt - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\_recordset.cpp
# End Source File
# Begin Source File

SOURCE=.\adodc.cpp
# End Source File
# Begin Source File

SOURCE=.\column.cpp
# End Source File
# Begin Source File

SOURCE=.\columns.cpp
# End Source File
# Begin Source File

SOURCE=.\dataformatdisp.cpp
# End Source File
# Begin Source File

SOURCE=.\datagrid.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgChangepwd.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgJwAddcourse.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgJwDelcourse.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgJwPublish.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLoginedJw.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLoginedStudent.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLoginedSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgLoginedTeacher.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPopInputscore.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemAddjw.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemAddstu.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemAddtch.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemDeljw.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemDelstu.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemDeltch.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemUpdatejw.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemUpdatestu.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSystemUpdatetch.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSysWelcome.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgTchInputscore.cpp
# End Source File
# Begin Source File

SOURCE=.\field.cpp
# End Source File
# Begin Source File

SOURCE=.\fields.cpp
# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\picture.cpp
# End Source File
# Begin Source File

SOURCE=.\properties.cpp
# End Source File
# Begin Source File

SOURCE=.\property.cpp
# End Source File
# Begin Source File

SOURCE=.\selbookmarks.cpp
# End Source File
# Begin Source File

SOURCE=.\split.cpp
# End Source File
# Begin Source File

SOURCE=.\splits.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\stddataformatsdisp.cpp
# End Source File
# Begin Source File

SOURCE=.\sys_jwxt.cpp
# End Source File
# Begin Source File

SOURCE=.\sys_jwxt.rc
# End Source File
# Begin Source File

SOURCE=.\sys_jwxtDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\T_Admin.cpp
# End Source File
# Begin Source File

SOURCE=.\T_Course.cpp
# End Source File
# Begin Source File

SOURCE=.\T_Isselectcourse.cpp
# End Source File
# Begin Source File

SOURCE=.\T_Jwadmin.cpp
# End Source File
# Begin Source File

SOURCE=.\T_Publish.cpp
# End Source File
# Begin Source File

SOURCE=.\T_SC.cpp
# End Source File
# Begin Source File

SOURCE=.\T_Student.cpp
# End Source File
# Begin Source File

SOURCE=.\T_Teacher.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\_recordset.h
# End Source File
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\adodc.h
# End Source File
# Begin Source File

SOURCE=.\column.h
# End Source File
# Begin Source File

SOURCE=.\columns.h
# End Source File
# Begin Source File

SOURCE=.\dataformatdisp.h
# End Source File
# Begin Source File

SOURCE=.\datagrid.h
# End Source File
# Begin Source File

SOURCE=.\DlgChangepwd.h
# End Source File
# Begin Source File

SOURCE=.\DlgJwAddcourse.h
# End Source File
# Begin Source File

SOURCE=.\DlgJwDelcourse.h
# End Source File
# Begin Source File

SOURCE=.\DlgJwPublish.h
# End Source File
# Begin Source File

SOURCE=.\DlgLoginedJw.h
# End Source File
# Begin Source File

SOURCE=.\DlgLoginedStudent.h
# End Source File
# Begin Source File

SOURCE=.\DlgLoginedSystem.h
# End Source File
# Begin Source File

SOURCE=.\DlgLoginedTeacher.h
# End Source File
# Begin Source File

SOURCE=.\DlgPopInputscore.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemAddjw.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemAddstu.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemAddtch.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemDeljw.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemDelstu.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemDeltch.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemUpdatejw.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemUpdatestu.h
# End Source File
# Begin Source File

SOURCE=.\DlgSystemUpdatetch.h
# End Source File
# Begin Source File

SOURCE=.\DlgSysWelcome.h
# End Source File
# Begin Source File

SOURCE=.\DlgTchInputscore.h
# End Source File
# Begin Source File

SOURCE=.\field.h
# End Source File
# Begin Source File

SOURCE=.\fields.h
# End Source File
# Begin Source File

SOURCE=.\font.h
# End Source File
# Begin Source File

SOURCE=.\picture.h
# End Source File
# Begin Source File

SOURCE=.\properties.h
# End Source File
# Begin Source File

SOURCE=.\property.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\selbookmarks.h
# End Source File
# Begin Source File

SOURCE=.\SkinMagicLib.h
# End Source File
# Begin Source File

SOURCE=.\split.h
# End Source File
# Begin Source File

SOURCE=.\splits.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\stddataformatsdisp.h
# End Source File
# Begin Source File

SOURCE=.\sys_jwxt.h
# End Source File
# Begin Source File

SOURCE=.\sys_jwxtDlg.h
# End Source File
# Begin Source File

SOURCE=.\T_Admin.h
# End Source File
# Begin Source File

SOURCE=.\T_Course.h
# End Source File
# Begin Source File

SOURCE=.\T_Isselectcourse.h
# End Source File
# Begin Source File

SOURCE=.\T_Jwadmin.h
# End Source File
# Begin Source File

SOURCE=.\T_Publish.h
# End Source File
# Begin Source File

SOURCE=.\T_SC.h
# End Source File
# Begin Source File

SOURCE=.\T_Student.h
# End Source File
# Begin Source File

SOURCE=.\T_Teacher.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\MainIco.ico
# End Source File
# Begin Source File

SOURCE=.\res\sys_jwxt.ico
# End Source File
# Begin Source File

SOURCE=.\res\sys_jwxt.rc2
# End Source File
# Begin Source File

SOURCE=.\welcome.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\Devior.smf
# End Source File
# Begin Source File

SOURCE=.\res\KromoBlue.smf
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section sys_jwxt : {00000504-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CProperties
# 	2:10:HeaderFile:properties.h
# 	2:8:ImplFile:properties.cpp
# End Section
# Section sys_jwxt : {CDE57A52-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CSelBookmarks
# 	2:10:HeaderFile:selbookmarks.h
# 	2:8:ImplFile:selbookmarks.cpp
# End Section
# Section sys_jwxt : {7BF80981-BF32-101A-8BBB-00AA00300CAB}
# 	2:5:Class:CPicture
# 	2:10:HeaderFile:picture.h
# 	2:8:ImplFile:picture.cpp
# End Section
# Section sys_jwxt : {67397AA3-7FB1-11D0-B148-00A0C922E820}
# 	2:21:DefaultSinkHeaderFile:adodc.h
# 	2:16:DefaultSinkClass:CAdodc
# End Section
# Section sys_jwxt : {00000503-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CProperty
# 	2:10:HeaderFile:property.h
# 	2:8:ImplFile:property.cpp
# End Section
# Section sys_jwxt : {0000054F-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:C_Recordset
# 	2:10:HeaderFile:_recordset.h
# 	2:8:ImplFile:_recordset.cpp
# End Section
# Section sys_jwxt : {CDE57A41-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CDataGrid
# 	2:10:HeaderFile:datagrid.h
# 	2:8:ImplFile:datagrid.cpp
# End Section
# Section sys_jwxt : {CDE57A50-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CColumns
# 	2:10:HeaderFile:columns.h
# 	2:8:ImplFile:columns.cpp
# End Section
# Section sys_jwxt : {0000054D-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CFields
# 	2:10:HeaderFile:fields.h
# 	2:8:ImplFile:fields.cpp
# End Section
# Section sys_jwxt : {E675F3F0-91B5-11D0-9484-00A0C91110ED}
# 	2:5:Class:CDataFormatDisp
# 	2:10:HeaderFile:dataformatdisp.h
# 	2:8:ImplFile:dataformatdisp.cpp
# End Section
# Section sys_jwxt : {CDE57A54-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CSplit
# 	2:10:HeaderFile:split.h
# 	2:8:ImplFile:split.cpp
# End Section
# Section sys_jwxt : {99FF4676-FFC3-11D0-BD02-00C04FC2FB86}
# 	2:5:Class:CStdDataFormatsDisp
# 	2:10:HeaderFile:stddataformatsdisp.h
# 	2:8:ImplFile:stddataformatsdisp.cpp
# End Section
# Section sys_jwxt : {CDE57A4F-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CColumn
# 	2:10:HeaderFile:column.h
# 	2:8:ImplFile:column.cpp
# End Section
# Section sys_jwxt : {CDE57A53-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CSplits
# 	2:10:HeaderFile:splits.h
# 	2:8:ImplFile:splits.cpp
# End Section
# Section sys_jwxt : {0000054C-0000-0010-8000-00AA006D2EA4}
# 	2:5:Class:CField
# 	2:10:HeaderFile:field.h
# 	2:8:ImplFile:field.cpp
# End Section
# Section sys_jwxt : {CDE57A43-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:21:DefaultSinkHeaderFile:datagrid.h
# 	2:16:DefaultSinkClass:CDataGrid
# End Section
# Section sys_jwxt : {47A738F1-7FAF-11D0-B148-00A0C922E820}
# 	2:5:Class:CAdodc
# 	2:10:HeaderFile:adodc.h
# 	2:8:ImplFile:adodc.cpp
# End Section
# Section sys_jwxt : {BEF6E003-A874-101A-8BBA-00AA00300CAB}
# 	2:5:Class:COleFont
# 	2:10:HeaderFile:font.h
# 	2:8:ImplFile:font.cpp
# End Section

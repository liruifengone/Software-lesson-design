# Microsoft Developer Studio Project File - Name="Goband5" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Goband5 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Goband5.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Goband5.mak" CFG="Goband5 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Goband5 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Goband5 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Goband5 - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Goband5 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
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
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Goband5 - Win32 Release"
# Name "Goband5 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;asm"
# Begin Source File

SOURCE=.\Goband5.cpp
# End Source File
# Begin Source File

SOURCE=.\Goband5.rc
# End Source File
# Begin Source File

SOURCE=.\Goband5Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PAGE1.cpp
# End Source File
# Begin Source File

SOURCE=.\PAGE2.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;inc"
# Begin Source File

SOURCE=.\Goband5.h
# End Source File
# Begin Source File

SOURCE=.\Goband5Dlg.h
# End Source File
# Begin Source File

SOURCE=.\PAGE1.h
# End Source File
# Begin Source File

SOURCE=.\PAGE2.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\)@T@3]`F~3]9I[4GFJ_J`}X.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\896W%_KSHI@RJ`QZX$0}P~.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\896W%_KSHI@RJ`QZX$0}P~E.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap18.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap25.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap26.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap27.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap28.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap29.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap30.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap31.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap32.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap33.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap34.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap35.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap36.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\black.bmp
# End Source File
# Begin Source File

SOURCE=.\res\board.bmp
# End Source File
# Begin Source File

SOURCE=.\res\board.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Goband5.ico
# End Source File
# Begin Source File

SOURCE=.\res\Goband5.rc2
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=".\res\QQͼƬ20180102231619.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\QQͼƬ20180104164626.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\QQͼƬ20180104164637.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\QQͼƬ20180104164647.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\timg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\white.bmp
# End Source File
# Begin Source File

SOURCE=".\res\�׷�5.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�ڷ�1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�ڷ����.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�ڷ����2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\�ڷ�ִ��.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\δ����-1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\δ����-1.ico"
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\5390.wav
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=".\res\���������㷨.png"
# End Source File
# Begin Source File

SOURCE=".\res\������Чd.mp3"
# End Source File
# End Target
# End Project

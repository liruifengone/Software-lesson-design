; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Goband5.h"

ClassCount=5
Class1=CGoband5App
Class2=CGoband5Dlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=PAGE1
Class4=CPAGE1
Resource4=IDD_GOBAND5_DIALOG
Class5=CPAGE2
Resource5=PAGE2

[CLS:CGoband5App]
Type=0
HeaderFile=Goband5.h
ImplementationFile=Goband5.cpp
Filter=N

[CLS:CGoband5Dlg]
Type=0
HeaderFile=Goband5Dlg.h
ImplementationFile=Goband5Dlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CGoband5Dlg

[CLS:CAboutDlg]
Type=0
HeaderFile=Goband5Dlg.h
ImplementationFile=Goband5Dlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_GOBAND5_DIALOG]
Type=1
Class=CGoband5Dlg
ControlCount=2
Control1=IDBack,button,1342242816
Control2=IDCANCEL,button,1342242816

[DLG:PAGE1]
Type=1
Class=CPAGE1
ControlCount=0

[CLS:CPAGE1]
Type=0
HeaderFile=PAGE1.h
ImplementationFile=PAGE1.cpp
BaseClass=CDialog
Filter=D
LastObject=CPAGE1
VirtualFilter=dWC

[DLG:PAGE2]
Type=1
Class=CPAGE2
ControlCount=0

[CLS:CPAGE2]
Type=0
HeaderFile=PAGE2.h
ImplementationFile=PAGE2.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPAGE2


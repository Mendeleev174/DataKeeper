; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDataKeeperDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DataKeeper.h"

ClassCount=4
Class1=CDataKeeperApp
Class2=CDataKeeperDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_DIALOGSAVER
Resource2=IDR_MAINFRAME
Resource3=IDD_DATAKEEPER_DIALOG
Class4=CSaveWizard
Resource4=IDD_ABOUTBOX

[CLS:CDataKeeperApp]
Type=0
HeaderFile=DataKeeper.h
ImplementationFile=DataKeeper.cpp
Filter=N
LastObject=CDataKeeperApp

[CLS:CDataKeeperDlg]
Type=0
HeaderFile=DataKeeperDlg.h
ImplementationFile=DataKeeperDlg.cpp
Filter=D
LastObject=IDC_RESNOW
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DataKeeperDlg.h
ImplementationFile=DataKeeperDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=13
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342181390
Control5=IDC_STATIC,static,1342308364
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352

[DLG:IDD_DATAKEEPER_DIALOG]
Type=1
Class=CDataKeeperDlg
ControlCount=26
Control1=IDC_HOUR,edit,1350631552
Control2=IDC_MINUTE,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_DAY,combobox,1344339970
Control7=IDC_EVERYDAY,button,1342242819
Control8=IDC_STATIC,button,1342177287
Control9=IDC_ENDYES,button,1342308361
Control10=IDC_ENDNO,button,1342177289
Control11=IDC_STATIC,button,1342178055
Control12=IDC_STATIC,static,1342308352
Control13=IDC_BASEPATH,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_ARCPATH,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_KEYPATH,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,button,1342177287
Control21=IDC_NOWTIME,edit,1484849281
Control22=IDC_UPDATE,button,1342242817
Control23=IDC_ABOUT,button,1342242816
Control24=IDC_SAVER,button,1342242816
Control25=IDC_RESNOW,button,1342242816
Control26=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOGSAVER]
Type=1
Class=CSaveWizard
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_SAVE3,button,1342243075
Control4=IDC_STATIC,button,1342177287
Control5=IDC_SAVE2,button,1342242819
Control6=IDC_SAVE1,button,1342242819

[CLS:CSaveWizard]
Type=0
HeaderFile=SaveWizard.h
ImplementationFile=SaveWizard.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC


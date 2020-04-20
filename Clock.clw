; CLW ファイルは MFC ClassWizard の情報を含んでいます。

[General Info]
Version=1
LastClass=CClockDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Clock.h"
LastPage=0

ClassCount=8
Class1=CClockApp
Class2=CClockDoc
Class3=CClockView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_CLOCK_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class5=CChildFrame
Class6=CAboutDlg
Class7=CClockDlg
Resource4=IDR_CLOCKTYPE
Class8=CTemp
Resource5=IDD_DIALOG1

[CLS:CClockApp]
Type=0
HeaderFile=Clock.h
ImplementationFile=Clock.cpp
Filter=N
LastObject=CClockApp

[CLS:CClockDoc]
Type=0
HeaderFile=ClockDoc.h
ImplementationFile=ClockDoc.cpp
Filter=N

[CLS:CClockView]
Type=0
HeaderFile=ClockView.h
ImplementationFile=ClockView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=Clock.cpp
ImplementationFile=Clock.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_CLOCKTYPE]
Type=1
Class=CClockView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_CLOCK_DIALOG]
Type=1
Class=CClockDlg
ControlCount=0

[CLS:CClockDlg]
Type=0
HeaderFile=ClockDlg.h
ImplementationFile=ClockDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CClockDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG1]
Type=1
Class=CTemp
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CTemp]
Type=0
HeaderFile=Temp.h
ImplementationFile=Temp.cpp
BaseClass=CDialog
Filter=D
LastObject=CTemp

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_CLOCK
Command2=ID_APP_ABOUT
Command3=ID_ICONCHANGE
Command4=ID_CLOSE_CLOCK
Command5=ID_APP_EXIT1
CommandCount=5


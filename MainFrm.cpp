// MainFrm.cpp : CMainFrame クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "Clock.h"
#include "ClockDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define	WM_ICON_NOTIFY			WM_USER+10
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_CLOCK, OnClock)
	ON_COMMAND(ID_ICONCHANGE, OnIconchange)
	ON_COMMAND(ID_APP_EXIT1, OnAppExit1)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_ICON_NOTIFY, OnTrayNotification)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの構築/消滅

CMainFrame::CMainFrame()
{
	m_iIcon = 0;
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFrameWnd::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの診断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame メッセージ ハンドラ

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_TrayIcon.Create(this, WM_ICON_NOTIFY, _T("TrayClock"), NULL, IDI_HEART))
		return -1;
	
	m_TrayIcon.SetIcon(IDI_HEART);
	OnClock();
	return 0;
}

LRESULT CMainFrame::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	CMenu menu, *pSubMenu;

	// ｿﾀｸ･ﾂﾊ ｸｶｿ�ｽｺ ｹ�ﾆｰﾀﾌ ｴｭｷﾈﾀｻ ｰ豼�: ﾄﾁﾅﾘｽｺﾆｮ ｸﾞｴｺ ﾃ箙ﾂ
	if (LOWORD(lParam) == WM_RBUTTONUP)
	{	
		if (!menu.LoadMenu(IDR_MAINFRAME)) return 0;
		if (!(pSubMenu = menu.GetSubMenu(0))) return 0;

		CPoint pos;
		GetCursorPos(&pos);
		SetForegroundWindow();
		// ﾄﾁﾅﾘｽｺﾆｮ ｸﾞｴｺ ﾃ箙ﾂ
		pSubMenu->TrackPopupMenu(TPM_RIGHTALIGN, pos.x, pos.y, this);

		menu.DestroyMenu();
	} 

	// ｿﾞﾂﾊ ｸｶｿ�ｽｺ ｹ�ﾆｰﾀﾌ ｴ�ｺ� ﾅｬｸｯｵﾇｾ�ﾀｻ ｰ豼�

	else if (LOWORD(lParam) == WM_LBUTTONDBLCLK) 
	{
		// ﾇﾁｷﾎｱﾗｷ･ ﾁ､ｺｸ ｴﾙﾀﾌｾ�ｷﾎｱﾗ ｹﾚｽｺ ﾃ箙ﾂ
		SendMessage(WM_COMMAND, ID_APP_ABOUT);
	}

	return 1;
}


void CMainFrame::OnIconchange() 
{
	CClockApp *pApp;
	pApp = (CClockApp *)AfxGetApp();
	m_iIcon++;
	switch (m_iIcon)
	{
	case 1:
		m_TrayIcon.SetIcon(IDI_HEART1);
		pApp->bmpHeart.LoadBitmap(IDB_BMP_HEART1);
		break;
	case 2:
		m_TrayIcon.SetIcon(IDI_HEART2);
		pApp->bmpHeart.LoadBitmap(IDB_BMP_HEART2);
		break;
	default:
		m_TrayIcon.SetIcon(IDI_HEART);
		pApp->bmpHeart.LoadBitmap(IDB_BMP_HEART);
		m_iIcon = 0;
		break;
	}
}



void CMainFrame::OnClock() 
{
	
	if (m_clockDlg.IsWindowVisible()) 
		m_clockDlg.EndDialog(TRUE);
	else
		m_clockDlg.DoModal();
}
	
void CMainFrame::OnAppExit1() 
{
	if (m_clockDlg.IsWindowVisible()) 
		m_clockDlg.EndDialog(TRUE);
	PostMessage(WM_COMMAND,ID_APP_EXIT);
}

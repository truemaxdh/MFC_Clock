// MainFrm.h : CMainFrame クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__38A35687_A318_4400_9A26_138FE437B309__INCLUDED_)
#define AFX_MAINFRM_H__38A35687_A318_4400_9A26_138FE437B309__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TrayIcon.h"
#include "ClockDlg.h"

class CMainFrame : public CFrameWnd
{
protected: // create from serialization only
	DECLARE_DYNCREATE(CMainFrame)


public:
	CMainFrame();
	CTrayIcon m_TrayIcon;
// アトリビュート
public:

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	int m_iIcon;
	CClockDlg m_clockDlg;
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClock();
	afx_msg void OnIconchange();
	afx_msg void OnAppExit1();
	//}}AFX_MSG
	afx_msg LONG OnTrayNotification(UINT wParam, LONG lParam);
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_MAINFRM_H__38A35687_A318_4400_9A26_138FE437B309__INCLUDED_)

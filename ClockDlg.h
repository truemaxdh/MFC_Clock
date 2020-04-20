// ClockDlg.h : ヘッダー ファイル
//

#if !defined(AFX_CLOCKDLG_H__CED9D4B6_D07D_422C_85EE_C876F9A2B9CB__INCLUDED_)
#define AFX_CLOCKDLG_H__CED9D4B6_D07D_422C_85EE_C876F9A2B9CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CClockDlg ダイアログ

class CClockDlg : public CDialog
{
// 構築
public:
	CClockDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CClockDlg)
	enum { IDD = IDD_CLOCK_DIALOG };
		// メモ: この位置に ClassWizard によってデータ メンバが追加されます。
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CClockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
//	HICON m_hIcon;
	bool m_bIsFirst;
	double oX,oY,ang,d_ang;
	double xH,yH,xM,yM,xS,yS;
	int m_colorR,m_colorG,m_colorB;
	int m_dR,m_dG, m_dB;
	int m_iStyle;
	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CClockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_CLOCKDLG_H__CED9D4B6_D07D_422C_85EE_C876F9A2B9CB__INCLUDED_)

// ClockDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_CLOCKDLG_H__CED9D4B6_D07D_422C_85EE_C876F9A2B9CB__INCLUDED_)
#define AFX_CLOCKDLG_H__CED9D4B6_D07D_422C_85EE_C876F9A2B9CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CClockDlg �_�C�A���O

class CClockDlg : public CDialog
{
// �\�z
public:
	CClockDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CClockDlg)
	enum { IDD = IDD_CLOCK_DIALOG };
		// ����: ���̈ʒu�� ClassWizard �ɂ���ăf�[�^ �����o���ǉ�����܂��B
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CClockDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
//	HICON m_hIcon;
	bool m_bIsFirst;
	double oX,oY,ang,d_ang;
	double xH,yH,xM,yM,xS,yS;
	int m_colorR,m_colorG,m_colorB;
	int m_dR,m_dG, m_dB;
	int m_iStyle;
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CClockDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CLOCKDLG_H__CED9D4B6_D07D_422C_85EE_C876F9A2B9CB__INCLUDED_)

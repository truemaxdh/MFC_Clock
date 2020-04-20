// ClockDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "Clock.h"
#include "ClockDlg.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// �A�v���P�[�V�����̃o�[�W�������Ŏg���Ă��� CAboutDlg �_�C�A���O

/////////////////////////////////////////////////////////////////////////////
// CClockDlg �_�C�A���O

CClockDlg::CClockDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClockDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClockDlg)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ă����o�̏��������ǉ�����܂��B
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
//	m_hIcon = AfxGetApp()->LoadIcon(IDI_HEART);
}

void CClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClockDlg)
		// ����: ���̏ꏊ�ɂ� ClassWizard �ɂ���� DDX �� DDV �̌Ăяo�����ǉ�����܂��B
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClockDlg, CDialog)
	//{{AFX_MSG_MAP(CClockDlg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockDlg ���b�Z�[�W �n���h��

BOOL CClockDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "�o�[�W�������..." ���j���[���ڂ��V�X�e�� ���j���[�֒ǉ����܂��B

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
//	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
//	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B
	SetWindowPos(&wndTopMost,1400,1000,150,150,SWP_SHOWWINDOW);
	
	//oX = 200;
	//oY = 200;
	ang = 3.141592 / 2 * 3;
	d_ang = 3.141592 / 30;
	m_colorR = m_colorG = m_colorB = 0;
	m_dR = m_dG = m_dB = 10;
	m_iStyle = 0;
	SetTimer(0,50,NULL);

	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

void CClockDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	CClientDC dc(this);
	CDC MemDC, MemDC2;
	CBitmap bmpDC2;

	MemDC.CreateCompatibleDC(&dc);
	MemDC2.CreateCompatibleDC(&dc);
		
	CTime	clsDT = CTime::GetCurrentTime();
	

	CRect rect;
	this->GetClientRect(&rect);
	
	bmpDC2.CreateCompatibleBitmap(&dc,2000,2000);
	MemDC2.SelectObject(&bmpDC2);
	
	oX = rect.right * 20 / 43;
	oY = rect.bottom * 20 / 43;
		
	if (m_colorR + m_dR>= 256 || m_colorR + m_dR <= 0) 
	{
		
		m_dR = -m_dR;

		if (m_colorG + m_dG>= 256 || m_colorG + m_dG<= 0)
		{
			
			m_dG = -m_dG;
			if (m_colorB + m_dB>= 256 || m_colorB + m_dB<= 256) m_dB = -m_dB;
			m_colorB+=m_dB;
		}
		m_colorG+=m_dG;
	}
	m_colorR+=m_dR;
	m_iStyle = m_colorR/35;
	if(m_iStyle > 5)
	{
		CBrush pBrush(RGB(m_colorR,m_colorG,m_colorB));
		MemDC2.FillRect(rect,&pBrush);
	}
	else	
	{
		//CBrush pBrush(m_iStyle, RGB(m_colorR,m_colorG,m_colorB));
		CBrush pBrush(RGB(m_colorR,m_colorG,m_colorB));
		MemDC2.FillRect(rect,&pBrush);
	}
	

	double iH,iM,iS;

	iH = clsDT.GetHour();
	iM = clsDT.GetMinute();
	iS = clsDT.GetSecond();

	iH = iH + iM / 60 + iS / 3600;
	iM = iM + iS / 60;

	CPen pen,pen1,*pOldPen;
	//pen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	//pOldPen = (CPen *)dc.SelectObject(&pen);
	//dc.MoveTo(oX,oY);
	//dc.LineTo( xH,yH);
	//dc.MoveTo(oX,oY);
	//dc.LineTo( xM,yM);
	//dc.MoveTo(oX,oY);
	//dc.LineTo( xS,yS);
	//dc.SelectObject(pOldPen);
	
	//xH = cos(ang + d_ang * iH * 5) * 140  + oX;
	//yH = sin(ang + d_ang * iH * 5) * 140 + oY;
	//xM = cos(ang + d_ang * iM) * 150 + oX;
	//yM = sin(ang + d_ang * iM) * 150 + oY;
	//xS = cos(ang + d_ang * iS) * 160 + oX;
	//yS = sin(ang + d_ang * iS) * 160 + oY;
	
	xH = cos(ang + d_ang * iH * 5) * (oX * 0.7)  + oX;
	yH = sin(ang + d_ang * iH * 5) * (oY * 0.7) + oY;
	xM = cos(ang + d_ang * iM) * (oX * 0.75) + oX;
	yM = sin(ang + d_ang * iM) * (oY * 0.75) + oY;
	xS = cos(ang + d_ang * iS) * (oX * 0.8) + oX;
	yS = sin(ang + d_ang * iS) * (oY * 0.8) + oY;
	

	pen1.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pOldPen = (CPen *)MemDC2.SelectObject(&pen1);

	//dc.Ellipse(20,20,390,390);
	MemDC2.Ellipse(oX * 0.1, oY * 0.1, oX * 1.95, oY * 1.95);
	for (int i = 1; i<=12 ; i++) 
	{
		double angTemp = ang;
		double xL = cos(angTemp + d_ang * i * 5) * (oX * 0.8) + oX;
		double yL = sin(angTemp + d_ang * i * 5) * (oY * 0.8) + oY;
		CRect rect(xL,yL,xL+15,yL+15);	
		CString strTL;
		strTL.Format("%i",i);
		CPen pen,pen1,*pOldPen;
		pen.CreatePen(PS_SOLID,1,RGB(255,0,255));
		pOldPen = (CPen *)MemDC2.SelectObject(&pen);

		MemDC2.DrawText(strTL,rect, DT_CENTER);
	
		MemDC2.SelectObject(pOldPen);
	}
	MemDC2.MoveTo(oX,oY);
	MemDC2.LineTo( xH,yH);
	MemDC2.MoveTo(oX,oY);
	MemDC2.LineTo( xM,yM);
	MemDC2.MoveTo(oX,oY);
	MemDC2.LineTo( xS,yS);
	CClockApp *pApp;
	pApp = (CClockApp *)AfxGetApp();
	//dc.DrawIcon(xS-16, yS-16, AfxGetApp()->LoadIcon(IDI_HEART));
	CBitmap *pOldBitmap = (CBitmap *)MemDC.SelectObject(&(pApp->bmpMask));
	MemDC2.BitBlt(xS-16,yS-16,32,32,&MemDC,0,0,SRCAND);
	MemDC.SelectObject(&(pApp->bmpHeart));
	MemDC2.BitBlt(xS-16,yS-16,32,32,&MemDC,0,0,SRCPAINT);
	dc.BitBlt(0,0,2000,2000,&MemDC2,0,0,SRCCOPY);
	MemDC.SelectObject(pOldBitmap);
	MemDC2.SelectObject(pOldPen);	
	CDialog::OnTimer(nIDEvent);
}


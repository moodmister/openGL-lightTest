// SlideControlDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "Glmfcn.h"
#include "SlideControlDlg.h"
#include "afxdialogex.h"


// SlideControlDlg dialog

IMPLEMENT_DYNAMIC(SlideControlDlg, CDialog)

SlideControlDlg::SlideControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, Red(0)
	, Green(0)
	, Blue(0)
{

}

SlideControlDlg::~SlideControlDlg()
{
}

void SlideControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, Red);
	DDV_MinMaxInt(pDX, Red, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER2, Green);
	DDV_MinMaxInt(pDX, Green, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER3, Blue);
	DDV_MinMaxInt(pDX, Blue, 0, 100);
}


BEGIN_MESSAGE_MAP(SlideControlDlg, CDialog)
END_MESSAGE_MAP()

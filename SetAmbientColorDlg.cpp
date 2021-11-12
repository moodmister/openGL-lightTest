// SetAmbientColorDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "Glmfcn.h"
#include "SetAmbientColorDlg.h"
#include "afxdialogex.h"


// SetAmbientColorDlg dialog

IMPLEMENT_DYNAMIC(SetAmbientColorDlg, CDialog)

SetAmbientColorDlg::SetAmbientColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, l_Red(0)
	, l_Green(0)
	, l_Blue(0)
	, l_amb(0)
{

}

SetAmbientColorDlg::~SetAmbientColorDlg()
{
}

void SetAmbientColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, l_Red);
	DDV_MinMaxInt(pDX, l_Red, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER2, l_Green);
	DDV_MinMaxInt(pDX, l_Green, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER3, l_Blue);
	DDV_MinMaxInt(pDX, l_Blue, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER4, l_amb);
	DDV_MinMaxInt(pDX, l_amb, 0, 100);
}


BEGIN_MESSAGE_MAP(SetAmbientColorDlg, CDialog)
END_MESSAGE_MAP()


// SetAmbientColorDlg message handlers

// SetSpecularLightDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "Glmfcn.h"
#include "SetSpecularLightDlg.h"
#include "afxdialogex.h"


// SetSpecularLightDlg dialog

IMPLEMENT_DYNAMIC(SetSpecularLightDlg, CDialog)

SetSpecularLightDlg::SetSpecularLightDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	, s_Red(0)
	, s_Green(0)
	, s_Blue(0)
	, s_spec(0)
{

}

SetSpecularLightDlg::~SetSpecularLightDlg()
{
}

void SetSpecularLightDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, s_Red);
	DDX_Slider(pDX, IDC_SLIDER2, s_Green);
	DDV_MinMaxInt(pDX, s_Green, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER3, s_Blue);
	DDV_MinMaxInt(pDX, s_Blue, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER4, s_spec);
	DDV_MinMaxInt(pDX, s_spec, 0, 100);
}


BEGIN_MESSAGE_MAP(SetSpecularLightDlg, CDialog)
END_MESSAGE_MAP()


// SetSpecularLightDlg message handlers

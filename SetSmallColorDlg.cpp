// SetSmallColorDlg.cpp : implementation file
//
#include "StdAfx.h"
#include "Glmfcn.h"
#include "SetSmallColorDlg.h"
#include "afxdialogex.h"


// SetSmallColorDlg dialog

IMPLEMENT_DYNAMIC(SetSmallColorDlg, CDialog)

SetSmallColorDlg::SetSmallColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, Red(0.0)
	, Green(0.0)
	, Blue(0.0)
{

}

SetSmallColorDlg::~SetSmallColorDlg()
{
}

void SetSmallColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, Red);
	DDV_MinMaxInt(pDX, Red, 0, 255);
	DDX_Slider(pDX, IDC_SLIDER2, Green);
	DDV_MinMaxInt(pDX, Green, 0, 255);
	DDX_Slider(pDX, IDC_SLIDER3, Blue);
	DDV_MinMaxInt(pDX, Blue, 0, 255);
}


BEGIN_MESSAGE_MAP(SetSmallColorDlg, CDialog)
END_MESSAGE_MAP()


// SetSmallColorDlg message handlers

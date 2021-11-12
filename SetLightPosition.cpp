// SetLightPosition.cpp : implementation file
//

#include "StdAfx.h"
#include "Glmfcn.h"
#include "SetLightPosition.h"
#include "afxdialogex.h"


// SetLightPosition dialog

IMPLEMENT_DYNAMIC(SetLightPosition, CDialog)

SetLightPosition::SetLightPosition(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG6, pParent)
	, p_y(0)
	, p_z(0)
	, p_w(0)
	, p_x(0)
{

}

SetLightPosition::~SetLightPosition()
{
}

void SetLightPosition::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER2, p_y);
	DDV_MinMaxInt(pDX, p_y, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER3, p_z);
	DDV_MinMaxInt(pDX, p_z, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER4, p_w);
	DDV_MinMaxInt(pDX, p_w, 0, 100);
	DDX_Slider(pDX, IDC_SLIDER1, p_x);
	DDV_MinMaxInt(pDX, p_x, 0, 100);
}


BEGIN_MESSAGE_MAP(SetLightPosition, CDialog)
END_MESSAGE_MAP()


// SetLightPosition message handlers

// SetShininessDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "Glmfcn.h"
#include "SetShininessDlg.h"
#include "afxdialogex.h"


// SetShininessDlg dialog

IMPLEMENT_DYNAMIC(SetShininessDlg, CDialog)

SetShininessDlg::SetShininessDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG5, pParent)
	, shininess(0)
{

}

SetShininessDlg::~SetShininessDlg()
{
}

void SetShininessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, shininess);
	DDV_MinMaxInt(pDX, shininess, 0, 100);
}


BEGIN_MESSAGE_MAP(SetShininessDlg, CDialog)
END_MESSAGE_MAP()


// SetShininessDlg message handlers

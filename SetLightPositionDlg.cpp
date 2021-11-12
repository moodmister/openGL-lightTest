// SetLightPositionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Glmfcn.h"
#include "afxdialogex.h"
#include "SetLightPositionDlg.h"


// SetLightPositionDlg dialog

IMPLEMENT_DYNAMIC(SetLightPositionDlg, CDialogEx)

SetLightPositionDlg::SetLightPositionDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, l_x(0)
	, l_y(0)
	, l_z(0)
	, l_w(0)
{

}

SetLightPositionDlg::~SetLightPositionDlg()
{
}

void SetLightPositionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, l_x);
	DDX_Text(pDX, IDC_EDIT2, l_y);
	DDX_Text(pDX, IDC_EDIT3, l_z);
	DDX_Text(pDX, IDC_EDIT4, l_w);
}


BEGIN_MESSAGE_MAP(SetLightPositionDlg, CDialog)
END_MESSAGE_MAP()


// SetLightPositionDlg message handlers

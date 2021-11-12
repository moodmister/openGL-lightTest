// SetLightDirectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Glmfcn.h"
#include "afxdialogex.h"
#include "SetLightDirectionDlg.h"


// SetLightDirectionDlg dialog

IMPLEMENT_DYNAMIC(SetLightDirectionDlg, CDialog)

SetLightDirectionDlg::SetLightDirectionDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, d_x(0)
	, d_y(0)
	, d_z(0)
{

}

SetLightDirectionDlg::~SetLightDirectionDlg()
{
}

void SetLightDirectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, d_x);
	DDX_Text(pDX, IDC_EDIT2, d_y);
	DDX_Text(pDX, IDC_EDIT3, d_z);
}


BEGIN_MESSAGE_MAP(SetLightDirectionDlg, CDialog)
END_MESSAGE_MAP()


// SetLightDirectionDlg message handlers

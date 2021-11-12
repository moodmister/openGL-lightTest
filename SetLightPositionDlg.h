#pragma once
#include "afxdialogex.h"


// SetLightPositionDlg dialog

class SetLightPositionDlg : public CDialog
{
	DECLARE_DYNAMIC(SetLightPositionDlg)

public:
	SetLightPositionDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SetLightPositionDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float l_x;
	float l_y;
	float l_z;
	float l_w;
};

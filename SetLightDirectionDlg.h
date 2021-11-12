#pragma once
#include "afxdialogex.h"


// SetLightDirectionDlg dialog

class SetLightDirectionDlg : public CDialog
{
	DECLARE_DYNAMIC(SetLightDirectionDlg)

public:
	SetLightDirectionDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SetLightDirectionDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	float d_x;
	float d_y;
	float d_z;
};

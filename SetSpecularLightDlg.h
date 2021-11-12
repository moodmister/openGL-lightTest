#pragma once


// SetSpecularLightDlg dialog

class SetSpecularLightDlg : public CDialog
{
	DECLARE_DYNAMIC(SetSpecularLightDlg)

public:
	SetSpecularLightDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SetSpecularLightDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int s_Red;
	int s_Green;
	int s_Blue;
	int s_spec;
};

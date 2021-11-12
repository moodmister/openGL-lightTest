#pragma once


// SetAmbientColorDlg dialog

class SetAmbientColorDlg : public CDialog
{
	DECLARE_DYNAMIC(SetAmbientColorDlg)

public:
	SetAmbientColorDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SetAmbientColorDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int l_Red;
	int l_Green;
	int l_Blue;
	int l_amb;
};

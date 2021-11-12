#pragma once


// SetSmallColorDlg dialog

class SetSmallColorDlg : public CDialog
{
	DECLARE_DYNAMIC(SetSmallColorDlg)

public:
	SetSmallColorDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SetSmallColorDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int Red;
	int Green;
	int Blue;
};

#pragma once


// SetShininessDlg dialog

class SetShininessDlg : public CDialog
{
	DECLARE_DYNAMIC(SetShininessDlg)

public:
	SetShininessDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SetShininessDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int shininess;
};

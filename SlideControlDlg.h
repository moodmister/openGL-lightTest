#pragma once


// SlideControlDlg dialog

class SlideControlDlg : public CDialog
{
	DECLARE_DYNAMIC(SlideControlDlg)

public:
	SlideControlDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SlideControlDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int Red;
	int Green;
	int Blue;
};

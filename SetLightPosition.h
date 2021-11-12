#pragma once


// SetLightPosition dialog

class SetLightPosition : public CDialog
{
	DECLARE_DYNAMIC(SetLightPosition)

public:
	SetLightPosition(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SetLightPosition();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	int p_x;
	afx_msg void OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult);
	int p_y;
	int p_z;
	int p_w;
	afx_msg void OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult);
};

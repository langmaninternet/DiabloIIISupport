
// DialoIIISupportDlg.h : header file
//

#pragma once


// CDialoIIISupportDlg dialog
class CDialoIIISupportDlg : public CDialogEx
{
// Construction
public:
	CDialoIIISupportDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOIIISUPPORT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	UINT_PTR myTimerID;
	afx_msg void OnTimer(UINT_PTR nIdEvent);
	



	DECLARE_MESSAGE_MAP()
};

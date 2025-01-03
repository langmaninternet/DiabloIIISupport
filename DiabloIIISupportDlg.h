
// DialoIIISupportDlg.h : header file
//

#pragma once


// CDialoIIISupportDlg dialog
class CDiabloIIISupportDlg : public CDialogEx
{
// Construction
public:
	CDiabloIIISupportDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIABLOIIISUPPORT_DIALOG };
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

	UINT_PTR mainTimerID;

	UINT_PTR autoTimerID;
	



	DECLARE_MESSAGE_MAP()

public:
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	afx_msg void OnHelp();


	afx_msg void OnTimer(UINT_PTR nIdEvent);
	afx_msg void OnLoadConfig();
	afx_msg void OnSaveConfig();
	afx_msg void OnKillFocusSkill01Time();
	afx_msg void OnKillFocusSkill02Time();
	afx_msg void OnKillFocusSkill03Time();
	afx_msg void OnKillFocusSkill04Time();


	afx_msg void OnShowSkillKey(int idW, wchar_t key);
	afx_msg void OnKillFocusSkillKey(int changeID, wchar_t & keySkill);
	afx_msg void OnKillFocusSkillKey01();
	afx_msg void OnKillFocusSkillKey02();
	afx_msg void OnKillFocusSkillKey03();
	afx_msg void OnKillFocusSkillKey04();
	afx_msg void OnKillFocusHealingKey();

	afx_msg void OnKillFocusTownPortalKey();

	afx_msg void OnClickedSkill01Check();
	afx_msg void OnClickedSkill02Check();
	afx_msg void OnClickedSkill03Check();
	afx_msg void OnClickedSkill04Check();
	afx_msg void OnClickedHealingCheck();



	afx_msg void OnKillFocusProfileName();
	afx_msg void OnBnClickedProfile();
	afx_msg void OnBnClickedProfile01();
	afx_msg void OnBnClickedProfile02();
	afx_msg void OnBnClickedProfile03();
	afx_msg void OnBnClickedProfile04();


	afx_msg void OnClickedRerollSupportCheck();

	afx_msg void OnClickedAutoBoneAmor();
	afx_msg void OnClickedAutoSimulacrum();
	afx_msg void OnClickedAutoPotion();
	afx_msg void OnChangeLicense();
	afx_msg void OnClickedAutoFanofknives();
	afx_msg void OnClickedAutoCompanion();
	afx_msg void OnClickedAutoSmokescreen();
	afx_msg void OnClickedAutoVengeance();
	afx_msg void OnClickedDump01Cdc2d();
	afx_msg void OnClickedDump02Cdc2d();
	afx_msg void OnClickedDump03Cdc2d();
	afx_msg void OnChangeDumpPercentValue();
	afx_msg void OnClickedAutoCommandSkeletons();
	afx_msg void OnClickedAutoArmyOfTheDead();
};

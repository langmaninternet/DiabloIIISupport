#include "stdafx.h"
#include "DiabloIIISupport.h"
#include "DiabloIIISupportDlg.h"
#include "afxdialogex.h"
#include <Windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Engine.h"


#include "map"



const double DiabloIIISupportVersion = 1.0;
/************************************************************************/
/* Struct                                                               */
/************************************************************************/
const int	maxProfileNumber = 10;
const int	maxProfileNameLength = 15;
const int	profileID[maxProfileNumber] =
{
IDC_PROFILE01,
IDC_PROFILE02,
IDC_PROFILE03,
IDC_PROFILE04,
IDC_PROFILE05,
IDC_PROFILE06,
IDC_PROFILE07,
IDC_PROFILE08,
IDC_PROFILE09,
IDC_PROFILE10,
};
struct DiabloIIISupportConfig
{
	int		leftMouseTime;
	int		rightMouseTime;
	int		skillSlot01Time;
	int		skillSlot02Time;
	int		skillSlot03Time;
	int		skillSlot04Time;
	int		healingTime;
	int		skill01Enable;
	int		skill02Enable;
	int		skill03Enable;
	int		skill04Enable;
	int		healingEnable;


	int     currentProfile;
	wchar_t profileName[maxProfileNumber + 1][maxProfileNameLength + 1];
	int		profileLeftMouseTime[maxProfileNumber + 1];
	int		profileRightMouseTime[maxProfileNumber + 1];
	int		profileSkillSlot01Time[maxProfileNumber + 1];
	int		profileSkillSlot02Time[maxProfileNumber + 1];
	int		profileSkillSlot03Time[maxProfileNumber + 1];
	int		profileSkillSlot04Time[maxProfileNumber + 1];
	int		profileHealingTime[maxProfileNumber + 1];
	int		profileSkill01Enable[maxProfileNumber + 1];
	int		profileSkill02Enable[maxProfileNumber + 1];
	int		profileSkill03Enable[maxProfileNumber + 1];
	int		profileSkill04Enable[maxProfileNumber + 1];
	int		profileHealingEnable[maxProfileNumber + 1];


	wchar_t	keySKill01;
	wchar_t	keySKill02;
	wchar_t	keySKill03;
	wchar_t	keySKill04;
	wchar_t	keyHealing;
	wchar_t keyTownPortal;


	int		autoBoneArmorEnable;
	int		autoSimulacrumEnable;
	int		autoPotion;



	double	saveDiabloIIISupportVersion;
};







/************************************************************************/
/* Variable                                                             */
/************************************************************************/
DiabloIIISupportConfig	d3Config;
wchar_t					configSavePath[3000] = { 0 };

int						enableRerollSupport = 0;

const int				mainTimerDelay = 30/*ms*/;
const int				autoCastRollTimerDelay = 100/*ms*/;


int						townPortalDelay = 0/*ms*/;

bool					flagOnF1 = false;
bool					flagOnF2 = false;
bool					flagOnF3 = false;
bool					flagOnCtrl5 = false;
bool					flagOnCtrl6 = false;
bool					flagOnCtrl7 = false;
bool					flagOnCtrl8 = false;
bool					flagOnCtrl9 = false;
bool					flagOnMainProcess = false;
bool					flagOnRollingProcess = false;


int						leftMouseCooldown;
int						rightMouseCooldown;
int						skillSlot01Cooldown;
int						skillSlot02Cooldown;
int						skillSlot03Cooldown;
int						skillSlot04Cooldown;
HHOOK					hGlobalHook;
time_t					last_main_timer;
extern D3Engine			d3Engine;



/************************************************************************/
/* Process Function                                                     */
/************************************************************************/
void		ValidateD3Key(wchar_t& keyValue, const wchar_t defaultValue)
{
	if (keyValue == '`') keyValue = '~';
	if (!((keyValue >= 'A' && keyValue <= 'Z')
		|| (keyValue >= '0' && keyValue <= '9')
		|| keyValue == ' '
		|| keyValue == '~'
		|| keyValue == VK_SHIFT
		|| keyValue == VK_CONTROL
		|| keyValue == VK_LBUTTON
		|| keyValue == VK_RBUTTON
		))
	{
		keyValue = defaultValue;
	}
}
void		ValidateD3Config(void)
{
	d3Config.leftMouseTime = int(round(d3Config.leftMouseTime / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.rightMouseTime = int(round(d3Config.rightMouseTime / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.skillSlot01Time = int(round(d3Config.skillSlot01Time / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.skillSlot02Time = int(round(d3Config.skillSlot02Time / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.skillSlot03Time = int(round(d3Config.skillSlot03Time / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.skillSlot04Time = int(round(d3Config.skillSlot04Time / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.healingTime = int(round(d3Config.healingTime / double(mainTimerDelay)) * mainTimerDelay);
	if (d3Config.leftMouseTime < mainTimerDelay) d3Config.leftMouseTime = mainTimerDelay;
	if (d3Config.rightMouseTime < mainTimerDelay) d3Config.rightMouseTime = mainTimerDelay;
	if (d3Config.skillSlot01Time < mainTimerDelay) d3Config.skillSlot01Time = mainTimerDelay;
	if (d3Config.skillSlot02Time < mainTimerDelay) d3Config.skillSlot02Time = mainTimerDelay;
	if (d3Config.skillSlot03Time < mainTimerDelay) d3Config.skillSlot03Time = mainTimerDelay;
	if (d3Config.skillSlot04Time < mainTimerDelay) d3Config.skillSlot04Time = mainTimerDelay;
	if (d3Config.healingTime < mainTimerDelay) d3Config.healingTime = mainTimerDelay;


	if (d3Config.skill01Enable != 0) d3Config.skill01Enable = 1;
	if (d3Config.skill02Enable != 0) d3Config.skill02Enable = 1;
	if (d3Config.skill03Enable != 0) d3Config.skill03Enable = 1;
	if (d3Config.skill04Enable != 0) d3Config.skill04Enable = 1;
	if (d3Config.healingEnable != 0) d3Config.healingEnable = 1;
	if (d3Config.currentProfile < 0 || d3Config.currentProfile >= maxProfileNumber) d3Config.currentProfile = 0;

	for (int iprofile = 0; iprofile < maxProfileNumber; iprofile++)
	{
		if (d3Config.profileName[iprofile][0] == 0)
		{
			swprintf_s(d3Config.profileName[iprofile], L"Profile %02d", iprofile);
		}
		d3Config.profileLeftMouseTime[iprofile] = int(round(d3Config.profileLeftMouseTime[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileRightMouseTime[iprofile] = int(round(d3Config.profileRightMouseTime[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileSkillSlot01Time[iprofile] = int(round(d3Config.profileSkillSlot01Time[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileSkillSlot02Time[iprofile] = int(round(d3Config.profileSkillSlot02Time[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileSkillSlot03Time[iprofile] = int(round(d3Config.profileSkillSlot03Time[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileSkillSlot04Time[iprofile] = int(round(d3Config.profileSkillSlot04Time[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileHealingTime[iprofile] = int(round(d3Config.profileHealingTime[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		if (d3Config.profileLeftMouseTime[iprofile] < mainTimerDelay) d3Config.profileLeftMouseTime[iprofile] = mainTimerDelay;
		if (d3Config.profileRightMouseTime[iprofile] < mainTimerDelay) d3Config.profileRightMouseTime[iprofile] = mainTimerDelay;
		if (d3Config.profileSkillSlot01Time[iprofile] < mainTimerDelay) d3Config.profileSkillSlot01Time[iprofile] = mainTimerDelay;
		if (d3Config.profileSkillSlot02Time[iprofile] < mainTimerDelay) d3Config.profileSkillSlot02Time[iprofile] = mainTimerDelay;
		if (d3Config.profileSkillSlot03Time[iprofile] < mainTimerDelay) d3Config.profileSkillSlot03Time[iprofile] = mainTimerDelay;
		if (d3Config.profileSkillSlot04Time[iprofile] < mainTimerDelay) d3Config.profileSkillSlot04Time[iprofile] = mainTimerDelay;
		if (d3Config.profileHealingTime[iprofile] < mainTimerDelay) d3Config.profileHealingTime[iprofile] = mainTimerDelay;
		if (d3Config.profileSkill01Enable[iprofile] != 0) d3Config.profileSkill01Enable[iprofile] = 1;
		if (d3Config.profileSkill02Enable[iprofile] != 0) d3Config.profileSkill02Enable[iprofile] = 1;
		if (d3Config.profileSkill03Enable[iprofile] != 0) d3Config.profileSkill03Enable[iprofile] = 1;
		if (d3Config.profileSkill04Enable[iprofile] != 0) d3Config.profileSkill04Enable[iprofile] = 1;
		if (d3Config.profileHealingEnable[iprofile] != 0) d3Config.profileHealingEnable[iprofile] = 1;
	}




	ValidateD3Key(d3Config.keySKill01, '1');
	ValidateD3Key(d3Config.keySKill02, '2');
	ValidateD3Key(d3Config.keySKill03, '3');
	ValidateD3Key(d3Config.keySKill04, '4');
	ValidateD3Key(d3Config.keyHealing, 'Q');


	//wiz
	ValidateD3Key(d3Config.keyTownPortal, 'T');



	/************************************************************************/
	/* Force                                                                */
	/************************************************************************/
	d3Config.healingTime = mainTimerDelay;
}


HWND		GetD3Windows(void)
{
	HWND d3Wnd = FindWindowW(L"D3 Main Window Class", L"Diablo III");
	if (d3Wnd == NULL) d3Wnd = FindWindowW(L"D3 Main Window Class", NULL);
	if (d3Wnd == NULL) d3Wnd = FindWindowW(NULL, L"Diablo III");
	return d3Wnd;
}
bool		IsD3WindowActive(void)
{
	HWND		currentHWD = GetForegroundWindow();
	if (currentHWD == GetD3Windows()) return true;
	return false;
}
void		SendD3LeftMouseClick()
{
	HWND d3Wnd = GetD3Windows();
	if (d3Wnd)
	{
		POINT point = { 0 };
		GetCursorPos(&point);

		RECT d3Rect = { 0 };
		GetWindowRect(d3Wnd, &d3Rect);

		LPARAM lParam = (point.x - d3Rect.left) | ((point.y - d3Rect.top) << 16);

		SendMessage(d3Wnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
		Sleep(10 + (rand() % 3));
		SendMessage(d3Wnd, WM_LBUTTONUP, 0, lParam);
		Sleep(10 + (rand() % 3));
	}
}
void		SendD3RightMouseHold()
{
	HWND d3Wnd = GetD3Windows();
	if (d3Wnd)
	{
		POINT point = { 0 };
		GetCursorPos(&point);

		RECT d3Rect = { 0 };
		GetWindowRect(d3Wnd, &d3Rect);

		LPARAM lParam = (point.x - d3Rect.left) | ((point.y - d3Rect.top) << 16);

		SendMessage(d3Wnd, WM_RBUTTONDOWN, MK_RBUTTON, lParam);
		Sleep(10 + (rand() % 3));
		//SendMessage(d3Wnd, WM_RBUTTONUP, 0, lParam);
		//Sleep(10 + (rand() % 3));
	}
}
void		SendD3RightMouseClick()
{
	HWND d3Wnd = GetD3Windows();
	if (d3Wnd)
	{
		POINT point = { 0 };
		GetCursorPos(&point);

		RECT d3Rect = { 0 };
		GetWindowRect(d3Wnd, &d3Rect);

		LPARAM lParam = (point.x - d3Rect.left) | ((point.y - d3Rect.top) << 16);

		SendMessage(d3Wnd, WM_RBUTTONDOWN, MK_RBUTTON, lParam);
		Sleep(10 + (rand() % 3));
		SendMessage(d3Wnd, WM_RBUTTONUP, 0, lParam);
		Sleep(10 + (rand() % 3));
	}
}
void		SendD3Key(int keyCode)
{
	HWND d3Wnd = GetD3Windows();
	if (d3Wnd)
	{
		SendMessage(d3Wnd, WM_KEYDOWN, keyCode, 0);
		Sleep(10 + (rand() % 3));
		SendMessage(d3Wnd, WM_KEYUP, keyCode, 0);
		Sleep(10 + (rand() % 3));
	}
}
void		SetD3Mouse(int x, int y)
{
	HWND d3Wnd = GetD3Windows();
	if (d3Wnd)
	{
		RECT d3Rect = { 0 };
		GetWindowRect(d3Wnd, &d3Rect);
		SetCursorPos(d3Rect.left + x, d3Rect.top + y);
	}
}
void		HoldShift(void)
{
	HWND d3Wnd = GetD3Windows();
	if (d3Wnd)
	{
		SendMessage(d3Wnd, WM_KEYDOWN, VK_SHIFT, 0);
		Sleep(10 + (rand() % 3));
	}
}
void		ReleaseShift(void)
{
	HWND d3Wnd = GetD3Windows();
	if (d3Wnd)
	{
		SendMessage(d3Wnd, WM_KEYUP, VK_SHIFT, 0);
		Sleep(10 + (rand() % 3));
	}
}
bool		PointInRect(POINT point, int rLeft, int rRight, int rTop, int rBottom)
{
	if (rLeft >= rRight || rTop >= rBottom)
	{
		MessageBox(0, L"D3 Engine Error!!", L"(rLeft <= rRight || rTop <= rBottom)", MB_OK);
	}
	return (point.x > rLeft && point.x < rRight && point.y > rTop && point.y < rBottom);
}
bool		ValidToSendD3Click(void)
{
	if (IsD3WindowActive())
	{
		HWND d3Wnd = GetD3Windows();
		if (d3Wnd)
		{
			RECT d3Rect = { 0 };
			GetWindowRect(d3Wnd, &d3Rect);
			if (d3Rect.right > d3Rect.left && d3Rect.bottom > d3Rect.top)
			{
				POINT point = { 0 };
				GetCursorPos(&point);
				if (PointInRect(point, d3Rect.left, d3Rect.right, d3Rect.top, d3Rect.bottom))
				{
					if (d3Rect.right - d3Rect.left == 1920 && d3Rect.bottom - d3Rect.top == 1080)
					{
						//chat button
						if (PointInRect(point, d3Rect.left + 10, d3Rect.left + 80, d3Rect.top + 980, d3Rect.top + 1044))
						{
							return false;
						}

						//Skill, Inventory,...
						if (PointInRect(point, d3Rect.left + 1089, d3Rect.left + 1284, d3Rect.top + 995, d3Rect.top + 1062))
						{
							return false;
						}

						//Friend Button
						if (PointInRect(point, d3Rect.left + 1764, d3Rect.left + 1904, d3Rect.top + 979, d3Rect.top + 1044))
						{
							return false;
						}

						//Small chat box
						if (PointInRect(point, d3Rect.left + 32, d3Rect.left + 346, d3Rect.top + 738, d3Rect.top + 877))
						{
							return false;
						}

						//Season Journey Button
						if (PointInRect(point, d3Rect.left + 1649, d3Rect.left + 1698, d3Rect.top + 25, d3Rect.top + 51))
						{
							return false;
						}

						//Objectives Object
						if (PointInRect(point, d3Rect.left + 1862, d3Rect.left + 1893, d3Rect.top + 367, d3Rect.top + 391))
						{
							return false;
						}

						//Main-Player
						if (PointInRect(point, d3Rect.left + 28, d3Rect.left + 93, d3Rect.top + 47, d3Rect.top + 149))
						{
							return false;
						}
					}


					return true;
				}
			}
		}
	}
	return false;
}


/************************************************************************/
/* Hook                                                                 */
/************************************************************************/
extern "C" __declspec(dllexport) LRESULT CALLBACK HookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	static bool flagOnCtrl = false;
	bool		flagNeedMoreHook = true;
	if (nCode >= 0 && nCode == HC_ACTION)
	{
		LPKBDLLHOOKSTRUCT keyParam = (LPKBDLLHOOKSTRUCT)(void*)lParam;
		if (wParam == WM_KEYUP)
		{
			switch (keyParam->vkCode)
			{
			case VK_LCONTROL:
			case VK_RCONTROL:
				flagOnCtrl = false;
				break;
			case VK_F1:
				if (IsD3WindowActive()) flagNeedMoreHook = false;
				break;
			}
		}
		else if (wParam == WM_KEYDOWN)
		{
			switch (keyParam->vkCode)
			{
			case VK_F1:
				flagNeedMoreHook = false;
				flagOnF1 = !flagOnF1;
				flagOnCtrl = false;
				flagOnCtrl5 = false;
				flagOnCtrl6 = false;
				flagOnCtrl7 = false;
				flagOnCtrl8 = false;
				flagOnCtrl9 = false;
				leftMouseCooldown = 99999;
				break;
			case VK_F2:
				flagOnF2 = !flagOnF2;
				flagOnCtrl = false;
				flagOnCtrl5 = false;
				flagOnCtrl6 = false;
				flagOnCtrl7 = false;
				flagOnCtrl8 = false;
				flagOnCtrl9 = false;
				skillSlot01Cooldown = 99999;
				skillSlot02Cooldown = 99999;
				skillSlot03Cooldown = 99999;
				skillSlot04Cooldown = 99999;
				break;
			case VK_F3:
				flagOnF3 = !flagOnF3;
				flagOnCtrl = false;
				flagOnCtrl5 = false;
				flagOnCtrl6 = false;
				flagOnCtrl7 = false;
				flagOnCtrl8 = false;
				flagOnCtrl9 = false;
				rightMouseCooldown = 99999;
				break;
			case VK_ESCAPE:
			case VK_SPACE:
				enableRerollSupport = false;

				flagOnCtrl = false;
				flagOnCtrl5 = false;
				flagOnCtrl6 = false;
				flagOnCtrl7 = false;
				flagOnCtrl8 = false;
				flagOnCtrl9 = false;


#ifdef _DEBUG
			case VK_F5:
				QuangBTDumpScreen();
				break;
#endif


			case 0x35/*'5'*/:
				if (flagOnCtrl)
				{
					flagOnF1 = false;
					flagOnF2 = false;
					flagOnF3 = false;
					flagOnCtrl5 = true;
					flagOnCtrl6 = false;
					flagOnCtrl7 = false;
					flagOnCtrl8 = false;
					flagOnCtrl9 = false;
				}
				break;
			case 0x36/*'6'*/:
				if (flagOnCtrl)
				{
					flagOnF1 = false;
					flagOnF2 = false;
					flagOnF3 = false;
					flagOnCtrl5 = false;
					flagOnCtrl6 = true;
					flagOnCtrl7 = false;
					flagOnCtrl8 = false;
					flagOnCtrl9 = false;
				}
				break;
			case 0x37/*'7'*/:
				if (flagOnCtrl)
				{
					flagOnF1 = false;
					flagOnF2 = false;
					flagOnF3 = false;
					flagOnCtrl5 = false;
					flagOnCtrl6 = false;
					flagOnCtrl7 = true;
					flagOnCtrl8 = false;
					flagOnCtrl9 = false;
				}
				break;
			case 0x38/*'8'*/:
				if (flagOnCtrl)
				{
					flagOnF1 = false;
					flagOnF2 = false;
					flagOnF3 = false;
					flagOnCtrl5 = false;
					flagOnCtrl6 = false;
					flagOnCtrl7 = false;
					flagOnCtrl8 = true;
					flagOnCtrl9 = false;
				}
				break;
			case 0x39/*'9'*/:
				if (flagOnCtrl)
				{
					flagOnF1 = false;
					flagOnF2 = false;
					flagOnF3 = false;
					flagOnCtrl5 = false;
					flagOnCtrl6 = false;
					flagOnCtrl7 = false;
					flagOnCtrl8 = false;
					flagOnCtrl9 = true;
				}
				break;

			case VK_LCONTROL:
			case VK_RCONTROL:
				flagOnCtrl = true;
				break;
			default:

				break;
			}
		}

		if (keyParam->vkCode == d3Config.keyTownPortal)
		{
			townPortalDelay = 11000/*ms*/;
		}
	}
	if (flagNeedMoreHook == false)
	{
		return 1;
	}
	return CallNextHookEx(hGlobalHook, nCode, wParam, lParam);
}





/************************************************************************/
/* MFC                                                                  */
/************************************************************************/
/**/		CDiabloIIISupportDlg::CDiabloIIISupportDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIABLOIIISUPPORT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void		CDiabloIIISupportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDiabloIIISupportDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_EN_KILLFOCUS(IDC_LEFTMOUSETIME, &CDiabloIIISupportDlg::OnKillFocusLeftMouseTime)
	ON_EN_KILLFOCUS(IDC_RIGHTMOUSETIME, &CDiabloIIISupportDlg::OnKillFocusRightMouseTime)
	ON_EN_KILLFOCUS(IDC_SKILL01TIME, &CDiabloIIISupportDlg::OnKillFocusSkill01Time)
	ON_EN_KILLFOCUS(IDC_SKILL02TIME, &CDiabloIIISupportDlg::OnKillFocusSkill02Time)
	ON_EN_KILLFOCUS(IDC_SKILL03TIME, &CDiabloIIISupportDlg::OnKillFocusSkill03Time)
	ON_EN_KILLFOCUS(IDC_SKILL04TIME, &CDiabloIIISupportDlg::OnKillFocusSkill04Time)
	ON_BN_CLICKED(IDC_SKILL01CHECK, &CDiabloIIISupportDlg::OnClickedSkill01Check)
	ON_BN_CLICKED(IDC_SKILL02CHECK, &CDiabloIIISupportDlg::OnClickedSkill02Check)
	ON_BN_CLICKED(IDC_SKILL03CHECK, &CDiabloIIISupportDlg::OnClickedSkill03Check)
	ON_BN_CLICKED(IDC_SKILL04CHECK, &CDiabloIIISupportDlg::OnClickedSkill04Check)
	ON_BN_CLICKED(IDC_HEALINGCHECK, &CDiabloIIISupportDlg::OnClickedHealingCheck)
	ON_COMMAND(ID_HELP, &CDiabloIIISupportDlg::OnHelp)
	ON_EN_KILLFOCUS(IDC_PROFILENAME, &CDiabloIIISupportDlg::OnKillFocusProfileName)
	ON_BN_CLICKED(IDC_PROFILE01, &CDiabloIIISupportDlg::OnBnClickedProfile01)
	ON_BN_CLICKED(IDC_PROFILE02, &CDiabloIIISupportDlg::OnBnClickedProfile02)
	ON_BN_CLICKED(IDC_PROFILE03, &CDiabloIIISupportDlg::OnBnClickedProfile03)
	ON_BN_CLICKED(IDC_PROFILE04, &CDiabloIIISupportDlg::OnBnClickedProfile04)
	ON_BN_CLICKED(IDC_PROFILE05, &CDiabloIIISupportDlg::OnBnClickedProfile05)
	ON_BN_CLICKED(IDC_PROFILE06, &CDiabloIIISupportDlg::OnBnClickedProfile06)
	ON_BN_CLICKED(IDC_PROFILE07, &CDiabloIIISupportDlg::OnBnClickedProfile07)
	ON_BN_CLICKED(IDC_PROFILE08, &CDiabloIIISupportDlg::OnBnClickedProfile08)
	ON_BN_CLICKED(IDC_PROFILE09, &CDiabloIIISupportDlg::OnBnClickedProfile09)
	ON_BN_CLICKED(IDC_PROFILE10, &CDiabloIIISupportDlg::OnBnClickedProfile10)
	ON_EN_KILLFOCUS(IDC_SKILLKEY01, &CDiabloIIISupportDlg::OnKillFocusSkillKey01)
	ON_EN_KILLFOCUS(IDC_SKILLKEY02, &CDiabloIIISupportDlg::OnKillFocusSkillKey02)
	ON_EN_KILLFOCUS(IDC_SKILLKEY03, &CDiabloIIISupportDlg::OnKillFocusSkillKey03)
	ON_EN_KILLFOCUS(IDC_SKILLKEY04, &CDiabloIIISupportDlg::OnKillFocusSkillKey04)
	ON_EN_KILLFOCUS(IDC_HEALINGKEY, &CDiabloIIISupportDlg::OnKillFocusHealingKey)
	ON_EN_KILLFOCUS(IDC_TOWNPORTALKEY, &CDiabloIIISupportDlg::OnKillFocusTownPortalKey)
	ON_BN_CLICKED(IDC_ENABLE_REROLL_SUPPORT, &CDiabloIIISupportDlg::OnClickedRerollSupportCheck)

	ON_BN_CLICKED(IDC_AUTO_BONE_AMOR, &CDiabloIIISupportDlg::OnClickedAutoBoneAmor)
	ON_BN_CLICKED(IDC_AUTO_SIMULACRUM, &CDiabloIIISupportDlg::OnClickedAutoSimulacrum)
	ON_BN_CLICKED(IDC_AUTO_POTION, &CDiabloIIISupportDlg::OnClickedAutoPotion)
END_MESSAGE_MAP()

BOOL		CDiabloIIISupportDlg::OnInitDialog()
{
	// Create mutex
	HANDLE hMutex = CreateMutex(NULL, TRUE, L"Diablo III Support");
	switch (GetLastError())
	{
	case ERROR_SUCCESS:
		// Mutex created successfully. There is 
		// no instances running
		break;

	case ERROR_ALREADY_EXISTS:
		// Mutex already exists so there is a 
		// running instance of our app.
		hMutex = NULL;
		exit(EXIT_SUCCESS);
		break;

	default:
		// Failed to create mutex by unknown reason
		break;
	}

	srand((unsigned int)time((time_t*)0));




	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	mainTimerID = CDialogEx::SetTimer(1, mainTimerDelay, NULL);
	autoCastRollTimerID = CDialogEx::SetTimer(2, autoCastRollTimerDelay, NULL);



	if (configSavePath[0] == 0)
	{
		wchar_t appdataPath[2000] = { 0 };
		GetEnvironmentVariable(L"AppData", appdataPath, 1999);
		wchar_t bufferDir[2000] = { 0 };
		swprintf_s(bufferDir, L"%ls\\DiabloIIISupport\\", appdataPath);
		CreateDirectoryW(bufferDir, 0);
		swprintf_s(configSavePath, L"%ls\\DiabloIIISupport\\DiabloIIISupport.dat", appdataPath);
	}

	OnLoadConfig();

	ValidateD3Config();
	wchar_t buffer[1000] = { 0 };

	swprintf_s(buffer, L"%d", d3Config.leftMouseTime);
	GetDlgItem(IDC_LEFTMOUSETIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.rightMouseTime);
	GetDlgItem(IDC_RIGHTMOUSETIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot01Time);
	GetDlgItem(IDC_SKILL01TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot02Time);
	GetDlgItem(IDC_SKILL02TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot03Time);
	GetDlgItem(IDC_SKILL03TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot04Time);
	GetDlgItem(IDC_SKILL04TIME)->SetWindowText(buffer);


	swprintf_s(buffer, L"Diablo III Support Version %0.2lf", DiabloIIISupportVersion);
	SetWindowTextW(buffer);


	GetDlgItem(IDC_SKILL01TIME)->EnableWindow(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL02TIME)->EnableWindow(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL03TIME)->EnableWindow(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL04TIME)->EnableWindow(d3Config.skill04Enable);
	GetDlgItem(IDC_SKILL01TEXT)->EnableWindow(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL02TEXT)->EnableWindow(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL03TEXT)->EnableWindow(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL04TEXT)->EnableWindow(d3Config.skill04Enable);
	GetDlgItem(IDC_SKILL01TEXTMS)->EnableWindow(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL02TEXTMS)->EnableWindow(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL03TEXTMS)->EnableWindow(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL04TEXTMS)->EnableWindow(d3Config.skill04Enable);
	GetDlgItem(IDC_HEALINGTEXTMS)->EnableWindow(d3Config.healingEnable);


	((CButton*)GetDlgItem(IDC_SKILL01CHECK))->SetCheck(d3Config.skill01Enable);
	((CButton*)GetDlgItem(IDC_SKILL02CHECK))->SetCheck(d3Config.skill02Enable);
	((CButton*)GetDlgItem(IDC_SKILL03CHECK))->SetCheck(d3Config.skill03Enable);
	((CButton*)GetDlgItem(IDC_SKILL04CHECK))->SetCheck(d3Config.skill04Enable);
	((CButton*)GetDlgItem(IDC_HEALINGCHECK))->SetCheck(d3Config.healingEnable);
	((CButton*)GetDlgItem(IDC_ENABLE_REROLL_SUPPORT))->SetCheck(enableRerollSupport);
	GetDlgItem(IDC_REROL_SUPPORT_DETAIL)->EnableWindow(enableRerollSupport);


	((CButton*)GetDlgItem(IDC_AUTO_BONE_AMOR))->SetCheck(d3Config.autoBoneArmorEnable);
	((CButton*)GetDlgItem(IDC_AUTO_SIMULACRUM))->SetCheck(d3Config.autoSimulacrumEnable);

	OnShowSkillKey(IDC_SKILLKEY01, d3Config.keySKill01);
	OnShowSkillKey(IDC_SKILLKEY02, d3Config.keySKill02);
	OnShowSkillKey(IDC_SKILLKEY03, d3Config.keySKill03);
	OnShowSkillKey(IDC_SKILLKEY04, d3Config.keySKill04);
	OnShowSkillKey(IDC_HEALINGKEY, d3Config.keyHealing);
	OnShowSkillKey(IDC_TOWNPORTALKEY, d3Config.keyTownPortal);



	for (int iprofile = 0; iprofile < maxProfileNumber; iprofile++)
	{
		CString currentProfileName = d3Config.profileName[iprofile];
		if (iprofile == d3Config.currentProfile)
		{
			GetDlgItem(IDC_PROFILENAME)->SetWindowTextW(currentProfileName);
			currentProfileName.Insert(0, L"> ");
		}
		GetDlgItem(profileID[iprofile])->SetWindowTextW(currentProfileName);
	}


	GetDlgItem(IDC_FORCE_TO_DPS)->EnableWindow(enableRerollSupport);



	hGlobalHook = SetWindowsHookEx(WH_KEYBOARD_LL, HookProc, GetModuleHandle(NULL), 0);


	return TRUE;  // return TRUE  unless you set the focus to a control
}
void		CDiabloIIISupportDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
HCURSOR		CDiabloIIISupportDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void		CDiabloIIISupportDlg::WinHelp(DWORD dwData, UINT nCmd)
{//prevent help to use F1 

}
void		CDiabloIIISupportDlg::OnHelp()
{
	// TODO: Add your command handler code here
}









/************************************************************************/
/*                                                                      */
/************************************************************************/
void CDiabloIIISupportDlg::OnTimer(UINT_PTR nIdEvent)
{
	if (mainTimerID == nIdEvent)
	{
		time_t current_timer;
		time(&current_timer);
		int elapsed_time = (difftime(current_timer, last_main_timer) * 1000);
		last_main_timer = current_timer;
		if (flagOnMainProcess == false)
		{
			flagOnMainProcess = true;


			WCHAR bufferActive[100] = L"Found";

			HWND d3Wnd = GetD3Windows();
			RECT d3Rect = { 0 };
			if (d3Wnd == 0)
			{
				bufferActive[0] = NULL;
				flagOnF1 = false;
				flagOnF2 = false;
				flagOnF3 = false;
			}
			else
			{
				::GetWindowRect(d3Wnd, &d3Rect);
			}
			POINT point = { 0 };
			GetCursorPos(&point);
			const WCHAR* validToClick = L"";
			if (ValidToSendD3Click())  validToClick = L"Vaild to click";
			CString debugInfo;
			debugInfo.AppendFormat(L"Diablo III: %ls\r\n	X: %04d     Y: %04d\r\n	W: %04d     H: %04d\r\nCursor: %ls\r\n	X : %04d     Y : %04d\r\n",
				bufferActive,
				d3Rect.left,
				d3Rect.top,
				d3Rect.right - d3Rect.left,
				d3Rect.bottom - d3Rect.top,
				validToClick,
				point.x,
				point.y
			);


			GetDlgItem(IDC_DEBUGINFO)->SetWindowTextW(debugInfo);

			if (elapsed_time > mainTimerDelay)
			{
				elapsed_time -= mainTimerDelay;
			}
			else
			{
				elapsed_time = 0;
			}



			bool flagPotionReady = true;
			bool flagIsOpenUrshi = false;
			bool flagIsOpenStash = false;
			if (d3Engine.ValidMode())
			{
				d3Engine.CaptureDesktop();
				flagIsOpenUrshi = d3Engine.D3IsOpenUrshi();
				flagIsOpenStash = d3Engine.D3IsOpenStash();
				if (d3Engine.GetPixel(1062, 1001) == 0x020202) flagPotionReady = false;
			}

			if (flagIsOpenUrshi)
			{
				flagOnF1 = false;
				flagOnF2 = false;
				flagOnF3 = false;
			}



			/************************************************************************/
			/* Skill Press                                                          */
			/************************************************************************/
			if (d3Engine.D3IsViewMap() == false
				&& d3Engine.D3IsOpenSkillTable() == false
				&& flagIsOpenUrshi == false
				&& d3Engine.D3IsOpenKadala() == false
				&& d3Engine.D3IsOpenStash() == false
				)
			{

				/************************************************************************/
				/* Use custom                                                           */
				/************************************************************************/
				if (flagOnF2) GetDlgItem(IDC_F2BIGFRAME)->SetWindowTextW(L"Skill (Hotkey F2) - Running");
				if (flagOnF2)
				{
					GetDlgItem(IDC_SKILL01TIME)->EnableWindow(FALSE);
					GetDlgItem(IDC_SKILL02TIME)->EnableWindow(FALSE);
					GetDlgItem(IDC_SKILL03TIME)->EnableWindow(FALSE);
					GetDlgItem(IDC_SKILL04TIME)->EnableWindow(FALSE);
					GetDlgItem(IDC_SKILL01CHECK)->EnableWindow(FALSE);
					GetDlgItem(IDC_SKILL02CHECK)->EnableWindow(FALSE);
					GetDlgItem(IDC_SKILL03CHECK)->EnableWindow(FALSE);
					GetDlgItem(IDC_SKILL04CHECK)->EnableWindow(FALSE);
					GetDlgItem(IDC_HEALINGCHECK)->EnableWindow(FALSE);

					if (d3Config.skill01Enable)
					{
						skillSlot01Cooldown += mainTimerDelay + elapsed_time;
						if (skillSlot01Cooldown >= d3Config.skillSlot01Time)
						{
							SendD3Key(d3Config.keySKill01);
							skillSlot01Cooldown = 0;
						}
					}
					if (d3Config.skill02Enable)
					{
						skillSlot02Cooldown += mainTimerDelay + elapsed_time;
						if (skillSlot02Cooldown >= d3Config.skillSlot02Time)
						{
							SendD3Key(d3Config.keySKill02);
							skillSlot02Cooldown = 0;
						}
					}
					if (d3Config.skill03Enable)
					{
						skillSlot03Cooldown += mainTimerDelay + elapsed_time;
						if (skillSlot03Cooldown >= d3Config.skillSlot03Time)
						{
							SendD3Key(d3Config.keySKill03);
							skillSlot03Cooldown = 0;
						}
					}
					if (d3Config.skill04Enable)
					{
						skillSlot04Cooldown += mainTimerDelay + elapsed_time;
						if (skillSlot04Cooldown >= d3Config.skillSlot04Time)
						{
							SendD3Key(d3Config.keySKill04);
							skillSlot04Cooldown = 0;
						}
					}
					if (d3Config.healingEnable && flagPotionReady)
					{
						SendD3Key(d3Config.keyHealing);
					}

				}
				else
				{
					if (d3Config.skill01Enable) GetDlgItem(IDC_SKILL01TIME)->EnableWindow(TRUE);
					if (d3Config.skill02Enable) GetDlgItem(IDC_SKILL02TIME)->EnableWindow(TRUE);
					if (d3Config.skill03Enable) GetDlgItem(IDC_SKILL03TIME)->EnableWindow(TRUE);
					if (d3Config.skill04Enable) GetDlgItem(IDC_SKILL04TIME)->EnableWindow(TRUE);
					GetDlgItem(IDC_SKILL01CHECK)->EnableWindow(TRUE);
					GetDlgItem(IDC_SKILL02CHECK)->EnableWindow(TRUE);
					GetDlgItem(IDC_SKILL03CHECK)->EnableWindow(TRUE);
					GetDlgItem(IDC_SKILL04CHECK)->EnableWindow(TRUE);
					GetDlgItem(IDC_HEALINGCHECK)->EnableWindow(TRUE);
					GetDlgItem(IDC_F2BIGFRAME)->SetWindowTextW(L"Skill (Hotkey F2)");
				}

				if (flagOnF1) GetDlgItem(IDC_LEFTMOUSETEXT)->SetWindowText(L"Left mouse (Hotkey F1): \r\n	Running");
				if (flagOnF1)
				{
					GetDlgItem(IDC_LEFTMOUSETEXT)->EnableWindow(FALSE);
					GetDlgItem(IDC_LEFTMOUSETEXTMS)->EnableWindow(FALSE);
					GetDlgItem(IDC_LEFTMOUSETIME)->EnableWindow(FALSE);
					if (d3Wnd != 0)
					{
						leftMouseCooldown += mainTimerDelay;
						if (leftMouseCooldown >= d3Config.leftMouseTime)
						{
							if (ValidToSendD3Click()) SendD3LeftMouseClick();
							leftMouseCooldown = 0;
						}
					}
				}
				else
				{
					GetDlgItem(IDC_LEFTMOUSETEXT)->SetWindowText(L"Left mouse (Hotkey F1): ");
					GetDlgItem(IDC_LEFTMOUSETEXT)->EnableWindow(TRUE);
					GetDlgItem(IDC_LEFTMOUSETEXTMS)->EnableWindow(TRUE);
					GetDlgItem(IDC_LEFTMOUSETIME)->EnableWindow(TRUE);
				}


				if (flagOnF3) GetDlgItem(IDC_RIGHTMOUSETEXT)->SetWindowText(L"Right Mouse (Hotkey F3): \r\n	F3-Running");
				if (flagOnF3)
				{
					GetDlgItem(IDC_RIGHTMOUSETEXT)->EnableWindow(FALSE);
					GetDlgItem(IDC_RIGHTMOUSETEXTMS)->EnableWindow(FALSE);
					GetDlgItem(IDC_RIGHTMOUSETIME)->EnableWindow(FALSE);
					if (d3Wnd != 0)
					{
						rightMouseCooldown += mainTimerDelay;
						if (rightMouseCooldown >= d3Config.leftMouseTime)
						{
							if (ValidToSendD3Click()) SendD3RightMouseClick();
							rightMouseCooldown = 0;
						}
					}
				}
				else
				{
					GetDlgItem(IDC_RIGHTMOUSETEXT)->SetWindowText(L"Right Mouse (Hotkey F3): ");
					GetDlgItem(IDC_RIGHTMOUSETEXT)->EnableWindow(TRUE);
					GetDlgItem(IDC_RIGHTMOUSETEXTMS)->EnableWindow(TRUE);
					GetDlgItem(IDC_RIGHTMOUSETIME)->EnableWindow(TRUE);
				}


			}





			/************************************************************************/
			/* Craft                                                                */
			/************************************************************************/
			if (d3Wnd != 0 && IsD3WindowActive() && (flagOnCtrl5 || flagOnCtrl6 || flagOnCtrl8 || flagOnCtrl9))
			{

				GetDlgItem(IDC_CTRL5TEXT)->EnableWindow(FALSE);
				GetDlgItem(IDC_CTRL6TEXT)->EnableWindow(FALSE);
				GetDlgItem(IDC_CTRL9TEXT)->EnableWindow(FALSE);
				double		d3Width = d3Rect.right - d3Rect.left;
				double		d3Height = d3Rect.bottom - d3Rect.top;

				const int	craftDelayTimeInMs = 30;
				double		d3WidthScale = d3Width / 1920.0;
				double		d3HeightScale = d3Height / 1080.0;
				int			xTransmute = (int)round(230.0 * d3WidthScale);
				int			yTransmute = (int)round(830.0 * d3HeightScale);
				int			xFill = (int)round(720.0 * d3WidthScale);
				int			yFill = (int)round(840.0 * d3HeightScale);
				int			xInventoryArray[60] = { int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale) };
				int			yInventoryArray[60] = { int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale) };
				int			preloadSalvageSlot[60] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
				double		xCubeLeftPage = 583 * d3WidthScale;
				double		yCubeLeftPage = 840 * d3HeightScale;
				double		xCubeRightPage = 852 * d3WidthScale;
				double		yCubeRightPage = 840 * d3HeightScale;
				int			xForgeWeaponTable = 517 * d3WidthScale;
				int			yForgeWeaponTable = 223 * d3HeightScale;
				int			xSalvageTable = 517 * d3WidthScale;
				int			ySalvageTable = 500 * d3HeightScale;
				int			xSalvageButton = (int)round(170.0 * d3WidthScale);
				int			ySalvageButton = (int)round(290.0 * d3HeightScale);
				int			xRepairTable = 517 * d3WidthScale;
				int			yRepairTable = 620 * d3HeightScale;
				int			xRepairButton = 264 * d3WidthScale;
				int			yRepairButton = 594 * d3HeightScale;
				int			xSalvageBlue = 318 * d3WidthScale;
				int			ySalvageBlue = 292 * d3HeightScale;



				if (d3WidthScale == 1280 && d3Height == 1024)
				{
					xTransmute = 222;
					yTransmute = 789;
					xFill = 677;
					yFill = 797;
					xCubeLeftPage = 552;
					yCubeLeftPage = 795;
					xCubeRightPage = 805;
					yCubeRightPage = 795;
					xForgeWeaponTable = 484;
					yForgeWeaponTable = 220;
					xSalvageButton = 127;
					ySalvageButton = 276;
					xSalvageTable = 484;
					ySalvageTable = 450;
					xRepairTable = 484;
					yRepairTable = 580;
					xRepairButton = 250;
					yRepairButton = 560;
				}

				/************************************************************************/
				/* Preload                                                              */
				/************************************************************************/
				if (d3Engine.ValidMode())
				{
					if (flagOnCtrl9)
					{
						SetD3Mouse(1000, 500);
					}
				}
				if (!IsD3WindowActive())
				{
					flagOnF1 = false;
					flagOnF2 = false;
					flagOnF3 = false;
					flagOnCtrl5 = false;
					flagOnCtrl6 = false;
					flagOnCtrl8 = false;
					flagOnCtrl9 = false;
				}
				PreloadSalvageItem(preloadSalvageSlot, 60);


				/************************************************************************/
				/* 1 Slot                                                               */
				/************************************************************************/
				if (flagOnCtrl5)
				{
					for (int iitem = 0; iitem < 60; iitem++)
					{
						if (preloadSalvageSlot[iitem])
						{
							if (d3WidthScale == 1280 && d3Height == 1024 && iitem == 0)
							{
								iitem = 24;
							}
							if (flagOnCtrl5) SetD3Mouse(xInventoryArray[iitem], yInventoryArray[iitem]);
							if (flagOnCtrl5) SendD3RightMouseClick();
							if (flagOnCtrl5) Sleep(50 + (rand() % 5));

							if (flagOnCtrl5) SetD3Mouse(xFill, yFill);
							if (flagOnCtrl5) SendD3LeftMouseClick();
							if (flagOnCtrl5) Sleep(craftDelayTimeInMs + (rand() % 5));

							if (flagOnCtrl5) SetD3Mouse(xTransmute, yTransmute);
							if (flagOnCtrl5) SendD3LeftMouseClick();
							if (flagOnCtrl5) Sleep(craftDelayTimeInMs + (rand() % 5));

							if (flagOnCtrl5) Sleep(250 + (rand() % 10));

							if (flagOnCtrl5) SetD3Mouse(xCubeLeftPage, yCubeLeftPage);
							if (flagOnCtrl5) SendD3LeftMouseClick();
							if (flagOnCtrl5) Sleep(craftDelayTimeInMs + (rand() % 5));

							if (flagOnCtrl5) SetD3Mouse(xCubeRightPage, yCubeRightPage);
							if (flagOnCtrl5) SendD3LeftMouseClick();
							if (flagOnCtrl5) Sleep(craftDelayTimeInMs + (rand() % 5));
						}
					}
					flagOnCtrl5 = false;
				}


				/************************************************************************/
				/* 2 Slot                                                               */
				/************************************************************************/
				else if (flagOnCtrl6)
				{
					for (int iitem = 0; iitem < 60; iitem += 2)
					{
						if (preloadSalvageSlot[iitem] || preloadSalvageSlot[iitem + 1])
						{
							if (d3WidthScale == 1280 && d3Height == 1024 && iitem == 0)
							{
								iitem = 12;
							}

							if (flagOnCtrl6) SetD3Mouse(xInventoryArray[iitem], yInventoryArray[iitem]);
							if (flagOnCtrl6) SendD3RightMouseClick();
							if (flagOnCtrl6) Sleep(craftDelayTimeInMs + (rand() % 5));


							if (flagOnCtrl6) SetD3Mouse(xFill, yFill);
							if (flagOnCtrl6) SendD3LeftMouseClick();
							if (flagOnCtrl6) Sleep(craftDelayTimeInMs + (rand() % 5));

							if (flagOnCtrl6) SetD3Mouse(xTransmute, yTransmute);
							if (flagOnCtrl6) SendD3LeftMouseClick();
							if (flagOnCtrl6) Sleep(craftDelayTimeInMs + (rand() % 5));

							if (flagOnCtrl6) Sleep(250 + (rand() % 10));

							if (flagOnCtrl6) SetD3Mouse(xCubeLeftPage, yCubeLeftPage);
							if (flagOnCtrl6) SendD3LeftMouseClick();
							if (flagOnCtrl6) Sleep(craftDelayTimeInMs + (rand() % 5));

							if (flagOnCtrl6) SetD3Mouse(xCubeRightPage, yCubeRightPage);
							if (flagOnCtrl6) SendD3LeftMouseClick();
							if (flagOnCtrl6) Sleep(craftDelayTimeInMs + (rand() % 5));
						}
					}
					flagOnCtrl6 = false;
				}


				/************************************************************************/
				/*                                                                      */
				/************************************************************************/
				else if (flagOnCtrl9 && d3Engine.D3IsOpenStash())
				{
					for (int iitem = 0; iitem < 60; iitem++)
					{
						if (preloadSalvageSlot[iitem])
						{
							if (flagOnCtrl9) SetD3Mouse(xInventoryArray[iitem], yInventoryArray[iitem]);
							if (flagOnCtrl9) SendD3RightMouseClick();
							if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));
						}
					}
					flagOnCtrl9 = false;
				}
				else if (flagOnCtrl9)
				{
					if (flagOnCtrl9) SetD3Mouse(xForgeWeaponTable, yForgeWeaponTable);
					if (flagOnCtrl9) SendD3LeftMouseClick();
					if (flagOnCtrl9) SetD3Mouse(xSalvageTable, ySalvageTable);
					if (flagOnCtrl9) SendD3LeftMouseClick();

					//	if (flagOnCtrl9) SetD3Mouse(xSalvageBlue, ySalvageBlue);
					//	if (flagOnCtrl9) SendD3LeftMouseClick();
					//	if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 10));
					//	
					//	if (flagOnCtrl9) SendD3Key(VK_RETURN);
					//	if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));
					//	
					//	if (flagOnCtrl9) SendD3Key(VK_RETURN);
					//	if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));
					//	
					//	
					if (flagOnCtrl9) SetD3Mouse(xSalvageButton, ySalvageButton);
					if (flagOnCtrl9) SendD3LeftMouseClick();
					if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));


					for (int iitem = 0; iitem < 60; iitem++)
					{
						if (preloadSalvageSlot[iitem])
						{
							if (flagOnCtrl9) SetD3Mouse(xInventoryArray[iitem], yInventoryArray[iitem]);
							if (flagOnCtrl9) SendD3LeftMouseClick();
							if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));

							if (flagOnCtrl9) SendD3Key(VK_RETURN);
							if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));

							if (flagOnCtrl9) SendD3Key(VK_RETURN);
							if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));
						}
					}

					if (flagOnCtrl9) SetD3Mouse(xRepairTable, yRepairTable);
					if (flagOnCtrl9) SendD3LeftMouseClick();
					if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));
					if (flagOnCtrl9) SetD3Mouse(xRepairButton, yRepairButton);
					if (flagOnCtrl9) SendD3LeftMouseClick();
					if (flagOnCtrl9) Sleep(craftDelayTimeInMs + (rand() % 5));
					flagOnCtrl9 = false;
				}

#ifdef _DEBUG
				else if (flagOnCtrl8)
				{
					for (int iitem = 1; iitem < 60; iitem++)
					{
						if (flagOnCtrl8) HoldShift();
						if (flagOnCtrl8) SetD3Mouse(xInventoryArray[0], yInventoryArray[0]);
						if (flagOnCtrl8) SendD3LeftMouseClick();
						if (flagOnCtrl8) Sleep(craftDelayTimeInMs + (rand() % 5));

						if (flagOnCtrl8) SetD3Mouse(1240, 525);
						if (flagOnCtrl8) SendD3LeftMouseClick();
						if (flagOnCtrl8) Sleep(craftDelayTimeInMs + (rand() % 5));

						if (flagOnCtrl8) SetD3Mouse(xInventoryArray[iitem], yInventoryArray[iitem]);
						if (flagOnCtrl8) SendD3LeftMouseClick();

					}
					if (flagOnCtrl8) ReleaseShift();
					flagOnCtrl8 = false;
				}
#endif





				GetDlgItem(IDC_CTRL5TEXT)->EnableWindow(TRUE);
				GetDlgItem(IDC_CTRL6TEXT)->EnableWindow(TRUE);
				GetDlgItem(IDC_CTRL9TEXT)->EnableWindow(TRUE);


			}
			else
			{
				flagOnCtrl5 = false;
				flagOnCtrl6 = false;
			}






			flagOnMainProcess = false;
		}
	}
	else if (autoCastRollTimerID == nIdEvent)
	{
#ifdef PREMIUM_FEATURE
		if (d3Engine.ValidMode())
		{
			GetDlgItem(IDC_AUTO_CAST_SKILL_FRAME)->EnableWindow(true);
			GetDlgItem(IDC_FORCESTANDTEXT)->EnableWindow(true);
			GetDlgItem(IDC_TOWNPORTALKEY)->EnableWindow(true);
			GetDlgItem(IDC_AUTO_BONE_AMOR)->EnableWindow(true);
			GetDlgItem(IDC_AUTO_SIMULACRUM)->EnableWindow(true);



			if (townPortalDelay > 0) townPortalDelay -= autoCastRollTimerDelay;
			else if (townPortalDelay < 0) townPortalDelay = 0;
			if (townPortalDelay == 0)
			{
				/************************************************************************/
				/* Auto Cast Skill                                                      */
				/************************************************************************/
				if (d3Engine.D3IsOnBattle())
				{
					d3Engine.CaptureDesktop();
					const int config_auto_skip_turn = 30;
					static int scan_witch_doctor_skip_turn = 0;
					static int scan_barbarian_skip_turn = 0;
					static int scan_wizard_skip_turn = 0;
					static int scan_monk_skip_turn = 0;
					static int scan_demon_hunter_skip_turn = 0;
					static int scan_crusader_skip_turn = 0;
					static int scan_necromancer_skip_turn = 0;




					bool flag_need_scan_skill_01 = true;
					bool flag_need_scan_skill_02 = true;
					bool flag_need_scan_skill_03 = true;
					bool flag_need_scan_skill_04 = true;


					if (scan_witch_doctor_skip_turn > 0) scan_witch_doctor_skip_turn--;
					if (scan_barbarian_skip_turn > 0) scan_barbarian_skip_turn--;
					if (scan_wizard_skip_turn > 0) scan_wizard_skip_turn--;
					if (scan_monk_skip_turn > 0) scan_monk_skip_turn--;
					if (scan_demon_hunter_skip_turn > 0) scan_demon_hunter_skip_turn--;
					if (scan_crusader_skip_turn > 0) scan_crusader_skip_turn--;
					if (scan_necromancer_skip_turn > 0) scan_necromancer_skip_turn--;


					if (scan_necromancer_skip_turn == 0)
					{
						if (d3Config.autoBoneArmorEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsBoneArmorReady())
							{
								SendD3Key(d3Config.keySKill01);
								GetDlgItem(IDC_AUTO_BONE_AMOR)->SetWindowTextW(CString(L"Auto BoneArmor - Skill 01 - Key [") + d3Config.keySKill01 + L"]");
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								// scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsBoneArmorReady())
							{
								SendD3Key(d3Config.keySKill02);
								GetDlgItem(IDC_AUTO_BONE_AMOR)->SetWindowTextW(CString(L"Auto BoneArmor - Skill 02 - Key [") + d3Config.keySKill02 + L"]");
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								// scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsBoneArmorReady())
							{
								SendD3Key(d3Config.keySKill03);
								GetDlgItem(IDC_AUTO_BONE_AMOR)->SetWindowTextW(CString(L"Auto BoneArmor - Skill 03 - Key [") + d3Config.keySKill03 + L"]");
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								// scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsBoneArmorReady())
							{
								SendD3Key(d3Config.keySKill04);
								GetDlgItem(IDC_AUTO_BONE_AMOR)->SetWindowTextW(CString(L"Auto BoneArmor - Skill 04 - Key [") + d3Config.keySKill04 + L"]");
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								// scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
							}
						}
						if (d3Config.autoSimulacrumEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsSimulacrumReady())
							{
								SendD3Key(d3Config.keySKill01);
								GetDlgItem(IDC_AUTO_SIMULACRUM)->SetWindowTextW(CString(L"Auto Simulacrum - Skill 01 - Key [") + d3Config.keySKill01 + L"]");
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								// scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsSimulacrumReady())
							{
								SendD3Key(d3Config.keySKill02);
								GetDlgItem(IDC_AUTO_SIMULACRUM)->SetWindowTextW(CString(L"Auto Simulacrum - Skill 02 - Key [") + d3Config.keySKill02 + L"]");
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								// scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsSimulacrumReady())
							{
								SendD3Key(d3Config.keySKill03);
								GetDlgItem(IDC_AUTO_SIMULACRUM)->SetWindowTextW(CString(L"Auto Simulacrum - Skill 03 - Key [") + d3Config.keySKill03 + L"]");
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								// scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsSimulacrumReady())
							{
								SendD3Key(d3Config.keySKill04);
								GetDlgItem(IDC_AUTO_SIMULACRUM)->SetWindowTextW(CString(L"Auto Simulacrum - Skill 04 - Key [") + d3Config.keySKill04 + L"]");
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								// scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
							}
						}

					}
					if (scan_demon_hunter_skip_turn == 0)
					{

					}
					if (d3Config.autoPotion)
					{
						SendD3Key(d3Config.keyHealing);
						GetDlgItem(IDC_AUTO_POTION)->SetWindowTextW(CString(L"Auto Potion - Key [") + d3Config.keyHealing + L"]");
						if (d3Config.healingEnable) OnClickedHealingCheck();
					}
				}



				/************************************************************************/
				/* Auto Reroll support                                                  */
				/************************************************************************/
				if (IsD3WindowActive() && enableRerollSupport
					&& (!(flagOnF1 || flagOnF2 || flagOnF3 || flagOnCtrl5 || flagOnCtrl6 || flagOnCtrl9 || flagOnRollingProcess))
					&& d3Engine.IsRolling())
				{
					d3Engine.CaptureDesktop();

					flagOnRollingProcess = true;
					CString roll_text;


					ROLL_OPTION option_01 = get_roll_option_01();
					ROLL_OPTION option_02 = get_roll_option_02();
					ROLL_OPTION option_03 = get_roll_option_03();

					ROLL_PARAMETER parameter_01 = get_roll_parameter_01(option_01);
					ROLL_PARAMETER parameter_02 = get_roll_parameter_02(option_02);
					ROLL_PARAMETER parameter_03 = get_roll_parameter_03(option_03);



					roll_text += L"Option 01: ";
					roll_text += get_roll_name(option_01);
					roll_text += get_parameter_name(parameter_01);
					roll_text += L"\r\n\r\n";


					roll_text += L"Option 02: ";
					roll_text += get_roll_name(option_02);
					roll_text += get_parameter_name(parameter_02);
					roll_text += L"\r\n\r\n";

					roll_text += L"Option 03: ";
					roll_text += get_roll_name(option_03);
					roll_text += get_parameter_name(parameter_03);
					roll_text += L"\r\n\r\n";

					if (option_01 + option_02 + option_03 + parameter_01 + parameter_02 + parameter_03 > 0 && d3Engine.HaveNoOption04and05())
					{
						ROLL_ITEM item = get_roll_item();
						roll_text += L"Item: ";
						roll_text += get_item_name(item);
						roll_text += L"\r\n\r\n";

						RESOURCE_STATUS resource_status = get_resource_status();
						roll_text += L"Resource: ";
						roll_text += get_resource_info(resource_status);
						roll_text += L"\r\n\r\n";

						GOLD_STATUS gold_status = get_gold_status();
						roll_text += L"Gold: ";
						roll_text += get_gold_info(gold_status);
						roll_text += L"\r\n\r\n";

						CButton* m_ctlCheck = (CButton*)GetDlgItem(IDC_FORCE_TO_DPS);
						int ChkBox = m_ctlCheck->GetCheck();
						GetDlgItem(IDC_REROL_SUPPORT_DETAIL)->SetWindowTextW(roll_text);
						do_roll(item, option_01, parameter_01, option_02, parameter_02, option_03, parameter_03, resource_status, gold_status, (ChkBox == BST_CHECKED));
					}
					flagOnRollingProcess = false;
				}

			}
		}
		else
		{
			GetDlgItem(IDC_AUTO_CAST_SKILL_FRAME)->EnableWindow(false);
			GetDlgItem(IDC_FORCESTANDTEXT)->EnableWindow(false);
			GetDlgItem(IDC_TOWNPORTALKEY)->EnableWindow(false);
			GetDlgItem(IDC_AUTO_BONE_AMOR)->EnableWindow(false);
			GetDlgItem(IDC_AUTO_SIMULACRUM)->EnableWindow(false);
		}
#else
		GetDlgItem(IDC_AUTO_REROLL_SUPPORT_FRAME)->EnableWindow(false);
		GetDlgItem(IDC_ENABLE_REROLL_SUPPORT)->EnableWindow(false);
#endif // !PREMIUM_FEATURE
	}
}
void CDiabloIIISupportDlg::OnLoadConfig()
{
	CFile loadFile;
	if (loadFile.Open(configSavePath, CFile::modeRead | CFile::typeBinary))
	{
		int fileSize = int(loadFile.GetLength());
		if (fileSize > sizeof(d3Config))
		{
			fileSize = sizeof(d3Config);
		}
		loadFile.Read(&d3Config, fileSize);
		loadFile.Close();
		if (d3Config.saveDiabloIIISupportVersion != DiabloIIISupportVersion)
		{
			memset(&d3Config, 0, sizeof(d3Config));
			d3Config.saveDiabloIIISupportVersion = DiabloIIISupportVersion;
			ValidateD3Config();
			OnSaveConfig();
		}
	}
}
void CDiabloIIISupportDlg::OnSaveConfig()
{
	CFile saveFile;
	if (saveFile.Open(configSavePath, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary))
	{
		saveFile.Write(&d3Config, sizeof(d3Config));
		saveFile.Close();
	}
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
void CDiabloIIISupportDlg::OnKillFocusLeftMouseTime()
{
	wchar_t bufferText[1000] = { 0 };
	GetDlgItem(IDC_LEFTMOUSETIME)->GetWindowTextW(bufferText, 999);
	int newValue = 0;
	swscanf_s(bufferText, L"%d", &newValue);
	newValue = int(round(newValue / (double)(mainTimerDelay)) * mainTimerDelay);
	if (newValue < mainTimerDelay) newValue = mainTimerDelay;
	swprintf_s(bufferText, L"%d", newValue);
	GetDlgItem(IDC_LEFTMOUSETIME)->SetWindowTextW(bufferText);
	if (newValue != d3Config.leftMouseTime)
	{
		d3Config.leftMouseTime = newValue;
		d3Config.profileLeftMouseTime[d3Config.currentProfile] = newValue;
		OnSaveConfig();
	}
}
void CDiabloIIISupportDlg::OnKillFocusRightMouseTime()
{
	wchar_t bufferText[1000] = { 0 };
	GetDlgItem(IDC_RIGHTMOUSETIME)->GetWindowTextW(bufferText, 999);
	int newValue = 0;
	swscanf_s(bufferText, L"%d", &newValue);
	newValue = int(round(newValue / (double)(mainTimerDelay)) * mainTimerDelay);
	if (newValue < mainTimerDelay) newValue = mainTimerDelay;
	swprintf(bufferText, L"%d", newValue);
	GetDlgItem(IDC_RIGHTMOUSETIME)->SetWindowTextW(bufferText);
	if (newValue != d3Config.rightMouseTime)
	{
		d3Config.rightMouseTime = newValue;
		d3Config.profileRightMouseTime[d3Config.currentProfile] = newValue;
		OnSaveConfig();
	}
}
void CDiabloIIISupportDlg::OnKillFocusSkill01Time()
{
	wchar_t bufferText[1000] = { 0 };
	GetDlgItem(IDC_SKILL01TIME)->GetWindowTextW(bufferText, 999);
	int newValue = 0;
	swscanf_s(bufferText, L"%d", &newValue);
	newValue = int(round(newValue / (double)(mainTimerDelay)) * mainTimerDelay);
	if (newValue < mainTimerDelay) newValue = mainTimerDelay;
	swprintf(bufferText, L"%d", newValue);
	GetDlgItem(IDC_SKILL01TIME)->SetWindowTextW(bufferText);
	if (newValue != d3Config.skillSlot01Time)
	{
		d3Config.skillSlot01Time = newValue;
		d3Config.profileSkillSlot01Time[d3Config.currentProfile] = newValue;
		OnSaveConfig();
	}
}
void CDiabloIIISupportDlg::OnKillFocusSkill02Time()
{
	wchar_t bufferText[1000] = { 0 };
	GetDlgItem(IDC_SKILL02TIME)->GetWindowTextW(bufferText, 999);
	int newValue = 0;
	swscanf_s(bufferText, L"%d", &newValue);
	newValue = int(round(newValue / (double)(mainTimerDelay)) * mainTimerDelay);
	if (newValue < mainTimerDelay) newValue = mainTimerDelay;
	swprintf(bufferText, L"%d", newValue);
	GetDlgItem(IDC_SKILL02TIME)->SetWindowTextW(bufferText);
	if (newValue != d3Config.skillSlot02Time)
	{
		d3Config.skillSlot02Time = newValue;
		d3Config.profileSkillSlot02Time[d3Config.currentProfile] = newValue;
		OnSaveConfig();
	}
}
void CDiabloIIISupportDlg::OnKillFocusSkill03Time()
{
	wchar_t bufferText[1000] = { 0 };
	GetDlgItem(IDC_SKILL03TIME)->GetWindowTextW(bufferText, 999);
	int newValue = 0;
	swscanf_s(bufferText, L"%d", &newValue);
	newValue = int(round(newValue / (double)(mainTimerDelay)) * mainTimerDelay);
	if (newValue < mainTimerDelay) newValue = mainTimerDelay;
	swprintf(bufferText, L"%d", newValue);
	GetDlgItem(IDC_SKILL03TIME)->SetWindowTextW(bufferText);
	if (newValue != d3Config.skillSlot03Time)
	{
		d3Config.skillSlot03Time = newValue;
		d3Config.profileSkillSlot03Time[d3Config.currentProfile] = newValue;
		OnSaveConfig();
	}
}
void CDiabloIIISupportDlg::OnKillFocusSkill04Time()
{
	wchar_t bufferText[1000] = { 0 };
	GetDlgItem(IDC_SKILL04TIME)->GetWindowTextW(bufferText, 999);
	int newValue = 0;
	swscanf_s(bufferText, L"%d", &newValue);
	newValue = int(round(newValue / (double)(mainTimerDelay)) * mainTimerDelay);
	if (newValue < mainTimerDelay) newValue = mainTimerDelay;
	swprintf(bufferText, L"%d", newValue);
	GetDlgItem(IDC_SKILL04TIME)->SetWindowTextW(bufferText);
	if (newValue != d3Config.skillSlot04Time)
	{
		d3Config.skillSlot04Time = newValue;
		d3Config.profileSkillSlot04Time[d3Config.currentProfile] = newValue;
		OnSaveConfig();
	}
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
void CDiabloIIISupportDlg::OnShowSkillKey(int idW, wchar_t key)
{
	wchar_t buffer[100] = { 0 };
	if (key == L' ') wcscpy(buffer, L"Space");
	else if (key == VK_SHIFT) wcscpy(buffer, L"Shift");
	else if (key == VK_LBUTTON) wcscpy(buffer, L"LeftMouse");
	else if (key == VK_RBUTTON) wcscpy(buffer, L"RightMouse");
	else swprintf_s(buffer, L"%lc", key);
	GetDlgItem(idW)->SetWindowText(buffer);
}
void CDiabloIIISupportDlg::OnKillFocusSkillKey(int changeID, wchar_t& keySkill)
{
	wchar_t bufferText[1001] = { 0 };
	GetDlgItem(changeID)->GetWindowTextW(bufferText, 999);

	CString tempTrunc = bufferText;
	tempTrunc.Replace(L" ", L"");
	tempTrunc.MakeUpper();
	wcscpy(bufferText, tempTrunc.GetBuffer());



	int newValue = bufferText[0];
	if (newValue == '`') newValue = '~';
	if (wcscmp(bufferText, L"SPACE") == 0 || newValue == ' ')
	{
		wcscpy(bufferText, L"Space");
		newValue = L' ';
	}
	else if (wcscmp(bufferText, L"SHIFT") == 0)
	{
		wcscpy(bufferText, L"Shift");
		newValue = VK_SHIFT;
	}
	else if (wcscmp(bufferText, L"CTRL") == 0)
	{
		wcscpy(bufferText, L"Ctrl");
		newValue = VK_CONTROL;
	}
	else if (wcscmp(bufferText, L"LEFTMOUSE") == 0 || wcscmp(bufferText, L"LM") == 0)
	{
		wcscpy(bufferText, L"LeftMouse");
		newValue = VK_LBUTTON;
	}
	else if (wcscmp(bufferText, L"RIGHTMOUSE") == 0 || wcscmp(bufferText, L"RM") == 0)
	{
		wcscpy(bufferText, L"RightMouse");
		newValue = VK_RBUTTON;
	}
	else bufferText[1] = 0;




	if (newValue >= 'a' && newValue <= 'z') newValue = 'A' + newValue - 'a';
	if ((newValue >= 'A' && newValue <= 'Z')
		|| (newValue >= '0' && newValue <= '9')
		|| newValue == ' '
		|| newValue == '~'
		|| newValue == VK_SHIFT
		|| newValue == VK_CONTROL
		|| newValue == VK_RBUTTON
		|| newValue == VK_LBUTTON
		)
	{
		if (newValue != keySkill)
		{
			keySkill = newValue;
			OnSaveConfig();
		}
	}
	else
	{
		static int flagAlreadyWarning = 0;
		if (flagAlreadyWarning == 0)
		{
			MessageBoxW(L"English : Only allow :\r\nABCDEFGHIJKLMNOPQRSTUVWXYZ\r\n0123456789\r\n~\r\nSpace\r\nShift\r\nCtrl\r\n\r\n Vietnamese : Chỉ hỗ trợ các kí tự A-Z 0-9 Shift, Space, Ctrl, LeftMouse, RightMouse\r\n Đối với các kí tự điều khiển thì cần bạn gõ đúng chuỗi kí tự vào");
			flagAlreadyWarning = 1;
		}
	}
	OnShowSkillKey(changeID, keySkill);
}
void CDiabloIIISupportDlg::OnKillFocusSkillKey01()
{
	OnKillFocusSkillKey(IDC_SKILLKEY01, d3Config.keySKill01);
}
void CDiabloIIISupportDlg::OnKillFocusSkillKey02()
{
	OnKillFocusSkillKey(IDC_SKILLKEY02, d3Config.keySKill02);
}
void CDiabloIIISupportDlg::OnKillFocusSkillKey03()
{
	OnKillFocusSkillKey(IDC_SKILLKEY03, d3Config.keySKill03);
}
void CDiabloIIISupportDlg::OnKillFocusSkillKey04()
{
	OnKillFocusSkillKey(IDC_SKILLKEY04, d3Config.keySKill04);
}
void CDiabloIIISupportDlg::OnKillFocusHealingKey()
{
	OnKillFocusSkillKey(IDC_HEALINGKEY, d3Config.keyHealing);
}
void CDiabloIIISupportDlg::OnKillFocusTownPortalKey()
{
	OnKillFocusSkillKey(IDC_TOWNPORTALKEY, d3Config.keyTownPortal);
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
void CDiabloIIISupportDlg::OnClickedSkill01Check()
{
	d3Config.skill01Enable = !d3Config.skill01Enable;
	d3Config.profileSkill01Enable[d3Config.currentProfile] = d3Config.skill01Enable;
	((CButton*)GetDlgItem(IDC_SKILL01CHECK))->SetCheck(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL01TIME)->EnableWindow(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL01TEXT)->EnableWindow(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL01TEXTMS)->EnableWindow(d3Config.skill01Enable);
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedSkill02Check()
{
	d3Config.skill02Enable = !d3Config.skill02Enable;
	d3Config.profileSkill02Enable[d3Config.currentProfile] = d3Config.skill02Enable;
	((CButton*)GetDlgItem(IDC_SKILL02CHECK))->SetCheck(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL02TIME)->EnableWindow(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL02TEXT)->EnableWindow(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL02TEXTMS)->EnableWindow(d3Config.skill02Enable);
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedSkill03Check()
{
	d3Config.skill03Enable = !d3Config.skill03Enable;
	d3Config.profileSkill03Enable[d3Config.currentProfile] = d3Config.skill03Enable;
	((CButton*)GetDlgItem(IDC_SKILL03CHECK))->SetCheck(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL03TIME)->EnableWindow(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL03TEXT)->EnableWindow(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL03TEXTMS)->EnableWindow(d3Config.skill03Enable);
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedSkill04Check()
{
	d3Config.skill04Enable = !d3Config.skill04Enable;
	d3Config.profileSkill04Enable[d3Config.currentProfile] = d3Config.skill04Enable;
	((CButton*)GetDlgItem(IDC_SKILL04CHECK))->SetCheck(d3Config.skill04Enable);
	GetDlgItem(IDC_SKILL04TIME)->EnableWindow(d3Config.skill04Enable);
	GetDlgItem(IDC_SKILL04TEXT)->EnableWindow(d3Config.skill04Enable);
	GetDlgItem(IDC_SKILL04TEXTMS)->EnableWindow(d3Config.skill04Enable);
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedHealingCheck()
{
	d3Config.healingEnable = !d3Config.healingEnable;
	d3Config.profileHealingEnable[d3Config.currentProfile] = d3Config.healingEnable;
	((CButton*)GetDlgItem(IDC_HEALINGCHECK))->SetCheck(d3Config.healingEnable);
	GetDlgItem(IDC_HEALINGTEXTMS)->EnableWindow(d3Config.healingEnable);
	OnSaveConfig();
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
void CDiabloIIISupportDlg::OnClickedAutoBoneAmor()
{
	d3Config.autoBoneArmorEnable = !d3Config.autoBoneArmorEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoSimulacrum()
{
	d3Config.autoSimulacrumEnable = !d3Config.autoSimulacrumEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoPotion()
{
	d3Config.autoPotion = !d3Config.autoPotion;
	OnSaveConfig();
}

/************************************************************************/
/*                                                                      */
/************************************************************************/
void CDiabloIIISupportDlg::OnKillFocusProfileName()
{
	wchar_t bufferProfileName[1000];
	GetDlgItem(IDC_PROFILENAME)->GetWindowTextW(bufferProfileName, 999);
	bufferProfileName[maxProfileNameLength] = 0;
	GetDlgItem(IDC_PROFILENAME)->SetWindowTextW(bufferProfileName);
	wcscpy(d3Config.profileName[d3Config.currentProfile], bufferProfileName);

	CString currentProfileName = d3Config.profileName[d3Config.currentProfile];
	currentProfileName += L"*";
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(currentProfileName);
}
void CDiabloIIISupportDlg::OnBnClickedProfile()
{
	d3Config.leftMouseTime = d3Config.profileLeftMouseTime[d3Config.currentProfile];
	d3Config.rightMouseTime = d3Config.profileRightMouseTime[d3Config.currentProfile];
	d3Config.skillSlot01Time = d3Config.profileSkillSlot01Time[d3Config.currentProfile];
	d3Config.skillSlot02Time = d3Config.profileSkillSlot02Time[d3Config.currentProfile];
	d3Config.skillSlot03Time = d3Config.profileSkillSlot03Time[d3Config.currentProfile];
	d3Config.skillSlot04Time = d3Config.profileSkillSlot04Time[d3Config.currentProfile];
	d3Config.healingTime = d3Config.profileHealingTime[d3Config.currentProfile];
	d3Config.skill01Enable = d3Config.profileSkill01Enable[d3Config.currentProfile];
	d3Config.skill02Enable = d3Config.profileSkill02Enable[d3Config.currentProfile];
	d3Config.skill03Enable = d3Config.profileSkill03Enable[d3Config.currentProfile];
	d3Config.skill04Enable = d3Config.profileSkill04Enable[d3Config.currentProfile];
	d3Config.healingEnable = d3Config.profileHealingEnable[d3Config.currentProfile];





	/************************************************************************/
	/* Force                                                                */
	/************************************************************************/
	d3Config.healingTime = 50;







	wchar_t buffer[1000] = { 0 };

	swprintf_s(buffer, L"%d", d3Config.leftMouseTime);
	GetDlgItem(IDC_LEFTMOUSETIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.rightMouseTime);
	GetDlgItem(IDC_RIGHTMOUSETIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot01Time);
	GetDlgItem(IDC_SKILL01TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot02Time);
	GetDlgItem(IDC_SKILL02TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot03Time);
	GetDlgItem(IDC_SKILL03TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot04Time);
	GetDlgItem(IDC_SKILL04TIME)->SetWindowText(buffer);


	GetDlgItem(IDC_SKILL01TIME)->EnableWindow(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL02TIME)->EnableWindow(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL03TIME)->EnableWindow(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL04TIME)->EnableWindow(d3Config.skill04Enable);
	GetDlgItem(IDC_SKILL01TEXT)->EnableWindow(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL02TEXT)->EnableWindow(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL03TEXT)->EnableWindow(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL04TEXT)->EnableWindow(d3Config.skill04Enable);
	GetDlgItem(IDC_SKILL01TEXTMS)->EnableWindow(d3Config.skill01Enable);
	GetDlgItem(IDC_SKILL02TEXTMS)->EnableWindow(d3Config.skill02Enable);
	GetDlgItem(IDC_SKILL03TEXTMS)->EnableWindow(d3Config.skill03Enable);
	GetDlgItem(IDC_SKILL04TEXTMS)->EnableWindow(d3Config.skill04Enable);
	GetDlgItem(IDC_HEALINGTEXTMS)->EnableWindow(d3Config.healingEnable);


	((CButton*)GetDlgItem(IDC_SKILL01CHECK))->SetCheck(d3Config.skill01Enable);
	((CButton*)GetDlgItem(IDC_SKILL02CHECK))->SetCheck(d3Config.skill02Enable);
	((CButton*)GetDlgItem(IDC_SKILL03CHECK))->SetCheck(d3Config.skill03Enable);
	((CButton*)GetDlgItem(IDC_SKILL04CHECK))->SetCheck(d3Config.skill04Enable);
	((CButton*)GetDlgItem(IDC_HEALINGCHECK))->SetCheck(d3Config.healingEnable);





	CString currentProfileName = L"> ";
	currentProfileName += d3Config.profileName[d3Config.currentProfile];
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(currentProfileName);
	GetDlgItem(IDC_PROFILENAME)->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnBnClickedProfile01()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 0;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile02()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 1;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile03()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 2;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile04()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 3;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile05()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 4;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile06()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 5;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile07()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 6;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile08()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 7;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile09()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 8;
	OnBnClickedProfile();
}
void CDiabloIIISupportDlg::OnBnClickedProfile10()
{
	GetDlgItem(profileID[d3Config.currentProfile])->SetWindowTextW(d3Config.profileName[d3Config.currentProfile]);
	d3Config.currentProfile = 9;
	OnBnClickedProfile();
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
void CDiabloIIISupportDlg::OnClickedRerollSupportCheck()
{
	enableRerollSupport = !enableRerollSupport;
	GetDlgItem(IDC_REROL_SUPPORT_DETAIL)->EnableWindow(enableRerollSupport);
	GetDlgItem(IDC_FORCE_TO_DPS)->EnableWindow(enableRerollSupport);
	OnSaveConfig();
}



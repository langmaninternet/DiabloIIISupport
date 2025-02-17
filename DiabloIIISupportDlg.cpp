﻿#include "stdafx.h"
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
const int	maxProfileNumber = 4;
const int	maxProfileNameLength = 15;
const int	profileID[maxProfileNumber] =
{
IDC_PROFILE01,
IDC_PROFILE02,
IDC_PROFILE03,
IDC_PROFILE04,
};
struct DiabloIIISupportConfig
{
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
	int		autoCommandSkeletonsEnable;
	int		autoArmyOfTheDeadEnable;

	int		autoFanOfKnivesEnable;
	int		autoCompanionEnable;
	int		autoShadowPowerEnable;
	int		autoSmokeScreenEnable;
	int		autoVengeanceEnable;

	int		autoSerenityEnable;
	int		autoMantraOfRetributionEnable;

	int		autoGargantuanEnable;
	int		autoSpiritWalkEnable;
	int		autoSummonZombieDogEnable;

	int		autoPotionEnable;



	double	saveDiabloIIISupportVersion;
};

CHARACTER_TYPE current_character_type = CHARACTER_TYPE_UNKNOWN;

wchar_t dumpvalue[100] = { 0 };




/************************************************************************/
/* Variable                                                             */
/************************************************************************/
DiabloIIISupportConfig	d3Config;
wchar_t					configSavePath[3000] = { 0 };
const int				mainTimerDelay = 30/*ms*/;
const int				autoTimerDelay = 100/*ms*/;
int						townPortalDelay = 0/*ms*/;
bool					flagOnF2 = false;
bool					flagOnCtrl5 = false;
bool					flagOnCtrl6 = false;
bool					flagOnCtrl7 = false;
bool					flagOnCtrl8 = false;
bool					flagOnCtrl9 = false;
bool					flagOnMainProcess = false;
bool					flagOnAutoProcess = false;
int						leftMouseCooldown;
int						rightMouseCooldown;
int						skillSlot01Cooldown;
int						skillSlot02Cooldown;
int						skillSlot03Cooldown;
int						skillSlot04Cooldown;
int						enableRerollSupport = 0;
time_t					last_main_timer;
extern D3Engine			d3Engine;



/************************************************************************/
/* Process Function                                                     */
/************************************************************************/
void			ValidateD3Key(wchar_t& keyValue, const wchar_t defaultValue)
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
void			ValidateD3Config(void)
{
	d3Config.skillSlot01Time = int(round(d3Config.skillSlot01Time / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.skillSlot02Time = int(round(d3Config.skillSlot02Time / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.skillSlot03Time = int(round(d3Config.skillSlot03Time / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.skillSlot04Time = int(round(d3Config.skillSlot04Time / double(mainTimerDelay)) * mainTimerDelay);
	d3Config.healingTime = int(round(d3Config.healingTime / double(mainTimerDelay)) * mainTimerDelay);
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
		d3Config.profileSkillSlot01Time[iprofile] = int(round(d3Config.profileSkillSlot01Time[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileSkillSlot02Time[iprofile] = int(round(d3Config.profileSkillSlot02Time[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileSkillSlot03Time[iprofile] = int(round(d3Config.profileSkillSlot03Time[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileSkillSlot04Time[iprofile] = int(round(d3Config.profileSkillSlot04Time[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
		d3Config.profileHealingTime[iprofile] = int(round(d3Config.profileHealingTime[iprofile] / double(mainTimerDelay)) * mainTimerDelay);
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
HWND			GetD3Windows(void)
{
	HWND d3Wnd = FindWindowW(L"D3 Main Window Class", L"Diablo III");
	if (d3Wnd == NULL) d3Wnd = FindWindowW(L"D3 Main Window Class", NULL);
	if (d3Wnd == NULL) d3Wnd = FindWindowW(NULL, L"Diablo III");
	return d3Wnd;
}
bool			IsD3WindowActive(void)
{
	HWND		currentHWD = GetForegroundWindow();
	if (currentHWD == GetD3Windows()) return true;
	return false;
}
void			SendD3LeftMouseClick()
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
void			SendD3RightMouseClick()
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
static void		SendD3Key(int keyCode)
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
void			SetD3Mouse(int x, int y)
{
	HWND d3Wnd = GetD3Windows();
	if (d3Wnd)
	{
		RECT d3Rect = { 0 };
		GetWindowRect(d3Wnd, &d3Rect);
		SetCursorPos(d3Rect.left + x, d3Rect.top + y);
	}
}
static bool		PointInRect(POINT point, int rLeft, int rRight, int rTop, int rBottom)
{
	if (rLeft >= rRight || rTop >= rBottom)
	{
		MessageBox(0, L"D3 Engine Error!!", L"(rLeft <= rRight || rTop <= rBottom)", MB_OK);
	}
	return (point.x > rLeft && point.x < rRight && point.y > rTop && point.y < rBottom);
}
static bool		ValidToSendD3Click(void)
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


#ifdef _DEBUG
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
#endif

/************************************************************************/
/* Hook                                                                 */
/************************************************************************/
HHOOK					hGlobalKeyboardHook;
extern "C" __declspec(dllexport) LRESULT CALLBACK KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam)
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
			case VK_ESCAPE:
			case VK_SPACE:
				enableRerollSupport = false;
				flagOnCtrl = false;
				flagOnCtrl5 = false;
				flagOnCtrl6 = false;
				flagOnCtrl7 = false;
				flagOnCtrl8 = false;
				flagOnCtrl9 = false;
				break;

#ifdef _DEBUG
			case VK_F5:
				QuangBTDumpScreen();
				break;
			case VK_F6:
				d3Engine.Dump2DigitByCriticalHitDamageLine01(dumpvalue);
				break;
			case VK_F7:
				d3Engine.Dump2DigitByCriticalHitDamageLine02(dumpvalue);
				break;
			case VK_F8:
				d3Engine.Dump2DigitByCriticalHitDamageLine03(dumpvalue);
				break;
#endif


			case 0x35/*'5'*/:
				if (flagOnCtrl)
				{
					flagOnF2 = false;
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
					flagOnF2 = false;
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
					flagOnF2 = false;
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
					flagOnF2 = false;
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
					flagOnF2 = false;
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
			}
		}

		if (keyParam->vkCode == d3Config.keyTownPortal)
		{
			townPortalDelay = 11000/*ms*/;
		}
	}
	if (flagNeedMoreHook == false) return 1;
	return CallNextHookEx(hGlobalKeyboardHook, nCode, wParam, lParam);
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
	ON_EN_KILLFOCUS(IDC_SKILLKEY01, &CDiabloIIISupportDlg::OnKillFocusSkillKey01)
	ON_EN_KILLFOCUS(IDC_SKILLKEY02, &CDiabloIIISupportDlg::OnKillFocusSkillKey02)
	ON_EN_KILLFOCUS(IDC_SKILLKEY03, &CDiabloIIISupportDlg::OnKillFocusSkillKey03)
	ON_EN_KILLFOCUS(IDC_SKILLKEY04, &CDiabloIIISupportDlg::OnKillFocusSkillKey04)
	ON_EN_KILLFOCUS(IDC_HEALINGKEY, &CDiabloIIISupportDlg::OnKillFocusHealingKey)
	ON_EN_KILLFOCUS(IDC_TOWNPORTALKEY, &CDiabloIIISupportDlg::OnKillFocusTownPortalKey)
	ON_BN_CLICKED(IDC_ENABLE_REROLL_SUPPORT, &CDiabloIIISupportDlg::OnClickedRerollSupportCheck)

	ON_BN_CLICKED(IDC_AUTO_BONE_AMOR, &CDiabloIIISupportDlg::OnClickedAutoBoneAmor)
	ON_BN_CLICKED(IDC_AUTO_SIMULACRUM, &CDiabloIIISupportDlg::OnClickedAutoSimulacrum)


	ON_BN_CLICKED(IDC_AUTO_FANOFKNIVES, &CDiabloIIISupportDlg::OnClickedAutoFanofknives)
	ON_BN_CLICKED(IDC_AUTO_COMPANION, &CDiabloIIISupportDlg::OnClickedAutoCompanion)
	ON_BN_CLICKED(IDC_AUTO_SHADOWPOWER, &CDiabloIIISupportDlg::OnClickedAutoShadowpower)
	ON_BN_CLICKED(IDC_AUTO_SMOKESCREEN, &CDiabloIIISupportDlg::OnClickedAutoSmokescreen)
	ON_BN_CLICKED(IDC_AUTO_VENGEANCE, &CDiabloIIISupportDlg::OnClickedAutoVengeance)

	ON_BN_CLICKED(IDC_AUTO_SERENITY, &CDiabloIIISupportDlg::OnClickedAutoSerenity)
	ON_BN_CLICKED(IDC_AUTO_MANTRAOFRETRIBUTION, &CDiabloIIISupportDlg::OnBnClickedAutoMantraOfRetribution)

	//ON_BN_CLICKED(IDC_AUTO_GARGANTUAN, &CDiabloIIISupportDlg::OnClickedAutoGargantuan)
	//ON_BN_CLICKED(IDC_AUTO_SPIRITWALK, &CDiabloIIISupportDlg::OnClickedAutoSpiritwalk)
	//ON_BN_CLICKED(IDC_AUTO_SUMMONZOMBIEDOG, &CDiabloIIISupportDlg::OnClickedAutoSummonzombiedog)

	ON_BN_CLICKED(IDC_AUTO_POTION, &CDiabloIIISupportDlg::OnClickedAutoPotion)

	ON_EN_CHANGE(IDC_LICENSE, &CDiabloIIISupportDlg::OnChangeLicense)

	ON_BN_CLICKED(IDC_DUMP_01_CDC_2d, &CDiabloIIISupportDlg::OnClickedDump01Cdc2d)
	ON_BN_CLICKED(IDC_DUMP_02_CDC_2d, &CDiabloIIISupportDlg::OnClickedDump02Cdc2d)
	ON_BN_CLICKED(IDC_DUMP_03_CDC_2d, &CDiabloIIISupportDlg::OnClickedDump03Cdc2d)
	ON_EN_CHANGE(IDC_DUMP_PERCENT_VALUE, &CDiabloIIISupportDlg::OnChangeDumpPercentValue)
	ON_BN_CLICKED(IDC_AUTO_COMMAND_SKELETONS, &CDiabloIIISupportDlg::OnClickedAutoCommandSkeletons)
	ON_BN_CLICKED(IDC_AUTO_ARMY_OF_THE_DEAD, &CDiabloIIISupportDlg::OnClickedAutoArmyOfTheDead)



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
	autoTimerID = CDialogEx::SetTimer(2, autoTimerDelay, NULL);



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

	swprintf_s(buffer, L"%d", d3Config.skillSlot01Time);
	GetDlgItem(IDC_SKILL01TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot02Time);
	GetDlgItem(IDC_SKILL02TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot03Time);
	GetDlgItem(IDC_SKILL03TIME)->SetWindowText(buffer);

	swprintf_s(buffer, L"%d", d3Config.skillSlot04Time);
	GetDlgItem(IDC_SKILL04TIME)->SetWindowText(buffer);


	const wchar_t* GetDeviceIdentification(void);
	GetDlgItem(IDC_DEVICE_ID)->SetWindowTextW(GetDeviceIdentification());


	bool			IsValidLicense(void);
	if (IsValidLicense())
	{
		GetDlgItem(IDC_LICENSE)->EnableWindow(FALSE);
		//GetDlgItem(IDC_LICENSE)->ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_LICENSE_TITLE)->ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_DEVICE_ID)->ShowWindow(SW_HIDE);
		//GetDlgItem(IDC_DEVICE_ID_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_ABOUT)->ShowWindow(SW_HIDE);
		swprintf_s(buffer, L"Diablo III Support Version %0.2lf Premium", DiabloIIISupportVersion);
		GetDlgItem(IDC_DEVICE_ID)->SetWindowTextW(L"Premium");

		GetDlgItem(IDC_AUTO_BONE_AMOR)->EnableWindow(TRUE);
		GetDlgItem(IDC_AUTO_SIMULACRUM)->EnableWindow(TRUE);
		GetDlgItem(IDC_AUTO_COMMAND_SKELETONS)->EnableWindow(TRUE);

		GetDlgItem(IDC_AUTO_FANOFKNIVES)->EnableWindow(TRUE);
		GetDlgItem(IDC_AUTO_COMPANION)->EnableWindow(TRUE);
		GetDlgItem(IDC_AUTO_SHADOWPOWER)->EnableWindow(TRUE);
		GetDlgItem(IDC_AUTO_SMOKESCREEN)->EnableWindow(TRUE);
		GetDlgItem(IDC_AUTO_VENGEANCE)->EnableWindow(TRUE);

		GetDlgItem(IDC_AUTO_SERENITY)->EnableWindow(TRUE);
		GetDlgItem(IDC_AUTO_MANTRAOFRETRIBUTION)->EnableWindow(TRUE);

		//GetDlgItem(IDC_AUTO_GARGANTUAN)->EnableWindow(TRUE);
		//GetDlgItem(IDC_AUTO_SPIRITWALK)->EnableWindow(TRUE);
		//GetDlgItem(IDC_AUTO_SUMMONZOMBIEDOG)->EnableWindow(TRUE);


		GetDlgItem(IDC_AUTO_POTION)->EnableWindow(TRUE);





		//	CRect rectFrame;
		//	GetWindowRect(&rectFrame);
		//	rectFrame.right = rectFrame.left + 605;
		//	MoveWindow(rectFrame);
	}
	else
	{
		swprintf_s(buffer, L"Diablo III Support Version %0.2lf", DiabloIIISupportVersion);

		GetDlgItem(IDC_AUTO_BONE_AMOR)->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTO_SIMULACRUM)->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTO_COMMAND_SKELETONS)->EnableWindow(FALSE);

		GetDlgItem(IDC_AUTO_FANOFKNIVES)->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTO_COMPANION)->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTO_SHADOWPOWER)->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTO_SMOKESCREEN)->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTO_VENGEANCE)->EnableWindow(FALSE);

		GetDlgItem(IDC_AUTO_SERENITY)->EnableWindow(FALSE);
		GetDlgItem(IDC_AUTO_MANTRAOFRETRIBUTION)->EnableWindow(FALSE);

		//GetDlgItem(IDC_AUTO_GARGANTUAN)->EnableWindow(FALSE);
		//GetDlgItem(IDC_AUTO_SPIRITWALK)->EnableWindow(FALSE);
		//GetDlgItem(IDC_AUTO_SUMMONZOMBIEDOG)->EnableWindow(FALSE);

		GetDlgItem(IDC_AUTO_POTION)->EnableWindow(FALSE);


	}
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
	((CButton*)GetDlgItem(IDC_AUTO_COMMAND_SKELETONS))->SetCheck(d3Config.autoCommandSkeletonsEnable);
	((CButton*)GetDlgItem(IDC_AUTO_ARMY_OF_THE_DEAD))->SetCheck(d3Config.autoArmyOfTheDeadEnable);

	((CButton*)GetDlgItem(IDC_AUTO_FANOFKNIVES))->SetCheck(d3Config.autoFanOfKnivesEnable);
	((CButton*)GetDlgItem(IDC_AUTO_COMPANION))->SetCheck(d3Config.autoCompanionEnable);
	((CButton*)GetDlgItem(IDC_AUTO_SHADOWPOWER))->SetCheck(d3Config.autoShadowPowerEnable);
	((CButton*)GetDlgItem(IDC_AUTO_SMOKESCREEN))->SetCheck(d3Config.autoSmokeScreenEnable);
	((CButton*)GetDlgItem(IDC_AUTO_VENGEANCE))->SetCheck(d3Config.autoVengeanceEnable);

	((CButton*)GetDlgItem(IDC_AUTO_SERENITY))->SetCheck(d3Config.autoSerenityEnable);
	((CButton*)GetDlgItem(IDC_AUTO_MANTRAOFRETRIBUTION))->SetCheck(d3Config.autoMantraOfRetributionEnable);

	//((CButton*)GetDlgItem(IDC_AUTO_GARGANTUAN))->SetCheck(d3Config.autoGargantuanEnable);
	//((CButton*)GetDlgItem(IDC_AUTO_SPIRITWALK))->SetCheck(d3Config.autoSpiritWalkEnable);
	//((CButton*)GetDlgItem(IDC_AUTO_SUMMONZOMBIEDOG))->SetCheck(d3Config.autoSummonZombieDogEnable);

	((CButton*)GetDlgItem(IDC_AUTO_POTION))->SetCheck(d3Config.autoPotionEnable);

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



	hGlobalKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookProc, GetModuleHandle(NULL), 0);





#ifdef _DEBUG
	GetDlgItem(IDC_DUMP_PERCENT_VALUE)->EnableWindow(true);
	GetDlgItem(IDC_DUMP_01_CDC_2d)->EnableWindow(true);
	GetDlgItem(IDC_DUMP_02_CDC_2d)->EnableWindow(true);
	GetDlgItem(IDC_DUMP_03_CDC_2d)->EnableWindow(true);
#endif // _DEBUG



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
	bool			IsValidLicense(void);
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
				flagOnF2 = false;
			}
			else
			{
				::GetWindowRect(d3Wnd, &d3Rect);
			}
			POINT point = { 0 };
			GetCursorPos(&point);
			WCHAR validToClick[100] = { 0 };
			//	extern int xOffsetItemInventoryArray[60];
			//	extern int yOffsetItemInventoryArray[60];
			//	
			//	for (int ix = -10; ix <= 10; ix++)
			//	{
			//		for (int iy = -10; iy <= 10; iy++)
			//		{
			//			if (d3Engine.ItemIsImperialDiamond(xOffsetItemInventoryArray[0]+ix, yOffsetItemInventoryArray[0]+iy))
			//			{
			//				swprintf(validToClick, L"%d %d", ix, iy);
			//			}
			//		}
			//	}


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
			if (current_character_type == CHARACTER_TYPE_MONK)
			{
				debugInfo.AppendFormat(L"Monk: %d%% spirits", d3Engine.SpiritEstimate());
			}
			//	if (current_character_type == CHARACTER_TYPE_DEMON_HUNTER)
			//	{
			//		debugInfo.AppendFormat(L"Hunter: %d%% spirits", d3Engine.DisciplineEstimate());
			//	}


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
				flagOnF2 = false;
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
				if (flagOnF2)
				{
					GetDlgItem(IDC_F2BIGFRAME)->SetWindowTextW(L"Skill (Hotkey F2) - Running");
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
			}





			/************************************************************************/
			/* Craft                                                                */
			/************************************************************************/
			if (d3Wnd != 0 && IsD3WindowActive() && (flagOnCtrl5 || flagOnCtrl6 || flagOnCtrl8 || flagOnCtrl9))
			{

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
					flagOnF2 = false;
					flagOnCtrl5 = false;
					flagOnCtrl6 = false;
					flagOnCtrl8 = false;
					flagOnCtrl9 = false;
				}
				d3Engine.VerifySalvageItem(preloadSalvageSlot, 60);


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







			}
			else
			{
				flagOnCtrl5 = false;
				flagOnCtrl6 = false;
			}






			flagOnMainProcess = false;
		}
	}
	else if (autoTimerID == nIdEvent && IsValidLicense())
	{
#ifdef PREMIUM_FEATURE
		if (d3Engine.ValidMode())
		{
			const int config_auto_skip_turn = 30 * 1000 / autoTimerDelay;
			static int scan_witch_doctor_skip_turn = 0;
			static int scan_barbarian_skip_turn = 0;
			static int scan_wizard_skip_turn = 0;
			static int scan_monk_skip_turn = 0;
			static int scan_demon_hunter_skip_turn = 0;
			static int scan_crusader_skip_turn = 0;
			static int scan_necromancer_skip_turn = 0;
			if (scan_witch_doctor_skip_turn > 0) scan_witch_doctor_skip_turn--;
			if (scan_barbarian_skip_turn > 0) scan_barbarian_skip_turn--;
			if (scan_wizard_skip_turn > 0) scan_wizard_skip_turn--;
			if (scan_monk_skip_turn > 0) scan_monk_skip_turn--;
			if (scan_demon_hunter_skip_turn > 0) scan_demon_hunter_skip_turn--;
			if (scan_crusader_skip_turn > 0) scan_crusader_skip_turn--;
			if (scan_necromancer_skip_turn > 0) scan_necromancer_skip_turn--;


			GetDlgItem(IDC_AUTO_CAST_SKILL_FRAME)->EnableWindow(TRUE);
			GetDlgItem(IDC_FORCESTANDTEXT)->EnableWindow(TRUE);
			GetDlgItem(IDC_TOWNPORTALKEY)->EnableWindow(TRUE);

			GetDlgItem(IDC_AUTO_BONE_AMOR)->EnableWindow(TRUE);
			GetDlgItem(IDC_AUTO_SIMULACRUM)->EnableWindow(TRUE);
			GetDlgItem(IDC_AUTO_COMMAND_SKELETONS)->EnableWindow(TRUE);
			GetDlgItem(IDC_AUTO_ARMY_OF_THE_DEAD)->EnableWindow(TRUE);

			GetDlgItem(IDC_AUTO_FANOFKNIVES)->EnableWindow(TRUE);
			GetDlgItem(IDC_AUTO_COMPANION)->EnableWindow(TRUE);
			GetDlgItem(IDC_AUTO_SHADOWPOWER)->EnableWindow(TRUE);
			GetDlgItem(IDC_AUTO_SMOKESCREEN)->EnableWindow(TRUE);
			GetDlgItem(IDC_AUTO_VENGEANCE)->EnableWindow(TRUE);

			GetDlgItem(IDC_AUTO_SERENITY)->EnableWindow(TRUE);
			GetDlgItem(IDC_AUTO_MANTRAOFRETRIBUTION)->EnableWindow(TRUE);

			//GetDlgItem(IDC_AUTO_GARGANTUAN)->EnableWindow(TRUE);
			//GetDlgItem(IDC_AUTO_SPIRITWALK)->EnableWindow(TRUE);
			//GetDlgItem(IDC_AUTO_SUMMONZOMBIEDOG)->EnableWindow(TRUE);

			GetDlgItem(IDC_AUTO_POTION)->EnableWindow(TRUE);



			if (townPortalDelay > 0) townPortalDelay -= autoTimerDelay;
			else if (townPortalDelay < 0) townPortalDelay = 0;
			if (townPortalDelay == 0)
			{
				/************************************************************************/
				/* Auto Cast Skill                                                      */
				/************************************************************************/
				if (d3Engine.D3IsOnBattle())
				{
					d3Engine.CaptureDesktop();
					bool flag_need_scan_skill_01 = true;
					bool flag_need_scan_skill_02 = true;
					bool flag_need_scan_skill_03 = true;
					bool flag_need_scan_skill_04 = true;

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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsBoneArmorReady())
							{
								SendD3Key(d3Config.keySKill02);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsBoneArmorReady())
							{
								SendD3Key(d3Config.keySKill03);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsBoneArmorReady())
							{
								SendD3Key(d3Config.keySKill04);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsSimulacrumReady())
							{
								SendD3Key(d3Config.keySKill02);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsSimulacrumReady())
							{
								SendD3Key(d3Config.keySKill03);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsSimulacrumReady())
							{
								SendD3Key(d3Config.keySKill04);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
						}
						if (d3Config.autoCommandSkeletonsEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsCommandSkeletonsReady())
							{
								SendD3Key(d3Config.keySKill01);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsCommandSkeletonsReady())
							{
								SendD3Key(d3Config.keySKill02);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsCommandSkeletonsReady())
							{
								SendD3Key(d3Config.keySKill03);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsCommandSkeletonsReady())
							{
								SendD3Key(d3Config.keySKill04);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
						}
						if (d3Config.autoArmyOfTheDeadEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsArmyOfTheDeadReady())
							{
								SendD3Key(d3Config.keySKill01);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsArmyOfTheDeadReady())
							{
								SendD3Key(d3Config.keySKill02);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsArmyOfTheDeadReady())
							{
								SendD3Key(d3Config.keySKill03);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsArmyOfTheDeadReady())
							{
								SendD3Key(d3Config.keySKill04);
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
								current_character_type = CHARACTER_TYPE_NECROMANCER;
							}
						}
					}
					if (scan_demon_hunter_skip_turn == 0)
					{
						if (d3Config.autoFanOfKnivesEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsFanOfKnivesReady())
							{
								SendD3Key(d3Config.keySKill01);
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsFanOfKnivesReady())
							{
								SendD3Key(d3Config.keySKill02);
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsFanOfKnivesReady())
							{
								SendD3Key(d3Config.keySKill03);
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsFanOfKnivesReady())
							{
								SendD3Key(d3Config.keySKill04);
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
						}
						if (d3Config.autoCompanionEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsCompanionReady())
							{
								SendD3Key(d3Config.keySKill01);
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsCompanionReady())
							{
								SendD3Key(d3Config.keySKill02);
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsCompanionReady())
							{
								SendD3Key(d3Config.keySKill03);
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsCompanionReady())
							{
								SendD3Key(d3Config.keySKill04);
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
						}
						if (d3Config.autoShadowPowerEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsShadowPowerReady())
							{
								SendD3Key(d3Config.keySKill01);
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsShadowPowerReady())
							{
								SendD3Key(d3Config.keySKill02);
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsShadowPowerReady())
							{
								SendD3Key(d3Config.keySKill03);
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsShadowPowerReady())
							{
								SendD3Key(d3Config.keySKill04);
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
						}
						if (d3Config.autoSmokeScreenEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsSmokeScreenReady())
							{
								SendD3Key(d3Config.keySKill01);
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsSmokeScreenReady())
							{
								SendD3Key(d3Config.keySKill02);
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsSmokeScreenReady())
							{
								SendD3Key(d3Config.keySKill03);
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsSmokeScreenReady())
							{
								SendD3Key(d3Config.keySKill04);
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
						}
						if (d3Config.autoVengeanceEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsVengeanceReady())
							{
								SendD3Key(d3Config.keySKill01);
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsVengeanceReady())
							{
								SendD3Key(d3Config.keySKill02);
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsVengeanceReady())
							{
								SendD3Key(d3Config.keySKill03);
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsVengeanceReady())
							{
								SendD3Key(d3Config.keySKill04);
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								scan_monk_skip_turn = config_auto_skip_turn;
								// scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
								current_character_type = CHARACTER_TYPE_DEMON_HUNTER;
							}
						}
					}
					if (scan_monk_skip_turn == 0)
					{

						if (d3Config.autoSerenityEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsSerenityReady())
							{
								SendD3Key(d3Config.keySKill01);
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								// scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
								current_character_type = CHARACTER_TYPE_MONK;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsSerenityReady())
							{
								SendD3Key(d3Config.keySKill02);
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								// scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
								current_character_type = CHARACTER_TYPE_MONK;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsSerenityReady())
							{
								SendD3Key(d3Config.keySKill03);
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								// scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
								current_character_type = CHARACTER_TYPE_MONK;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsSerenityReady())
							{
								SendD3Key(d3Config.keySKill04);
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								// scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
								current_character_type = CHARACTER_TYPE_MONK;
							}
						}
						if (d3Config.autoMantraOfRetributionEnable)
						{
							static int cache_scan_slot_01_skip_turn = 0;
							static int cache_scan_slot_02_skip_turn = 0;
							static int cache_scan_slot_03_skip_turn = 0;
							static int cache_scan_slot_04_skip_turn = 0;
							if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
							if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
							if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
							if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
							if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsMantraOfRetributionReady())
							{
								SendD3Key(d3Config.keySKill01);
								flag_need_scan_skill_01 = false;
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								// scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill01Enable) OnClickedSkill01Check();
								current_character_type = CHARACTER_TYPE_MONK;
							}
							else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsMantraOfRetributionReady() && d3Engine.SpiritEstimate() > 50)
							{
								SendD3Key(d3Config.keySKill02);
								flag_need_scan_skill_02 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								// scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill02Enable) OnClickedSkill02Check();
								current_character_type = CHARACTER_TYPE_MONK;
							}
							else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsMantraOfRetributionReady() && d3Engine.SpiritEstimate() > 50)
							{
								SendD3Key(d3Config.keySKill03);
								flag_need_scan_skill_03 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								// scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill03Enable) OnClickedSkill03Check();
								current_character_type = CHARACTER_TYPE_MONK;
							}
							else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsMantraOfRetributionReady() && d3Engine.SpiritEstimate() > 50)
							{
								SendD3Key(d3Config.keySKill04);
								flag_need_scan_skill_04 = false;
								//skip scan other character skill
								scan_witch_doctor_skip_turn = config_auto_skip_turn;
								scan_barbarian_skip_turn = config_auto_skip_turn;
								scan_wizard_skip_turn = config_auto_skip_turn;
								// scan_monk_skip_turn = config_auto_skip_turn;
								scan_demon_hunter_skip_turn = config_auto_skip_turn;
								scan_crusader_skip_turn = config_auto_skip_turn;
								scan_necromancer_skip_turn = config_auto_skip_turn;
								cache_scan_slot_01_skip_turn = config_auto_skip_turn;
								cache_scan_slot_02_skip_turn = config_auto_skip_turn;
								cache_scan_slot_03_skip_turn = config_auto_skip_turn;
								//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
								if (d3Config.skill04Enable) OnClickedSkill04Check();
								current_character_type = CHARACTER_TYPE_MONK;
							}
						}
					}


					//			if (scan_witch_doctor_skip_turn == 0)
					//			{
					//				if (d3Config.autoGargantuanEnable)
					//				{
					//					static int cache_scan_slot_01_skip_turn = 0;
					//					static int cache_scan_slot_02_skip_turn = 0;
					//					static int cache_scan_slot_03_skip_turn = 0;
					//					static int cache_scan_slot_04_skip_turn = 0;
					//					if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
					//					if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
					//					if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
					//					if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
					//					if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsGargantuanReady())
					//					{
					//						SendD3Key(d3Config.keySKill01);
					//						flag_need_scan_skill_01 = false;
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill01Enable) OnClickedSkill01Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsGargantuanReady())
					//					{
					//						SendD3Key(d3Config.keySKill02);
					//						flag_need_scan_skill_02 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill02Enable) OnClickedSkill02Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsGargantuanReady())
					//					{
					//						SendD3Key(d3Config.keySKill03);
					//						flag_need_scan_skill_03 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill03Enable) OnClickedSkill03Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsGargantuanReady())
					//					{
					//						SendD3Key(d3Config.keySKill04);
					//						flag_need_scan_skill_04 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill04Enable) OnClickedSkill04Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//				}
					//				if (d3Config.autoSpiritWalkEnable)
					//				{
					//					static int cache_scan_slot_01_skip_turn = 0;
					//					static int cache_scan_slot_02_skip_turn = 0;
					//					static int cache_scan_slot_03_skip_turn = 0;
					//					static int cache_scan_slot_04_skip_turn = 0;
					//					if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
					//					if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
					//					if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
					//					if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
					//					if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsSpiritWalkReady())
					//					{
					//						SendD3Key(d3Config.keySKill01);
					//						flag_need_scan_skill_01 = false;
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill01Enable) OnClickedSkill01Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsSpiritWalkReady())
					//					{
					//						SendD3Key(d3Config.keySKill02);
					//						flag_need_scan_skill_02 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill02Enable) OnClickedSkill02Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsSpiritWalkReady())
					//					{
					//						SendD3Key(d3Config.keySKill03);
					//						flag_need_scan_skill_03 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill03Enable) OnClickedSkill03Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsSpiritWalkReady())
					//					{
					//						SendD3Key(d3Config.keySKill04);
					//						flag_need_scan_skill_04 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill04Enable) OnClickedSkill04Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//				}
					//				if (d3Config.autoSummonZombieDogEnable && (!d3Engine.D3HaveFiveZombieDog()))
					//				{
					//					static int cache_scan_slot_01_skip_turn = 0;
					//					static int cache_scan_slot_02_skip_turn = 0;
					//					static int cache_scan_slot_03_skip_turn = 0;
					//					static int cache_scan_slot_04_skip_turn = 0;
					//					if (cache_scan_slot_01_skip_turn > 0) cache_scan_slot_01_skip_turn--;
					//					if (cache_scan_slot_02_skip_turn > 0) cache_scan_slot_02_skip_turn--;
					//					if (cache_scan_slot_03_skip_turn > 0) cache_scan_slot_03_skip_turn--;
					//					if (cache_scan_slot_04_skip_turn > 0) cache_scan_slot_04_skip_turn--;
					//					if (flag_need_scan_skill_01 && cache_scan_slot_01_skip_turn == 0 && d3Engine.D3Skill01IsSummonZombieDogReady())
					//					{
					//						SendD3Key(d3Config.keySKill01);
					//						flag_need_scan_skill_01 = false;
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						// cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill01Enable) OnClickedSkill01Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_02 && cache_scan_slot_02_skip_turn == 0 && d3Engine.D3Skill02IsSummonZombieDogReady())
					//					{
					//						SendD3Key(d3Config.keySKill02);
					//						flag_need_scan_skill_02 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						// cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill02Enable) OnClickedSkill02Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_03 && cache_scan_slot_03_skip_turn == 0 && d3Engine.D3Skill03IsSummonZombieDogReady())
					//					{
					//						SendD3Key(d3Config.keySKill03);
					//						flag_need_scan_skill_03 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						//cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill03Enable) OnClickedSkill03Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//					else if (flag_need_scan_skill_04 && cache_scan_slot_04_skip_turn == 0 && d3Engine.D3Skill04IsSummonZombieDogReady())
					//					{
					//						SendD3Key(d3Config.keySKill04);
					//						flag_need_scan_skill_04 = false;
					//						//skip scan other character skill
					//						scan_witch_doctor_skip_turn = config_auto_skip_turn;
					//						scan_barbarian_skip_turn = config_auto_skip_turn;
					//						scan_wizard_skip_turn = config_auto_skip_turn;
					//						// scan_monk_skip_turn = config_auto_skip_turn;
					//						scan_demon_hunter_skip_turn = config_auto_skip_turn;
					//						scan_crusader_skip_turn = config_auto_skip_turn;
					//						scan_necromancer_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_01_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_02_skip_turn = config_auto_skip_turn;
					//						cache_scan_slot_03_skip_turn = config_auto_skip_turn;
					//						//cache_scan_slot_04_skip_turn = config_auto_skip_turn;
					//						if (d3Config.skill04Enable) OnClickedSkill04Check();
					//						current_character_type = CHARACTER_TYPE_WITCH_DOCTOR;
					//					}
					//				}
					//			}








					if (d3Config.autoPotionEnable)
					{
						SendD3Key(d3Config.keyHealing);
						if (d3Config.healingEnable) OnClickedHealingCheck();
					}
				}



				/************************************************************************/
				/* Auto Reroll support                                                  */
				/************************************************************************/
				if (IsD3WindowActive() && enableRerollSupport
					&& (!(flagOnF2 || flagOnCtrl5 || flagOnCtrl6 || flagOnCtrl9 || flagOnAutoProcess))
					&& d3Engine.IsRolling())
				{
					d3Engine.CaptureDesktop();

					flagOnAutoProcess = true;
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
					flagOnAutoProcess = false;
				}

			}
		}
		else
		{
			GetDlgItem(IDC_AUTO_CAST_SKILL_FRAME)->EnableWindow(FALSE);
			GetDlgItem(IDC_FORCESTANDTEXT)->EnableWindow(FALSE);
			GetDlgItem(IDC_TOWNPORTALKEY)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_BONE_AMOR)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_SIMULACRUM)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_COMMAND_SKELETONS)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_ARMY_OF_THE_DEAD)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_FANOFKNIVES)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_COMPANION)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_SHADOWPOWER)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_SMOKESCREEN)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_VENGEANCE)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_SERENITY)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_MANTRAOFRETRIBUTION)->EnableWindow(FALSE);
			//GetDlgItem(IDC_AUTO_GARGANTUAN)->EnableWindow(FALSE);
			//GetDlgItem(IDC_AUTO_SPIRITWALK)->EnableWindow(FALSE);
			//GetDlgItem(IDC_AUTO_SUMMONZOMBIEDOG)->EnableWindow(FALSE);
			GetDlgItem(IDC_AUTO_POTION)->EnableWindow(FALSE);
		}
		((CButton*)GetDlgItem(IDC_ENABLE_REROLL_SUPPORT))->SetCheck(enableRerollSupport);
		GetDlgItem(IDC_REROL_SUPPORT_DETAIL)->EnableWindow(enableRerollSupport);
#else
		GetDlgItem(IDC_AUTO_REROLL_SUPPORT_FRAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_ENABLE_REROLL_SUPPORT)->EnableWindow(FALSE);
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
void CDiabloIIISupportDlg::OnChangeLicense()
{
	wchar_t bufferText[1000] = { 0 };
	GetDlgItem(IDC_LICENSE)->GetWindowTextW(bufferText, 999);
	bool			ScanLicenseID(const wchar_t* licenseID);
	if (ScanLicenseID(bufferText))
	{
		GetDlgItem(IDC_LICENSE)->EnableWindow(FALSE);
		GetDlgItem(IDC_LICENSE)->ShowWindow(SW_HIDE);
	}

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
void CDiabloIIISupportDlg::OnClickedAutoCommandSkeletons()
{
	d3Config.autoCommandSkeletonsEnable = !d3Config.autoCommandSkeletonsEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoArmyOfTheDead()
{
	d3Config.autoArmyOfTheDeadEnable = !d3Config.autoArmyOfTheDeadEnable;
	OnSaveConfig();
}








void CDiabloIIISupportDlg::OnClickedAutoFanofknives()
{
	d3Config.autoFanOfKnivesEnable = !d3Config.autoFanOfKnivesEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoCompanion()
{
	d3Config.autoCompanionEnable = !d3Config.autoCompanionEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoShadowpower()
{
	d3Config.autoShadowPowerEnable = !d3Config.autoShadowPowerEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoSmokescreen()
{
	d3Config.autoSmokeScreenEnable = !d3Config.autoSmokeScreenEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoVengeance()
{
	d3Config.autoVengeanceEnable = !d3Config.autoVengeanceEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoSerenity()
{
	d3Config.autoSerenityEnable = !d3Config.autoSerenityEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnBnClickedAutoMantraOfRetribution()
{
	d3Config.autoMantraOfRetributionEnable = !d3Config.autoMantraOfRetributionEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoGargantuan()
{
	d3Config.autoGargantuanEnable = !d3Config.autoGargantuanEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoSpiritwalk()
{
	d3Config.autoSpiritWalkEnable = !d3Config.autoSpiritWalkEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoSummonzombiedog()
{
	d3Config.autoSummonZombieDogEnable = !d3Config.autoSummonZombieDogEnable;
	OnSaveConfig();
}
void CDiabloIIISupportDlg::OnClickedAutoPotion()
{
	d3Config.autoPotionEnable = !d3Config.autoPotionEnable;
	OnSaveConfig();
}




void CDiabloIIISupportDlg::OnChangeDumpPercentValue()
{
	GetDlgItem(IDC_DUMP_PERCENT_VALUE)->GetWindowTextW(dumpvalue, 99);
}

void CDiabloIIISupportDlg::OnClickedDump01Cdc2d()
{
#ifdef DEBUG
	d3Engine.Dump2DigitByCriticalHitDamageLine01(dumpvalue);
#endif // DEBUG
}
void CDiabloIIISupportDlg::OnClickedDump02Cdc2d()
{
#ifdef DEBUG
	d3Engine.Dump2DigitByCriticalHitDamageLine02(dumpvalue);
#endif // DEBUG
}
void CDiabloIIISupportDlg::OnClickedDump03Cdc2d()
{
#ifdef DEBUG
	d3Engine.Dump2DigitByCriticalHitDamageLine03(dumpvalue);
#endif // DEBUG
}






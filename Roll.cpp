#include "Roll.h"
#include "Engine.h"
extern Win32GDI w32gdi;
void		SetD3Mouse(int x, int y);
void		SendD3LeftMouseClick();


wchar_t* get_roll_name(ROLL_OPTION x)
{
	switch (x)
	{
	case ROLL_OPTION_UNKNOWN:
		return L"-";
		break;
	case ROLL_OPTION_DHSKILL_HUNGERING_ARROW:
		return L"DH - Hungering Arrow";
		break;
	case ROLL_OPTION_DHSKILL_BOLAS:
		return L"DH - Bolas";
		break;
	case ROLL_OPTION_DHSKILL_GRENADE:
		return L"DH - Grenade";
		break;
	case ROLL_OPTION_DHSKILL_ENTANGLING_SHOT:
		return L"DH - Entangling Shot";
		break;
	case ROLL_OPTION_DHSKILL_EVASIVE_FIRE:
		return L"DH - Evasive Fire";
		break;
	case ROLL_OPTION_REDUCE_MELEE_DAMAGE:
		return L"Reduce melee damage";
		break;
	case ROLL_OPTION_REDUCE_RANGED_DAMAGE:
		return L"Reduce ranged damage";
		break;
	case ROLL_OPTION_LIFE_PERCENT:
		return L"+% life";
		break;
	case ROLL_OPTION_REGEN_LIFE:
		return L"Regenerate life";
		break;
	case ROLL_OPTION_ARMOR:
		return L"Armor";
		break;
	case ROLL_OPTION_THORN_DAMAGE:
		return L"Thorn damage";
		break;
	case ROLL_OPTION_HEALING_GLOBE:
		return L"Healing Globe";
		break;
	case ROLL_OPTION_GOLD_PICKUP:
		return L"Gold Pickup";
		break;
	case ROLL_OPTION_EXP:
		L"Exp after kill";
		break;
	default:
		return L"-";
		break;
	}
	return L"-";
}

wchar_t* get_parameter_name(ROLL_PARAMETER x)
{
	switch (x)
	{
	case ROLL_PARAMETER_UNKNOWN:
		return L"-";
		break;
	case ROLL_PARAMETER_15_PERCENT:
		return L"Parameter: 15%";
		break;
	case ROLL_PARAMETER_14_PERCENT:
		return L"Parameter: 14%";
		break;
	case ROLL_PARAMETER_13_PERCENT:
		return L"Parameter: 13%";
		break;
	case ROLL_PARAMETER_12_PERCENT:
		return L"Parameter: 12%";
		break;
	case ROLL_PARAMETER_11_PERCENT:
		return L"Parameter: 11%";
		break;
	case ROLL_PARAMETER_10_PERCENT:
		return L"Parameter: 10%";
		break;
	case ROLL_PARAMETER_07_PERCENT:
		return L"Parameter: 7%";
		break;
	default:
		return L"-";
		break;
	}
	return L"-";
}

wchar_t* get_item_name(ROLL_ITEM x)
{
	switch (x)
	{
	case ROLL_ITEM_UNKNOWN:
		return L"-";
		break;
	case ROLL_ITEM_HUNTERS_WRATH:
		return L"Hunter's Wrath";
		break;
	default:
		break;
	}
	return L"-";
}




ROLL_OPTION get_roll_option_01(void)
{
	if (w32gdi.RollingOption01IsHungeringArrow()) return ROLL_OPTION_DHSKILL_HUNGERING_ARROW;
	if (w32gdi.RollingOption01IsEvasiveFire()) return ROLL_OPTION_DHSKILL_EVASIVE_FIRE;
	if (w32gdi.RollingOption01IsRegenHP()) return ROLL_OPTION_REGEN_LIFE;



	return ROLL_OPTION_UNKNOWN;
}


ROLL_OPTION get_roll_option_02(void)
{
	if (w32gdi.RollingOption02IsHungeringArrow()) return ROLL_OPTION_DHSKILL_HUNGERING_ARROW;
	if (w32gdi.RollingOption02IsBolas()) return ROLL_OPTION_DHSKILL_BOLAS;
	if (w32gdi.RollingOption02IsGrenade()) return ROLL_OPTION_DHSKILL_GRENADE;
	if (w32gdi.RollingOption02IsEntanglingShot()) return ROLL_OPTION_DHSKILL_ENTANGLING_SHOT;
	if (w32gdi.RollingOption02IsEvasiveFire()) return ROLL_OPTION_DHSKILL_EVASIVE_FIRE;
	if (w32gdi.RollingOption02IsRegenHP()) return ROLL_OPTION_REGEN_LIFE;
	



	return ROLL_OPTION_UNKNOWN;
}

ROLL_OPTION get_roll_option_03(void)
{
	if (w32gdi.RollingOption03IsHungeringArrow()) return ROLL_OPTION_DHSKILL_HUNGERING_ARROW;
	if (w32gdi.RollingOption03IsRegenHP()) return ROLL_OPTION_REGEN_LIFE;
	if (w32gdi.RollingOption03IsLifePercent()) return ROLL_OPTION_LIFE_PERCENT;

	if (w32gdi.RollingOption03IsArmor()) return ROLL_OPTION_ARMOR;

	return ROLL_OPTION_UNKNOWN;
}






ROLL_PARAMETER get_roll_parameter_01(void)
{
	if (w32gdi.RollingOption01Is15Percent()) return ROLL_PARAMETER_15_PERCENT;
	if (w32gdi.RollingOption01Is14Percent()) return ROLL_PARAMETER_14_PERCENT;
	if (w32gdi.RollingOption01Is13Percent()) return ROLL_PARAMETER_13_PERCENT;
	//if (w32gdi.RollingOption01Is12Percent()) return ROLL_PARAMETER_12_PERCENT;
	//if (w32gdi.RollingOption01Is11Percent()) return ROLL_PARAMETER_11_PERCENT;
	//if (w32gdi.RollingOption01Is10Percent()) return ROLL_PARAMETER_10_PERCENT;
	if (w32gdi.RollingOption01Is07Percent()) return ROLL_PARAMETER_07_PERCENT;
	//if (w32gdi.RollingOption01Is06Percent()) return ROLL_PARAMETER_06_PERCENT;
	return ROLL_PARAMETER_UNKNOWN;
}
ROLL_PARAMETER get_roll_parameter_02(void)
{
	if (w32gdi.RollingOption02Is15Percent()) return ROLL_PARAMETER_15_PERCENT;
	//if (w32gdi.RollingOption02Is14Percent()) return ROLL_PARAMETER_14_PERCENT;
	//if (w32gdi.RollingOption02Is13Percent()) return ROLL_PARAMETER_13_PERCENT;
	//if (w32gdi.RollingOption02Is12Percent()) return ROLL_PARAMETER_12_PERCENT;
	//if (w32gdi.RollingOption02Is11Percent()) return ROLL_PARAMETER_11_PERCENT;
	if (w32gdi.RollingOption02Is10Percent()) return ROLL_PARAMETER_10_PERCENT;
	//if (w32gdi.RollingOption02Is07Percent()) return ROLL_PARAMETER_07_PERCENT;
	//if (w32gdi.RollingOption02Is06Percent()) return ROLL_PARAMETER_06_PERCENT;
	return ROLL_PARAMETER_UNKNOWN;
}
ROLL_PARAMETER get_roll_parameter_03(void)
{
	if (w32gdi.RollingOption03Is15Percent()) return ROLL_PARAMETER_15_PERCENT;
	//if (w32gdi.RollingOption03Is14Percent()) return ROLL_PARAMETER_14_PERCENT;
	//if (w32gdi.RollingOption03Is13Percent()) return ROLL_PARAMETER_13_PERCENT;
	//if (w32gdi.RollingOption03Is12Percent()) return ROLL_PARAMETER_12_PERCENT;
	//if (w32gdi.RollingOption03Is11Percent()) return ROLL_PARAMETER_11_PERCENT;
	//if (w32gdi.RollingOption03Is10Percent()) return ROLL_PARAMETER_10_PERCENT;
	//if (w32gdi.RollingOption03Is07Percent()) return ROLL_PARAMETER_07_PERCENT;
	//if (w32gdi.RollingOption03Is06Percent()) return ROLL_PARAMETER_06_PERCENT;
	return ROLL_PARAMETER_UNKNOWN;
}

RESOURCE_STATUS get_resource_status(void)
{
	if (w32gdi.IsFullResourceForClothes()) return RESOURCE_STATUS_FULL_FOR_CLOTHES;

	return RESOURCE_STATUS();
}

wchar_t* get_resource_info(RESOURCE_STATUS x)
{
	switch (x)
	{
	case RESOURCE_STATUS_UNKNOWN:
		return L"-";
		break;
	case RESOURCE_STATUS_FULL_FOR_CLOTHES:
		return L"Full for clothes";
		break;
	default:
		return L"-";
		break;
	}
	return L"-";
}

ROLL_ITEM get_roll_item(void)
{
	if (w32gdi.IsRollingHuntersWrath()) return ROLL_ITEM_HUNTERS_WRATH;
	return ROLL_ITEM_UNKNOWN;
}

/************************************************************************/
/* Action                                                               */
/************************************************************************/
void do_roll(ROLL_ITEM item,
	ROLL_OPTION option_01, ROLL_PARAMETER parameter_01,
	ROLL_OPTION option_02, ROLL_PARAMETER parameter_02,
	ROLL_OPTION option_03, ROLL_PARAMETER parameter_03,
	RESOURCE_STATUS resource_status)
{




	if (option_01 + option_02 + option_03 + parameter_01 + parameter_02 + parameter_03 > 0 && w32gdi.D3IsRollWaiting() == false)
	{
		ROLL_DESCISION final_decision = DESCISION_NOTHING;

		if (item == ROLL_ITEM_HUNTERS_WRATH)
		{
			if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW || option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW || option_03 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW)
			{// Need HUNGERING_ARROW

				// HUNGERING_ARROW 15% - kết thúc 
				if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW && parameter_01 == ROLL_PARAMETER_15_PERCENT)
				{
					final_decision = DESCISION_STAY_IN_OPTION_01;
				}
				else if (option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW && parameter_02 == ROLL_PARAMETER_15_PERCENT)
				{
					final_decision = DESCISION_SELECT_OPTION_02_AND_STOP_ROLL;
				}
				else if (option_03 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW && parameter_03 == ROLL_PARAMETER_15_PERCENT)
				{
					final_decision = DESCISION_SELECT_OPTION_03_AND_STOP_ROLL;
				}

				// Chỉ có 1 dòng HUNGERING_ARROW
				else if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_02 != ROLL_OPTION_UNKNOWN && option_02 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_03 != ROLL_OPTION_UNKNOWN && option_03 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW)
				{
					final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
				}
				else if (option_01!= ROLL_OPTION_UNKNOWN && option_01!= ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_03 != ROLL_OPTION_UNKNOWN && option_03 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW)
				{
					final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				}
				else if (option_01 != ROLL_OPTION_UNKNOWN && option_01 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_02 != ROLL_OPTION_UNKNOWN && option_02 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_03 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW)
				{
					final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				}

				//Chỉ có 2 dòng HUNGERING_ARROW
				else if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_03 != ROLL_OPTION_UNKNOWN && option_03 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& parameter_01!= ROLL_PARAMETER_UNKNOWN
					&& parameter_02 != ROLL_PARAMETER_UNKNOWN
					)
				{
					//final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
				}

			}
		}

		if (final_decision == DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT)
		{
			//Chọn dòng 1
			SetD3Mouse(180, 394);
			SendD3LeftMouseClick();
			Sleep(50 + (rand() % 5));
			SendD3LeftMouseClick();
			// Chọn nút select
			w32gdi.CaptureDesktop();
			if (w32gdi.D3IsRollSelecting())
			{
				SetD3Mouse(256, 780);
				Sleep(50 + (rand() % 5));
				SendD3LeftMouseClick();
				Sleep(50 + (rand() % 5));
			}
			Sleep(500 + (rand() % 5));
		}
		else if (final_decision == DESCISION_SELECT_OPTION_02_AND_STOP_ROLL)
		{
			//Chọn dòng 2
			SetD3Mouse(180, 440);
			SendD3LeftMouseClick();
			Sleep(50 + (rand() % 5));
			SendD3LeftMouseClick();
			// Chọn nút select
			w32gdi.CaptureDesktop();
			if (w32gdi.D3IsRollSelecting())
			{
				SetD3Mouse(350, 780);
				Sleep(50 + (rand() % 5));
				SendD3LeftMouseClick();
				Sleep(50 + (rand() % 5));
			}
			// Move chuột ra chỗ khác
			SetD3Mouse(256, 730);
			Sleep(50 + (rand() % 5));
			Sleep(500 + (rand() % 5));
		}
		else if (final_decision == DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT)
		{
			//Chọn dòng 2
			SetD3Mouse(180, 440);
			SendD3LeftMouseClick();
			Sleep(50 + (rand() % 5));
			SendD3LeftMouseClick();
			// Chọn nút select
			w32gdi.CaptureDesktop();
			if (w32gdi.D3IsRollSelecting())
			{
				SetD3Mouse(350, 780);
				Sleep(50 + (rand() % 5));
				SendD3LeftMouseClick();
				Sleep(50 + (rand() % 5));
			}
			Sleep(500 + (rand() % 5));
		}
		else if (final_decision == DESCISION_SELECT_OPTION_03_AND_STOP_ROLL)
		{
			//Chọn dòng 3
			SetD3Mouse(180, 480);
			SendD3LeftMouseClick();
			Sleep(50 + (rand() % 5));
			SendD3LeftMouseClick();
			// Chọn nút select
			w32gdi.CaptureDesktop();
			if (w32gdi.D3IsRollSelecting())
			{
				SetD3Mouse(350, 780);
				Sleep(50 + (rand() % 5));
				SendD3LeftMouseClick();
				Sleep(50 + (rand() % 5));
			}
			// Move chuột ra chỗ khác
			SetD3Mouse(256, 730);
			Sleep(50 + (rand() % 5));
			Sleep(500 + (rand() % 5));
		}
		else if (final_decision == DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT)
		{
			//Chọn dòng 3
			SetD3Mouse(180, 480);
			SendD3LeftMouseClick();
			Sleep(50 + (rand() % 5));
			SendD3LeftMouseClick();
			// Chọn nút select
			w32gdi.CaptureDesktop();
			if (w32gdi.D3IsRollSelecting())
			{
				SetD3Mouse(350, 780);
				Sleep(50 + (rand() % 5));
				SendD3LeftMouseClick();
				Sleep(50 + (rand() % 5));
			}
			Sleep(500 + (rand() % 5));
		}
		






	}


}
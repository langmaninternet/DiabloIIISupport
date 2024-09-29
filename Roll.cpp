#include "Roll.h"
#include "Engine.h"
extern Win32GDI w32gdi;


wchar_t* get_roll_name(ROLL_OPTION x)
{
	switch (x)
	{
	case ROLL_OPTION_UNKNOWN:
		return L"-";
		break;
	case ROLL_OPTION_HUNGERING_ARROW:
		return L"Hungering Arrow";
		break;
	case ROLL_OPTION_REDUCE_MELEE_DAMAGE:
		return L"Reduce melee damage";
		break;
	case ROLL_OPTION_REDUCE_RANGED_DAMAGE:
		return L"Reduce ranged damage";
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





ROLL_OPTION get_roll_option_01(void)
{
	if (w32gdi.RollingOption01IsHungeringArrow()) return ROLL_OPTION_HUNGERING_ARROW;




	return ROLL_OPTION_UNKNOWN;
}


ROLL_OPTION get_roll_option_02(void)
{
	if (w32gdi.RollingOption02IsHungeringArrow()) return ROLL_OPTION_HUNGERING_ARROW;




	return ROLL_OPTION_UNKNOWN;
}

ROLL_OPTION get_roll_option_03(void)
{
	if (w32gdi.RollingOption03IsHungeringArrow()) return ROLL_OPTION_HUNGERING_ARROW;




	return ROLL_OPTION_UNKNOWN;
}






ROLL_PARAMETER get_roll_parameter_01(void)
{
	if (w32gdi.RollingOption01Is15Percent()) return ROLL_PARAMETER_15_PERCENT;
	if (w32gdi.RollingOption01Is14Percent()) return ROLL_PARAMETER_14_PERCENT;
	//if (w32gdi.RollingOption01Is13Percent()) return ROLL_PARAMETER_13_PERCENT;
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
	//if (w32gdi.RollingOption02Is10Percent()) return ROLL_PARAMETER_10_PERCENT;
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

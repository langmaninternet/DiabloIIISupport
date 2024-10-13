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

		// 1. CriticalHit
	case ROLL_OPTION_CRITICAL_HIT_CHANCE:
		return L"Critical Hit Chance";
		break;
	case ROLL_OPTION_CRITICAL_HIT_DAMAGE:
		return L"Critical Hit Damage";
		break;


		// 2. Socket

	case ROLL_OPTION_ONE_SOCKET:
		return L"Socket (1)";
		break;
	case ROLL_OPTION_TWO_SOCKET:
		return L"Socket (2)";
		break;
	case ROLL_OPTION_THREE_SOCKET:
		return L"Socket (3)";
		break;


		// 3. Damage
	case ROLL_OPTION_BASE_DAMAGE:
		return L"Base Damage";
		break;
	case ROLL_OPTION_AREA_DAMAGE:
		return L"Area Damage";
		break;


		//4. Stats
	case ROLL_OPTION_STRENGTH:
		return L"Strength";
		break;
	case ROLL_OPTION_DEXTERITY:
		return L"Dexterity";
		break;
	case ROLL_OPTION_INTELLIGENCE:
		return L"Intelligence";
		break;
	case ROLL_OPTION_VITALITY:
		return L"Vitality";
		break;





		// 5. Reduce
	case ROLL_OPTION_REDUCE_MELEE_DAMAGE:
		return L"Reduce melee damage";
		break;
	case ROLL_OPTION_REDUCE_RANGED_DAMAGE:
		return L"Reduce ranged damage";
		break;
	case ROLL_OPTION_REDUCE_COOLDOWN:
		return L"Reduce cooldown";
		break;
	case ROLL_OPTION_REDUCE_RESOURCE:
		return L"Reduce resource cost";
		break;


		// 6. Attack speed
	case ROLL_OPTION_ATTACK_SPEED:
		return L"Attack speed";
		break;

	case ROLL_OPTION_RESIST_ALL:
		return L"Resist All";
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

	case ROLL_OPTION_LIFE_PERCENT:
		return L"+% life";
		break;
	case ROLL_OPTION_LIFE_PER_SECOND:
		return L"Life per second";
		break;
	case ROLL_OPTION_LIFE_HIT:
		return L"Life per hit";
		break;
	case ROLL_OPTION_LIFE_KILL:
		return L"Life per kill";
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
		return L"";
		break;
	case ROLL_PARAMETER_04_PERCENT:
		return L" + %";
		break;
	case ROLL_PARAMETER_04_D_5_PERCENT:
		return L" + 4.5%";
		break;
	case ROLL_PARAMETER_05_PERCENT:
		return L" + 5%";
		break;
	case ROLL_PARAMETER_05_D_5_PERCENT:
		return L" + 5.5%";
		break;
	case ROLL_PARAMETER_06_PERCENT:
		return L" + 6%";
		break;
	case ROLL_PARAMETER_07_PERCENT:
		return L" + 7%";
		break;
	case ROLL_PARAMETER_08_PERCENT:
		return L" + 8%";
		break;
	case ROLL_PARAMETER_09_PERCENT:
		return L" + 9%";
		break;
	case ROLL_PARAMETER_10_PERCENT:
		return L" + 10%";
		break;
	case ROLL_PARAMETER_11_PERCENT:
		return L" + 11%";
		break;
	case ROLL_PARAMETER_12_PERCENT:
		return L" + 12%";
		break;
	case ROLL_PARAMETER_13_PERCENT:
		return L" + 13%";
		break;
	case ROLL_PARAMETER_14_PERCENT:
		return L" + 14%";
		break;
	case ROLL_PARAMETER_15_PERCENT:
		return L" + 15%";
		break;
	case ROLL_PARAMETER_16_PERCENT:
		return L" + 16%";
		break;
	case ROLL_PARAMETER_17_PERCENT:
		return L" + 17%";
		break;
	case ROLL_PARAMETER_18_PERCENT:
		return L" + 18%";
		break;
	case ROLL_PARAMETER_19_PERCENT:
		return L" + 19%";
		break;
	case ROLL_PARAMETER_20_PERCENT:
		return L" + 20%";
		break;
	case ROLL_PARAMETER_21_PERCENT:
		return L" + 21%";
		break;
	case ROLL_PARAMETER_22_PERCENT:
		return L" + 22%";
		break;
	case ROLL_PARAMETER_23_PERCENT:
		return L" + 23%";
		break;
	case ROLL_PARAMETER_24_PERCENT:
		return L" + 24%";
		break;
	case ROLL_PARAMETER_25_PERCENT:
		return L" + 25%";
		break;
	case ROLL_PARAMETER_26_PERCENT:
		return L" + 26%";
		break;
	case ROLL_PARAMETER_27_PERCENT:
		return L" + 27%";
		break;
	case ROLL_PARAMETER_28_PERCENT:
		return L" + 28%";
		break;
	case ROLL_PARAMETER_29_PERCENT:
		return L" + 29%";
		break;
	case ROLL_PARAMETER_30_PERCENT:
		return L" + 30%";
		break;
	case ROLL_PARAMETER_31_PERCENT:
		return L" + 31%";
		break;
	case ROLL_PARAMETER_32_PERCENT:
		return L" + 32%";
		break;
	case ROLL_PARAMETER_33_PERCENT:
		return L" + 33%";
		break;
	case ROLL_PARAMETER_34_PERCENT:
		return L" + 34%";
		break;
	case ROLL_PARAMETER_35_PERCENT:
		return L" + 35%";
		break;
	case ROLL_PARAMETER_36_PERCENT:
		return L" + 36%";
		break;
	case ROLL_PARAMETER_37_PERCENT:
		return L" + 37%";
		break;
	case ROLL_PARAMETER_38_PERCENT:
		return L" + 38%";
		break;
	case ROLL_PARAMETER_39_PERCENT:
		return L" + 39%";
		break;
	case ROLL_PARAMETER_40_PERCENT:
		return L" + 40%";
		break;
	case ROLL_PARAMETER_41_PERCENT:
		return L" + 41%";
		break;
	case ROLL_PARAMETER_42_PERCENT:
		return L" + 42%";
		break;
	case ROLL_PARAMETER_43_PERCENT:
		return L" + 43%";
		break;
	case ROLL_PARAMETER_44_PERCENT:
		return L" + 44%";
		break;
	case ROLL_PARAMETER_45_PERCENT:
		return L" + 45%";
		break;
	case ROLL_PARAMETER_46_PERCENT:
		return L" + 46%";
		break;
	case ROLL_PARAMETER_47_PERCENT:
		return L" + 47%";
		break;
	case ROLL_PARAMETER_48_PERCENT:
		return L" + 48%";
		break;
	case ROLL_PARAMETER_49_PERCENT:
		return L" + 49%";
		break;
	case ROLL_PARAMETER_50_PERCENT:
		return L" + 50%";
		break;
	case ROLL_PARAMETER_51_PERCENT:
		return L" + 51%";
		break;
	case ROLL_PARAMETER_52_PERCENT:
		return L" + 52%";
		break;
	case ROLL_PARAMETER_53_PERCENT:
		return L" + 53%";
		break;
	case ROLL_PARAMETER_54_PERCENT:
		return L" + 54%";
		break;
	case ROLL_PARAMETER_55_PERCENT:
		return L" + 55%";
		break;
	case ROLL_PARAMETER_56_PERCENT:
		return L" + 56%";
		break;
	case ROLL_PARAMETER_57_PERCENT:
		return L" + 57%";
		break;
	case ROLL_PARAMETER_58_PERCENT:
		return L" + 58%";
		break;
	case ROLL_PARAMETER_59_PERCENT:
		return L" + 59%";
		break;
	case ROLL_PARAMETER_60_PERCENT:
		return L" + 60%";
		break;
	case ROLL_PARAMETER_61_PERCENT:
		return L" + 61%";
		break;
	case ROLL_PARAMETER_62_PERCENT:
		return L" + 62%";
		break;
	case ROLL_PARAMETER_63_PERCENT:
		return L" + 63%";
		break;
	case ROLL_PARAMETER_64_PERCENT:
		return L" + 64%";
		break;
	case ROLL_PARAMETER_65_PERCENT:
		return L" + 65%";
		break;
	case ROLL_PARAMETER_66_PERCENT:
		return L" + 66%";
		break;
	case ROLL_PARAMETER_67_PERCENT:
		return L" + 67%";
		break;
	case ROLL_PARAMETER_68_PERCENT:
		return L" + 68%";
		break;
	case ROLL_PARAMETER_69_PERCENT:
		return L" + 69%";
		break;
	case ROLL_PARAMETER_70_PERCENT:
		return L" + 70%";
		break;
	case ROLL_PARAMETER_71_PERCENT:
		return L" + 71%";
		break;
	case ROLL_PARAMETER_72_PERCENT:
		return L" + 72%";
		break;
	case ROLL_PARAMETER_73_PERCENT:
		return L" + 73%";
		break;
	case ROLL_PARAMETER_74_PERCENT:
		return L" + 74%";
		break;
	case ROLL_PARAMETER_75_PERCENT:
		return L" + 75%";
		break;
	case ROLL_PARAMETER_76_PERCENT:
		return L" + 76%";
		break;
	case ROLL_PARAMETER_77_PERCENT:
		return L" + 77%";
		break;
	case ROLL_PARAMETER_78_PERCENT:
		return L" + 78%";
		break;
	case ROLL_PARAMETER_79_PERCENT:
		return L" + 79%";
		break;
	case ROLL_PARAMETER_80_PERCENT:
		return L" + 80%";
		break;
	case ROLL_PARAMETER_81_PERCENT:
		return L" + 81%";
		break;
	case ROLL_PARAMETER_82_PERCENT:
		return L" + 82%";
		break;
	case ROLL_PARAMETER_83_PERCENT:
		return L" + 83%";
		break;
	case ROLL_PARAMETER_84_PERCENT:
		return L" + 84%";
		break;
	case ROLL_PARAMETER_85_PERCENT:
		return L" + 85%";
		break;
	case ROLL_PARAMETER_86_PERCENT:
		return L" + 86%";
		break;
	case ROLL_PARAMETER_87_PERCENT:
		return L" + 87%";
		break;
	case ROLL_PARAMETER_88_PERCENT:
		return L" + 88%";
		break;
	case ROLL_PARAMETER_89_PERCENT:
		return L" + 89%";
		break;
	case ROLL_PARAMETER_90_PERCENT:
		return L" + 90%";
		break;
	case ROLL_PARAMETER_91_PERCENT:
		return L" + 91%";
		break;
	case ROLL_PARAMETER_92_PERCENT:
		return L" + 92%";
		break;
	case ROLL_PARAMETER_93_PERCENT:
		return L" + 93%";
		break;
	case ROLL_PARAMETER_94_PERCENT:
		return L" + 94%";
		break;
	case ROLL_PARAMETER_95_PERCENT:
		return L" + 95%";
		break;
	case ROLL_PARAMETER_96_PERCENT:
		return L" + 96%";
		break;
	case ROLL_PARAMETER_97_PERCENT:
		return L" + 97%";
		break;
	case ROLL_PARAMETER_98_PERCENT:
		return L" + 98%";
		break;
	case ROLL_PARAMETER_99_PERCENT:
		return L" + 99%";
		break;
	case ROLL_PARAMETER_100_PERCENT:
		return L" + 100%";
		break;

	default:
		return L"";
		break;
	}
	return L"";
}
wchar_t* get_item_name(ROLL_ITEM x)
{
	switch (x)
	{
	case ROLL_ITEM_UNKNOWN:
		return L"-";
		break;
		//case ROLL_ITEM_FOCUS:
		//	return L"Focus";
		//	break;
		//case ROLL_ITEM_COE:
		//	return L"CoE";
		//	break;
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
	// 1. CriticalHit
	if (w32gdi.RollingOption01IsCriticalHitChance()) return ROLL_OPTION_CRITICAL_HIT_CHANCE;
	if (w32gdi.RollingOption01IsCriticalHitDamage()) return ROLL_OPTION_CRITICAL_HIT_DAMAGE;
	// 2. Socket
	//if (w32gdi.RollingOption02IsOneSocket()) return ROLL_OPTION_ONE_SOCKET;
	// 3. Damage
	if (w32gdi.RollingOption01IsAreaDamage()) return ROLL_OPTION_AREA_DAMAGE;
	if (w32gdi.RollingOption01IsBaseDamage()) return ROLL_OPTION_BASE_DAMAGE;



	//4. Stats


	// 5. Reduce Damage
	if (w32gdi.RollingOption01IsReduceMeleeDamage()) return ROLL_OPTION_REDUCE_MELEE_DAMAGE;



	// 5. Reduce
	if (w32gdi.RollingOption01IsReduceResource()) return ROLL_OPTION_REDUCE_RESOURCE;

	// 6. Attack Speed
	if (w32gdi.RollingOption01IsAttackSpeed()) return ROLL_OPTION_ATTACK_SPEED;

	//7. Life
	if (w32gdi.RollingOption01IsLifePerKill()) return ROLL_OPTION_LIFE_KILL;

	if (w32gdi.RollingOption01IsHungeringArrow()) return ROLL_OPTION_DHSKILL_HUNGERING_ARROW;
	if (w32gdi.RollingOption01IsBolas()) return ROLL_OPTION_DHSKILL_BOLAS;
	if (w32gdi.RollingOption01IsGrenade()) return ROLL_OPTION_DHSKILL_GRENADE;
	if (w32gdi.RollingOption01IsEntanglingShot()) return ROLL_OPTION_DHSKILL_ENTANGLING_SHOT;
	if (w32gdi.RollingOption01IsEvasiveFire()) return ROLL_OPTION_DHSKILL_EVASIVE_FIRE;
	if (w32gdi.RollingOption01IsLifePerSecond()) return ROLL_OPTION_LIFE_PER_SECOND;
	if (w32gdi.RollingOption01IsLifePercent()) return ROLL_OPTION_LIFE_PERCENT;


	return ROLL_OPTION_UNKNOWN;
}


ROLL_OPTION get_roll_option_02(void)
{
	// 1. CriticalHit
	if (w32gdi.RollingOption02IsCriticalHitChance()) return ROLL_OPTION_CRITICAL_HIT_CHANCE;
	if (w32gdi.RollingOption02IsCriticalHitDamage()) return ROLL_OPTION_CRITICAL_HIT_DAMAGE;
	// 2. Socket
	if (w32gdi.RollingOption02IsOneSocket()) return ROLL_OPTION_ONE_SOCKET;
	// 3. Area Damage
	if (w32gdi.RollingOption02IsAreaDamage()) return ROLL_OPTION_AREA_DAMAGE;
	if (w32gdi.RollingOption02IsBaseDamage()) return ROLL_OPTION_BASE_DAMAGE;
	//4. Stats
	if (w32gdi.RollingOption02IsDexterity()) return ROLL_OPTION_DEXTERITY;
	if (w32gdi.RollingOption02IsIntelligence()) return ROLL_OPTION_INTELLIGENCE;
	if (w32gdi.RollingOption02IsVitality()) return ROLL_OPTION_VITALITY;
	// 5. Reduce Damage
	if (w32gdi.RollingOption02IsReduceMeleeDamage()) return ROLL_OPTION_REDUCE_MELEE_DAMAGE;
	
	
	// 5. Reduce
	if (w32gdi.RollingOption02IsReduceResource()) return ROLL_OPTION_REDUCE_RESOURCE;
	if (w32gdi.RollingOption02IsReduceCooldown()) return ROLL_OPTION_REDUCE_COOLDOWN;

	// 6. Attack Speed
	if (w32gdi.RollingOption02IsAttackSpeed()) return ROLL_OPTION_ATTACK_SPEED;


	// 7. life
	if (w32gdi.RollingOption02IsLifePercent()) return ROLL_OPTION_LIFE_PERCENT;
	if (w32gdi.RollingOption02IsLifePerSecond()) return ROLL_OPTION_LIFE_PER_SECOND;
	if (w32gdi.RollingOption02IsLifePerHit()) return ROLL_OPTION_LIFE_HIT;

	if (w32gdi.RollingOption02IsResistAll()) return ROLL_OPTION_RESIST_ALL;

	if (w32gdi.RollingOption02IsHungeringArrow()) return ROLL_OPTION_DHSKILL_HUNGERING_ARROW;
	if (w32gdi.RollingOption02IsBolas()) return ROLL_OPTION_DHSKILL_BOLAS;
	if (w32gdi.RollingOption02IsGrenade()) return ROLL_OPTION_DHSKILL_GRENADE;
	if (w32gdi.RollingOption02IsEntanglingShot()) return ROLL_OPTION_DHSKILL_ENTANGLING_SHOT;
	if (w32gdi.RollingOption02IsEvasiveFire()) return ROLL_OPTION_DHSKILL_EVASIVE_FIRE;
	if (w32gdi.RollingOption02IsArmor()) return ROLL_OPTION_ARMOR;

	return ROLL_OPTION_UNKNOWN;
}

ROLL_OPTION get_roll_option_03(void)
{
	// 1. CriticalHit
	if (w32gdi.RollingOption03IsCriticalHitChance()) return ROLL_OPTION_CRITICAL_HIT_CHANCE;
	if (w32gdi.RollingOption03IsCriticalHitDamage()) return ROLL_OPTION_CRITICAL_HIT_DAMAGE;
	// 2. Socket
	if (w32gdi.RollingOption03IsOneSocket()) return ROLL_OPTION_ONE_SOCKET;
	// 3. Damage
	if (w32gdi.RollingOption03IsAreaDamage()) return ROLL_OPTION_AREA_DAMAGE;
	if (w32gdi.RollingOption03IsBaseDamage()) return ROLL_OPTION_BASE_DAMAGE;
	//4. Stats
	if (w32gdi.RollingOption03IsDexterity()) return ROLL_OPTION_DEXTERITY;
	if (w32gdi.RollingOption03IsIntelligence()) return ROLL_OPTION_INTELLIGENCE;
	if (w32gdi.RollingOption03IsVitality()) return ROLL_OPTION_VITALITY;
	// 5. Reduce Damage
	if (w32gdi.RollingOption03IsReduceMeleeDamage()) return ROLL_OPTION_REDUCE_MELEE_DAMAGE;



	// 5. Reduce	
	if (w32gdi.RollingOption03IsReduceCooldown()) return ROLL_OPTION_REDUCE_COOLDOWN;
	if (w32gdi.RollingOption03IsReduceResource()) return ROLL_OPTION_REDUCE_RESOURCE;
	if (w32gdi.RollingOption03IsReduceMeleeDamage()) return ROLL_OPTION_REDUCE_MELEE_DAMAGE;



	// 6. Attack Speed
	if (w32gdi.RollingOption03IsAttackSpeed()) return ROLL_OPTION_ATTACK_SPEED;


	// 7. life
	if (w32gdi.RollingOption03IsLifePercent()) return ROLL_OPTION_LIFE_PERCENT;
	if (w32gdi.RollingOption03IsLifePerSecond()) return ROLL_OPTION_LIFE_PER_SECOND;
	if (w32gdi.RollingOption03IsLifePerHit()) return ROLL_OPTION_LIFE_HIT;


	if (w32gdi.RollingOption03IsResistAll()) return ROLL_OPTION_RESIST_ALL;



	if (w32gdi.RollingOption03IsHungeringArrow()) return ROLL_OPTION_DHSKILL_HUNGERING_ARROW;
	if (w32gdi.RollingOption03IsBolas()) return ROLL_OPTION_DHSKILL_BOLAS;
	if (w32gdi.RollingOption03IsGrenade()) return ROLL_OPTION_DHSKILL_GRENADE;
	if (w32gdi.RollingOption03IsEntanglingShot()) return ROLL_OPTION_DHSKILL_ENTANGLING_SHOT;
	if (w32gdi.RollingOption03IsEvasiveFire()) return ROLL_OPTION_DHSKILL_EVASIVE_FIRE;
	if (w32gdi.RollingOption03IsArmor()) return ROLL_OPTION_ARMOR;


	return ROLL_OPTION_UNKNOWN;
}






ROLL_PARAMETER get_roll_parameter_01(ROLL_OPTION option_01)
{
	if (option_01 == ROLL_OPTION_CRITICAL_HIT_DAMAGE)
	{
		if (w32gdi.RollingParameter01Is100PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_100_PERCENT;
		//if (w32gdi.RollingParameter01Is99PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_99_PERCENT;
		//if (w32gdi.RollingParameter01Is98PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_98_PERCENT;
		//if (w32gdi.RollingParameter01Is97PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_97_PERCENT;
		//if (w32gdi.RollingParameter01Is96PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_96_PERCENT;
		//if (w32gdi.RollingParameter01Is95PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_95_PERCENT;
		//if (w32gdi.RollingParameter01Is94PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_94_PERCENT;
		//if (w32gdi.RollingParameter01Is93PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_93_PERCENT;
		//if (w32gdi.RollingParameter01Is92PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_92_PERCENT;
		//if (w32gdi.RollingParameter01Is91PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_91_PERCENT;
		//if (w32gdi.RollingParameter01Is90PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_90_PERCENT;
		//if (w32gdi.RollingParameter01Is89PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_89_PERCENT;
		//if (w32gdi.RollingParameter01Is88PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_88_PERCENT;
		//if (w32gdi.RollingParameter01Is87PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_87_PERCENT;
		//if (w32gdi.RollingParameter01Is86PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_86_PERCENT;
		//if (w32gdi.RollingParameter01Is85PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_85_PERCENT;
		//if (w32gdi.RollingParameter01Is84PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_84_PERCENT;
		//if (w32gdi.RollingParameter01Is83PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_83_PERCENT;
		//if (w32gdi.RollingParameter01Is82PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_82_PERCENT;
		//if (w32gdi.RollingParameter01Is81PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_81_PERCENT;
		//if (w32gdi.RollingParameter01Is80PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_80_PERCENT;
		//if (w32gdi.RollingParameter01Is79PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_79_PERCENT;
		//if (w32gdi.RollingParameter01Is78PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_78_PERCENT;
		//if (w32gdi.RollingParameter01Is77PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_77_PERCENT;
		//if (w32gdi.RollingParameter01Is76PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_76_PERCENT;
		//if (w32gdi.RollingParameter01Is75PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_75_PERCENT;
		//if (w32gdi.RollingParameter01Is74PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_74_PERCENT;
		//if (w32gdi.RollingParameter01Is73PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_73_PERCENT;
		//if (w32gdi.RollingParameter01Is72PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_72_PERCENT;
		//if (w32gdi.RollingParameter01Is71PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_71_PERCENT;
		//if (w32gdi.RollingParameter01Is70PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_70_PERCENT;
		//if (w32gdi.RollingParameter01Is69PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_69_PERCENT;
		//if (w32gdi.RollingParameter01Is68PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_68_PERCENT;
		//if (w32gdi.RollingParameter01Is67PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_67_PERCENT;
		//if (w32gdi.RollingParameter01Is66PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_66_PERCENT;
		//if (w32gdi.RollingParameter01Is65PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_65_PERCENT;
		//if (w32gdi.RollingParameter01Is64PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_64_PERCENT;
		//if (w32gdi.RollingParameter01Is63PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_63_PERCENT;
		//if (w32gdi.RollingParameter01Is62PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_62_PERCENT;
		//if (w32gdi.RollingParameter01Is61PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_61_PERCENT;
		//if (w32gdi.RollingParameter01Is60PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_60_PERCENT;
		//if (w32gdi.RollingParameter01Is59PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_59_PERCENT;
		//if (w32gdi.RollingParameter01Is58PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_58_PERCENT;
		//if (w32gdi.RollingParameter01Is57PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_57_PERCENT;
		//if (w32gdi.RollingParameter01Is56PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_56_PERCENT;
		//if (w32gdi.RollingParameter01Is55PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_55_PERCENT;
		//if (w32gdi.RollingParameter01Is54PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_54_PERCENT;
		//if (w32gdi.RollingParameter01Is53PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_53_PERCENT;
		//if (w32gdi.RollingParameter01Is52PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_52_PERCENT;
		//if (w32gdi.RollingParameter01Is51PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_51_PERCENT;
		//if (w32gdi.RollingParameter01Is50PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_50_PERCENT;
		if (w32gdi.RollingParameter01Is49PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_49_PERCENT;
		if (w32gdi.RollingParameter01Is48PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_48_PERCENT;
		//if (w32gdi.RollingParameter01Is47PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_47_PERCENT;
		if (w32gdi.RollingParameter01Is46PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_46_PERCENT;
		if (w32gdi.RollingParameter01Is45PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_45_PERCENT;
		//if (w32gdi.RollingParameter01Is44PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_44_PERCENT;
		//if (w32gdi.RollingParameter01Is43PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_43_PERCENT;
		if (w32gdi.RollingParameter01Is42PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_42_PERCENT;
		if (w32gdi.RollingParameter01Is41PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_41_PERCENT;
		if (w32gdi.RollingParameter01Is40PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_40_PERCENT;
		//if (w32gdi.RollingParameter01Is39PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_39_PERCENT;
		//if (w32gdi.RollingParameter01Is38PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_38_PERCENT;
		//if (w32gdi.RollingParameter01Is37PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_37_PERCENT;
		//if (w32gdi.RollingParameter01Is36PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_36_PERCENT;
		//if (w32gdi.RollingParameter01Is35PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_35_PERCENT;
		if (w32gdi.RollingParameter01Is34PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_34_PERCENT;
		//if (w32gdi.RollingParameter01Is33PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_33_PERCENT;
		//if (w32gdi.RollingParameter01Is32PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_32_PERCENT;
		//if (w32gdi.RollingParameter01Is31PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_31_PERCENT;
		//if (w32gdi.RollingParameter01Is30PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_30_PERCENT;
		//if (w32gdi.RollingParameter01Is29PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_29_PERCENT;
		//if (w32gdi.RollingParameter01Is28PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_28_PERCENT;
		//if (w32gdi.RollingParameter01Is27PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_27_PERCENT;
		//if (w32gdi.RollingParameter01Is26PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_26_PERCENT;
	}
	else if (option_01 == ROLL_OPTION_CRITICAL_HIT_CHANCE)
	{
		// Amulet
		if (w32gdi.RollingParameter01Is10PercentBaseCriticalHitChance()) return ROLL_PARAMETER_10_PERCENT;
		//		if (w32gdi.RollingParameter01Is09d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_09_D_5_PERCENT;
		//		if (w32gdi.RollingParameter01Is09PercentBaseCriticalHitChance()) return ROLL_PARAMETER_09_PERCENT;
		//		if (w32gdi.RollingParameter01Is08d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_08_D_5_PERCENT;
		if (w32gdi.RollingParameter01Is08PercentBaseCriticalHitChance()) return ROLL_PARAMETER_08_PERCENT;
		// Ring
		if (w32gdi.RollingParameter01Is06PercentBaseCriticalHitChance()) return ROLL_PARAMETER_06_PERCENT;
		if (w32gdi.RollingParameter01Is05d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_05_D_5_PERCENT;
		if (w32gdi.RollingParameter01Is05PercentBaseCriticalHitChance()) return ROLL_PARAMETER_05_PERCENT;
		if (w32gdi.RollingParameter01Is04d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_04_D_5_PERCENT;
	}
	else if (option_01 == ROLL_OPTION_AREA_DAMAGE)
	{
		//if (w32gdi.RollingParameter01Is20PercentBaseAreaDamage()) return ROLL_PARAMETER_20_PERCENT;
		if (w32gdi.RollingParameter01Is19PercentBaseAreaDamage()) return ROLL_PARAMETER_19_PERCENT;
		//if (w32gdi.RollingParameter01Is18PercentBaseAreaDamage()) return ROLL_PARAMETER_18_PERCENT;
		//if (w32gdi.RollingParameter01Is17PercentBaseAreaDamage()) return ROLL_PARAMETER_17_PERCENT;
		if (w32gdi.RollingParameter01Is16PercentBaseAreaDamage()) return ROLL_PARAMETER_16_PERCENT;
		//if (w32gdi.RollingParameter01Is15PercentBaseAreaDamage()) return ROLL_PARAMETER_15_PERCENT;
		//if (w32gdi.RollingParameter01Is14PercentBaseAreaDamage()) return ROLL_PARAMETER_14_PERCENT;
		//if (w32gdi.RollingParameter01Is13PercentBaseAreaDamage()) return ROLL_PARAMETER_13_PERCENT;
		//if (w32gdi.RollingParameter01Is12PercentBaseAreaDamage()) return ROLL_PARAMETER_12_PERCENT;
		//if (w32gdi.RollingParameter01Is11PercentBaseAreaDamage()) return ROLL_PARAMETER_11_PERCENT;
		//if (w32gdi.RollingParameter01Is10PercentBaseAreaDamage()) return ROLL_PARAMETER_10_PERCENT;
	}
	else if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW)
	{
		if (w32gdi.RollingParameter01Is15PercentBaseHungeringArrow()) return ROLL_PARAMETER_15_PERCENT;
		if (w32gdi.RollingParameter01Is14PercentBaseHungeringArrow()) return ROLL_PARAMETER_14_PERCENT;
		if (w32gdi.RollingParameter01Is13PercentBaseHungeringArrow()) return ROLL_PARAMETER_13_PERCENT;
		if (w32gdi.RollingParameter01Is12PercentBaseHungeringArrow()) return ROLL_PARAMETER_12_PERCENT;
		if (w32gdi.RollingParameter01Is11PercentBaseHungeringArrow()) return ROLL_PARAMETER_11_PERCENT;
		if (w32gdi.RollingParameter01Is10PercentBaseHungeringArrow()) return ROLL_PARAMETER_10_PERCENT;
	}



	return ROLL_PARAMETER_UNKNOWN;
}
ROLL_PARAMETER get_roll_parameter_02(ROLL_OPTION option_02)
{
	if (option_02 == ROLL_OPTION_CRITICAL_HIT_DAMAGE)
	{
		if (w32gdi.RollingParameter02Is100PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_100_PERCENT;
		//if (w32gdi.RollingParameter02Is99PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_99_PERCENT;
		//if (w32gdi.RollingParameter02Is98PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_98_PERCENT;
		//if (w32gdi.RollingParameter02Is97PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_97_PERCENT;
		//if (w32gdi.RollingParameter02Is96PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_96_PERCENT;
		//if (w32gdi.RollingParameter02Is95PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_95_PERCENT;
		//if (w32gdi.RollingParameter02Is94PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_94_PERCENT;
		//if (w32gdi.RollingParameter02Is93PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_93_PERCENT;
		//if (w32gdi.RollingParameter02Is92PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_92_PERCENT;
		//if (w32gdi.RollingParameter02Is91PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_91_PERCENT;
		//if (w32gdi.RollingParameter02Is90PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_90_PERCENT;
		//if (w32gdi.RollingParameter02Is89PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_89_PERCENT;
		//if (w32gdi.RollingParameter02Is88PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_88_PERCENT;
		//if (w32gdi.RollingParameter02Is87PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_87_PERCENT;
		//if (w32gdi.RollingParameter02Is86PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_86_PERCENT;
		//if (w32gdi.RollingParameter02Is85PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_85_PERCENT;
		//if (w32gdi.RollingParameter02Is84PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_84_PERCENT;
		//if (w32gdi.RollingParameter02Is83PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_83_PERCENT;
		//if (w32gdi.RollingParameter02Is82PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_82_PERCENT;
		//if (w32gdi.RollingParameter02Is81PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_81_PERCENT;
		//if (w32gdi.RollingParameter02Is80PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_80_PERCENT;
		//if (w32gdi.RollingParameter02Is79PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_79_PERCENT;
		//if (w32gdi.RollingParameter02Is78PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_78_PERCENT;
		//if (w32gdi.RollingParameter02Is77PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_77_PERCENT;
		//if (w32gdi.RollingParameter02Is76PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_76_PERCENT;
		//if (w32gdi.RollingParameter02Is75PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_75_PERCENT;
		//if (w32gdi.RollingParameter02Is74PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_74_PERCENT;
		//if (w32gdi.RollingParameter02Is73PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_73_PERCENT;
		//if (w32gdi.RollingParameter02Is72PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_72_PERCENT;
		//if (w32gdi.RollingParameter02Is71PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_71_PERCENT;
		//if (w32gdi.RollingParameter02Is70PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_70_PERCENT;
		//if (w32gdi.RollingParameter02Is69PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_69_PERCENT;
		//if (w32gdi.RollingParameter02Is68PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_68_PERCENT;
		//if (w32gdi.RollingParameter02Is67PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_67_PERCENT;
		//if (w32gdi.RollingParameter02Is66PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_66_PERCENT;
		//if (w32gdi.RollingParameter02Is65PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_65_PERCENT;
		//if (w32gdi.RollingParameter02Is64PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_64_PERCENT;
		//if (w32gdi.RollingParameter02Is63PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_63_PERCENT;
		//if (w32gdi.RollingParameter02Is62PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_62_PERCENT;
		//if (w32gdi.RollingParameter02Is61PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_61_PERCENT;
		//if (w32gdi.RollingParameter02Is60PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_60_PERCENT;
		//if (w32gdi.RollingParameter02Is59PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_59_PERCENT;
		//if (w32gdi.RollingParameter02Is58PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_58_PERCENT;
		//if (w32gdi.RollingParameter02Is57PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_57_PERCENT;
		//if (w32gdi.RollingParameter02Is56PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_56_PERCENT;
		//if (w32gdi.RollingParameter02Is55PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_55_PERCENT;
		//if (w32gdi.RollingParameter02Is54PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_54_PERCENT;
		//if (w32gdi.RollingParameter02Is53PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_53_PERCENT;
		//if (w32gdi.RollingParameter02Is52PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_52_PERCENT;
		//if (w32gdi.RollingParameter02Is51PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_51_PERCENT;
		//if (w32gdi.RollingParameter02Is50PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_50_PERCENT;
		if (w32gdi.RollingParameter02Is49PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_49_PERCENT;
		if (w32gdi.RollingParameter02Is48PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_48_PERCENT;
		//if (w32gdi.RollingParameter02Is47PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_47_PERCENT;
		if (w32gdi.RollingParameter02Is46PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_46_PERCENT;
		//if (w32gdi.RollingParameter02Is45PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_45_PERCENT;
		//if (w32gdi.RollingParameter02Is44PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_44_PERCENT;
		//if (w32gdi.RollingParameter02Is43PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_43_PERCENT;
		if (w32gdi.RollingParameter02Is42PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_42_PERCENT;
		//if (w32gdi.RollingParameter02Is41PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_41_PERCENT;
		//if (w32gdi.RollingParameter02Is40PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_40_PERCENT;
		if (w32gdi.RollingParameter02Is39PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_39_PERCENT;
		if (w32gdi.RollingParameter02Is38PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_38_PERCENT;
		//if (w32gdi.RollingParameter02Is37PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_37_PERCENT;
		//if (w32gdi.RollingParameter02Is36PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_36_PERCENT;
		if (w32gdi.RollingParameter02Is35PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_35_PERCENT;
		if (w32gdi.RollingParameter02Is34PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_34_PERCENT;
		if (w32gdi.RollingParameter02Is33PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_33_PERCENT;
		if (w32gdi.RollingParameter02Is32PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_32_PERCENT;
		if (w32gdi.RollingParameter02Is31PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_31_PERCENT;
		//if (w32gdi.RollingParameter02Is30PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_30_PERCENT;
		if (w32gdi.RollingParameter02Is29PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_29_PERCENT;
		//if (w32gdi.RollingParameter02Is28PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_28_PERCENT;
		//if (w32gdi.RollingParameter02Is27PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_27_PERCENT;
		if (w32gdi.RollingParameter02Is26PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_26_PERCENT;
	}
	else if (option_02 == ROLL_OPTION_CRITICAL_HIT_CHANCE)
	{
		// Amulet
		if (w32gdi.RollingParameter02Is10PercentBaseCriticalHitChance()) return ROLL_PARAMETER_10_PERCENT;
		//if (w32gdi.RollingParameter02Is09d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_09_D_5_PERCENT;
		//if (w32gdi.RollingParameter02Is09PercentBaseCriticalHitChance()) return ROLL_PARAMETER_09_PERCENT;
		//if (w32gdi.RollingParameter02Is08d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_08_D_5_PERCENT;
		//if (w32gdi.RollingParameter02Is08PercentBaseCriticalHitChance()) return ROLL_PARAMETER_08_PERCENT;
		// Ring
		if (w32gdi.RollingParameter02Is06PercentBaseCriticalHitChance()) return ROLL_PARAMETER_06_PERCENT;
		if (w32gdi.RollingParameter02Is05d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_05_D_5_PERCENT;
		if (w32gdi.RollingParameter02Is05PercentBaseCriticalHitChance()) return ROLL_PARAMETER_05_PERCENT;
		if (w32gdi.RollingParameter02Is04d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_04_D_5_PERCENT;
	}
	else if (option_02 == ROLL_OPTION_AREA_DAMAGE)
	{
		if (w32gdi.RollingParameter02Is20PercentBaseAreaDamage()) return ROLL_PARAMETER_20_PERCENT;
		if (w32gdi.RollingParameter02Is19PercentBaseAreaDamage()) return ROLL_PARAMETER_19_PERCENT;
		//if (w32gdi.RollingParameter02Is18PercentBaseAreaDamage()) return ROLL_PARAMETER_18_PERCENT;
		//if (w32gdi.RollingParameter02Is17PercentBaseAreaDamage()) return ROLL_PARAMETER_17_PERCENT;
		//if (w32gdi.RollingParameter02Is16PercentBaseAreaDamage()) return ROLL_PARAMETER_16_PERCENT;
		//if (w32gdi.RollingParameter02Is15PercentBaseAreaDamage()) return ROLL_PARAMETER_15_PERCENT;
		//if (w32gdi.RollingParameter02Is14PercentBaseAreaDamage()) return ROLL_PARAMETER_14_PERCENT;
		//if (w32gdi.RollingParameter02Is13PercentBaseAreaDamage()) return ROLL_PARAMETER_13_PERCENT;
		//if (w32gdi.RollingParameter02Is12PercentBaseAreaDamage()) return ROLL_PARAMETER_12_PERCENT;
		if (w32gdi.RollingParameter02Is11PercentBaseAreaDamage()) return ROLL_PARAMETER_11_PERCENT;
		//if (w32gdi.RollingParameter02Is10PercentBaseAreaDamage()) return ROLL_PARAMETER_10_PERCENT;
	}
	else if (option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW)
	{
		if (w32gdi.RollingParameter02Is15PercentBaseHungeringArrow()) return ROLL_PARAMETER_15_PERCENT;
		if (w32gdi.RollingParameter02Is14PercentBaseHungeringArrow()) return ROLL_PARAMETER_14_PERCENT;
		if (w32gdi.RollingParameter02Is13PercentBaseHungeringArrow()) return ROLL_PARAMETER_13_PERCENT;
		if (w32gdi.RollingParameter02Is12PercentBaseHungeringArrow()) return ROLL_PARAMETER_12_PERCENT;
		if (w32gdi.RollingParameter02Is11PercentBaseHungeringArrow()) return ROLL_PARAMETER_11_PERCENT;
		if (w32gdi.RollingParameter02Is10PercentBaseHungeringArrow()) return ROLL_PARAMETER_10_PERCENT;
	}

	return ROLL_PARAMETER_UNKNOWN;
}
ROLL_PARAMETER get_roll_parameter_03(ROLL_OPTION option_03)
{
	if (option_03 == ROLL_OPTION_CRITICAL_HIT_DAMAGE)
	{
		if (w32gdi.RollingParameter03Is100PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_100_PERCENT;
		//if (w32gdi.RollingParameter03Is99PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_99_PERCENT;
		//if (w32gdi.RollingParameter03Is98PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_98_PERCENT;
		//if (w32gdi.RollingParameter03Is97PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_97_PERCENT;
		//if (w32gdi.RollingParameter03Is96PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_96_PERCENT;
		//if (w32gdi.RollingParameter03Is95PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_95_PERCENT;
		//if (w32gdi.RollingParameter03Is94PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_94_PERCENT;
		//if (w32gdi.RollingParameter03Is93PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_93_PERCENT;
		//if (w32gdi.RollingParameter03Is92PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_92_PERCENT;
		//if (w32gdi.RollingParameter03Is91PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_91_PERCENT;
		//if (w32gdi.RollingParameter03Is90PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_90_PERCENT;
		//if (w32gdi.RollingParameter03Is89PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_89_PERCENT;
		//if (w32gdi.RollingParameter03Is88PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_88_PERCENT;
		//if (w32gdi.RollingParameter03Is87PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_87_PERCENT;
		//if (w32gdi.RollingParameter03Is86PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_86_PERCENT;
		//if (w32gdi.RollingParameter03Is85PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_85_PERCENT;
		//if (w32gdi.RollingParameter03Is84PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_84_PERCENT;
		//if (w32gdi.RollingParameter03Is83PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_83_PERCENT;
		//if (w32gdi.RollingParameter03Is82PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_82_PERCENT;
		//if (w32gdi.RollingParameter03Is81PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_81_PERCENT;
		//if (w32gdi.RollingParameter03Is80PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_80_PERCENT;
		//if (w32gdi.RollingParameter03Is79PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_79_PERCENT;
		//if (w32gdi.RollingParameter03Is78PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_78_PERCENT;
		//if (w32gdi.RollingParameter03Is77PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_77_PERCENT;
		//if (w32gdi.RollingParameter03Is76PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_76_PERCENT;
		//if (w32gdi.RollingParameter03Is75PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_75_PERCENT;
		//if (w32gdi.RollingParameter03Is74PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_74_PERCENT;
		//if (w32gdi.RollingParameter03Is73PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_73_PERCENT;
		//if (w32gdi.RollingParameter03Is72PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_72_PERCENT;
		//if (w32gdi.RollingParameter03Is71PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_71_PERCENT;
		//if (w32gdi.RollingParameter03Is70PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_70_PERCENT;
		//if (w32gdi.RollingParameter03Is69PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_69_PERCENT;
		//if (w32gdi.RollingParameter03Is68PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_68_PERCENT;
		//if (w32gdi.RollingParameter03Is67PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_67_PERCENT;
		//if (w32gdi.RollingParameter03Is66PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_66_PERCENT;
		//if (w32gdi.RollingParameter03Is65PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_65_PERCENT;
		//if (w32gdi.RollingParameter03Is64PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_64_PERCENT;
		//if (w32gdi.RollingParameter03Is63PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_63_PERCENT;
		//if (w32gdi.RollingParameter03Is62PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_62_PERCENT;
		//if (w32gdi.RollingParameter03Is61PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_61_PERCENT;
		//if (w32gdi.RollingParameter03Is60PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_60_PERCENT;
		//if (w32gdi.RollingParameter03Is59PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_59_PERCENT;
		//if (w32gdi.RollingParameter03Is58PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_58_PERCENT;
		//if (w32gdi.RollingParameter03Is57PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_57_PERCENT;
		//if (w32gdi.RollingParameter03Is56PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_56_PERCENT;
		//if (w32gdi.RollingParameter03Is55PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_55_PERCENT;
		//if (w32gdi.RollingParameter03Is54PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_54_PERCENT;
		//if (w32gdi.RollingParameter03Is53PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_53_PERCENT;
		//if (w32gdi.RollingParameter03Is52PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_52_PERCENT;
		//if (w32gdi.RollingParameter03Is51PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_51_PERCENT;
		//if (w32gdi.RollingParameter03Is50PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_50_PERCENT;
		if (w32gdi.RollingParameter03Is49PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_49_PERCENT;
		if (w32gdi.RollingParameter03Is48PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_48_PERCENT;
		//if (w32gdi.RollingParameter03Is47PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_47_PERCENT;
		if (w32gdi.RollingParameter03Is46PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_46_PERCENT;
		//if (w32gdi.RollingParameter03Is45PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_45_PERCENT;
		//if (w32gdi.RollingParameter03Is44PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_44_PERCENT;
		//if (w32gdi.RollingParameter03Is43PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_43_PERCENT;
		if (w32gdi.RollingParameter03Is42PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_42_PERCENT;
		//if (w32gdi.RollingParameter03Is41PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_41_PERCENT;
		//if (w32gdi.RollingParameter03Is40PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_40_PERCENT;
		if (w32gdi.RollingParameter03Is39PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_39_PERCENT;
		if (w32gdi.RollingParameter03Is38PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_38_PERCENT;
		//if (w32gdi.RollingParameter03Is37PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_37_PERCENT;
		//if (w32gdi.RollingParameter03Is36PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_36_PERCENT;
		if (w32gdi.RollingParameter03Is35PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_35_PERCENT;
		if (w32gdi.RollingParameter03Is34PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_34_PERCENT;
		if (w32gdi.RollingParameter03Is33PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_33_PERCENT;
		if (w32gdi.RollingParameter03Is32PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_32_PERCENT;
		if (w32gdi.RollingParameter03Is31PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_31_PERCENT;
		//if (w32gdi.RollingParameter03Is30PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_30_PERCENT;
		if (w32gdi.RollingParameter03Is29PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_29_PERCENT;
		//if (w32gdi.RollingParameter03Is28PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_28_PERCENT;
		//if (w32gdi.RollingParameter03Is27PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_27_PERCENT;
		if (w32gdi.RollingParameter03Is26PercentBaseCriticalHitDamage()) return ROLL_PARAMETER_26_PERCENT;
	}
	else if (option_03 == ROLL_OPTION_CRITICAL_HIT_CHANCE)
	{
		// Amulet
		if (w32gdi.RollingParameter03Is10PercentBaseCriticalHitChance()) return ROLL_PARAMETER_10_PERCENT;
		//if (w32gdi.RollingParameter03Is09d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_09_D_5_PERCENT;
		//if (w32gdi.RollingParameter03Is09PercentBaseCriticalHitChance()) return ROLL_PARAMETER_09_PERCENT;
		//if (w32gdi.RollingParameter03Is08d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_08_D_5_PERCENT;
		//if (w32gdi.RollingParameter03Is08PercentBaseCriticalHitChance()) return ROLL_PARAMETER_08_PERCENT;
		// Ring
		if (w32gdi.RollingParameter03Is06PercentBaseCriticalHitChance()) return ROLL_PARAMETER_06_PERCENT;
		if (w32gdi.RollingParameter03Is05d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_05_D_5_PERCENT;
		if (w32gdi.RollingParameter03Is05PercentBaseCriticalHitChance()) return ROLL_PARAMETER_05_PERCENT;
		if (w32gdi.RollingParameter03Is04d5PercentBaseCriticalHitChance()) return ROLL_PARAMETER_04_D_5_PERCENT;
	}
	else if (option_03 == ROLL_OPTION_AREA_DAMAGE)
	{
		if (w32gdi.RollingParameter03Is20PercentBaseAreaDamage()) return ROLL_PARAMETER_20_PERCENT;
		if (w32gdi.RollingParameter03Is19PercentBaseAreaDamage()) return ROLL_PARAMETER_19_PERCENT;
		//if (w32gdi.RollingParameter03Is18PercentBaseAreaDamage()) return ROLL_PARAMETER_18_PERCENT;
		//if (w32gdi.RollingParameter03Is17PercentBaseAreaDamage()) return ROLL_PARAMETER_17_PERCENT;
		//if (w32gdi.RollingParameter03Is16PercentBaseAreaDamage()) return ROLL_PARAMETER_16_PERCENT;
		//if (w32gdi.RollingParameter03Is15PercentBaseAreaDamage()) return ROLL_PARAMETER_15_PERCENT;
		//if (w32gdi.RollingParameter03Is14PercentBaseAreaDamage()) return ROLL_PARAMETER_14_PERCENT;
		//if (w32gdi.RollingParameter03Is13PercentBaseAreaDamage()) return ROLL_PARAMETER_13_PERCENT;
		//if (w32gdi.RollingParameter03Is12PercentBaseAreaDamage()) return ROLL_PARAMETER_12_PERCENT;
		if (w32gdi.RollingParameter03Is11PercentBaseAreaDamage()) return ROLL_PARAMETER_11_PERCENT;
		//if (w32gdi.RollingParameter03Is10PercentBaseAreaDamage()) return ROLL_PARAMETER_10_PERCENT;
	}
	else if (option_03 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW)
	{
		if (w32gdi.RollingParameter03Is15PercentBaseHungeringArrow()) return ROLL_PARAMETER_15_PERCENT;
		if (w32gdi.RollingParameter03Is14PercentBaseHungeringArrow()) return ROLL_PARAMETER_14_PERCENT;
		if (w32gdi.RollingParameter03Is13PercentBaseHungeringArrow()) return ROLL_PARAMETER_13_PERCENT;
		if (w32gdi.RollingParameter03Is12PercentBaseHungeringArrow()) return ROLL_PARAMETER_12_PERCENT;
		if (w32gdi.RollingParameter03Is11PercentBaseHungeringArrow()) return ROLL_PARAMETER_11_PERCENT;
		if (w32gdi.RollingParameter03Is10PercentBaseHungeringArrow()) return ROLL_PARAMETER_10_PERCENT;
	}

	return ROLL_PARAMETER_UNKNOWN;
}

ROLL_ITEM get_roll_item(void)
{
	if (w32gdi.RollingItemIsHuntersWrath()) return ROLL_ITEM_HUNTERS_WRATH;
	if (w32gdi.RollingItemIsColdCathodeTrousers()) return ROLL_ITEM_COLD_CATHODE_TROUSERS;
	return ROLL_ITEM_UNKNOWN;
}


RESOURCE_STATUS get_resource_status(void)
{
	if (w32gdi.IsFullResourceForClothes()) return RESOURCE_STATUS_FULL_FOR_CLOTHES;
	if (w32gdi.IsEnoughResourceForJewelry()) return RESOURCE_STATUS_ENOUGH_FOR_JEWELRY;
	return RESOURCE_STATUS_UNKNOWN;
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
	case RESOURCE_STATUS_ENOUGH_FOR_JEWELRY:
		return L"Enough for jewelry";
		break;
	default:
		return L"-";
		break;
	}
	return L"-";
}



GOLD_STATUS get_gold_status(void)
{
	if (w32gdi.IsEnoughGold5Digit()) return GOLD_STATUS_FULL_FOR_ROLLING;
	if (w32gdi.IsEnoughGold6Digit()) return GOLD_STATUS_FULL_FOR_ROLLING;
	if (w32gdi.IsEnoughGold7Digit()) return GOLD_STATUS_FULL_FOR_ROLLING;
	//if (w32gdi.IsEnoughGold8Digit()) return GOLD_STATUS_FULL_FOR_ROLLING;

	return GOLD_STATUS_UNKNOWN;
}

wchar_t* get_gold_info(GOLD_STATUS x)
{
	switch (x)
	{
	case GOLD_STATUS_UNKNOWN:
		return L"-";
		break;
	case GOLD_STATUS_FULL_FOR_ROLLING:
		return L"Full for rolling";
		break;
	default:
		return L"-";
		break;
	}
	return L"-";
}





/************************************************************************/
/* Action                                                               */
/************************************************************************/
bool is_require_hungering_arrow(ROLL_ITEM x, bool force_to_dps_build)
{
	return (x == ROLL_ITEM_HUNTERS_WRATH
		|| (force_to_dps_build && x == ROLL_ITEM_COLD_CATHODE_TROUSERS));
}

bool is_option_less_dps_priority_than_area_damage(ROLL_OPTION x)
{
	return (x == ROLL_OPTION_STRENGTH
		|| x == ROLL_OPTION_DEXTERITY
		|| x == ROLL_OPTION_INTELLIGENCE
		|| x == ROLL_OPTION_VITALITY
		|| x == ROLL_OPTION_LIFE_PERCENT
		|| x == ROLL_OPTION_LIFE_PER_SECOND
		|| x == ROLL_OPTION_LIFE_HIT
		|| x == ROLL_OPTION_LIFE_KILL
		|| x == ROLL_OPTION_ARMOR);
}
bool is_critical_hit_or_socket_option(ROLL_OPTION x)
{
	return (x == ROLL_OPTION_CRITICAL_HIT_CHANCE
		|| x == ROLL_OPTION_CRITICAL_HIT_DAMAGE
		|| x == ROLL_OPTION_ONE_SOCKET);
}
bool is_not_critical_hit_or_socket_option(ROLL_OPTION x)
{
	return (x != ROLL_OPTION_UNKNOWN
		&& x != ROLL_OPTION_CRITICAL_HIT_CHANCE
		&& x != ROLL_OPTION_CRITICAL_HIT_DAMAGE
		&& x != ROLL_OPTION_ONE_SOCKET);
}
bool is_life_option(ROLL_OPTION x)
{
	return (x == ROLL_OPTION_LIFE_PERCENT
		|| x == ROLL_OPTION_LIFE_PER_SECOND
		|| x == ROLL_OPTION_LIFE_HIT);
}
bool is_dh_skill(ROLL_OPTION x)
{
	return (x == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
		|| x == ROLL_OPTION_DHSKILL_BOLAS
		|| x == ROLL_OPTION_DHSKILL_GRENADE
		|| x == ROLL_OPTION_DHSKILL_ENTANGLING_SHOT
		|| x == ROLL_OPTION_DHSKILL_EVASIVE_FIRE);
}


bool is_critical_hit_chance_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_04_D_5_PERCENT
		|| x == ROLL_PARAMETER_05_PERCENT
		|| x == ROLL_PARAMETER_05_D_5_PERCENT
		|| x == ROLL_PARAMETER_06_PERCENT
		|| x == ROLL_PARAMETER_08_PERCENT
		|| x == ROLL_PARAMETER_08_D_5_PERCENT
		|| x == ROLL_PARAMETER_09_PERCENT
		|| x == ROLL_PARAMETER_09_D_5_PERCENT
		|| x == ROLL_PARAMETER_10_PERCENT);
}
bool is_critical_hit_damage_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_26_PERCENT
		|| x == ROLL_PARAMETER_27_PERCENT
		|| x == ROLL_PARAMETER_28_PERCENT
		|| x == ROLL_PARAMETER_29_PERCENT
		|| x == ROLL_PARAMETER_30_PERCENT
		|| x == ROLL_PARAMETER_31_PERCENT
		|| x == ROLL_PARAMETER_32_PERCENT
		|| x == ROLL_PARAMETER_33_PERCENT
		|| x == ROLL_PARAMETER_34_PERCENT
		|| x == ROLL_PARAMETER_35_PERCENT
		|| x == ROLL_PARAMETER_36_PERCENT
		|| x == ROLL_PARAMETER_37_PERCENT
		|| x == ROLL_PARAMETER_38_PERCENT
		|| x == ROLL_PARAMETER_39_PERCENT
		|| x == ROLL_PARAMETER_40_PERCENT
		|| x == ROLL_PARAMETER_41_PERCENT
		|| x == ROLL_PARAMETER_42_PERCENT
		|| x == ROLL_PARAMETER_43_PERCENT
		|| x == ROLL_PARAMETER_44_PERCENT
		|| x == ROLL_PARAMETER_45_PERCENT
		|| x == ROLL_PARAMETER_46_PERCENT
		|| x == ROLL_PARAMETER_47_PERCENT
		|| x == ROLL_PARAMETER_48_PERCENT
		|| x == ROLL_PARAMETER_49_PERCENT
		|| x == ROLL_PARAMETER_50_PERCENT
		|| x == ROLL_PARAMETER_51_PERCENT
		|| x == ROLL_PARAMETER_52_PERCENT
		|| x == ROLL_PARAMETER_53_PERCENT
		|| x == ROLL_PARAMETER_54_PERCENT
		|| x == ROLL_PARAMETER_55_PERCENT
		|| x == ROLL_PARAMETER_56_PERCENT
		|| x == ROLL_PARAMETER_57_PERCENT
		|| x == ROLL_PARAMETER_58_PERCENT
		|| x == ROLL_PARAMETER_59_PERCENT
		|| x == ROLL_PARAMETER_60_PERCENT
		|| x == ROLL_PARAMETER_61_PERCENT
		|| x == ROLL_PARAMETER_62_PERCENT
		|| x == ROLL_PARAMETER_63_PERCENT
		|| x == ROLL_PARAMETER_64_PERCENT
		|| x == ROLL_PARAMETER_65_PERCENT
		|| x == ROLL_PARAMETER_66_PERCENT
		|| x == ROLL_PARAMETER_67_PERCENT
		|| x == ROLL_PARAMETER_68_PERCENT
		|| x == ROLL_PARAMETER_69_PERCENT
		|| x == ROLL_PARAMETER_70_PERCENT
		|| x == ROLL_PARAMETER_71_PERCENT
		|| x == ROLL_PARAMETER_72_PERCENT
		|| x == ROLL_PARAMETER_73_PERCENT
		|| x == ROLL_PARAMETER_74_PERCENT
		|| x == ROLL_PARAMETER_75_PERCENT
		|| x == ROLL_PARAMETER_76_PERCENT
		|| x == ROLL_PARAMETER_77_PERCENT
		|| x == ROLL_PARAMETER_78_PERCENT
		|| x == ROLL_PARAMETER_79_PERCENT
		|| x == ROLL_PARAMETER_80_PERCENT
		|| x == ROLL_PARAMETER_81_PERCENT
		|| x == ROLL_PARAMETER_82_PERCENT
		|| x == ROLL_PARAMETER_83_PERCENT
		|| x == ROLL_PARAMETER_84_PERCENT
		|| x == ROLL_PARAMETER_85_PERCENT
		|| x == ROLL_PARAMETER_86_PERCENT
		|| x == ROLL_PARAMETER_87_PERCENT
		|| x == ROLL_PARAMETER_88_PERCENT
		|| x == ROLL_PARAMETER_89_PERCENT
		|| x == ROLL_PARAMETER_90_PERCENT
		|| x == ROLL_PARAMETER_91_PERCENT
		|| x == ROLL_PARAMETER_92_PERCENT
		|| x == ROLL_PARAMETER_93_PERCENT
		|| x == ROLL_PARAMETER_94_PERCENT
		|| x == ROLL_PARAMETER_95_PERCENT
		|| x == ROLL_PARAMETER_96_PERCENT
		|| x == ROLL_PARAMETER_97_PERCENT
		|| x == ROLL_PARAMETER_98_PERCENT
		|| x == ROLL_PARAMETER_99_PERCENT
		|| x == ROLL_PARAMETER_100_PERCENT);
}
bool is_area_damage_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_10_PERCENT
		|| x == ROLL_PARAMETER_11_PERCENT
		|| x == ROLL_PARAMETER_12_PERCENT
		|| x == ROLL_PARAMETER_13_PERCENT
		|| x == ROLL_PARAMETER_14_PERCENT
		|| x == ROLL_PARAMETER_15_PERCENT
		|| x == ROLL_PARAMETER_16_PERCENT
		|| x == ROLL_PARAMETER_17_PERCENT
		|| x == ROLL_PARAMETER_18_PERCENT
		|| x == ROLL_PARAMETER_19_PERCENT
		|| x == ROLL_PARAMETER_20_PERCENT
		);
}

bool is_04_to_06_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_04_PERCENT
		|| x == ROLL_PARAMETER_04_D_5_PERCENT
		|| x == ROLL_PARAMETER_05_PERCENT
		|| x == ROLL_PARAMETER_05_D_5_PERCENT
		|| x == ROLL_PARAMETER_06_PERCENT);
}
bool is_08_to_10_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_08_PERCENT
		|| x == ROLL_PARAMETER_08_D_5_PERCENT
		|| x == ROLL_PARAMETER_09_PERCENT
		|| x == ROLL_PARAMETER_09_D_5_PERCENT
		|| x == ROLL_PARAMETER_10_PERCENT);
}
bool is_10_to_14_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_10_PERCENT
		|| x == ROLL_PARAMETER_11_PERCENT
		|| x == ROLL_PARAMETER_12_PERCENT
		|| x == ROLL_PARAMETER_13_PERCENT
		|| x == ROLL_PARAMETER_14_PERCENT);
}
bool is_10_to_15_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_10_PERCENT
		|| x == ROLL_PARAMETER_11_PERCENT
		|| x == ROLL_PARAMETER_12_PERCENT
		|| x == ROLL_PARAMETER_13_PERCENT
		|| x == ROLL_PARAMETER_14_PERCENT
		|| x == ROLL_PARAMETER_15_PERCENT);
}
bool is_10_to_20_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_10_PERCENT
		|| x == ROLL_PARAMETER_11_PERCENT
		|| x == ROLL_PARAMETER_12_PERCENT
		|| x == ROLL_PARAMETER_13_PERCENT
		|| x == ROLL_PARAMETER_14_PERCENT
		|| x == ROLL_PARAMETER_15_PERCENT
		|| x == ROLL_PARAMETER_16_PERCENT
		|| x == ROLL_PARAMETER_17_PERCENT
		|| x == ROLL_PARAMETER_18_PERCENT
		|| x == ROLL_PARAMETER_19_PERCENT
		|| x == ROLL_PARAMETER_20_PERCENT
		);
}
bool is_26_to_50_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_26_PERCENT
		|| x == ROLL_PARAMETER_27_PERCENT
		|| x == ROLL_PARAMETER_28_PERCENT
		|| x == ROLL_PARAMETER_29_PERCENT
		|| x == ROLL_PARAMETER_30_PERCENT
		|| x == ROLL_PARAMETER_31_PERCENT
		|| x == ROLL_PARAMETER_32_PERCENT
		|| x == ROLL_PARAMETER_33_PERCENT
		|| x == ROLL_PARAMETER_34_PERCENT
		|| x == ROLL_PARAMETER_35_PERCENT
		|| x == ROLL_PARAMETER_36_PERCENT
		|| x == ROLL_PARAMETER_37_PERCENT
		|| x == ROLL_PARAMETER_38_PERCENT
		|| x == ROLL_PARAMETER_39_PERCENT
		|| x == ROLL_PARAMETER_40_PERCENT
		|| x == ROLL_PARAMETER_41_PERCENT
		|| x == ROLL_PARAMETER_42_PERCENT
		|| x == ROLL_PARAMETER_43_PERCENT
		|| x == ROLL_PARAMETER_44_PERCENT
		|| x == ROLL_PARAMETER_45_PERCENT
		|| x == ROLL_PARAMETER_46_PERCENT
		|| x == ROLL_PARAMETER_47_PERCENT
		|| x == ROLL_PARAMETER_48_PERCENT
		|| x == ROLL_PARAMETER_49_PERCENT
		|| x == ROLL_PARAMETER_50_PERCENT
		);
}
bool is_51_to_100_percent(ROLL_PARAMETER x)
{
	return (x == ROLL_PARAMETER_51_PERCENT
		|| x == ROLL_PARAMETER_52_PERCENT
		|| x == ROLL_PARAMETER_53_PERCENT
		|| x == ROLL_PARAMETER_54_PERCENT
		|| x == ROLL_PARAMETER_55_PERCENT
		|| x == ROLL_PARAMETER_56_PERCENT
		|| x == ROLL_PARAMETER_57_PERCENT
		|| x == ROLL_PARAMETER_58_PERCENT
		|| x == ROLL_PARAMETER_59_PERCENT
		|| x == ROLL_PARAMETER_60_PERCENT
		|| x == ROLL_PARAMETER_61_PERCENT
		|| x == ROLL_PARAMETER_62_PERCENT
		|| x == ROLL_PARAMETER_63_PERCENT
		|| x == ROLL_PARAMETER_64_PERCENT
		|| x == ROLL_PARAMETER_65_PERCENT
		|| x == ROLL_PARAMETER_66_PERCENT
		|| x == ROLL_PARAMETER_67_PERCENT
		|| x == ROLL_PARAMETER_68_PERCENT
		|| x == ROLL_PARAMETER_69_PERCENT
		|| x == ROLL_PARAMETER_70_PERCENT
		|| x == ROLL_PARAMETER_71_PERCENT
		|| x == ROLL_PARAMETER_72_PERCENT
		|| x == ROLL_PARAMETER_73_PERCENT
		|| x == ROLL_PARAMETER_74_PERCENT
		|| x == ROLL_PARAMETER_75_PERCENT
		|| x == ROLL_PARAMETER_76_PERCENT
		|| x == ROLL_PARAMETER_77_PERCENT
		|| x == ROLL_PARAMETER_78_PERCENT
		|| x == ROLL_PARAMETER_79_PERCENT
		|| x == ROLL_PARAMETER_80_PERCENT
		|| x == ROLL_PARAMETER_81_PERCENT
		|| x == ROLL_PARAMETER_82_PERCENT
		|| x == ROLL_PARAMETER_83_PERCENT
		|| x == ROLL_PARAMETER_84_PERCENT
		|| x == ROLL_PARAMETER_85_PERCENT
		|| x == ROLL_PARAMETER_86_PERCENT
		|| x == ROLL_PARAMETER_87_PERCENT
		|| x == ROLL_PARAMETER_88_PERCENT
		|| x == ROLL_PARAMETER_89_PERCENT
		|| x == ROLL_PARAMETER_90_PERCENT
		|| x == ROLL_PARAMETER_91_PERCENT
		|| x == ROLL_PARAMETER_92_PERCENT
		|| x == ROLL_PARAMETER_93_PERCENT
		|| x == ROLL_PARAMETER_94_PERCENT
		|| x == ROLL_PARAMETER_95_PERCENT
		|| x == ROLL_PARAMETER_96_PERCENT
		|| x == ROLL_PARAMETER_97_PERCENT
		|| x == ROLL_PARAMETER_98_PERCENT
		|| x == ROLL_PARAMETER_99_PERCENT
		|| x == ROLL_PARAMETER_100_PERCENT);
}


void start_roll(void)
{
	// Chọn nút select
	w32gdi.CaptureDesktop();
	SetD3Mouse(350, 780);
	Sleep(50 + (rand() % 5));
	SendD3LeftMouseClick();
	Sleep(50 + (rand() % 5));
}
void select_option_01(void)
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
		SetD3Mouse(350, 780);
		Sleep(50 + (rand() % 5));
		SendD3LeftMouseClick();
		Sleep(50 + (rand() % 5));
	}
}
void select_option_02(void)
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
}
void select_option_03(void)
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
}
void wait_after_roll(void)
{
	Sleep(500 + (rand() % 5));
}
void stop_roll(void)
{
	// Move chuột ra chỗ khác
	SetD3Mouse(256, 730);
	Sleep(50 + (rand() % 5));
}

void do_roll(ROLL_ITEM item,
	ROLL_OPTION option_01, ROLL_PARAMETER parameter_01,
	ROLL_OPTION option_02, ROLL_PARAMETER parameter_02,
	ROLL_OPTION option_03, ROLL_PARAMETER parameter_03,
	RESOURCE_STATUS resource_status,
	GOLD_STATUS gold_status,
	bool force_to_dps_build)
{




	if (option_01 + option_02 + option_03 + parameter_01 + parameter_02 + parameter_03 > 0 && w32gdi.D3IsRollWaiting() == false)
	{
		ROLL_DESCISION final_decision = DESCISION_NOTHING;

		// #1: Basic - 3 same option
		if (final_decision == DESCISION_NOTHING
			&& option_01 == ROLL_OPTION_CRITICAL_HIT_CHANCE
			&& option_02 == ROLL_OPTION_CRITICAL_HIT_CHANCE
			&& option_03 == ROLL_OPTION_CRITICAL_HIT_CHANCE
			&& is_critical_hit_chance_percent(parameter_01)
			&& is_critical_hit_chance_percent(parameter_02)
			&& is_critical_hit_chance_percent(parameter_03)
			)
		{
			if (parameter_01 >= parameter_02 && parameter_01 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			else if (parameter_02 >= parameter_01 && parameter_02 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
			else if (parameter_03 >= parameter_01 && parameter_03 >= parameter_02) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
		}
		else if (final_decision == DESCISION_NOTHING
			&& option_01 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
			&& option_02 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
			&& option_03 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
			&& is_critical_hit_damage_percent(parameter_01)
			&& is_critical_hit_damage_percent(parameter_02)
			&& is_critical_hit_damage_percent(parameter_03)
			)
		{
			if (parameter_01 >= parameter_02 && parameter_01 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			else if (parameter_02 >= parameter_01 && parameter_02 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
			else if (parameter_03 >= parameter_01 && parameter_03 >= parameter_02) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
		}
		else if (final_decision == DESCISION_NOTHING
			&& option_01 == ROLL_OPTION_AREA_DAMAGE
			&& option_02 == ROLL_OPTION_AREA_DAMAGE
			&& option_03 == ROLL_OPTION_AREA_DAMAGE
			&& is_area_damage_percent(parameter_01)
			&& is_area_damage_percent(parameter_02)
			&& is_area_damage_percent(parameter_03)
			)
		{
			if (parameter_01 >= parameter_02 && parameter_01 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			else if (parameter_02 >= parameter_01 && parameter_02 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
			else if (parameter_03 >= parameter_01 && parameter_03 >= parameter_02) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
		}



		// #1: force_to_dps_build - Critical hit
		if (force_to_dps_build && final_decision == DESCISION_NOTHING)
		{
			if (option_01 == ROLL_OPTION_CRITICAL_HIT_CHANCE
				&& is_critical_hit_chance_percent(parameter_01)
				&& is_not_critical_hit_or_socket_option(option_02)
				&& is_not_critical_hit_or_socket_option(option_03)
				)
			{
				final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}
			else if (option_01 == ROLL_OPTION_CRITICAL_HIT_CHANCE
				&& is_critical_hit_chance_percent(parameter_01)
				&& option_02 == ROLL_OPTION_CRITICAL_HIT_CHANCE
				&& is_critical_hit_chance_percent(parameter_02)
				&& is_not_critical_hit_or_socket_option(option_03)
				)
			{
				if (parameter_02 > parameter_01) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}
			else if (option_01 == ROLL_OPTION_CRITICAL_HIT_CHANCE
				&& is_critical_hit_chance_percent(parameter_01)
				&& is_not_critical_hit_or_socket_option(option_02)
				&& option_03 == ROLL_OPTION_CRITICAL_HIT_CHANCE
				&& is_critical_hit_chance_percent(parameter_03)
				)
			{
				if (parameter_03 > parameter_01) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}
			else if (option_01 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
				&& is_critical_hit_damage_percent(parameter_01)
				&& is_not_critical_hit_or_socket_option(option_02)
				&& is_not_critical_hit_or_socket_option(option_03)
				)
			{
				final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}
			else if (option_01 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
				&& is_critical_hit_damage_percent(parameter_01)
				&& option_02 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
				&& is_critical_hit_damage_percent(parameter_02)
				&& is_not_critical_hit_or_socket_option(option_03)
				)
			{
				if (parameter_02 > parameter_01) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}
			else if (option_01 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
				&& is_critical_hit_damage_percent(parameter_01)
				&& is_not_critical_hit_or_socket_option(option_02)
				&& option_03 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
				&& is_critical_hit_damage_percent(parameter_03)
				)
			{
				if (parameter_03 > parameter_01) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}

		}

		// #2: force_to_dps_build - Area damage
		if (force_to_dps_build && final_decision == DESCISION_NOTHING)
		{
			if (option_01 == ROLL_OPTION_AREA_DAMAGE
				&& option_02 == ROLL_OPTION_AREA_DAMAGE
				&& is_10_to_20_percent(parameter_01)
				&& is_10_to_20_percent(parameter_02)
				&& is_option_less_dps_priority_than_area_damage(option_03))
			{
				if (parameter_02 > parameter_01) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}
			else if (option_01 == ROLL_OPTION_AREA_DAMAGE
				&& is_option_less_dps_priority_than_area_damage(option_02)
				&& option_03 == ROLL_OPTION_AREA_DAMAGE
				&& is_10_to_20_percent(parameter_01)
				&& is_10_to_20_percent(parameter_03))
			{
				if (parameter_03 > parameter_01) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}






			if (final_decision == DESCISION_NOTHING
				&& is_require_hungering_arrow(item, force_to_dps_build)
				&& (is_dh_skill(option_01) || is_dh_skill(option_02) || is_dh_skill(option_03)))
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
				else if (option_01 != ROLL_OPTION_UNKNOWN && option_01 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
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

				//Có HUNGERING_ARROW ở dòng 1 và dòng 2
				else if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_03 != ROLL_OPTION_UNKNOWN && option_03 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& is_10_to_15_percent(parameter_01)
					&& is_10_to_15_percent(parameter_02)
					)
				{
					if (parameter_01 >= parameter_02) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
					else final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				}
				//Có HUNGERING_ARROW ở dòng 1 và dòng 3
				else if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_02 != ROLL_OPTION_UNKNOWN && option_02 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_03 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& is_10_to_15_percent(parameter_01)
					&& is_10_to_15_percent(parameter_03)
					)
				{
					if (parameter_01 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
					else final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				}
				//Có HUNGERING_ARROW ở dòng 2 và dòng 3
				else if (option_01 != ROLL_OPTION_UNKNOWN && option_01 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& option_03 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
					&& is_10_to_15_percent(parameter_02)
					&& is_10_to_15_percent(parameter_03)
					)
				{
					if (parameter_02 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
					else final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				}





				//không có HUNGERING_ARROW ở dòng nào, nhưng có skill
				else if (option_01 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW && option_01 != ROLL_OPTION_UNKNOWN
					&& option_02 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW && option_02 != ROLL_OPTION_UNKNOWN
					&& option_03 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW && option_03 != ROLL_OPTION_UNKNOWN
					&& (is_dh_skill(option_01) || is_dh_skill(option_02) || is_dh_skill(option_03))
					)
				{
					if (is_dh_skill(option_01) && parameter_01 == ROLL_PARAMETER_15_PERCENT) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
					else if (is_dh_skill(option_02) && parameter_02 == ROLL_PARAMETER_15_PERCENT) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
					else if (is_dh_skill(option_03) && parameter_03 == ROLL_PARAMETER_15_PERCENT) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
					else if (is_dh_skill(option_01) && is_10_to_15_percent(parameter_01) && parameter_01 >= parameter_02 && parameter_01 >= parameter_03)
					{
						final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
					}
					else if (is_dh_skill(option_02) && is_10_to_15_percent(parameter_02) && parameter_02 >= parameter_01 && parameter_02 >= parameter_03)
					{
						final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
					}
					else if (is_dh_skill(option_03) && is_10_to_15_percent(parameter_03) && parameter_03 >= parameter_01 && parameter_03 >= parameter_02)
					{
						final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
					}
					else if (is_dh_skill(option_01)) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
					else if (is_dh_skill(option_02)) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
					else if (is_dh_skill(option_03)) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
					else  final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
				}

			}











			//looking to update area damage
			else if (option_01 == ROLL_OPTION_AREA_DAMAGE
				&& is_option_less_dps_priority_than_area_damage(option_02)
				&& is_option_less_dps_priority_than_area_damage(option_03))
			{
				final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}
		}






		if (final_decision == DESCISION_NOTHING
			&& is_require_hungering_arrow(item, force_to_dps_build)
			&& (is_dh_skill(option_01) || is_dh_skill(option_02) || is_dh_skill(option_03)))
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
			else if (option_01 != ROLL_OPTION_UNKNOWN && option_01 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
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

			//Có HUNGERING_ARROW ở dòng 1 và dòng 2
			else if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& option_03 != ROLL_OPTION_UNKNOWN && option_03 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& is_10_to_15_percent(parameter_01)
				&& is_10_to_15_percent(parameter_02)
				)
			{
				if (parameter_01 >= parameter_02) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
			}
			//Có HUNGERING_ARROW ở dòng 1 và dòng 3
			else if (option_01 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& option_02 != ROLL_OPTION_UNKNOWN && option_02 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& option_03 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& is_10_to_15_percent(parameter_01)
				&& is_10_to_15_percent(parameter_03)
				)
			{
				if (parameter_01 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
			}
			//Có HUNGERING_ARROW ở dòng 2 và dòng 3
			else if (option_01 != ROLL_OPTION_UNKNOWN && option_01 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& option_02 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& option_03 == ROLL_OPTION_DHSKILL_HUNGERING_ARROW
				&& is_10_to_15_percent(parameter_02)
				&& is_10_to_15_percent(parameter_03)
				)
			{
				if (parameter_02 >= parameter_03) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				else final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
			}





			//không có HUNGERING_ARROW ở dòng nào, nhưng có skill
			else if (option_01 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW && option_01 != ROLL_OPTION_UNKNOWN
				&& option_02 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW && option_02 != ROLL_OPTION_UNKNOWN
				&& option_03 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW && option_03 != ROLL_OPTION_UNKNOWN
				&& (is_dh_skill(option_01) || is_dh_skill(option_02) || is_dh_skill(option_03))
				)
			{
				if (is_dh_skill(option_01) && parameter_01 == ROLL_PARAMETER_15_PERCENT) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
				else if (is_dh_skill(option_02) && parameter_02 == ROLL_PARAMETER_15_PERCENT) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				else if (is_dh_skill(option_03) && parameter_03 == ROLL_PARAMETER_15_PERCENT) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				else if (is_dh_skill(option_01) && is_10_to_15_percent(parameter_01) && parameter_01 >= parameter_02 && parameter_01 >= parameter_03)
				{
					final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
				}
				else if (is_dh_skill(option_02) && is_10_to_15_percent(parameter_02) && parameter_02 >= parameter_01 && parameter_02 >= parameter_03)
				{
					final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				}
				else if (is_dh_skill(option_03) && is_10_to_15_percent(parameter_03) && parameter_03 >= parameter_01 && parameter_03 >= parameter_02)
				{
					final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				}
				else if (is_dh_skill(option_01)) final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
				else if (is_dh_skill(option_02)) final_decision = DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT;
				else if (is_dh_skill(option_03)) final_decision = DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT;
				else  final_decision = DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT;
			}

		}












		if (final_decision == DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT)
		{
			select_option_01();
			wait_after_roll();
		}
		else if (final_decision == DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT)
		{
			select_option_02();
			wait_after_roll();
		}
		else if (final_decision == DESCISION_SELECT_OPTION_02_AND_STOP_ROLL)
		{
			select_option_02();
			stop_roll();
		}
		else if (final_decision == DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT)
		{
			select_option_03();
			wait_after_roll();
		}
		else if (final_decision == DESCISION_SELECT_OPTION_03_AND_STOP_ROLL)
		{
			select_option_03();
			stop_roll();
		}
	}

	//Hungering_arrow
	else if (is_require_hungering_arrow(item, force_to_dps_build)
		&& is_dh_skill(option_01)
		&& (is_10_to_14_percent(parameter_01) || option_01 != ROLL_OPTION_DHSKILL_HUNGERING_ARROW)
		&& w32gdi.D3IsRollWaiting()
		&& resource_status == RESOURCE_STATUS_FULL_FOR_CLOTHES
		&& gold_status == GOLD_STATUS_FULL_FOR_ROLLING)
	{
		start_roll();
	}


	//Critical hit chance 4 - 6
	else if (force_to_dps_build
		&& option_01 == ROLL_OPTION_CRITICAL_HIT_CHANCE
		&& is_04_to_06_percent(parameter_01)
		&& parameter_01 < ROLL_PARAMETER_06_PERCENT
		&& w32gdi.D3IsRollWaiting()
		&& (resource_status == RESOURCE_STATUS_ENOUGH_FOR_JEWELRY || resource_status == RESOURCE_STATUS_FULL_FOR_CLOTHES))
	{
		start_roll();
	}
	//Critical hit chance 8 - 10
	else if (force_to_dps_build
		&& option_01 == ROLL_OPTION_CRITICAL_HIT_CHANCE
		&& is_08_to_10_percent(parameter_01)
		&& parameter_01 < ROLL_PARAMETER_10_PERCENT
		&& w32gdi.D3IsRollWaiting()
		&& (resource_status == RESOURCE_STATUS_ENOUGH_FOR_JEWELRY || resource_status == RESOURCE_STATUS_FULL_FOR_CLOTHES))
	{
		start_roll();
	}
	//Critical hit damage 26-50
	else if (force_to_dps_build
		&& option_01 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
		&& is_26_to_50_percent(parameter_01)
		&& parameter_01 < ROLL_PARAMETER_50_PERCENT
		&& w32gdi.D3IsRollWaiting()
		&& (resource_status == RESOURCE_STATUS_ENOUGH_FOR_JEWELRY || resource_status == RESOURCE_STATUS_FULL_FOR_CLOTHES))
	{
		start_roll();
	}
	//Critical hit damage 51-100
	else if (force_to_dps_build
		&& option_01 == ROLL_OPTION_CRITICAL_HIT_DAMAGE
		&& is_51_to_100_percent(parameter_01)
		&& parameter_01 < ROLL_PARAMETER_100_PERCENT
		&& w32gdi.D3IsRollWaiting()
		&& (resource_status == RESOURCE_STATUS_ENOUGH_FOR_JEWELRY || resource_status == RESOURCE_STATUS_FULL_FOR_CLOTHES))
	{
		start_roll();
	}
	//Area damage
	else if (force_to_dps_build
		&& option_01 == ROLL_OPTION_AREA_DAMAGE
		&& is_10_to_20_percent(parameter_01)
		&& parameter_01 < ROLL_PARAMETER_20_PERCENT
		&& w32gdi.D3IsRollWaiting()
		&& resource_status == RESOURCE_STATUS_FULL_FOR_CLOTHES
		&& gold_status == GOLD_STATUS_FULL_FOR_ROLLING)
	{
		start_roll();
	}
}
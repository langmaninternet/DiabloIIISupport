#ifndef QBT_ROLL_HEADER
#define QBT_ROLL_HEADER

enum ROLL_OPTION
{
	ROLL_OPTION_UNKNOWN = 0,

	// 1. CriticalHit
	ROLL_OPTION_CRITICAL_HIT_CHANCE,
	ROLL_OPTION_CRITICAL_HIT_DAMAGE,


	// 2. Socket
	ROLL_OPTION_ONE_SOCKET,
	ROLL_OPTION_TWO_SOCKET,
	ROLL_OPTION_THREE_SOCKET,

	// 3. Damage
	ROLL_OPTION_BASE_DAMAGE,
	ROLL_OPTION_AREA_DAMAGE,
	ROLL_OPTION_COLD_DAMAGE,
	ROLL_OPTION_LIGHTNING_DAMAGE,
	ROLL_OPTION_PHYSICAL_DAMAGE,


	//4. Stats
	ROLL_OPTION_STRENGTH,
	ROLL_OPTION_DEXTERITY,
	ROLL_OPTION_INTELLIGENCE,
	ROLL_OPTION_VITALITY,




	// 5. Reduce
	ROLL_OPTION_REDUCE_MELEE_DAMAGE,
	ROLL_OPTION_REDUCE_RANGED_DAMAGE,
	ROLL_OPTION_REDUCE_COOLDOWN,
	ROLL_OPTION_REDUCE_RESOURCE,



	// 6. Attack Speed
	ROLL_OPTION_ATTACK_SPEED,

	// 7. Life
	ROLL_OPTION_LIFE_PERCENT,
	ROLL_OPTION_LIFE_HIT,
	ROLL_OPTION_LIFE_PER_SECOND,	
	ROLL_OPTION_LIFE_KILL,


	// Resist All  RESIST ALL
	ROLL_OPTION_RESIST_ALL,




	ROLL_OPTION_DHSKILL_HUNGERING_ARROW,
	ROLL_OPTION_DHSKILL_BOLAS,
	ROLL_OPTION_DHSKILL_GRENADE,
	ROLL_OPTION_DHSKILL_ENTANGLING_SHOT,
	ROLL_OPTION_DHSKILL_EVASIVE_FIRE,






	ROLL_OPTION_ARMOR,


	ROLL_OPTION_HEALING_GLOBE,
	ROLL_OPTION_GOLD_PICKUP,
	ROLL_OPTION_EXP,
	ROLL_OPTION_THORN_DAMAGE,


	ROLL_OPTION_MOVEMENT_SPEED,
};

enum ROLL_PARAMETER
{
	ROLL_PARAMETER_UNKNOWN = 0,
	ROLL_PARAMETER_04_PERCENT,
	ROLL_PARAMETER_04_D_5_PERCENT,
	ROLL_PARAMETER_05_PERCENT,
	ROLL_PARAMETER_05_D_5_PERCENT,
	ROLL_PARAMETER_06_PERCENT,
	ROLL_PARAMETER_07_PERCENT,
	ROLL_PARAMETER_08_PERCENT,
	ROLL_PARAMETER_08_D_5_PERCENT,
	ROLL_PARAMETER_09_PERCENT,
	ROLL_PARAMETER_09_D_5_PERCENT,
	ROLL_PARAMETER_10_PERCENT,
	ROLL_PARAMETER_11_PERCENT,
	ROLL_PARAMETER_12_PERCENT,
	ROLL_PARAMETER_13_PERCENT,
	ROLL_PARAMETER_14_PERCENT,
	ROLL_PARAMETER_15_PERCENT,
	ROLL_PARAMETER_16_PERCENT,
	ROLL_PARAMETER_17_PERCENT,
	ROLL_PARAMETER_18_PERCENT,
	ROLL_PARAMETER_19_PERCENT,
	ROLL_PARAMETER_20_PERCENT,
	ROLL_PARAMETER_21_PERCENT,
	ROLL_PARAMETER_22_PERCENT,
	ROLL_PARAMETER_23_PERCENT,
	ROLL_PARAMETER_24_PERCENT,
	ROLL_PARAMETER_25_PERCENT,
	ROLL_PARAMETER_26_PERCENT,
	ROLL_PARAMETER_27_PERCENT,
	ROLL_PARAMETER_28_PERCENT,
	ROLL_PARAMETER_29_PERCENT,
	ROLL_PARAMETER_30_PERCENT,
	ROLL_PARAMETER_31_PERCENT,
	ROLL_PARAMETER_32_PERCENT,
	ROLL_PARAMETER_33_PERCENT,
	ROLL_PARAMETER_34_PERCENT,
	ROLL_PARAMETER_35_PERCENT,
	ROLL_PARAMETER_36_PERCENT,
	ROLL_PARAMETER_37_PERCENT,
	ROLL_PARAMETER_38_PERCENT,
	ROLL_PARAMETER_39_PERCENT,
	ROLL_PARAMETER_40_PERCENT,
	ROLL_PARAMETER_41_PERCENT,
	ROLL_PARAMETER_42_PERCENT,
	ROLL_PARAMETER_43_PERCENT,
	ROLL_PARAMETER_44_PERCENT,
	ROLL_PARAMETER_45_PERCENT,
	ROLL_PARAMETER_46_PERCENT,
	ROLL_PARAMETER_47_PERCENT,
	ROLL_PARAMETER_48_PERCENT,
	ROLL_PARAMETER_49_PERCENT,
	ROLL_PARAMETER_50_PERCENT,
	ROLL_PARAMETER_51_PERCENT,
	ROLL_PARAMETER_52_PERCENT,
	ROLL_PARAMETER_53_PERCENT,
	ROLL_PARAMETER_54_PERCENT,
	ROLL_PARAMETER_55_PERCENT,
	ROLL_PARAMETER_56_PERCENT,
	ROLL_PARAMETER_57_PERCENT,
	ROLL_PARAMETER_58_PERCENT,
	ROLL_PARAMETER_59_PERCENT,
	ROLL_PARAMETER_60_PERCENT,
	ROLL_PARAMETER_61_PERCENT,
	ROLL_PARAMETER_62_PERCENT,
	ROLL_PARAMETER_63_PERCENT,
	ROLL_PARAMETER_64_PERCENT,
	ROLL_PARAMETER_65_PERCENT,
	ROLL_PARAMETER_66_PERCENT,
	ROLL_PARAMETER_67_PERCENT,
	ROLL_PARAMETER_68_PERCENT,
	ROLL_PARAMETER_69_PERCENT,
	ROLL_PARAMETER_70_PERCENT,
	ROLL_PARAMETER_71_PERCENT,
	ROLL_PARAMETER_72_PERCENT,
	ROLL_PARAMETER_73_PERCENT,
	ROLL_PARAMETER_74_PERCENT,
	ROLL_PARAMETER_75_PERCENT,
	ROLL_PARAMETER_76_PERCENT,
	ROLL_PARAMETER_77_PERCENT,
	ROLL_PARAMETER_78_PERCENT,
	ROLL_PARAMETER_79_PERCENT,
	ROLL_PARAMETER_80_PERCENT,
	ROLL_PARAMETER_81_PERCENT,
	ROLL_PARAMETER_82_PERCENT,
	ROLL_PARAMETER_83_PERCENT,
	ROLL_PARAMETER_84_PERCENT,
	ROLL_PARAMETER_85_PERCENT,
	ROLL_PARAMETER_86_PERCENT,
	ROLL_PARAMETER_87_PERCENT,
	ROLL_PARAMETER_88_PERCENT,
	ROLL_PARAMETER_89_PERCENT,
	ROLL_PARAMETER_90_PERCENT,
	ROLL_PARAMETER_91_PERCENT,
	ROLL_PARAMETER_92_PERCENT,
	ROLL_PARAMETER_93_PERCENT,
	ROLL_PARAMETER_94_PERCENT,
	ROLL_PARAMETER_95_PERCENT,
	ROLL_PARAMETER_96_PERCENT,
	ROLL_PARAMETER_97_PERCENT,
	ROLL_PARAMETER_98_PERCENT,
	ROLL_PARAMETER_99_PERCENT,
	ROLL_PARAMETER_100_PERCENT,
};



enum ROLL_ITEM
{
	ROLL_ITEM_UNKNOWN,
	//ROLL_ITEM_FOCUS,
	//ROLL_ITEM_COE,


	ROLL_ITEM_HUNTERS_WRATH,
	ROLL_ITEM_COLD_CATHODE_TROUSERS,
};

enum RESOURCE_STATUS
{
	RESOURCE_STATUS_UNKNOWN,
	RESOURCE_STATUS_FULL_FOR_CLOTHES,
	RESOURCE_STATUS_ENOUGH_FOR_JEWELRY,
};

enum GOLD_STATUS
{
	GOLD_STATUS_UNKNOWN,
	GOLD_STATUS_FULL_FOR_ROLLING,
};

enum ROLL_DESCISION
{
	DESCISION_NOTHING = 0,
	DESCISION_STAY_IN_OPTION_01,
	DESCISION_SELECT_OPTION_01_AND_WAIT_NEXT,
	DESCISION_SELECT_OPTION_02_AND_WAIT_NEXT,
	DESCISION_SELECT_OPTION_02_AND_STOP_ROLL,
	DESCISION_SELECT_OPTION_03_AND_WAIT_NEXT,
	DESCISION_SELECT_OPTION_03_AND_STOP_ROLL,
};


wchar_t* get_roll_name(ROLL_OPTION);


ROLL_OPTION get_roll_option_01(void);
ROLL_OPTION get_roll_option_02(void);
ROLL_OPTION get_roll_option_03(void);

ROLL_PARAMETER get_roll_parameter_01(ROLL_OPTION);
ROLL_PARAMETER get_roll_parameter_02(ROLL_OPTION);
ROLL_PARAMETER get_roll_parameter_03(ROLL_OPTION);
wchar_t* get_parameter_name(ROLL_PARAMETER);


ROLL_ITEM get_roll_item(void);
wchar_t* get_item_name(ROLL_ITEM);


RESOURCE_STATUS get_resource_status(void);
wchar_t* get_resource_info(RESOURCE_STATUS);

GOLD_STATUS get_gold_status(void);
wchar_t* get_gold_info(GOLD_STATUS);


void do_roll(ROLL_ITEM item,
	ROLL_OPTION option_01, ROLL_PARAMETER parameter_01,
	ROLL_OPTION option_02, ROLL_PARAMETER parameter_02,
	ROLL_OPTION option_03, ROLL_PARAMETER parameter_03,
	RESOURCE_STATUS resource_status,
	GOLD_STATUS gold_status,
	bool force_to_dps_build);




#endif
#ifndef QBT_STARPACT_HEADER
#define QBT_STARPACT_HEADER
#include <Windows.h>




/************************************************************************/
/* Win32GDI                                                             */
/************************************************************************/
class Win32GDI
{
protected:
private:
	HBITMAP		hBitmap;
	HDC			hScreenMemDC;
	RECT		rectDesktop;
public:
	/*Constructor*/		Win32GDI(void);
	void				CaptureDesktop(void);
	void				BlurRectangle(int xleft, int ytop, int xright, int ybottom);
	int					GetPixel(int x, int y);
	bool				ValidMode(void);
	bool				D3IsViewMap(void);
	bool				D3IsOpenSkillTable(void);
	bool				D3IsOpenKadala(void);
	bool				D3IsOpenUrshi(void);
	bool				D3IsOpenStash(void);
	bool				D3Skill01KeyIs1(void);
	bool				D3Skill02KeyIs2(void);
	bool				D3Skill03KeyIs3(void);
	bool				D3Skill04KeyIs4(void);


	bool				D3Skill01Is_ArchonBlast_AndReady(void);

	bool				D3Skill02Is_Storm_Armor_AndReady(void);
	bool				D3Skill02Is_Magic_Weapon_AndReady(void);
	bool				D3Skill02Is_Familiar_AndReady(void);

	bool				D3Skill03Is_Magic_Weapon_AndReady(void);
	bool				D3Skill03Is_Familiar_AndReady(void);
	bool				D3Skill03Is_Storm_Armor_AndReady(void);

	bool				D3Skill04Is_Familiar_AndReady(void);
	bool				D3Skill04Is_Storm_Armor_AndReady(void);
	bool				D3Skill04Is_Magic_Weapon_AndReady(void);
	bool				D3Skill04Is_Vengeance_AndReady(void);






	/************************************************************************/
	/* Code chuẩn                                                           */
	/************************************************************************/
	bool				IsRolling(void);
	bool				IsFullResourceForClothes(void);
	bool				IsEnoughResourceForJewelry(void);
	bool				IsEnoughGold5Digit(int);
	bool				IsEnoughGold5Digit(void);
	bool				IsEnoughGold6Digit(int);
	bool				IsEnoughGold6Digit(void);
	bool				IsEnoughGold7Digit(int);
	bool				IsEnoughGold7Digit(void);
	bool				HaveNoOption04and05(void);


	/************************************************************************/
	/* Critical Hit Damage                                                  */
	/************************************************************************/
	bool				RollingOption01IsCriticalHitDamage(void);
	bool				RollingOption02IsCriticalHitDamage(void);
	bool				RollingOption03IsCriticalHitDamage(void);


	bool				RollingParameter01Is100PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is100PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is100PercentBaseCriticalHitDamage(void);

	bool				RollingParameter01Is50PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is50PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is50PercentBaseCriticalHitDamage(void);
	bool				RollingParameter01Is49PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is49PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is49PercentBaseCriticalHitDamage(void);
	bool				RollingParameter01Is48PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is48PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is48PercentBaseCriticalHitDamage(void);


	bool				RollingParameter01Is46PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is46PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is46PercentBaseCriticalHitDamage(void);
	bool				RollingParameter01Is45PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is45PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is45PercentBaseCriticalHitDamage(void);


	bool				RollingParameter02Is44PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is44PercentBaseCriticalHitDamage(void);
	bool				RollingParameter01Is43PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is43PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is43PercentBaseCriticalHitDamage(void);
	bool				RollingParameter01Is42PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is42PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is42PercentBaseCriticalHitDamage(void);
	bool				RollingParameter01Is41PercentBaseCriticalHitDamage(void);


	bool				RollingParameter01Is40PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is40PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is40PercentBaseCriticalHitDamage(void);


	bool				RollingParameter02Is39PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is39PercentBaseCriticalHitDamage(void);



	bool				RollingParameter02Is38PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is38PercentBaseCriticalHitDamage(void);


	bool				RollingParameter02Is37PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is37PercentBaseCriticalHitDamage(void);

	bool				RollingParameter02Is36PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is36PercentBaseCriticalHitDamage(void);

	bool				RollingParameter02Is35PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is35PercentBaseCriticalHitDamage(void);



	bool				RollingParameter01Is34PercentBaseCriticalHitDamage(void);
	bool				RollingParameter02Is34PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is34PercentBaseCriticalHitDamage(void);

	bool				RollingParameter02Is33PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is33PercentBaseCriticalHitDamage(void);


	bool				RollingParameter02Is32PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is32PercentBaseCriticalHitDamage(void);


	bool				RollingParameter02Is31PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is31PercentBaseCriticalHitDamage(void);

	bool				RollingParameter02Is30PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is30PercentBaseCriticalHitDamage(void);


	bool				RollingParameter02Is29PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is29PercentBaseCriticalHitDamage(void);


	bool				RollingParameter02Is28PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is28PercentBaseCriticalHitDamage(void);

	bool				RollingParameter02Is27PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is27PercentBaseCriticalHitDamage(void);


	bool				RollingParameter02Is26PercentBaseCriticalHitDamage(void);
	bool				RollingParameter03Is26PercentBaseCriticalHitDamage(void);


	/************************************************************************/
	/* Critical Hit Chance                                                  */
	/************************************************************************/
	bool				RollingOption01IsCriticalHitChance(void);
	bool				RollingOption02IsCriticalHitChance(void);
	bool				RollingOption03IsCriticalHitChance(void);
	bool				RollingParameter01Is10PercentBaseCriticalHitChance(void);
	bool				RollingParameter02Is10PercentBaseCriticalHitChance(void);
	bool				RollingParameter03Is10PercentBaseCriticalHitChance(void);
	bool				RollingParameter01Is09d5PercentBaseCriticalHitChance(void);
	bool				RollingParameter02Is09d5PercentBaseCriticalHitChance(void);
	bool				RollingParameter03Is09d5PercentBaseCriticalHitChance(void);

	bool				RollingParameter01Is08PercentBaseCriticalHitChance(void);
	bool				RollingParameter01Is06PercentBaseCriticalHitChance(void);
	bool				RollingParameter02Is06PercentBaseCriticalHitChance(void);
	bool				RollingParameter03Is06PercentBaseCriticalHitChance(void);
	bool				RollingParameter01Is05d5PercentBaseCriticalHitChance(void);
	bool				RollingParameter02Is05d5PercentBaseCriticalHitChance(void);
	bool				RollingParameter03Is05d5PercentBaseCriticalHitChance(void);
	bool				RollingParameter01Is05PercentBaseCriticalHitChance(void);
	bool				RollingParameter02Is05PercentBaseCriticalHitChance(void);
	bool				RollingParameter03Is05PercentBaseCriticalHitChance(void);
	bool				RollingParameter01Is04d5PercentBaseCriticalHitChance(void);
	bool				RollingParameter02Is04d5PercentBaseCriticalHitChance(void);
	bool				RollingParameter03Is04d5PercentBaseCriticalHitChance(void);



	/************************************************************************/
	/* Area Damage                                                          */
	/************************************************************************/
	bool				RollingOption01IsAreaDamage(int);
	bool				RollingOption01IsAreaDamage(void);
	bool				RollingOption02IsAreaDamage(int);
	bool				RollingOption02IsAreaDamage(void);
	bool				RollingOption03IsAreaDamage(int);
	bool				RollingOption03IsAreaDamage(void);

	bool				RollingParameter02Is20PercentBaseAreaDamage(int);
	bool				RollingParameter02Is20PercentBaseAreaDamage(void);
	bool				RollingParameter03Is20PercentBaseAreaDamage(int);
	bool				RollingParameter03Is20PercentBaseAreaDamage(void);
	bool				RollingParameter01Is19PercentBaseAreaDamage(int);
	bool				RollingParameter01Is19PercentBaseAreaDamage(void);
	bool				RollingParameter02Is19PercentBaseAreaDamage(int);
	bool				RollingParameter02Is19PercentBaseAreaDamage(void);
	bool				RollingParameter03Is19PercentBaseAreaDamage(int);
	bool				RollingParameter03Is19PercentBaseAreaDamage(void);
	bool				RollingParameter01Is16PercentBaseAreaDamage(int);
	bool				RollingParameter01Is16PercentBaseAreaDamage(void);
	bool				RollingParameter02Is11PercentBaseAreaDamage(int);
	bool				RollingParameter02Is11PercentBaseAreaDamage(void);
	bool				RollingParameter03Is11PercentBaseAreaDamage(int);
	bool				RollingParameter03Is11PercentBaseAreaDamage(void);

	/************************************************************************/
	/* Elements Damage                                                      */
	/************************************************************************/
	bool				RollingOption02IsColdDamage(void);
	bool				RollingOption03IsColdDamage(void);


	bool				RollingOption02IsPhysicalDamage(void);
	bool				RollingOption03IsPhysicalDamage(void);

	/************************************************************************/
	/* HungeringArrow                                                       */
	/************************************************************************/

	bool				RollingItemIsHuntersWrath(void);
	bool				RollingItemIsColdCathodeTrousers(void);

	bool				RollingOption01IsHungeringArrow(void);
	bool				RollingOption02IsHungeringArrow(void);
	bool				RollingOption03IsHungeringArrow(void);

	//Parameter
	bool				RollingParameter01Is15PercentBaseHungeringArrow(void);
	bool				RollingParameter02Is15PercentBaseHungeringArrow(void);
	bool				RollingParameter03Is15PercentBaseHungeringArrow(void);
	bool				RollingParameter01Is14PercentBaseHungeringArrow(void);
	bool				RollingParameter02Is14PercentBaseHungeringArrow(void);
	bool				RollingParameter03Is14PercentBaseHungeringArrow(void);
	bool				RollingParameter01Is13PercentBaseHungeringArrow(void);
	bool				RollingParameter02Is13PercentBaseHungeringArrow(void);
	bool				RollingParameter03Is13PercentBaseHungeringArrow(void);
	bool				RollingParameter01Is12PercentBaseHungeringArrow(void);
	bool				RollingParameter02Is12PercentBaseHungeringArrow(void);
	bool				RollingParameter03Is12PercentBaseHungeringArrow(void);
	bool				RollingParameter01Is11PercentBaseHungeringArrow(void);
	bool				RollingParameter02Is11PercentBaseHungeringArrow(void);
	bool				RollingParameter03Is11PercentBaseHungeringArrow(void);
	bool				RollingParameter01Is10PercentBaseHungeringArrow(void);
	bool				RollingParameter02Is10PercentBaseHungeringArrow(void);
	bool				RollingParameter03Is10PercentBaseHungeringArrow(void);

	/************************************************************************/
	/* Stats                                                                */
	/************************************************************************/

	bool				RollingOption02IsDexterity(int);
	bool				RollingOption02IsDexterity(void);
	bool				RollingOption03IsDexterity(int);
	bool				RollingOption03IsDexterity(void);

	bool				RollingOption02IsIntelligence(int);
	bool				RollingOption02IsIntelligence(void);
	bool				RollingOption03IsIntelligence(int);
	bool				RollingOption03IsIntelligence(void);

	bool				RollingOption02IsVitality(int);
	bool				RollingOption02IsVitality(void);
	bool				RollingOption03IsVitality(int);
	bool				RollingOption03IsVitality(void);


	/************************************************************************/
	/* Reduce Damage                                                        */
	/************************************************************************/
	bool				RollingOption01IsReduceMeleeDamage(void);
	bool				RollingOption02IsReduceMeleeDamage(void);
	bool				RollingOption03IsReduceMeleeDamage(void);
	bool				RollingOption01Is06PercentBaseReduceMeleeDamage(void);
	bool				RollingOption02Is06PercentBaseReduceMeleeDamage(void);
	bool				RollingOption03Is06PercentBaseReduceMeleeDamage(void);

	/************************************************************************/
	/* Armor                                                                */
	/************************************************************************/
	bool				RollingOption02IsArmor(int);
	bool				RollingOption02IsArmor(void);
	bool				RollingOption03IsArmor(int);
	bool				RollingOption03IsArmor(void);




	/************************************************************************/
	/* ???????????????????                                                  */
	/************************************************************************/


	bool				RollingOption01Is07Percent(int);
	bool				RollingOption01Is07Percent(void);


	bool				RollingOption02Is07PercentBaseAttackSpeed(int);
	bool				RollingOption02Is07PercentBaseAttackSpeed(void);
	bool				RollingOption03Is07PercentBaseAttackSpeed(int);
	bool				RollingOption03Is07PercentBaseAttackSpeed(void);











	//bool				RollingOption01IsCriticalHitDamage(void);
	//bool				RollingOption02IsCriticalHitDamage(void);
	//bool				RollingOption03IsCriticalHitDamage(void);




	// 2. Socket
	bool				RollingOption02IsOneSocket(void);
	bool				RollingOption03IsOneSocket(void);





	// 3. Damage
	bool				RollingOption01IsBaseDamage(int);
	bool				RollingOption01IsBaseDamage(void);
	bool				RollingOption02IsBaseDamage(int);
	bool				RollingOption02IsBaseDamage(void);
	bool				RollingOption03IsBaseDamage(int);
	bool				RollingOption03IsBaseDamage(void);






	// 5. Reduce


	bool				RollingOption02IsReduceCooldown(void);
	bool				RollingOption03IsReduceCooldown(void);

	bool				RollingOption01IsReduceResource(void);
	bool				RollingOption02IsReduceResource(void);
	bool				RollingOption03IsReduceResource(void);


	//6. Attack Speed
	bool				RollingOption01IsAttackSpeed(void);
	bool				RollingOption02IsAttackSpeed(void);
	bool				RollingOption03IsAttackSpeed(void);



	//7. Life 








	bool				RollingOption01IsReduceRangedDamage(void);



	bool				RollingOption02IsResistAll(int);
	bool				RollingOption02IsResistAll(void);
	bool				RollingOption03IsResistAll(int);
	bool				RollingOption03IsResistAll(void);



	bool				RollingOption01IsGrenade(void);
	bool				RollingOption02IsGrenade(void);
	bool				RollingOption03IsGrenade(void);
	bool				RollingOption01IsEvasiveFire(void);
	bool				RollingOption02IsEvasiveFire(void);
	bool				RollingOption03IsEvasiveFire(void);
	bool				RollingOption01IsBolas(void);
	bool				RollingOption02IsBolas(void);
	bool				RollingOption03IsBolas(void);
	bool				RollingOption01IsEntanglingShot(void);
	bool				RollingOption02IsEntanglingShot(void);
	bool				RollingOption03IsEntanglingShot(void);





	bool				RollingOption01IsLifePercent(int);
	bool				RollingOption01IsLifePercent(void);
	bool				RollingOption02IsLifePercent(int);
	bool				RollingOption02IsLifePercent(void);
	bool				RollingOption03IsLifePercent(int);
	bool				RollingOption03IsLifePercent(void);


	bool				RollingOption01IsLifePerSecond(void);
	bool				RollingOption02IsLifePerSecond(void);
	bool				RollingOption03IsLifePerSecond(void);


	bool				RollingOption02IsLifePerHit(int);
	bool				RollingOption02IsLifePerHit(void);
	bool				RollingOption03IsLifePerHit(int);
	bool				RollingOption03IsLifePerHit(void);


	bool				RollingOption01IsLifePerKill(int);
	bool				RollingOption01IsLifePerKill(void);




	bool				RollingOption01IsHealingGlobe(void);
	//bool				RollingOption02IsHealingGlobe(void);
	bool				RollingOption03IsHealingGlobe(void);

	bool				RollingOption02IsPoisonResistance(int);
	bool				RollingOption02IsPoisonResistance(void);


	bool				RollingOption03IsColdResistance(int);
	bool				RollingOption03IsColdResistance(void);




	bool				RollingOption02IsThornDamage(int);
	bool				RollingOption02IsThornDamage(void);


	bool				RollingOption03IsThornDamage(int);
	bool				RollingOption03IsThornDamage(void);


	bool				RollingItemIsFocus(void);






	/************************************************************************/
	/* Code đầu tiên                                                        */
	/************************************************************************/

	bool				D3IsRollSelecting(void);
	bool				D3IsRollWaiting(void);





	bool				D3Rol02Is_RedueMeleeDamge7P(void);
	bool				D3Rol03Is_RedueMeleeDamge6P(void);

	bool				D3Rol01Is_RedueRangedDamge7P(void);
	bool				D3Rol03Is_RedueRangedDamge6P(void);



	bool				D3Rol02Is_Resistance(int offset);
	bool				D3Rol03Is_Resistance(int offset);


	bool				D3Rol02Is_HealingGlobe(void);

	bool				D3Rol01Is_GoldPickup(void);
	bool				D3Rol02Is_GoldPickup(void);
	bool				D3Rol03Is_GoldPickup(void);

	bool				D3Rol01Is_Exp(void);
	bool				D3Rol02Is_Exp(void);
	bool				D3Rol03Is_Exp(void);













#ifdef _DEBUG
	void				SaveScreen(const char* filePath = "D:\\Dump.bmp");
	void				SaveSubSreen(const char* filePath, int xleft, int ytop, int xright, int ybottom);
	void				SaveSubSreenWithBlur(const char* filePath, int xleft, int ytop, int xright, int ybottom);
	void				DumpRectangle(int xleft, int ytop, int xright, int ybottom);
	void				DumpRectangleEx(int xleft, int ytop, int xright, int ybottom);
	void				DumpSkill01(const char* filePath = "D:\\DumpSkill01.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill02(const char* filePath = "D:\\DumpSkill02.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill03(const char* filePath = "D:\\DumpSkill03.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill04(const char* filePath = "D:\\DumpSkill04.txt", const char* logDumpFolder = "D:\\DumpImage\\");


	void				DumpRollOption01(void);
	void				DumpRollOption01Ex(void);
	void				DumpRollOption02(void);
	void				DumpRollOption02Ex(void);
	void				DumpRollOption03(void);
	void				DumpRollOption03Ex(void);

#endif

	/*Desstructor*/		~Win32GDI();
};


/************************************************************************/
/* StarPact Engine                                                      */
/************************************************************************/
void		QuangBTDumpScreen(void);



/************************************************************************/
/*                                                                      */
/************************************************************************/
struct DiabloIIIStatusStruct
{
	bool	flagInAttackMode;
	bool	flagPotionReady;
	bool	flagIsOpenMap;
	bool	flagIsOpenSkillTable;
	bool	flagIsOpenKadala;
	bool	flagIsOpenUrshi;
	bool	flagIsOpenStash;




#ifdef _DEBUG
	int		getStatusTime;
#endif
};
extern		DiabloIIIStatusStruct diabloGameStatus;
void		GetCurrentDiabloIIStatus(void);
void		PreloadSalvageItem(int* preloadSalvageSlot, int preloadSalvageSlotSize);


#endif
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

	bool				IsEnoughGold5Digit(int);
	bool				IsEnoughGold5Digit(void);
	bool				IsEnoughGold6Digit(int);
	bool				IsEnoughGold6Digit(void);
	bool				IsEnoughGold7Digit(int);
	bool				IsEnoughGold7Digit(void);

	bool				HaveNoOption04and05(void);

	bool				RollingOption01Is15Percent(int);
	bool				RollingOption01Is15Percent(void);
	bool				RollingOption02Is15Percent(int);
	bool				RollingOption02Is15Percent(void);
	bool				RollingOption03Is15Percent(int);
	bool				RollingOption03Is15Percent(void);
	bool				RollingOption01Is14Percent(int);
	bool				RollingOption01Is14Percent(void);
	bool				RollingOption01Is13Percent(int);
	bool				RollingOption01Is13Percent(void);

	bool				RollingOption02Is12Percent(int);
	bool				RollingOption02Is12Percent(void);
	bool				RollingOption03Is12Percent(int);
	bool				RollingOption03Is12Percent(void);



	bool				RollingOption02Is11Percent(int);
	bool				RollingOption02Is11Percent(void);


	bool				RollingOption03Is11Percent(int);
	bool				RollingOption03Is11Percent(void);

	bool				RollingOption02Is10Percent(int);
	bool				RollingOption02Is10Percent(void);

	bool				RollingOption01Is07Percent(int);
	bool				RollingOption01Is07Percent(void);

	bool				RollingOption01Is05Percent(int);
	bool				RollingOption01Is05Percent(void);

	bool				RollingOption03Is05Percent(int);
	bool				RollingOption03Is05Percent(void);

	bool				RollingOption01Is04d5Percent(int);
	bool				RollingOption01Is04d5Percent(void);
	bool				RollingOption02Is04d5Percent(int);
	bool				RollingOption02Is04d5Percent(void);


	bool				RollingOption01IsCriticalHitChance(void);	
	bool				RollingOption02IsCriticalHitChance(void);
	bool				RollingOption03IsCriticalHitChance(void);


	//bool				RollingOption01IsCriticalHitDamage(void);
	//bool				RollingOption02IsCriticalHitDamage(void);
	//bool				RollingOption03IsCriticalHitDamage(void);

	bool				RollingOption03IsDexterity(int);
	bool				RollingOption03IsDexterity(void);
	
	bool				RollingOption02IsIntelligence(int);
	bool				RollingOption02IsIntelligence(void);

	bool				RollingOption01IsBaseDamage(int);
	bool				RollingOption01IsBaseDamage(void);


	bool				RollingOption02IsAreaDamage(int);
	bool				RollingOption02IsAreaDamage(void);
	bool				RollingOption03IsAreaDamage(int);
	bool				RollingOption03IsAreaDamage(void);


	bool				RollingOption03IsCooldown(void);

	bool				RollingOption02IsOneSocket(void);
	bool				RollingOption03IsOneSocket(void);


	bool				RollingOption01IsHungeringArrow(void);
	bool				RollingOption02IsHungeringArrow(void);
	bool				RollingOption03IsHungeringArrow(void);
	bool				RollingOption01IsGrenade(void);
	bool				RollingOption02IsGrenade(void);
	bool				RollingOption03IsGrenade(void);
	bool				RollingOption01IsEvasiveFire(void);
	bool				RollingOption02IsEvasiveFire(void);
	bool				RollingOption03IsEvasiveFire(void);

	bool				RollingOption02IsBolas(void);
	bool				RollingOption03IsBolas(void);

	bool				RollingOption02IsEntanglingShot(void);
	bool				RollingOption03IsEntanglingShot(void);


	bool				RollingOption01IsRedueRangedDamge(void);


	bool				RollingOption01IsLifePercent(int);
	bool				RollingOption01IsLifePercent(void);
	bool				RollingOption02IsLifePercent(int);
	bool				RollingOption02IsLifePercent(void);
	bool				RollingOption03IsLifePercent(int);
	bool				RollingOption03IsLifePercent(void);

	bool				RollingOption01IsLifePerSecond(void);
	bool				RollingOption02IsLifePerSecond(void);
	bool				RollingOption03IsLifePerSecond(int);
	bool				RollingOption03IsLifePerSecond(void);


	bool				RollingOption02IsLifePerHit(int);
	bool				RollingOption02IsLifePerHit(void);







	bool				RollingOption02IsArmor(int);
	bool				RollingOption02IsArmor(void);
	bool				RollingOption03IsArmor(int);
	bool				RollingOption03IsArmor(void);


	bool				RollingOption01IsHealingGlobe(void);
	//bool				RollingOption02IsHealingGlobe(void);
	bool				RollingOption03IsHealingGlobe(void);

	bool				RollingOption02IsPoisonResistance(int);
	bool				RollingOption02IsPoisonResistance(void);


	bool				RollingOption03IsColdResistance(int);
	bool				RollingOption03IsColdResistance(void);

	bool				RollingOption02IsThornDamage(int);
	bool				RollingOption02IsThornDamage(void);





	bool				RollingItemIsFocus(void);
	bool				RollingItemIsHuntersWrath(void);






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
	void				DumpRectangle(int xleft, int ytop, int xright, int ybottom);
	void				DumpRectangleEx(int xleft, int ytop, int xright, int ybottom);
	void				DumpSkill01(const char* filePath = "D:\\DumpSkill01.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill02(const char* filePath = "D:\\DumpSkill02.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill03(const char* filePath = "D:\\DumpSkill03.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill04(const char* filePath = "D:\\DumpSkill04.txt", const char* logDumpFolder = "D:\\DumpImage\\");


	void				DumpRollItem01(const char* filePath = "D:\\DumpRollItem01.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpRollItem01Ex(const char* filePath = "D:\\DumpRollItem01.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpRollItem02(const char* filePath = "D:\\DumpRollItem02.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpRollItem02Ex(const char* filePath = "D:\\DumpRollItem02.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpRollItem03(const char* filePath = "D:\\DumpRollItem03.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpRollItem03Ex(const char* filePath = "D:\\DumpRollItem03.txt", const char* logDumpFolder = "D:\\DumpImage\\");

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
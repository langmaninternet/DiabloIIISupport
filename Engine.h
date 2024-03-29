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



#ifdef _DEBUG
	void				SaveScreen(const char* filePath = "D:\\Dump.bmp");
	void				SaveSubSreen(const char* filePath, int xleft, int ytop, int xright, int ybottom);
	void				DumpRectangle(int xleft, int ytop, int xright, int ybottom);
	void				DumpSkill01(const char* filePath = "D:\\DumpSkill01.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill02(const char* filePath = "D:\\DumpSkill02.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill03(const char* filePath = "D:\\DumpSkill03.txt", const char* logDumpFolder = "D:\\DumpImage\\");
	void				DumpSkill04(const char* filePath = "D:\\DumpSkill04.txt", const char* logDumpFolder = "D:\\DumpImage\\");
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
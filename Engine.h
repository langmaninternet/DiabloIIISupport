#ifndef QBT_STARPACT_HEADER
#define QBT_STARPACT_HEADER
#include <Windows.h>
#define PREMIUM_FEATURE

#ifdef PREMIUM_FEATURE
#include "../DiabloIIICore/Roll/Roll.h"
#endif

/************************************************************************/
/* D3Engine                                                             */
/************************************************************************/
class D3Engine
{
protected:
private:
	HBITMAP		hBitmap;
	HDC			hScreenMemDC;
	RECT		rectDesktop;
public:
	/*Constructor*/		D3Engine(void);
	void				CaptureDesktop(void);

	int					GetPixel(int x, int y);
	bool				ValidMode(void);



#include "../DiabloIIICore/Game/Battle.h"
#include "../DiabloIIICore/Game/Potion.h"
#include "../DiabloIIICore/Skill/Necromancer.h"
#include "../DiabloIIICore/Skill/DemonHunter.h"



#include "../DiabloIIICore/Roll/AreaDamage.h"
#include "../DiabloIIICore/Roll/AttackSpeed.h"
#include "../DiabloIIICore/Roll/BaseDamage.h"
#include "../DiabloIIICore/Roll/Cooldown.h"
#include "../DiabloIIICore/Roll/CriticalHit.h"
#include "../DiabloIIICore/Roll/DemonHunter.h"
#include "../DiabloIIICore/Roll/ElementDamage.h"
#include "../DiabloIIICore/Roll/LifePerHit.h"
#include "../DiabloIIICore/Roll/LifePerKill.h"
#include "../DiabloIIICore/Roll/LifePerSecond.h"
#include "../DiabloIIICore/Roll/LifePercent.h"
#include "../DiabloIIICore/Roll/MovementSpeed.h"
#include "../DiabloIIICore/Roll/ReduceDamage.h"
#include "../DiabloIIICore/Roll/Resistance.h"
#include "../DiabloIIICore/Roll/ResourceCost.h"
#include "../DiabloIIICore/Roll/Roll.h"
#include "../DiabloIIICore/Roll/Socket.h"
#include "../DiabloIIICore/Roll/Stats.h"
#include "../DiabloIIICore/Roll/Thorn.h"





#include "../DiabloIIITemp/Diablo3RolDataCode.h"
#include "../DiabloIIITemp/Diablo3ScreenDataCode.h"
#include "../DiabloIIITemp/Diablo3Roll.h"
#include "../DiabloIIITemp/Diablo3Salvage.h"





#ifdef _DEBUG
#include "../DiabloIIICore/GDI/SaveScreen.h"
#include "../DiabloIIICore/GDI/DumpRectangle.h"
#include "../DiabloIIICore/GDI/DumpSkill.h"
#include "../DiabloIIICore/GDI/DumpRollOption.h"
#endif
	/*Destructor*/		~D3Engine();
};


/************************************************************************/
/* StarPact Engine                                                      */
/************************************************************************/
void		QuangBTDumpScreen(void);



/************************************************************************/
/*                                                                      */
/************************************************************************/
void		PreloadSalvageItem(int* preloadSalvageSlot, int preloadSalvageSlotSize);


#endif
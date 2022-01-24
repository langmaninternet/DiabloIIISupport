#include "stdafx.h"
#include <Windows.h>
#include <Wingdi.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <list>
#include "Engine.h"




Win32GDI					w32gdi;
DiabloIIIStatusStruct		d3GameStatus;
bool						flagOnWizCycle;




























































/************************************************************************/
/* D3 Game status                                                       */
/************************************************************************/
void		GetCurrentDiabloIIStatus(void)
{
	/************************************************************************/
	/* Giá trị mặc định , cần để bảo đảm tool vẫn chạy trong trường hợp xấu */
	/************************************************************************/
	d3GameStatus.flagInAttackMode = true;
	d3GameStatus.flagPotionReady = true;
	d3GameStatus.flagIsOpenMap = false;
	d3GameStatus.flagIsOpenSkillTable = false;
	d3GameStatus.flagIsOpenKadala = false;
	d3GameStatus.flagIsOpenUrshi = false;
	d3GameStatus.flagIsOpenStash = false;
	d3GameStatus.flagIsWizard = false;
	d3GameStatus.flagIsDemonHunter = false;
	d3GameStatus.flagIsMonk = false;
	d3GameStatus.flagInArchonMode = false;
	d3GameStatus.flagSkill01IsReadyToAndNeedAutoPress = false;
	d3GameStatus.flagSkill02IsReadyToAndNeedAutoPress = false;
	d3GameStatus.flagSkill03IsReadyToAndNeedAutoPress = false;
	d3GameStatus.flagSkill04IsReadyToAndNeedAutoPress = false;
#ifdef _DEBUG
	d3GameStatus.getStatusTime = 0;
	DWORD		startTime = GetTickCount();
#endif


	if (w32gdi.ValidMode())
	{
		w32gdi.CaptureDesktop();
		d3GameStatus.flagIsOpenMap = w32gdi.D3IsViewMap();
		d3GameStatus.flagIsOpenSkillTable = w32gdi.D3IsOpenSkillTable();
		d3GameStatus.flagIsOpenKadala = w32gdi.D3IsOpenKadala();
		d3GameStatus.flagIsOpenUrshi = w32gdi.D3IsOpenUrshi();
		d3GameStatus.flagIsOpenStash = w32gdi.D3IsOpenStash();
		//tọa độ cây kiếm 1155 1022
		//đứng im == 0x297EB1
		//đánh nhau == 0x16435E
		if (w32gdi.GetPixel(1155, 1022) == 0x297EB1 || d3GameStatus.flagIsOpenSkillTable) d3GameStatus.flagInAttackMode = false;

		//tọa độ bình máu
		//sẵn sàng 0x080808
		//cool down 0x020202
		if (w32gdi.GetPixel(1062, 1001) == 0x020202) d3GameStatus.flagPotionReady = false;




		//	//Skill02
		//	if (w32gdi.D3Skill02IsArchonSlowTimeAndReady())
		//	{
		//		d3GameStatus.flagSkill02IsReadyToAndNeedAutoPress = true;
		//		d3GameStatus.flagIsWizard = true;
		//	}
		//	else if (d3GameStatus.flagIsWizard == false && d3GameStatus.flagIsMonk == false && w32gdi.D3Skill02IsShadowPowerAndReady())
		//	{
		//		d3GameStatus.flagSkill02IsReadyToAndNeedAutoPress = true;
		//		d3GameStatus.flagIsDemonHunter = true;
		//	}


		if (w32gdi.D3Skill01KeyIs1()) d3GameStatus.skill01Key = '1';
		else if (w32gdi.D3Skill01KeyIsQ()) d3GameStatus.skill01Key = 'Q';

		if (w32gdi.D3Skill03KeyIs2()) d3GameStatus.skill02Key = '2';
		else if (w32gdi.D3Skill02KeyIsW()) d3GameStatus.skill02Key = 'W';

		if (w32gdi.D3Skill03KeyIs3()) d3GameStatus.skill03Key = '3';
		else if (w32gdi.D3Skill03KeyIsE()) d3GameStatus.skill03Key = 'E';

		if (w32gdi.D3Skill04KeyIs4()) d3GameStatus.skill04Key = '4';
		else if (w32gdi.D3Skill04KeyIsR()) d3GameStatus.skill04Key = 'R';


	}
#ifdef _DEBUG
	d3GameStatus.getStatusTime = GetTickCount() - startTime;
#endif
}
void		PreloadSalvageItem(int * preloadSalvageSlot, int preloadSalvageSlotSize)
{
	if (w32gdi.ValidMode())
	{
		w32gdi.CaptureDesktop();
		int			xIventoryArray[60] = { 1428 , 1428 , 1428 , 1428 , 1428 , 1428 , 1478 , 1478 , 1478 , 1478 , 1478 , 1478 , 1529 , 1529 , 1529 , 1529 , 1529 , 1529 , 1579 , 1579 , 1579 , 1579 , 1579 , 1579 , 1630 , 1630 , 1630 , 1630 , 1630 , 1630 , 1680 , 1680 , 1680 , 1680 , 1680 , 1680 , 1731 , 1731 , 1731 , 1731 , 1731 , 1731 , 1781 , 1781 , 1781 , 1781 , 1781 , 1781 , 1831 , 1831 , 1831 , 1831 , 1831 , 1831 , 1881 , 1881 , 1881 , 1881 , 1881 , 1881 };
		int			yIventoryArray[60] = { 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 };
		for (int ip = 0; ip < 60 && ip < preloadSalvageSlotSize; ip++)
		{
			int color1 = w32gdi.GetPixel(xIventoryArray[ip], yIventoryArray[ip]);
			int color2 = w32gdi.GetPixel(xIventoryArray[ip] + 1, yIventoryArray[ip] + 1);
			int color3 = w32gdi.GetPixel(xIventoryArray[ip] + 1, yIventoryArray[ip] - 1);
			int color4 = w32gdi.GetPixel(xIventoryArray[ip] - 1, yIventoryArray[ip] + 1);
			int color5 = w32gdi.GetPixel(xIventoryArray[ip] - 1, yIventoryArray[ip] - 1);

			if ((color1 == 0x80D10/* R16 G13 B8*/ || color1 == 0x80E10/* R16 G14 B8*/ || color1 == 0x80F10/* R16 G15 B8*/)
				&& (color2 == 0x80D10/* R16 G13 B8*/ || color2 == 0x80E10/* R16 G14 B8*/ || color2 == 0x80F10/* R16 G15 B8*/)
				&& (color3 == 0x80D10/* R16 G13 B8*/ || color3 == 0x80E10/* R16 G14 B8*/ || color3 == 0x80F10/* R16 G15 B8*/)
				&& (color4 == 0x80D10/* R16 G13 B8*/ || color4 == 0x80E10/* R16 G14 B8*/ || color4 == 0x80F10/* R16 G15 B8*/)
				&& (color5 == 0x80D10/* R16 G13 B8*/ || color5 == 0x80E10/* R16 G14 B8*/ || color5 == 0x80F10/* R16 G15 B8*/)
				)
			{
				preloadSalvageSlot[ip] = 0;
			}
		}
	}
}


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
DiabloIIIStatusStruct		diabloGameStatus;







/************************************************************************/
/* D3 Game status                                                       */
/************************************************************************/
void		GetCurrentDiabloIIStatus(void)
{
	/************************************************************************/
	/* Giá trị mặc định , cần để bảo đảm tool vẫn chạy trong trường hợp xấu */
	/************************************************************************/
	diabloGameStatus.flagInAttackMode = true;
	diabloGameStatus.flagPotionReady = true;
	diabloGameStatus.flagIsOpenMap = false;
	diabloGameStatus.flagIsOpenSkillTable = false;
	diabloGameStatus.flagIsOpenKadala = false;
	diabloGameStatus.flagIsOpenUrshi = false;
	diabloGameStatus.flagIsOpenStash = false;
	diabloGameStatus.flagSkill01IsReadyToAndNeedAutoPress = false;
	diabloGameStatus.flagSkill02IsReadyToAndNeedAutoPress = false;
	diabloGameStatus.flagSkill03IsReadyToAndNeedAutoPress = false;
	diabloGameStatus.flagSkill04IsReadyToAndNeedAutoPress = false;
#ifdef _DEBUG
	diabloGameStatus.getStatusTime = 0;
	DWORD		startTime = GetTickCount();
#endif


	if (w32gdi.ValidMode())
	{
		w32gdi.CaptureDesktop();
		diabloGameStatus.flagIsOpenMap = w32gdi.D3IsViewMap();
		diabloGameStatus.flagIsOpenSkillTable = w32gdi.D3IsOpenSkillTable();
		diabloGameStatus.flagIsOpenKadala = w32gdi.D3IsOpenKadala();
		diabloGameStatus.flagIsOpenUrshi = w32gdi.D3IsOpenUrshi();
		diabloGameStatus.flagIsOpenStash = w32gdi.D3IsOpenStash();


		//tọa độ cây kiếm 1155 1022
		//đứng im == 0x297EB1
		//đánh nhau == 0x16435E
		if (w32gdi.GetPixel(1155, 1022) == 0x297EB1 || diabloGameStatus.flagIsOpenSkillTable) diabloGameStatus.flagInAttackMode = false;

		//tọa độ bình máu
		//sẵn sàng 0x080808
		//cool down 0x020202
		if (w32gdi.GetPixel(1062, 1001) == 0x020202) diabloGameStatus.flagPotionReady = false;




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


		if (w32gdi.D3Skill01KeyIs1()) diabloGameStatus.skill01Key = '1';
		else if (w32gdi.D3Skill01KeyIsQ()) diabloGameStatus.skill01Key = 'Q';

		if (w32gdi.D3Skill03KeyIs2()) diabloGameStatus.skill02Key = '2';
		else if (w32gdi.D3Skill02KeyIsW()) diabloGameStatus.skill02Key = 'W';

		if (w32gdi.D3Skill03KeyIs3()) diabloGameStatus.skill03Key = '3';
		else if (w32gdi.D3Skill03KeyIsE()) diabloGameStatus.skill03Key = 'E';

		if (w32gdi.D3Skill04KeyIs4()) diabloGameStatus.skill04Key = '4';
		else if (w32gdi.D3Skill04KeyIsR()) diabloGameStatus.skill04Key = 'R';


	}
#ifdef _DEBUG
	diabloGameStatus.getStatusTime = GetTickCount() - startTime;
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























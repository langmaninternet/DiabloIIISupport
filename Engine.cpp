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




D3Engine					d3Engine;







/************************************************************************/
/* D3 Game status                                                       */
/************************************************************************/
void		PreloadSalvageItem(int* preloadSalvageSlot, int preloadSalvageSlotSize)
{
	if (d3Engine.ValidMode())
	{
		d3Engine.CaptureDesktop();
		int			xInventoryArray[60] = { 1428 , 1428 , 1428 , 1428 , 1428 , 1428 , 1478 , 1478 , 1478 , 1478 , 1478 , 1478 , 1529 , 1529 , 1529 , 1529 , 1529 , 1529 , 1579 , 1579 , 1579 , 1579 , 1579 , 1579 , 1630 , 1630 , 1630 , 1630 , 1630 , 1630 , 1680 , 1680 , 1680 , 1680 , 1680 , 1680 , 1731 , 1731 , 1731 , 1731 , 1731 , 1731 , 1781 , 1781 , 1781 , 1781 , 1781 , 1781 , 1831 , 1831 , 1831 , 1831 , 1831 , 1831 , 1881 , 1881 , 1881 , 1881 , 1881 , 1881 };
		int			yInventoryArray[60] = { 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 , 584 , 634 , 684 , 734 , 784 , 833 };


		int			xOffsetItemInventoryArray[60] = {
			/*cột 01*/ 0 , 0 , 0 , 0 , 0 , 0 ,
			/*cột 02*/ 50 , 50 , 50 , 50 , 50 , 50 ,
			/*cột 03*/ 100 , 100 , 100 , 100 , 100 , 100 ,
			/*cột 04*/ 150 , 150 , 150 , 150 , 150 , 150 ,
			/*cột 05*/ 200 , 200 , 200 , 200 , 200 , 200 ,
			/*cột 06*/ 250 , 250 , 250 , 250 , 250 , 250 ,
			/*cột 07*/ 300 , 300 , 300 , 300 , 300 , 300 ,
			/*cột 08*/ 350 , 350 , 350 , 350 , 350 , 350 ,
			/*cột 09*/ 400 , 400 , 400 , 400 , 400 , 400 ,
			/*cột 10*/ 450 , 450 , 450 , 450 , 450 , 450 };

		int			yOffsetItemInventoryArray[60] = {
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 ,
			0 , 50 , 100 , 150 , 200 , 250 };

		if (d3Engine.D3IsOpenStash())
		{
			for (int ip = 0; ip < 60 && ip < preloadSalvageSlotSize; ip++)
			{

				int color1 = d3Engine.GetPixel(xInventoryArray[ip], yInventoryArray[ip]);
				int color2 = d3Engine.GetPixel(xInventoryArray[ip] + 1, yInventoryArray[ip] + 1);
				int color3 = d3Engine.GetPixel(xInventoryArray[ip] + 1, yInventoryArray[ip] - 1);
				int color4 = d3Engine.GetPixel(xInventoryArray[ip] - 1, yInventoryArray[ip] + 1);
				int color5 = d3Engine.GetPixel(xInventoryArray[ip] - 1, yInventoryArray[ip] - 1);

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
		else
		{

			for (int ip = 0; ip < 60 && ip < preloadSalvageSlotSize; ip++)
			{
				int color1 = d3Engine.GetPixel(xInventoryArray[ip], yInventoryArray[ip]);
				int color2 = d3Engine.GetPixel(xInventoryArray[ip] + 1, yInventoryArray[ip] + 1);
				int color3 = d3Engine.GetPixel(xInventoryArray[ip] + 1, yInventoryArray[ip] - 1);
				int color4 = d3Engine.GetPixel(xInventoryArray[ip] - 1, yInventoryArray[ip] + 1);
				int color5 = d3Engine.GetPixel(xInventoryArray[ip] - 1, yInventoryArray[ip] - 1);

				if ((color1 == 0x80D10/* R16 G13 B8*/ || color1 == 0x80E10/* R16 G14 B8*/ || color1 == 0x80F10/* R16 G15 B8*/)
					&& (color2 == 0x80D10/* R16 G13 B8*/ || color2 == 0x80E10/* R16 G14 B8*/ || color2 == 0x80F10/* R16 G15 B8*/)
					&& (color3 == 0x80D10/* R16 G13 B8*/ || color3 == 0x80E10/* R16 G14 B8*/ || color3 == 0x80F10/* R16 G15 B8*/)
					&& (color4 == 0x80D10/* R16 G13 B8*/ || color4 == 0x80E10/* R16 G14 B8*/ || color4 == 0x80F10/* R16 G15 B8*/)
					&& (color5 == 0x80D10/* R16 G13 B8*/ || color5 == 0x80E10/* R16 G14 B8*/ || color5 == 0x80F10/* R16 G15 B8*/)
					)
				{
					preloadSalvageSlot[ip] = 0;
				}
				else if (d3Engine.ItemSlotIsMarquiseRuby(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])
					|| d3Engine.ItemSlotIsMarquiseDiamond(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])
					|| d3Engine.ItemSlotIsMarquiseAmethyst(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])
					|| d3Engine.ItemSlotIsMarquiseTopaz(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])
					|| d3Engine.ItemSlotIsMarquiseEmerald(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])

					|| d3Engine.ItemSlotIsImperialRuby(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])
					|| d3Engine.ItemSlotIsImperialDiamond(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])

					|| d3Engine.ItemSlotIsWhisperOfAtonement(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])
					|| d3Engine.ItemSlotIsRamaladinGift(xOffsetItemInventoryArray[ip], yOffsetItemInventoryArray[ip])
					)
				{
					preloadSalvageSlot[ip] = 0;
				}
				else
				{
					for (int xoffset = -10; xoffset <= 10; xoffset++)
					{
						for (int yoffset = -10; yoffset <= 10; yoffset++)
						{
							if (d3Engine.ItemSlotIsWhisperOfAtonement(xoffset + xOffsetItemInventoryArray[ip], yoffset + yOffsetItemInventoryArray[ip]))
							{
								preloadSalvageSlot[ip] = 0;
							}
						}
					}
				}
			}
		}
	}
}







/************************************************************************/
/*                                                                      */
/************************************************************************/






//skill 01 635  1004 - Half 681 1029 
//skill 02 702  1004 - Half 748 1029 
//skill 03 768  1004 - Half 814 1029 
//skill 04 834  1003 - Half 881 1029





//left     905  1006 - Half 951 1030
//right    970  1006 - Half 1016 1030




//left     905  1006 - Half 951 1030
//right    970  1006 - Half 1016 1030

//Critical Hit Damage - 100% : 319 - 371
//Critical Hit Damage - xx% : 318 - 362
// 
//Critical Hit Chance - xx% : 313 - 348
//Critical Hit Chance - a.b% : 313 - 348
// 
// 
//Reduce melee damage - x% : 368 - 403


const int				rol_01_x_left = 318;
const int				rol_01_y_top = 388/*Fixed*/;
const int				rol_01_x_right = 362;
const int				rol_01_y_bottom = 399/*Fixed*/;


const int				rol_02_x_left = 313;
const int				rol_02_y_top = 432/*Fixed*/;
const int				rol_02_x_right = 348;
const int				rol_02_y_bottom = 445/*Fixed*/;


const int				rol_03_x_left = 318;
const int				rol_03_y_top = 476/*Fixed*/;
const int				rol_03_x_right = 362;
const int				rol_03_y_bottom = 486/*Fixed*/;


const char* RollOption01FilePath = "D:\\DumpRollItem01.txt";
const char* RollOption02FilePath = "D:\\DumpRollItem02.txt";
const char* RollOption03FilePath = "D:\\DumpRollItem03.txt";
const char* logDumpImageFolder = "D:\\DumpImage\\";






void		SendD3LeftMouseClick();
void		SetD3Mouse(int x, int y);

#ifdef DEBUG
void		CaptureInventory(void)
{

	int			d3WidthScale = 1;
	int			d3HeightScale = 1;
	int			xInventoryArray[60] = { int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1428 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1478 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1529 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1579 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1630 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1680 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1731 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1781 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1831 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale), int(1881 * d3WidthScale) };
	int			yInventoryArray[60] = { int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale), int(584 * d3HeightScale), int(634 * d3HeightScale), int(684 * d3HeightScale), int(734 * d3HeightScale), int(784 * d3HeightScale), int(833 * d3HeightScale) };



	bool flag_shoot_all_in_one = 0;


	if (flag_shoot_all_in_one)
	{
		for (int item = 0; item < 60; item++)
		{
			char bufferPrefix[10] = {};
			sprintf_s(bufferPrefix, "%d", item);
			d3Engine.DumpRectangle(
				1407 + xOffsetItemInventoryArray[item],
				563 + yOffsetItemInventoryArray[item],
				1449 + xOffsetItemInventoryArray[item],
				594 + yOffsetItemInventoryArray[item],
				bufferPrefix);
		}
		SetD3Mouse(1200, 600);
	}
	else
	{
		bool		IsD3WindowActive(void);
		SetD3Mouse(1000, 500);
		d3Engine.DumpRectangle(
			1407 + xOffsetItemInventoryArray[0],
			563 + yOffsetItemInventoryArray[0],
			1449 + xOffsetItemInventoryArray[0],
			594 + yOffsetItemInventoryArray[0],
			"0");

		for (int item = 1; item < 60 && IsD3WindowActive(); item++)
		{
			SetD3Mouse(xInventoryArray[item - 1], yInventoryArray[item - 1]);
			Sleep(100 + (rand() % 5));
			SendD3LeftMouseClick();
			Sleep(100 + (rand() % 5));
			SetD3Mouse(xInventoryArray[item], yInventoryArray[item]);
			Sleep(100 + (rand() % 5));
			SendD3LeftMouseClick();
			Sleep(100 + (rand() % 5));
			SetD3Mouse(1000, 500);
			Sleep(200 + (rand() % 5));

			char bufferPrefix[10] = {};
			sprintf_s(bufferPrefix, "%d", item);
			d3Engine.DumpRectangle(
				1407 + xOffsetItemInventoryArray[item],
				563 + yOffsetItemInventoryArray[item],
				1449 + xOffsetItemInventoryArray[item],
				594 + yOffsetItemInventoryArray[item],
				bufferPrefix);
		}
	}
}
#endif

void		QuangBTDumpScreen(void)
{
#ifdef DEBUG



	d3Engine.CaptureDesktop();

	d3Engine.SaveScreen();

	FILE* p = fopen("D:\\abc.txt", "w");
	if (p)
	{
		for (int i = 0; i < 60; i++)
		{
			fprintf(p,"/*Item %d*/{%d,%d},\n ",i+1, 1407 + xOffsetItemInventoryArray[i], 563 + yOffsetItemInventoryArray[i]);
		}
	}
	fclose(p);



	static bool needCleanFolder = true;
	if (needCleanFolder)
	{
		std::wstring		wFolder = L"D:\\DumpImage";
		if (wFolder.size() && wFolder[wFolder.size() - 1] != L'\\') wFolder += L'\\';
		wFolder += L"*.bmp";
		WIN32_FIND_DATAW		fd;
		HANDLE hFind = FindFirstFileW(wFolder.c_str(), &fd);
		if (hFind == INVALID_HANDLE_VALUE) {};
		do
		{
			if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{//là thư mục
			}
			else
			{//là file
				std::wstring filePath = L"D:\\DumpImage";
				if (filePath.size() && filePath[filePath.size() - 1] != L'\\') filePath += L'\\';
				filePath += fd.cFileName;
				DeleteFileW(filePath.c_str());
			}
		} while (FindNextFileW(hFind, &fd));
		FindClose(hFind);

		needCleanFolder = false;
	}

	//left     905  1006 - Half 951 1030
	//right    970  1006 - Half 1016 1030



	d3Engine.DumpSkill01();
	d3Engine.DumpSkill02();
	d3Engine.DumpSkill03();
	d3Engine.DumpSkill04();

	//d3Engine.DumpRollOption01();
	//d3Engine.DumpRollOption02();
	//d3Engine.DumpRollOption03();

	//CaptureInventory();


	d3Engine.DumpRectangle(1030, 998, 1059, 1003);

	// item slot 01
	//d3Engine.DumpRectangle(1407, 563, 1449, 594);


	//d3Engine.DumpRectangle(1458, 563, 1498, 594);

	//d3Engine.DumpRectangle(171, 776, 282, 785);

#endif // DEBUG

}






/************************************************************************/
/*                                                                      */
/************************************************************************/
/*Constructor*/		D3Engine::D3Engine(void)
{
	hBitmap = NULL;
	hScreenMemDC = NULL;
	rectDesktop = { 0 };
	HWND		hDesktop = GetDesktopWindow();
	HDC			hdcDesktop = GetWindowDC(hDesktop);
	if (hdcDesktop != NULL)
	{
		GetWindowRect(hDesktop, &rectDesktop);
		hScreenMemDC = CreateCompatibleDC(hdcDesktop);
		if (hScreenMemDC != NULL)
		{
			hBitmap = CreateCompatibleBitmap(hdcDesktop, rectDesktop.right, rectDesktop.bottom);
			if (hBitmap != NULL)
			{
				SelectObject(hScreenMemDC, hBitmap);
			}
			else
			{
				DeleteDC(hScreenMemDC);
				hScreenMemDC = NULL;
			}
		}
		ReleaseDC(hDesktop, hdcDesktop);
	}
}
void				D3Engine::CaptureDesktop(void)
{
	HWND		hDesktop = GetDesktopWindow();
	HDC			hdcDesktop = GetWindowDC(hDesktop);
	BitBlt(hScreenMemDC, 0, 0, rectDesktop.right, rectDesktop.bottom, hdcDesktop, 0, 0, SRCCOPY);
	ReleaseDC(hDesktop, hdcDesktop);
#ifdef _DEBUG
	SetTextColor(hScreenMemDC, RGB(0xFF, 0xFF, 0xFF));
	SetBkMode(hScreenMemDC, TRANSPARENT);
	for (int i = 0; i < 60; i++)
	{
		SetPixel(hScreenMemDC, left_top_Inventory[i].x, left_top_Inventory[i].y, 0x00FFFFFF);
		RECT  rect;
		rect.left = left_top_Inventory[i].x+10;
		rect.top = left_top_Inventory[i].y+10;
		wchar_t buffer[100] = { 0 };
		swprintf(buffer, L"%d", i + 1);
		DrawText(hScreenMemDC, buffer, -1, &rect, DT_SINGLELINE | DT_NOCLIP);
	}
#endif // _DEBUG
}
int					D3Engine::GetPixel(int x, int y)
{
	if (hScreenMemDC != NULL)
	{
		int color = int(::GetPixel(hScreenMemDC, x, y));
		return color;
	}
	return 0;
}
bool				D3Engine::ValidMode(void)
{
	HWND	d3Wnd = FindWindowW(L"D3 Main Window Class", L"Diablo III");
	RECT	d3rect;
	GetClientRect(d3Wnd, &d3rect);

	return (hScreenMemDC != NULL
		&& d3rect.top == 0
		&& d3rect.left == 0
		&& d3rect.right == 1920
		&& d3rect.bottom == 1080
		);
}
/*Destructor*/		D3Engine::~D3Engine()
{
	if (hBitmap != NULL) DeleteObject(hBitmap);
	if (hScreenMemDC != NULL) DeleteDC(hScreenMemDC);
}



/************************************************************************/
/* Debug                                                                */
/************************************************************************/
#ifdef _DEBUG
bool				IsD3WindowActive(void);
#include "../DiabloIIICore/GDI/SaveScreen.cpp"
#include "../DiabloIIICore/GDI/DumpRectangle.cpp"
#include "../DiabloIIICore/GDI/DumpSkill.cpp"
#include "../DiabloIIICore/GDI/DumpRollOption.cpp"
#endif









#ifdef PREMIUM_FEATURE
#include "../DiabloIIICore/Roll/Roll.cpp"
#include "../DiabloIIICore/Item/Inventory.cpp"
#endif







#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64) 
#pragma managed(push, off)
#pragma optimize("", off)
#pragma warning(push)
#pragma warning(disable : 4100)
#else
#pragma GCC push_options
#pragma GCC optimize ("O0")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif


#include "../DiabloIIITemp/Diablo3RolDataCode"
#include "../DiabloIIITemp/Diablo3ScreenDataCode"
#include "../DiabloIIITemp/Diablo3Roll"
#include "../DiabloIIITemp/Diablo3Salvage"



#ifdef PREMIUM_FEATURE
#include "../DiabloIIICore/Game/Battle"
#include "../DiabloIIICore/Game/Potion"
#include "../DiabloIIICore/Skill/Necromancer"
#include "../DiabloIIICore/Skill/DemonHunter"
#include "../DiabloIIICore/Roll/CriticalHit"
#include "../DiabloIIICore/Roll/ElementDamage"
#include "../DiabloIIICore/Roll/AttackSpeed"
#include "../DiabloIIICore/Roll/Cooldown"
#include "../DiabloIIICore/Roll/ResourceCost"
#include "../DiabloIIICore/Roll/AreaDamage"
#include "../DiabloIIICore/Roll/ReduceDamage"
#include "../DiabloIIICore/Roll/BaseDamage"
#include "../DiabloIIICore/Roll/LifePercent"
#include "../DiabloIIICore/Roll/LifePerHit"
#include "../DiabloIIICore/Roll/LifePerSecond"
#include "../DiabloIIICore/Roll/LifePerKill"
#include "../DiabloIIICore/Roll/Resistance"
#include "../DiabloIIICore/Roll/Socket"
#include "../DiabloIIICore/Roll/Stats"
#include "../DiabloIIICore/Roll/MovementSpeed"
#include "../DiabloIIICore/Roll/Thorn"
#include "../DiabloIIICore/Roll/DemonHunter"
#include "../DiabloIIICore/Roll/Digit"
#endif

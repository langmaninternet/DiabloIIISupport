﻿#include "stdafx.h"
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
#endif

void		QuangBTDumpScreen(void)
{
#ifdef DEBUG
	d3Engine.CaptureDesktop();
	d3Engine.SaveScreen();



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

	d3Engine.DumpRollItem();


			//	d3Engine.DumpSkill01();
			//	d3Engine.DumpSkill02();
			//	d3Engine.DumpSkill03();
			//	d3Engine.DumpSkill04();

	//d3Engine.DumpRollOption01();
	//d3Engine.DumpRollOption02();
	//d3Engine.DumpRollOption03();

	//CaptureInventory();

	//d3Engine.DumpInventoryItemWithUnderLine();
	//d3Engine.DumpFiveZombieDog();

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
#include "../DiabloIIICore/GDI/DumpInventory.cpp"
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



#ifdef PREMIUM_FEATURE
#include "../DiabloIIICore/Game/Battle"
#include "../DiabloIIICore/Game/Potion"
#include "../DiabloIIICore/Game/Spirit"
#include "../DiabloIIICore/Item/Salvage"
#include "../DiabloIIICore/Skill/Necromancer"
#include "../DiabloIIICore/Skill/DemonHunter"
#include "../DiabloIIICore/Skill/Monk"
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

#include "stdafx.h"
#include <Wingdi.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <list>
#include "Engine.h"



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



// Khung rol đồ : 
// ô 1: 80 380 430 400
// ô 2: 80 430 430 450
// ô 3: 80 480 430 500

//12_MaxDiscipline

const int				rol_01_x_left = 90;
const int				rol_01_y_top = 387;
const int				rol_01_x_right = 254;
const int				rol_01_y_bottom = 399;

const int				rol_02_x_left = 90;
const int				rol_02_y_top = 432;
const int				rol_02_x_right = 253;
const int				rol_02_y_bottom = 443;


const int				rol_03_x_left = 126;
const int				rol_03_y_top = 477;
const int				rol_03_x_right = 198;
const int				rol_03_y_bottom = 488;


extern Win32GDI w32gdi;
void		QuangBTDumpScreen(void)
{
	w32gdi.CaptureDesktop();
	w32gdi.SaveScreen();


	//left     905  1006 - Half 951 1030
	//right    970  1006 - Half 1016 1030


	//w32gdi.DumpSkill02();
	//w32gdi.DumpSkill03();
	//w32gdi.DumpSkill04();



	//w32gdi.DumpRollItem01();
	w32gdi.DumpRollItem02();
	w32gdi.DumpRollItem03();
}






/************************************************************************/
/*                                                                      */
/************************************************************************/
/*Constructor*/		Win32GDI::Win32GDI(void)
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
void				Win32GDI::CaptureDesktop(void)
{
	HWND		hDesktop = GetDesktopWindow();
	HDC			hdcDesktop = GetWindowDC(hDesktop);
	BitBlt(hScreenMemDC, 0, 0, rectDesktop.right, rectDesktop.bottom, hdcDesktop, 0, 0, SRCCOPY);
	ReleaseDC(hDesktop, hdcDesktop);


	//Blur skill 1 and key
	BlurRectangle(635, 1004, 681, 1029);
	BlurRectangle(657, 1062, 662, 1072);


	//Blur skill 2 and key
	BlurRectangle(702, 1004, 748, 1029);
	BlurRectangle(722, 1062, 729, 1072);


	//Blur skill 3 and key
	BlurRectangle(768, 1004, 814, 1029);
	BlurRectangle(789, 1062, 796, 1072);


	//Blur skill 4 and key
	BlurRectangle(834, 1003, 881, 1029);
	BlurRectangle(856, 1063, 863, 1073);


}
void				Win32GDI::BlurRectangle(int xleft, int ytop, int xright, int ybottom)
{
	static const int			blur_coefficient = 32;
	for (int ix = xleft; ix < xright; ix++)
	{
		for (int iy = ytop; iy < ybottom; iy++)
		{
			//	int color = ::GetPixel(hScreenMemDC, ix, iy);
			//	int color_r = GetRValue(color);
			//	int color_g = GetGValue(color);
			//	int color_b = GetBValue(color);
			//	color_r -= color_r % blur_coefficient;
			//	color_g -= color_g % blur_coefficient;
			//	color_b -= color_b % blur_coefficient;
			//	::SetPixel(hScreenMemDC, ix, iy, RGB(color_r, color_g, color_b));

			int color = ::GetPixel(hScreenMemDC, ix, iy);
			color &= 0xE0E0E0;
			::SetPixel(hScreenMemDC, ix, iy, color);

		}
	}
}
int					Win32GDI::GetPixel(int x, int y)
{
	if (hScreenMemDC != NULL)
	{
		int color = int(::GetPixel(hScreenMemDC, x, y));
		return color;
	}
	return 0;
}
bool				Win32GDI::ValidMode(void)
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
/*Desstructor*/		Win32GDI::~Win32GDI()
{
	if (hBitmap != NULL) DeleteObject(hBitmap);
	if (hScreenMemDC != NULL) DeleteDC(hScreenMemDC);
}




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

bool				Win32GDI::D3IsViewMap(void)
{

	int color = 0;
	if (GetPixel(1869, 373) != 0X30712) return false;
	if (GetPixel(1869, 374) != 0X30712) return false;
	if (GetPixel(1870, 373) != 0X30D) return false;
	if (GetPixel(1870, 385) != 0X412) return false;
	if (GetPixel(1871, 372) != 0X20C) return false;
	if (GetPixel(1871, 383) != 0X412) return false;
	color = GetPixel(1869, 371); if (color != 0X40710 && color != 0X60913) return false;
	color = GetPixel(1869, 372); if (color != 0X30610 && color != 0X30611) return false;
	color = GetPixel(1869, 375); if (color != 0X30611 && color != 0X30713) return false;
	color = GetPixel(1869, 376); if (color != 0X30610 && color != 0X30714) return false;
	color = GetPixel(1869, 377); if (color != 0X30610 && color != 0X30714) return false;
	color = GetPixel(1869, 378); if (color != 0X30610 && color != 0X30714) return false;
	color = GetPixel(1869, 379); if (color != 0X30610 && color != 0X30816) return false;
	color = GetPixel(1869, 380); if (color != 0X30610 && color != 0X30816) return false;
	color = GetPixel(1869, 381); if (color != 0X30610 && color != 0X30816) return false;
	color = GetPixel(1869, 382); if (color != 0X30712 && color != 0X30714) return false;
	color = GetPixel(1869, 383); if (color != 0X30713 && color != 0X30714) return false;
	color = GetPixel(1869, 384); if (color != 0X30713 && color != 0X30714) return false;
	color = GetPixel(1869, 385); if (color != 0X30714 && color != 0X30815) return false;
	color = GetPixel(1870, 371); if (color != 0X3040D && color != 0X3050E) return false;
	color = GetPixel(1870, 372); if (color != 0X20B && color != 0X20C) return false;
	color = GetPixel(1870, 374); if (color != 0X30D && color != 0X30E) return false;
	color = GetPixel(1870, 375); if (color != 0X30D && color != 0X310) return false;
	color = GetPixel(1870, 376); if (color != 0X20C && color != 0X314) return false;
	color = GetPixel(1870, 377); if (color != 0X20C && color != 0X314) return false;
	color = GetPixel(1870, 378); if (color != 0X20C && color != 0X314) return false;
	color = GetPixel(1870, 379); if (color != 0X20E && color != 0X20518) return false;
	color = GetPixel(1870, 380); if (color != 0X20E && color != 0X20518) return false;
	color = GetPixel(1870, 381); if (color != 0X20E && color != 0X20518) return false;
	color = GetPixel(1870, 382); if (color != 0X30F && color != 0X10415) return false;
	color = GetPixel(1870, 383); if (color != 0X30F && color != 0X411) return false;
	color = GetPixel(1870, 384); if (color != 0X310 && color != 0X412) return false;
	color = GetPixel(1871, 371); if (color != 0X3040D && color != 0X3050E) return false;
	color = GetPixel(1871, 373); if (color != 0X30D && color != 0X30E) return false;
	color = GetPixel(1871, 374); if (color != 0X40E && color != 0X410) return false;
	color = GetPixel(1871, 375); if (color != 0X30F && color != 0X20512) return false;
	color = GetPixel(1871, 376); if (color != 0X311 && color != 0XA1121) return false;
	color = GetPixel(1871, 377); if (color != 0X312 && color != 0XE1726) return false;
	color = GetPixel(1871, 378); if (color != 0X313 && color != 0XE1726) return false;
	color = GetPixel(1871, 379); if (color != 0X315 && color != 0XA1020) return false;
	color = GetPixel(1871, 380); if (color != 0X315 && color != 0XC1222) return false;
	color = GetPixel(1871, 381); if (color != 0X313 && color != 0X101725) return false;
	color = GetPixel(1871, 382); if (color != 0X312 && color != 0X40918) return false;
	color = GetPixel(1871, 384); if (color != 0X411 && color != 0X513) return false;
	color = GetPixel(1871, 385); if (color != 0X411 && color != 0X412) return false;
	color = GetPixel(1872, 371); if (color != 0X3040D && color != 0X3050E) return false;
	color = GetPixel(1872, 372); if (color != 0X20C && color != 0X30D) return false;
	color = GetPixel(1872, 373); if (color != 0X30E && color != 0X410) return false;
	color = GetPixel(1872, 374); if (color != 0X40E && color != 0X410) return false;
	color = GetPixel(1872, 375); if (color != 0X410 && color != 0X10412) return false;
	color = GetPixel(1872, 376); if (color != 0X311 && color != 0X80E1E) return false;
	color = GetPixel(1872, 377); if (color != 0X312 && color != 0X192633) return false;
	color = GetPixel(1872, 378); if (color != 0X416 && color != 0X202F3C) return false;
	color = GetPixel(1872, 379); if (color != 0X418 && color != 0X243339) return false;
	color = GetPixel(1872, 380); if (color != 0X417 && color != 0X212E35) return false;
	color = GetPixel(1872, 381); if (color != 0X311 && color != 0XE1524) return false;
	color = GetPixel(1872, 382); if (color != 0X412 && color != 0X20717) return false;
	color = GetPixel(1872, 383); if (color != 0X411 && color != 0X513) return false;
	color = GetPixel(1872, 384); if (color != 0X512 && color != 0X513) return false;
	color = GetPixel(1872, 385); if (color != 0X413 && color != 0X512) return false;
	color = GetPixel(1873, 371); if (color != 0X20510 && color != 0X3040D) return false;
	color = GetPixel(1873, 372); if (color != 0X20D && color != 0X314) return false;
	color = GetPixel(1873, 373); if (color != 0X315 && color != 0X40F) return false;
	color = GetPixel(1873, 374); if (color != 0X315 && color != 0X510) return false;
	color = GetPixel(1873, 375); if (color != 0X311 && color != 0X31A) return false;
	color = GetPixel(1873, 376); if (color != 0X427 && color != 0XC1527) return false;
	color = GetPixel(1873, 377); if (color != 0XA102E && color != 0X182631) return false;
	color = GetPixel(1873, 378); if (color != 0XF182A && color != 0X202F3D) return false;
	color = GetPixel(1873, 379); if (color != 0XC1329 && color != 0X25373F) return false;
	color = GetPixel(1873, 380); if (color != 0X162236 && color != 0X182431) return false;
	color = GetPixel(1873, 381); if (color != 0X1052A && color != 0X182431) return false;
	color = GetPixel(1873, 382); if (color != 0X420 && color != 0XA111D) return false;
	color = GetPixel(1873, 383); if (color != 0X310 && color != 0X41A) return false;
	color = GetPixel(1873, 384); if (color != 0X41A && color != 0X512) return false;
	color = GetPixel(1873, 385); if (color != 0X419 && color != 0X614) return false;
	color = GetPixel(1874, 371); if (color != 0X20510 && color != 0X3040D) return false;
	color = GetPixel(1874, 372); if (color != 0X20D && color != 0X10414) return false;
	color = GetPixel(1874, 373); if (color != 0X20E && color != 0X80D20) return false;
	color = GetPixel(1874, 374); if (color != 0X316 && color != 0X40F) return false;
	color = GetPixel(1874, 375); if (color != 0X31B && color != 0X513) return false;
	color = GetPixel(1874, 376); if (color != 0X429 && color != 0X20821) return false;
	color = GetPixel(1874, 377); if (color != 0X70D2D && color != 0X121D2D) return false;
	color = GetPixel(1874, 378); if (color != 0X202F3C && color != 0X26373D) return false;
	color = GetPixel(1874, 379); if (color != 0X25363F && color != 0X29393F) return false;
	color = GetPixel(1874, 380); if (color != 0X142036 && color != 0X23323B) return false;
	color = GetPixel(1874, 381); if (color != 0X42B && color != 0X80E27) return false;
	color = GetPixel(1874, 382); if (color != 0X418 && color != 0X421) return false;
	color = GetPixel(1874, 383); if (color != 0X41A && color != 0X512) return false;
	color = GetPixel(1874, 384); if (color != 0X512 && color != 0XA1125) return false;
	color = GetPixel(1874, 385); if (color != 0X41A && color != 0X512) return false;
	color = GetPixel(1875, 371); if (color != 0X20510 && color != 0X3040D) return false;
	color = GetPixel(1875, 372); if (color != 0X20D && color != 0X10414) return false;
	color = GetPixel(1875, 373); if (color != 0X30E && color != 0X172132) return false;
	color = GetPixel(1875, 374); if (color != 0X40F && color != 0XB1124) return false;
	color = GetPixel(1875, 375); if (color != 0X514 && color != 0X1051C) return false;
	color = GetPixel(1875, 376); if (color != 0X2062A && color != 0X20821) return false;
	color = GetPixel(1875, 377); if (color != 0X20821 && color != 0X80E2E) return false;
	color = GetPixel(1875, 378); if (color != 0X202F3C && color != 0X213039) return false;
	color = GetPixel(1875, 379); if (color != 0X25363F && color != 0X29393F) return false;
	color = GetPixel(1875, 380); if (color != 0X142036 && color != 0X162231) return false;
	color = GetPixel(1875, 381); if (color != 0X421 && color != 0X2062C) return false;
	color = GetPixel(1875, 382); if (color != 0X519 && color != 0X20623) return false;
	color = GetPixel(1875, 383); if (color != 0X513 && color != 0X2061C) return false;
	color = GetPixel(1875, 384); if (color != 0X512 && color != 0X1D2A3A) return false;
	color = GetPixel(1875, 385); if (color != 0X513 && color != 0X80D21) return false;
	color = GetPixel(1876, 371); if (color != 0X20511 && color != 0X3040D) return false;
	color = GetPixel(1876, 372); if (color != 0X20C && color != 0X10316) return false;
	color = GetPixel(1876, 373); if (color != 0X40F && color != 0X162132) return false;
	color = GetPixel(1876, 374); if (color != 0X30E && color != 0X1D2A39) return false;
	color = GetPixel(1876, 375); if (color != 0X413 && color != 0X121B2C) return false;
	color = GetPixel(1876, 376); if (color != 0X10620 && color != 0X131E35) return false;
	color = GetPixel(1876, 377); if (color != 0X40922 && color != 0X131E35) return false;
	color = GetPixel(1876, 378); if (color != 0X21303A && color != 0X21313D) return false;
	color = GetPixel(1876, 379); if (color != 0X25363F && color != 0X29393F) return false;
	color = GetPixel(1876, 380); if (color != 0X162231 && color != 0X1A2839) return false;
	color = GetPixel(1876, 381); if (color != 0X421 && color != 0X131E35) return false;
	color = GetPixel(1876, 382); if (color != 0X418 && color != 0X131C31) return false;
	color = GetPixel(1876, 383); if (color != 0X410 && color != 0X121B2D) return false;
	color = GetPixel(1876, 384); if (color != 0X412 && color != 0X202D3C) return false;
	color = GetPixel(1876, 385); if (color != 0X514 && color != 0X1051C) return false;
	color = GetPixel(1877, 371); if (color != 0X20512 && color != 0X3040D) return false;
	color = GetPixel(1877, 372); if (color != 0X20C && color != 0X10219) return false;
	color = GetPixel(1877, 373); if (color != 0X40E && color != 0X162130) return false;
	color = GetPixel(1877, 374); if (color != 0X30D && color != 0X27373F) return false;
	color = GetPixel(1877, 375); if (color != 0X412 && color != 0X26373F) return false;
	color = GetPixel(1877, 376); if (color != 0X31E && color != 0X25363F) return false;
	color = GetPixel(1877, 377); if (color != 0X70D25 && color != 0X25363F) return false;
	color = GetPixel(1877, 378); if (color != 0X202E3B && color != 0X25363F) return false;
	color = GetPixel(1877, 379); if (color != 0X25353F && color != 0X293A3F) return false;
	color = GetPixel(1877, 380); if (color != 0X162231 && color != 0X25353F) return false;
	color = GetPixel(1877, 381); if (color != 0X421 && color != 0X25353F) return false;
	color = GetPixel(1877, 382); if (color != 0X418 && color != 0X25353F) return false;
	color = GetPixel(1877, 383); if (color != 0X410 && color != 0X25343F) return false;
	color = GetPixel(1877, 384); if (color != 0X411 && color != 0X25343F) return false;
	color = GetPixel(1877, 385); if (color != 0X513 && color != 0X20623) return false;
	color = GetPixel(1878, 371); if (color != 0X20512 && color != 0X3040D) return false;
	color = GetPixel(1878, 372); if (color != 0X20C && color != 0X10219) return false;
	color = GetPixel(1878, 373); if (color != 0X30D && color != 0X162130) return false;
	color = GetPixel(1878, 374); if (color != 0X30D && color != 0X26373F) return false;
	color = GetPixel(1878, 375); if (color != 0X412 && color != 0X1F2D3A) return false;
	color = GetPixel(1878, 376); if (color != 0X31E && color != 0X1E2D3D) return false;
	color = GetPixel(1878, 377); if (color != 0X70D25 && color != 0X1E2D3D) return false;
	color = GetPixel(1878, 378); if (color != 0X202E3B && color != 0X23343F) return false;
	color = GetPixel(1878, 379); if (color != 0X25353F && color != 0X293A3F) return false;
	color = GetPixel(1878, 380); if (color != 0X162231 && color != 0X23333F) return false;
	color = GetPixel(1878, 381); if (color != 0X421 && color != 0X1E2C3D) return false;
	color = GetPixel(1878, 382); if (color != 0X418 && color != 0X1E2C3B) return false;
	color = GetPixel(1878, 383); if (color != 0X410 && color != 0X23323E) return false;
	color = GetPixel(1878, 384); if (color != 0X411 && color != 0X25343F) return false;
	color = GetPixel(1878, 385); if (color != 0X513 && color != 0X20623) return false;
	color = GetPixel(1879, 371); if (color != 0X20512 && color != 0X3040D) return false;
	color = GetPixel(1879, 372); if (color != 0X20B && color != 0X10219) return false;
	color = GetPixel(1879, 373); if (color != 0X30D && color != 0X162130) return false;
	color = GetPixel(1879, 374); if (color != 0X40E && color != 0X141C2E) return false;
	color = GetPixel(1879, 375); if (color != 0X412 && color != 0X80C28) return false;
	color = GetPixel(1879, 376); if (color != 0X31E && color != 0X70D35) return false;
	color = GetPixel(1879, 377); if (color != 0X20620 && color != 0XD1437) return false;
	color = GetPixel(1879, 378); if (color != 0X1E2C39 && color != 0X21303E) return false;
	color = GetPixel(1879, 379); if (color != 0X25353F && color != 0X293A3F) return false;
	color = GetPixel(1879, 380); if (color != 0X162231 && color != 0X18253C) return false;
	color = GetPixel(1879, 381); if (color != 0X421 && color != 0X70D37) return false;
	color = GetPixel(1879, 382); if (color != 0X419 && color != 0X80E2F) return false;
	color = GetPixel(1879, 383); if (color != 0X411 && color != 0XB132C) return false;
	color = GetPixel(1879, 384); if (color != 0X410 && color != 0X24333E) return false;
	color = GetPixel(1879, 385); if (color != 0X513 && color != 0X20623) return false;
	color = GetPixel(1880, 371); if (color != 0X2040F && color != 0X3040D) return false;
	color = GetPixel(1880, 372); if (color != 0X20C && color != 0X10412) return false;
	color = GetPixel(1880, 373); if (color != 0X30E && color != 0X141F2B) return false;
	color = GetPixel(1880, 374); if (color != 0X30E && color != 0X20616) return false;
	color = GetPixel(1880, 375); if (color != 0X411 && color != 0X418) return false;
	color = GetPixel(1880, 376); if (color != 0X419 && color != 0X525) return false;
	color = GetPixel(1880, 377); if (color != 0X80D20 && color != 0X80E2A) return false;
	color = GetPixel(1880, 378); if (color != 0X21303C && color != 0X27353A) return false;
	color = GetPixel(1880, 379); if (color != 0X28393F && color != 0X293A3F) return false;
	color = GetPixel(1880, 380); if (color != 0X152335 && color != 0X1F2D37) return false;
	color = GetPixel(1880, 381); if (color != 0X41B && color != 0X629) return false;
	color = GetPixel(1880, 382); if (color != 0X517 && color != 0X30923) return false;
	color = GetPixel(1880, 383); if (color != 0X614 && color != 0X10619) return false;
	color = GetPixel(1880, 384); if (color != 0X512 && color != 0X142032) return false;
	color = GetPixel(1880, 385); if (color != 0X512 && color != 0X50A1D) return false;
	color = GetPixel(1881, 371); if (color != 0X2040E && color != 0X3040D) return false;
	color = GetPixel(1881, 372); if (color != 0X30D && color != 0X10411) return false;
	color = GetPixel(1881, 373); if (color != 0X30E && color != 0X413) return false;
	color = GetPixel(1881, 374); if (color != 0X40F && color != 0X412) return false;
	color = GetPixel(1881, 375); if (color != 0X310 && color != 0X416) return false;
	color = GetPixel(1881, 376); if (color != 0X523 && color != 0XD1523) return false;
	color = GetPixel(1881, 377); if (color != 0X80F28 && color != 0X1F2C32) return false;
	color = GetPixel(1881, 378); if (color != 0X1F2D32 && color != 0X22303B) return false;
	color = GetPixel(1881, 379); if (color != 0X1B2A33 && color != 0X293A3F) return false;
	color = GetPixel(1881, 380); if (color != 0X162334 && color != 0X1E2C35) return false;
	color = GetPixel(1881, 381); if (color != 0X727 && color != 0X1E2B35) return false;
	color = GetPixel(1881, 382); if (color != 0X51C && color != 0X60B18) return false;
	color = GetPixel(1881, 383); if (color != 0X410 && color != 0X414) return false;
	color = GetPixel(1881, 384); if (color != 0X415 && color != 0X512) return false;
	color = GetPixel(1881, 385); if (color != 0X414 && color != 0X614) return false;
	color = GetPixel(1882, 371); if (color != 0X2040E && color != 0X3040D) return false;
	color = GetPixel(1882, 372); if (color != 0X30D && color != 0X10411) return false;
	color = GetPixel(1882, 373); if (color != 0X30E && color != 0X412) return false;
	color = GetPixel(1882, 374); if (color != 0X30E && color != 0X412) return false;
	color = GetPixel(1882, 375); if (color != 0X411 && color != 0X516) return false;
	color = GetPixel(1882, 376); if (color != 0X418 && color != 0X20824) return false;
	color = GetPixel(1882, 377); if (color != 0X418 && color != 0X111C2F) return false;
	color = GetPixel(1882, 378); if (color != 0X418 && color != 0X23333C) return false;
	color = GetPixel(1882, 379); if (color != 0X41A && color != 0X27383E) return false;
	color = GetPixel(1882, 380); if (color != 0X41A && color != 0X172434) return false;
	color = GetPixel(1882, 381); if (color != 0X41A && color != 0X20A28) return false;
	color = GetPixel(1882, 382); if (color != 0X416 && color != 0X1061C) return false;
	color = GetPixel(1882, 383); if (color != 0X411 && color != 0X414) return false;
	color = GetPixel(1882, 384); if (color != 0X410 && color != 0X414) return false;
	color = GetPixel(1882, 385); if (color != 0X414 && color != 0X512) return false;
	color = GetPixel(1883, 371); if (color != 0X2040F && color != 0X3040D) return false;
	color = GetPixel(1883, 372); if (color != 0X20C && color != 0X10410) return false;
	color = GetPixel(1883, 373); if (color != 0X30D && color != 0X411) return false;
	color = GetPixel(1883, 374); if (color != 0X30D && color != 0X411) return false;
	color = GetPixel(1883, 375); if (color != 0X410 && color != 0X30716) return false;
	color = GetPixel(1883, 376); if (color != 0X416 && color != 0XF182B) return false;
	color = GetPixel(1883, 377); if (color != 0X416 && color != 0X14202F) return false;
	color = GetPixel(1883, 378); if (color != 0X416 && color != 0X141F2E) return false;
	color = GetPixel(1883, 379); if (color != 0X418 && color != 0X152230) return false;
	color = GetPixel(1883, 380); if (color != 0X418 && color != 0X15222F) return false;
	color = GetPixel(1883, 381); if (color != 0X418 && color != 0X121C2E) return false;
	color = GetPixel(1883, 382); if (color != 0X414 && color != 0X50B1D) return false;
	color = GetPixel(1883, 383); if (color != 0X412 && color != 0X414) return false;
	color = GetPixel(1883, 384); if (color != 0X414 && color != 0X10411) return false;
	color = GetPixel(1883, 385); if (color != 0X10414 && color != 0X10511) return false;
	color = GetPixel(1884, 371); if (color != 0X3040D && color != 0X30510) return false;
	color = GetPixel(1884, 372); if (color != 0X20B && color != 0X1030E) return false;
	color = GetPixel(1884, 373); if (color != 0X30C && color != 0X2030F) return false;
	color = GetPixel(1884, 374); if (color != 0X30C && color != 0X2030F) return false;
	color = GetPixel(1884, 375); if (color != 0X30D && color != 0X20410) return false;
	color = GetPixel(1884, 376); if (color != 0X1040E && color != 0X20717) return false;
	color = GetPixel(1884, 377); if (color != 0X1040E && color != 0X30818) return false;
	color = GetPixel(1884, 378); if (color != 0X1040E && color != 0X30718) return false;
	color = GetPixel(1884, 379); if (color != 0X10510 && color != 0X3091B) return false;
	color = GetPixel(1884, 380); if (color != 0X10510 && color != 0X30819) return false;
	color = GetPixel(1884, 381); if (color != 0X1040F && color != 0X30819) return false;
	color = GetPixel(1884, 382); if (color != 0X30F && color != 0X20615) return false;
	color = GetPixel(1884, 383); if (color != 0X310 && color != 0X20512) return false;
	color = GetPixel(1884, 384); if (color != 0X10512 && color != 0X20512) return false;
	color = GetPixel(1884, 385); if (color != 0X20512 && color != 0X30613) return false;
	return true;
}
bool				Win32GDI::D3IsOpenSkillTable(void)
{
	if (GetPixel(931, 44) != 0X60A1D) return false;
	if (GetPixel(931, 45) != 0X60B1F) return false;
	if (GetPixel(931, 46) != 0X60A1E) return false;
	if (GetPixel(931, 47) != 0X6091C) return false;
	if (GetPixel(931, 48) != 0X6081A) return false;
	if (GetPixel(931, 49) != 0X6081B) return false;
	if (GetPixel(931, 50) != 0X7091B) return false;
	if (GetPixel(931, 51) != 0X70A20) return false;
	if (GetPixel(931, 52) != 0X60C22) return false;
	if (GetPixel(931, 53) != 0X70A1C) return false;
	if (GetPixel(931, 54) != 0X70817) return false;
	if (GetPixel(932, 44) != 0X50A1E) return false;
	if (GetPixel(932, 45) != 0XE3563) return false;
	if (GetPixel(932, 46) != 0X135691) return false;
	if (GetPixel(932, 47) != 0X104375) return false;
	if (GetPixel(932, 48) != 0X50D1E) return false;
	if (GetPixel(932, 49) != 0X50819) return false;
	if (GetPixel(932, 50) != 0X50A20) return false;
	if (GetPixel(932, 51) != 0X6091C) return false;
	if (GetPixel(932, 52) != 0X145C9A) return false;
	if (GetPixel(932, 53) != 0X145B99) return false;
	if (GetPixel(932, 54) != 0X60B1A) return false;
	if (GetPixel(933, 44) != 0X104070) return false;
	if (GetPixel(933, 45) != 0X1874BE) return false;
	if (GetPixel(933, 46) != 0X11487C) return false;
	if (GetPixel(933, 47) != 0X166CB2) return false;
	if (GetPixel(933, 48) != 0X166AAF) return false;
	if (GetPixel(933, 49) != 0X40713) return false;
	if (GetPixel(933, 50) != 0X40715) return false;
	if (GetPixel(933, 51) != 0X50714) return false;
	if (GetPixel(933, 52) != 0XD2C53) return false;
	if (GetPixel(933, 53) != 0X1564A5) return false;
	if (GetPixel(933, 54) != 0X12528A) return false;
	if (GetPixel(934, 44) != 0X1875BF) return false;
	if (GetPixel(934, 45) != 0XC2345) return false;
	if (GetPixel(934, 46) != 0X4050F) return false;
	if (GetPixel(934, 47) != 0X50B17) return false;
	if (GetPixel(934, 48) != 0X1878C4) return false;
	if (GetPixel(934, 49) != 0XF3D69) return false;
	if (GetPixel(934, 50) != 0X4050F) return false;
	if (GetPixel(934, 51) != 0X50511) return false;
	if (GetPixel(934, 52) != 0X40510) return false;
	if (GetPixel(934, 53) != 0XB1D3C) return false;
	if (GetPixel(934, 54) != 0X1877C1) return false;
	if (GetPixel(935, 44) != 0X197BC7) return false;
	if (GetPixel(935, 45) != 0X50C19) return false;
	if (GetPixel(935, 46) != 0X40510) return false;
	if (GetPixel(935, 47) != 0X40610) return false;
	if (GetPixel(935, 48) != 0XF3964) return false;
	if (GetPixel(935, 49) != 0X187AC6) return false;
	if (GetPixel(935, 50) != 0X40712) return false;
	if (GetPixel(935, 51) != 0X4050F) return false;
	if (GetPixel(935, 52) != 0X4050E) return false;
	if (GetPixel(935, 53) != 0X50C1A) return false;
	if (GetPixel(935, 54) != 0X197BC8) return false;
	if (GetPixel(936, 44) != 0X145C9A) return false;
	if (GetPixel(936, 45) != 0X124B7F) return false;
	if (GetPixel(936, 46) != 0X60D1B) return false;
	if (GetPixel(936, 47) != 0X5050F) return false;
	if (GetPixel(936, 48) != 0X40610) return false;
	if (GetPixel(936, 49) != 0X176EB4) return false;
	if (GetPixel(936, 50) != 0X135895) return false;
	if (GetPixel(936, 51) != 0X4050E) return false;
	if (GetPixel(936, 52) != 0X4050E) return false;
	if (GetPixel(936, 53) != 0X11487A) return false;
	if (GetPixel(936, 54) != 0X145C99) return false;
	if (GetPixel(937, 44) != 0XA1A3A) return false;
	if (GetPixel(937, 45) != 0X1771B9) return false;
	if (GetPixel(937, 46) != 0XE3057) return false;
	if (GetPixel(937, 47) != 0X5050F) return false;
	if (GetPixel(937, 48) != 0X4050F) return false;
	if (GetPixel(937, 49) != 0XB2242) return false;
	if (GetPixel(937, 50) != 0X197DCB) return false;
	if (GetPixel(937, 51) != 0X1771BB) return false;
	if (GetPixel(937, 52) != 0X166AAF) return false;
	if (GetPixel(937, 53) != 0X1875BF) return false;
	if (GetPixel(937, 54) != 0XA1A36) return false;
	if (GetPixel(938, 44) != 0X60818) return false;
	if (GetPixel(938, 45) != 0X60816) return false;
	if (GetPixel(938, 46) != 0X60613) return false;
	if (GetPixel(938, 47) != 0X60612) return false;
	if (GetPixel(938, 48) != 0X60611) return false;
	if (GetPixel(938, 49) != 0X50819) return false;
	if (GetPixel(938, 50) != 0X60E23) return false;
	if (GetPixel(938, 51) != 0XE3462) return false;
	if (GetPixel(938, 52) != 0XE335E) return false;
	if (GetPixel(938, 53) != 0X60B1C) return false;
	if (GetPixel(938, 54) != 0X60614) return false;
	if (GetPixel(939, 44) != 0X60713) return false;
	if (GetPixel(939, 45) != 0X60712) return false;
	if (GetPixel(939, 46) != 0X60611) return false;
	if (GetPixel(939, 47) != 0X60611) return false;
	if (GetPixel(939, 48) != 0X50718) return false;
	if (GetPixel(939, 49) != 0X5081A) return false;
	if (GetPixel(939, 50) != 0X50613) return false;
	if (GetPixel(939, 51) != 0X50611) return false;
	if (GetPixel(939, 52) != 0X50612) return false;
	if (GetPixel(939, 53) != 0X50514) return false;
	if (GetPixel(939, 54) != 0X60615) return false;
	if (GetPixel(940, 44) != 0X60816) return false;
	if (GetPixel(940, 45) != 0X60815) return false;
	if (GetPixel(940, 46) != 0X60715) return false;
	if (GetPixel(940, 47) != 0X6091A) return false;
	if (GetPixel(940, 48) != 0X50A1F) return false;
	if (GetPixel(940, 49) != 0X5081A) return false;
	if (GetPixel(940, 50) != 0X50510) return false;
	if (GetPixel(940, 51) != 0X50612) return false;
	if (GetPixel(940, 52) != 0X50511) return false;
	if (GetPixel(940, 53) != 0X60615) return false;
	if (GetPixel(940, 54) != 0X60616) return false;
	if (GetPixel(941, 44) != 0X60A1E) return false;
	if (GetPixel(941, 45) != 0X60819) return false;
	if (GetPixel(941, 46) != 0X50819) return false;
	if (GetPixel(941, 47) != 0X50920) return false;
	if (GetPixel(941, 48) != 0X4081B) return false;
	if (GetPixel(941, 49) != 0X40716) return false;
	if (GetPixel(941, 50) != 0X40510) return false;
	if (GetPixel(941, 51) != 0X4040D) return false;
	if (GetPixel(941, 52) != 0X50510) return false;
	if (GetPixel(941, 53) != 0X50717) return false;
	if (GetPixel(941, 54) != 0X60614) return false;
	if (GetPixel(942, 44) != 0X104375) return false;
	if (GetPixel(942, 45) != 0XA1B39) return false;
	if (GetPixel(942, 46) != 0XA1B3D) return false;
	if (GetPixel(942, 47) != 0XA1E4A) return false;
	if (GetPixel(942, 48) != 0XA1E46) return false;
	if (GetPixel(942, 49) != 0XA1E46) return false;
	if (GetPixel(942, 50) != 0XA1B3C) return false;
	if (GetPixel(942, 51) != 0XA1934) return false;
	if (GetPixel(942, 52) != 0XA1D41) return false;
	if (GetPixel(942, 53) != 0XA1D40) return false;
	if (GetPixel(942, 54) != 0X104273) return false;
	if (GetPixel(943, 44) != 0X1A84D6) return false;
	if (GetPixel(943, 45) != 0X1A84D6) return false;
	if (GetPixel(943, 46) != 0X1A84D6) return false;
	if (GetPixel(943, 47) != 0X1A84D6) return false;
	if (GetPixel(943, 48) != 0X1A84D6) return false;
	if (GetPixel(943, 49) != 0X1A84D6) return false;
	if (GetPixel(943, 50) != 0X1A84D6) return false;
	if (GetPixel(943, 51) != 0X1A84D6) return false;
	if (GetPixel(943, 52) != 0X1A84D6) return false;
	if (GetPixel(943, 53) != 0X1A84D6) return false;
	if (GetPixel(943, 54) != 0X1A84D6) return false;
	if (GetPixel(944, 44) != 0XE3564) return false;
	if (GetPixel(944, 45) != 0X40817) return false;
	if (GetPixel(944, 46) != 0X30510) return false;
	if (GetPixel(944, 47) != 0XA1B3C) return false;
	if (GetPixel(944, 48) != 0X1774BE) return false;
	if (GetPixel(944, 49) != 0X187BC9) return false;
	if (GetPixel(944, 50) != 0X135594) return false;
	if (GetPixel(944, 51) != 0X30611) return false;
	if (GetPixel(944, 52) != 0X30714) return false;
	if (GetPixel(944, 53) != 0X40716) return false;
	if (GetPixel(944, 54) != 0XE335D) return false;
	if (GetPixel(945, 44) != 0X5091B) return false;
	if (GetPixel(945, 45) != 0X40819) return false;
	if (GetPixel(945, 46) != 0XB1E42) return false;
	if (GetPixel(945, 47) != 0X1875C0) return false;
	if (GetPixel(945, 48) != 0XF396C) return false;
	if (GetPixel(945, 49) != 0X30918) return false;
	if (GetPixel(945, 50) != 0X1774BF) return false;
	if (GetPixel(945, 51) != 0X145A98) return false;
	if (GetPixel(945, 52) != 0X30610) return false;
	if (GetPixel(945, 53) != 0X40611) return false;
	if (GetPixel(945, 54) != 0X50611) return false;
	if (GetPixel(946, 44) != 0X50A1E) return false;
	if (GetPixel(946, 45) != 0XB244B) return false;
	if (GetPixel(946, 46) != 0X1877C2) return false;
	if (GetPixel(946, 47) != 0XE3564) return false;
	if (GetPixel(946, 48) != 0X30511) return false;
	if (GetPixel(946, 49) != 0X40614) return false;
	if (GetPixel(946, 50) != 0X40B18) return false;
	if (GetPixel(946, 51) != 0X1771B9) return false;
	if (GetPixel(946, 52) != 0X145E9C) return false;
	if (GetPixel(946, 53) != 0X40712) return false;
	if (GetPixel(946, 54) != 0X50611) return false;
	if (GetPixel(947, 44) != 0XB2651) return false;
	if (GetPixel(947, 45) != 0X1878C4) return false;
	if (GetPixel(947, 46) != 0XE315E) return false;
	if (GetPixel(947, 47) != 0X40614) return false;
	if (GetPixel(947, 48) != 0X4050F) return false;
	if (GetPixel(947, 49) != 0X40612) return false;
	if (GetPixel(947, 50) != 0X4050F) return false;
	if (GetPixel(947, 51) != 0X50A18) return false;
	if (GetPixel(947, 52) != 0X176EB5) return false;
	if (GetPixel(947, 53) != 0X1563A3) return false;
	if (GetPixel(947, 54) != 0X50916) return false;
	if (GetPixel(948, 44) != 0X1879C5) return false;
	if (GetPixel(948, 45) != 0XD2E58) return false;
	if (GetPixel(948, 46) != 0X60715) return false;
	if (GetPixel(948, 47) != 0X60714) return false;
	if (GetPixel(948, 48) != 0X60612) return false;
	if (GetPixel(948, 49) != 0X60714) return false;
	if (GetPixel(948, 50) != 0X60611) return false;
	if (GetPixel(948, 51) != 0X50716) return false;
	if (GetPixel(948, 52) != 0X60C1D) return false;
	if (GetPixel(948, 53) != 0X166CB1) return false;
	if (GetPixel(948, 54) != 0X1566A8) return false;
	if (GetPixel(949, 44) != 0XF3C6A) return false;
	if (GetPixel(949, 45) != 0X60715) return false;
	if (GetPixel(949, 46) != 0X60613) return false;
	if (GetPixel(949, 47) != 0X70714) return false;
	if (GetPixel(949, 48) != 0X80A1D) return false;
	if (GetPixel(949, 49) != 0X80A1E) return false;
	if (GetPixel(949, 50) != 0X60919) return false;
	if (GetPixel(949, 51) != 0X6091A) return false;
	if (GetPixel(949, 52) != 0X60818) return false;
	if (GetPixel(949, 53) != 0X70E20) return false;
	if (GetPixel(949, 54) != 0X166CB2) return false;
	if (GetPixel(950, 44) != 0X7091A) return false;
	if (GetPixel(950, 45) != 0X70717) return false;
	if (GetPixel(950, 46) != 0X70715) return false;
	if (GetPixel(950, 47) != 0X90B20) return false;
	if (GetPixel(950, 48) != 0XC102D) return false;
	if (GetPixel(950, 49) != 0XE153B) return false;
	if (GetPixel(950, 50) != 0X70D29) return false;
	if (GetPixel(950, 51) != 0X70A21) return false;
	if (GetPixel(950, 52) != 0X70A1E) return false;
	if (GetPixel(950, 53) != 0X60A1E) return false;
	if (GetPixel(950, 54) != 0XC264B) return false;
	if (GetPixel(951, 44) != 0X70716) return false;
	if (GetPixel(951, 45) != 0X70714) return false;
	if (GetPixel(951, 46) != 0X8091B) return false;
	if (GetPixel(951, 47) != 0XA0F29) return false;
	if (GetPixel(951, 48) != 0XD1335) return false;
	if (GetPixel(951, 49) != 0XD1335) return false;
	if (GetPixel(951, 50) != 0X70C26) return false;
	if (GetPixel(951, 51) != 0X70818) return false;
	if (GetPixel(951, 52) != 0X60613) return false;
	if (GetPixel(951, 53) != 0X60819) return false;
	if (GetPixel(951, 54) != 0X60C23) return false;
	if (GetPixel(952, 44) != 0X60713) return false;
	if (GetPixel(952, 45) != 0X70712) return false;
	if (GetPixel(952, 46) != 0X70714) return false;
	if (GetPixel(952, 47) != 0X70C1E) return false;
	if (GetPixel(952, 48) != 0X60A1B) return false;
	if (GetPixel(952, 49) != 0X70A1B) return false;
	if (GetPixel(952, 50) != 0X6081B) return false;
	if (GetPixel(952, 51) != 0X60717) return false;
	if (GetPixel(952, 52) != 0X60614) return false;
	if (GetPixel(952, 53) != 0X60613) return false;
	if (GetPixel(952, 54) != 0X6091B) return false;
	if (GetPixel(953, 44) != 0X60711) return false;
	if (GetPixel(953, 45) != 0X60612) return false;
	if (GetPixel(953, 46) != 0X60815) return false;
	if (GetPixel(953, 47) != 0X60817) return false;
	if (GetPixel(953, 48) != 0X60713) return false;
	if (GetPixel(953, 49) != 0X60713) return false;
	if (GetPixel(953, 50) != 0X60717) return false;
	if (GetPixel(953, 51) != 0X60719) return false;
	if (GetPixel(953, 52) != 0X60715) return false;
	if (GetPixel(953, 53) != 0X60613) return false;
	if (GetPixel(953, 54) != 0X6081B) return false;
	if (GetPixel(954, 44) != 0XC2443) return false;
	if (GetPixel(954, 45) != 0X60611) return false;
	if (GetPixel(954, 46) != 0X60714) return false;
	if (GetPixel(954, 47) != 0X60917) return false;
	if (GetPixel(954, 48) != 0X60714) return false;
	if (GetPixel(954, 49) != 0X60815) return false;
	if (GetPixel(954, 50) != 0X60717) return false;
	if (GetPixel(954, 51) != 0X60717) return false;
	if (GetPixel(954, 52) != 0X60614) return false;
	if (GetPixel(954, 53) != 0X60715) return false;
	if (GetPixel(954, 54) != 0XC274E) return false;
	if (GetPixel(955, 44) != 0X1A82D2) return false;
	if (GetPixel(955, 45) != 0X1875BF) return false;
	if (GetPixel(955, 46) != 0X1875BF) return false;
	if (GetPixel(955, 47) != 0X1875BF) return false;
	if (GetPixel(955, 48) != 0X1875BE) return false;
	if (GetPixel(955, 49) != 0X1875BF) return false;
	if (GetPixel(955, 50) != 0X1875BF) return false;
	if (GetPixel(955, 51) != 0X1875BF) return false;
	if (GetPixel(955, 52) != 0X1875BF) return false;
	if (GetPixel(955, 53) != 0X1876C0) return false;
	if (GetPixel(955, 54) != 0X1A82D3) return false;
	if (GetPixel(956, 44) != 0X13558C) return false;
	if (GetPixel(956, 45) != 0XE3155) return false;
	if (GetPixel(956, 46) != 0XE3054) return false;
	if (GetPixel(956, 47) != 0XE2F53) return false;
	if (GetPixel(956, 48) != 0XE2F53) return false;
	if (GetPixel(956, 49) != 0XE2F53) return false;
	if (GetPixel(956, 50) != 0XE2F55) return false;
	if (GetPixel(956, 51) != 0XE3056) return false;
	if (GetPixel(956, 52) != 0XE3057) return false;
	if (GetPixel(956, 53) != 0XE3157) return false;
	if (GetPixel(956, 54) != 0X13558E) return false;
	if (GetPixel(957, 44) != 0X70B17) return false;
	if (GetPixel(957, 45) != 0X60711) return false;
	if (GetPixel(957, 46) != 0X60611) return false;
	if (GetPixel(957, 47) != 0X60611) return false;
	if (GetPixel(957, 48) != 0X50610) return false;
	if (GetPixel(957, 49) != 0X60611) return false;
	if (GetPixel(957, 50) != 0X50613) return false;
	if (GetPixel(957, 51) != 0X60714) return false;
	if (GetPixel(957, 52) != 0X60612) return false;
	if (GetPixel(957, 53) != 0X60712) return false;
	if (GetPixel(957, 54) != 0X70B18) return false;
	if (GetPixel(958, 44) != 0X6070E) return false;
	if (GetPixel(958, 45) != 0X60610) return false;
	if (GetPixel(958, 46) != 0X5060F) return false;
	if (GetPixel(958, 47) != 0X50610) return false;
	if (GetPixel(958, 48) != 0X50714) return false;
	if (GetPixel(958, 49) != 0X5060F) return false;
	if (GetPixel(958, 50) != 0X50612) return false;
	if (GetPixel(958, 51) != 0X50715) return false;
	if (GetPixel(958, 52) != 0X50714) return false;
	if (GetPixel(958, 53) != 0X60814) return false;
	if (GetPixel(958, 54) != 0X60712) return false;
	if (GetPixel(959, 44) != 0X60710) return false;
	if (GetPixel(959, 45) != 0X60710) return false;
	if (GetPixel(959, 46) != 0X50815) return false;
	if (GetPixel(959, 47) != 0X50714) return false;
	if (GetPixel(959, 48) != 0X50612) return false;
	if (GetPixel(959, 49) != 0X50612) return false;
	if (GetPixel(959, 50) != 0X50714) return false;
	if (GetPixel(959, 51) != 0X50917) return false;
	if (GetPixel(959, 52) != 0X50918) return false;
	if (GetPixel(959, 53) != 0X60918) return false;
	if (GetPixel(959, 54) != 0X60714) return false;
	if (GetPixel(960, 44) != 0X60711) return false;
	if (GetPixel(960, 45) != 0X60713) return false;
	if (GetPixel(960, 46) != 0X60816) return false;
	if (GetPixel(960, 47) != 0X60816) return false;
	if (GetPixel(960, 48) != 0X50510) return false;
	if (GetPixel(960, 49) != 0X50814) return false;
	if (GetPixel(960, 50) != 0X50917) return false;
	if (GetPixel(960, 51) != 0X50917) return false;
	if (GetPixel(960, 52) != 0X50917) return false;
	if (GetPixel(960, 53) != 0X60817) return false;
	if (GetPixel(960, 54) != 0X60614) return false;
	if (GetPixel(961, 44) != 0X104270) return false;
	if (GetPixel(961, 45) != 0XA1A32) return false;
	if (GetPixel(961, 46) != 0XA1B36) return false;
	if (GetPixel(961, 47) != 0XA1A35) return false;
	if (GetPixel(961, 48) != 0XA1830) return false;
	if (GetPixel(961, 49) != 0XA1A35) return false;
	if (GetPixel(961, 50) != 0XA1C39) return false;
	if (GetPixel(961, 51) != 0XA1934) return false;
	if (GetPixel(961, 52) != 0XA1830) return false;
	if (GetPixel(961, 53) != 0XA1831) return false;
	if (GetPixel(961, 54) != 0XA1936) return false;
	if (GetPixel(962, 44) != 0X1A84D6) return false;
	if (GetPixel(962, 45) != 0X1A84D6) return false;
	if (GetPixel(962, 46) != 0X1A84D6) return false;
	if (GetPixel(962, 47) != 0X1A84D6) return false;
	if (GetPixel(962, 48) != 0X1A84D6) return false;
	if (GetPixel(962, 49) != 0X1A84D6) return false;
	if (GetPixel(962, 50) != 0X1A84D6) return false;
	if (GetPixel(962, 51) != 0X1A84D6) return false;
	if (GetPixel(962, 52) != 0X1A84D6) return false;
	if (GetPixel(962, 53) != 0X1A84D6) return false;
	if (GetPixel(962, 54) != 0X1A84D6) return false;
	if (GetPixel(963, 44) != 0XE3562) return false;
	if (GetPixel(963, 45) != 0X60A1C) return false;
	if (GetPixel(963, 46) != 0X60A19) return false;
	if (GetPixel(963, 47) != 0X60715) return false;
	if (GetPixel(963, 48) != 0X60714) return false;
	if (GetPixel(963, 49) != 0X60919) return false;
	if (GetPixel(963, 50) != 0X50917) return false;
	if (GetPixel(963, 51) != 0X50611) return false;
	if (GetPixel(963, 52) != 0X5040C) return false;
	if (GetPixel(963, 53) != 0XA172D) return false;
	if (GetPixel(963, 54) != 0X1A84D6) return false;
	if (GetPixel(964, 44) != 0X60B22) return false;
	if (GetPixel(964, 45) != 0X60A1E) return false;
	if (GetPixel(964, 46) != 0X60B1E) return false;
	if (GetPixel(964, 47) != 0X60B1C) return false;
	if (GetPixel(964, 48) != 0X60816) return false;
	if (GetPixel(964, 49) != 0X60715) return false;
	if (GetPixel(964, 50) != 0X50612) return false;
	if (GetPixel(964, 51) != 0X5050E) return false;
	if (GetPixel(964, 52) != 0X5020A) return false;
	if (GetPixel(964, 53) != 0XA1629) return false;
	if (GetPixel(964, 54) != 0X1A84D5) return false;
	if (GetPixel(965, 44) != 0X70D26) return false;
	if (GetPixel(965, 45) != 0X70B22) return false;
	if (GetPixel(965, 46) != 0X70A1C) return false;
	if (GetPixel(965, 47) != 0X7091A) return false;
	if (GetPixel(965, 48) != 0X70714) return false;
	if (GetPixel(965, 49) != 0X70714) return false;
	if (GetPixel(965, 50) != 0X60612) return false;
	if (GetPixel(965, 51) != 0X60510) return false;
	if (GetPixel(965, 52) != 0X5030B) return false;
	if (GetPixel(965, 53) != 0XA162B) return false;
	if (GetPixel(965, 54) != 0X1A84D5) return false;
	if (GetPixel(966, 44) != 0X70B1D) return false;
	if (GetPixel(966, 45) != 0X70B1C) return false;
	if (GetPixel(966, 46) != 0X40814) return false;
	if (GetPixel(966, 47) != 0X40913) return false;
	if (GetPixel(966, 48) != 0X50914) return false;
	if (GetPixel(966, 49) != 0X50813) return false;
	if (GetPixel(966, 50) != 0X60612) return false;
	if (GetPixel(966, 51) != 0X60611) return false;
	if (GetPixel(966, 52) != 0X6050F) return false;
	if (GetPixel(966, 53) != 0XA1931) return false;
	if (GetPixel(966, 54) != 0X1A84D6) return false;
	if (GetPixel(967, 44) != 0X80B1A) return false;
	if (GetPixel(967, 45) != 0X80A18) return false;
	if (GetPixel(967, 46) != 0X50A15) return false;
	if (GetPixel(967, 47) != 0X50B15) return false;
	if (GetPixel(967, 48) != 0X50B15) return false;
	if (GetPixel(967, 49) != 0X50B15) return false;
	if (GetPixel(967, 50) != 0X70716) return false;
	if (GetPixel(967, 51) != 0X70819) return false;
	if (GetPixel(967, 52) != 0X6081A) return false;
	if (GetPixel(967, 53) != 0XF3D6E) return false;
	if (GetPixel(967, 54) != 0X166AAF) return false;
	if (GetPixel(968, 44) != 0X70916) return false;
	if (GetPixel(968, 45) != 0X70813) return false;
	if (GetPixel(968, 46) != 0X50913) return false;
	if (GetPixel(968, 47) != 0X40913) return false;
	if (GetPixel(968, 48) != 0X40912) return false;
	if (GetPixel(968, 49) != 0X40912) return false;
	if (GetPixel(968, 50) != 0X60715) return false;
	if (GetPixel(968, 51) != 0X6091E) return false;
	if (GetPixel(968, 52) != 0X6081C) return false;
	if (GetPixel(968, 53) != 0X6091E) return false;
	if (GetPixel(968, 54) != 0X50715) return false;
	if (GetPixel(969, 44) != 0X70813) return false;
	if (GetPixel(969, 45) != 0X70813) return false;
	if (GetPixel(969, 46) != 0X50812) return false;
	if (GetPixel(969, 47) != 0X40912) return false;
	if (GetPixel(969, 48) != 0X40912) return false;
	if (GetPixel(969, 49) != 0X20711) return false;
	if (GetPixel(969, 50) != 0X60920) return false;
	if (GetPixel(969, 51) != 0X6091E) return false;
	if (GetPixel(969, 52) != 0X6081A) return false;
	if (GetPixel(969, 53) != 0X60716) return false;
	if (GetPixel(969, 54) != 0X60611) return false;
	if (GetPixel(970, 44) != 0X60712) return false;
	if (GetPixel(970, 45) != 0X60711) return false;
	if (GetPixel(970, 46) != 0X60712) return false;
	if (GetPixel(970, 47) != 0X60712) return false;
	if (GetPixel(970, 48) != 0X6060D) return false;
	if (GetPixel(970, 49) != 0X6091D) return false;
	if (GetPixel(970, 50) != 0X5081C) return false;
	if (GetPixel(970, 51) != 0X50817) return false;
	if (GetPixel(970, 52) != 0X50610) return false;
	if (GetPixel(970, 53) != 0X50510) return false;
	if (GetPixel(970, 54) != 0X50510) return false;
	if (GetPixel(971, 44) != 0X10426F) return false;
	if (GetPixel(971, 45) != 0XA192F) return false;
	if (GetPixel(971, 46) != 0XA182B) return false;
	if (GetPixel(971, 47) != 0XA1829) return false;
	if (GetPixel(971, 48) != 0XA1A34) return false;
	if (GetPixel(971, 49) != 0XA1F45) return false;
	if (GetPixel(971, 50) != 0XA1A39) return false;
	if (GetPixel(971, 51) != 0XA192E) return false;
	if (GetPixel(971, 52) != 0XA182C) return false;
	if (GetPixel(971, 53) != 0XA1830) return false;
	if (GetPixel(971, 54) != 0XA1831) return false;
	if (GetPixel(972, 44) != 0X1A84D5) return false;
	if (GetPixel(972, 45) != 0X1A84D5) return false;
	if (GetPixel(972, 46) != 0X1A84D5) return false;
	if (GetPixel(972, 47) != 0X1A84D5) return false;
	if (GetPixel(972, 48) != 0X1A84D6) return false;
	if (GetPixel(972, 49) != 0X1A84D6) return false;
	if (GetPixel(972, 50) != 0X1A84D5) return false;
	if (GetPixel(972, 51) != 0X1A84D5) return false;
	if (GetPixel(972, 52) != 0X1A84D5) return false;
	if (GetPixel(972, 53) != 0X1A84D6) return false;
	if (GetPixel(972, 54) != 0X1A84D6) return false;
	if (GetPixel(973, 44) != 0XE3356) return false;
	if (GetPixel(973, 45) != 0X60711) return false;
	if (GetPixel(973, 46) != 0X60714) return false;
	if (GetPixel(973, 47) != 0X6091C) return false;
	if (GetPixel(973, 48) != 0X6091A) return false;
	if (GetPixel(973, 49) != 0X6060F) return false;
	if (GetPixel(973, 50) != 0X5050A) return false;
	if (GetPixel(973, 51) != 0X5050B) return false;
	if (GetPixel(973, 52) != 0X5050B) return false;
	if (GetPixel(973, 53) != 0XA192F) return false;
	if (GetPixel(973, 54) != 0X1A84D5) return false;
	if (GetPixel(974, 44) != 0X60713) return false;
	if (GetPixel(974, 45) != 0X60815) return false;
	if (GetPixel(974, 46) != 0X6081D) return false;
	if (GetPixel(974, 47) != 0X6091F) return false;
	if (GetPixel(974, 48) != 0X60715) return false;
	if (GetPixel(974, 49) != 0X6060C) return false;
	if (GetPixel(974, 50) != 0X5060C) return false;
	if (GetPixel(974, 51) != 0X5060D) return false;
	if (GetPixel(974, 52) != 0X5060D) return false;
	if (GetPixel(974, 53) != 0XA192E) return false;
	if (GetPixel(974, 54) != 0X1A84D5) return false;
	if (GetPixel(975, 44) != 0X70815) return false;
	if (GetPixel(975, 45) != 0X70A1D) return false;
	if (GetPixel(975, 46) != 0X70A22) return false;
	if (GetPixel(975, 47) != 0X7091E) return false;
	if (GetPixel(975, 48) != 0X70815) return false;
	if (GetPixel(975, 49) != 0X7070D) return false;
	if (GetPixel(975, 50) != 0X6080F) return false;
	if (GetPixel(975, 51) != 0X60810) return false;
	if (GetPixel(975, 52) != 0X5070F) return false;
	if (GetPixel(975, 53) != 0XA192E) return false;
	if (GetPixel(975, 54) != 0X1A84D5) return false;
	if (GetPixel(976, 44) != 0X7091C) return false;
	if (GetPixel(976, 45) != 0X70A20) return false;
	if (GetPixel(976, 46) != 0X70A22) return false;
	if (GetPixel(976, 47) != 0X70A1E) return false;
	if (GetPixel(976, 48) != 0X7070F) return false;
	if (GetPixel(976, 49) != 0X70813) return false;
	if (GetPixel(976, 50) != 0X60811) return false;
	if (GetPixel(976, 51) != 0X60810) return false;
	if (GetPixel(976, 52) != 0X6070E) return false;
	if (GetPixel(976, 53) != 0XA1A30) return false;
	if (GetPixel(976, 54) != 0X1A84D5) return false;
	if (GetPixel(977, 44) != 0X80A1F) return false;
	if (GetPixel(977, 45) != 0X80B25) return false;
	if (GetPixel(977, 46) != 0X80B21) return false;
	if (GetPixel(977, 47) != 0X80B1B) return false;
	if (GetPixel(977, 48) != 0X80915) return false;
	if (GetPixel(977, 49) != 0X80915) return false;
	if (GetPixel(977, 50) != 0X70813) return false;
	if (GetPixel(977, 51) != 0X70813) return false;
	if (GetPixel(977, 52) != 0X60813) return false;
	if (GetPixel(977, 53) != 0XF3C66) return false;
	if (GetPixel(977, 54) != 0X166AAD) return false;
	if (GetPixel(978, 44) != 0X7091E) return false;
	if (GetPixel(978, 45) != 0X7091C) return false;
	if (GetPixel(978, 46) != 0X70815) return false;
	if (GetPixel(978, 47) != 0X70814) return false;
	if (GetPixel(978, 48) != 0X70A18) return false;
	if (GetPixel(978, 49) != 0X70A19) return false;
	if (GetPixel(978, 50) != 0X70A17) return false;
	if (GetPixel(978, 51) != 0X70813) return false;
	if (GetPixel(978, 52) != 0X70814) return false;
	if (GetPixel(978, 53) != 0X60716) return false;
	if (GetPixel(978, 54) != 0X60616) return false;
	if (GetPixel(979, 44) != 0X7091C) return false;
	if (GetPixel(979, 45) != 0X70711) return false;
	if (GetPixel(979, 46) != 0X70811) return false;
	if (GetPixel(979, 47) != 0X70812) return false;
	if (GetPixel(979, 48) != 0X7091A) return false;
	if (GetPixel(979, 49) != 0X70917) return false;
	if (GetPixel(979, 50) != 0X70916) return false;
	if (GetPixel(979, 51) != 0X70812) return false;
	if (GetPixel(979, 52) != 0X60813) return false;
	if (GetPixel(979, 53) != 0X60714) return false;
	if (GetPixel(979, 54) != 0X60615) return false;
	if (GetPixel(980, 44) != 0X60714) return false;
	if (GetPixel(980, 45) != 0X5060D) return false;
	if (GetPixel(980, 46) != 0X60710) return false;
	if (GetPixel(980, 47) != 0X60711) return false;
	if (GetPixel(980, 48) != 0X60710) return false;
	if (GetPixel(980, 49) != 0X60814) return false;
	if (GetPixel(980, 50) != 0X60815) return false;
	if (GetPixel(980, 51) != 0X60712) return false;
	if (GetPixel(980, 52) != 0X60813) return false;
	if (GetPixel(980, 53) != 0X60611) return false;
	if (GetPixel(980, 54) != 0X60613) return false;
	if (GetPixel(981, 44) != 0X2050C) return false;
	if (GetPixel(981, 45) != 0XA3052) return false;
	if (GetPixel(981, 46) != 0X125389) return false;
	if (GetPixel(981, 47) != 0X10406D) return false;
	if (GetPixel(981, 48) != 0X50A14) return false;
	if (GetPixel(981, 49) != 0X5050F) return false;
	if (GetPixel(981, 50) != 0X50511) return false;
	if (GetPixel(981, 51) != 0X60612) return false;
	if (GetPixel(981, 52) != 0X145B97) return false;
	if (GetPixel(981, 53) != 0X145A95) return false;
	if (GetPixel(981, 54) != 0X60916) return false;
	if (GetPixel(982, 44) != 0XD3C65) return false;
	if (GetPixel(982, 45) != 0X1774BC) return false;
	if (GetPixel(982, 46) != 0X104675) return false;
	if (GetPixel(982, 47) != 0X166BAF) return false;
	if (GetPixel(982, 48) != 0X166AAD) return false;
	if (GetPixel(982, 49) != 0X4050D) return false;
	if (GetPixel(982, 50) != 0X4040D) return false;
	if (GetPixel(982, 51) != 0X50510) return false;
	if (GetPixel(982, 52) != 0XD2A4C) return false;
	if (GetPixel(982, 53) != 0X1563A2) return false;
	if (GetPixel(982, 54) != 0X125085) return false;
	if (GetPixel(983, 44) != 0X1775BE) return false;
	if (GetPixel(983, 45) != 0X8213A) return false;
	if (GetPixel(983, 46) != 0X3040B) return false;
	if (GetPixel(983, 47) != 0X50914) return false;
	if (GetPixel(983, 48) != 0X1878C3) return false;
	if (GetPixel(983, 49) != 0XF3C67) return false;
	if (GetPixel(983, 50) != 0X4040B) return false;
	if (GetPixel(983, 51) != 0X5050D) return false;
	if (GetPixel(983, 52) != 0X4040C) return false;
	if (GetPixel(983, 53) != 0XB1B34) return false;
	if (GetPixel(983, 54) != 0X1876C0) return false;
	if (GetPixel(984, 44) != 0X187BC7) return false;
	if (GetPixel(984, 45) != 0X50C17) return false;
	if (GetPixel(984, 46) != 0X4050D) return false;
	if (GetPixel(984, 47) != 0X4050C) return false;
	if (GetPixel(984, 48) != 0XF375E) return false;
	if (GetPixel(984, 49) != 0X187AC6) return false;
	if (GetPixel(984, 50) != 0X4070E) return false;
	if (GetPixel(984, 51) != 0X4040C) return false;
	if (GetPixel(984, 52) != 0X4040A) return false;
	if (GetPixel(984, 53) != 0X50B15) return false;
	if (GetPixel(984, 54) != 0X187BC8) return false;
	if (GetPixel(985, 44) != 0X145D99) return false;
	if (GetPixel(985, 45) != 0X124B7D) return false;
	if (GetPixel(985, 46) != 0X60E1B) return false;
	if (GetPixel(985, 47) != 0X5060F) return false;
	if (GetPixel(985, 48) != 0X4060E) return false;
	if (GetPixel(985, 49) != 0X176EB3) return false;
	if (GetPixel(985, 50) != 0X135790) return false;
	if (GetPixel(985, 51) != 0X4040B) return false;
	if (GetPixel(985, 52) != 0X4040B) return false;
	if (GetPixel(985, 53) != 0X104777) return false;
	if (GetPixel(985, 54) != 0X135C97) return false;
	if (GetPixel(986, 44) != 0XA192E) return false;
	if (GetPixel(986, 45) != 0X1771B7) return false;
	if (GetPixel(986, 46) != 0XE3053) return false;
	if (GetPixel(986, 47) != 0X5060E) return false;
	if (GetPixel(986, 48) != 0X4050C) return false;
	if (GetPixel(986, 49) != 0XB213B) return false;
	if (GetPixel(986, 50) != 0X197DCA) return false;
	if (GetPixel(986, 51) != 0X1771B8) return false;
	if (GetPixel(986, 52) != 0X166AAD) return false;
	if (GetPixel(986, 53) != 0X1775BE) return false;
	if (GetPixel(986, 54) != 0X6192F) return false;
	return true;
}
bool				Win32GDI::D3IsOpenKadala(void)
{
	if (GetPixel(452, 829) != 0XC1B29) return false;
	if (GetPixel(452, 830) != 0X1A4C7C) return false;
	if (GetPixel(452, 831) != 0X80A0D) return false;
	if (GetPixel(452, 832) != 0X90909) return false;
	if (GetPixel(452, 833) != 0XC0C0C) return false;
	if (GetPixel(452, 834) != 0XE0E0E) return false;
	if (GetPixel(452, 835) != 0XC1012) return false;
	if (GetPixel(452, 836) != 0XB1013) return false;
	if (GetPixel(452, 837) != 0XB1013) return false;
	if (GetPixel(452, 838) != 0XC1012) return false;
	if (GetPixel(452, 839) != 0XE0F0F) return false;
	if (GetPixel(452, 840) != 0XF0F0F) return false;
	if (GetPixel(452, 841) != 0XC0D0F) return false;
	if (GetPixel(452, 842) != 0XA0C0F) return false;
	if (GetPixel(452, 843) != 0XA0C0F) return false;
	if (GetPixel(452, 844) != 0XB0D0F) return false;
	if (GetPixel(452, 847) != 0XB0D0F) return false;
	if (GetPixel(452, 848) != 0XA0C0F) return false;
	if (GetPixel(452, 850) != 0XB0D10) return false;
	if (GetPixel(452, 851) != 0XB0D10) return false;
	if (GetPixel(452, 852) != 0XB0D10) return false;
	if (GetPixel(452, 853) != 0X80C0F) return false;
	if (GetPixel(452, 854) != 0X80B0D) return false;
	if (GetPixel(452, 855) != 0X8090B) return false;
	if (GetPixel(452, 856) != 0X80808) return false;
	if (GetPixel(452, 857) != 0XF2334) return false;
	if (GetPixel(452, 858) != 0X184369) return false;
	if (GetPixel(452, 859) != 0X80808) return false;
	if (GetPixel(453, 829) != 0XC1B29) return false;
	if (GetPixel(453, 830) != 0X1A4C7C) return false;
	if (GetPixel(453, 831) != 0X80A0D) return false;
	if (GetPixel(453, 832) != 0X90909) return false;
	if (GetPixel(453, 833) != 0XA0C0C) return false;
	if (GetPixel(453, 834) != 0XC0F0F) return false;
	if (GetPixel(453, 835) != 0XB1012) return false;
	if (GetPixel(453, 836) != 0XC1014) return false;
	if (GetPixel(453, 837) != 0XB1013) return false;
	if (GetPixel(453, 838) != 0XC1014) return false;
	if (GetPixel(453, 839) != 0XC0F11) return false;
	if (GetPixel(453, 840) != 0XE1011) return false;
	if (GetPixel(453, 841) != 0XC0F11) return false;
	if (GetPixel(453, 842) != 0XB0D11) return false;
	if (GetPixel(453, 843) != 0XB0D10) return false;
	if (GetPixel(453, 844) != 0XC0E10) return false;
	if (GetPixel(453, 845) != 0XC0E10) return false;
	if (GetPixel(453, 846) != 0XD0F10) return false;
	if (GetPixel(453, 847) != 0XD0F10) return false;
	if (GetPixel(453, 848) != 0XC0E10) return false;
	if (GetPixel(453, 849) != 0XD0F10) return false;
	if (GetPixel(453, 850) != 0XC0E10) return false;
	if (GetPixel(453, 851) != 0XB0D10) return false;
	if (GetPixel(453, 852) != 0XB0D10) return false;
	if (GetPixel(453, 853) != 0X80C0D) return false;
	if (GetPixel(453, 854) != 0X80B0D) return false;
	if (GetPixel(453, 855) != 0X8080B) return false;
	if (GetPixel(453, 856) != 0X80608) return false;
	if (GetPixel(453, 857) != 0XF2334) return false;
	if (GetPixel(453, 858) != 0X184369) return false;
	if (GetPixel(453, 859) != 0X80808) return false;
	if (GetPixel(454, 829) != 0XC1B29) return false;
	if (GetPixel(454, 830) != 0X1A4C7C) return false;
	if (GetPixel(454, 831) != 0X80A0D) return false;
	if (GetPixel(454, 832) != 0X80909) return false;
	if (GetPixel(454, 833) != 0X80C0C) return false;
	if (GetPixel(454, 834) != 0X80F0F) return false;
	if (GetPixel(454, 835) != 0XA0F12) return false;
	if (GetPixel(454, 836) != 0XD1116) return false;
	if (GetPixel(454, 837) != 0XB0F13) return false;
	if (GetPixel(454, 838) != 0XD1116) return false;
	if (GetPixel(454, 839) != 0XC1014) return false;
	if (GetPixel(454, 840) != 0XB0F13) return false;
	if (GetPixel(454, 841) != 0XB0F13) return false;
	if (GetPixel(454, 842) != 0X50606) return false;
	if (GetPixel(454, 843) != 0X80909) return false;
	if (GetPixel(454, 844) != 0X80509) return false;
	if (GetPixel(454, 845) != 0XB0D10) return false;
	if (GetPixel(454, 846) != 0XC0E10) return false;
	if (GetPixel(454, 847) != 0XD0F10) return false;
	if (GetPixel(454, 848) != 0XC0E10) return false;
	if (GetPixel(454, 849) != 0XD0F10) return false;
	if (GetPixel(454, 850) != 0XB0D10) return false;
	if (GetPixel(454, 851) != 0XB0D10) return false;
	if (GetPixel(454, 852) != 0XB0D10) return false;
	if (GetPixel(454, 853) != 0X80C0D) return false;
	if (GetPixel(454, 854) != 0X80C0D) return false;
	if (GetPixel(454, 855) != 0X8080B) return false;
	if (GetPixel(454, 856) != 0X80508) return false;
	if (GetPixel(454, 857) != 0XF2334) return false;
	if (GetPixel(454, 858) != 0X184369) return false;
	if (GetPixel(454, 859) != 0X80808) return false;
	if (GetPixel(455, 829) != 0XC1B29) return false;
	if (GetPixel(455, 830) != 0X1A4C7C) return false;
	if (GetPixel(455, 831) != 0X80A0D) return false;
	if (GetPixel(455, 832) != 0X80909) return false;
	if (GetPixel(455, 833) != 0X80C0C) return false;
	if (GetPixel(455, 834) != 0X80F0F) return false;
	if (GetPixel(455, 835) != 0XA0F12) return false;
	if (GetPixel(455, 836) != 0XC1014) return false;
	if (GetPixel(455, 837) != 0XB0F13) return false;
	if (GetPixel(455, 838) != 0XC1014) return false;
	if (GetPixel(455, 839) != 0XD1116) return false;
	if (GetPixel(455, 840) != 0XC1014) return false;
	if (GetPixel(455, 841) != 0X6090A) return false;
	if (GetPixel(455, 842) != 0X16285C) return false;
	if (GetPixel(455, 843) != 0X1A307F) return false;
	if (GetPixel(455, 844) != 0X213E8C) return false;
	if (GetPixel(455, 845) != 0XB1D4C) return false;
	if (GetPixel(455, 846) != 0X80A0B) return false;
	if (GetPixel(455, 847) != 0XF1010) return false;
	if (GetPixel(455, 848) != 0XD0F10) return false;
	if (GetPixel(455, 849) != 0XD0F10) return false;
	if (GetPixel(455, 850) != 0XC0E10) return false;
	if (GetPixel(455, 851) != 0XB0D10) return false;
	if (GetPixel(455, 852) != 0XB0D10) return false;
	if (GetPixel(455, 853) != 0X80F0F) return false;
	if (GetPixel(455, 854) != 0X80C0D) return false;
	if (GetPixel(455, 855) != 0X8080B) return false;
	if (GetPixel(455, 856) != 0X8070A) return false;
	if (GetPixel(455, 857) != 0XF2334) return false;
	if (GetPixel(455, 858) != 0X184369) return false;
	if (GetPixel(455, 859) != 0X80808) return false;
	if (GetPixel(456, 829) != 0XC1B29) return false;
	if (GetPixel(456, 830) != 0X1A4C7C) return false;
	if (GetPixel(456, 831) != 0X80A0D) return false;
	if (GetPixel(456, 832) != 0X80909) return false;
	if (GetPixel(456, 833) != 0X80C0C) return false;
	if (GetPixel(456, 834) != 0X80F0F) return false;
	if (GetPixel(456, 835) != 0XA0F12) return false;
	if (GetPixel(456, 836) != 0XB0F13) return false;
	if (GetPixel(456, 837) != 0XB0F13) return false;
	if (GetPixel(456, 838) != 0XB0F13) return false;
	if (GetPixel(456, 839) != 0XB0F14) return false;
	if (GetPixel(456, 840) != 0XA0E12) return false;
	if (GetPixel(456, 841) != 0XF1D41) return false;
	if (GetPixel(456, 842) != 0X16297A) return false;
	if (GetPixel(456, 843) != 0X142684) return false;
	if (GetPixel(456, 844) != 0X1246E1) return false;
	if (GetPixel(456, 845) != 0X184CBE) return false;
	if (GetPixel(456, 846) != 0X1F67E1) return false;
	if (GetPixel(456, 847) != 0X30B0D) return false;
	if (GetPixel(456, 848) != 0XC0E10) return false;
	if (GetPixel(456, 849) != 0XD0F10) return false;
	if (GetPixel(456, 850) != 0XC0E10) return false;
	if (GetPixel(456, 851) != 0XB0D10) return false;
	if (GetPixel(456, 852) != 0XE0F10) return false;
	if (GetPixel(456, 853) != 0X91010) return false;
	if (GetPixel(456, 854) != 0X80C0D) return false;
	if (GetPixel(456, 855) != 0X8080B) return false;
	if (GetPixel(456, 856) != 0X80508) return false;
	if (GetPixel(456, 857) != 0XF2334) return false;
	if (GetPixel(456, 858) != 0X184369) return false;
	if (GetPixel(456, 859) != 0X80808) return false;
	if (GetPixel(457, 829) != 0XC1B29) return false;
	if (GetPixel(457, 830) != 0X1A4C7C) return false;
	if (GetPixel(457, 831) != 0X80A0D) return false;
	if (GetPixel(457, 832) != 0X90909) return false;
	if (GetPixel(457, 833) != 0XC0C0C) return false;
	if (GetPixel(457, 834) != 0XF0F0F) return false;
	if (GetPixel(457, 835) != 0XD1010) return false;
	if (GetPixel(457, 836) != 0XD1010) return false;
	if (GetPixel(457, 837) != 0XD1010) return false;
	if (GetPixel(457, 838) != 0XD1011) return false;
	if (GetPixel(457, 839) != 0XB0F13) return false;
	if (GetPixel(457, 840) != 0X10708) return false;
	if (GetPixel(457, 841) != 0X1E2D7C) return false;
	if (GetPixel(457, 842) != 0X1435A2) return false;
	if (GetPixel(457, 843) != 0X142873) return false;
	if (GetPixel(457, 844) != 0X443DD) return false;
	if (GetPixel(457, 845) != 0X50F3) return false;
	if (GetPixel(457, 846) != 0X62F3) return false;
	if (GetPixel(457, 847) != 0X4ABBEA) return false;
	if (GetPixel(457, 848) != 0X1B3C50) return false;
	if (GetPixel(457, 849) != 0XB0D10) return false;
	if (GetPixel(457, 850) != 0XB0D10) return false;
	if (GetPixel(457, 851) != 0XC0E10) return false;
	if (GetPixel(457, 852) != 0XF1010) return false;
	if (GetPixel(457, 853) != 0X90D10) return false;
	if (GetPixel(457, 854) != 0X80C10) return false;
	if (GetPixel(457, 855) != 0X5090B) return false;
	if (GetPixel(457, 856) != 0X30706) return false;
	if (GetPixel(457, 857) != 0XF2334) return false;
	if (GetPixel(457, 858) != 0X184369) return false;
	if (GetPixel(457, 859) != 0X80808) return false;
	if (GetPixel(458, 829) != 0XC1B29) return false;
	if (GetPixel(458, 830) != 0X1A4C7C) return false;
	if (GetPixel(458, 831) != 0X80A0D) return false;
	if (GetPixel(458, 832) != 0X90909) return false;
	if (GetPixel(458, 833) != 0XC0C0C) return false;
	if (GetPixel(458, 834) != 0XD0D0D) return false;
	if (GetPixel(458, 835) != 0XD1010) return false;
	if (GetPixel(458, 836) != 0XD1010) return false;
	if (GetPixel(458, 837) != 0XD1010) return false;
	if (GetPixel(458, 838) != 0XD1010) return false;
	if (GetPixel(458, 839) != 0X7090A) return false;
	if (GetPixel(458, 840) != 0XD2C62) return false;
	if (GetPixel(458, 841) != 0X224F9E) return false;
	if (GetPixel(458, 842) != 0X1A3C98) return false;
	if (GetPixel(458, 843) != 0X539E9) return false;
	if (GetPixel(458, 844) != 0X46F9) return false;
	if (GetPixel(458, 845) != 0X4FF0) return false;
	if (GetPixel(458, 846) != 0X6FF2) return false;
	if (GetPixel(458, 847) != 0X279FD7) return false;
	if (GetPixel(458, 848) != 0X4AB4F5) return false;
	if (GetPixel(458, 849) != 0X60708) return false;
	if (GetPixel(458, 850) != 0XC0E10) return false;
	if (GetPixel(458, 851) != 0XF1010) return false;
	if (GetPixel(458, 852) != 0X101010) return false;
	if (GetPixel(458, 853) != 0X90D10) return false;
	if (GetPixel(458, 854) != 0X80C10) return false;
	if (GetPixel(458, 855) != 0X5090B) return false;
	if (GetPixel(458, 856) != 0X30705) return false;
	if (GetPixel(458, 857) != 0XF2334) return false;
	if (GetPixel(458, 858) != 0X184369) return false;
	if (GetPixel(458, 859) != 0X80808) return false;
	if (GetPixel(459, 829) != 0XC1B29) return false;
	if (GetPixel(459, 830) != 0X1A4C7C) return false;
	if (GetPixel(459, 831) != 0X80A0D) return false;
	if (GetPixel(459, 832) != 0X90909) return false;
	if (GetPixel(459, 833) != 0XC0C0C) return false;
	if (GetPixel(459, 834) != 0XF0F0F) return false;
	if (GetPixel(459, 835) != 0XD1010) return false;
	if (GetPixel(459, 836) != 0XD1010) return false;
	if (GetPixel(459, 837) != 0XD1010) return false;
	if (GetPixel(459, 838) != 0XB1010) return false;
	if (GetPixel(459, 839) != 0X8090B) return false;
	if (GetPixel(459, 840) != 0XB1B3F) return false;
	if (GetPixel(459, 841) != 0X8204A) return false;
	if (GetPixel(459, 842) != 0X2F60D5) return false;
	if (GetPixel(459, 843) != 0X131F4) return false;
	if (GetPixel(459, 844) != 0X44FC) return false;
	if (GetPixel(459, 845) != 0X3BDB) return false;
	if (GetPixel(459, 846) != 0X99FC) return false;
	if (GetPixel(459, 847) != 0X17B2F5) return false;
	if (GetPixel(459, 848) != 0X31937) return false;
	if (GetPixel(459, 849) != 0XB0D10) return false;
	if (GetPixel(459, 850) != 0XB0D10) return false;
	if (GetPixel(459, 851) != 0XB0D10) return false;
	if (GetPixel(459, 852) != 0XC0E10) return false;
	if (GetPixel(459, 853) != 0X90C10) return false;
	if (GetPixel(459, 854) != 0X80C10) return false;
	if (GetPixel(459, 855) != 0X5090B) return false;
	if (GetPixel(459, 856) != 0X30705) return false;
	if (GetPixel(459, 857) != 0XF2334) return false;
	if (GetPixel(459, 858) != 0X184369) return false;
	if (GetPixel(459, 859) != 0X80808) return false;
	if (GetPixel(460, 829) != 0XC1B29) return false;
	if (GetPixel(460, 830) != 0X1A4C7C) return false;
	if (GetPixel(460, 831) != 0X80A0D) return false;
	if (GetPixel(460, 832) != 0X90909) return false;
	if (GetPixel(460, 833) != 0XC0C0C) return false;
	if (GetPixel(460, 834) != 0XE0E0E) return false;
	if (GetPixel(460, 835) != 0XD0F10) return false;
	if (GetPixel(460, 836) != 0XC1010) return false;
	if (GetPixel(460, 837) != 0XB1010) return false;
	if (GetPixel(460, 838) != 0XB1010) return false;
	if (GetPixel(460, 839) != 0X6080A) return false;
	if (GetPixel(460, 840) != 0X101931) return false;
	if (GetPixel(460, 841) != 0X1D2D84) return false;
	if (GetPixel(460, 842) != 0X103CDE) return false;
	if (GetPixel(460, 843) != 0X32E6) return false;
	if (GetPixel(460, 844) != 0X40E0) return false;
	if (GetPixel(460, 845) != 0X52E6) return false;
	if (GetPixel(460, 846) != 0X97F8) return false;
	if (GetPixel(460, 847) != 0X254F) return false;
	if (GetPixel(460, 848) != 0X90C0E) return false;
	if (GetPixel(460, 849) != 0XB0D10) return false;
	if (GetPixel(460, 850) != 0XB0D10) return false;
	if (GetPixel(460, 851) != 0XB0D10) return false;
	if (GetPixel(460, 852) != 0XC0E10) return false;
	if (GetPixel(460, 853) != 0X90C0F) return false;
	if (GetPixel(460, 854) != 0X90C0F) return false;
	if (GetPixel(460, 855) != 0X5090B) return false;
	if (GetPixel(460, 856) != 0X40707) return false;
	if (GetPixel(460, 857) != 0XF2334) return false;
	if (GetPixel(460, 858) != 0X184369) return false;
	if (GetPixel(460, 859) != 0X80808) return false;
	if (GetPixel(461, 829) != 0XC1B29) return false;
	if (GetPixel(461, 830) != 0X1A4C7C) return false;
	if (GetPixel(461, 831) != 0X80A0D) return false;
	if (GetPixel(461, 832) != 0X90909) return false;
	if (GetPixel(461, 833) != 0XC0C0C) return false;
	if (GetPixel(461, 834) != 0XF0F0F) return false;
	if (GetPixel(461, 835) != 0XC1010) return false;
	if (GetPixel(461, 836) != 0XB0F10) return false;
	if (GetPixel(461, 837) != 0XB0F10) return false;
	if (GetPixel(461, 838) != 0XC0F10) return false;
	if (GetPixel(461, 839) != 0X70A0F) return false;
	if (GetPixel(461, 840) != 0X142048) return false;
	if (GetPixel(461, 841) != 0X1F36B7) return false;
	if (GetPixel(461, 842) != 0X831DE) return false;
	if (GetPixel(461, 843) != 0X32ED) return false;
	if (GetPixel(461, 844) != 0X45EE) return false;
	if (GetPixel(461, 845) != 0X4CDE) return false;
	if (GetPixel(461, 846) != 0X71E5) return false;
	if (GetPixel(461, 847) != 0X4070B) return false;
	if (GetPixel(461, 848) != 0X80C0D) return false;
	if (GetPixel(461, 849) != 0X90C0F) return false;
	if (GetPixel(461, 850) != 0XA0D10) return false;
	if (GetPixel(461, 851) != 0XB0D10) return false;
	if (GetPixel(461, 852) != 0XB0D10) return false;
	if (GetPixel(461, 853) != 0XB0C0D) return false;
	if (GetPixel(461, 854) != 0XB0C0D) return false;
	if (GetPixel(461, 855) != 0X7090C) return false;
	if (GetPixel(461, 856) != 0X5080A) return false;
	if (GetPixel(461, 857) != 0XF2334) return false;
	if (GetPixel(461, 858) != 0X184369) return false;
	if (GetPixel(461, 859) != 0X80808) return false;
	if (GetPixel(462, 829) != 0XC1B29) return false;
	if (GetPixel(462, 830) != 0X1A4C7C) return false;
	if (GetPixel(462, 831) != 0X80A0D) return false;
	if (GetPixel(462, 832) != 0X90909) return false;
	if (GetPixel(462, 833) != 0XC0C0C) return false;
	if (GetPixel(462, 834) != 0XE0E0E) return false;
	if (GetPixel(462, 835) != 0XC1010) return false;
	if (GetPixel(462, 836) != 0XC1010) return false;
	if (GetPixel(462, 837) != 0XB0F10) return false;
	if (GetPixel(462, 838) != 0XB0F10) return false;
	if (GetPixel(462, 839) != 0X91129) return false;
	if (GetPixel(462, 840) != 0X111F4E) return false;
	if (GetPixel(462, 841) != 0XF2ACA) return false;
	if (GetPixel(462, 842) != 0X2CF2) return false;
	if (GetPixel(462, 843) != 0X2DE3) return false;
	if (GetPixel(462, 844) != 0X33B5) return false;
	if (GetPixel(462, 845) != 0X3BA8) return false;
	if (GetPixel(462, 846) != 0X10110) return false;
	if (GetPixel(462, 847) != 0X80C0D) return false;
	if (GetPixel(462, 848) != 0X80C0D) return false;
	if (GetPixel(462, 849) != 0X90C0F) return false;
	if (GetPixel(462, 850) != 0X90C10) return false;
	if (GetPixel(462, 851) != 0XA0D10) return false;
	if (GetPixel(462, 852) != 0XB0D10) return false;
	if (GetPixel(462, 853) != 0XB0C0D) return false;
	if (GetPixel(462, 854) != 0XB0C0D) return false;
	if (GetPixel(462, 855) != 0XB0C0D) return false;
	if (GetPixel(462, 856) != 0X5080A) return false;
	if (GetPixel(462, 857) != 0XF2334) return false;
	if (GetPixel(462, 858) != 0X184369) return false;
	if (GetPixel(462, 859) != 0X80808) return false;
	if (GetPixel(463, 829) != 0XC1B29) return false;
	if (GetPixel(463, 830) != 0X1A4C7C) return false;
	if (GetPixel(463, 831) != 0X80A0D) return false;
	if (GetPixel(463, 832) != 0X90909) return false;
	if (GetPixel(463, 833) != 0XC0C0C) return false;
	if (GetPixel(463, 834) != 0XD0D0D) return false;
	if (GetPixel(463, 835) != 0XB0F0F) return false;
	if (GetPixel(463, 836) != 0XC1010) return false;
	if (GetPixel(463, 837) != 0XB0F10) return false;
	if (GetPixel(463, 838) != 0X60809) return false;
	if (GetPixel(463, 839) != 0XC1A2E) return false;
	if (GetPixel(463, 840) != 0XB297B) return false;
	if (GetPixel(463, 841) != 0XA2AC9) return false;
	if (GetPixel(463, 842) != 0X2CDA) return false;
	if (GetPixel(463, 843) != 0X3AEA) return false;
	if (GetPixel(463, 844) != 0X844E5) return false;
	if (GetPixel(463, 845) != 0X10F30) return false;
	if (GetPixel(463, 846) != 0X80C0D) return false;
	if (GetPixel(463, 847) != 0X80C0D) return false;
	if (GetPixel(463, 848) != 0X80C0E) return false;
	if (GetPixel(463, 849) != 0X80C0E) return false;
	if (GetPixel(463, 850) != 0X90C10) return false;
	if (GetPixel(463, 851) != 0X90C10) return false;
	if (GetPixel(463, 852) != 0XA0D10) return false;
	if (GetPixel(463, 853) != 0XB0C0D) return false;
	if (GetPixel(463, 854) != 0XB0C0D) return false;
	if (GetPixel(463, 855) != 0X7090C) return false;
	if (GetPixel(463, 856) != 0X30609) return false;
	if (GetPixel(463, 857) != 0XF2334) return false;
	if (GetPixel(463, 858) != 0X184369) return false;
	if (GetPixel(463, 859) != 0X80808) return false;
	if (GetPixel(464, 829) != 0XC1B27) return false;
	if (GetPixel(464, 830) != 0X1B4B73) return false;
	if (GetPixel(464, 831) != 0X80A0D) return false;
	if (GetPixel(464, 832) != 0X80808) return false;
	if (GetPixel(464, 833) != 0X90909) return false;
	if (GetPixel(464, 834) != 0X90909) return false;
	if (GetPixel(464, 835) != 0XE0F0F) return false;
	if (GetPixel(464, 836) != 0XF1010) return false;
	if (GetPixel(464, 837) != 0XE1010) return false;
	if (GetPixel(464, 838) != 0X20202) return false;
	if (GetPixel(464, 839) != 0XF2347) return false;
	if (GetPixel(464, 840) != 0X2048B9) return false;
	if (GetPixel(464, 841) != 0X294CC5) return false;
	if (GetPixel(464, 842) != 0XF34A9) return false;
	if (GetPixel(464, 843) != 0X1750) return false;
	if (GetPixel(464, 844) != 0X40709) return false;
	if (GetPixel(464, 845) != 0X80D10) return false;
	if (GetPixel(464, 846) != 0XA0D0F) return false;
	if (GetPixel(464, 847) != 0XA0D0F) return false;
	if (GetPixel(464, 848) != 0XB0E10) return false;
	if (GetPixel(464, 849) != 0X80C0E) return false;
	if (GetPixel(464, 850) != 0X80C0D) return false;
	if (GetPixel(464, 851) != 0X80E0F) return false;
	if (GetPixel(464, 852) != 0X90F10) return false;
	if (GetPixel(464, 853) != 0X90A0B) return false;
	if (GetPixel(464, 854) != 0X90909) return false;
	if (GetPixel(464, 855) != 0X70809) return false;
	if (GetPixel(464, 856) != 0X60708) return false;
	if (GetPixel(464, 857) != 0XF2435) return false;
	if (GetPixel(464, 858) != 0X18466B) return false;
	if (GetPixel(464, 859) != 0X80808) return false;
	if (GetPixel(465, 829) != 0XD1B26) return false;
	if (GetPixel(465, 830) != 0X1B4B6F) return false;
	if (GetPixel(465, 831) != 0X80A0D) return false;
	if (GetPixel(465, 832) != 0X80808) return false;
	if (GetPixel(465, 833) != 0X80808) return false;
	if (GetPixel(465, 834) != 0X80808) return false;
	if (GetPixel(465, 835) != 0XD0D0D) return false;
	if (GetPixel(465, 836) != 0XE0E0E) return false;
	if (GetPixel(465, 837) != 0XD0D0D) return false;
	if (GetPixel(465, 838) != 0XD0D0D) return false;
	if (GetPixel(465, 839) != 0X8090C) return false;
	if (GetPixel(465, 840) != 0X20309) return false;
	if (GetPixel(465, 841) != 0X20310) return false;
	if (GetPixel(465, 842) != 0X2030A) return false;
	if (GetPixel(465, 843) != 0X80D10) return false;
	if (GetPixel(465, 844) != 0X80D10) return false;
	if (GetPixel(465, 845) != 0X80D10) return false;
	if (GetPixel(465, 846) != 0XB0D10) return false;
	if (GetPixel(465, 847) != 0XB0D10) return false;
	if (GetPixel(465, 848) != 0XB0D10) return false;
	if (GetPixel(465, 849) != 0X90E10) return false;
	if (GetPixel(465, 850) != 0X80F0F) return false;
	if (GetPixel(465, 851) != 0X80E0E) return false;
	if (GetPixel(465, 852) != 0X80C0C) return false;
	if (GetPixel(465, 853) != 0X80909) return false;
	if (GetPixel(465, 854) != 0X80808) return false;
	if (GetPixel(465, 855) != 0X80808) return false;
	if (GetPixel(465, 856) != 0X80808) return false;
	if (GetPixel(465, 857) != 0XF2536) return false;
	if (GetPixel(465, 858) != 0X18476D) return false;
	if (GetPixel(465, 859) != 0X80808) return false;
	if (GetPixel(466, 829) != 0XD1B26) return false;
	if (GetPixel(466, 830) != 0X1B4B6F) return false;
	if (GetPixel(466, 831) != 0X80A0D) return false;
	if (GetPixel(466, 832) != 0X80808) return false;
	if (GetPixel(466, 833) != 0X80808) return false;
	if (GetPixel(466, 834) != 0X80808) return false;
	if (GetPixel(466, 835) != 0XB0B0B) return false;
	if (GetPixel(466, 836) != 0XD0D0D) return false;
	if (GetPixel(466, 837) != 0XD0D0D) return false;
	if (GetPixel(466, 838) != 0XD0D0D) return false;
	if (GetPixel(466, 839) != 0XC0E10) return false;
	if (GetPixel(466, 840) != 0XC0E10) return false;
	if (GetPixel(466, 841) != 0XB0D10) return false;
	if (GetPixel(466, 842) != 0X90D10) return false;
	if (GetPixel(466, 843) != 0X80D10) return false;
	if (GetPixel(466, 844) != 0X80D10) return false;
	if (GetPixel(466, 845) != 0X80D10) return false;
	if (GetPixel(466, 846) != 0XB0D10) return false;
	if (GetPixel(466, 847) != 0XD0F10) return false;
	if (GetPixel(466, 848) != 0XC0E10) return false;
	if (GetPixel(466, 849) != 0XA0E10) return false;
	if (GetPixel(466, 850) != 0X80F0F) return false;
	if (GetPixel(466, 851) != 0X80C0C) return false;
	if (GetPixel(466, 852) != 0X80B0B) return false;
	if (GetPixel(466, 853) != 0X80808) return false;
	if (GetPixel(466, 854) != 0X80808) return false;
	if (GetPixel(466, 855) != 0X80808) return false;
	if (GetPixel(466, 856) != 0X80808) return false;
	if (GetPixel(466, 857) != 0XF2536) return false;
	if (GetPixel(466, 858) != 0X18476D) return false;
	if (GetPixel(466, 859) != 0X80808) return false;
	if (GetPixel(467, 829) != 0XF2130) return false;
	if (GetPixel(467, 830) != 0X2970AE) return false;
	if (GetPixel(467, 831) != 0X173A5B) return false;
	if (GetPixel(467, 832) != 0X143451) return false;
	if (GetPixel(467, 833) != 0XC161F) return false;
	if (GetPixel(467, 834) != 0X80A0B) return false;
	if (GetPixel(467, 835) != 0X80808) return false;
	if (GetPixel(467, 836) != 0XB0B0B) return false;
	if (GetPixel(467, 837) != 0XB0B0B) return false;
	if (GetPixel(467, 838) != 0XC0D0D) return false;
	if (GetPixel(467, 839) != 0XB0D10) return false;
	if (GetPixel(467, 840) != 0XB0D10) return false;
	if (GetPixel(467, 841) != 0XB0D10) return false;
	if (GetPixel(467, 842) != 0X90D10) return false;
	if (GetPixel(467, 843) != 0X80D10) return false;
	if (GetPixel(467, 844) != 0X80D10) return false;
	if (GetPixel(467, 845) != 0X80D10) return false;
	if (GetPixel(467, 846) != 0XB0D10) return false;
	if (GetPixel(467, 847) != 0XC0D10) return false;
	if (GetPixel(467, 848) != 0XF0F10) return false;
	if (GetPixel(467, 849) != 0XA0D0F) return false;
	if (GetPixel(467, 850) != 0X80C0C) return false;
	if (GetPixel(467, 851) != 0X80909) return false;
	if (GetPixel(467, 852) != 0X80808) return false;
	if (GetPixel(467, 853) != 0X8090A) return false;
	if (GetPixel(467, 854) != 0X90C0E) return false;
	if (GetPixel(467, 855) != 0X143249) return false;
	if (GetPixel(467, 856) != 0X184062) return false;
	if (GetPixel(467, 857) != 0X194771) return false;
	if (GetPixel(467, 858) != 0X18456A) return false;
	if (GetPixel(467, 859) != 0X80808) return false;
	if (GetPixel(468, 829) != 0X12181D) return false;
	if (GetPixel(468, 830) != 0X1E405D) return false;
	if (GetPixel(468, 831) != 0X1B4567) return false;
	if (GetPixel(468, 832) != 0X164E7A) return false;
	if (GetPixel(468, 833) != 0X175686) return false;
	if (GetPixel(468, 834) != 0X113552) return false;
	if (GetPixel(468, 835) != 0XA1117) return false;
	if (GetPixel(468, 836) != 0X80808) return false;
	if (GetPixel(468, 837) != 0X80808) return false;
	if (GetPixel(468, 838) != 0X80909) return false;
	if (GetPixel(468, 839) != 0X80B0E) return false;
	if (GetPixel(468, 840) != 0X80C0F) return false;
	if (GetPixel(468, 841) != 0X80B0D) return false;
	if (GetPixel(468, 842) != 0XA0C0F) return false;
	if (GetPixel(468, 843) != 0XB0D10) return false;
	if (GetPixel(468, 844) != 0XC0D10) return false;
	if (GetPixel(468, 845) != 0XF0F10) return false;
	if (GetPixel(468, 846) != 0XD0F12) return false;
	if (GetPixel(468, 847) != 0XC0D0F) return false;
	if (GetPixel(468, 848) != 0XC0F11) return false;
	if (GetPixel(468, 849) != 0XA0A0B) return false;
	if (GetPixel(468, 850) != 0X80808) return false;
	if (GetPixel(468, 851) != 0X80808) return false;
	if (GetPixel(468, 852) != 0XA0E13) return false;
	if (GetPixel(468, 853) != 0X112840) return false;
	if (GetPixel(468, 854) != 0X1F5A90) return false;
	if (GetPixel(468, 855) != 0X1E568A) return false;
	if (GetPixel(468, 856) != 0X163D5E) return false;
	if (GetPixel(468, 857) != 0X163F62) return false;
	if (GetPixel(468, 858) != 0X132635) return false;
	if (GetPixel(468, 859) != 0X101010) return false;
	if (GetPixel(469, 829) != 0X111417) return false;
	if (GetPixel(469, 830) != 0X101010) return false;
	if (GetPixel(469, 831) != 0XD0B0A) return false;
	if (GetPixel(469, 832) != 0XA0E11) return false;
	if (GetPixel(469, 833) != 0X11324C) return false;
	if (GetPixel(469, 834) != 0X164E79) return false;
	if (GetPixel(469, 835) != 0X153858) return false;
	if (GetPixel(469, 836) != 0X90A0C) return false;
	if (GetPixel(469, 837) != 0X80808) return false;
	if (GetPixel(469, 838) != 0X80909) return false;
	if (GetPixel(469, 839) != 0X80C0F) return false;
	if (GetPixel(469, 840) != 0X80C10) return false;
	if (GetPixel(469, 841) != 0X80C10) return false;
	if (GetPixel(469, 842) != 0XA0D10) return false;
	if (GetPixel(469, 843) != 0XB0D10) return false;
	if (GetPixel(469, 844) != 0XE0F10) return false;
	if (GetPixel(469, 845) != 0XB0D10) return false;
	if (GetPixel(469, 846) != 0XB0C0D) return false;
	if (GetPixel(469, 847) != 0XD1013) return false;
	if (GetPixel(469, 848) != 0XC0E10) return false;
	if (GetPixel(469, 849) != 0XA0A0B) return false;
	if (GetPixel(469, 850) != 0X80808) return false;
	if (GetPixel(469, 851) != 0X80808) return false;
	if (GetPixel(469, 852) != 0X153759) return false;
	if (GetPixel(469, 853) != 0X1C4F80) return false;
	if (GetPixel(469, 854) != 0X143653) return false;
	if (GetPixel(469, 855) != 0XE1B2A) return false;
	if (GetPixel(469, 856) != 0X90909) return false;
	if (GetPixel(469, 857) != 0X101010) return false;
	if (GetPixel(469, 858) != 0X101010) return false;
	if (GetPixel(469, 859) != 0X101010) return false;
	if (GetPixel(470, 829) != 0X15202B) return false;
	if (GetPixel(470, 830) != 0X12171B) return false;
	if (GetPixel(470, 831) != 0XF1317) return false;
	if (GetPixel(470, 832) != 0XA0E11) return false;
	if (GetPixel(470, 833) != 0X90807) return false;
	if (GetPixel(470, 834) != 0XE2637) return false;
	if (GetPixel(470, 835) != 0X1E5688) return false;
	if (GetPixel(470, 836) != 0XF2131) return false;
	if (GetPixel(470, 837) != 0X80808) return false;
	if (GetPixel(470, 838) != 0X80809) return false;
	if (GetPixel(470, 839) != 0X80B0D) return false;
	if (GetPixel(470, 840) != 0X80C0F) return false;
	if (GetPixel(470, 841) != 0X80C0F) return false;
	if (GetPixel(470, 842) != 0XA0C10) return false;
	if (GetPixel(470, 843) != 0XB0E10) return false;
	if (GetPixel(470, 844) != 0XA0D10) return false;
	if (GetPixel(470, 845) != 0XA0D10) return false;
	if (GetPixel(470, 846) != 0XB0C0D) return false;
	if (GetPixel(470, 847) != 0XC0E10) return false;
	if (GetPixel(470, 848) != 0XB0C0C) return false;
	if (GetPixel(470, 849) != 0X90A0A) return false;
	if (GetPixel(470, 850) != 0X80808) return false;
	if (GetPixel(470, 851) != 0XC151F) return false;
	if (GetPixel(470, 852) != 0X1C4C7D) return false;
	if (GetPixel(470, 853) != 0X10253A) return false;
	if (GetPixel(470, 854) != 0X8090A) return false;
	if (GetPixel(470, 855) != 0X80808) return false;
	if (GetPixel(470, 856) != 0X90909) return false;
	if (GetPixel(470, 857) != 0X101010) return false;
	if (GetPixel(470, 858) != 0X101010) return false;
	if (GetPixel(470, 859) != 0X101010) return false;
	if (GetPixel(471, 829) != 0X1B252F) return false;
	if (GetPixel(471, 830) != 0X1B252F) return false;
	if (GetPixel(471, 831) != 0X1A242F) return false;
	if (GetPixel(471, 832) != 0X17232F) return false;
	if (GetPixel(471, 833) != 0X101419) return false;
	if (GetPixel(471, 834) != 0XB1117) return false;
	if (GetPixel(471, 835) != 0X1C4A74) return false;
	if (GetPixel(471, 836) != 0X1B486F) return false;
	if (GetPixel(471, 837) != 0X80808) return false;
	if (GetPixel(471, 838) != 0X80808) return false;
	if (GetPixel(471, 839) != 0X8090A) return false;
	if (GetPixel(471, 840) != 0X80A0B) return false;
	if (GetPixel(471, 841) != 0X80A0B) return false;
	if (GetPixel(471, 842) != 0X90A0B) return false;
	if (GetPixel(471, 843) != 0X80A0C) return false;
	if (GetPixel(471, 844) != 0X80A0C) return false;
	if (GetPixel(471, 845) != 0X80A0C) return false;
	if (GetPixel(471, 846) != 0XA080B) return false;
	if (GetPixel(471, 847) != 0XA080B) return false;
	if (GetPixel(471, 848) != 0X9080A) return false;
	if (GetPixel(471, 849) != 0X8080B) return false;
	if (GetPixel(471, 850) != 0X80C10) return false;
	if (GetPixel(471, 851) != 0X13324E) return false;
	if (GetPixel(471, 852) != 0X1A4876) return false;
	if (GetPixel(471, 853) != 0XB131A) return false;
	if (GetPixel(471, 854) != 0XA0C0D) return false;
	if (GetPixel(471, 855) != 0XD1013) return false;
	if (GetPixel(471, 856) != 0XE1114) return false;
	if (GetPixel(471, 857) != 0X141619) return false;
	if (GetPixel(471, 858) != 0X151719) return false;
	if (GetPixel(471, 859) != 0X141618) return false;
	if (GetPixel(472, 829) != 0X212831) return false;
	if (GetPixel(472, 830) != 0X212831) return false;
	if (GetPixel(472, 831) != 0X212831) return false;
	if (GetPixel(472, 832) != 0X212831) return false;
	if (GetPixel(472, 833) != 0X1A1F25) return false;
	if (GetPixel(472, 834) != 0XC0D0E) return false;
	if (GetPixel(472, 835) != 0X152F48) return false;
	if (GetPixel(472, 836) != 0X1E4C74) return false;
	if (GetPixel(472, 837) != 0X80808) return false;
	if (GetPixel(472, 838) != 0X80808) return false;
	if (GetPixel(472, 839) != 0X80808) return false;
	if (GetPixel(472, 840) != 0X80808) return false;
	if (GetPixel(472, 841) != 0X80808) return false;
	if (GetPixel(472, 842) != 0X80808) return false;
	if (GetPixel(472, 843) != 0X80808) return false;
	if (GetPixel(472, 844) != 0X80808) return false;
	if (GetPixel(472, 845) != 0X80808) return false;
	if (GetPixel(472, 846) != 0X80408) return false;
	if (GetPixel(472, 847) != 0X80408) return false;
	if (GetPixel(472, 848) != 0X80408) return false;
	if (GetPixel(472, 849) != 0X8090E) return false;
	if (GetPixel(472, 850) != 0X81018) return false;
	if (GetPixel(472, 851) != 0X153A58) return false;
	if (GetPixel(472, 852) != 0X112C44) return false;
	if (GetPixel(472, 853) != 0X90B0E) return false;
	if (GetPixel(472, 854) != 0X101419) return false;
	if (GetPixel(472, 855) != 0X13181E) return false;
	if (GetPixel(472, 856) != 0X14191F) return false;
	if (GetPixel(472, 857) != 0X181C21) return false;
	if (GetPixel(472, 858) != 0X191D22) return false;
	if (GetPixel(472, 859) != 0X1B1E23) return false;
	if (GetPixel(473, 829) != 0X1F262D) return false;
	if (GetPixel(473, 830) != 0X1F262D) return false;
	if (GetPixel(473, 831) != 0X20272F) return false;
	if (GetPixel(473, 832) != 0X212831) return false;
	if (GetPixel(473, 833) != 0X1C2228) return false;
	if (GetPixel(473, 834) != 0XC0E0F) return false;
	if (GetPixel(473, 835) != 0X112336) return false;
	if (GetPixel(473, 836) != 0X256098) return false;
	if (GetPixel(473, 837) != 0X101F2F) return false;
	if (GetPixel(473, 838) != 0XF1F2F) return false;
	if (GetPixel(473, 839) != 0XE1F31) return false;
	if (GetPixel(473, 840) != 0XE1F31) return false;
	if (GetPixel(473, 841) != 0XE1F31) return false;
	if (GetPixel(473, 842) != 0XE1F31) return false;
	if (GetPixel(473, 843) != 0XE1F31) return false;
	if (GetPixel(473, 844) != 0XE1F31) return false;
	if (GetPixel(473, 845) != 0XE1F31) return false;
	if (GetPixel(473, 846) != 0XE1C31) return false;
	if (GetPixel(473, 847) != 0XE1C31) return false;
	if (GetPixel(473, 848) != 0XE1C31) return false;
	if (GetPixel(473, 849) != 0XF2036) return false;
	if (GetPixel(473, 850) != 0X10273E) return false;
	if (GetPixel(473, 851) != 0X1D517D) return false;
	if (GetPixel(473, 852) != 0X10293F) return false;
	if (GetPixel(473, 853) != 0XB0E11) return false;
	if (GetPixel(473, 854) != 0X13171D) return false;
	if (GetPixel(473, 855) != 0X171E26) return false;
	if (GetPixel(473, 856) != 0X171E26) return false;
	if (GetPixel(473, 857) != 0X1D2025) return false;
	if (GetPixel(473, 858) != 0X1F2227) return false;
	if (GetPixel(473, 859) != 0X202328) return false;
	if (GetPixel(474, 829) != 0X1C2327) return false;
	if (GetPixel(474, 830) != 0X1C2327) return false;
	if (GetPixel(474, 831) != 0X1B2226) return false;
	if (GetPixel(474, 832) != 0X1D242B) return false;
	if (GetPixel(474, 833) != 0X1C2228) return false;
	if (GetPixel(474, 834) != 0X111418) return false;
	if (GetPixel(474, 835) != 0X122438) return false;
	if (GetPixel(474, 836) != 0X2869A7) return false;
	if (GetPixel(474, 837) != 0X256199) return false;
	if (GetPixel(474, 838) != 0X24619A) return false;
	if (GetPixel(474, 839) != 0X1E61A0) return false;
	if (GetPixel(474, 840) != 0X1E61A0) return false;
	if (GetPixel(474, 841) != 0X1E61A0) return false;
	if (GetPixel(474, 842) != 0X1E61A0) return false;
	if (GetPixel(474, 843) != 0X1E61A0) return false;
	if (GetPixel(474, 844) != 0X1E61A0) return false;
	if (GetPixel(474, 845) != 0X1E61A0) return false;
	if (GetPixel(474, 846) != 0X1E63A0) return false;
	if (GetPixel(474, 847) != 0X1E63A0) return false;
	if (GetPixel(474, 848) != 0X1E63A0) return false;
	if (GetPixel(474, 849) != 0X2165A1) return false;
	if (GetPixel(474, 850) != 0X2569A2) return false;
	if (GetPixel(474, 851) != 0X2770AE) return false;
	if (GetPixel(474, 852) != 0X112C43) return false;
	if (GetPixel(474, 853) != 0XC1014) return false;
	if (GetPixel(474, 854) != 0X171E26) return false;
	if (GetPixel(474, 855) != 0X182029) return false;
	if (GetPixel(474, 856) != 0X192028) return false;
	if (GetPixel(474, 857) != 0X1E2126) return false;
	if (GetPixel(474, 858) != 0X1E2126) return false;
	if (GetPixel(474, 859) != 0X1F2227) return false;
	if (GetPixel(475, 829) != 0X1B2024) return false;
	if (GetPixel(475, 830) != 0X1F2227) return false;
	if (GetPixel(475, 831) != 0X202429) return false;
	if (GetPixel(475, 832) != 0X212429) return false;
	if (GetPixel(475, 833) != 0X1F2227) return false;
	if (GetPixel(475, 834) != 0X191D22) return false;
	if (GetPixel(475, 835) != 0XB1015) return false;
	if (GetPixel(475, 836) != 0XA121A) return false;
	if (GetPixel(475, 837) != 0XF1822) return false;
	if (GetPixel(475, 838) != 0XF1822) return false;
	if (GetPixel(475, 839) != 0XE1822) return false;
	if (GetPixel(475, 840) != 0XE1822) return false;
	if (GetPixel(475, 841) != 0XE1822) return false;
	if (GetPixel(475, 842) != 0XE1822) return false;
	if (GetPixel(475, 843) != 0XE1822) return false;
	if (GetPixel(475, 844) != 0XE1822) return false;
	if (GetPixel(475, 845) != 0XE1822) return false;
	if (GetPixel(475, 846) != 0XE1721) return false;
	if (GetPixel(475, 847) != 0XE1721) return false;
	if (GetPixel(475, 848) != 0XE1721) return false;
	if (GetPixel(475, 849) != 0XF1721) return false;
	if (GetPixel(475, 850) != 0XF1821) return false;
	if (GetPixel(475, 851) != 0XC151D) return false;
	if (GetPixel(475, 852) != 0X90E14) return false;
	if (GetPixel(475, 853) != 0X11161B) return false;
	if (GetPixel(475, 854) != 0X13191F) return false;
	if (GetPixel(475, 855) != 0X161F24) return false;
	if (GetPixel(475, 856) != 0X182429) return false;
	if (GetPixel(475, 857) != 0X182429) return false;
	if (GetPixel(475, 858) != 0X182429) return false;
	if (GetPixel(475, 859) != 0X172126) return false;

	return true;
}
bool				Win32GDI::D3IsOpenUrshi(void)
{
	if (GetPixel(185, 128) != 0X40813) return false;
	if (GetPixel(185, 129) != 0X52C4D) return false;
	if (GetPixel(185, 130) != 0X50611) return false;
	if (GetPixel(185, 131) != 0X40610) return false;
	if (GetPixel(185, 132) != 0X40610) return false;
	if (GetPixel(185, 133) != 0X40611) return false;
	if (GetPixel(185, 134) != 0X40611) return false;
	if (GetPixel(185, 135) != 0X30510) return false;
	if (GetPixel(185, 136) != 0X40612) return false;
	if (GetPixel(185, 137) != 0X60917) return false;
	if (GetPixel(185, 138) != 0X60919) return false;
	if (GetPixel(185, 139) != 0X6091A) return false;
	if (GetPixel(186, 128) != 0X40611) return false;
	if (GetPixel(186, 129) != 0X9FF9) return false;
	if (GetPixel(186, 130) != 0X18ADA) return false;
	if (GetPixel(186, 131) != 0X189D8) return false;
	if (GetPixel(186, 132) != 0X189D8) return false;
	if (GetPixel(186, 133) != 0X89D8) return false;
	if (GetPixel(186, 134) != 0X89D8) return false;
	if (GetPixel(186, 135) != 0X89D8) return false;
	if (GetPixel(186, 136) != 0X189D9) return false;
	if (GetPixel(186, 137) != 0X18ADA) return false;
	if (GetPixel(186, 138) != 0X18ADA) return false;
	if (GetPixel(186, 139) != 0X18BDC) return false;
	if (GetPixel(187, 128) != 0X40611) return false;
	if (GetPixel(187, 129) != 0XA3FF) return false;
	if (GetPixel(187, 130) != 0X44D7D) return false;
	if (GetPixel(187, 131) != 0X54571) return false;
	if (GetPixel(187, 132) != 0X44571) return false;
	if (GetPixel(187, 133) != 0X14573) return false;
	if (GetPixel(187, 134) != 0X14573) return false;
	if (GetPixel(187, 135) != 0X9FFA) return false;
	if (GetPixel(187, 136) != 0X3548B) return false;
	if (GetPixel(187, 137) != 0X54879) return false;
	if (GetPixel(187, 138) != 0X54879) return false;
	if (GetPixel(187, 139) != 0X54776) return false;
	if (GetPixel(188, 128) != 0X40611) return false;
	if (GetPixel(188, 129) != 0XA3FF) return false;
	if (GetPixel(188, 130) != 0X40D19) return false;
	if (GetPixel(188, 131) != 0X4040B) return false;
	if (GetPixel(188, 132) != 0X4040B) return false;
	if (GetPixel(188, 133) != 0X1040B) return false;
	if (GetPixel(188, 134) != 0X1050D) return false;
	if (GetPixel(188, 135) != 0X9DF6) return false;
	if (GetPixel(188, 136) != 0X6345E) return false;
	if (GetPixel(188, 137) != 0X40712) return false;
	if (GetPixel(188, 138) != 0X50712) return false;
	if (GetPixel(188, 139) != 0X50510) return false;
	if (GetPixel(189, 128) != 0X40713) return false;
	if (GetPixel(189, 129) != 0X195E9) return false;
	if (GetPixel(189, 130) != 0X62847) return false;
	if (GetPixel(189, 131) != 0X4050C) return false;
	if (GetPixel(189, 132) != 0X4050C) return false;
	if (GetPixel(189, 133) != 0X3040B) return false;
	if (GetPixel(189, 134) != 0X30B16) return false;
	if (GetPixel(189, 135) != 0XA3FF) return false;
	if (GetPixel(189, 136) != 0X198F0) return false;
	if (GetPixel(189, 137) != 0X72647) return false;
	if (GetPixel(189, 138) != 0X3060F) return false;
	if (GetPixel(189, 139) != 0X3060F) return false;
	if (GetPixel(190, 128) != 0X40713) return false;
	if (GetPixel(190, 129) != 0X365A3) return false;
	if (GetPixel(190, 130) != 0X27DC6) return false;
	if (GetPixel(190, 131) != 0X40E1D) return false;
	if (GetPixel(190, 132) != 0X4050D) return false;
	if (GetPixel(190, 133) != 0X30A14) return false;
	if (GetPixel(190, 134) != 0X276BD) return false;
	if (GetPixel(190, 135) != 0X27ECA) return false;
	if (GetPixel(190, 136) != 0X36BAE) return false;
	if (GetPixel(190, 137) != 0X195EA) return false;
	if (GetPixel(190, 138) != 0X2111F) return false;
	if (GetPixel(190, 139) != 0X3060F) return false;
	if (GetPixel(191, 128) != 0X40713) return false;
	if (GetPixel(191, 129) != 0X50D1A) return false;
	if (GetPixel(191, 130) != 0X27BC2) return false;
	if (GetPixel(191, 131) != 0XA2FD) return false;
	if (GetPixel(191, 132) != 0X192E8) return false;
	if (GetPixel(191, 133) != 0XA1FC) return false;
	if (GetPixel(191, 134) != 0X284D3) return false;
	if (GetPixel(191, 135) != 0X40E1E) return false;
	if (GetPixel(191, 136) != 0X30611) return false;
	if (GetPixel(191, 137) != 0X272B6) return false;
	if (GetPixel(191, 138) != 0X191E5) return false;
	if (GetPixel(191, 139) != 0X31322) return false;
	if (GetPixel(192, 128) != 0X70B1D) return false;
	if (GetPixel(192, 129) != 0X60A1F) return false;
	if (GetPixel(192, 130) != 0X6091A) return false;
	if (GetPixel(192, 131) != 0X62A4D) return false;
	if (GetPixel(192, 132) != 0X54174) return false;
	if (GetPixel(192, 133) != 0X62F57) return false;
	if (GetPixel(192, 134) != 0X6081A) return false;
	if (GetPixel(192, 135) != 0X50715) return false;
	if (GetPixel(192, 136) != 0X40712) return false;
	if (GetPixel(192, 137) != 0X30914) return false;
	if (GetPixel(192, 138) != 0X17AC1) return false;
	if (GetPixel(192, 139) != 0X18DDE) return false;
	if (GetPixel(193, 128) != 0X60B1D) return false;
	if (GetPixel(193, 129) != 0X60A1B) return false;
	if (GetPixel(193, 130) != 0X6091A) return false;
	if (GetPixel(193, 131) != 0X40713) return false;
	if (GetPixel(193, 132) != 0X60918) return false;
	if (GetPixel(193, 133) != 0X60917) return false;
	if (GetPixel(193, 134) != 0X60917) return false;
	if (GetPixel(193, 135) != 0X60815) return false;
	if (GetPixel(193, 136) != 0X60714) return false;
	if (GetPixel(193, 137) != 0X60814) return false;
	if (GetPixel(193, 138) != 0X60B18) return false;
	if (GetPixel(193, 139) != 0X281CB) return false;
	if (GetPixel(194, 128) != 0X50A1A) return false;
	if (GetPixel(194, 129) != 0X50817) return false;
	if (GetPixel(194, 130) != 0X40713) return false;
	if (GetPixel(194, 131) != 0X40712) return false;
	if (GetPixel(194, 132) != 0X40815) return false;
	if (GetPixel(194, 133) != 0X70918) return false;
	if (GetPixel(194, 134) != 0X70919) return false;
	if (GetPixel(194, 135) != 0X70818) return false;
	if (GetPixel(194, 136) != 0X70816) return false;
	if (GetPixel(194, 137) != 0X60815) return false;
	if (GetPixel(194, 138) != 0X60712) return false;
	if (GetPixel(194, 139) != 0X5101E) return false;
	if (GetPixel(195, 128) != 0X30918) return false;
	if (GetPixel(195, 129) != 0X50816) return false;
	if (GetPixel(195, 130) != 0X40712) return false;
	if (GetPixel(195, 131) != 0X30711) return false;
	if (GetPixel(195, 132) != 0X40815) return false;
	if (GetPixel(195, 133) != 0X70918) return false;
	if (GetPixel(195, 134) != 0X7091A) return false;
	if (GetPixel(195, 135) != 0X70919) return false;
	if (GetPixel(195, 136) != 0X70917) return false;
	if (GetPixel(195, 137) != 0X70815) return false;
	if (GetPixel(195, 138) != 0X60813) return false;
	if (GetPixel(195, 139) != 0X60916) return false;
	if (GetPixel(196, 128) != 0X40817) return false;
	if (GetPixel(196, 129) != 0X50817) return false;
	if (GetPixel(196, 130) != 0X60817) return false;
	if (GetPixel(196, 131) != 0X60816) return false;
	if (GetPixel(196, 132) != 0X50714) return false;
	if (GetPixel(196, 133) != 0X40815) return false;
	if (GetPixel(196, 134) != 0X50918) return false;
	if (GetPixel(196, 135) != 0X60919) return false;
	if (GetPixel(196, 136) != 0X60918) return false;
	if (GetPixel(196, 137) != 0X50816) return false;
	if (GetPixel(196, 138) != 0X50815) return false;
	if (GetPixel(196, 139) != 0X30713) return false;
	if (GetPixel(197, 128) != 0X50819) return false;
	if (GetPixel(197, 129) != 0X60715) return false;
	if (GetPixel(197, 130) != 0X70817) return false;
	if (GetPixel(197, 131) != 0X7091A) return false;
	if (GetPixel(197, 132) != 0X60817) return false;
	if (GetPixel(197, 133) != 0X30915) return false;
	if (GetPixel(197, 134) != 0X40916) return false;
	if (GetPixel(197, 135) != 0X50918) return false;
	if (GetPixel(197, 136) != 0X50817) return false;
	if (GetPixel(197, 137) != 0X40715) return false;
	if (GetPixel(197, 138) != 0X40715) return false;
	if (GetPixel(197, 139) != 0X30615) return false;
	if (GetPixel(198, 128) != 0X40818) return false;
	if (GetPixel(198, 129) != 0X51930) return false;
	if (GetPixel(198, 130) != 0X60716) return false;
	if (GetPixel(198, 131) != 0X6091A) return false;
	if (GetPixel(198, 132) != 0X50919) return false;
	if (GetPixel(198, 133) != 0X40814) return false;
	if (GetPixel(198, 134) != 0X40815) return false;
	if (GetPixel(198, 135) != 0X40815) return false;
	if (GetPixel(198, 136) != 0X50816) return false;
	if (GetPixel(198, 137) != 0X50818) return false;
	if (GetPixel(198, 138) != 0X40715) return false;
	if (GetPixel(198, 139) != 0X40715) return false;
	if (GetPixel(199, 128) != 0X6091A) return false;
	if (GetPixel(199, 129) != 0X187D6) return false;
	if (GetPixel(199, 130) != 0X3629F) return false;
	if (GetPixel(199, 131) != 0X3609C) return false;
	if (GetPixel(199, 132) != 0X3619E) return false;
	if (GetPixel(199, 133) != 0X3619D) return false;
	if (GetPixel(199, 134) != 0X1609A) return false;
	if (GetPixel(199, 135) != 0X2609B) return false;
	if (GetPixel(199, 136) != 0X3619D) return false;
	if (GetPixel(199, 137) != 0X3619E) return false;
	if (GetPixel(199, 138) != 0X2609C) return false;
	if (GetPixel(199, 139) != 0X2619E) return false;
	if (GetPixel(200, 128) != 0X70818) return false;
	if (GetPixel(200, 129) != 0X198EF) return false;
	if (GetPixel(200, 130) != 0X27FCA) return false;
	if (GetPixel(200, 131) != 0X27DC7) return false;
	if (GetPixel(200, 132) != 0X27DC7) return false;
	if (GetPixel(200, 133) != 0X27EC8) return false;
	if (GetPixel(200, 134) != 0X17DC6) return false;
	if (GetPixel(200, 135) != 0X17DC7) return false;
	if (GetPixel(200, 136) != 0X27DC8) return false;
	if (GetPixel(200, 137) != 0X27EC8) return false;
	if (GetPixel(200, 138) != 0X27DC8) return false;
	if (GetPixel(200, 139) != 0X27EC8) return false;
	if (GetPixel(201, 128) != 0X7091A) return false;
	if (GetPixel(201, 129) != 0X63055) return false;
	if (GetPixel(201, 130) != 0X60D21) return false;
	if (GetPixel(201, 131) != 0X60A1A) return false;
	if (GetPixel(201, 132) != 0X50612) return false;
	if (GetPixel(201, 133) != 0X20711) return false;
	if (GetPixel(201, 134) != 0X50816) return false;
	if (GetPixel(201, 135) != 0X60918) return false;
	if (GetPixel(201, 136) != 0X60817) return false;
	if (GetPixel(201, 137) != 0X60918) return false;
	if (GetPixel(201, 138) != 0X60919) return false;
	if (GetPixel(201, 139) != 0X60716) return false;
	if (GetPixel(202, 128) != 0X7091A) return false;
	if (GetPixel(202, 129) != 0X70A1C) return false;
	if (GetPixel(202, 130) != 0X70D20) return false;
	if (GetPixel(202, 131) != 0X60A1B) return false;
	if (GetPixel(202, 132) != 0X60714) return false;
	if (GetPixel(202, 133) != 0X20813) return false;
	if (GetPixel(202, 134) != 0X40916) return false;
	if (GetPixel(202, 135) != 0X50917) return false;
	if (GetPixel(202, 136) != 0X60A19) return false;
	if (GetPixel(202, 137) != 0X60919) return false;
	if (GetPixel(202, 138) != 0X70A1B) return false;
	if (GetPixel(202, 139) != 0X7091A) return false;
	if (GetPixel(203, 128) != 0X70A1C) return false;
	if (GetPixel(203, 129) != 0X70A1A) return false;
	if (GetPixel(203, 130) != 0X70919) return false;
	if (GetPixel(203, 131) != 0X70818) return false;
	if (GetPixel(203, 132) != 0X70817) return false;
	if (GetPixel(203, 133) != 0X50816) return false;
	if (GetPixel(203, 134) != 0X50816) return false;
	if (GetPixel(203, 135) != 0X50815) return false;
	if (GetPixel(203, 136) != 0X60919) return false;
	if (GetPixel(203, 137) != 0X70A1C) return false;
	if (GetPixel(203, 138) != 0X70A1C) return false;
	if (GetPixel(203, 139) != 0X70A1D) return false;
	if (GetPixel(204, 128) != 0X7091B) return false;
	if (GetPixel(204, 129) != 0X7091A) return false;
	if (GetPixel(204, 130) != 0X70819) return false;
	if (GetPixel(204, 131) != 0X60614) return false;
	if (GetPixel(204, 132) != 0X60613) return false;
	if (GetPixel(204, 133) != 0X60614) return false;
	if (GetPixel(204, 134) != 0X60615) return false;
	if (GetPixel(204, 135) != 0X60614) return false;
	if (GetPixel(204, 136) != 0X60816) return false;
	if (GetPixel(204, 137) != 0X60919) return false;
	if (GetPixel(204, 138) != 0X60918) return false;
	if (GetPixel(204, 139) != 0X7091A) return false;
	if (GetPixel(205, 128) != 0X7091A) return false;
	if (GetPixel(205, 129) != 0X70A19) return false;
	if (GetPixel(205, 130) != 0X70A1C) return false;
	if (GetPixel(205, 131) != 0X70716) return false;
	if (GetPixel(205, 132) != 0X60615) return false;
	if (GetPixel(205, 133) != 0X60615) return false;
	if (GetPixel(205, 134) != 0X60616) return false;
	if (GetPixel(205, 135) != 0X60617) return false;
	if (GetPixel(205, 136) != 0X60817) return false;
	if (GetPixel(205, 137) != 0X70818) return false;
	if (GetPixel(205, 138) != 0X70817) return false;
	if (GetPixel(205, 139) != 0X70919) return false;
	if (GetPixel(206, 128) != 0X70A1A) return false;
	if (GetPixel(206, 129) != 0X60918) return false;
	if (GetPixel(206, 130) != 0X60818) return false;
	if (GetPixel(206, 131) != 0X60714) return false;
	if (GetPixel(206, 132) != 0X60715) return false;
	if (GetPixel(206, 133) != 0X51124) return false;
	if (GetPixel(206, 134) != 0X50F21) return false;
	if (GetPixel(206, 135) != 0X51125) return false;
	if (GetPixel(206, 136) != 0X60A19) return false;
	if (GetPixel(206, 137) != 0X60815) return false;
	if (GetPixel(206, 138) != 0X60715) return false;
	if (GetPixel(206, 139) != 0X70716) return false;
	if (GetPixel(207, 128) != 0X70A1B) return false;
	if (GetPixel(207, 129) != 0X5162B) return false;
	if (GetPixel(207, 130) != 0X51326) return false;
	if (GetPixel(207, 131) != 0X41223) return false;
	if (GetPixel(207, 132) != 0X41221) return false;
	if (GetPixel(207, 133) != 0X54A7B) return false;
	if (GetPixel(207, 134) != 0XA3FF) return false;
	if (GetPixel(207, 135) != 0X45F9B) return false;
	if (GetPixel(207, 136) != 0X41327) return false;
	if (GetPixel(207, 137) != 0X51327) return false;
	if (GetPixel(207, 138) != 0X5132A) return false;
	if (GetPixel(207, 139) != 0X5152D) return false;
	if (GetPixel(208, 128) != 0X60817) return false;
	if (GetPixel(208, 129) != 0XA3FF) return false;
	if (GetPixel(208, 130) != 0XA3FF) return false;
	if (GetPixel(208, 131) != 0XA3FF) return false;
	if (GetPixel(208, 132) != 0XA3FF) return false;
	if (GetPixel(208, 133) != 0XA3FF) return false;
	if (GetPixel(208, 134) != 0XA3FF) return false;
	if (GetPixel(208, 135) != 0XA3FF) return false;
	if (GetPixel(208, 136) != 0XA3FF) return false;
	if (GetPixel(208, 137) != 0XA3FF) return false;
	if (GetPixel(208, 138) != 0XA3FF) return false;
	if (GetPixel(208, 139) != 0XA3FF) return false;
	if (GetPixel(209, 128) != 0X60818) return false;
	if (GetPixel(209, 129) != 0XA3FF) return false;
	if (GetPixel(209, 130) != 0X63965) return false;
	if (GetPixel(209, 131) != 0X40F1E) return false;
	if (GetPixel(209, 132) != 0X40E1C) return false;
	if (GetPixel(209, 133) != 0X30F1C) return false;
	if (GetPixel(209, 134) != 0XA3FF) return false;
	if (GetPixel(209, 135) != 0X53B65) return false;
	if (GetPixel(209, 136) != 0X40F1F) return false;
	if (GetPixel(209, 137) != 0X41023) return false;
	if (GetPixel(209, 138) != 0X51126) return false;
	if (GetPixel(209, 139) != 0X61429) return false;
	if (GetPixel(210, 128) != 0X60919) return false;
	if (GetPixel(210, 129) != 0XA3FF) return false;
	if (GetPixel(210, 130) != 0X62C52) return false;
	if (GetPixel(210, 131) != 0X40612) return false;
	if (GetPixel(210, 132) != 0X40611) return false;
	if (GetPixel(210, 133) != 0X40915) return false;
	if (GetPixel(210, 134) != 0XA3FF) return false;
	if (GetPixel(210, 135) != 0X62E52) return false;
	if (GetPixel(210, 136) != 0X50513) return false;
	if (GetPixel(210, 137) != 0X50516) return false;
	if (GetPixel(210, 138) != 0X60618) return false;
	if (GetPixel(210, 139) != 0X60617) return false;
	if (GetPixel(211, 128) != 0X6091A) return false;
	if (GetPixel(211, 129) != 0XA3FF) return false;
	if (GetPixel(211, 130) != 0X62D53) return false;
	if (GetPixel(211, 131) != 0X50714) return false;
	if (GetPixel(211, 132) != 0X50714) return false;
	if (GetPixel(211, 133) != 0X40A18) return false;
	if (GetPixel(211, 134) != 0XA3FF) return false;
	if (GetPixel(211, 135) != 0X63054) return false;
	if (GetPixel(211, 136) != 0X50713) return false;
	if (GetPixel(211, 137) != 0X60816) return false;
	if (GetPixel(211, 138) != 0X60917) return false;
	if (GetPixel(211, 139) != 0X70A1A) return false;
	if (GetPixel(212, 128) != 0X6091B) return false;
	if (GetPixel(212, 129) != 0XA3FF) return false;
	if (GetPixel(212, 130) != 0X62E54) return false;
	if (GetPixel(212, 131) != 0X50816) return false;
	if (GetPixel(212, 132) != 0X50716) return false;
	if (GetPixel(212, 133) != 0X50C1C) return false;
	if (GetPixel(212, 134) != 0XA3FF) return false;
	if (GetPixel(212, 135) != 0X63154) return false;
	if (GetPixel(212, 136) != 0X60814) return false;
	if (GetPixel(212, 137) != 0X60917) return false;
	if (GetPixel(212, 138) != 0X60918) return false;
	if (GetPixel(212, 139) != 0X70A1B) return false;
	if (GetPixel(213, 128) != 0X54171) return false;
	if (GetPixel(213, 129) != 0XA3FF) return false;
	if (GetPixel(213, 130) != 0X45F9C) return false;
	if (GetPixel(213, 131) != 0X60D1F) return false;
	if (GetPixel(213, 132) != 0X6091A) return false;
	if (GetPixel(213, 133) != 0X44F84) return false;
	if (GetPixel(213, 134) != 0X9AF2) return false;
	if (GetPixel(213, 135) != 0X3619F) return false;
	if (GetPixel(213, 136) != 0X70F21) return false;
	if (GetPixel(213, 137) != 0X70A18) return false;
	if (GetPixel(213, 138) != 0X70A1B) return false;
	if (GetPixel(213, 139) != 0X80B1D) return false;
	if (GetPixel(214, 128) != 0X71229) return false;
	if (GetPixel(214, 129) != 0X60B1E) return false;
	if (GetPixel(214, 130) != 0X60F23) return false;
	if (GetPixel(214, 131) != 0X60D20) return false;
	if (GetPixel(214, 132) != 0X70A1D) return false;
	if (GetPixel(214, 133) != 0X70B1D) return false;
	if (GetPixel(214, 134) != 0X60A1B) return false;
	if (GetPixel(214, 135) != 0X70A1C) return false;
	if (GetPixel(214, 136) != 0X70A1A) return false;
	if (GetPixel(214, 137) != 0X70B17) return false;
	if (GetPixel(214, 138) != 0X80B1C) return false;
	if (GetPixel(214, 139) != 0X80C21) return false;
	if (GetPixel(215, 128) != 0X70B1E) return false;
	if (GetPixel(215, 129) != 0X6091A) return false;
	if (GetPixel(215, 130) != 0X60A1C) return false;
	if (GetPixel(215, 131) != 0X70A1D) return false;
	if (GetPixel(215, 132) != 0X70A1E) return false;
	if (GetPixel(215, 133) != 0X70B1E) return false;
	if (GetPixel(215, 134) != 0X70B1D) return false;
	if (GetPixel(215, 135) != 0X70B1D) return false;
	if (GetPixel(215, 136) != 0X70B18) return false;
	if (GetPixel(215, 137) != 0X80B1A) return false;
	if (GetPixel(215, 138) != 0X80C1F) return false;
	if (GetPixel(215, 139) != 0X80C23) return false;
	if (GetPixel(216, 128) != 0X70B1E) return false;
	if (GetPixel(216, 129) != 0X6091A) return false;
	if (GetPixel(216, 130) != 0X70A1D) return false;
	if (GetPixel(216, 131) != 0X70A1E) return false;
	if (GetPixel(216, 132) != 0X70B1E) return false;
	if (GetPixel(216, 133) != 0X70B1C) return false;
	if (GetPixel(216, 134) != 0X70C20) return false;
	if (GetPixel(216, 135) != 0X80B1E) return false;
	if (GetPixel(216, 136) != 0X80C1F) return false;
	if (GetPixel(216, 137) != 0X80C21) return false;
	if (GetPixel(216, 138) != 0X80C22) return false;
	if (GetPixel(216, 139) != 0X80C27) return false;
	if (GetPixel(217, 128) != 0X54372) return false;
	if (GetPixel(217, 129) != 0X45D98) return false;
	if (GetPixel(217, 130) != 0X54E82) return false;
	if (GetPixel(217, 131) != 0X61126) return false;
	if (GetPixel(217, 132) != 0X70A1C) return false;
	if (GetPixel(217, 133) != 0X70B1F) return false;
	if (GetPixel(217, 134) != 0X70C21) return false;
	if (GetPixel(217, 135) != 0X80D22) return false;
	if (GetPixel(217, 136) != 0X80C1F) return false;
	if (GetPixel(217, 137) != 0X80C1E) return false;
	if (GetPixel(217, 138) != 0X80C22) return false;
	if (GetPixel(217, 139) != 0X80C29) return false;
	if (GetPixel(218, 128) != 0X61023) return false;
	if (GetPixel(218, 129) != 0XA3FF) return false;
	if (GetPixel(218, 130) != 0X6355B) return false;
	if (GetPixel(218, 131) != 0X60A1C) return false;
	if (GetPixel(218, 132) != 0X70A1E) return false;
	if (GetPixel(218, 133) != 0X70A1D) return false;
	if (GetPixel(218, 134) != 0X70B20) return false;
	if (GetPixel(218, 135) != 0X80C21) return false;
	if (GetPixel(218, 136) != 0X80B1E) return false;
	if (GetPixel(218, 137) != 0X80B1D) return false;
	if (GetPixel(218, 138) != 0X80B1D) return false;
	if (GetPixel(218, 139) != 0X80D22) return false;
	if (GetPixel(219, 128) != 0X60918) return false;
	if (GetPixel(219, 129) != 0XA3FF) return false;
	if (GetPixel(219, 130) != 0X62D4F) return false;
	if (GetPixel(219, 131) != 0X60919) return false;
	if (GetPixel(219, 132) != 0X6091B) return false;
	if (GetPixel(219, 133) != 0X6091A) return false;
	if (GetPixel(219, 134) != 0X70A1D) return false;
	if (GetPixel(219, 135) != 0X70A1E) return false;
	if (GetPixel(219, 136) != 0X70A1B) return false;
	if (GetPixel(219, 137) != 0X70A1A) return false;
	if (GetPixel(219, 138) != 0X70A1B) return false;
	if (GetPixel(219, 139) != 0X70C1F) return false;
	if (GetPixel(220, 128) != 0X60918) return false;
	if (GetPixel(220, 129) != 0XA3FF) return false;
	if (GetPixel(220, 130) != 0X62D50) return false;
	if (GetPixel(220, 131) != 0X50818) return false;
	if (GetPixel(220, 132) != 0X60919) return false;
	if (GetPixel(220, 133) != 0X6091A) return false;
	if (GetPixel(220, 134) != 0X70A1C) return false;
	if (GetPixel(220, 135) != 0X70A1C) return false;
	if (GetPixel(220, 136) != 0X7091A) return false;
	if (GetPixel(220, 137) != 0X70919) return false;
	if (GetPixel(220, 138) != 0X70B1D) return false;
	if (GetPixel(220, 139) != 0X70C1F) return false;
	if (GetPixel(221, 128) != 0X60918) return false;
	if (GetPixel(221, 129) != 0XA3FF) return false;
	if (GetPixel(221, 130) != 0X62D53) return false;
	if (GetPixel(221, 131) != 0X50716) return false;
	if (GetPixel(221, 132) != 0X50817) return false;
	if (GetPixel(221, 133) != 0X50817) return false;
	if (GetPixel(221, 134) != 0X6091A) return false;
	if (GetPixel(221, 135) != 0X60919) return false;
	if (GetPixel(221, 136) != 0X60918) return false;
	if (GetPixel(221, 137) != 0X60918) return false;
	if (GetPixel(221, 138) != 0X60A1C) return false;
	if (GetPixel(221, 139) != 0X60C22) return false;
	if (GetPixel(222, 128) != 0X60918) return false;
	if (GetPixel(222, 129) != 0XA3FF) return false;
	if (GetPixel(222, 130) != 0X45B97) return false;
	if (GetPixel(222, 131) != 0X5487B) return false;
	if (GetPixel(222, 132) != 0X54779) return false;
	if (GetPixel(222, 133) != 0X54779) return false;
	if (GetPixel(222, 134) != 0X54779) return false;
	if (GetPixel(222, 135) != 0X54778) return false;
	if (GetPixel(222, 136) != 0X54779) return false;
	if (GetPixel(222, 137) != 0X54779) return false;
	if (GetPixel(222, 138) != 0X5487A) return false;
	if (GetPixel(222, 139) != 0X54B81) return false;
	if (GetPixel(223, 128) != 0X60918) return false;
	if (GetPixel(223, 129) != 0XA3FF) return false;
	if (GetPixel(223, 130) != 0X193E8) return false;
	if (GetPixel(223, 131) != 0X18EE1) return false;
	if (GetPixel(223, 132) != 0X18EE1) return false;
	if (GetPixel(223, 133) != 0X18EE1) return false;
	if (GetPixel(223, 134) != 0X18EE1) return false;
	if (GetPixel(223, 135) != 0X18EE1) return false;
	if (GetPixel(223, 136) != 0X18EE1) return false;
	if (GetPixel(223, 137) != 0X18EE1) return false;
	if (GetPixel(223, 138) != 0X18EE1) return false;
	if (GetPixel(223, 139) != 0X190E4) return false;
	if (GetPixel(224, 128) != 0X60919) return false;
	if (GetPixel(224, 129) != 0XA3FF) return false;
	if (GetPixel(224, 130) != 0X62C53) return false;
	if (GetPixel(224, 131) != 0X50716) return false;
	if (GetPixel(224, 132) != 0X50717) return false;
	if (GetPixel(224, 133) != 0X50817) return false;
	if (GetPixel(224, 134) != 0X6091A) return false;
	if (GetPixel(224, 135) != 0X6091B) return false;
	if (GetPixel(224, 136) != 0X6091B) return false;
	if (GetPixel(224, 137) != 0X6091A) return false;
	if (GetPixel(224, 138) != 0X60A1C) return false;
	if (GetPixel(224, 139) != 0X60C23) return false;
	if (GetPixel(225, 128) != 0X60819) return false;
	if (GetPixel(225, 129) != 0XA3FF) return false;
	if (GetPixel(225, 130) != 0X62C53) return false;
	if (GetPixel(225, 131) != 0X50717) return false;
	if (GetPixel(225, 132) != 0X60818) return false;
	if (GetPixel(225, 133) != 0X60818) return false;
	if (GetPixel(225, 134) != 0X6091B) return false;
	if (GetPixel(225, 135) != 0X60A1B) return false;
	if (GetPixel(225, 136) != 0X60A1C) return false;
	if (GetPixel(225, 137) != 0X60A1C) return false;
	if (GetPixel(225, 138) != 0X70A1D) return false;
	if (GetPixel(225, 139) != 0X70B1F) return false;
	if (GetPixel(226, 128) != 0X6091D) return false;
	if (GetPixel(226, 129) != 0XA3FF) return false;
	if (GetPixel(226, 130) != 0X62C53) return false;
	if (GetPixel(226, 131) != 0X60818) return false;
	if (GetPixel(226, 132) != 0X6081A) return false;
	if (GetPixel(226, 133) != 0X6091A) return false;
	if (GetPixel(226, 134) != 0X70A1D) return false;
	if (GetPixel(226, 135) != 0X70A1E) return false;
	if (GetPixel(226, 136) != 0X70A1D) return false;
	if (GetPixel(226, 137) != 0X70A1E) return false;
	if (GetPixel(226, 138) != 0X70A1F) return false;
	if (GetPixel(226, 139) != 0X70B1F) return false;
	if (GetPixel(227, 128) != 0X6091B) return false;
	if (GetPixel(227, 129) != 0XA3FF) return false;
	if (GetPixel(227, 130) != 0X62E55) return false;
	if (GetPixel(227, 131) != 0X6081A) return false;
	if (GetPixel(227, 132) != 0X6091C) return false;
	if (GetPixel(227, 133) != 0X70A1C) return false;
	if (GetPixel(227, 134) != 0X70B1E) return false;
	if (GetPixel(227, 135) != 0X70B1F) return false;
	if (GetPixel(227, 136) != 0X70B1F) return false;
	if (GetPixel(227, 137) != 0X70B20) return false;
	if (GetPixel(227, 138) != 0X70B20) return false;
	if (GetPixel(227, 139) != 0X70B1C) return false;
	if (GetPixel(228, 128) != 0X54273) return false;
	if (GetPixel(228, 129) != 0XA3FF) return false;
	if (GetPixel(228, 130) != 0X461A0) return false;
	if (GetPixel(228, 131) != 0X70F25) return false;
	if (GetPixel(228, 132) != 0X70A1F) return false;
	if (GetPixel(228, 133) != 0X70B20) return false;
	if (GetPixel(228, 134) != 0X80C21) return false;
	if (GetPixel(228, 135) != 0X80C21) return false;
	if (GetPixel(228, 136) != 0X80C22) return false;
	if (GetPixel(228, 137) != 0X80C23) return false;
	if (GetPixel(228, 138) != 0X80C1F) return false;
	if (GetPixel(228, 139) != 0X80C1E) return false;
	if (GetPixel(229, 128) != 0X70F24) return false;
	if (GetPixel(229, 129) != 0X70A1E) return false;
	if (GetPixel(229, 130) != 0X70D24) return false;
	if (GetPixel(229, 131) != 0X70D22) return false;
	if (GetPixel(229, 132) != 0X70B20) return false;
	if (GetPixel(229, 133) != 0X80B1F) return false;
	if (GetPixel(229, 134) != 0X80C20) return false;
	if (GetPixel(229, 135) != 0X80C20) return false;
	if (GetPixel(229, 136) != 0X80B1E) return false;
	if (GetPixel(229, 137) != 0X80C20) return false;
	if (GetPixel(229, 138) != 0X80B1E) return false;
	if (GetPixel(229, 139) != 0X80C21) return false;
	if (GetPixel(230, 128) != 0X70C1F) return false;
	if (GetPixel(230, 129) != 0X70A1D) return false;
	if (GetPixel(230, 130) != 0X70B1F) return false;
	if (GetPixel(230, 131) != 0X70B1F) return false;
	if (GetPixel(230, 132) != 0X80B1F) return false;
	if (GetPixel(230, 133) != 0X80C20) return false;
	if (GetPixel(230, 134) != 0X80C21) return false;
	if (GetPixel(230, 135) != 0X80C1F) return false;
	if (GetPixel(230, 136) != 0X80B1E) return false;
	if (GetPixel(230, 137) != 0X80B1E) return false;
	if (GetPixel(230, 138) != 0X80B1E) return false;
	if (GetPixel(230, 139) != 0X80C20) return false;
	if (GetPixel(231, 128) != 0X80C21) return false;
	if (GetPixel(231, 129) != 0X70B1F) return false;
	if (GetPixel(231, 130) != 0X80B1F) return false;
	if (GetPixel(231, 131) != 0X80C21) return false;
	if (GetPixel(231, 132) != 0X80C20) return false;
	if (GetPixel(231, 133) != 0X80C1F) return false;
	if (GetPixel(231, 134) != 0X80C1F) return false;
	if (GetPixel(231, 135) != 0X80C1E) return false;
	if (GetPixel(231, 136) != 0X80B1E) return false;
	if (GetPixel(231, 137) != 0X80B1E) return false;
	if (GetPixel(231, 138) != 0X80B1E) return false;
	if (GetPixel(231, 139) != 0X80B1E) return false;
	if (GetPixel(232, 128) != 0X80C21) return false;
	if (GetPixel(232, 129) != 0X80C20) return false;
	if (GetPixel(232, 130) != 0X80B1E) return false;
	if (GetPixel(232, 131) != 0X80C21) return false;
	if (GetPixel(232, 132) != 0X80C1F) return false;
	if (GetPixel(232, 133) != 0X80C1E) return false;
	if (GetPixel(232, 134) != 0X80C1E) return false;
	if (GetPixel(232, 135) != 0X80C1C) return false;
	if (GetPixel(232, 136) != 0X80B1E) return false;
	if (GetPixel(232, 137) != 0X80B20) return false;
	if (GetPixel(232, 138) != 0X80B20) return false;
	if (GetPixel(232, 139) != 0X80B20) return false;
	if (GetPixel(233, 128) != 0X80C21) return false;
	if (GetPixel(233, 129) != 0X80B1F) return false;
	if (GetPixel(233, 130) != 0X80C20) return false;
	if (GetPixel(233, 131) != 0X80C21) return false;
	if (GetPixel(233, 132) != 0X80B1F) return false;
	if (GetPixel(233, 133) != 0X80C1D) return false;
	if (GetPixel(233, 134) != 0X80C1A) return false;
	if (GetPixel(233, 135) != 0X80C1B) return false;
	if (GetPixel(233, 136) != 0X80B1F) return false;
	if (GetPixel(233, 137) != 0X80B21) return false;
	if (GetPixel(233, 138) != 0X80B21) return false;
	if (GetPixel(233, 139) != 0X80B21) return false;
	if (GetPixel(234, 128) != 0X80C21) return false;
	if (GetPixel(234, 129) != 0X80B1F) return false;
	if (GetPixel(234, 130) != 0X80B1F) return false;
	if (GetPixel(234, 131) != 0X80B1F) return false;
	if (GetPixel(234, 132) != 0X80A1B) return false;
	if (GetPixel(234, 133) != 0X80C19) return false;
	if (GetPixel(234, 134) != 0X80C1A) return false;
	if (GetPixel(234, 135) != 0X80C1D) return false;
	if (GetPixel(234, 136) != 0X80B20) return false;
	if (GetPixel(234, 137) != 0X80B21) return false;
	if (GetPixel(234, 138) != 0X80B21) return false;
	if (GetPixel(234, 139) != 0X80B21) return false;
	if (GetPixel(235, 128) != 0X80C21) return false;
	if (GetPixel(235, 129) != 0X80C21) return false;
	if (GetPixel(235, 130) != 0X80C21) return false;
	if (GetPixel(235, 131) != 0X80B1E) return false;
	if (GetPixel(235, 132) != 0X80B1D) return false;
	if (GetPixel(235, 133) != 0X80C19) return false;
	if (GetPixel(235, 134) != 0X80C1E) return false;
	if (GetPixel(235, 135) != 0X80C1E) return false;
	if (GetPixel(235, 136) != 0X80B20) return false;
	if (GetPixel(235, 137) != 0X80B21) return false;
	if (GetPixel(235, 138) != 0X80B21) return false;
	if (GetPixel(235, 139) != 0X80D28) return false;
	if (GetPixel(236, 128) != 0X80B1E) return false;
	if (GetPixel(236, 129) != 0X80B1E) return false;
	if (GetPixel(236, 130) != 0X80D23) return false;
	if (GetPixel(236, 131) != 0X80B1D) return false;
	if (GetPixel(236, 132) != 0X80B1D) return false;
	if (GetPixel(236, 133) != 0X80B1D) return false;
	if (GetPixel(236, 134) != 0X80A1D) return false;
	if (GetPixel(236, 135) != 0X80A1D) return false;
	if (GetPixel(236, 136) != 0X80B1F) return false;
	if (GetPixel(236, 137) != 0X80D23) return false;
	if (GetPixel(236, 138) != 0X80F2A) return false;
	if (GetPixel(236, 139) != 0X80F2B) return false;
	if (GetPixel(237, 128) != 0X80B1E) return false;
	if (GetPixel(237, 129) != 0X80B1D) return false;
	if (GetPixel(237, 130) != 0X80C22) return false;
	if (GetPixel(237, 131) != 0X70A1C) return false;
	if (GetPixel(237, 132) != 0X70A1B) return false;
	if (GetPixel(237, 133) != 0X70A1B) return false;
	if (GetPixel(237, 134) != 0X70A1B) return false;
	if (GetPixel(237, 135) != 0X70A1B) return false;
	if (GetPixel(237, 136) != 0X70B1F) return false;
	if (GetPixel(237, 137) != 0X70E2A) return false;
	if (GetPixel(237, 138) != 0X70F2E) return false;
	if (GetPixel(237, 139) != 0X80C25) return false;
	if (GetPixel(238, 128) != 0X80C1F) return false;
	if (GetPixel(238, 129) != 0X80C21) return false;
	if (GetPixel(238, 130) != 0X70D21) return false;
	if (GetPixel(238, 131) != 0X70C20) return false;
	if (GetPixel(238, 132) != 0X7091B) return false;
	if (GetPixel(238, 133) != 0X7091A) return false;
	if (GetPixel(238, 134) != 0X7091A) return false;
	if (GetPixel(238, 135) != 0X70A1A) return false;
	if (GetPixel(238, 136) != 0X70C21) return false;
	if (GetPixel(238, 137) != 0X70D28) return false;
	if (GetPixel(238, 138) != 0X70D26) return false;
	if (GetPixel(238, 139) != 0X70B1F) return false;
	if (GetPixel(239, 128) != 0X80F27) return false;
	if (GetPixel(239, 129) != 0X70F27) return false;
	if (GetPixel(239, 130) != 0X70E24) return false;
	if (GetPixel(239, 131) != 0X70D24) return false;
	if (GetPixel(239, 132) != 0X60B1E) return false;
	if (GetPixel(239, 133) != 0X60B1E) return false;
	if (GetPixel(239, 134) != 0X60B1D) return false;
	if (GetPixel(239, 135) != 0X60C1F) return false;
	if (GetPixel(239, 136) != 0X60C20) return false;
	if (GetPixel(239, 137) != 0X60A1E) return false;
	if (GetPixel(239, 138) != 0X70A1C) return false;
	if (GetPixel(239, 139) != 0X70A1D) return false;
	if (GetPixel(240, 128) != 0X70F25) return false;
	if (GetPixel(240, 129) != 0X70E28) return false;
	if (GetPixel(240, 130) != 0X60B21) return false;
	if (GetPixel(240, 131) != 0X60B21) return false;
	if (GetPixel(240, 132) != 0X62B52) return false;
	if (GetPixel(240, 133) != 0X363A3) return false;
	if (GetPixel(240, 134) != 0X27CC7) return false;
	if (GetPixel(240, 135) != 0X27CC7) return false;
	if (GetPixel(240, 136) != 0X363A2) return false;
	if (GetPixel(240, 137) != 0X6294C) return false;
	if (GetPixel(240, 138) != 0X60A1A) return false;
	if (GetPixel(240, 139) != 0X60A1B) return false;
	if (GetPixel(241, 128) != 0X70B1D) return false;
	if (GetPixel(241, 129) != 0X60B1F) return false;
	if (GetPixel(241, 130) != 0X60C1D) return false;
	if (GetPixel(241, 131) != 0X45A94) return false;
	if (GetPixel(241, 132) != 0XA1FC) return false;
	if (GetPixel(241, 133) != 0X283D0) return false;
	if (GetPixel(241, 134) != 0X362A1) return false;
	if (GetPixel(241, 135) != 0X362A1) return false;
	if (GetPixel(241, 136) != 0X282CF) return false;
	if (GetPixel(241, 137) != 0XA1FC) return false;
	if (GetPixel(241, 138) != 0X45A94) return false;
	if (GetPixel(241, 139) != 0X60C1C) return false;
	if (GetPixel(242, 128) != 0X70919) return false;
	if (GetPixel(242, 129) != 0X60919) return false;
	if (GetPixel(242, 130) != 0X364A2) return false;
	if (GetPixel(242, 131) != 0X197ED) return false;
	if (GetPixel(242, 132) != 0X63A64) return false;
	if (GetPixel(242, 133) != 0X50818) return false;
	if (GetPixel(242, 134) != 0X50816) return false;
	if (GetPixel(242, 135) != 0X50816) return false;
	if (GetPixel(242, 136) != 0X50816) return false;
	if (GetPixel(242, 137) != 0X63963) return false;
	if (GetPixel(242, 138) != 0X196EC) return false;
	if (GetPixel(242, 139) != 0X364A2) return false;
	if (GetPixel(243, 128) != 0X40918) return false;
	if (GetPixel(243, 129) != 0X63156) return false;
	if (GetPixel(243, 130) != 0XA2FD) return false;
	if (GetPixel(243, 131) != 0X63055) return false;
	if (GetPixel(243, 132) != 0X60815) return false;
	if (GetPixel(243, 133) != 0X60918) return false;
	if (GetPixel(243, 134) != 0X60918) return false;
	if (GetPixel(243, 135) != 0X60918) return false;
	if (GetPixel(243, 136) != 0X60917) return false;
	if (GetPixel(243, 137) != 0X60815) return false;
	if (GetPixel(243, 138) != 0X63056) return false;
	if (GetPixel(243, 139) != 0XA1FC) return false;
	if (GetPixel(244, 128) != 0X5091E) return false;
	if (GetPixel(244, 129) != 0X276BD) return false;
	if (GetPixel(244, 130) != 0X36DB0) return false;
	if (GetPixel(244, 131) != 0X50815) return false;
	if (GetPixel(244, 132) != 0X60916) return false;
	if (GetPixel(244, 133) != 0X60919) return false;
	if (GetPixel(244, 134) != 0X60A1C) return false;
	if (GetPixel(244, 135) != 0X60A1D) return false;
	if (GetPixel(244, 136) != 0X60A1A) return false;
	if (GetPixel(244, 137) != 0X60816) return false;
	if (GetPixel(244, 138) != 0X50815) return false;
	if (GetPixel(244, 139) != 0X36CAE) return false;
	if (GetPixel(245, 128) != 0X5091E) return false;
	if (GetPixel(245, 129) != 0X197EE) return false;
	if (GetPixel(245, 130) != 0X5487A) return false;
	if (GetPixel(245, 131) != 0X60815) return false;
	if (GetPixel(245, 132) != 0X60917) return false;
	if (GetPixel(245, 133) != 0X6091B) return false;
	if (GetPixel(245, 134) != 0X70C22) return false;
	if (GetPixel(245, 135) != 0X70D25) return false;
	if (GetPixel(245, 136) != 0X60B1E) return false;
	if (GetPixel(245, 137) != 0X60917) return false;
	if (GetPixel(245, 138) != 0X60815) return false;
	if (GetPixel(245, 139) != 0X54777) return false;
	if (GetPixel(246, 128) != 0X40919) return false;
	if (GetPixel(246, 129) != 0X9DF6) return false;
	if (GetPixel(246, 130) != 0X6375E) return false;
	if (GetPixel(246, 131) != 0X60916) return false;
	if (GetPixel(246, 132) != 0X70A19) return false;
	if (GetPixel(246, 133) != 0X70A1E) return false;
	if (GetPixel(246, 134) != 0X70D25) return false;
	if (GetPixel(246, 135) != 0X70D25) return false;
	if (GetPixel(246, 136) != 0X70B1F) return false;
	if (GetPixel(246, 137) != 0X70A1A) return false;
	if (GetPixel(246, 138) != 0X60816) return false;
	if (GetPixel(246, 139) != 0X6375E) return false;
	if (GetPixel(247, 128) != 0X60715) return false;
	if (GetPixel(247, 129) != 0X188D7) return false;
	if (GetPixel(247, 130) != 0X54D81) return false;
	if (GetPixel(247, 131) != 0X6091A) return false;
	if (GetPixel(247, 132) != 0X70B1F) return false;
	if (GetPixel(247, 133) != 0X70B25) return false;
	if (GetPixel(247, 134) != 0X70B23) return false;
	if (GetPixel(247, 135) != 0X70A1F) return false;
	if (GetPixel(247, 136) != 0X70A1D) return false;
	if (GetPixel(247, 137) != 0X7091C) return false;
	if (GetPixel(247, 138) != 0X6091A) return false;
	if (GetPixel(247, 139) != 0X44E83) return false;
	if (GetPixel(248, 128) != 0X7091C) return false;
	if (GetPixel(248, 129) != 0X45E9B) return false;
	if (GetPixel(248, 130) != 0X188D8) return false;
	if (GetPixel(248, 131) != 0X60D21) return false;
	if (GetPixel(248, 132) != 0X70D2C) return false;
	if (GetPixel(248, 133) != 0X70D2B) return false;
	if (GetPixel(248, 134) != 0X80C25) return false;
	if (GetPixel(248, 135) != 0X80A1F) return false;
	if (GetPixel(248, 136) != 0X70A1E) return false;
	if (GetPixel(248, 137) != 0X7091E) return false;
	if (GetPixel(248, 138) != 0X60B1D) return false;
	if (GetPixel(248, 139) != 0X18BDC) return false;
	if (GetPixel(249, 128) != 0X70920) return false;
	if (GetPixel(249, 129) != 0X51631) return false;
	if (GetPixel(249, 130) != 0X274BA) return false;
	if (GetPixel(249, 131) != 0X45F9F) return false;
	if (GetPixel(249, 132) != 0X70E31) return false;
	if (GetPixel(249, 133) != 0X70E2C) return false;
	if (GetPixel(249, 134) != 0X70D29) return false;
	if (GetPixel(249, 135) != 0X70A21) return false;
	if (GetPixel(249, 136) != 0X70A20) return false;
	if (GetPixel(249, 137) != 0X70E27) return false;
	if (GetPixel(249, 138) != 0X4558E) return false;
	if (GetPixel(249, 139) != 0X370B4) return false;
	if (GetPixel(250, 128) != 0X70B25) return false;
	if (GetPixel(250, 129) != 0X70C24) return false;
	if (GetPixel(250, 130) != 0X70A1D) return false;
	if (GetPixel(250, 131) != 0X70D29) return false;
	if (GetPixel(250, 132) != 0X70E2F) return false;
	if (GetPixel(250, 133) != 0XA0E2E) return false;
	if (GetPixel(250, 134) != 0X90F2C) return false;
	if (GetPixel(250, 135) != 0X90D27) return false;
	if (GetPixel(250, 136) != 0X80D27) return false;
	if (GetPixel(250, 137) != 0X70D29) return false;
	if (GetPixel(250, 138) != 0X70B21) return false;
	if (GetPixel(250, 139) != 0X70A1C) return false;
	if (GetPixel(251, 128) != 0X70C26) return false;
	if (GetPixel(251, 129) != 0X70D29) return false;
	if (GetPixel(251, 130) != 0X70C23) return false;
	if (GetPixel(251, 131) != 0X70C23) return false;
	if (GetPixel(251, 132) != 0X80D27) return false;
	if (GetPixel(251, 133) != 0XA0E2A) return false;
	if (GetPixel(251, 134) != 0XA0D2A) return false;
	if (GetPixel(251, 135) != 0X90D27) return false;
	if (GetPixel(251, 136) != 0X80E29) return false;
	if (GetPixel(251, 137) != 0X70E29) return false;
	if (GetPixel(251, 138) != 0X70B23) return false;
	if (GetPixel(251, 139) != 0X70A1C) return false;
	if (GetPixel(252, 128) != 0X80C27) return false;
	if (GetPixel(252, 129) != 0X70E2C) return false;
	if (GetPixel(252, 130) != 0X70E29) return false;
	if (GetPixel(252, 131) != 0X70C23) return false;
	if (GetPixel(252, 132) != 0X70C22) return false;
	if (GetPixel(252, 133) != 0XA0D27) return false;
	if (GetPixel(252, 134) != 0XA0D28) return false;
	if (GetPixel(252, 135) != 0XA0D26) return false;
	if (GetPixel(252, 136) != 0X70C25) return false;
	if (GetPixel(252, 137) != 0X70C25) return false;
	if (GetPixel(252, 138) != 0X70B20) return false;
	if (GetPixel(252, 139) != 0X70A1C) return false;
	if (GetPixel(253, 128) != 0X70F2D) return false;
	if (GetPixel(253, 129) != 0X70E2C) return false;
	if (GetPixel(253, 130) != 0X70D29) return false;
	if (GetPixel(253, 131) != 0X60C23) return false;
	if (GetPixel(253, 132) != 0X60B22) return false;
	if (GetPixel(253, 133) != 0X90C24) return false;
	if (GetPixel(253, 134) != 0X80B22) return false;
	if (GetPixel(253, 135) != 0X70A20) return false;
	if (GetPixel(253, 136) != 0X6091D) return false;
	if (GetPixel(253, 137) != 0X60A1B) return false;
	if (GetPixel(253, 138) != 0X6091B) return false;
	if (GetPixel(253, 139) != 0X70A1C) return false;
	if (GetPixel(254, 128) != 0X70F2D) return false;
	if (GetPixel(254, 129) != 0X70E2B) return false;
	if (GetPixel(254, 130) != 0X60C26) return false;
	if (GetPixel(254, 131) != 0X60C23) return false;
	if (GetPixel(254, 132) != 0X52A50) return false;
	if (GetPixel(254, 133) != 0X363A2) return false;
	if (GetPixel(254, 134) != 0X27CC7) return false;
	if (GetPixel(254, 135) != 0X27CC6) return false;
	if (GetPixel(254, 136) != 0X362A1) return false;
	if (GetPixel(254, 137) != 0X6294C) return false;
	if (GetPixel(254, 138) != 0X60817) return false;
	if (GetPixel(254, 139) != 0X6091A) return false;
	if (GetPixel(255, 128) != 0X70E2A) return false;
	if (GetPixel(255, 129) != 0X60D26) return false;
	if (GetPixel(255, 130) != 0X30C1E) return false;
	if (GetPixel(255, 131) != 0X25A95) return false;
	if (GetPixel(255, 132) != 0X9AF1) return false;
	if (GetPixel(255, 133) != 0X36EB1) return false;
	if (GetPixel(255, 134) != 0X9FF9) return false;
	if (GetPixel(255, 135) != 0X36DAF) return false;
	if (GetPixel(255, 136) != 0X18CDE) return false;
	if (GetPixel(255, 137) != 0XA1FC) return false;
	if (GetPixel(255, 138) != 0X45992) return false;
	if (GetPixel(255, 139) != 0X50B1A) return false;
	if (GetPixel(256, 128) != 0X70B1E) return false;
	if (GetPixel(256, 129) != 0X4091A) return false;
	if (GetPixel(256, 130) != 0X264A3) return false;
	if (GetPixel(256, 131) != 0X83D0) return false;
	if (GetPixel(256, 132) != 0X20E1B) return false;
	if (GetPixel(256, 133) != 0X4050F) return false;
	if (GetPixel(256, 134) != 0X9AF2) return false;
	if (GetPixel(256, 135) != 0X30D1A) return false;
	if (GetPixel(256, 136) != 0X4050F) return false;
	if (GetPixel(256, 137) != 0X5487A) return false;
	if (GetPixel(256, 138) != 0X9DF6) return false;
	if (GetPixel(256, 139) != 0X364A2) return false;
	if (GetPixel(257, 128) != 0X60916) return false;
	if (GetPixel(257, 129) != 0X23153) return false;
	if (GetPixel(257, 130) != 0X97ED) return false;
	if (GetPixel(257, 131) != 0X10D1A) return false;
	if (GetPixel(257, 132) != 0X20610) return false;
	if (GetPixel(257, 133) != 0X40814) return false;
	if (GetPixel(257, 134) != 0X9AF3) return false;
	if (GetPixel(257, 135) != 0X30F1E) return false;
	if (GetPixel(257, 136) != 0X40510) return false;
	if (GetPixel(257, 137) != 0X40611) return false;
	if (GetPixel(257, 138) != 0X53E6C) return false;
	if (GetPixel(257, 139) != 0XA2FE) return false;
	if (GetPixel(258, 128) != 0X50817) return false;
	if (GetPixel(258, 129) != 0X176BB) return false;
	if (GetPixel(258, 130) != 0X1568C) return false;
	if (GetPixel(258, 131) != 0X10610) return false;
	if (GetPixel(258, 132) != 0X30714) return false;
	if (GetPixel(258, 133) != 0X40919) return false;
	if (GetPixel(258, 134) != 0X9BF3) return false;
	if (GetPixel(258, 135) != 0X30F1F) return false;
	if (GetPixel(258, 136) != 0X3050E) return false;
	if (GetPixel(258, 137) != 0X4050F) return false;
	if (GetPixel(258, 138) != 0X40610) return false;
	if (GetPixel(258, 139) != 0X27BC5) return false;
	if (GetPixel(259, 128) != 0X40814) return false;
	if (GetPixel(259, 129) != 0X97ED) return false;
	if (GetPixel(259, 130) != 0X14C7C) return false;
	if (GetPixel(259, 131) != 0X33055) return false;
	if (GetPixel(259, 132) != 0X5325E) return false;
	if (GetPixel(259, 133) != 0X63361) return false;
	if (GetPixel(259, 134) != 0X9DF6) return false;
	if (GetPixel(259, 135) != 0X54070) return false;
	if (GetPixel(259, 136) != 0X62F54) return false;
	if (GetPixel(259, 137) != 0X62F53) return false;
	if (GetPixel(259, 138) != 0X63056) return false;
	if (GetPixel(259, 139) != 0X365A5) return false;
	if (GetPixel(260, 128) != 0X40813) return false;
	if (GetPixel(260, 129) != 0X9FFA) return false;
	if (GetPixel(260, 130) != 0X8EE0) return false;
	if (GetPixel(260, 131) != 0X89D9) return false;
	if (GetPixel(260, 132) != 0X18ADA) return false;
	if (GetPixel(260, 133) != 0X18ADA) return false;
	if (GetPixel(260, 134) != 0XA2FE) return false;
	if (GetPixel(260, 135) != 0X18DDF) return false;
	if (GetPixel(260, 136) != 0X189D9) return false;
	if (GetPixel(260, 137) != 0X189D9) return false;
	if (GetPixel(260, 138) != 0X189D9) return false;
	if (GetPixel(260, 139) != 0X193E8) return false;
	if (GetPixel(261, 128) != 0X50813) return false;
	if (GetPixel(261, 129) != 0X18DDF) return false;
	if (GetPixel(261, 130) != 0X43C67) return false;
	if (GetPixel(261, 131) != 0X3050E) return false;
	if (GetPixel(261, 132) != 0X30610) return false;
	if (GetPixel(261, 133) != 0X4050E) return false;
	if (GetPixel(261, 134) != 0X9AF2) return false;
	if (GetPixel(261, 135) != 0X30E1C) return false;
	if (GetPixel(261, 136) != 0X3050E) return false;
	if (GetPixel(261, 137) != 0X4050E) return false;
	if (GetPixel(261, 138) != 0X4050E) return false;
	if (GetPixel(261, 139) != 0X45F9C) return false;
	if (GetPixel(262, 128) != 0X60814) return false;
	if (GetPixel(262, 129) != 0X45F9A) return false;
	if (GetPixel(262, 130) != 0X370B3) return false;
	if (GetPixel(262, 131) != 0X4060F) return false;
	if (GetPixel(262, 132) != 0X4050E) return false;
	if (GetPixel(262, 133) != 0X4060C) return false;
	if (GetPixel(262, 134) != 0X9AF2) return false;
	if (GetPixel(262, 135) != 0X30E1C) return false;
	if (GetPixel(262, 136) != 0X3050E) return false;
	if (GetPixel(262, 137) != 0X4050E) return false;
	if (GetPixel(262, 138) != 0X40A14) return false;
	if (GetPixel(262, 139) != 0X192E6) return false;
	if (GetPixel(263, 128) != 0X60712) return false;
	if (GetPixel(263, 129) != 0X50E1D) return false;
	if (GetPixel(263, 130) != 0X195EA) return false;
	if (GetPixel(263, 131) != 0X63861) return false;
	if (GetPixel(263, 132) != 0X4050D) return false;
	if (GetPixel(263, 133) != 0X4060D) return false;
	if (GetPixel(263, 134) != 0X9AF2) return false;
	if (GetPixel(263, 135) != 0X30E1A) return false;
	if (GetPixel(263, 136) != 0X4060F) return false;
	if (GetPixel(263, 137) != 0X40711) return false;
	if (GetPixel(263, 138) != 0X370B4) return false;
	if (GetPixel(263, 139) != 0X195EB) return false;
	if (GetPixel(264, 128) != 0X70815) return false;
	if (GetPixel(264, 129) != 0X60816) return false;
	if (GetPixel(264, 130) != 0X6375E) return false;
	if (GetPixel(264, 131) != 0X9AF2) return false;
	if (GetPixel(264, 132) != 0X45388) return false;
	if (GetPixel(264, 133) != 0X30C18) return false;
	if (GetPixel(264, 134) != 0X9AF2) return false;
	if (GetPixel(264, 135) != 0X3101D) return false;
	if (GetPixel(264, 136) != 0X6345A) return false;
	if (GetPixel(264, 137) != 0X285D2) return false;
	if (GetPixel(264, 138) != 0X9DF6) return false;
	if (GetPixel(264, 139) != 0X6375E) return false;
	if (GetPixel(265, 128) != 0X70A16) return false;
	if (GetPixel(265, 129) != 0X40916) return false;
	if (GetPixel(265, 130) != 0X40813) return false;
	if (GetPixel(265, 131) != 0X31628) return false;
	if (GetPixel(265, 132) != 0X180CA) return false;
	if (GetPixel(265, 133) != 0XA1FC) return false;
	if (GetPixel(265, 134) != 0XA3FF) return false;
	if (GetPixel(265, 135) != 0X9FFA) return false;
	if (GetPixel(265, 136) != 0XA3FF) return false;
	if (GetPixel(265, 137) != 0X27FC9) return false;
	if (GetPixel(265, 138) != 0X41524) return false;
	if (GetPixel(265, 139) != 0X60911) return false;
	if (GetPixel(266, 128) != 0X70916) return false;
	if (GetPixel(266, 129) != 0X40915) return false;
	if (GetPixel(266, 130) != 0X40916) return false;
	if (GetPixel(266, 131) != 0X50917) return false;
	if (GetPixel(266, 132) != 0X40815) return false;
	if (GetPixel(266, 133) != 0X5192F) return false;
	if (GetPixel(266, 134) != 0X53C68) return false;
	if (GetPixel(266, 135) != 0X53D69) return false;
	if (GetPixel(266, 136) != 0X51930) return false;
	if (GetPixel(266, 137) != 0X60919) return false;
	if (GetPixel(266, 138) != 0X60918) return false;
	if (GetPixel(266, 139) != 0X70A14) return false;
	if (GetPixel(267, 128) != 0X80B17) return false;
	if (GetPixel(267, 129) != 0X50A18) return false;
	if (GetPixel(267, 130) != 0X40A18) return false;
	if (GetPixel(267, 131) != 0X70A1C) return false;
	if (GetPixel(267, 132) != 0X60A1A) return false;
	if (GetPixel(267, 133) != 0X60917) return false;
	if (GetPixel(267, 134) != 0X60917) return false;
	if (GetPixel(267, 135) != 0X60A1A) return false;
	if (GetPixel(267, 136) != 0X6091B) return false;
	if (GetPixel(267, 137) != 0X60A1C) return false;
	if (GetPixel(267, 138) != 0X70A1D) return false;
	if (GetPixel(267, 139) != 0X70B18) return false;
	if (GetPixel(268, 128) != 0X80A1A) return false;
	if (GetPixel(268, 129) != 0X60A19) return false;
	if (GetPixel(268, 130) != 0X50A18) return false;
	if (GetPixel(268, 131) != 0X70A1C) return false;
	if (GetPixel(268, 132) != 0X60919) return false;
	if (GetPixel(268, 133) != 0X60816) return false;
	if (GetPixel(268, 134) != 0X60918) return false;
	if (GetPixel(268, 135) != 0X60A1B) return false;
	if (GetPixel(268, 136) != 0X60919) return false;
	if (GetPixel(268, 137) != 0X60919) return false;
	if (GetPixel(268, 138) != 0X7091A) return false;
	if (GetPixel(268, 139) != 0X70A1E) return false;
	if (GetPixel(269, 128) != 0X70C21) return false;
	if (GetPixel(269, 129) != 0X70A1B) return false;
	if (GetPixel(269, 130) != 0X7091A) return false;
	if (GetPixel(269, 131) != 0X70A1A) return false;
	if (GetPixel(269, 132) != 0X60918) return false;
	if (GetPixel(269, 133) != 0X60815) return false;
	if (GetPixel(269, 134) != 0X60918) return false;
	if (GetPixel(269, 135) != 0X60A1D) return false;
	if (GetPixel(269, 136) != 0X60918) return false;
	if (GetPixel(269, 137) != 0X60916) return false;
	if (GetPixel(269, 138) != 0X70A1B) return false;
	if (GetPixel(269, 139) != 0X70B21) return false;
	if (GetPixel(270, 128) != 0X70D26) return false;
	if (GetPixel(270, 129) != 0X60B1C) return false;
	if (GetPixel(270, 130) != 0X70A1C) return false;
	if (GetPixel(270, 131) != 0X60A1A) return false;
	if (GetPixel(270, 132) != 0X60918) return false;
	if (GetPixel(270, 133) != 0X60917) return false;
	if (GetPixel(270, 134) != 0X60A1C) return false;
	if (GetPixel(270, 135) != 0X60A1E) return false;
	if (GetPixel(270, 136) != 0X60918) return false;
	if (GetPixel(270, 137) != 0X60916) return false;
	if (GetPixel(270, 138) != 0X60918) return false;
	if (GetPixel(270, 139) != 0X70B1F) return false;
	if (GetPixel(271, 128) != 0X70E29) return false;
	if (GetPixel(271, 129) != 0X6325B) return false;
	if (GetPixel(271, 130) != 0X60A1B) return false;
	if (GetPixel(271, 131) != 0X60B1E) return false;
	if (GetPixel(271, 132) != 0X60A1A) return false;
	if (GetPixel(271, 133) != 0X60A1B) return false;
	if (GetPixel(271, 134) != 0X60A1D) return false;
	if (GetPixel(271, 135) != 0X60919) return false;
	if (GetPixel(271, 136) != 0X60811) return false;
	if (GetPixel(271, 137) != 0X6070E) return false;
	if (GetPixel(271, 138) != 0X6070E) return false;
	if (GetPixel(271, 139) != 0X60917) return false;
	if (GetPixel(272, 128) != 0X60C25) return false;
	if (GetPixel(272, 129) != 0X9EF7) return false;
	if (GetPixel(272, 130) != 0X189D9) return false;
	if (GetPixel(272, 131) != 0X187D7) return false;
	if (GetPixel(272, 132) != 0X187D7) return false;
	if (GetPixel(272, 133) != 0X187D5) return false;
	if (GetPixel(272, 134) != 0X187D5) return false;
	if (GetPixel(272, 135) != 0X187D5) return false;
	if (GetPixel(272, 136) != 0X187D4) return false;
	if (GetPixel(272, 137) != 0X186D3) return false;
	if (GetPixel(272, 138) != 0X187D4) return false;
	if (GetPixel(272, 139) != 0X189D9) return false;
	if (GetPixel(273, 128) != 0X60A1F) return false;
	if (GetPixel(273, 129) != 0XA3FF) return false;
	if (GetPixel(273, 130) != 0X4609E) return false;
	if (GetPixel(273, 131) != 0X54B7C) return false;
	if (GetPixel(273, 132) != 0X54B7C) return false;
	if (GetPixel(273, 133) != 0X54C7A) return false;
	if (GetPixel(273, 134) != 0X54C7A) return false;
	if (GetPixel(273, 135) != 0X54C7A) return false;
	if (GetPixel(273, 136) != 0X54B77) return false;
	if (GetPixel(273, 137) != 0X54A75) return false;
	if (GetPixel(273, 138) != 0X54A79) return false;
	if (GetPixel(273, 139) != 0X54D80) return false;
	if (GetPixel(274, 128) != 0X60918) return false;
	if (GetPixel(274, 129) != 0XA3FF) return false;
	if (GetPixel(274, 130) != 0X62C4E) return false;
	if (GetPixel(274, 131) != 0X4060F) return false;
	if (GetPixel(274, 132) != 0X50610) return false;
	if (GetPixel(274, 133) != 0X5070F) return false;
	if (GetPixel(274, 134) != 0X5080F) return false;
	if (GetPixel(274, 135) != 0X5080F) return false;
	if (GetPixel(274, 136) != 0X50610) return false;
	if (GetPixel(274, 137) != 0X50611) return false;
	if (GetPixel(274, 138) != 0X50716) return false;
	if (GetPixel(274, 139) != 0X60817) return false;
	if (GetPixel(275, 128) != 0X50916) return false;
	if (GetPixel(275, 129) != 0XA3FF) return false;
	if (GetPixel(275, 130) != 0X62C4C) return false;
	if (GetPixel(275, 131) != 0X4060E) return false;
	if (GetPixel(275, 132) != 0X5060F) return false;
	if (GetPixel(275, 133) != 0X5070E) return false;
	if (GetPixel(275, 134) != 0X5080F) return false;
	if (GetPixel(275, 135) != 0X50812) return false;
	if (GetPixel(275, 136) != 0X50816) return false;
	if (GetPixel(275, 137) != 0X50819) return false;
	if (GetPixel(275, 138) != 0X5081B) return false;
	if (GetPixel(275, 139) != 0X60817) return false;
	if (GetPixel(276, 128) != 0X40813) return false;
	if (GetPixel(276, 129) != 0XA3FF) return false;
	if (GetPixel(276, 130) != 0X62D4B) return false;
	if (GetPixel(276, 131) != 0X4060D) return false;
	if (GetPixel(276, 132) != 0X5070E) return false;
	if (GetPixel(276, 133) != 0X4070D) return false;
	if (GetPixel(276, 134) != 0X50810) return false;
	if (GetPixel(276, 135) != 0X50917) return false;
	if (GetPixel(276, 136) != 0X50918) return false;
	if (GetPixel(276, 137) != 0X50819) return false;
	if (GetPixel(276, 138) != 0X50817) return false;
	if (GetPixel(276, 139) != 0X60813) return false;
	if (GetPixel(277, 128) != 0X30813) return false;
	if (GetPixel(277, 129) != 0XA3FF) return false;
	if (GetPixel(277, 130) != 0X281CA) return false;
	if (GetPixel(277, 131) != 0X277BB) return false;
	if (GetPixel(277, 132) != 0X277BB) return false;
	if (GetPixel(277, 133) != 0X277BB) return false;
	if (GetPixel(277, 134) != 0X277BE) return false;
	if (GetPixel(277, 135) != 0X277C1) return false;
	if (GetPixel(277, 136) != 0X277BF) return false;
	if (GetPixel(277, 137) != 0X277BE) return false;
	if (GetPixel(277, 138) != 0X276BC) return false;
	if (GetPixel(277, 139) != 0X278BF) return false;
	if (GetPixel(278, 128) != 0X30812) return false;
	if (GetPixel(278, 129) != 0XA3FF) return false;
	if (GetPixel(278, 130) != 0X26EAE) return false;
	if (GetPixel(278, 131) != 0X35F96) return false;
	if (GetPixel(278, 132) != 0X45F97) return false;
	if (GetPixel(278, 133) != 0X45F9B) return false;
	if (GetPixel(278, 134) != 0X4609F) return false;
	if (GetPixel(278, 135) != 0X4609D) return false;
	if (GetPixel(278, 136) != 0X45F99) return false;
	if (GetPixel(278, 137) != 0X45E98) return false;
	if (GetPixel(278, 138) != 0X45E98) return false;
	if (GetPixel(278, 139) != 0X4609A) return false;
	if (GetPixel(279, 128) != 0X50713) return false;
	if (GetPixel(279, 129) != 0XA3FF) return false;
	if (GetPixel(279, 130) != 0X52D4A) return false;
	if (GetPixel(279, 131) != 0X4060C) return false;
	if (GetPixel(279, 132) != 0X5070F) return false;
	if (GetPixel(279, 133) != 0X40716) return false;
	if (GetPixel(279, 134) != 0X50818) return false;
	if (GetPixel(279, 135) != 0X50611) return false;
	if (GetPixel(279, 136) != 0X5060E) return false;
	if (GetPixel(279, 137) != 0X50710) return false;
	if (GetPixel(279, 138) != 0X50811) return false;
	if (GetPixel(279, 139) != 0X60812) return false;
	if (GetPixel(280, 128) != 0X60713) return false;
	if (GetPixel(280, 129) != 0XA3FF) return false;
	if (GetPixel(280, 130) != 0X62D4B) return false;
	if (GetPixel(280, 131) != 0X4070D) return false;
	if (GetPixel(280, 132) != 0X50714) return false;
	if (GetPixel(280, 133) != 0X50716) return false;
	if (GetPixel(280, 134) != 0X50612) return false;
	if (GetPixel(280, 135) != 0X5050B) return false;
	if (GetPixel(280, 136) != 0X5060C) return false;
	if (GetPixel(280, 137) != 0X5070E) return false;
	if (GetPixel(280, 138) != 0X50810) return false;
	if (GetPixel(280, 139) != 0X60911) return false;
	if (GetPixel(281, 128) != 0X60814) return false;
	if (GetPixel(281, 129) != 0XA3FF) return false;
	if (GetPixel(281, 130) != 0X62D4B) return false;
	if (GetPixel(281, 131) != 0X40713) return false;
	if (GetPixel(281, 132) != 0X50717) return false;
	if (GetPixel(281, 133) != 0X50612) return false;
	if (GetPixel(281, 134) != 0X5060D) return false;
	if (GetPixel(281, 135) != 0X5050D) return false;
	if (GetPixel(281, 136) != 0X5060D) return false;
	if (GetPixel(281, 137) != 0X5070E) return false;
	if (GetPixel(281, 138) != 0X50810) return false;
	if (GetPixel(281, 139) != 0X60811) return false;
	if (GetPixel(282, 128) != 0X60815) return false;
	if (GetPixel(282, 129) != 0XA3FF) return false;
	if (GetPixel(282, 130) != 0X372B7) return false;
	if (GetPixel(282, 131) != 0X364A5) return false;
	if (GetPixel(282, 132) != 0X364A4) return false;
	if (GetPixel(282, 133) != 0X3629D) return false;
	if (GetPixel(282, 134) != 0X3629C) return false;
	if (GetPixel(282, 135) != 0X3629E) return false;
	if (GetPixel(282, 136) != 0X3639E) return false;
	if (GetPixel(282, 137) != 0X3649E) return false;
	if (GetPixel(282, 138) != 0X3639D) return false;
	if (GetPixel(282, 139) != 0X365A1) return false;
	if (GetPixel(283, 128) != 0X60816) return false;
	if (GetPixel(283, 129) != 0X18EE0) return false;
	if (GetPixel(283, 130) != 0X371B7) return false;
	if (GetPixel(283, 131) != 0X36FB6) return false;
	if (GetPixel(283, 132) != 0X36FB3) return false;
	if (GetPixel(283, 133) != 0X36FB1) return false;
	if (GetPixel(283, 134) != 0X36FB0) return false;
	if (GetPixel(283, 135) != 0X36FB1) return false;
	if (GetPixel(283, 136) != 0X36FB1) return false;
	if (GetPixel(283, 137) != 0X36FB1) return false;
	if (GetPixel(283, 138) != 0X36FB1) return false;
	if (GetPixel(283, 139) != 0X370B2) return false;
	if (GetPixel(284, 128) != 0X70A19) return false;
	if (GetPixel(284, 129) != 0X51C34) return false;
	if (GetPixel(284, 130) != 0X6091B) return false;
	if (GetPixel(284, 131) != 0X6091D) return false;
	if (GetPixel(284, 132) != 0X60916) return false;
	if (GetPixel(284, 133) != 0X60712) return false;
	if (GetPixel(284, 134) != 0X60815) return false;
	if (GetPixel(284, 135) != 0X60815) return false;
	if (GetPixel(284, 136) != 0X60812) return false;
	if (GetPixel(284, 137) != 0X60814) return false;
	if (GetPixel(284, 138) != 0X60915) return false;
	if (GetPixel(284, 139) != 0X60916) return false;
	if (GetPixel(285, 128) != 0X70A1B) return false;
	if (GetPixel(285, 129) != 0X70A1C) return false;
	if (GetPixel(285, 130) != 0X70A1B) return false;
	if (GetPixel(285, 131) != 0X60A19) return false;
	if (GetPixel(285, 132) != 0X60A17) return false;
	if (GetPixel(285, 133) != 0X60916) return false;
	if (GetPixel(285, 134) != 0X70916) return false;
	if (GetPixel(285, 135) != 0X70916) return false;
	if (GetPixel(285, 136) != 0X60814) return false;
	if (GetPixel(285, 137) != 0X70915) return false;
	if (GetPixel(285, 138) != 0X70916) return false;
	if (GetPixel(285, 139) != 0X70919) return false;
	if (GetPixel(286, 128) != 0X70B1D) return false;
	if (GetPixel(286, 129) != 0X70A19) return false;
	if (GetPixel(286, 130) != 0X60915) return false;
	if (GetPixel(286, 131) != 0X60A13) return false;
	if (GetPixel(286, 132) != 0X60914) return false;
	if (GetPixel(286, 133) != 0X60917) return false;
	if (GetPixel(286, 134) != 0X60917) return false;
	if (GetPixel(286, 135) != 0X60915) return false;
	if (GetPixel(286, 136) != 0X60914) return false;
	if (GetPixel(286, 137) != 0X60916) return false;
	if (GetPixel(286, 138) != 0X60916) return false;
	if (GetPixel(286, 139) != 0X70A1A) return false;
	if (GetPixel(287, 128) != 0X70C21) return false;
	if (GetPixel(287, 129) != 0X70A16) return false;
	if (GetPixel(287, 130) != 0X40712) return false;
	if (GetPixel(287, 131) != 0X50813) return false;
	if (GetPixel(287, 132) != 0X60A14) return false;
	if (GetPixel(287, 133) != 0X60918) return false;
	if (GetPixel(287, 134) != 0X60917) return false;
	if (GetPixel(287, 135) != 0X60915) return false;
	if (GetPixel(287, 136) != 0X60914) return false;
	if (GetPixel(287, 137) != 0X60A15) return false;
	if (GetPixel(287, 138) != 0X60A17) return false;
	if (GetPixel(287, 139) != 0X70A17) return false;
	if (GetPixel(288, 128) != 0X70B1E) return false;
	if (GetPixel(288, 129) != 0X50813) return false;
	if (GetPixel(288, 130) != 0X40712) return false;
	if (GetPixel(288, 131) != 0X60912) return false;
	if (GetPixel(288, 132) != 0X60913) return false;
	if (GetPixel(288, 133) != 0X60812) return false;
	if (GetPixel(288, 134) != 0X60915) return false;
	if (GetPixel(288, 135) != 0X60815) return false;
	if (GetPixel(288, 136) != 0X60913) return false;
	if (GetPixel(288, 137) != 0X60A13) return false;
	if (GetPixel(288, 138) != 0X60A17) return false;
	if (GetPixel(288, 139) != 0X70A18) return false;
	if (GetPixel(289, 128) != 0X70816) return false;
	if (GetPixel(289, 129) != 0X42D4E) return false;
	if (GetPixel(289, 130) != 0X2050F) return false;
	if (GetPixel(289, 131) != 0X40710) return false;
	if (GetPixel(289, 132) != 0X60912) return false;
	if (GetPixel(289, 133) != 0X60610) return false;
	if (GetPixel(289, 134) != 0X60712) return false;
	if (GetPixel(289, 135) != 0X60813) return false;
	if (GetPixel(289, 136) != 0X60913) return false;
	if (GetPixel(289, 137) != 0X60912) return false;
	if (GetPixel(289, 138) != 0X60913) return false;
	if (GetPixel(289, 139) != 0X60918) return false;
	if (GetPixel(290, 128) != 0X60710) return false;
	if (GetPixel(290, 129) != 0X9FF9) return false;
	if (GetPixel(290, 130) != 0X18AD9) return false;
	if (GetPixel(290, 131) != 0X189D9) return false;
	if (GetPixel(290, 132) != 0X189D8) return false;
	if (GetPixel(290, 133) != 0X189D8) return false;
	if (GetPixel(290, 134) != 0X189D8) return false;
	if (GetPixel(290, 135) != 0X189D8) return false;
	if (GetPixel(290, 136) != 0X18AD8) return false;
	if (GetPixel(290, 137) != 0X18AD8) return false;
	if (GetPixel(290, 138) != 0X18AD8) return false;
	if (GetPixel(290, 139) != 0X18BDB) return false;
	if (GetPixel(291, 128) != 0X60814) return false;
	if (GetPixel(291, 129) != 0XA3FF) return false;
	if (GetPixel(291, 130) != 0X44D7D) return false;
	if (GetPixel(291, 131) != 0X54774) return false;
	if (GetPixel(291, 132) != 0X54774) return false;
	if (GetPixel(291, 133) != 0X54571) return false;
	if (GetPixel(291, 134) != 0X54571) return false;
	if (GetPixel(291, 135) != 0X9FFA) return false;
	if (GetPixel(291, 136) != 0X45486) return false;
	if (GetPixel(291, 137) != 0X44772) return false;
	if (GetPixel(291, 138) != 0X34771) return false;
	if (GetPixel(291, 139) != 0X54975) return false;
	if (GetPixel(292, 128) != 0X60815) return false;
	if (GetPixel(292, 129) != 0XA3FF) return false;
	if (GetPixel(292, 130) != 0X40E1C) return false;
	if (GetPixel(292, 131) != 0X4060E) return false;
	if (GetPixel(292, 132) != 0X4060F) return false;
	if (GetPixel(292, 133) != 0X4060D) return false;
	if (GetPixel(292, 134) != 0X4050C) return false;
	if (GetPixel(292, 135) != 0X9DF6) return false;
	if (GetPixel(292, 136) != 0X31321) return false;
	if (GetPixel(292, 137) != 0X3080E) return false;
	if (GetPixel(292, 138) != 0X40910) return false;
	if (GetPixel(292, 139) != 0X60912) return false;
	if (GetPixel(293, 128) != 0X60815) return false;
	if (GetPixel(293, 129) != 0X195E9) return false;
	if (GetPixel(293, 130) != 0X62947) return false;
	if (GetPixel(293, 131) != 0X4060E) return false;
	if (GetPixel(293, 132) != 0X4060E) return false;
	if (GetPixel(293, 133) != 0X4060D) return false;
	if (GetPixel(293, 134) != 0X30C19) return false;
	if (GetPixel(293, 135) != 0XA2FD) return false;
	if (GetPixel(293, 136) != 0X50C18) return false;
	if (GetPixel(293, 137) != 0X60812) return false;
	if (GetPixel(293, 138) != 0X60913) return false;
	if (GetPixel(293, 139) != 0X60913) return false;
	if (GetPixel(294, 128) != 0X60816) return false;
	if (GetPixel(294, 129) != 0X369A7) return false;
	if (GetPixel(294, 130) != 0X276BA) return false;
	if (GetPixel(294, 131) != 0X40912) return false;
	if (GetPixel(294, 132) != 0X4050D) return false;
	if (GetPixel(294, 133) != 0X20710) return false;
	if (GetPixel(294, 134) != 0X26BAB) return false;
	if (GetPixel(294, 135) != 0X17EC8) return false;
	if (GetPixel(294, 136) != 0X50813) return false;
	if (GetPixel(294, 137) != 0X60814) return false;
	if (GetPixel(294, 138) != 0X60915) return false;
	if (GetPixel(294, 139) != 0X70814) return false;
	if (GetPixel(295, 128) != 0X60A1A) return false;
	if (GetPixel(295, 129) != 0X5111F) return false;
	if (GetPixel(295, 130) != 0X18CDC) return false;
	if (GetPixel(295, 131) != 0X194E8) return false;
	if (GetPixel(295, 132) != 0X279C0) return false;
	if (GetPixel(295, 133) != 0X193E7) return false;
	if (GetPixel(295, 134) != 0X192E6) return false;
	if (GetPixel(295, 135) != 0X31629) return false;
	if (GetPixel(295, 136) != 0X50816) return false;
	if (GetPixel(295, 137) != 0X70919) return false;
	if (GetPixel(295, 138) != 0X70A18) return false;
	if (GetPixel(295, 139) != 0X70A19) return false;
	if (GetPixel(296, 128) != 0X70C21) return false;
	if (GetPixel(296, 129) != 0X60914) return false;
	if (GetPixel(296, 130) != 0X60D19) return false;
	if (GetPixel(296, 131) != 0X54976) return false;
	if (GetPixel(296, 132) != 0X3639E) return false;
	if (GetPixel(296, 133) != 0X44B7D) return false;
	if (GetPixel(296, 134) != 0X51021) return false;
	if (GetPixel(296, 135) != 0X40915) return false;
	if (GetPixel(296, 136) != 0X60A1B) return false;
	if (GetPixel(296, 137) != 0X70B1E) return false;
	if (GetPixel(296, 138) != 0X80A1B) return false;
	if (GetPixel(296, 139) != 0X80B1A) return false;
	if (GetPixel(297, 128) != 0X70D26) return false;
	if (GetPixel(297, 129) != 0X60A1A) return false;
	if (GetPixel(297, 130) != 0X60912) return false;
	if (GetPixel(297, 131) != 0X60911) return false;
	if (GetPixel(297, 132) != 0X60912) return false;
	if (GetPixel(297, 133) != 0X60916) return false;
	if (GetPixel(297, 134) != 0X60915) return false;
	if (GetPixel(297, 135) != 0X50913) return false;
	if (GetPixel(297, 136) != 0X70A18) return false;
	if (GetPixel(297, 137) != 0X70A1B) return false;
	if (GetPixel(297, 138) != 0X70B1C) return false;
	if (GetPixel(297, 139) != 0X70B1D) return false;
	if (GetPixel(298, 128) != 0X70D27) return false;
	if (GetPixel(298, 129) != 0X60C20) return false;
	if (GetPixel(298, 130) != 0X60B1D) return false;
	if (GetPixel(298, 131) != 0X60A17) return false;
	if (GetPixel(298, 132) != 0X60912) return false;
	if (GetPixel(298, 133) != 0X60915) return false;
	if (GetPixel(298, 134) != 0X60919) return false;
	if (GetPixel(298, 135) != 0X60916) return false;
	if (GetPixel(298, 136) != 0X60A14) return false;
	if (GetPixel(298, 137) != 0X70A18) return false;
	if (GetPixel(298, 138) != 0X70A1D) return false;
	if (GetPixel(298, 139) != 0X70B1F) return false;
	if (GetPixel(299, 128) != 0X70D27) return false;
	if (GetPixel(299, 129) != 0X60C22) return false;
	if (GetPixel(299, 130) != 0X60C20) return false;
	if (GetPixel(299, 131) != 0X60B1D) return false;
	if (GetPixel(299, 132) != 0X60917) return false;
	if (GetPixel(299, 133) != 0X60918) return false;
	if (GetPixel(299, 134) != 0X6091A) return false;
	if (GetPixel(299, 135) != 0X6091A) return false;
	if (GetPixel(299, 136) != 0X6091A) return false;
	if (GetPixel(299, 137) != 0X6091B) return false;
	if (GetPixel(299, 138) != 0X60A1C) return false;
	if (GetPixel(299, 139) != 0X70A21) return false;
	if (GetPixel(300, 128) != 0X70D27) return false;
	if (GetPixel(300, 129) != 0X63764) return false;
	if (GetPixel(300, 130) != 0X60C20) return false;
	if (GetPixel(300, 131) != 0X60B1F) return false;
	if (GetPixel(300, 132) != 0X60B1E) return false;
	if (GetPixel(300, 133) != 0X6091A) return false;
	if (GetPixel(300, 134) != 0X6091B) return false;
	if (GetPixel(300, 135) != 0X6091B) return false;
	if (GetPixel(300, 136) != 0X6091A) return false;
	if (GetPixel(300, 137) != 0X6091A) return false;
	if (GetPixel(300, 138) != 0X6091A) return false;
	if (GetPixel(300, 139) != 0X6091B) return false;
	if (GetPixel(301, 128) != 0X70A22) return false;
	if (GetPixel(301, 129) != 0XA0FA) return false;
	if (GetPixel(301, 130) != 0X18BDD) return false;
	if (GetPixel(301, 131) != 0X18ADB) return false;
	if (GetPixel(301, 132) != 0X18ADB) return false;
	if (GetPixel(301, 133) != 0X18ADA) return false;
	if (GetPixel(301, 134) != 0X18AD9) return false;
	if (GetPixel(301, 135) != 0X18ADA) return false;
	if (GetPixel(301, 136) != 0X18ADA) return false;
	if (GetPixel(301, 137) != 0X18ADA) return false;
	if (GetPixel(301, 138) != 0X18ADA) return false;
	if (GetPixel(301, 139) != 0X18ADB) return false;
	if (GetPixel(302, 128) != 0X50920) return false;
	if (GetPixel(302, 129) != 0X278C2) return false;
	if (GetPixel(302, 130) != 0X54A7E) return false;
	if (GetPixel(302, 131) != 0X54877) return false;
	if (GetPixel(302, 132) != 0X54877) return false;
	if (GetPixel(302, 133) != 0X54775) return false;
	if (GetPixel(302, 134) != 0X54776) return false;
	if (GetPixel(302, 135) != 0X54779) return false;
	if (GetPixel(302, 136) != 0X54779) return false;
	if (GetPixel(302, 137) != 0X5487A) return false;
	if (GetPixel(302, 138) != 0X5487A) return false;
	if (GetPixel(302, 139) != 0X45D9B) return false;
	if (GetPixel(303, 128) != 0X4091B) return false;
	if (GetPixel(303, 129) != 0X51832) return false;
	if (GetPixel(303, 130) != 0X70B1D) return false;
	if (GetPixel(303, 131) != 0X60A15) return false;
	if (GetPixel(303, 132) != 0X60913) return false;
	if (GetPixel(303, 133) != 0X60916) return false;
	if (GetPixel(303, 134) != 0X6091A) return false;
	if (GetPixel(303, 135) != 0X6091B) return false;
	if (GetPixel(303, 136) != 0X60817) return false;
	if (GetPixel(303, 137) != 0X50817) return false;
	if (GetPixel(303, 138) != 0X50815) return false;
	if (GetPixel(303, 139) != 0X62E54) return false;
	if (GetPixel(304, 128) != 0X60B20) return false;
	if (GetPixel(304, 129) != 0X70D25) return false;
	if (GetPixel(304, 130) != 0X70D24) return false;
	if (GetPixel(304, 131) != 0X70B1E) return false;
	if (GetPixel(304, 132) != 0X70A18) return false;
	if (GetPixel(304, 133) != 0X70A1A) return false;
	if (GetPixel(304, 134) != 0X70A1D) return false;
	if (GetPixel(304, 135) != 0X70A1B) return false;
	if (GetPixel(304, 136) != 0X60918) return false;
	if (GetPixel(304, 137) != 0X60917) return false;
	if (GetPixel(304, 138) != 0X50817) return false;
	if (GetPixel(304, 139) != 0X62D53) return false;
	if (GetPixel(305, 128) != 0X80E25) return false;
	if (GetPixel(305, 129) != 0X70E29) return false;
	if (GetPixel(305, 130) != 0X70D27) return false;
	if (GetPixel(305, 131) != 0X70B22) return false;
	if (GetPixel(305, 132) != 0X70A1D) return false;
	if (GetPixel(305, 133) != 0X70A1C) return false;
	if (GetPixel(305, 134) != 0X70A1C) return false;
	if (GetPixel(305, 135) != 0X7091A) return false;
	if (GetPixel(305, 136) != 0X60817) return false;
	if (GetPixel(305, 137) != 0X60817) return false;
	if (GetPixel(305, 138) != 0X60918) return false;
	if (GetPixel(305, 139) != 0X62E53) return false;
	if (GetPixel(306, 128) != 0X80E23) return false;
	if (GetPixel(306, 129) != 0X80E26) return false;
	if (GetPixel(306, 130) != 0X80E2A) return false;
	if (GetPixel(306, 131) != 0X80D28) return false;
	if (GetPixel(306, 132) != 0X80C22) return false;
	if (GetPixel(306, 133) != 0X80B1E) return false;
	if (GetPixel(306, 134) != 0X80B1E) return false;
	if (GetPixel(306, 135) != 0X70A1D) return false;
	if (GetPixel(306, 136) != 0X70A1B) return false;
	if (GetPixel(306, 137) != 0X70919) return false;
	if (GetPixel(306, 138) != 0X60A1B) return false;
	if (GetPixel(306, 139) != 0X6335B) return false;
	if (GetPixel(307, 128) != 0X80B1F) return false;
	if (GetPixel(307, 129) != 0X80C22) return false;
	if (GetPixel(307, 130) != 0X80D27) return false;
	if (GetPixel(307, 131) != 0X80D27) return false;
	if (GetPixel(307, 132) != 0X80D25) return false;
	if (GetPixel(307, 133) != 0X80B1E) return false;
	if (GetPixel(307, 134) != 0X80B1E) return false;
	if (GetPixel(307, 135) != 0X80B1E) return false;
	if (GetPixel(307, 136) != 0X70A1C) return false;
	if (GetPixel(307, 137) != 0X70A1B) return false;
	if (GetPixel(307, 138) != 0X71328) return false;
	if (GetPixel(307, 139) != 0X4548B) return false;
	if (GetPixel(308, 128) != 0X80C19) return false;
	if (GetPixel(308, 129) != 0X80C20) return false;
	if (GetPixel(308, 130) != 0X80F25) return false;
	if (GetPixel(308, 131) != 0X80D22) return false;
	if (GetPixel(308, 132) != 0X80E24) return false;
	if (GetPixel(308, 133) != 0X80C21) return false;
	if (GetPixel(308, 134) != 0X80B1F) return false;
	if (GetPixel(308, 135) != 0X80B1F) return false;
	if (GetPixel(308, 136) != 0X70B1E) return false;
	if (GetPixel(308, 137) != 0X70B19) return false;
	if (GetPixel(308, 138) != 0X70B1C) return false;
	if (GetPixel(308, 139) != 0X70A1D) return false;
	if (GetPixel(309, 128) != 0X80B1D) return false;
	if (GetPixel(309, 129) != 0X70C1F) return false;
	if (GetPixel(309, 130) != 0X70C20) return false;
	if (GetPixel(309, 131) != 0X70B1F) return false;
	if (GetPixel(309, 132) != 0X70D20) return false;
	if (GetPixel(309, 133) != 0X70B1D) return false;
	if (GetPixel(309, 134) != 0X70A1C) return false;
	if (GetPixel(309, 135) != 0X70A1C) return false;
	if (GetPixel(309, 136) != 0X70A1B) return false;
	if (GetPixel(309, 137) != 0X70A16) return false;
	if (GetPixel(309, 138) != 0X70A14) return false;
	if (GetPixel(309, 139) != 0X70A1A) return false;
	if (GetPixel(310, 128) != 0X70B21) return false;
	if (GetPixel(310, 129) != 0X70B1F) return false;
	if (GetPixel(310, 130) != 0X70B1E) return false;
	if (GetPixel(310, 131) != 0X70C20) return false;
	if (GetPixel(310, 132) != 0X60B1C) return false;
	if (GetPixel(310, 133) != 0X60B1D) return false;
	if (GetPixel(310, 134) != 0X60A1B) return false;
	if (GetPixel(310, 135) != 0X60A1B) return false;
	if (GetPixel(310, 136) != 0X6091B) return false;
	if (GetPixel(310, 137) != 0X60A19) return false;
	if (GetPixel(310, 138) != 0X60A17) return false;
	if (GetPixel(310, 139) != 0X70A1A) return false;
	if (GetPixel(311, 128) != 0X70B1F) return false;
	if (GetPixel(311, 129) != 0X60B1E) return false;
	if (GetPixel(311, 130) != 0X60C1D) return false;
	if (GetPixel(311, 131) != 0X60A1A) return false;
	if (GetPixel(311, 132) != 0X60A1A) return false;
	if (GetPixel(311, 133) != 0X51428) return false;
	if (GetPixel(311, 134) != 0X51225) return false;
	if (GetPixel(311, 135) != 0X51428) return false;
	if (GetPixel(311, 136) != 0X50C1B) return false;
	if (GetPixel(311, 137) != 0X60817) return false;
	if (GetPixel(311, 138) != 0X60918) return false;
	if (GetPixel(311, 139) != 0X60915) return false;
	if (GetPixel(312, 128) != 0X7091F) return false;
	if (GetPixel(312, 129) != 0X51730) return false;
	if (GetPixel(312, 130) != 0X5162D) return false;
	if (GetPixel(312, 131) != 0X5152A) return false;
	if (GetPixel(312, 132) != 0X41329) return false;
	if (GetPixel(312, 133) != 0X54A7D) return false;
	if (GetPixel(312, 134) != 0XA3FF) return false;
	if (GetPixel(312, 135) != 0X4619F) return false;
	if (GetPixel(312, 136) != 0X41427) return false;
	if (GetPixel(312, 137) != 0X41326) return false;
	if (GetPixel(312, 138) != 0X51427) return false;
	if (GetPixel(312, 139) != 0X51629) return false;
	if (GetPixel(313, 128) != 0X6081C) return false;
	if (GetPixel(313, 129) != 0XA3FF) return false;
	if (GetPixel(313, 130) != 0XA3FF) return false;
	if (GetPixel(313, 131) != 0XA3FF) return false;
	if (GetPixel(313, 132) != 0XA3FF) return false;
	if (GetPixel(313, 133) != 0XA3FF) return false;
	if (GetPixel(313, 134) != 0XA3FF) return false;
	if (GetPixel(313, 135) != 0XA3FF) return false;
	if (GetPixel(313, 136) != 0XA3FF) return false;
	if (GetPixel(313, 137) != 0XA3FF) return false;
	if (GetPixel(313, 138) != 0XA3FF) return false;
	if (GetPixel(313, 139) != 0XA3FF) return false;
	if (GetPixel(314, 128) != 0X6091E) return false;
	if (GetPixel(314, 129) != 0XA3FF) return false;
	if (GetPixel(314, 130) != 0X63B68) return false;
	if (GetPixel(314, 131) != 0X40F21) return false;
	if (GetPixel(314, 132) != 0X40F1F) return false;
	if (GetPixel(314, 133) != 0X31020) return false;
	if (GetPixel(314, 134) != 0XA3FF) return false;
	if (GetPixel(314, 135) != 0X63B68) return false;
	if (GetPixel(314, 136) != 0X30E1D) return false;
	if (GetPixel(314, 137) != 0X41020) return false;
	if (GetPixel(314, 138) != 0X41020) return false;
	if (GetPixel(314, 139) != 0X63A66) return false;
	if (GetPixel(315, 128) != 0X6091A) return false;
	if (GetPixel(315, 129) != 0XA3FF) return false;
	if (GetPixel(315, 130) != 0X62D57) return false;
	if (GetPixel(315, 131) != 0X40716) return false;
	if (GetPixel(315, 132) != 0X40715) return false;
	if (GetPixel(315, 133) != 0X40918) return false;
	if (GetPixel(315, 134) != 0XA3FF) return false;
	if (GetPixel(315, 135) != 0X62E54) return false;
	if (GetPixel(315, 136) != 0X40713) return false;
	if (GetPixel(315, 137) != 0X50714) return false;
	if (GetPixel(315, 138) != 0X40713) return false;
	if (GetPixel(315, 139) != 0X62C51) return false;
	if (GetPixel(316, 128) != 0X60918) return false;
	if (GetPixel(316, 129) != 0XA3FF) return false;
	if (GetPixel(316, 130) != 0X62D58) return false;
	if (GetPixel(316, 131) != 0X50718) return false;
	if (GetPixel(316, 132) != 0X50718) return false;
	if (GetPixel(316, 133) != 0X40A19) return false;
	if (GetPixel(316, 134) != 0XA3FF) return false;
	if (GetPixel(316, 135) != 0X62D53) return false;
	if (GetPixel(316, 136) != 0X50816) return false;
	if (GetPixel(316, 137) != 0X50916) return false;
	if (GetPixel(316, 138) != 0X50815) return false;
	if (GetPixel(316, 139) != 0X62C4F) return false;
	if (GetPixel(317, 128) != 0X60914) return false;
	if (GetPixel(317, 129) != 0XA3FF) return false;
	if (GetPixel(317, 130) != 0X62E59) return false;
	if (GetPixel(317, 131) != 0X5081A) return false;
	if (GetPixel(317, 132) != 0X50719) return false;
	if (GetPixel(317, 133) != 0X50C1D) return false;
	if (GetPixel(317, 134) != 0XA3FF) return false;
	if (GetPixel(317, 135) != 0X62E55) return false;
	if (GetPixel(317, 136) != 0X50816) return false;
	if (GetPixel(317, 137) != 0X50917) return false;
	if (GetPixel(317, 138) != 0X50816) return false;
	if (GetPixel(317, 139) != 0X62D50) return false;
	if (GetPixel(318, 128) != 0X53F66) return false;
	if (GetPixel(318, 129) != 0XA3FF) return false;
	if (GetPixel(318, 130) != 0X45F9C) return false;
	if (GetPixel(318, 131) != 0X60D20) return false;
	if (GetPixel(318, 132) != 0X6091E) return false;
	if (GetPixel(318, 133) != 0X54E84) return false;
	if (GetPixel(318, 134) != 0X9AF2) return false;
	if (GetPixel(318, 135) != 0X362A0) return false;
	if (GetPixel(318, 136) != 0X51023) return false;
	if (GetPixel(318, 137) != 0X60A1A) return false;
	if (GetPixel(318, 138) != 0X60F21) return false;
	if (GetPixel(318, 139) != 0X45E9A) return false;
	if (GetPixel(319, 128) != 0X20E16) return false;
	if (GetPixel(319, 129) != 0X50918) return false;
	if (GetPixel(319, 130) != 0X60E23) return false;
	if (GetPixel(319, 131) != 0X70C21) return false;
	if (GetPixel(319, 132) != 0X70A22) return false;
	if (GetPixel(319, 133) != 0X70A22) return false;
	if (GetPixel(319, 134) != 0X60A21) return false;
	if (GetPixel(319, 135) != 0X70920) return false;
	if (GetPixel(319, 136) != 0X70A1C) return false;
	if (GetPixel(319, 137) != 0X70A1C) return false;
	if (GetPixel(319, 138) != 0X70E1F) return false;
	if (GetPixel(319, 139) != 0X70F1F) return false;
	if (GetPixel(320, 128) != 0X3060C) return false;
	if (GetPixel(320, 129) != 0X60715) return false;
	if (GetPixel(320, 130) != 0X7081C) return false;
	if (GetPixel(320, 131) != 0X7091E) return false;
	if (GetPixel(320, 132) != 0X7091F) return false;
	if (GetPixel(320, 133) != 0X70A21) return false;
	if (GetPixel(320, 134) != 0X70920) return false;
	if (GetPixel(320, 135) != 0X70A21) return false;
	if (GetPixel(320, 136) != 0X70A1B) return false;
	if (GetPixel(320, 137) != 0X70A18) return false;
	if (GetPixel(320, 138) != 0X70A17) return false;
	if (GetPixel(320, 139) != 0X70813) return false;
	if (GetPixel(321, 128) != 0X40811) return false;
	if (GetPixel(321, 129) != 0X60713) return false;
	if (GetPixel(321, 130) != 0X70818) return false;
	if (GetPixel(321, 131) != 0X7091D) return false;
	if (GetPixel(321, 132) != 0X7091D) return false;
	if (GetPixel(321, 133) != 0X7091D) return false;
	if (GetPixel(321, 134) != 0X70A1F) return false;
	if (GetPixel(321, 135) != 0X80A21) return false;
	if (GetPixel(321, 136) != 0X80A1B) return false;
	if (GetPixel(321, 137) != 0X80918) return false;
	if (GetPixel(321, 138) != 0X80917) return false;
	if (GetPixel(321, 139) != 0X80811) return false;
	if (GetPixel(322, 128) != 0X50811) return false;
	if (GetPixel(322, 129) != 0X60612) return false;
	if (GetPixel(322, 130) != 0X70713) return false;
	if (GetPixel(322, 131) != 0X70818) return false;
	if (GetPixel(322, 132) != 0X70715) return false;
	if (GetPixel(322, 133) != 0X70818) return false;
	if (GetPixel(322, 134) != 0X8091E) return false;
	if (GetPixel(322, 135) != 0X80B21) return false;
	if (GetPixel(322, 136) != 0X80A1C) return false;
	if (GetPixel(322, 137) != 0X80A18) return false;
	if (GetPixel(322, 138) != 0X80B1B) return false;
	if (GetPixel(322, 139) != 0X80A18) return false;
	if (GetPixel(323, 128) != 0X5416A) return false;
	if (GetPixel(323, 129) != 0X45C93) return false;
	if (GetPixel(323, 130) != 0X54B7B) return false;
	if (GetPixel(323, 131) != 0X6101F) return false;
	if (GetPixel(323, 132) != 0X70814) return false;
	if (GetPixel(323, 133) != 0X70817) return false;
	if (GetPixel(323, 134) != 0X80A1D) return false;
	if (GetPixel(323, 135) != 0X80B21) return false;
	if (GetPixel(323, 136) != 0X80B1F) return false;
	if (GetPixel(323, 137) != 0X80C20) return false;
	if (GetPixel(323, 138) != 0X80B1E) return false;
	if (GetPixel(323, 139) != 0X80B1E) return false;
	if (GetPixel(324, 128) != 0X60E1E) return false;
	if (GetPixel(324, 129) != 0XA3FF) return false;
	if (GetPixel(324, 130) != 0X63355) return false;
	if (GetPixel(324, 131) != 0X60712) return false;
	if (GetPixel(324, 132) != 0X70813) return false;
	if (GetPixel(324, 133) != 0X70817) return false;
	if (GetPixel(324, 134) != 0X70A1D) return false;
	if (GetPixel(324, 135) != 0X80A1D) return false;
	if (GetPixel(324, 136) != 0X80B1E) return false;
	if (GetPixel(324, 137) != 0X80C21) return false;
	if (GetPixel(324, 138) != 0X80C20) return false;
	if (GetPixel(324, 139) != 0X80B1D) return false;
	if (GetPixel(325, 128) != 0X60815) return false;
	if (GetPixel(325, 129) != 0XA3FF) return false;
	if (GetPixel(325, 130) != 0X62B49) return false;
	if (GetPixel(325, 131) != 0X60610) return false;
	if (GetPixel(325, 132) != 0X60711) return false;
	if (GetPixel(325, 133) != 0X60713) return false;
	if (GetPixel(325, 134) != 0X70819) return false;
	if (GetPixel(325, 135) != 0X70919) return false;
	if (GetPixel(325, 136) != 0X70A1B) return false;
	if (GetPixel(325, 137) != 0X70B1F) return false;
	if (GetPixel(325, 138) != 0X70B1C) return false;
	if (GetPixel(325, 139) != 0X70A1B) return false;
	if (GetPixel(326, 128) != 0X60711) return false;
	if (GetPixel(326, 129) != 0XA3FF) return false;
	if (GetPixel(326, 130) != 0X62A4B) return false;
	if (GetPixel(326, 131) != 0X50510) return false;
	if (GetPixel(326, 132) != 0X60611) return false;
	if (GetPixel(326, 133) != 0X40611) return false;
	if (GetPixel(326, 134) != 0X70714) return false;
	if (GetPixel(326, 135) != 0X70715) return false;
	if (GetPixel(326, 136) != 0X70919) return false;
	if (GetPixel(326, 137) != 0X70A1C) return false;
	if (GetPixel(326, 138) != 0X70918) return false;
	if (GetPixel(326, 139) != 0X70917) return false;
	if (GetPixel(327, 128) != 0X60710) return false;
	if (GetPixel(327, 129) != 0XA3FF) return false;
	if (GetPixel(327, 130) != 0X42A49) return false;
	if (GetPixel(327, 131) != 0X5050F) return false;
	if (GetPixel(327, 132) != 0X50510) return false;
	if (GetPixel(327, 133) != 0X4050F) return false;
	if (GetPixel(327, 134) != 0X50611) return false;
	if (GetPixel(327, 135) != 0X40611) return false;
	if (GetPixel(327, 136) != 0X50816) return false;
	if (GetPixel(327, 137) != 0X60917) return false;
	if (GetPixel(327, 138) != 0X60712) return false;
	if (GetPixel(327, 139) != 0X60916) return false;
	if (GetPixel(328, 128) != 0X60610) return false;
	if (GetPixel(328, 129) != 0XA3FF) return false;
	if (GetPixel(328, 130) != 0X25A91) return false;
	if (GetPixel(328, 131) != 0X54573) return false;
	if (GetPixel(328, 132) != 0X34571) return false;
	if (GetPixel(328, 133) != 0X24570) return false;
	if (GetPixel(328, 134) != 0X34571) return false;
	if (GetPixel(328, 135) != 0X34571) return false;
	if (GetPixel(328, 136) != 0X44673) return false;
	if (GetPixel(328, 137) != 0X54774) return false;
	if (GetPixel(328, 138) != 0X54572) return false;
	if (GetPixel(328, 139) != 0X54877) return false;
	if (GetPixel(329, 128) != 0X5060F) return false;
	if (GetPixel(329, 129) != 0XA3FF) return false;
	if (GetPixel(329, 130) != 0X193E6) return false;
	if (GetPixel(329, 131) != 0X18EDF) return false;
	if (GetPixel(329, 132) != 0X18EDF) return false;
	if (GetPixel(329, 133) != 0X18EDF) return false;
	if (GetPixel(329, 134) != 0X18EDF) return false;
	if (GetPixel(329, 135) != 0X18EDF) return false;
	if (GetPixel(329, 136) != 0X18EDF) return false;
	if (GetPixel(329, 137) != 0X18EDF) return false;
	if (GetPixel(329, 138) != 0X18EDF) return false;
	if (GetPixel(329, 139) != 0X18FE1) return false;
	if (GetPixel(330, 128) != 0X40810) return false;
	if (GetPixel(330, 129) != 0XA3FF) return false;
	if (GetPixel(330, 130) != 0X42A49) return false;
	if (GetPixel(330, 131) != 0X3050E) return false;
	if (GetPixel(330, 132) != 0X3050F) return false;
	if (GetPixel(330, 133) != 0X3060F) return false;
	if (GetPixel(330, 134) != 0X30710) return false;
	if (GetPixel(330, 135) != 0X40711) return false;
	if (GetPixel(330, 136) != 0X40813) return false;
	if (GetPixel(330, 137) != 0X40915) return false;
	if (GetPixel(330, 138) != 0X20813) return false;
	if (GetPixel(330, 139) != 0X20712) return false;
	if (GetPixel(331, 128) != 0X40810) return false;
	if (GetPixel(331, 129) != 0XA3FF) return false;
	if (GetPixel(331, 130) != 0X42A49) return false;
	if (GetPixel(331, 131) != 0X3050E) return false;
	if (GetPixel(331, 132) != 0X3060F) return false;
	if (GetPixel(331, 133) != 0X2060E) return false;
	if (GetPixel(331, 134) != 0X20510) return false;
	if (GetPixel(331, 135) != 0X30711) return false;
	if (GetPixel(331, 136) != 0X40814) return false;
	if (GetPixel(331, 137) != 0X30815) return false;
	if (GetPixel(331, 138) != 0X40916) return false;
	if (GetPixel(331, 139) != 0X30814) return false;
	if (GetPixel(332, 128) != 0X40811) return false;
	if (GetPixel(332, 129) != 0XA3FF) return false;
	if (GetPixel(332, 130) != 0X42A49) return false;
	if (GetPixel(332, 131) != 0X3060F) return false;
	if (GetPixel(332, 132) != 0X40611) return false;
	if (GetPixel(332, 133) != 0X2060F) return false;
	if (GetPixel(332, 134) != 0X30611) return false;
	if (GetPixel(332, 135) != 0X30711) return false;
	if (GetPixel(332, 136) != 0X30814) return false;
	if (GetPixel(332, 137) != 0X20814) return false;
	if (GetPixel(332, 138) != 0X30A17) return false;
	if (GetPixel(332, 139) != 0X50A1B) return false;
	if (GetPixel(333, 128) != 0X40911) return false;
	if (GetPixel(333, 129) != 0XA3FF) return false;
	if (GetPixel(333, 130) != 0X42C4B) return false;
	if (GetPixel(333, 131) != 0X40711) return false;
	if (GetPixel(333, 132) != 0X40712) return false;
	if (GetPixel(333, 133) != 0X30711) return false;
	if (GetPixel(333, 134) != 0X20611) return false;
	if (GetPixel(333, 135) != 0X30712) return false;
	if (GetPixel(333, 136) != 0X40812) return false;
	if (GetPixel(333, 137) != 0X40812) return false;
	if (GetPixel(333, 138) != 0X60A16) return false;
	if (GetPixel(333, 139) != 0X70B19) return false;
	if (GetPixel(334, 128) != 0X3426B) return false;
	if (GetPixel(334, 129) != 0XA3FF) return false;
	if (GetPixel(334, 130) != 0X16098) return false;
	if (GetPixel(334, 131) != 0X20E1A) return false;
	if (GetPixel(334, 132) != 0X40813) return false;
	if (GetPixel(334, 133) != 0X50814) return false;
	if (GetPixel(334, 134) != 0X30813) return false;
	if (GetPixel(334, 135) != 0X20713) return false;
	if (GetPixel(334, 136) != 0X30811) return false;
	if (GetPixel(334, 137) != 0X40912) return false;
	if (GetPixel(334, 138) != 0X60A14) return false;
	if (GetPixel(334, 139) != 0X60A14) return false;
	if (GetPixel(335, 128) != 0X40E19) return false;
	if (GetPixel(335, 129) != 0X40712) return false;
	if (GetPixel(335, 130) != 0X40A17) return false;
	if (GetPixel(335, 131) != 0X40A16) return false;
	if (GetPixel(335, 132) != 0X40814) return false;
	if (GetPixel(335, 133) != 0X40813) return false;
	if (GetPixel(335, 134) != 0X20712) return false;
	if (GetPixel(335, 135) != 0X20712) return false;
	if (GetPixel(335, 136) != 0X2070E) return false;
	if (GetPixel(335, 137) != 0X2070E) return false;
	if (GetPixel(335, 138) != 0X50912) return false;
	if (GetPixel(335, 139) != 0X50913) return false;
	if (GetPixel(336, 128) != 0X20811) return false;
	if (GetPixel(336, 129) != 0X30711) return false;
	if (GetPixel(336, 130) != 0X60613) return false;
	if (GetPixel(336, 131) != 0X60613) return false;
	if (GetPixel(336, 132) != 0X40712) return false;
	if (GetPixel(336, 133) != 0X40712) return false;
	if (GetPixel(336, 134) != 0X40712) return false;
	if (GetPixel(336, 135) != 0X20610) return false;
	if (GetPixel(336, 136) != 0X309) return false;
	if (GetPixel(336, 137) != 0X1050A) return false;
	if (GetPixel(336, 138) != 0X2060B) return false;
	if (GetPixel(336, 139) != 0X40811) return false;
	if (GetPixel(337, 128) != 0X20814) return false;
	if (GetPixel(337, 129) != 0X30612) return false;
	if (GetPixel(337, 130) != 0X40612) return false;
	if (GetPixel(337, 131) != 0X40611) return false;
	if (GetPixel(337, 132) != 0X30610) return false;
	if (GetPixel(337, 133) != 0X2050F) return false;
	if (GetPixel(337, 134) != 0X30610) return false;
	if (GetPixel(337, 135) != 0X1050E) return false;
	if (GetPixel(337, 136) != 0X1030B) return false;
	if (GetPixel(337, 137) != 0X2030B) return false;
	if (GetPixel(337, 138) != 0X3060F) return false;
	if (GetPixel(337, 139) != 0X40710) return false;
	if (GetPixel(338, 128) != 0X20813) return false;
	if (GetPixel(338, 129) != 0X2060E) return false;
	if (GetPixel(338, 130) != 0X1060E) return false;
	if (GetPixel(338, 131) != 0X40610) return false;
	if (GetPixel(338, 132) != 0X30610) return false;
	if (GetPixel(338, 133) != 0X1111E) return false;
	if (GetPixel(338, 134) != 0X10E1B) return false;
	if (GetPixel(338, 135) != 0X1101F) return false;
	if (GetPixel(338, 136) != 0X30912) return false;
	if (GetPixel(338, 137) != 0X4060E) return false;
	if (GetPixel(338, 138) != 0X4060E) return false;
	if (GetPixel(338, 139) != 0X4060F) return false;
	if (GetPixel(339, 128) != 0X30914) return false;
	if (GetPixel(339, 129) != 0X21324) return false;
	if (GetPixel(339, 130) != 0X31323) return false;
	if (GetPixel(339, 131) != 0X31121) return false;
	if (GetPixel(339, 132) != 0X2111E) return false;
	if (GetPixel(339, 133) != 0X24774) return false;
	if (GetPixel(339, 134) != 0XA3FF) return false;
	if (GetPixel(339, 135) != 0X25F99) return false;
	if (GetPixel(339, 136) != 0X21220) return false;
	if (GetPixel(339, 137) != 0X2111D) return false;
	if (GetPixel(339, 138) != 0X31120) return false;
	if (GetPixel(339, 139) != 0X31323) return false;
	if (GetPixel(340, 128) != 0X50816) return false;
	if (GetPixel(340, 129) != 0XA3FF) return false;
	if (GetPixel(340, 130) != 0XA3FF) return false;
	if (GetPixel(340, 131) != 0XA3FF) return false;
	if (GetPixel(340, 132) != 0XA3FF) return false;
	if (GetPixel(340, 133) != 0XA3FF) return false;
	if (GetPixel(340, 134) != 0XA3FF) return false;
	if (GetPixel(340, 135) != 0XA3FF) return false;
	if (GetPixel(340, 136) != 0XA3FF) return false;
	if (GetPixel(340, 137) != 0XA3FF) return false;
	if (GetPixel(340, 138) != 0XA3FF) return false;
	if (GetPixel(340, 139) != 0XA3FF) return false;
	if (GetPixel(341, 128) != 0X60919) return false;
	if (GetPixel(341, 129) != 0XA3FF) return false;
	if (GetPixel(341, 130) != 0X43963) return false;
	if (GetPixel(341, 131) != 0X20E1C) return false;
	if (GetPixel(341, 132) != 0X20E19) return false;
	if (GetPixel(341, 133) != 0X20F1A) return false;
	if (GetPixel(341, 134) != 0XA3FF) return false;
	if (GetPixel(341, 135) != 0X2375C) return false;
	if (GetPixel(341, 136) != 0X10B14) return false;
	if (GetPixel(341, 137) != 0X10C16) return false;
	if (GetPixel(341, 138) != 0X20C16) return false;
	if (GetPixel(341, 139) != 0X4375D) return false;
	if (GetPixel(342, 128) != 0X30814) return false;
	if (GetPixel(342, 129) != 0XA3FF) return false;
	if (GetPixel(342, 130) != 0X22C4B) return false;
	if (GetPixel(342, 131) != 0X1050C) return false;
	if (GetPixel(342, 132) != 0X1050C) return false;
	if (GetPixel(342, 133) != 0X2070E) return false;
	if (GetPixel(342, 134) != 0XA3FF) return false;
	if (GetPixel(342, 135) != 0X22947) return false;
	if (GetPixel(342, 136) != 0X10308) return false;
	if (GetPixel(342, 137) != 0X10307) return false;
	if (GetPixel(342, 138) != 0X10307) return false;
	if (GetPixel(342, 139) != 0X42947) return false;
	if (GetPixel(343, 128) != 0X20711) return false;
	if (GetPixel(343, 129) != 0XA3FF) return false;
	if (GetPixel(343, 130) != 0X22B49) return false;
	if (GetPixel(343, 131) != 0X1050D) return false;
	if (GetPixel(343, 132) != 0X1050D) return false;
	if (GetPixel(343, 133) != 0X2070F) return false;
	if (GetPixel(343, 134) != 0XA3FF) return false;
	if (GetPixel(343, 135) != 0X22947) return false;
	if (GetPixel(343, 136) != 0X10309) return false;
	if (GetPixel(343, 137) != 0X10308) return false;
	if (GetPixel(343, 138) != 0X2040A) return false;
	if (GetPixel(343, 139) != 0X42947) return false;
	if (GetPixel(344, 128) != 0X30610) return false;
	if (GetPixel(344, 129) != 0XA3FF) return false;
	if (GetPixel(344, 130) != 0X52B4C) return false;
	if (GetPixel(344, 131) != 0X4050F) return false;
	if (GetPixel(344, 132) != 0X3050C) return false;
	if (GetPixel(344, 133) != 0X40910) return false;
	if (GetPixel(344, 134) != 0XA3FF) return false;
	if (GetPixel(344, 135) != 0X22A46) return false;
	if (GetPixel(344, 136) != 0X10409) return false;
	if (GetPixel(344, 137) != 0X10509) return false;
	if (GetPixel(344, 138) != 0X10409) return false;
	if (GetPixel(344, 139) != 0X22A44) return false;

	return true;
}
bool				Win32GDI::D3IsOpenStash(void)
{
	int color = 0;
	if (GetPixel(0, 0) != 0X80808) return false;
	if (GetPixel(0, 1) != 0X80909) return false;
	if (GetPixel(0, 2) != 0X80909) return false;
	if (GetPixel(0, 4) != 0XA080B) return false;
	if (GetPixel(0, 5) != 0X80509) return false;
	if (GetPixel(0, 6) != 0X80509) return false;
	if (GetPixel(0, 7) != 0X20509) return false;
	if (GetPixel(0, 8) != 0X10509) return false;
	if (GetPixel(0, 9) != 0X10509) return false;
	if (GetPixel(0, 10) != 0X10509) return false;
	if (GetPixel(0, 11) != 0X10509) return false;
	if (GetPixel(0, 12) != 0X10509) return false;
	if (GetPixel(0, 13) != 0X10509) return false;
	if (GetPixel(0, 14) != 0X50509) return false;
	if (GetPixel(0, 15) != 0X80509) return false;
	if (GetPixel(0, 16) != 0X80509) return false;
	if (GetPixel(0, 17) != 0X80509) return false;
	if (GetPixel(0, 18) != 0X10509) return false;
	if (GetPixel(0, 19) != 0X10509) return false;
	if (GetPixel(0, 20) != 0X10509) return false;
	if (GetPixel(0, 21) != 0X40509) return false;
	if (GetPixel(0, 22) != 0X80509) return false;
	if (GetPixel(0, 23) != 0X80509) return false;
	if (GetPixel(0, 24) != 0X80509) return false;
	if (GetPixel(0, 25) != 0X80509) return false;
	if (GetPixel(0, 26) != 0X80509) return false;
	if (GetPixel(0, 27) != 0X80509) return false;
	if (GetPixel(0, 28) != 0X80509) return false;
	if (GetPixel(0, 29) != 0X80509) return false;
	if (GetPixel(0, 30) != 0X80509) return false;
	if (GetPixel(0, 31) != 0X80509) return false;
	if (GetPixel(0, 32) != 0X80509) return false;
	if (GetPixel(0, 33) != 0X80509) return false;
	if (GetPixel(0, 34) != 0X80509) return false;
	if (GetPixel(1, 0) != 0X90909) return false;
	if (GetPixel(1, 4) != 0XD1213) return false;
	if (GetPixel(1, 5) != 0XD1213) return false;
	if (GetPixel(1, 6) != 0XD1213) return false;
	if (GetPixel(1, 7) != 0XB1213) return false;
	if (GetPixel(1, 8) != 0XB1213) return false;
	if (GetPixel(1, 9) != 0XB1213) return false;
	if (GetPixel(1, 10) != 0XB1213) return false;
	if (GetPixel(1, 11) != 0XB1213) return false;
	if (GetPixel(1, 12) != 0XB1213) return false;
	if (GetPixel(1, 13) != 0XB1213) return false;
	if (GetPixel(1, 14) != 0XC1213) return false;
	if (GetPixel(1, 15) != 0XD1213) return false;
	if (GetPixel(1, 16) != 0XD1213) return false;
	if (GetPixel(1, 17) != 0XD1213) return false;
	if (GetPixel(1, 18) != 0XB1113) return false;
	if (GetPixel(1, 19) != 0XB1113) return false;
	if (GetPixel(1, 20) != 0XB1113) return false;
	if (GetPixel(1, 21) != 0XC1113) return false;
	if (GetPixel(1, 22) != 0XD1213) return false;
	if (GetPixel(1, 23) != 0XD1213) return false;
	if (GetPixel(1, 24) != 0XD1213) return false;
	if (GetPixel(1, 25) != 0XD1213) return false;
	if (GetPixel(1, 26) != 0XD1213) return false;
	if (GetPixel(1, 27) != 0XD1213) return false;
	if (GetPixel(1, 28) != 0XD1213) return false;
	if (GetPixel(1, 29) != 0XD1213) return false;
	if (GetPixel(1, 30) != 0XD1213) return false;
	if (GetPixel(1, 31) != 0XD1213) return false;
	if (GetPixel(1, 32) != 0XD1213) return false;
	if (GetPixel(1, 33) != 0XD1213) return false;
	if (GetPixel(1, 34) != 0XD1213) return false;
	if (GetPixel(2, 0) != 0X90A0A) return false;
	if (GetPixel(3, 0) != 0X90A0A) return false;
	if (GetPixel(4, 0) != 0X90A0A) return false;
	if (GetPixel(4, 1) != 0X212C31) return false;
	if (GetPixel(4, 2) != 0X202A2F) return false;
	if (GetPixel(4, 11) != 0X182024) return false;
	if (GetPixel(4, 12) != 0X182024) return false;
	if (GetPixel(4, 13) != 0X182024) return false;
	if (GetPixel(5, 0) != 0X90A0A) return false;
	if (GetPixel(5, 1) != 0X212C31) return false;
	if (GetPixel(5, 2) != 0X212C31) return false;
	if (GetPixel(5, 11) != 0X1D272C) return false;
	if (GetPixel(5, 12) != 0X1D272C) return false;
	if (GetPixel(5, 13) != 0X1D272C) return false;
	if (GetPixel(6, 12) != 0X1B2429) return false;
	if (GetPixel(7, 0) != 0XA0A0A) return false;
	if (GetPixel(7, 12) != 0X202B30) return false;
	if (GetPixel(7, 19) != 0X212831) return false;
	if (GetPixel(8, 0) != 0XA0A0A) return false;
	if (GetPixel(8, 1) != 0X293031) return false;
	if (GetPixel(8, 2) != 0X262C2D) return false;
	if (GetPixel(8, 3) != 0X232A2C) return false;
	if (GetPixel(8, 8) != 0X2060A) return false;
	if (GetPixel(8, 9) != 0X2060A) return false;
	if (GetPixel(8, 10) != 0X3060A) return false;
	if (GetPixel(8, 11) != 0X9060A) return false;
	if (GetPixel(8, 12) != 0X9060A) return false;
	if (GetPixel(8, 13) != 0X9060A) return false;
	if (GetPixel(8, 18) != 0X20203) return false;
	if (GetPixel(8, 19) != 0X20203) return false;
	if (GetPixel(8, 20) != 0X20203) return false;
	if (GetPixel(8, 21) != 0X20202) return false;
	if (GetPixel(8, 22) != 0X70708) return false;
	if (GetPixel(8, 23) != 0X121417) return false;
	if (GetPixel(8, 24) != 0XF1012) return false;
	if (GetPixel(8, 32) != 0X111619) return false;
	if (GetPixel(8, 34) != 0X90A0A) return false;
	if (GetPixel(9, 0) != 0XA0A0A) return false;
	if (GetPixel(9, 1) != 0X293031) return false;
	if (GetPixel(9, 8) != 0X10509) return false;
	if (GetPixel(9, 9) != 0XB0F16) return false;
	if (GetPixel(9, 10) != 0XC0F16) return false;
	if (GetPixel(9, 11) != 0X101116) return false;
	if (GetPixel(9, 13) != 0XC0B10) return false;
	if (GetPixel(9, 18) != 0XB0D10) return false;
	if (GetPixel(9, 19) != 0XB0D10) return false;
	if (GetPixel(9, 20) != 0XB0D10) return false;
	if (GetPixel(9, 21) != 0XB0D0F) return false;
	if (GetPixel(9, 33) != 0X80808) return false;
	if (GetPixel(11, 0) != 0XA0A0B) return false;
	if (GetPixel(11, 15) != 0X121717) return false;
	if (GetPixel(11, 16) != 0X141A1A) return false;
	if (GetPixel(11, 17) != 0X141A1B) return false;
	if (GetPixel(11, 18) != 0X101619) return false;
	if (GetPixel(11, 19) != 0X141B1C) return false;
	if (GetPixel(11, 20) != 0X12191B) return false;
	if (GetPixel(11, 31) != 0X90D11) return false;
	if (GetPixel(12, 0) != 0XA0A0B) return false;
	if (GetPixel(12, 14) != 0XF1214) return false;
	if (GetPixel(12, 15) != 0XD1010) return false;
	if (GetPixel(12, 16) != 0X111616) return false;
	if (GetPixel(12, 17) != 0X141A1A) return false;
	if (GetPixel(12, 18) != 0X141A1D) return false;
	if (GetPixel(12, 19) != 0X11181A) return false;
	if (GetPixel(12, 20) != 0XE1316) return false;
	if (GetPixel(12, 21) != 0XB1012) return false;
	if (GetPixel(12, 22) != 0XC1010) return false;
	if (GetPixel(12, 30) != 0XB0F13) return false;
	if (GetPixel(13, 16) != 0X80808) return false;
	if (GetPixel(13, 17) != 0XA0C0C) return false;
	if (GetPixel(13, 18) != 0XA0F13) return false;
	if (GetPixel(14, 1) != 0X293439) return false;
	if (GetPixel(14, 16) != 0XB0B0B) return false;
	if (GetPixel(14, 17) != 0XB0B0B) return false;
	if (GetPixel(15, 1) != 0X293439) return false;
	if (GetPixel(15, 2) != 0X263035) return false;
	if (GetPixel(15, 4) != 0X1C2127) return false;
	if (GetPixel(15, 5) != 0X181C21) return false;
	if (GetPixel(15, 6) != 0X181C21) return false;
	if (GetPixel(15, 11) != 0XC1014) return false;
	if (GetPixel(15, 12) != 0XA0E12) return false;
	if (GetPixel(15, 13) != 0X12191B) return false;
	if (GetPixel(15, 14) != 0X151818) return false;
	if (GetPixel(15, 15) != 0XE0E0E) return false;
	if (GetPixel(15, 16) != 0X101010) return false;
	if (GetPixel(15, 17) != 0X151515) return false;
	if (GetPixel(15, 26) != 0X202A2F) return false;
	if (GetPixel(15, 27) != 0X1A2225) return false;
	if (GetPixel(16, 1) != 0X293439) return false;
	if (GetPixel(16, 2) != 0X283338) return false;
	if (GetPixel(16, 3) != 0X2D373F) return false;
	if (GetPixel(16, 4) != 0X2B343D) return false;
	if (GetPixel(16, 5) != 0X1C2026) return false;
	if (GetPixel(16, 6) != 0X181C21) return false;
	if (GetPixel(16, 11) != 0X90D11) return false;
	if (GetPixel(16, 12) != 0XA0E12) return false;
	if (GetPixel(16, 13) != 0X12191B) return false;
	if (GetPixel(16, 14) != 0X121515) return false;
	if (GetPixel(16, 15) != 0X111111) return false;
	if (GetPixel(16, 16) != 0X161616) return false;
	if (GetPixel(16, 17) != 0X181818) return false;
	if (GetPixel(16, 25) != 0XF0F10) return false;
	if (GetPixel(16, 26) != 0X202A2F) return false;
	if (GetPixel(16, 27) != 0X161A1C) return false;
	if (GetPixel(16, 28) != 0X101111) return false;
	if (GetPixel(17, 6) != 0X181C21) return false;
	if (GetPixel(17, 8) != 0X10202) return false;
	if (GetPixel(17, 11) != 0X80C10) return false;
	if (GetPixel(17, 12) != 0XC1114) return false;
	if (GetPixel(17, 13) != 0X131A1B) return false;
	if (GetPixel(17, 33) != 0X1E2324) return false;
	if (GetPixel(17, 34) != 0X181B1C) return false;
	if (GetPixel(18, 8) != 0X10102) return false;
	if (GetPixel(18, 9) != 0X8090B) return false;
	if (GetPixel(18, 10) != 0X80A0C) return false;
	if (GetPixel(18, 11) != 0X80C10) return false;
	if (GetPixel(18, 12) != 0XD1215) return false;
	if (GetPixel(18, 13) != 0X101618) return false;
	if (GetPixel(18, 14) != 0XA0C0D) return false;
	if (GetPixel(18, 15) != 0X80808) return false;
	if (GetPixel(18, 16) != 0X111415) return false;
	if (GetPixel(18, 17) != 0X131618) return false;
	if (GetPixel(18, 18) != 0X181B1B) return false;
	if (GetPixel(18, 19) != 0X181D1E) return false;
	if (GetPixel(18, 20) != 0X181D1E) return false;
	if (GetPixel(18, 21) != 0X181D1F) return false;
	if (GetPixel(18, 22) != 0X15191C) return false;
	if (GetPixel(18, 23) != 0XF1313) return false;
	if (GetPixel(18, 24) != 0X90D0A) return false;
	if (GetPixel(19, 8) != 0X40505) return false;
	if (GetPixel(19, 9) != 0X90B0D) return false;
	if (GetPixel(19, 10) != 0XA0C0F) return false;
	if (GetPixel(19, 11) != 0XF1518) return false;
	if (GetPixel(19, 12) != 0X12191A) return false;
	if (GetPixel(19, 13) != 0XD1215) return false;
	if (GetPixel(19, 14) != 0X80A0B) return false;
	if (GetPixel(19, 15) != 0XC0D0F) return false;
	if (GetPixel(19, 16) != 0X131618) return false;
	if (GetPixel(19, 17) != 0X181C21) return false;
	if (GetPixel(19, 18) != 0X181D1E) return false;
	if (GetPixel(19, 19) != 0X181D1E) return false;
	if (GetPixel(19, 21) != 0X181D1F) return false;
	if (GetPixel(19, 22) != 0X15191C) return false;
	if (GetPixel(19, 23) != 0XF1313) return false;
	if (GetPixel(19, 24) != 0X90D0A) return false;
	if (GetPixel(19, 34) != 0X111111) return false;
	if (GetPixel(20, 30) != 0X131415) return false;
	if (GetPixel(21, 0) != 0XA0A0A) return false;
	if (GetPixel(22, 0) != 0XA0A0A) return false;
	if (GetPixel(22, 1) != 0X293234) return false;
	if (GetPixel(22, 2) != 0X293234) return false;
	if (GetPixel(22, 3) != 0X293336) return false;
	if (GetPixel(22, 4) != 0X1E2528) return false;
	if (GetPixel(22, 5) != 0X101213) return false;
	if (GetPixel(22, 6) != 0X111416) return false;
	if (GetPixel(22, 9) != 0X80808) return false;
	if (GetPixel(22, 10) != 0X80908) return false;
	if (GetPixel(22, 11) != 0XA0E0C) return false;
	if (GetPixel(22, 12) != 0XD1112) return false;
	if (GetPixel(22, 13) != 0XF1317) return false;
	if (GetPixel(23, 0) != 0XA0A0A) return false;
	if (GetPixel(23, 1) != 0X293234) return false;
	if (GetPixel(23, 2) != 0X293234) return false;
	if (GetPixel(23, 3) != 0X293336) return false;
	if (GetPixel(23, 4) != 0X1E2528) return false;
	if (GetPixel(23, 5) != 0X101314) return false;
	if (GetPixel(23, 6) != 0X121416) return false;
	if (GetPixel(23, 9) != 0X80808) return false;
	if (GetPixel(23, 11) != 0XD1112) return false;
	if (GetPixel(23, 12) != 0XF1317) return false;
	if (GetPixel(23, 13) != 0XF1316) return false;
	if (GetPixel(23, 18) != 0X101010) return false;
	if (GetPixel(23, 22) != 0X12181A) return false;
	if (GetPixel(23, 23) != 0X12181A) return false;
	if (GetPixel(24, 9) != 0X80808) return false;
	if (GetPixel(25, 0) != 0XA0B0B) return false;
	if (GetPixel(25, 4) != 0X1E2628) return false;
	if (GetPixel(25, 5) != 0X101818) return false;
	if (GetPixel(25, 6) != 0X101818) return false;
	if (GetPixel(25, 9) != 0X80808) return false;
	if (GetPixel(25, 11) != 0X90D11) return false;
	if (GetPixel(25, 12) != 0X90D11) return false;
	if (GetPixel(25, 16) != 0X1F2627) return false;
	if (GetPixel(26, 4) != 0X1E2628) return false;
	if (GetPixel(26, 5) != 0X101818) return false;
	if (GetPixel(26, 6) != 0X101818) return false;
	if (GetPixel(26, 9) != 0X80808) return false;
	if (GetPixel(26, 10) != 0X8090A) return false;
	if (GetPixel(26, 11) != 0X80C10) return false;
	if (GetPixel(26, 15) != 0X212829) return false;
	if (GetPixel(26, 16) != 0X14191C) return false;
	if (GetPixel(26, 17) != 0XA0E12) return false;
	if (GetPixel(26, 29) != 0X101516) return false;
	if (GetPixel(26, 30) != 0XD1211) return false;
	if (GetPixel(26, 31) != 0X151A1D) return false;
	if (GetPixel(27, 0) != 0X90A0A) return false;
	if (GetPixel(27, 5) != 0X101818) return false;
	if (GetPixel(27, 6) != 0X101818) return false;
	if (GetPixel(27, 10) != 0X8090A) return false;
	if (GetPixel(27, 17) != 0X101518) return false;
	if (GetPixel(27, 30) != 0XD1110) return false;
	if (GetPixel(27, 31) != 0X141A1C) return false;
	if (GetPixel(28, 0) != 0X90A0A) return false;
	if (GetPixel(29, 0) != 0X90A0A) return false;
	if (GetPixel(29, 1) != 0X212C31) return false;
	if (GetPixel(29, 2) != 0X212C31) return false;
	if (GetPixel(29, 3) != 0X232E33) return false;
	if (GetPixel(29, 11) != 0X1E2125) return false;
	if (GetPixel(29, 12) != 0X17191B) return false;
	if (GetPixel(29, 13) != 0X111111) return false;
	if (GetPixel(29, 14) != 0X131515) return false;
	if (GetPixel(30, 0) != 0X90A0A) return false;
	if (GetPixel(30, 1) != 0X202B30) return false;
	if (GetPixel(30, 2) != 0X1E292D) return false;
	if (GetPixel(30, 10) != 0X181B20) return false;
	if (GetPixel(30, 11) != 0X151617) return false;
	if (GetPixel(30, 12) != 0X111111) return false;
	if (GetPixel(30, 13) != 0X151617) return false;
	if (GetPixel(32, 4) != 0X1F292C) return false;
	if (GetPixel(32, 5) != 0X121A1B) return false;
	if (GetPixel(32, 6) != 0X101818) return false;
	if (GetPixel(32, 16) != 0X131618) return false;
	if (GetPixel(32, 19) != 0X1A2020) return false;
	if (GetPixel(32, 20) != 0X121415) return false;
	if (GetPixel(33, 4) != 0X202A2E) return false;
	if (GetPixel(33, 5) != 0X131C1C) return false;
	if (GetPixel(33, 6) != 0X101818) return false;
	if (GetPixel(33, 15) != 0X131618) return false;
	if (GetPixel(33, 16) != 0X1A2022) return false;
	if (GetPixel(33, 17) != 0X1E2629) return false;
	if (GetPixel(33, 18) != 0XF1011) return false;
	if (GetPixel(33, 19) != 0XC0D0D) return false;
	if (GetPixel(33, 20) != 0X80808) return false;
	if (GetPixel(33, 33) != 0XE1214) return false;
	if (GetPixel(33, 34) != 0XE1214) return false;
	if (GetPixel(34, 4) != 0X1D2729) return false;
	if (GetPixel(34, 5) != 0X101919) return false;
	if (GetPixel(34, 6) != 0X101818) return false;
	if (GetPixel(34, 7) != 0X171B1F) return false;
	if (GetPixel(34, 15) != 0X1A2022) return false;
	if (GetPixel(34, 16) != 0X1E2629) return false;
	if (GetPixel(34, 17) != 0XD0E0F) return false;
	if (GetPixel(34, 18) != 0X80808) return false;
	if (GetPixel(34, 19) != 0X9090A) return false;
	if (GetPixel(34, 20) != 0XF1011) return false;
	if (GetPixel(34, 33) != 0XD1012) return false;
	if (GetPixel(34, 34) != 0XD1113) return false;
	color = GetPixel(0, 3); if (color != 0X9090A && color != 0X9090B) return false;
	color = GetPixel(1, 1); if (color != 0X121516 && color != 0X12151A) return false;
	color = GetPixel(1, 2); if (color != 0X101213 && color != 0X101216) return false;
	color = GetPixel(1, 3); if (color != 0XF1213 && color != 0XF1215) return false;
	color = GetPixel(2, 1); if (color != 0X1F252D && color != 0X1F2628) return false;
	color = GetPixel(2, 2); if (color != 0X121419 && color != 0X121516) return false;
	color = GetPixel(2, 3); if (color != 0XF1213 && color != 0XF1215) return false;
	color = GetPixel(2, 4); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 5); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 6); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 7); if (color != 0XB1213 && color != 0XD1112) return false;
	color = GetPixel(2, 8); if (color != 0XB1213 && color != 0XC1112) return false;
	color = GetPixel(2, 9); if (color != 0XB1213 && color != 0XC1112) return false;
	color = GetPixel(2, 10); if (color != 0XB1213 && color != 0XC1212) return false;
	color = GetPixel(2, 11); if (color != 0XB1213 && color != 0XC1314) return false;
	color = GetPixel(2, 12); if (color != 0XB1213 && color != 0XC1314) return false;
	color = GetPixel(2, 13); if (color != 0XB1213 && color != 0XC1314) return false;
	color = GetPixel(2, 14); if (color != 0XC1213 && color != 0XD1214) return false;
	color = GetPixel(2, 15); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(2, 16); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(2, 17); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(2, 18); if (color != 0XB1113 && color != 0XC1114) return false;
	color = GetPixel(2, 19); if (color != 0XB1113 && color != 0XC1114) return false;
	color = GetPixel(2, 20); if (color != 0XB1113 && color != 0XC1114) return false;
	color = GetPixel(2, 21); if (color != 0XC1113 && color != 0XD1113) return false;
	color = GetPixel(2, 22); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 23); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 24); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 25); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 26); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 27); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 28); if (color != 0XD1213 && color != 0XE1112) return false;
	color = GetPixel(2, 29); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(2, 30); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(2, 31); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(2, 32); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(2, 33); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(2, 34); if (color != 0XD1213 && color != 0XE1214) return false;
	color = GetPixel(3, 1); if (color != 0X202930 && color != 0X202B30) return false;
	color = GetPixel(3, 2); if (color != 0X192025 && color != 0X192225) return false;
	color = GetPixel(3, 3); if (color != 0X111619 && color != 0X121517) return false;
	color = GetPixel(3, 4); if (color != 0XE1315 && color != 0X101010) return false;
	color = GetPixel(3, 5); if (color != 0XE1315 && color != 0X111213) return false;
	color = GetPixel(3, 6); if (color != 0XE1315 && color != 0X121314) return false;
	color = GetPixel(3, 7); if (color != 0XD1115 && color != 0X101111) return false;
	color = GetPixel(3, 8); if (color != 0XD1115 && color != 0X101010) return false;
	color = GetPixel(3, 9); if (color != 0XD1115 && color != 0X101010) return false;
	color = GetPixel(3, 10); if (color != 0XF1418 && color != 0X121415) return false;
	color = GetPixel(3, 11); if (color != 0XD1315 && color != 0X101418) return false;
	color = GetPixel(3, 12); if (color != 0XD1315 && color != 0X101418) return false;
	color = GetPixel(3, 13); if (color != 0XD1315 && color != 0X101418) return false;
	color = GetPixel(3, 14); if (color != 0XE1315 && color != 0X101217) return false;
	color = GetPixel(3, 15); if (color != 0XE1315 && color != 0X101116) return false;
	color = GetPixel(3, 16); if (color != 0XE1315 && color != 0X101116) return false;
	color = GetPixel(3, 17); if (color != 0XE1315 && color != 0X101116) return false;
	color = GetPixel(3, 18); if (color != 0XD1215 && color != 0X101018) return false;
	color = GetPixel(3, 19); if (color != 0XD1215 && color != 0X101018) return false;
	color = GetPixel(3, 20); if (color != 0XD1215 && color != 0X101018) return false;
	color = GetPixel(3, 21); if (color != 0XD1215 && color != 0X101015) return false;
	color = GetPixel(3, 22); if (color != 0XE1315 && color != 0X101010) return false;
	color = GetPixel(3, 23); if (color != 0XE1315 && color != 0X101010) return false;
	color = GetPixel(3, 24); if (color != 0XE1315 && color != 0X101010) return false;
	color = GetPixel(3, 25); if (color != 0XE1315 && color != 0X101010) return false;
	color = GetPixel(3, 26); if (color != 0XE1315 && color != 0X101010) return false;
	color = GetPixel(3, 27); if (color != 0XE1315 && color != 0X121314) return false;
	color = GetPixel(3, 28); if (color != 0XE1315 && color != 0X101011) return false;
	color = GetPixel(3, 29); if (color != 0XE1315 && color != 0X101116) return false;
	color = GetPixel(3, 30); if (color != 0XE1315 && color != 0X101116) return false;
	color = GetPixel(3, 31); if (color != 0XE1315 && color != 0X101116) return false;
	color = GetPixel(3, 32); if (color != 0XE1316 && color != 0X101216) return false;
	color = GetPixel(3, 33); if (color != 0XE1416 && color != 0X101316) return false;
	color = GetPixel(3, 34); if (color != 0XE1416 && color != 0X101316) return false;
	color = GetPixel(4, 3); if (color != 0X1B2326 && color != 0X1C2428) return false;
	color = GetPixel(4, 4); if (color != 0X181E20 && color != 0X1B2026) return false;
	color = GetPixel(4, 5); if (color != 0X1A2124 && color != 0X1B2026) return false;
	color = GetPixel(4, 6); if (color != 0X1B2026 && color != 0X1B2226) return false;
	color = GetPixel(4, 7); if (color != 0X191E25 && color != 0X191F21) return false;
	color = GetPixel(4, 8); if (color != 0X181E20 && color != 0X181E24) return false;
	color = GetPixel(4, 9); if (color != 0X191E21 && color != 0X191E25) return false;
	color = GetPixel(4, 10); if (color != 0X1B2226 && color != 0X1B2228) return false;
	color = GetPixel(4, 14); if (color != 0X181F24 && color != 0X182024) return false;
	color = GetPixel(4, 15); if (color != 0X181E23 && color != 0X182024) return false;
	color = GetPixel(4, 16); if (color != 0X181E23 && color != 0X182024) return false;
	color = GetPixel(4, 17); if (color != 0X181E23 && color != 0X182024) return false;
	color = GetPixel(4, 18); if (color != 0X181E24 && color != 0X182024) return false;
	color = GetPixel(4, 19); if (color != 0X181E24 && color != 0X182024) return false;
	color = GetPixel(4, 20); if (color != 0X181E24 && color != 0X182024) return false;
	color = GetPixel(4, 21); if (color != 0X181E23 && color != 0X182024) return false;
	color = GetPixel(4, 22); if (color != 0X181E20 && color != 0X182024) return false;
	color = GetPixel(4, 23); if (color != 0X181E20 && color != 0X182024) return false;
	color = GetPixel(4, 24); if (color != 0X181E20 && color != 0X182024) return false;
	color = GetPixel(4, 25); if (color != 0X181E20 && color != 0X182026) return false;
	color = GetPixel(4, 26); if (color != 0X181E20 && color != 0X182026) return false;
	color = GetPixel(4, 27); if (color != 0X182026 && color != 0X1B2226) return false;
	color = GetPixel(4, 28); if (color != 0X181E21 && color != 0X182026) return false;
	color = GetPixel(4, 29); if (color != 0X181E23 && color != 0X181E24) return false;
	color = GetPixel(4, 30); if (color != 0X181E23 && color != 0X181E24) return false;
	color = GetPixel(4, 31); if (color != 0X181E23 && color != 0X181E24) return false;
	color = GetPixel(4, 32); if (color != 0X181F23 && color != 0X182025) return false;
	color = GetPixel(4, 33); if (color != 0X182023 && color != 0X182126) return false;
	color = GetPixel(4, 34); if (color != 0X182023 && color != 0X182126) return false;
	color = GetPixel(5, 3); if (color != 0X212C31 && color != 0X232C32) return false;
	color = GetPixel(5, 4); if (color != 0X1F292E && color != 0X232930) return false;
	color = GetPixel(5, 5); if (color != 0X1D262A && color != 0X1F242B) return false;
	color = GetPixel(5, 6); if (color != 0X1D262A && color != 0X1F242B) return false;
	color = GetPixel(5, 7); if (color != 0X1D262A && color != 0X1E262C) return false;
	color = GetPixel(5, 8); if (color != 0X1D262A && color != 0X1D262C) return false;
	color = GetPixel(5, 9); if (color != 0X1D262A && color != 0X1D262C) return false;
	color = GetPixel(5, 10); if (color != 0X1D272B && color != 0X1D272C) return false;
	color = GetPixel(5, 14); if (color != 0X1D272C && color != 0X202A2F) return false;
	color = GetPixel(5, 15); if (color != 0X1D272C && color != 0X212C31) return false;
	color = GetPixel(5, 16); if (color != 0X1C252A && color != 0X1D272C) return false;
	color = GetPixel(5, 17); if (color != 0X1B2428 && color != 0X1D272C) return false;
	color = GetPixel(5, 18); if (color != 0X1D262C && color != 0X1D272C) return false;
	color = GetPixel(5, 19); if (color != 0X1D262C && color != 0X1D272C) return false;
	color = GetPixel(5, 20); if (color != 0X1D262C && color != 0X1D272C) return false;
	color = GetPixel(5, 21); if (color != 0X1D262B && color != 0X1D272C) return false;
	color = GetPixel(5, 22); if (color != 0X1D262A && color != 0X1D272C) return false;
	color = GetPixel(5, 23); if (color != 0X1D262A && color != 0X1D272C) return false;
	color = GetPixel(5, 24); if (color != 0X1D262A && color != 0X1D272C) return false;
	color = GetPixel(5, 25); if (color != 0X1C252C && color != 0X1D262A) return false;
	color = GetPixel(5, 26); if (color != 0X1B242B && color != 0X1D262A) return false;
	color = GetPixel(5, 27); if (color != 0X1B242B && color != 0X1D262A) return false;
	color = GetPixel(5, 28); if (color != 0X1C242C && color != 0X1D262A) return false;
	color = GetPixel(5, 29); if (color != 0X1B2428 && color != 0X1D242C) return false;
	color = GetPixel(5, 30); if (color != 0X1B2428 && color != 0X1D242C) return false;
	color = GetPixel(5, 31); if (color != 0X1B2428 && color != 0X1D242C) return false;
	color = GetPixel(5, 32); if (color != 0X1B2528 && color != 0X1C252B) return false;
	color = GetPixel(5, 33); if (color != 0X1B2528 && color != 0X1B262A) return false;
	color = GetPixel(5, 34); if (color != 0X1B2528 && color != 0X1B262A) return false;
	color = GetPixel(6, 0); if (color != 0X90A0A && color != 0XA0A0A) return false;
	color = GetPixel(6, 1); if (color != 0X212C31 && color != 0X252D2F) return false;
	color = GetPixel(6, 2); if (color != 0X21282A && color != 0X212C31) return false;
	color = GetPixel(6, 3); if (color != 0X232C32 && color != 0X242D30) return false;
	color = GetPixel(6, 4); if (color != 0X1D2529 && color != 0X20262D) return false;
	color = GetPixel(6, 5); if (color != 0X191F24 && color != 0X1B1F26) return false;
	color = GetPixel(6, 6); if (color != 0X191F24 && color != 0X1B1F26) return false;
	color = GetPixel(6, 7); if (color != 0X1B2228 && color != 0X1E252C) return false;
	color = GetPixel(6, 8); if (color != 0X1F272E && color != 0X1F292E) return false;
	color = GetPixel(6, 9); if (color != 0X1B2329 && color != 0X1F262D) return false;
	color = GetPixel(6, 10); if (color != 0X181F24 && color != 0X1B2329) return false;
	color = GetPixel(6, 11); if (color != 0X192025 && color != 0X1B2429) return false;
	color = GetPixel(6, 13); if (color != 0X1B2429 && color != 0X1F2A2F) return false;
	color = GetPixel(6, 14); if (color != 0X1B2429 && color != 0X20292D) return false;
	color = GetPixel(6, 15); if (color != 0X1B2429 && color != 0X21292B) return false;
	color = GetPixel(6, 16); if (color != 0X1B2429 && color != 0X1F2628) return false;
	color = GetPixel(6, 17); if (color != 0X1B2429 && color != 0X1F2527) return false;
	color = GetPixel(6, 18); if (color != 0X1B2429 && color != 0X1F272F) return false;
	color = GetPixel(6, 19); if (color != 0X1F272F && color != 0X1F292E) return false;
	color = GetPixel(6, 20); if (color != 0X1B2429 && color != 0X1F272F) return false;
	color = GetPixel(6, 21); if (color != 0X1B2429 && color != 0X1F252C) return false;
	color = GetPixel(6, 22); if (color != 0X1B2429 && color != 0X1F2428) return false;
	color = GetPixel(6, 23); if (color != 0X1B2429 && color != 0X1F2428) return false;
	color = GetPixel(6, 24); if (color != 0X1B2429 && color != 0X1F2428) return false;
	color = GetPixel(6, 25); if (color != 0X182026 && color != 0X1E2428) return false;
	color = GetPixel(6, 26); if (color != 0X181F26 && color != 0X1D2428) return false;
	color = GetPixel(6, 27); if (color != 0X181F26 && color != 0X1D2428) return false;
	color = GetPixel(6, 28); if (color != 0X182026 && color != 0X1D2428) return false;
	color = GetPixel(6, 29); if (color != 0X1A2327 && color != 0X1B2229) return false;
	color = GetPixel(6, 30); if (color != 0X1A2327 && color != 0X1B2229) return false;
	color = GetPixel(6, 31); if (color != 0X1A2327 && color != 0X1B2229) return false;
	color = GetPixel(6, 32); if (color != 0X192227 && color != 0X1B2427) return false;
	color = GetPixel(6, 33); if (color != 0X182226 && color != 0X1C2527) return false;
	color = GetPixel(6, 34); if (color != 0X182226 && color != 0X1C2527) return false;
	color = GetPixel(7, 1); if (color != 0X262E2F && color != 0X272E2F) return false;
	color = GetPixel(7, 2); if (color != 0X212727 && color != 0X212728) return false;
	color = GetPixel(7, 3); if (color != 0X283133 && color != 0X283134) return false;
	color = GetPixel(7, 4); if (color != 0X1C2428 && color != 0X1D2326) return false;
	color = GetPixel(7, 5); if (color != 0X11161A && color != 0X16181B) return false;
	color = GetPixel(7, 6); if (color != 0X11161A && color != 0X181C1F) return false;
	color = GetPixel(7, 7); if (color != 0X1E252D && color != 0X1F252D) return false;
	color = GetPixel(7, 8); if (color != 0X212831 && color != 0X212931) return false;
	color = GetPixel(7, 9); if (color != 0X202730 && color != 0X212831) return false;
	color = GetPixel(7, 10); if (color != 0X1F272F && color != 0X202830) return false;
	color = GetPixel(7, 11); if (color != 0X202A2F && color != 0X202B30) return false;
	color = GetPixel(7, 13); if (color != 0X202B30 && color != 0X212C31) return false;
	color = GetPixel(7, 14); if (color != 0X202930 && color != 0X212A2C) return false;
	color = GetPixel(7, 15); if (color != 0X202730 && color != 0X212829) return false;
	color = GetPixel(7, 16); if (color != 0X202730 && color != 0X212829) return false;
	color = GetPixel(7, 17); if (color != 0X202730 && color != 0X212829) return false;
	color = GetPixel(7, 18); if (color != 0X202730 && color != 0X212831) return false;
	color = GetPixel(7, 20); if (color != 0X202730 && color != 0X212831) return false;
	color = GetPixel(7, 21); if (color != 0X20262D && color != 0X21262E) return false;
	color = GetPixel(7, 22); if (color != 0X202429 && color != 0X212429) return false;
	color = GetPixel(7, 23); if (color != 0X202429 && color != 0X212429) return false;
	color = GetPixel(7, 24); if (color != 0X202429 && color != 0X212429) return false;
	color = GetPixel(7, 25); if (color != 0X1F2529 && color != 0X20252B) return false;
	color = GetPixel(7, 26); if (color != 0X1E2529 && color != 0X20252B) return false;
	color = GetPixel(7, 27); if (color != 0X1E2529 && color != 0X20252B) return false;
	color = GetPixel(7, 28); if (color != 0X1D2529 && color != 0X1E252B) return false;
	color = GetPixel(7, 29); if (color != 0X182429 && color != 0X1B2529) return false;
	color = GetPixel(7, 30); if (color != 0X182429 && color != 0X1B2529) return false;
	color = GetPixel(7, 31); if (color != 0X182429 && color != 0X1B2529) return false;
	color = GetPixel(7, 32); if (color != 0X1D2629 && color != 0X1D262D) return false;
	color = GetPixel(7, 33); if (color != 0X1E2629 && color != 0X20272F) return false;
	color = GetPixel(7, 34); if (color != 0X1E2629 && color != 0X20272F) return false;
	color = GetPixel(8, 4); if (color != 0X1C2224 && color != 0X1C2428) return false;
	color = GetPixel(8, 5); if (color != 0X101418 && color != 0X151719) return false;
	color = GetPixel(8, 6); if (color != 0X101418 && color != 0X121314) return false;
	color = GetPixel(8, 7); if (color != 0X4080B && color != 0X4080D) return false;
	color = GetPixel(8, 14); if (color != 0X50405 && color != 0X50406) return false;
	color = GetPixel(8, 15); if (color != 0X20202 && color != 0X20203) return false;
	color = GetPixel(8, 16); if (color != 0X20202 && color != 0X20203) return false;
	color = GetPixel(8, 17); if (color != 0X20202 && color != 0X20203) return false;
	color = GetPixel(8, 25); if (color != 0XA070B && color != 0XA0A0B) return false;
	color = GetPixel(8, 26); if (color != 0X9060A && color != 0X90A0A) return false;
	color = GetPixel(8, 27); if (color != 0X9060A && color != 0X90A0A) return false;
	color = GetPixel(8, 28); if (color != 0X8060A && color != 0X80809) return false;
	color = GetPixel(8, 29); if (color != 0X10202 && color != 0X1060A) return false;
	color = GetPixel(8, 30); if (color != 0X1060A && color != 0X40607) return false;
	color = GetPixel(8, 31); if (color != 0X80D11 && color != 0XD1315) return false;
	color = GetPixel(8, 33); if (color != 0XB0C0E && color != 0XC0D0E) return false;
	color = GetPixel(9, 2); if (color != 0X262D2D && color != 0X262D2E) return false;
	color = GetPixel(9, 3); if (color != 0X232A2C && color != 0X232A2D) return false;
	color = GetPixel(9, 4); if (color != 0X20272B && color != 0X21292E) return false;
	color = GetPixel(9, 5); if (color != 0X181B1E && color != 0X181E23) return false;
	color = GetPixel(9, 6); if (color != 0X181B1E && color != 0X181E23) return false;
	color = GetPixel(9, 7); if (color != 0X161D22 && color != 0X161D23) return false;
	color = GetPixel(9, 12); if (color != 0X101116 && color != 0X101217) return false;
	color = GetPixel(9, 14); if (color != 0XA0A0B && color != 0XA0A0D) return false;
	color = GetPixel(9, 15); if (color != 0XB0D0D && color != 0XB0D10) return false;
	color = GetPixel(9, 16); if (color != 0XB0D0D && color != 0XB0D10) return false;
	color = GetPixel(9, 17); if (color != 0XB0D0D && color != 0XB0D10) return false;
	color = GetPixel(9, 22); if (color != 0X101214 && color != 0X111214) return false;
	color = GetPixel(9, 23); if (color != 0X16181A && color != 0X16191B) return false;
	color = GetPixel(9, 24); if (color != 0XE0F10 && color != 0XE0F11) return false;
	color = GetPixel(9, 25); if (color != 0X80509 && color != 0X80809) return false;
	color = GetPixel(9, 26); if (color != 0X80408 && color != 0X80808) return false;
	color = GetPixel(9, 27); if (color != 0X80408 && color != 0X80808) return false;
	color = GetPixel(9, 28); if (color != 0X70408 && color != 0X70707) return false;
	color = GetPixel(9, 29); if (color != 0X4090D && color != 0X50809) return false;
	color = GetPixel(9, 30); if (color != 0XD1318 && color != 0X10191B) return false;
	color = GetPixel(9, 31); if (color != 0XD1318 && color != 0X10191B) return false;
	color = GetPixel(9, 32); if (color != 0XA0C0E && color != 0XB0E0F) return false;
	color = GetPixel(9, 34); if (color != 0X80808 && color != 0X80809) return false;
	color = GetPixel(10, 0); if (color != 0XA0A0A && color != 0XA0A0B) return false;
	color = GetPixel(10, 1); if (color != 0X292F39 && color != 0X293132) return false;
	color = GetPixel(10, 2); if (color != 0X292F39 && color != 0X293132) return false;
	color = GetPixel(10, 3); if (color != 0X293235 && color != 0X2C323D) return false;
	color = GetPixel(10, 4); if (color != 0X21282C && color != 0X242A31) return false;
	color = GetPixel(10, 5); if (color != 0X181B1E && color != 0X181C21) return false;
	color = GetPixel(10, 6); if (color != 0X181A1D && color != 0X181C21) return false;
	color = GetPixel(10, 7); if (color != 0X161D21 && color != 0X171C22) return false;
	color = GetPixel(10, 8); if (color != 0X10502 && color != 0X20509) return false;
	color = GetPixel(10, 9); if (color != 0XB0F10 && color != 0XB0F15) return false;
	color = GetPixel(10, 10); if (color != 0XA0F10 && color != 0XD1016) return false;
	color = GetPixel(10, 11); if (color != 0XC1314 && color != 0X111418) return false;
	color = GetPixel(10, 12); if (color != 0X15191D && color != 0X171D21) return false;
	color = GetPixel(10, 13); if (color != 0X111719 && color != 0X14181D) return false;
	color = GetPixel(10, 14); if (color != 0XE1013 && color != 0XE1313) return false;
	color = GetPixel(10, 15); if (color != 0XB0D0D && color != 0XC0F11) return false;
	color = GetPixel(10, 16); if (color != 0XA0B0B && color != 0XC0F11) return false;
	color = GetPixel(10, 17); if (color != 0XA0B0B && color != 0XC0F11) return false;
	color = GetPixel(10, 18); if (color != 0X90D11 && color != 0XB0E11) return false;
	color = GetPixel(10, 19); if (color != 0XA0E12 && color != 0XC0F12) return false;
	color = GetPixel(10, 20); if (color != 0XB1013 && color != 0XC0F12) return false;
	color = GetPixel(10, 21); if (color != 0XF1417 && color != 0X101315) return false;
	color = GetPixel(10, 22); if (color != 0X101418 && color != 0X15181A) return false;
	color = GetPixel(10, 23); if (color != 0XD1113 && color != 0XF1012) return false;
	color = GetPixel(10, 24); if (color != 0X90D0B && color != 0XB0B0D) return false;
	color = GetPixel(10, 25); if (color != 0X80908 && color != 0X8090A) return false;
	color = GetPixel(10, 26); if (color != 0X80808 && color != 0X80909) return false;
	color = GetPixel(10, 27); if (color != 0X80808 && color != 0X80909) return false;
	color = GetPixel(10, 28); if (color != 0XA0B0C && color != 0XB0D0E) return false;
	color = GetPixel(10, 29); if (color != 0XF1518 && color != 0X11191C) return false;
	color = GetPixel(10, 30); if (color != 0X10181A && color != 0X12191A) return false;
	color = GetPixel(10, 31); if (color != 0XB1113 && color != 0XD1215) return false;
	color = GetPixel(10, 32); if (color != 0X80C0C && color != 0X90A0B) return false;
	color = GetPixel(10, 33); if (color != 0XA0A0A && color != 0XA0D0A) return false;
	color = GetPixel(10, 34); if (color != 0XD100D && color != 0XF1114) return false;
	color = GetPixel(11, 1); if (color != 0X292F39 && color != 0X293539) return false;
	color = GetPixel(11, 2); if (color != 0X292F39 && color != 0X293539) return false;
	color = GetPixel(11, 3); if (color != 0X293539 && color != 0X2C323D) return false;
	color = GetPixel(11, 4); if (color != 0X232A2E && color != 0X262B33) return false;
	color = GetPixel(11, 5); if (color != 0X191D22 && color != 0X1A1C1C) return false;
	color = GetPixel(11, 6); if (color != 0X181818 && color != 0X181C21) return false;
	color = GetPixel(11, 7); if (color != 0X161D21 && color != 0X181B1F) return false;
	color = GetPixel(11, 8); if (color != 0X10502 && color != 0X90509) return false;
	color = GetPixel(11, 9); if (color != 0XB0F10 && color != 0XD0C10) return false;
	color = GetPixel(11, 10); if (color != 0XA0F10 && color != 0X101115) return false;
	color = GetPixel(11, 11); if (color != 0X81010 && color != 0X90D11) return false;
	color = GetPixel(11, 12); if (color != 0XE1416 && color != 0X101419) return false;
	color = GetPixel(11, 13); if (color != 0X15191E && color != 0X151A1E) return false;
	color = GetPixel(11, 14); if (color != 0X121517 && color != 0X121617) return false;
	color = GetPixel(11, 21); if (color != 0X101618 && color != 0X101718) return false;
	color = GetPixel(11, 22); if (color != 0XE1214 && color != 0XE1414) return false;
	color = GetPixel(11, 23); if (color != 0XA0E0C && color != 0XC0F0F) return false;
	color = GetPixel(11, 24); if (color != 0X90D09 && color != 0XB0D0D) return false;
	color = GetPixel(11, 25); if (color != 0X80C0F && color != 0XA0B0B) return false;
	color = GetPixel(11, 26); if (color != 0X80808 && color != 0X80C10) return false;
	color = GetPixel(11, 27); if (color != 0XB0F13 && color != 0XD0E0F) return false;
	color = GetPixel(11, 28); if (color != 0X13181C && color != 0X15171A) return false;
	color = GetPixel(11, 29); if (color != 0X141B1C && color != 0X161A1F) return false;
	color = GetPixel(11, 30); if (color != 0XE1216 && color != 0XE1316) return false;
	color = GetPixel(11, 32); if (color != 0XD1011 && color != 0XE1012) return false;
	color = GetPixel(11, 33); if (color != 0X131413 && color != 0X131416) return false;
	color = GetPixel(11, 34); if (color != 0X141514 && color != 0X141517) return false;
	color = GetPixel(12, 1); if (color != 0X292F39 && color != 0X293539) return false;
	color = GetPixel(12, 2); if (color != 0X292F39 && color != 0X293539) return false;
	color = GetPixel(12, 3); if (color != 0X293539 && color != 0X2B313B) return false;
	color = GetPixel(12, 4); if (color != 0X22292C && color != 0X262B33) return false;
	color = GetPixel(12, 5); if (color != 0X191A1B && color != 0X1A1E24) return false;
	color = GetPixel(12, 6); if (color != 0X181818 && color != 0X181C21) return false;
	color = GetPixel(12, 7); if (color != 0X16191D && color != 0X161D21) return false;
	color = GetPixel(12, 8); if (color != 0X10502 && color != 0X90509) return false;
	color = GetPixel(12, 9); if (color != 0XB0F10 && color != 0XD0C10) return false;
	color = GetPixel(12, 10); if (color != 0XA0F10 && color != 0XC0C10) return false;
	color = GetPixel(12, 11); if (color != 0X80C10 && color != 0X81010) return false;
	color = GetPixel(12, 12); if (color != 0XC1014 && color != 0XC1314) return false;
	color = GetPixel(12, 13); if (color != 0X15191E && color != 0X151A1E) return false;
	color = GetPixel(12, 23); if (color != 0XC0F0F && color != 0XC100F) return false;
	color = GetPixel(12, 24); if (color != 0XC0F0F && color != 0XC100F) return false;
	color = GetPixel(12, 25); if (color != 0X90D10 && color != 0XF1112) return false;
	color = GetPixel(12, 26); if (color != 0X80809 && color != 0X80C10) return false;
	color = GetPixel(12, 27); if (color != 0X171D1F && color != 0X1C1F23) return false;
	color = GetPixel(12, 28); if (color != 0X181E21 && color != 0X1F2327) return false;
	color = GetPixel(12, 29); if (color != 0X13171C && color != 0X131A1C) return false;
	color = GetPixel(12, 31); if (color != 0XD1115 && color != 0XD1215) return false;
	color = GetPixel(12, 32); if (color != 0X14171B && color != 0X151718) return false;
	color = GetPixel(12, 33); if (color != 0X171A1D && color != 0X181818) return false;
	color = GetPixel(12, 34); if (color != 0X16181B && color != 0X181818) return false;
	color = GetPixel(13, 0); if (color != 0XA080B && color != 0XA0A0B) return false;
	color = GetPixel(13, 1); if (color != 0X293139 && color != 0X293539) return false;
	color = GetPixel(13, 2); if (color != 0X293139 && color != 0X293539) return false;
	color = GetPixel(13, 3); if (color != 0X262D34 && color != 0X273135) return false;
	color = GetPixel(13, 4); if (color != 0X1C2126 && color != 0X1E2123) return false;
	color = GetPixel(13, 5); if (color != 0X181818 && color != 0X181C21) return false;
	color = GetPixel(13, 6); if (color != 0X181818 && color != 0X181C21) return false;
	color = GetPixel(13, 7); if (color != 0X141518 && color != 0X141A1E) return false;
	color = GetPixel(13, 8); if (color != 0X10502 && color != 0X90509) return false;
	color = GetPixel(13, 9); if (color != 0X90E0E && color != 0XD0C10) return false;
	color = GetPixel(13, 10); if (color != 0X90E0F && color != 0XD0C10) return false;
	color = GetPixel(13, 11); if (color != 0X80E10 && color != 0XA0E12) return false;
	color = GetPixel(13, 12); if (color != 0XC1014 && color != 0XC1214) return false;
	color = GetPixel(13, 13); if (color != 0X15191E && color != 0X151C1E) return false;
	color = GetPixel(13, 14); if (color != 0X111517 && color != 0X131618) return false;
	color = GetPixel(13, 15); if (color != 0X90A0A && color != 0XA0B0B) return false;
	color = GetPixel(13, 19); if (color != 0X80D10 && color != 0X90D10) return false;
	color = GetPixel(13, 20); if (color != 0XB0F13 && color != 0XC1013) return false;
	color = GetPixel(13, 21); if (color != 0XC1013 && color != 0XD1112) return false;
	color = GetPixel(13, 22); if (color != 0XE1414 && color != 0X101313) return false;
	color = GetPixel(13, 23); if (color != 0XF1515 && color != 0X101414) return false;
	color = GetPixel(13, 24); if (color != 0XD1414 && color != 0XE1213) return false;
	color = GetPixel(13, 25); if (color != 0X90D10 && color != 0XF1112) return false;
	color = GetPixel(13, 26); if (color != 0X101518 && color != 0X111517) return false;
	color = GetPixel(13, 27); if (color != 0X1E2327 && color != 0X202729) return false;
	color = GetPixel(13, 28); if (color != 0X161D1F && color != 0X1B2124) return false;
	color = GetPixel(13, 29); if (color != 0XD1115 && color != 0XD1214) return false;
	color = GetPixel(13, 30); if (color != 0XD1113 && color != 0XD1115) return false;
	color = GetPixel(13, 31); if (color != 0X11151A && color != 0X111617) return false;
	color = GetPixel(13, 32); if (color != 0X15191D && color != 0X171A1B) return false;
	color = GetPixel(13, 33); if (color != 0X171A1E && color != 0X181819) return false;
	color = GetPixel(13, 34); if (color != 0X151719 && color != 0X171718) return false;
	color = GetPixel(14, 0); if (color != 0XA070B && color != 0XA0A0B) return false;
	color = GetPixel(14, 2); if (color != 0X273136 && color != 0X273236) return false;
	color = GetPixel(14, 3); if (color != 0X1E252A && color != 0X1F262A) return false;
	color = GetPixel(14, 4); if (color != 0X181C21 && color != 0X191C20) return false;
	color = GetPixel(14, 5); if (color != 0X181A1E && color != 0X181C21) return false;
	color = GetPixel(14, 6); if (color != 0X181A1E && color != 0X181C21) return false;
	color = GetPixel(14, 7); if (color != 0X151A1E && color != 0X151C23) return false;
	color = GetPixel(14, 8); if (color != 0X10502 && color != 0X40305) return false;
	color = GetPixel(14, 9); if (color != 0X80D0D && color != 0XC0D10) return false;
	color = GetPixel(14, 10); if (color != 0X80D0E && color != 0XC0E11) return false;
	color = GetPixel(14, 11); if (color != 0XA0F13 && color != 0XC1014) return false;
	color = GetPixel(14, 12); if (color != 0XB0F13 && color != 0XB1013) return false;
	color = GetPixel(14, 13); if (color != 0X14191C && color != 0X141B1C) return false;
	color = GetPixel(14, 14); if (color != 0X141718 && color != 0X151818) return false;
	color = GetPixel(14, 15); if (color != 0XA0B0B && color != 0XB0B0B) return false;
	color = GetPixel(14, 18); if (color != 0XD1114 && color != 0XD1115) return false;
	color = GetPixel(14, 19); if (color != 0XE1215 && color != 0XF1417) return false;
	color = GetPixel(14, 20); if (color != 0X111619 && color != 0X151919) return false;
	color = GetPixel(14, 21); if (color != 0X121719 && color != 0X151918) return false;
	color = GetPixel(14, 22); if (color != 0X15191A && color != 0X161A17) return false;
	color = GetPixel(14, 23); if (color != 0X141816 && color != 0X15191A) return false;
	color = GetPixel(14, 24); if (color != 0XF1314 && color != 0X101416) return false;
	color = GetPixel(14, 25); if (color != 0XD0F11 && color != 0XF1010) return false;
	color = GetPixel(14, 26); if (color != 0X1D2629 && color != 0X1E272B) return false;
	color = GetPixel(14, 27); if (color != 0X1B2225 && color != 0X1D2426) return false;
	color = GetPixel(14, 28); if (color != 0X121415 && color != 0X121517) return false;
	color = GetPixel(14, 29); if (color != 0XA0E11 && color != 0XE1012) return false;
	color = GetPixel(14, 30); if (color != 0X121518 && color != 0X121615) return false;
	color = GetPixel(14, 31); if (color != 0X151917 && color != 0X15191D) return false;
	color = GetPixel(14, 32); if (color != 0X16191B && color != 0X17191A) return false;
	color = GetPixel(14, 33); if (color != 0X161719 && color != 0X161819) return false;
	color = GetPixel(14, 34); if (color != 0X121313 && color != 0X131314) return false;
	color = GetPixel(15, 0); if (color != 0XA070B && color != 0XA0A0B) return false;
	color = GetPixel(15, 3); if (color != 0X1F252A && color != 0X1F262A) return false;
	color = GetPixel(15, 7); if (color != 0X161E21 && color != 0X181F28) return false;
	color = GetPixel(15, 8); if (color != 0X10202 && color != 0X10502) return false;
	color = GetPixel(15, 9); if (color != 0X80D0D && color != 0XB0E10) return false;
	color = GetPixel(15, 10); if (color != 0X90E0F && color != 0XB0F11) return false;
	color = GetPixel(15, 18); if (color != 0X141A1C && color != 0X161A1A) return false;
	color = GetPixel(15, 19); if (color != 0X151B1D && color != 0X161A1A) return false;
	color = GetPixel(15, 20); if (color != 0X151B1D && color != 0X181C1B) return false;
	color = GetPixel(15, 21); if (color != 0X161B1C && color != 0X181C1A) return false;
	color = GetPixel(15, 22); if (color != 0X181A1B && color != 0X181C18) return false;
	color = GetPixel(15, 23); if (color != 0X151917 && color != 0X181A1B) return false;
	color = GetPixel(15, 24); if (color != 0XF1314 && color != 0X121417) return false;
	color = GetPixel(15, 25); if (color != 0XF1010 && color != 0X101011) return false;
	color = GetPixel(15, 28); if (color != 0XF1010 && color != 0X101011) return false;
	color = GetPixel(15, 29); if (color != 0XE1213 && color != 0X121315) return false;
	color = GetPixel(15, 30); if (color != 0X141618 && color != 0X141817) return false;
	color = GetPixel(15, 31); if (color != 0X16191C && color != 0X171B18) return false;
	color = GetPixel(15, 32); if (color != 0X16181A && color != 0X171818) return false;
	color = GetPixel(15, 33); if (color != 0X131314 && color != 0X131414) return false;
	color = GetPixel(15, 34); if (color != 0X1B1C20 && color != 0X1B1F20) return false;
	color = GetPixel(16, 0); if (color != 0XA070B && color != 0XA0A0B) return false;
	color = GetPixel(16, 7); if (color != 0X161E21 && color != 0X181F28) return false;
	color = GetPixel(16, 8); if (color != 0X10202 && color != 0X10502) return false;
	color = GetPixel(16, 9); if (color != 0X80D0D && color != 0XB0E10) return false;
	color = GetPixel(16, 10); if (color != 0X80D0E && color != 0XB0E10) return false;
	color = GetPixel(16, 18); if (color != 0X161C1E && color != 0X181C1B) return false;
	color = GetPixel(16, 19); if (color != 0X161C1E && color != 0X181C1B) return false;
	color = GetPixel(16, 20); if (color != 0X161C1E && color != 0X181C1B) return false;
	color = GetPixel(16, 21); if (color != 0X171B1D && color != 0X181C1A) return false;
	color = GetPixel(16, 22); if (color != 0X181A1B && color != 0X181C18) return false;
	color = GetPixel(16, 23); if (color != 0X141618 && color != 0X151917) return false;
	color = GetPixel(16, 24); if (color != 0XC0F13 && color != 0XC1012) return false;
	color = GetPixel(16, 29); if (color != 0X121616 && color != 0X141517) return false;
	color = GetPixel(16, 30); if (color != 0X151917 && color != 0X16191C) return false;
	color = GetPixel(16, 31); if (color != 0X161A17 && color != 0X171A1E) return false;
	color = GetPixel(16, 32); if (color != 0X121413 && color != 0X131415) return false;
	color = GetPixel(16, 33); if (color != 0X17191B && color != 0X171A1B) return false;
	color = GetPixel(16, 34); if (color != 0X202327 && color != 0X202627) return false;
	color = GetPixel(17, 0); if (color != 0XA0A0B && color != 0XA0E0B) return false;
	color = GetPixel(17, 1); if (color != 0X293039 && color != 0X293439) return false;
	color = GetPixel(17, 2); if (color != 0X293039 && color != 0X293439) return false;
	color = GetPixel(17, 3); if (color != 0X2F3840 && color != 0X2F3B43) return false;
	color = GetPixel(17, 4); if (color != 0X2E373C && color != 0X2E3741) return false;
	color = GetPixel(17, 5); if (color != 0X1C2126 && color != 0X1C2127) return false;
	color = GetPixel(17, 7); if (color != 0X161E21 && color != 0X181C21) return false;
	color = GetPixel(17, 9); if (color != 0X8090B && color != 0XB0E10) return false;
	color = GetPixel(17, 10); if (color != 0X80A0C && color != 0XA0E10) return false;
	color = GetPixel(17, 14); if (color != 0XF1213 && color != 0XF1314) return false;
	color = GetPixel(17, 15); if (color != 0XA0A0A && color != 0XA0A0B) return false;
	color = GetPixel(17, 16); if (color != 0XD0E0F && color != 0X111111) return false;
	color = GetPixel(17, 17); if (color != 0X171B20 && color != 0X181818) return false;
	color = GetPixel(17, 18); if (color != 0X161C1E && color != 0X181B1B) return false;
	color = GetPixel(17, 19); if (color != 0X161C1E && color != 0X181B1B) return false;
	color = GetPixel(17, 20); if (color != 0X161C1E && color != 0X181B1B) return false;
	color = GetPixel(17, 21); if (color != 0X171B1D && color != 0X181B1D) return false;
	color = GetPixel(17, 22); if (color != 0X161A1C && color != 0X181A1B) return false;
	color = GetPixel(17, 23); if (color != 0X131518 && color != 0X131718) return false;
	color = GetPixel(17, 24); if (color != 0XA0E12 && color != 0XB0F0D) return false;
	color = GetPixel(17, 25); if (color != 0X131619 && color != 0X15181A) return false;
	color = GetPixel(17, 26); if (color != 0X1B2326 && color != 0X202429) return false;
	color = GetPixel(17, 27); if (color != 0X101010 && color != 0X101113) return false;
	color = GetPixel(17, 28); if (color != 0X111112 && color != 0X111213) return false;
	color = GetPixel(17, 29); if (color != 0X161616 && color != 0X16181B) return false;
	color = GetPixel(17, 30); if (color != 0X16181B && color != 0X181818) return false;
	color = GetPixel(17, 31); if (color != 0X151619 && color != 0X171717) return false;
	color = GetPixel(17, 32); if (color != 0X151617 && color != 0X161717) return false;
	color = GetPixel(18, 0); if (color != 0X90A0A && color != 0XA0E0B) return false;
	color = GetPixel(18, 1); if (color != 0X232F34 && color != 0X272E36) return false;
	color = GetPixel(18, 2); if (color != 0X21282D && color != 0X232F34) return false;
	color = GetPixel(18, 3); if (color != 0X283239 && color != 0X2F373F) return false;
	color = GetPixel(18, 4); if (color != 0X262D34 && color != 0X283035) return false;
	color = GetPixel(18, 5); if (color != 0X141C1D && color != 0X181C21) return false;
	color = GetPixel(18, 6); if (color != 0X101818 && color != 0X181C21) return false;
	color = GetPixel(18, 7); if (color != 0X171B1F && color != 0X181C21) return false;
	color = GetPixel(18, 25); if (color != 0X15181A && color != 0X151B1A) return false;
	color = GetPixel(18, 26); if (color != 0X181E1E && color != 0X202328) return false;
	color = GetPixel(18, 27); if (color != 0X80809 && color != 0X80909) return false;
	color = GetPixel(18, 28); if (color != 0X101213 && color != 0X111214) return false;
	color = GetPixel(18, 29); if (color != 0X141717 && color != 0X181818) return false;
	color = GetPixel(18, 30); if (color != 0X151819 && color != 0X181818) return false;
	color = GetPixel(18, 31); if (color != 0X131516 && color != 0X151515) return false;
	color = GetPixel(18, 32); if (color != 0X181E20 && color != 0X1B2020) return false;
	color = GetPixel(18, 33); if (color != 0X1B2326 && color != 0X1C2223) return false;
	color = GetPixel(18, 34); if (color != 0X121313 && color != 0X121314) return false;
	color = GetPixel(19, 0); if (color != 0X90A0A && color != 0XA0E0B) return false;
	color = GetPixel(19, 1); if (color != 0X232F34 && color != 0X272E36) return false;
	color = GetPixel(19, 2); if (color != 0X1F252A && color != 0X232F34) return false;
	color = GetPixel(19, 3); if (color != 0X252E32 && color != 0X283239) return false;
	color = GetPixel(19, 4); if (color != 0X232A2E && color != 0X262D34) return false;
	color = GetPixel(19, 5); if (color != 0X141C1D && color != 0X181C21) return false;
	color = GetPixel(19, 6); if (color != 0X101818 && color != 0X181C21) return false;
	color = GetPixel(19, 7); if (color != 0X171B1F && color != 0X181C21) return false;
	color = GetPixel(19, 20); if (color != 0X181D1E && color != 0X181F20) return false;
	color = GetPixel(19, 25); if (color != 0X171A1C && color != 0X171C1C) return false;
	color = GetPixel(19, 26); if (color != 0X181B1E && color != 0X181E1E) return false;
	color = GetPixel(19, 27); if (color != 0X80809 && color != 0X80909) return false;
	color = GetPixel(19, 28); if (color != 0X101213 && color != 0X111214) return false;
	color = GetPixel(19, 29); if (color != 0X131516 && color != 0X181718) return false;
	color = GetPixel(19, 30); if (color != 0X131516 && color != 0X171617) return false;
	color = GetPixel(19, 31); if (color != 0X121313 && color != 0X131313) return false;
	color = GetPixel(19, 32); if (color != 0X1B1F20 && color != 0X1B2124) return false;
	color = GetPixel(19, 33); if (color != 0X181B1C && color != 0X181D20) return false;
	color = GetPixel(20, 0); if (color != 0X90A0A && color != 0XA0D0B) return false;
	color = GetPixel(20, 1); if (color != 0X232F34 && color != 0X282F36) return false;
	color = GetPixel(20, 2); if (color != 0X232B2F && color != 0X232F34) return false;
	color = GetPixel(20, 3); if (color != 0X283239 && color != 0X2A3339) return false;
	color = GetPixel(20, 4); if (color != 0X232B2F && color != 0X262D34) return false;
	color = GetPixel(20, 5); if (color != 0X141C1D && color != 0X181C20) return false;
	color = GetPixel(20, 6); if (color != 0X101818 && color != 0X171A1E) return false;
	color = GetPixel(20, 7); if (color != 0X171B1E && color != 0X171B1F) return false;
	color = GetPixel(20, 8); if (color != 0X101317 && color != 0X111517) return false;
	color = GetPixel(20, 9); if (color != 0X111417 && color != 0X121519) return false;
	color = GetPixel(20, 10); if (color != 0X121619 && color != 0X121719) return false;
	color = GetPixel(20, 11); if (color != 0X121819 && color != 0X12191A) return false;
	color = GetPixel(20, 12); if (color != 0XD1215 && color != 0XE1314) return false;
	color = GetPixel(20, 13); if (color != 0X90D10 && color != 0X90D11) return false;
	color = GetPixel(20, 14); if (color != 0XA0C0E && color != 0XA0D0F) return false;
	color = GetPixel(20, 15); if (color != 0X111315 && color != 0X121315) return false;
	color = GetPixel(20, 16); if (color != 0X171A1D && color != 0X171B1F) return false;
	color = GetPixel(20, 17); if (color != 0X171A1F && color != 0X181B1E) return false;
	color = GetPixel(20, 18); if (color != 0X161A1A && color != 0X181A1A) return false;
	color = GetPixel(20, 19); if (color != 0X161C1C && color != 0X181C1C) return false;
	color = GetPixel(20, 20); if (color != 0X161C1C && color != 0X181C1C) return false;
	color = GetPixel(20, 21); if (color != 0X161B1D && color != 0X171B1D) return false;
	color = GetPixel(20, 22); if (color != 0X14181A && color != 0X14181B) return false;
	color = GetPixel(20, 23); if (color != 0XE1211 && color != 0XE1213) return false;
	color = GetPixel(20, 24); if (color != 0X90D0A && color != 0X90D0C) return false;
	color = GetPixel(20, 25); if (color != 0X1D2124 && color != 0X1D2323) return false;
	color = GetPixel(20, 26); if (color != 0X181C1F && color != 0X181F1F) return false;
	color = GetPixel(20, 27); if (color != 0X80809 && color != 0X80909) return false;
	color = GetPixel(20, 28); if (color != 0X101213 && color != 0X111213) return false;
	color = GetPixel(20, 29); if (color != 0X131516 && color != 0X141416) return false;
	color = GetPixel(20, 31); if (color != 0X131617 && color != 0X141617) return false;
	color = GetPixel(20, 32); if (color != 0X1B2022 && color != 0X1B2326) return false;
	color = GetPixel(20, 33); if (color != 0X131616 && color != 0X141718) return false;
	color = GetPixel(20, 34); if (color != 0XF1010 && color != 0X101010) return false;
	color = GetPixel(21, 1); if (color != 0X253034 && color != 0X293234) return false;
	color = GetPixel(21, 2); if (color != 0X253034 && color != 0X293234) return false;
	color = GetPixel(21, 3); if (color != 0X293336 && color != 0X293338) return false;
	color = GetPixel(21, 4); if (color != 0X212A2E && color != 0X232A2F) return false;
	color = GetPixel(21, 5); if (color != 0X141A1B && color != 0X161A1C) return false;
	color = GetPixel(21, 6); if (color != 0X111718 && color != 0X131618) return false;
	color = GetPixel(21, 7); if (color != 0X131818 && color != 0X141A1D) return false;
	color = GetPixel(21, 8); if (color != 0XF1315 && color != 0X111515) return false;
	color = GetPixel(21, 9); if (color != 0XF1212 && color != 0X121417) return false;
	color = GetPixel(21, 10); if (color != 0X111416 && color != 0X111616) return false;
	color = GetPixel(21, 11); if (color != 0XC1010 && color != 0XD1212) return false;
	color = GetPixel(21, 12); if (color != 0X90D10 && color != 0XB0F0E) return false;
	color = GetPixel(21, 13); if (color != 0XC1014 && color != 0XD1112) return false;
	color = GetPixel(21, 14); if (color != 0X111517 && color != 0X121416) return false;
	color = GetPixel(21, 15); if (color != 0X131618 && color != 0X171718) return false;
	color = GetPixel(21, 16); if (color != 0X15191D && color != 0X181818) return false;
	color = GetPixel(21, 17); if (color != 0X131618 && color != 0X161617) return false;
	color = GetPixel(21, 18); if (color != 0X101616 && color != 0X151515) return false;
	color = GetPixel(21, 19); if (color != 0X101616 && color != 0X151515) return false;
	color = GetPixel(21, 20); if (color != 0X101616 && color != 0X151616) return false;
	color = GetPixel(21, 21); if (color != 0X101617 && color != 0X141617) return false;
	color = GetPixel(21, 22); if (color != 0XE1212 && color != 0XE1316) return false;
	color = GetPixel(21, 23); if (color != 0XA0E0D && color != 0XA0E12) return false;
	color = GetPixel(21, 24); if (color != 0X80C10 && color != 0X90D0B) return false;
	color = GetPixel(21, 25); if (color != 0X1D2325 && color != 0X1D2327) return false;
	color = GetPixel(21, 26); if (color != 0X181C1E && color != 0X181F1F) return false;
	color = GetPixel(21, 27); if (color != 0X80909 && color != 0XB0B0B) return false;
	color = GetPixel(21, 28); if (color != 0X101212 && color != 0X101213) return false;
	color = GetPixel(21, 29); if (color != 0X101316 && color != 0X121316) return false;
	color = GetPixel(21, 30); if (color != 0X101316 && color != 0X111215) return false;
	color = GetPixel(21, 31); if (color != 0X161B1D && color != 0X161C1F) return false;
	color = GetPixel(21, 32); if (color != 0X192224 && color != 0X1A2225) return false;
	color = GetPixel(21, 33); if (color != 0XF1212 && color != 0X101313) return false;
	color = GetPixel(21, 34); if (color != 0XD0F0F && color != 0XE100F) return false;
	color = GetPixel(22, 7); if (color != 0X101818 && color != 0X131818) return false;
	color = GetPixel(22, 8); if (color != 0XC1010 && color != 0XD1010) return false;
	color = GetPixel(22, 14); if (color != 0X121518 && color != 0X131517) return false;
	color = GetPixel(22, 15); if (color != 0X131618 && color != 0X151617) return false;
	color = GetPixel(22, 16); if (color != 0X101315 && color != 0X131416) return false;
	color = GetPixel(22, 17); if (color != 0X101214 && color != 0X101215) return false;
	color = GetPixel(22, 18); if (color != 0X101010 && color != 0X101111) return false;
	color = GetPixel(22, 19); if (color != 0X101010 && color != 0X101111) return false;
	color = GetPixel(22, 20); if (color != 0X101212 && color != 0X111111) return false;
	color = GetPixel(22, 21); if (color != 0XE1314 && color != 0X101213) return false;
	color = GetPixel(22, 22); if (color != 0XA0E12 && color != 0XB0E10) return false;
	color = GetPixel(22, 23); if (color != 0X80C10 && color != 0XB0E10) return false;
	color = GetPixel(22, 24); if (color != 0XE1316 && color != 0XF1416) return false;
	color = GetPixel(22, 25); if (color != 0X1E2526 && color != 0X1E252D) return false;
	color = GetPixel(22, 26); if (color != 0X17191C && color != 0X181F1F) return false;
	color = GetPixel(22, 27); if (color != 0XC0D0E && color != 0X101010) return false;
	color = GetPixel(22, 28); if (color != 0X101011 && color != 0X101213) return false;
	color = GetPixel(22, 29); if (color != 0X101116 && color != 0X101316) return false;
	color = GetPixel(22, 30); if (color != 0X101116 && color != 0X101316) return false;
	color = GetPixel(22, 31); if (color != 0X181E23 && color != 0X182023) return false;
	color = GetPixel(22, 32); if (color != 0X1C2227 && color != 0X1C2527) return false;
	color = GetPixel(22, 33); if (color != 0XC0F0F && color != 0XC100F) return false;
	color = GetPixel(22, 34); if (color != 0XC0F0F && color != 0XC100F) return false;
	color = GetPixel(23, 7); if (color != 0X101818 && color != 0X131818) return false;
	color = GetPixel(23, 8); if (color != 0XA0C0C && color != 0XB0E0E) return false;
	color = GetPixel(23, 10); if (color != 0X90909 && color != 0XA0C0C) return false;
	color = GetPixel(23, 14); if (color != 0XF1114 && color != 0XF1214) return false;
	color = GetPixel(23, 15); if (color != 0XD1013 && color != 0XF1113) return false;
	color = GetPixel(23, 16); if (color != 0XA0E11 && color != 0XD0E10) return false;
	color = GetPixel(23, 17); if (color != 0XD0E10 && color != 0XD1013) return false;
	color = GetPixel(23, 19); if (color != 0X101314 && color != 0X141517) return false;
	color = GetPixel(23, 20); if (color != 0X101515 && color != 0X141517) return false;
	color = GetPixel(23, 21); if (color != 0X111718 && color != 0X131618) return false;
	color = GetPixel(23, 24); if (color != 0X1A2123 && color != 0X1A2226) return false;
	color = GetPixel(23, 25); if (color != 0X202728 && color != 0X202830) return false;
	color = GetPixel(23, 26); if (color != 0X181F1F && color != 0X191E23) return false;
	color = GetPixel(23, 27); if (color != 0X101010 && color != 0X101213) return false;
	color = GetPixel(23, 28); if (color != 0X101011 && color != 0X101213) return false;
	color = GetPixel(23, 29); if (color != 0X101116 && color != 0X101316) return false;
	color = GetPixel(23, 30); if (color != 0X101116 && color != 0X101316) return false;
	color = GetPixel(23, 31); if (color != 0X181E23 && color != 0X182023) return false;
	color = GetPixel(23, 32); if (color != 0X1C2227 && color != 0X1C2527) return false;
	color = GetPixel(23, 33); if (color != 0XC100F && color != 0XF1212) return false;
	color = GetPixel(23, 34); if (color != 0XC100F && color != 0XD1010) return false;
	color = GetPixel(24, 0); if (color != 0XA0A0A && color != 0XA0B0B) return false;
	color = GetPixel(24, 1); if (color != 0X293234 && color != 0X29363E) return false;
	color = GetPixel(24, 2); if (color != 0X27333A && color != 0X293234) return false;
	color = GetPixel(24, 3); if (color != 0X252F33 && color != 0X293336) return false;
	color = GetPixel(24, 4); if (color != 0X1E2528 && color != 0X1E2628) return false;
	color = GetPixel(24, 5); if (color != 0X111718 && color != 0X131618) return false;
	color = GetPixel(24, 6); if (color != 0X111718 && color != 0X131618) return false;
	color = GetPixel(24, 7); if (color != 0X101818 && color != 0X111818) return false;
	color = GetPixel(24, 8); if (color != 0XB0C0C && color != 0XB0E0E) return false;
	color = GetPixel(24, 10); if (color != 0XB0D0D && color != 0XB0E0E) return false;
	color = GetPixel(24, 11); if (color != 0XE1214 && color != 0XF1317) return false;
	color = GetPixel(24, 12); if (color != 0XF1317 && color != 0X101418) return false;
	color = GetPixel(24, 13); if (color != 0XD1111 && color != 0XD1114) return false;
	color = GetPixel(24, 14); if (color != 0X90D11 && color != 0XC0F0F) return false;
	color = GetPixel(24, 15); if (color != 0XD1114 && color != 0X101214) return false;
	color = GetPixel(24, 16); if (color != 0X13191B && color != 0X14171B) return false;
	color = GetPixel(24, 17); if (color != 0X15181C && color != 0X151B1D) return false;
	color = GetPixel(24, 18); if (color != 0X161E20 && color != 0X181C21) return false;
	color = GetPixel(24, 19); if (color != 0X1C262A && color != 0X1E242B) return false;
	color = GetPixel(24, 20); if (color != 0X1C262A && color != 0X1E242B) return false;
	color = GetPixel(24, 21); if (color != 0X1E252C && color != 0X1F272B) return false;
	color = GetPixel(24, 22); if (color != 0X1E282D && color != 0X24282D) return false;
	color = GetPixel(24, 23); if (color != 0X1E282D && color != 0X24282D) return false;
	color = GetPixel(24, 24); if (color != 0X202B30 && color != 0X262A2E) return false;
	color = GetPixel(24, 25); if (color != 0X212931 && color != 0X222B2F) return false;
	color = GetPixel(24, 26); if (color != 0X1B2027 && color != 0X1B2224) return false;
	color = GetPixel(24, 27); if (color != 0X141618 && color != 0X141719) return false;
	color = GetPixel(24, 28); if (color != 0X141518 && color != 0X141718) return false;
	color = GetPixel(24, 29); if (color != 0X101116 && color != 0X101416) return false;
	color = GetPixel(24, 30); if (color != 0XE1212 && color != 0X101116) return false;
	color = GetPixel(24, 31); if (color != 0X161B1E && color != 0X181E23) return false;
	color = GetPixel(24, 32); if (color != 0X1B2125 && color != 0X1C2227) return false;
	color = GetPixel(24, 33); if (color != 0XC100F && color != 0XF1212) return false;
	color = GetPixel(24, 34); if (color != 0XC0E0E && color != 0XC100F) return false;
	color = GetPixel(25, 1); if (color != 0X27363F && color != 0X2E383D) return false;
	color = GetPixel(25, 2); if (color != 0X1F2B30 && color != 0X242D2F) return false;
	color = GetPixel(25, 3); if (color != 0X232D32 && color != 0X273033) return false;
	color = GetPixel(25, 7); if (color != 0X101818 && color != 0X161818) return false;
	color = GetPixel(25, 8); if (color != 0XB0E0E && color != 0XD0E0E) return false;
	color = GetPixel(25, 10); if (color != 0XB0D0E && color != 0XC0D0E) return false;
	color = GetPixel(25, 13); if (color != 0XC1013 && color != 0XC1014) return false;
	color = GetPixel(25, 14); if (color != 0X13181B && color != 0X13191B) return false;
	color = GetPixel(25, 15); if (color != 0X1C2224 && color != 0X1C2324) return false;
	color = GetPixel(25, 17); if (color != 0X202628 && color != 0X202728) return false;
	color = GetPixel(25, 18); if (color != 0X172125 && color != 0X181F21) return false;
	color = GetPixel(25, 19); if (color != 0XC1115 && color != 0X101314) return false;
	color = GetPixel(25, 20); if (color != 0XC0D0F && color != 0XC1115) return false;
	color = GetPixel(25, 21); if (color != 0XC0D0F && color != 0XC1113) return false;
	color = GetPixel(25, 22); if (color != 0XC0E0F && color != 0XD110F) return false;
	color = GetPixel(25, 23); if (color != 0XD110F && color != 0XF1113) return false;
	color = GetPixel(25, 24); if (color != 0XD110F && color != 0X101315) return false;
	color = GetPixel(25, 25); if (color != 0X121414 && color != 0X121415) return false;
	color = GetPixel(25, 26); if (color != 0X121314 && color != 0X141618) return false;
	color = GetPixel(25, 27); if (color != 0X16181B && color != 0X16191B) return false;
	color = GetPixel(25, 28); if (color != 0X15171A && color != 0X15181A) return false;
	color = GetPixel(25, 29); if (color != 0X101416 && color != 0X101516) return false;
	color = GetPixel(25, 30); if (color != 0X101415 && color != 0X101416) return false;
	color = GetPixel(25, 31); if (color != 0X181E22 && color != 0X181E23) return false;
	color = GetPixel(25, 32); if (color != 0X1A2024 && color != 0X1C2127) return false;
	color = GetPixel(25, 33); if (color != 0XE1111 && color != 0XF1214) return false;
	color = GetPixel(25, 34); if (color != 0XB0D0D && color != 0XD0E10) return false;
	color = GetPixel(26, 0); if (color != 0XA0A0A && color != 0XA0B0B) return false;
	color = GetPixel(26, 1); if (color != 0X242D2F && color != 0X27353F) return false;
	color = GetPixel(26, 2); if (color != 0X1E292E && color != 0X232C2E) return false;
	color = GetPixel(26, 3); if (color != 0X232D32 && color != 0X262F32) return false;
	color = GetPixel(26, 7); if (color != 0X101818 && color != 0X171818) return false;
	color = GetPixel(26, 8); if (color != 0XB0E0E && color != 0XE0E0E) return false;
	color = GetPixel(26, 12); if (color != 0XE1216 && color != 0XE1316) return false;
	color = GetPixel(26, 13); if (color != 0X1C1F24 && color != 0X1C2224) return false;
	color = GetPixel(26, 14); if (color != 0X202628 && color != 0X202728) return false;
	color = GetPixel(26, 18); if (color != 0X90A0A && color != 0X90D11) return false;
	color = GetPixel(26, 19); if (color != 0X90E12 && color != 0XD1010) return false;
	color = GetPixel(26, 20); if (color != 0XE1212 && color != 0X10151A) return false;
	color = GetPixel(26, 21); if (color != 0X111518 && color != 0X121617) return false;
	color = GetPixel(26, 22); if (color != 0X121515 && color != 0X121517) return false;
	color = GetPixel(26, 23); if (color != 0X121515 && color != 0X131517) return false;
	color = GetPixel(26, 24); if (color != 0X121515 && color != 0X131618) return false;
	color = GetPixel(26, 25); if (color != 0X131416 && color != 0X15181A) return false;
	color = GetPixel(26, 26); if (color != 0X16181A && color != 0X16191A) return false;
	color = GetPixel(26, 27); if (color != 0X16181B && color != 0X16191B) return false;
	color = GetPixel(26, 28); if (color != 0X15171A && color != 0X15181A) return false;
	color = GetPixel(26, 32); if (color != 0X191D22 && color != 0X1A2024) return false;
	color = GetPixel(26, 33); if (color != 0XE1111 && color != 0XF1012) return false;
	color = GetPixel(26, 34); if (color != 0XB0D0D && color != 0XD0E10) return false;
	color = GetPixel(27, 1); if (color != 0X1E292E && color != 0X232C2E) return false;
	color = GetPixel(27, 2); if (color != 0X1E292E && color != 0X232C2E) return false;
	color = GetPixel(27, 3); if (color != 0X232D32 && color != 0X262F32) return false;
	color = GetPixel(27, 4); if (color != 0X1E2628 && color != 0X1E2629) return false;
	color = GetPixel(27, 7); if (color != 0X101818 && color != 0X171818) return false;
	color = GetPixel(27, 8); if (color != 0XB0E0E && color != 0XE0E0E) return false;
	color = GetPixel(27, 9); if (color != 0X70808 && color != 0X80808) return false;
	color = GetPixel(27, 11); if (color != 0XD1216 && color != 0X101318) return false;
	color = GetPixel(27, 12); if (color != 0X1C2324 && color != 0X212429) return false;
	color = GetPixel(27, 13); if (color != 0X202728 && color != 0X212428) return false;
	color = GetPixel(27, 14); if (color != 0X1A2123 && color != 0X1B2023) return false;
	color = GetPixel(27, 15); if (color != 0XD1114 && color != 0XD1115) return false;
	color = GetPixel(27, 16); if (color != 0X80D10 && color != 0X90C10) return false;
	color = GetPixel(27, 18); if (color != 0X10161B && color != 0X131818) return false;
	color = GetPixel(27, 19); if (color != 0X10161B && color != 0X131818) return false;
	color = GetPixel(27, 20); if (color != 0X10161B && color != 0X131818) return false;
	color = GetPixel(27, 21); if (color != 0X111619 && color != 0X131718) return false;
	color = GetPixel(27, 22); if (color != 0X131616 && color != 0X131618) return false;
	color = GetPixel(27, 23); if (color != 0X131616 && color != 0X131618) return false;
	color = GetPixel(27, 24); if (color != 0X131616 && color != 0X131618) return false;
	color = GetPixel(27, 25); if (color != 0X15171A && color != 0X15181A) return false;
	color = GetPixel(27, 26); if (color != 0X16181B && color != 0X16191B) return false;
	color = GetPixel(27, 27); if (color != 0X16181B && color != 0X16191B) return false;
	color = GetPixel(27, 28); if (color != 0X15171A && color != 0X15181A) return false;
	color = GetPixel(27, 29); if (color != 0X101416 && color != 0X101516) return false;
	color = GetPixel(27, 32); if (color != 0X1A2024 && color != 0X1B2027) return false;
	color = GetPixel(27, 33); if (color != 0XC0E0F && color != 0XE1111) return false;
	color = GetPixel(27, 34); if (color != 0XB0D0D && color != 0XC0D0F) return false;
	color = GetPixel(28, 1); if (color != 0X212C31 && color != 0X232C2F) return false;
	color = GetPixel(28, 2); if (color != 0X212C31 && color != 0X232C2F) return false;
	color = GetPixel(28, 3); if (color != 0X232E33 && color != 0X262F33) return false;
	color = GetPixel(28, 4); if (color != 0X1C2429 && color != 0X1E2628) return false;
	color = GetPixel(28, 5); if (color != 0X101818 && color != 0X13171B) return false;
	color = GetPixel(28, 6); if (color != 0X101818 && color != 0X13171B) return false;
	color = GetPixel(28, 7); if (color != 0X171919 && color != 0X171B20) return false;
	color = GetPixel(28, 8); if (color != 0X90D11 && color != 0XD0D0D) return false;
	color = GetPixel(28, 9); if (color != 0X408 && color != 0X70707) return false;
	color = GetPixel(28, 10); if (color != 0X60A0E && color != 0XB0D0D) return false;
	color = GetPixel(28, 11); if (color != 0X1C2224 && color != 0X1D2024) return false;
	color = GetPixel(28, 12); if (color != 0X1D2325 && color != 0X202327) return false;
	color = GetPixel(28, 13); if (color != 0X13181A && color != 0X1A1B1E) return false;
	color = GetPixel(28, 14); if (color != 0XC1013 && color != 0X121213) return false;
	color = GetPixel(28, 15); if (color != 0XF1316 && color != 0X111212) return false;
	color = GetPixel(28, 16); if (color != 0X111618 && color != 0X131516) return false;
	color = GetPixel(28, 17); if (color != 0X111618 && color != 0X161B1B) return false;
	color = GetPixel(28, 18); if (color != 0X131819 && color != 0X161B1B) return false;
	color = GetPixel(28, 19); if (color != 0X131819 && color != 0X161B1B) return false;
	color = GetPixel(28, 20); if (color != 0X121718 && color != 0X151A1A) return false;
	color = GetPixel(28, 21); if (color != 0X121618 && color != 0X131819) return false;
	color = GetPixel(28, 22); if (color != 0X101418 && color != 0X121517) return false;
	color = GetPixel(28, 23); if (color != 0X101418 && color != 0X121517) return false;
	color = GetPixel(28, 24); if (color != 0X101418 && color != 0X121517) return false;
	color = GetPixel(28, 25); if (color != 0X101418 && color != 0X121316) return false;
	color = GetPixel(28, 26); if (color != 0X101418 && color != 0X121316) return false;
	color = GetPixel(28, 27); if (color != 0X101418 && color != 0X121316) return false;
	color = GetPixel(28, 28); if (color != 0XF1317 && color != 0X111316) return false;
	color = GetPixel(28, 29); if (color != 0X80C10 && color != 0XD1110) return false;
	color = GetPixel(28, 30); if (color != 0X80B08 && color != 0X80C10) return false;
	color = GetPixel(28, 31); if (color != 0X101516 && color != 0X13181B) return false;
	color = GetPixel(28, 32); if (color != 0X191E22 && color != 0X1A2223) return false;
	color = GetPixel(28, 33); if (color != 0XD1010 && color != 0XE0F10) return false;
	color = GetPixel(28, 34); if (color != 0XC0F0F && color != 0XD0D0F) return false;
	color = GetPixel(29, 4); if (color != 0X1B2527 && color != 0X1C2429) return false;
	color = GetPixel(29, 5); if (color != 0X101818 && color != 0X13171B) return false;
	color = GetPixel(29, 6); if (color != 0X101818 && color != 0X13171B) return false;
	color = GetPixel(29, 7); if (color != 0X171B1F && color != 0X171B20) return false;
	color = GetPixel(29, 8); if (color != 0X90D0C && color != 0X90D11) return false;
	color = GetPixel(29, 9); if (color != 0X10501 && color != 0X10509) return false;
	color = GetPixel(29, 10); if (color != 0X101415 && color != 0X101418) return false;
	color = GetPixel(29, 15); if (color != 0X151A1A && color != 0X16191B) return false;
	color = GetPixel(29, 16); if (color != 0X161B1B && color != 0X171A1D) return false;
	color = GetPixel(29, 17); if (color != 0X16191B && color != 0X161B1B) return false;
	color = GetPixel(29, 18); if (color != 0X161A1E && color != 0X161B1B) return false;
	color = GetPixel(29, 19); if (color != 0X14181C && color != 0X151919) return false;
	color = GetPixel(29, 20); if (color != 0X101418 && color != 0X131515) return false;
	color = GetPixel(29, 21); if (color != 0X101316 && color != 0X111416) return false;
	color = GetPixel(29, 22); if (color != 0X101418 && color != 0X111415) return false;
	color = GetPixel(29, 23); if (color != 0X11151A && color != 0X121516) return false;
	color = GetPixel(29, 24); if (color != 0X121516 && color != 0X12161B) return false;
	color = GetPixel(29, 25); if (color != 0XF1319 && color != 0X12161B) return false;
	color = GetPixel(29, 26); if (color != 0XE131A && color != 0X12161B) return false;
	color = GetPixel(29, 27); if (color != 0XE131A && color != 0X12161B) return false;
	color = GetPixel(29, 28); if (color != 0XE1218 && color != 0X11161A) return false;
	color = GetPixel(29, 29); if (color != 0XD0F10 && color != 0XD1215) return false;
	color = GetPixel(29, 30); if (color != 0XC0D0E && color != 0XC1114) return false;
	color = GetPixel(29, 31); if (color != 0X16191D && color != 0X161C1E) return false;
	color = GetPixel(29, 32); if (color != 0X1A2223 && color != 0X1C2024) return false;
	color = GetPixel(29, 33); if (color != 0X101415 && color != 0X131415) return false;
	color = GetPixel(29, 34); if (color != 0XD1010 && color != 0X101010) return false;
	color = GetPixel(30, 3); if (color != 0X222D31 && color != 0X232E33) return false;
	color = GetPixel(30, 4); if (color != 0X1A2325 && color != 0X1C2429) return false;
	color = GetPixel(30, 5); if (color != 0X101818 && color != 0X13171B) return false;
	color = GetPixel(30, 6); if (color != 0X101818 && color != 0X13171B) return false;
	color = GetPixel(30, 7); if (color != 0X171B1F && color != 0X171B20) return false;
	color = GetPixel(30, 8); if (color != 0X90D0C && color != 0X90D11) return false;
	color = GetPixel(30, 9); if (color != 0X70B0A && color != 0X70B0F) return false;
	color = GetPixel(30, 14); if (color != 0X171A1B && color != 0X171A1D) return false;
	color = GetPixel(30, 15); if (color != 0X161B1B && color != 0X181B20) return false;
	color = GetPixel(30, 16); if (color != 0X161B1B && color != 0X171B1F) return false;
	color = GetPixel(30, 17); if (color != 0X151819 && color != 0X151919) return false;
	color = GetPixel(30, 18); if (color != 0X13171B && color != 0X151819) return false;
	color = GetPixel(30, 19); if (color != 0X101418 && color != 0X131516) return false;
	color = GetPixel(30, 20); if (color != 0X13171B && color != 0X141718) return false;
	color = GetPixel(30, 21); if (color != 0X14181A && color != 0X151A1C) return false;
	color = GetPixel(30, 22); if (color != 0X151C20 && color != 0X191E1F) return false;
	color = GetPixel(30, 23); if (color != 0X192025 && color != 0X1C2222) return false;
	color = GetPixel(30, 24); if (color != 0X1A2227 && color != 0X1C2222) return false;
	color = GetPixel(30, 25); if (color != 0X1A2227 && color != 0X1B2127) return false;
	color = GetPixel(30, 26); if (color != 0X1A2128 && color != 0X1A2227) return false;
	color = GetPixel(30, 27); if (color != 0X1A2128 && color != 0X1A2227) return false;
	color = GetPixel(30, 28); if (color != 0X192024 && color != 0X1B2229) return false;
	color = GetPixel(30, 29); if (color != 0X1D2228 && color != 0X1D2425) return false;
	color = GetPixel(30, 30); if (color != 0X1E2329 && color != 0X1E2426) return false;
	color = GetPixel(30, 31); if (color != 0X22282F && color != 0X22292A) return false;
	color = GetPixel(30, 32); if (color != 0X1C2425 && color != 0X1F2328) return false;
	color = GetPixel(30, 33); if (color != 0X101415 && color != 0X141416) return false;
	color = GetPixel(30, 34); if (color != 0XD1010 && color != 0X101010) return false;
	color = GetPixel(31, 0); if (color != 0X90A0A && color != 0XA0A0A) return false;
	color = GetPixel(31, 1); if (color != 0X202B30 && color != 0X242D30) return false;
	color = GetPixel(31, 2); if (color != 0X1D272A && color != 0X20282A) return false;
	color = GetPixel(31, 3); if (color != 0X212C30 && color != 0X232C2F) return false;
	color = GetPixel(31, 4); if (color != 0X1C2529 && color != 0X1C2628) return false;
	color = GetPixel(31, 5); if (color != 0X101818 && color != 0X111719) return false;
	color = GetPixel(31, 6); if (color != 0X101818 && color != 0X111719) return false;
	color = GetPixel(31, 7); if (color != 0X171B1F && color != 0X171B20) return false;
	color = GetPixel(31, 8); if (color != 0XB0F11 && color != 0XD1111) return false;
	color = GetPixel(31, 9); if (color != 0X101416 && color != 0X111518) return false;
	color = GetPixel(31, 10); if (color != 0X101314 && color != 0X101315) return false;
	color = GetPixel(31, 11); if (color != 0X101111 && color != 0X111111) return false;
	color = GetPixel(31, 12); if (color != 0X131516 && color != 0X151617) return false;
	color = GetPixel(31, 13); if (color != 0X171A1C && color != 0X1A1C1F) return false;
	color = GetPixel(31, 14); if (color != 0X161A1B && color != 0X191D21) return false;
	color = GetPixel(31, 15); if (color != 0X141819 && color != 0X171B1F) return false;
	color = GetPixel(31, 16); if (color != 0X141819 && color != 0X151819) return false;
	color = GetPixel(31, 17); if (color != 0X131617 && color != 0X131716) return false;
	color = GetPixel(31, 18); if (color != 0X13171B && color != 0X161A1A) return false;
	color = GetPixel(31, 19); if (color != 0X191F21 && color != 0X1A1F20) return false;
	color = GetPixel(31, 20); if (color != 0X1C2223 && color != 0X1C2224) return false;
	color = GetPixel(31, 21); if (color != 0X1B2223 && color != 0X1D2425) return false;
	color = GetPixel(31, 22); if (color != 0X191E21 && color != 0X1A2021) return false;
	color = GetPixel(31, 23); if (color != 0X161A1A && color != 0X161C20) return false;
	color = GetPixel(31, 24); if (color != 0X11191D && color != 0X141818) return false;
	color = GetPixel(31, 25); if (color != 0X11161C && color != 0X12181B) return false;
	color = GetPixel(31, 26); if (color != 0X101618 && color != 0X10161C) return false;
	color = GetPixel(31, 27); if (color != 0X10161C && color != 0X13181A) return false;
	color = GetPixel(31, 28); if (color != 0X101417 && color != 0X11161C) return false;
	color = GetPixel(31, 29); if (color != 0X101618 && color != 0X14171A) return false;
	color = GetPixel(31, 30); if (color != 0X151B1D && color != 0X181C20) return false;
	color = GetPixel(31, 31); if (color != 0X191F1F && color != 0X1B1F24) return false;
	color = GetPixel(31, 32); if (color != 0X171D1E && color != 0X1C1F23) return false;
	color = GetPixel(31, 33); if (color != 0XF1315 && color != 0X131415) return false;
	color = GetPixel(31, 34); if (color != 0XD1011 && color != 0X101010) return false;
	color = GetPixel(32, 0); if (color != 0X90A0A && color != 0XA0A0A) return false;
	color = GetPixel(32, 1); if (color != 0X222C2F && color != 0X293031) return false;
	color = GetPixel(32, 2); if (color != 0X212B2E && color != 0X262C2D) return false;
	color = GetPixel(32, 3); if (color != 0X222A2C && color != 0X232D30) return false;
	color = GetPixel(32, 7); if (color != 0X14191B && color != 0X171B1F) return false;
	color = GetPixel(32, 8); if (color != 0X111515 && color != 0X121618) return false;
	color = GetPixel(32, 9); if (color != 0XE1012 && color != 0XF1312) return false;
	color = GetPixel(32, 10); if (color != 0X90B0A && color != 0X90D09) return false;
	color = GetPixel(32, 11); if (color != 0X111212 && color != 0X121213) return false;
	color = GetPixel(32, 12); if (color != 0X151A1A && color != 0X17191D) return false;
	color = GetPixel(32, 13); if (color != 0X161B1B && color != 0X191D21) return false;
	color = GetPixel(32, 14); if (color != 0X141819 && color != 0X171A1E) return false;
	color = GetPixel(32, 15); if (color != 0X131618 && color != 0X14171A) return false;
	color = GetPixel(32, 17); if (color != 0X191F22 && color != 0X192021) return false;
	color = GetPixel(32, 18); if (color != 0X1D2325 && color != 0X1D2425) return false;
	color = GetPixel(32, 21); if (color != 0XE1112 && color != 0X101313) return false;
	color = GetPixel(32, 22); if (color != 0XA0C0F && color != 0XD0E0E) return false;
	color = GetPixel(32, 23); if (color != 0X90B0E && color != 0XA0B0B) return false;
	color = GetPixel(32, 24); if (color != 0X6080C && color != 0XA0B0B) return false;
	color = GetPixel(32, 25); if (color != 0X60909 && color != 0X80909) return false;
	color = GetPixel(32, 26); if (color != 0X50908 && color != 0X70707) return false;
	color = GetPixel(32, 27); if (color != 0X50908 && color != 0X90909) return false;
	color = GetPixel(32, 28); if (color != 0X50908 && color != 0X80809) return false;
	color = GetPixel(32, 29); if (color != 0X3070A && color != 0X80808) return false;
	color = GetPixel(32, 30); if (color != 0X4080A && color != 0X80808) return false;
	color = GetPixel(32, 31); if (color != 0X90D0D && color != 0XC0C0D) return false;
	color = GetPixel(32, 32); if (color != 0XE1212 && color != 0X101213) return false;
	color = GetPixel(32, 33); if (color != 0XF1316 && color != 0X101315) return false;
	color = GetPixel(32, 34); if (color != 0XF1316 && color != 0X101215) return false;
	color = GetPixel(33, 0); if (color != 0X90A0A && color != 0XA0A0A) return false;
	color = GetPixel(33, 1); if (color != 0X232C2E && color != 0X293031) return false;
	color = GetPixel(33, 2); if (color != 0X232C2E && color != 0X282F30) return false;
	color = GetPixel(33, 3); if (color != 0X252F32 && color != 0X272F32) return false;
	color = GetPixel(33, 7); if (color != 0X161A1D && color != 0X171B1F) return false;
	color = GetPixel(33, 8); if (color != 0X131618 && color != 0X131718) return false;
	color = GetPixel(33, 9); if (color != 0X90D0A && color != 0XD0E10) return false;
	color = GetPixel(33, 10); if (color != 0XA0A0A && color != 0XA0D0A) return false;
	color = GetPixel(33, 11); if (color != 0X131416 && color != 0X131616) return false;
	color = GetPixel(33, 12); if (color != 0X161B1B && color != 0X171A1D) return false;
	color = GetPixel(33, 13); if (color != 0X161B1B && color != 0X171B1F) return false;
	color = GetPixel(33, 14); if (color != 0X14171A && color != 0X141819) return false;
	color = GetPixel(33, 21); if (color != 0X70809 && color != 0X90909) return false;
	color = GetPixel(33, 22); if (color != 0XA0C0F && color != 0XB0E0E) return false;
	color = GetPixel(33, 23); if (color != 0XC1111 && color != 0XE1011) return false;
	color = GetPixel(33, 24); if (color != 0XC1111 && color != 0XE1011) return false;
	color = GetPixel(33, 25); if (color != 0XC0F0D && color != 0XF0F0F) return false;
	color = GetPixel(33, 26); if (color != 0XC0F0C && color != 0XF0F0F) return false;
	color = GetPixel(33, 27); if (color != 0XC0F0C && color != 0XF0F0F) return false;
	color = GetPixel(33, 28); if (color != 0XC0E0C && color != 0XE0E0E) return false;
	color = GetPixel(33, 29); if (color != 0X90D0C && color != 0XC0C0C) return false;
	color = GetPixel(33, 30); if (color != 0X90D0C && color != 0XC0C0C) return false;
	color = GetPixel(33, 31); if (color != 0XA0E0D && color != 0XC0C0C) return false;
	color = GetPixel(33, 32); if (color != 0XC1011 && color != 0XD0F11) return false;
	color = GetPixel(34, 0); if (color != 0XA0A0A && color != 0XA0B0B) return false;
	color = GetPixel(34, 1); if (color != 0X293031 && color != 0X2D373C) return false;
	color = GetPixel(34, 2); if (color != 0X232C2E && color != 0X293031) return false;
	color = GetPixel(34, 3); if (color != 0X252F32 && color != 0X293234) return false;
	color = GetPixel(34, 8); if (color != 0XF1212 && color != 0X131618) return false;
	color = GetPixel(34, 9); if (color != 0X80C08 && color != 0X9090A) return false;
	color = GetPixel(34, 10); if (color != 0XA0E0A && color != 0XD0E10) return false;
	color = GetPixel(34, 11); if (color != 0X141517 && color != 0X141717) return false;
	color = GetPixel(34, 12); if (color != 0X16181B && color != 0X161B1B) return false;
	color = GetPixel(34, 13); if (color != 0X151819 && color != 0X16181B) return false;
	color = GetPixel(34, 14); if (color != 0X131618 && color != 0X141719) return false;
	color = GetPixel(34, 21); if (color != 0XE1111 && color != 0XF1011) return false;
	color = GetPixel(34, 22); if (color != 0XD1212 && color != 0XF1112) return false;
	color = GetPixel(34, 23); if (color != 0XD1313 && color != 0X101213) return false;
	color = GetPixel(34, 24); if (color != 0XD1313 && color != 0X101213) return false;
	color = GetPixel(34, 25); if (color != 0XD100E && color != 0X101010) return false;
	color = GetPixel(34, 26); if (color != 0XD100D && color != 0X101010) return false;
	color = GetPixel(34, 27); if (color != 0XD100D && color != 0X101010) return false;
	color = GetPixel(34, 28); if (color != 0XD0F0D && color != 0XF100F) return false;
	color = GetPixel(34, 29); if (color != 0XB0F0D && color != 0XD0D0D) return false;
	color = GetPixel(34, 30); if (color != 0XB0F0D && color != 0XD0D0D) return false;
	color = GetPixel(34, 31); if (color != 0XB0F0D && color != 0XD0D0D) return false;
	color = GetPixel(34, 32); if (color != 0XB0F0E && color != 0XC0E0E) return false;

	return true;
}



/************************************************************************/
/* Debug                                                                */
/************************************************************************/
#ifdef _DEBUG
bool				IsD3WindowActive(void);
void				Win32GDI::SaveScreen(const char* filePath /*= "D:\\Dump.bmp"*/)
{
	uint16_t BitsPerPixel = 24;
	uint32_t Width = rectDesktop.right - rectDesktop.left;
	uint32_t Height = rectDesktop.bottom - rectDesktop.top;
	BITMAPINFO Info;
	BITMAPFILEHEADER Header;
	memset(&Info, 0, sizeof(Info));
	memset(&Header, 0, sizeof(Header));
	Info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	Info.bmiHeader.biWidth = Width;
	Info.bmiHeader.biHeight = Height;
	Info.bmiHeader.biPlanes = 1;
	Info.bmiHeader.biBitCount = BitsPerPixel;
	Info.bmiHeader.biCompression = BI_RGB;
	Info.bmiHeader.biSizeImage = Width * Height * (BitsPerPixel > 24 ? 4 : 3);
	Header.bfType = 0x4D42;
	Header.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	char* memPixels = NULL;
	HDC MemDC = CreateCompatibleDC(hScreenMemDC);
	if (MemDC != NULL)
	{
		HBITMAP hSection = CreateDIBSection(hScreenMemDC, &Info, DIB_RGB_COLORS, (void**)&memPixels, 0, 0);
		if (hSection != NULL)
		{
			HGDIOBJ hgiObject = SelectObject(MemDC, hSection);
			if (hgiObject != NULL)
			{
				BitBlt(MemDC, 0, 0, Width, Height, hScreenMemDC, rectDesktop.left, rectDesktop.top, SRCCOPY);
				std::fstream hFile(filePath, std::ios::out | std::ios::binary);
				if (hFile.is_open())
				{
					hFile.write((char*)&Header, sizeof(Header));
					hFile.write((char*)&Info.bmiHeader, sizeof(Info.bmiHeader));
					hFile.write(memPixels, (((BitsPerPixel * Width + 31) & ~31) / 8) * Height);
					hFile.close();
				}
				DeleteObject(hgiObject);
			}
			DeleteObject(hSection);
		}
		DeleteDC(MemDC);
	}
}
void				Win32GDI::SaveSubSreen(const char* filePath, int xleft, int ytop, int xright, int ybottom)
{
	uint16_t BitsPerPixel = 24;
	uint32_t Width = xright - xleft;
	uint32_t Height = ybottom - ytop;
	BITMAPINFO Info;
	BITMAPFILEHEADER Header;
	memset(&Info, 0, sizeof(Info));
	memset(&Header, 0, sizeof(Header));
	Info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	Info.bmiHeader.biWidth = Width;
	Info.bmiHeader.biHeight = Height;
	Info.bmiHeader.biPlanes = 1;
	Info.bmiHeader.biBitCount = BitsPerPixel;
	Info.bmiHeader.biCompression = BI_RGB;
	Info.bmiHeader.biSizeImage = Width * Height * (BitsPerPixel > 24 ? 4 : 3);
	Header.bfType = 0x4D42;
	Header.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	char* memPixels = NULL;
	HDC MemDC = CreateCompatibleDC(hScreenMemDC);
	if (MemDC != NULL)
	{
		HBITMAP hSection = CreateDIBSection(hScreenMemDC, &Info, DIB_RGB_COLORS, (void**)&memPixels, 0, 0);
		if (hSection != NULL)
		{
			HGDIOBJ hgiObject = SelectObject(MemDC, hSection);
			if (hgiObject != NULL)
			{
				BitBlt(MemDC, 0, 0, Width, Height, hScreenMemDC, xleft, ytop, SRCCOPY);
				std::fstream hFile(filePath, std::ios::out | std::ios::binary);
				if (hFile.is_open())
				{
					hFile.write((char*)&Header, sizeof(Header));
					hFile.write((char*)&Info.bmiHeader, sizeof(Info.bmiHeader));
					hFile.write(memPixels, (((BitsPerPixel * Width + 31) & ~31) / 8) * Height);
					hFile.close();
				}
				DeleteObject(hgiObject);
			}
			DeleteObject(hSection);
		}
		DeleteDC(MemDC);
	}
}
void				Win32GDI::DumpRectangle(int xleft, int ytop, int xright, int ybottom)
{
	const char* filePath = "D:\\DumpRectangle.txt";
	const char* logDumpFolder = "D:\\DumpImage\\";
	if (IsD3WindowActive())
	{
		static int					snap_count = 0;
		static std::set<int>		bitmap_data[1000][1000];

		snap_count++;
		CaptureDesktop();
		BlurRectangle(xleft, ytop, xright, ybottom);
		CreateDirectoryA(logDumpFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_04_%06d.bmp", logDumpFolder, snap_count);
		SaveSubSreen(bufferDumpFileName, xleft, ytop, xright, ybottom);


		//Copy data to set
		for (int ix = xleft; ix < xright; ix++)
		{
			for (int iy = ytop; iy < ybottom; iy++)
			{
				int color = ::GetPixel(hScreenMemDC, ix, iy);
				bitmap_data[ix - xleft][iy - ytop].insert(color);
			}
		}

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, filePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool D3_XXXXX_Is_YYYY(void)\n{\n");

			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = xleft; ix < xright; ix++)
				{
					for (int iy = ytop; iy < ybottom; iy++)
					{
						if (bitmap_data[ix - xleft][iy - ytop].size() > 1)
						{
							fprintf(logFile, "int color = 0;\n");
							/*soft break*/
							ix = xright;
							iy = ybottom;
							isize = 9;
						}
					}
				}
			}
			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = xleft; ix < xright; ix++)
				{
					for (int iy = ytop; iy < ybottom; iy++)
					{
						if (isize == 1 && bitmap_data[ix - xleft][iy - ytop].size() == 1)
						{
							fprintf(logFile, "if (GetPixel(%d, %d) != 0X%X) return false;\n", ix, iy, *(bitmap_data[ix - xleft][iy - ytop].begin()));
						}
						else if (isize == 2 && bitmap_data[ix - xleft][iy - ytop].size() == 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_data[ix - xleft][iy - ytop].begin()),
								*(std::next(bitmap_data[ix - xleft][iy - ytop].begin()))
							);
						}
						else if (bitmap_data[ix - xleft][iy - ytop].size() > 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (");
							for (auto icolor = bitmap_data[ix - xleft][iy - ytop].begin(); icolor != bitmap_data[ix - xleft][iy - ytop].end(); icolor++)
							{
								fprintf(logFile, "color != 0X%X", *icolor);
								if (std::next(icolor) != bitmap_data[ix - xleft][iy - ytop].end())
								{
									fprintf(logFile, " && ");
								}
							}
							fprintf(logFile, ") return false;\n");
						}
					}
				}
			}
			fprintf(logFile, "return true;\n}\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpSkill01(const char* filePath /*= "D:\\DumpSkill01.txt"*/, const char* logDumpFolder /*= "D:\\DumpImage\\"*/)
{
	const int				skill_01_x_left = 635;
	const int				skill_01_y_top = 1004;
	const int				skill_01_x_right = 681;
	const int				skill_01_y_bottom = 1029;
	static int				skill_01_snap_count = 0;
	static std::set<int>	bitmap_skill_01_data[skill_01_x_right - skill_01_x_left][skill_01_y_bottom - skill_01_y_top];
	if (IsD3WindowActive())
	{
		skill_01_snap_count++;
		CaptureDesktop();
		BlurRectangle(skill_01_x_left, skill_01_y_top, skill_01_x_right, skill_01_y_bottom);
		CreateDirectoryA(logDumpFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_01_%06d.bmp", logDumpFolder, skill_01_snap_count);
		SaveSubSreen(bufferDumpFileName, skill_01_x_left, skill_01_y_top, skill_01_x_right, skill_01_y_bottom);


		//Copy data to set
		for (int ix = skill_01_x_left; ix < skill_01_x_right; ix++)
		{
			for (int iy = skill_01_y_top; iy < skill_01_y_bottom; iy++)
			{
				int color = ::GetPixel(hScreenMemDC, ix, iy);
				bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].insert(color);
			}
		}

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, filePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool D3Skill01Is_XXXXX_AndReady(void)\n{\n");

			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = skill_01_x_left; ix < skill_01_x_right; ix++)
				{
					for (int iy = skill_01_y_top; iy < skill_01_y_bottom; iy++)
					{
						if (bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].size() > 1)
						{
							fprintf(logFile, "int color = 0;\n");
							/*soft break*/
							ix = skill_01_x_right;
							iy = skill_01_y_bottom;
							isize = 9;
						}
					}
				}
			}
			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = skill_01_x_left; ix < skill_01_x_right; ix++)
				{
					for (int iy = skill_01_y_top; iy < skill_01_y_bottom; iy++)
					{
						if (isize == 1 && bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].size() == 1)
						{
							fprintf(logFile, "if (GetPixel(%d, %d) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].size() == 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].begin()),
								*(std::next(bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].begin()))
							);
						}
						else if (bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].size() > 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (");
							for (auto icolor = bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].begin(); icolor != bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].end(); icolor++)
							{
								fprintf(logFile, "color != 0X%X", *icolor);
								if (std::next(icolor) != bitmap_skill_01_data[ix - skill_01_x_left][iy - skill_01_y_top].end())
								{
									fprintf(logFile, " && ");
								}
							}
							fprintf(logFile, ") return false;\n");
						}
					}
				}
			}
			fprintf(logFile, "return true;\n}\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpSkill02(const char* filePath /*= "D:\\DumpSkill02.txt"*/, const char* logDumpFolder /*= "D:\\DumpImage\\"*/)
{
	const int				skill_02_x_left = 702;
	const int				skill_02_y_top = 1004;
	const int				skill_02_x_right = 748;
	const int				skill_02_y_bottom = 1029;
	static int				skill_02_snap_count = 0;
	static std::set<int>	bitmap_skill_02_data[skill_02_x_right - skill_02_x_left][skill_02_y_bottom - skill_02_y_top];
	if (IsD3WindowActive())
	{
		skill_02_snap_count++;
		CaptureDesktop();
		BlurRectangle(skill_02_x_left, skill_02_y_top, skill_02_x_right, skill_02_y_bottom);
		CreateDirectoryA(logDumpFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_02_%06d.bmp", logDumpFolder, skill_02_snap_count);
		SaveSubSreen(bufferDumpFileName, skill_02_x_left, skill_02_y_top, skill_02_x_right, skill_02_y_bottom);


		//Copy data to set
		for (int ix = skill_02_x_left; ix < skill_02_x_right; ix++)
		{
			for (int iy = skill_02_y_top; iy < skill_02_y_bottom; iy++)
			{
				int color = ::GetPixel(hScreenMemDC, ix, iy);
				bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].insert(color);
			}
		}

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, filePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool D3Skill02Is_XXXXX_AndReady(void)\n{\n");

			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = skill_02_x_left; ix < skill_02_x_right; ix++)
				{
					for (int iy = skill_02_y_top; iy < skill_02_y_bottom; iy++)
					{
						if (bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].size() > 1)
						{
							fprintf(logFile, "int color = 0;\n");
							/*soft break*/
							ix = skill_02_x_right;
							iy = skill_02_y_bottom;
							isize = 9;
						}
					}
				}
			}
			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = skill_02_x_left; ix < skill_02_x_right; ix++)
				{
					for (int iy = skill_02_y_top; iy < skill_02_y_bottom; iy++)
					{
						if (isize == 1 && bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].size() == 1)
						{
							fprintf(logFile, "if (GetPixel(%d, %d) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].size() == 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].begin()),
								*(std::next(bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].begin()))
							);
						}
						else if (bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].size() > 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (");
							for (auto icolor = bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].begin(); icolor != bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].end(); icolor++)
							{
								fprintf(logFile, "color != 0X%X", *icolor);
								if (std::next(icolor) != bitmap_skill_02_data[ix - skill_02_x_left][iy - skill_02_y_top].end())
								{
									fprintf(logFile, " && ");
								}
							}
							fprintf(logFile, ") return false;\n");
						}
					}
				}
			}
			fprintf(logFile, "return true;\n}\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpSkill03(const char* filePath /*= "D:\\DumpSkill03.txt"*/, const char* logDumpFolder /*= "D:\\DumpImage\\"*/)
{
	const int				skill_03_x_left = 768;
	const int				skill_03_y_top = 1004;
	const int				skill_03_x_right = 814;
	const int				skill_03_y_bottom = 1029;
	static int				skill_03_snap_count = 0;
	static std::set<int>	bitmap_skill_03_data[skill_03_x_right - skill_03_x_left][skill_03_y_bottom - skill_03_y_top];
	if (IsD3WindowActive())
	{
		skill_03_snap_count++;
		CaptureDesktop();
		BlurRectangle(skill_03_x_left, skill_03_y_top, skill_03_x_right, skill_03_y_bottom);
		CreateDirectoryA(logDumpFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_03_%06d.bmp", logDumpFolder, skill_03_snap_count);
		SaveSubSreen(bufferDumpFileName, skill_03_x_left, skill_03_y_top, skill_03_x_right, skill_03_y_bottom);


		//Copy data to set
		for (int ix = skill_03_x_left; ix < skill_03_x_right; ix++)
		{
			for (int iy = skill_03_y_top; iy < skill_03_y_bottom; iy++)
			{
				int color = ::GetPixel(hScreenMemDC, ix, iy);
				bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].insert(color);
			}
		}

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, filePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool D3Skill03Is_XXXXX_AndReady(void)\n{\n");

			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = skill_03_x_left; ix < skill_03_x_right; ix++)
				{
					for (int iy = skill_03_y_top; iy < skill_03_y_bottom; iy++)
					{
						if (bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].size() > 1)
						{
							fprintf(logFile, "int color = 0;\n");
							/*soft break*/
							ix = skill_03_x_right;
							iy = skill_03_y_bottom;
							isize = 9;
						}
					}
				}
			}
			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = skill_03_x_left; ix < skill_03_x_right; ix++)
				{
					for (int iy = skill_03_y_top; iy < skill_03_y_bottom; iy++)
					{
						if (isize == 1 && bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].size() == 1)
						{
							fprintf(logFile, "if (GetPixel(%d, %d) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].size() == 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].begin()),
								*(std::next(bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].begin()))
							);
						}
						else if (bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].size() > 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (");
							for (auto icolor = bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].begin(); icolor != bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].end(); icolor++)
							{
								fprintf(logFile, "color != 0X%X", *icolor);
								if (std::next(icolor) != bitmap_skill_03_data[ix - skill_03_x_left][iy - skill_03_y_top].end())
								{
									fprintf(logFile, " && ");
								}
							}
							fprintf(logFile, ") return false;\n");
						}
					}
				}
			}
			fprintf(logFile, "return true;\n}\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpSkill04(const char* filePath /*= "D:\\DumpSkill04.txt"*/, const char* logDumpFolder /*= "D:\\DumpImage\\"*/)
{
	const int				skill_04_x_left = 834;
	const int				skill_04_y_top = 1003;
	const int				skill_04_x_right = 881;
	const int				skill_04_y_bottom = 1029;
	static int				skill_04_snap_count = 0;
	static std::set<int>	bitmap_skill_04_data[skill_04_x_right - skill_04_x_left][skill_04_y_bottom - skill_04_y_top];
	if (IsD3WindowActive())
	{
		skill_04_snap_count++;
		CaptureDesktop();
		BlurRectangle(skill_04_x_left, skill_04_y_top, skill_04_x_right, skill_04_y_bottom);
		CreateDirectoryA(logDumpFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_04_%06d.bmp", logDumpFolder, skill_04_snap_count);
		SaveSubSreen(bufferDumpFileName, skill_04_x_left, skill_04_y_top, skill_04_x_right, skill_04_y_bottom);


		//Copy data to set
		for (int ix = skill_04_x_left; ix < skill_04_x_right; ix++)
		{
			for (int iy = skill_04_y_top; iy < skill_04_y_bottom; iy++)
			{
				int color = ::GetPixel(hScreenMemDC, ix, iy);
				bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].insert(color);
			}
		}

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, filePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool D3Skill04Is_XXXXX_AndReady(void)\n{\n");

			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = skill_04_x_left; ix < skill_04_x_right; ix++)
				{
					for (int iy = skill_04_y_top; iy < skill_04_y_bottom; iy++)
					{
						if (bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].size() > 1)
						{
							fprintf(logFile, "int color = 0;\n");
							/*soft break*/
							ix = skill_04_x_right;
							iy = skill_04_y_bottom;
							isize = 9;
						}
					}
				}
			}
			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = skill_04_x_left; ix < skill_04_x_right; ix++)
				{
					for (int iy = skill_04_y_top; iy < skill_04_y_bottom; iy++)
					{
						if (isize == 1 && bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].size() == 1)
						{
							fprintf(logFile, "if (GetPixel(%d, %d) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].size() == 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].begin()),
								*(std::next(bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].begin()))
							);
						}
						else if (bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].size() > 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (");
							for (auto icolor = bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].begin(); icolor != bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].end(); icolor++)
							{
								fprintf(logFile, "color != 0X%X", *icolor);
								if (std::next(icolor) != bitmap_skill_04_data[ix - skill_04_x_left][iy - skill_04_y_top].end())
								{
									fprintf(logFile, " && ");
								}
							}
							fprintf(logFile, ") return false;\n");
						}
					}
				}
			}
			fprintf(logFile, "return true;\n}\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpRollItem01(const char* filePath, const char* logDumpFolder)
{

	static int				rol_01_snap_count = 0;
	static std::set<int>	bitmap_skill_01_data[rol_01_x_right - rol_01_x_left][rol_01_y_bottom - rol_01_y_top];
	if (IsD3WindowActive())
	{
		rol_01_snap_count++;
		CaptureDesktop();
		BlurRectangle(rol_01_x_left, rol_01_y_top, rol_01_x_right, rol_01_y_bottom);
		CreateDirectoryA(logDumpFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_01_%06d.bmp", logDumpFolder, rol_01_snap_count);
		SaveSubSreen(bufferDumpFileName, rol_01_x_left, rol_01_y_top, rol_01_x_right, rol_01_y_bottom);


		//Copy data to set
		for (int ix = rol_01_x_left; ix < rol_01_x_right; ix++)
		{
			for (int iy = rol_01_y_top; iy < rol_01_y_bottom; iy++)
			{
				int color = ::GetPixel(hScreenMemDC, ix, iy);
				bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].insert(color);
			}
		}

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, filePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::D3Rol01Is_XXXXX(void)\n{\n");

			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = rol_01_x_left; ix < rol_01_x_right; ix++)
				{
					for (int iy = rol_01_y_top; iy < rol_01_y_bottom; iy++)
					{
						if (bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].size() > 1)
						{
							fprintf(logFile, "int color = 0;\n");
							/*soft break*/
							ix = rol_01_x_right;
							iy = rol_01_y_bottom;
							isize = 9;
						}
					}
				}
			}
			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = rol_01_x_left; ix < rol_01_x_right; ix++)
				{
					for (int iy = rol_01_y_top; iy < rol_01_y_bottom; iy++)
					{
						if (isize == 1 && bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].size() == 1)
						{
							fprintf(logFile, "if (GetPixel(%d, %d) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].size() == 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()),
								*(std::next(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()))
							);
						}
						else if (bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].size() > 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (");
							for (auto icolor = bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin(); icolor != bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].end(); icolor++)
							{
								fprintf(logFile, "color != 0X%X", *icolor);
								if (std::next(icolor) != bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].end())
								{
									fprintf(logFile, " && ");
								}
							}
							fprintf(logFile, ") return false;\n");
						}
					}
				}
			}
			fprintf(logFile, "return true;\n}\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpRollItem02(const char* filePath, const char* logDumpFolder)
{

	// ô 2: 80 430 430 450

	static int				skill_02_snap_count = 0;
	static std::set<int>	bitmap_skill_02_data[rol_02_x_right - rol_02_x_left][rol_02_y_bottom - rol_02_y_top];
	if (IsD3WindowActive())
	{
		skill_02_snap_count++;
		CaptureDesktop();
		BlurRectangle(rol_02_x_left, rol_02_y_top, rol_02_x_right, rol_02_y_bottom);
		CreateDirectoryA(logDumpFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_02_%06d.bmp", logDumpFolder, skill_02_snap_count);
		SaveSubSreen(bufferDumpFileName, rol_02_x_left, rol_02_y_top, rol_02_x_right, rol_02_y_bottom);


		//Copy data to set
		for (int ix = rol_02_x_left; ix < rol_02_x_right; ix++)
		{
			for (int iy = rol_02_y_top; iy < rol_02_y_bottom; iy++)
			{
				int color = ::GetPixel(hScreenMemDC, ix, iy);
				bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].insert(color);
			}
		}

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, filePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::D3Rol01Is_XXXXX(void)\n{\n");

			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = rol_02_x_left; ix < rol_02_x_right; ix++)
				{
					for (int iy = rol_02_y_top; iy < rol_02_y_bottom; iy++)
					{
						if (bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() > 1)
						{
							fprintf(logFile, "int color = 0;\n");
							/*soft break*/
							ix = rol_02_x_right;
							iy = rol_02_y_bottom;
							isize = 9;
						}
					}
				}
			}
			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = rol_02_x_left; ix < rol_02_x_right; ix++)
				{
					for (int iy = rol_02_y_top; iy < rol_02_y_bottom; iy++)
					{
						if (isize == 1 && bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() == 1)
						{
							fprintf(logFile, "if (GetPixel(%d, %d) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() == 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()),
								*(std::next(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()))
							);
						}
						else if (bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() > 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (");
							for (auto icolor = bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin(); icolor != bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].end(); icolor++)
							{
								fprintf(logFile, "color != 0X%X", *icolor);
								if (std::next(icolor) != bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].end())
								{
									fprintf(logFile, " && ");
								}
							}
							fprintf(logFile, ") return false;\n");
						}
					}
				}
			}
			fprintf(logFile, "return true;\n}\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpRollItem03(const char* filePath, const char* logDumpFolder)
{

	// ô 3: 80 480 430 500


	static int				skill_03_snap_count = 0;
	static std::set<int>	bitmap_skill_03_data[rol_03_x_right - rol_03_x_left][rol_03_y_bottom - rol_03_y_top];
	if (IsD3WindowActive())
	{
		skill_03_snap_count++;
		CaptureDesktop();
		BlurRectangle(rol_03_x_left, rol_03_y_top, rol_03_x_right, rol_03_y_bottom);
		CreateDirectoryA(logDumpFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_03_%06d.bmp", logDumpFolder, skill_03_snap_count);
		SaveSubSreen(bufferDumpFileName, rol_03_x_left, rol_03_y_top, rol_03_x_right, rol_03_y_bottom);


		//Copy data to set
		for (int ix = rol_03_x_left; ix < rol_03_x_right; ix++)
		{
			for (int iy = rol_03_y_top; iy < rol_03_y_bottom; iy++)
			{
				int color = ::GetPixel(hScreenMemDC, ix, iy);
				bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].insert(color);
			}
		}

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, filePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::D3Rol01Is_XXXXX(void)\n{\n");

			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = rol_03_x_left; ix < rol_03_x_right; ix++)
				{
					for (int iy = rol_03_y_top; iy < rol_03_y_bottom; iy++)
					{
						if (bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].size() > 1)
						{
							fprintf(logFile, "int color = 0;\n");
							/*soft break*/
							ix = rol_03_x_right;
							iy = rol_03_y_bottom;
							isize = 9;
						}
					}
				}
			}
			for (int isize = 1; isize <= 3; isize++)
			{
				for (int ix = rol_03_x_left; ix < rol_03_x_right; ix++)
				{
					for (int iy = rol_03_y_top; iy < rol_03_y_bottom; iy++)
					{
						if (isize == 1 && bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].size() == 1)
						{
							fprintf(logFile, "if (GetPixel(%d, %d) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].size() == 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()),
								*(std::next(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()))
							);
						}
						else if (bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].size() > 2)
						{
							fprintf(logFile, "color = GetPixel(%d, %d);", ix, iy);
							fprintf(logFile, "if (");
							for (auto icolor = bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin(); icolor != bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].end(); icolor++)
							{
								fprintf(logFile, "color != 0X%X", *icolor);
								if (std::next(icolor) != bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].end())
								{
									fprintf(logFile, " && ");
								}
							}
							fprintf(logFile, ") return false;\n");
						}
					}
				}
			}
			fprintf(logFile, "return true;\n}\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}










#endif
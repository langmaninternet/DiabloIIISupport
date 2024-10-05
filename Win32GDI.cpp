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


const int				rol_01_x_left = 318;
const int				rol_01_y_top = 388/*Fixed*/;
const int				rol_01_x_right = 362;
const int				rol_01_y_bottom = 399/*Fixed*/;

//const int				rol_01_x_left = 196;
//const int				rol_01_y_top = 388/*Fixed*/;
//const int				rol_01_x_right = 226;
//const int				rol_01_y_bottom = 399/*Fixed*/;
const int				rol_02_x_left = 319;
const int				rol_02_y_top = 434/*Fixed*/;
const int				rol_02_x_right = 362;
const int				rol_02_y_bottom = 445/*Fixed*/;



const int				rol_03_x_left = 368;
const int				rol_03_y_top = 476/*Fixed*/;
const int				rol_03_x_right = 403;
const int				rol_03_y_bottom = 486/*Fixed*/;



const char* RollOption01FilePath = "D:\\DumpRollItem01.txt";
const char* RollOption02FilePath = "D:\\DumpRollItem02.txt";
const char* RollOption03FilePath = "D:\\DumpRollItem03.txt";
const char* logDumpImageFolder = "D:\\DumpImage\\";





extern Win32GDI w32gdi;



void		QuangBTDumpScreen(void)
{
	w32gdi.CaptureDesktop();
	w32gdi.SaveScreen();


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


	//w32gdi.DumpSkill02();
	//w32gdi.DumpSkill03();
	//w32gdi.DumpSkill04();

	//w32gdi.DumpRollOption01();
	//w32gdi.DumpRollOption01Ex();
	//w32gdi.DumpRollOption02();
	w32gdi.DumpRollOption02Ex();
	//w32gdi.DumpRollOption03();
	//w32gdi.DumpRollOption03Ex();

	//Roll item
	//w32gdi.DumpRectangle(238, 209, 291, 307);

	//w32gdi.DumpRectangleEx(171, 776, 282, 785);

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


void				Win32GDI::SaveSubSreenWithBlur(const char* filePath, int xleft, int ytop, int xright, int ybottom)
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
				for (int ix = xleft; ix < xright; ix++)
				{
					for (int iy = ytop; iy < ybottom; iy++)
					{
						int color = ::GetPixel(hScreenMemDC, ix, iy);
						color &= 0xE0E0E0;
						::SetPixel(hScreenMemDC, ix, iy, color);
					}
				}
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
			fprintf(logFile, "bool Win32GDI::D3_XXXXX_Is_YYYY(void)\n{\n");
			//fprintf(logFile, "DumpRectangle(%d,%d,%d,%d);\n", xleft, ytop, xright, ybottom);
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
							fprintf(logFile, "if ((GetPixel(%d, %d)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_data[ix - xleft][iy - ytop].begin()));
						}
						else if (isize == 2 && bitmap_data[ix - xleft][iy - ytop].size() == 2)
						{
							fprintf(logFile, "color = (GetPixel(%d, %d)&0xE0E0E0);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_data[ix - xleft][iy - ytop].begin()),
								*(std::next(bitmap_data[ix - xleft][iy - ytop].begin()))
							);
						}
						else if (bitmap_data[ix - xleft][iy - ytop].size() > 2)
						{
							fprintf(logFile, "color = (GetPixel(%d, %d)&0xE0E0E0);", ix, iy);
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
			fprintf(logFile, "return true;\n}\n\n\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}











void				Win32GDI::DumpRectangleEx(int xleft, int ytop, int xright, int ybottom)
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
			fprintf(logFile, "bool Win32GDI::D3_XXXXX_Is_YYYY(int offset)\n{\n");
			//fprintf(logFile, "DumpRectangle(%d,%d,%d,%d);\n", xleft, ytop, xright, ybottom);
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
							fprintf(logFile, "if ((GetPixel(%d+offset, %d)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_data[ix - xleft][iy - ytop].begin()));
						}
						else if (isize == 2 && bitmap_data[ix - xleft][iy - ytop].size() == 2)
						{
							fprintf(logFile, "color = (GetPixel(%d+offset, %d)&0xE0E0E0);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_data[ix - xleft][iy - ytop].begin()),
								*(std::next(bitmap_data[ix - xleft][iy - ytop].begin()))
							);
						}
						else if (bitmap_data[ix - xleft][iy - ytop].size() > 2)
						{
							fprintf(logFile, "color = (GetPixel(%d+offset, %d)&0xE0E0E0);", ix, iy);
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
			fprintf(logFile, "return true;\n}\n\n\n");
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
			fprintf(logFile, "BlurRectangle(%d,%d,%d,%d);\n", skill_01_x_left, skill_01_y_top, skill_01_x_right, skill_01_y_bottom);
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}





// 0XE0E0E0 == màu trắng
// 0XE0A080 == màu xám nhạt, chủ xuất hiện ở dòng 1
// 0XE06060 == màu xám, xuất hiện ở dòng 2, dòng 3



void				Win32GDI::DumpRollOption01(void)
{
	static int				skill_01_snap_count = 0;
	static std::set<int>	bitmap_skill_01_data[rol_01_x_right - rol_01_x_left][rol_01_y_bottom - rol_01_y_top];
	if (IsD3WindowActive())
	{
		skill_01_snap_count++;
		CaptureDesktop();
		BlurRectangle(rol_01_x_left, rol_01_y_top, rol_01_x_right, rol_01_y_bottom);
		CreateDirectoryA(logDumpImageFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_01_%06d.bmp", logDumpImageFolder, skill_01_snap_count);
		SaveSubSreenWithBlur(bufferDumpFileName, rol_01_x_left, rol_01_y_top, rol_01_x_right, rol_01_y_bottom);

		//Write to file
		FILE* logFile = NULL;
		fopen_s(&logFile, RollOption01FilePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::D3Rol01Is_XXXXX(void)\n{\n");
			fprintf(logFile, "//const int				rol_01_x_left = %d;\n", rol_01_x_left);
			fprintf(logFile, "//const int				rol_01_y_top = %d/*Fixed*/;\n", rol_01_y_top);
			fprintf(logFile, "//const int				rol_01_x_right = %d;\n", rol_01_x_right);
			fprintf(logFile, "//const int				rol_01_y_bottom = %d/*Fixed*/;\n", rol_01_y_bottom);

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
							fprintf(logFile, "if ((GetPixel(%d, %d)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].size() == 2)
						{
							fprintf(logFile, "color = (GetPixel(%d, %d)&0xE0E0E0);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()),
								*(std::next(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()))
							);
						}
						else if (bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].size() > 2)
						{
							fprintf(logFile, "color = (GetPixel(%d, %d)&0xE0E0E0);", ix, iy);
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpRollOption01Ex(void)
{
	static int				skill_01_snap_count = 0;
	static std::set<int>	bitmap_skill_01_data[rol_01_x_right - rol_01_x_left][rol_01_y_bottom - rol_01_y_top];
	if (IsD3WindowActive())
	{
		skill_01_snap_count++;
		CaptureDesktop();
		CreateDirectoryA(logDumpImageFolder, 0);
		BlurRectangle(rol_01_x_left, rol_01_y_top, rol_01_x_right, rol_01_y_bottom);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_01EX_%06d.bmp", logDumpImageFolder, skill_01_snap_count);
		SaveSubSreenWithBlur(bufferDumpFileName, rol_01_x_left, rol_01_y_top, rol_01_x_right, rol_01_y_bottom);


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
		fopen_s(&logFile, RollOption01FilePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::D3Rol01Is_XXXXX_Ex(int offset)\n{\n");
			fprintf(logFile, "//const int				rol_01_x_left = %d;\n", rol_01_x_left);
			fprintf(logFile, "//const int				rol_01_y_top = %d/*Fixed*/;\n", rol_01_y_top);
			fprintf(logFile, "//const int				rol_01_x_right = %d;\n", rol_01_x_right);
			fprintf(logFile, "//const int				rol_01_y_bottom = %d/*Fixed*/;\n", rol_01_y_bottom);


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
							fprintf(logFile, "if ((GetPixel(%d+offset, %d)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].size() == 2)
						{
							fprintf(logFile, "color = (GetPixel(%d+offset, %d)&0xE0E0E0);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()),
								*(std::next(bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].begin()))
							);
						}
						else if (bitmap_skill_01_data[ix - rol_01_x_left][iy - rol_01_y_top].size() > 2)
						{
							fprintf(logFile, "color = (GetPixel(%d+offset, %d)&0xE0E0E0);", ix, iy);
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpRollOption02(void)
{
	static int				skill_02_snap_count = 0;
	static std::set<int>	bitmap_skill_02_data[rol_02_x_right - rol_02_x_left][rol_02_y_bottom - rol_02_y_top];
	if (IsD3WindowActive())
	{
		skill_02_snap_count++;
		CaptureDesktop();
		BlurRectangle(rol_02_x_left, rol_02_y_top, rol_02_x_right, rol_02_y_bottom);
		CreateDirectoryA(logDumpImageFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_02_%06d.bmp", logDumpImageFolder, skill_02_snap_count);
		SaveSubSreenWithBlur(bufferDumpFileName, rol_02_x_left, rol_02_y_top, rol_02_x_right, rol_02_y_bottom);


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
		fopen_s(&logFile, RollOption02FilePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::D3Rol02Is_XXXXX(void)\n{\n");
			fprintf(logFile, "//const int				rol_02_x_left = %d;\n", rol_02_x_left);
			fprintf(logFile, "//const int				rol_02_y_top = %d/*Fixed*/;\n", rol_02_y_top);
			fprintf(logFile, "//const int				rol_02_x_right = %d;\n", rol_02_x_right);
			fprintf(logFile, "//const int				rol_02_y_bottom = %d/*Fixed*/;\n", rol_02_y_bottom);

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
							fprintf(logFile, "if ((GetPixel(%d, %d)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() == 2)
						{
							fprintf(logFile, "color = (GetPixel(%d, %d)&0xE0E0E0);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()),
								*(std::next(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()))
							);
						}
						else if (bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() > 2)
						{
							fprintf(logFile, "color = (GetPixel(%d, %d)&0xE0E0E0);", ix, iy);
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpRollOption02Ex(void)
{
	static int				skill_02_snap_count = 0;
	static std::set<int>	bitmap_skill_02_data[rol_02_x_right - rol_02_x_left][rol_02_y_bottom - rol_02_y_top];
	if (IsD3WindowActive())
	{
		skill_02_snap_count++;
		CaptureDesktop();
		CreateDirectoryA(logDumpImageFolder, 0);
		BlurRectangle(rol_02_x_left, rol_02_y_top, rol_02_x_right, rol_02_y_bottom);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_02EX_%06d.bmp", logDumpImageFolder, skill_02_snap_count);
		SaveSubSreenWithBlur(bufferDumpFileName, rol_02_x_left, rol_02_y_top, rol_02_x_right, rol_02_y_bottom);


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
		fopen_s(&logFile, RollOption02FilePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::RollingOption02Is_XXXXX_Ex(int xOffset)\n{\n");
			fprintf(logFile, "//const int				rol_02_x_left = %d;\n", rol_02_x_left);
			fprintf(logFile, "//const int				rol_02_y_top = %d/*Fixed*/;\n", rol_02_y_top);
			fprintf(logFile, "//const int				rol_02_x_right = %d;\n", rol_02_x_right);
			fprintf(logFile, "//const int				rol_02_y_bottom = %d/*Fixed*/;\n", rol_02_y_bottom);


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
							fprintf(logFile, "if ((GetPixel(%d+xOffset, %d)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() == 2)
						{
							fprintf(logFile, "color = (GetPixel(%d+xOffset, %d)&0xE0E0E0);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()),
								*(std::next(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()))
							);
						}
						else if (bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() > 2)
						{
							fprintf(logFile, "color = (GetPixel(%d+xOffset, %d)&0xE0E0E0);", ix, iy);
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
			fflush(logFile);
			fclose(logFile);







			//Write to file
			fopen_s(&logFile, RollOption03FilePath, "wb");
			if (logFile != NULL)
			{
				fprintf(logFile, "bool Win32GDI::RollingOption03Is_XXXXX_Ex(int xOffset)\n{\n");
				fprintf(logFile, "//const int				rol_02_clone_x_left = %d;\n", rol_02_x_left);
				fprintf(logFile, "//const int				rol_02_clone_y_top = %d/*Fixed*/;\n", rol_02_y_top);
				fprintf(logFile, "//const int				rol_02_clone_x_right = %d;\n", rol_02_x_right);
				fprintf(logFile, "//const int				rol_02_clone_y_bottom = %d/*Fixed*/;\n", rol_02_y_bottom);
				fprintf(logFile, "const int yOffset=44;\n");

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
								fprintf(logFile, "if ((GetPixel(%d+xOffset, %d+yOffset)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()));
							}
							else if (isize == 2 && bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() == 2)
							{
								fprintf(logFile, "color = (GetPixel(%d+xOffset, %d+yOffset)&0xE0E0E0);", ix, iy);
								fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
									*(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()),
									*(std::next(bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].begin()))
								);
							}
							else if (bitmap_skill_02_data[ix - rol_02_x_left][iy - rol_02_y_top].size() > 2)
							{
								fprintf(logFile, "color = (GetPixel(%d+xOffset, %d+yOffset)&0xE0E0E0);", ix, iy);
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
				fprintf(logFile, "return true;\n}\n\n\n\n");
				fflush(logFile);
				fclose(logFile);


			}

		}
	}
}
void				Win32GDI::DumpRollOption03(void)
{
	static int				skill_03_snap_count = 0;
	static std::set<int>	bitmap_skill_03_data[rol_03_x_right - rol_03_x_left][rol_03_y_bottom - rol_03_y_top];
	if (IsD3WindowActive())
	{
		skill_03_snap_count++;
		CaptureDesktop();
		BlurRectangle(rol_03_x_left, rol_03_y_top, rol_03_x_right, rol_03_y_bottom);
		CreateDirectoryA(logDumpImageFolder, 0);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_03_%06d.bmp", logDumpImageFolder, skill_03_snap_count);
		SaveSubSreenWithBlur(bufferDumpFileName, rol_03_x_left, rol_03_y_top, rol_03_x_right, rol_03_y_bottom);


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
		fopen_s(&logFile, RollOption03FilePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::D3Rol03Is_XXXXX(void)\n{\n");
			fprintf(logFile, "//const int				rol_03_x_left = %d;\n", rol_03_x_left);
			fprintf(logFile, "//const int				rol_03_y_top = %d/*Fixed*/;\n", rol_03_y_top);
			fprintf(logFile, "//const int				rol_03_x_right = %d;\n", rol_03_x_right);
			fprintf(logFile, "//const int				rol_03_y_bottom = %d/*Fixed*/;\n", rol_03_y_bottom);

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
							fprintf(logFile, "if ((GetPixel(%d, %d)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].size() == 2)
						{
							fprintf(logFile, "color = (GetPixel(%d, %d)&0xE0E0E0);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()),
								*(std::next(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()))
							);
						}
						else if (bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].size() > 2)
						{
							fprintf(logFile, "color = (GetPixel(%d, %d)&0xE0E0E0);", ix, iy);
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}
void				Win32GDI::DumpRollOption03Ex(void)
{
	static int				skill_03_snap_count = 0;
	static std::set<int>	bitmap_skill_03_data[rol_03_x_right - rol_03_x_left][rol_03_y_bottom - rol_03_y_top];
	if (IsD3WindowActive())
	{
		skill_03_snap_count++;
		CaptureDesktop();
		CreateDirectoryA(logDumpImageFolder, 0);
		BlurRectangle(rol_03_x_left, rol_03_y_top, rol_03_x_right, rol_03_y_bottom);

		char bufferDumpFileName[1000] = { 0 };
		sprintf_s(bufferDumpFileName, 999, "%s\\DS_03EX_%06d.bmp", logDumpImageFolder, skill_03_snap_count);
		SaveSubSreenWithBlur(bufferDumpFileName, rol_03_x_left, rol_03_y_top, rol_03_x_right, rol_03_y_bottom);


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
		fopen_s(&logFile, RollOption03FilePath, "wb");
		if (logFile != NULL)
		{
			fprintf(logFile, "bool Win32GDI::D3Rol03Is_XXXXX_Ex(int offset)\n{\n");
			fprintf(logFile, "//const int				rol_03_x_left = %d;\n", rol_03_x_left);
			fprintf(logFile, "//const int				rol_03_y_top = %d/*Fixed*/;\n", rol_03_y_top);
			fprintf(logFile, "//const int				rol_03_x_right = %d;\n", rol_03_x_right);
			fprintf(logFile, "//const int				rol_03_y_bottom = %d/*Fixed*/;\n", rol_03_y_bottom);


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
							fprintf(logFile, "if ((GetPixel(%d+offset, %d)&0xE0E0E0) != 0X%X) return false;\n", ix, iy, *(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()));
						}
						else if (isize == 2 && bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].size() == 2)
						{
							fprintf(logFile, "color = (GetPixel(%d+offset, %d)&0xE0E0E0);", ix, iy);
							fprintf(logFile, "if (color != 0X%X && color != 0X%X) return false;\n",
								*(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()),
								*(std::next(bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].begin()))
							);
						}
						else if (bitmap_skill_03_data[ix - rol_03_x_left][iy - rol_03_y_top].size() > 2)
						{
							fprintf(logFile, "color = (GetPixel(%d+offset, %d)&0xE0E0E0);", ix, iy);
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
			fprintf(logFile, "return true;\n}\n\n\n\n");
			fflush(logFile);
			fclose(logFile);
		}
	}
}



#endif
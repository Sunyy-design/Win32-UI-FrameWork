#pragma once
#define GDIPVER  0x0110	// 使用GDI+1.1版
#include<comdef.h>
#include<GdiPlus.h>

#pragma comment(lib,"gdiplus.lib")

#include"FGdiPlusItemType.h"

#ifndef FGDIPLUSITEMTYPE_H
using namespace Gdiplus;
#endif
/*
	创建日期：	2017-11-14
	创始人：	田巍
	产权所有：	西安兆元软件科技有限公司

	简介：
		本类封装GDI+，让使用更加贴合业务层。
*/

class FGDIPlus
{
private:
	// GDI+ ToKen
	ULONG_PTR	m_GdiPlusToKen;
	// GDI+ Input
	Gdiplus::GdiplusStartupInput
				m_GdiplusStartupInput;
public:
	// GDI+核心类
	Gdiplus::Graphics*	m_pGraphics;
public:
	FGDIPlus(void);
	~FGDIPlus(void);
public:
	// 初始化GDI Plus
	bool GdiplusStartup();
	// 销毁GDI Plus
	bool GdiplusShutdown();
	// 获得GDI Plus核心
	virtual Gdiplus::Graphics& GetGdiPlus(HDC hDC);
};


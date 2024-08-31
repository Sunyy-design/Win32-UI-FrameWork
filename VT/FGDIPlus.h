#pragma once
#define GDIPVER  0x0110	// ʹ��GDI+1.1��
#include<comdef.h>
#include<GdiPlus.h>

#pragma comment(lib,"gdiplus.lib")

#include"FGdiPlusItemType.h"

#ifndef FGDIPLUSITEMTYPE_H
using namespace Gdiplus;
#endif
/*
	�������ڣ�	2017-11-14
	��ʼ�ˣ�	��Ρ
	��Ȩ���У�	������Ԫ����Ƽ����޹�˾

	��飺
		�����װGDI+����ʹ�ø�������ҵ��㡣
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
	// GDI+������
	Gdiplus::Graphics*	m_pGraphics;
public:
	FGDIPlus(void);
	~FGDIPlus(void);
public:
	// ��ʼ��GDI Plus
	bool GdiplusStartup();
	// ����GDI Plus
	bool GdiplusShutdown();
	// ���GDI Plus����
	virtual Gdiplus::Graphics& GetGdiPlus(HDC hDC);
};


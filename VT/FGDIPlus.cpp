//#include "StdAfx.h"
#include "FGDIPlus.h"


FGDIPlus::FGDIPlus(void)
	:m_pGraphics(0)
	,m_GdiPlusToKen(0)
{
	GdiplusStartup();
}

FGDIPlus::~FGDIPlus(void)
{
	if(m_pGraphics)
	{
		delete m_pGraphics;
		m_pGraphics=0;
	}
	GdiplusShutdown();
}
// ��ʼ��GDI Plus
bool FGDIPlus::GdiplusStartup()
{
	if(!m_GdiPlusToKen)
		Gdiplus::GdiplusStartup(&m_GdiPlusToKen,&m_GdiplusStartupInput,NULL);
	else
		return false;
	if(m_GdiPlusToKen)
		return true;
	else
		return false;
}
// ����GDI Plus
bool FGDIPlus::GdiplusShutdown()
{
	if(!m_GdiPlusToKen)
		return false;
	else
	{
		Gdiplus::GdiplusShutdown(m_GdiPlusToKen);
		m_GdiPlusToKen=0;
		return true;
	}
}
// ���GDI Plus����
Gdiplus::Graphics& FGDIPlus::GetGdiPlus(HDC hDC)
{
	if(m_pGraphics)
	{
		delete m_pGraphics;
		m_pGraphics=0;
	}
	m_pGraphics=new Gdiplus::Graphics(hDC);

	return *m_pGraphics;
}
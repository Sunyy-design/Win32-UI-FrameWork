#pragma once

#include "Ecom.h"
#include "resource.h"


extern HINSTANCE g_hInstance;
extern FGDIPlus g_GDIP;
extern GameTimer g_Timer;

/*
* ϵͳ�������ڳ���ϵͳ��Ϣѭ��Ҳ��������������
*/
class VTwindow
{
public:
	VTwindow(HINSTANCE hInstance):m_hInstance(hInstance),m_hWnd(NULL)
	{
		// ��ȡϵͳ��ʾ�ֱ���
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);
	};

	~VTwindow(){};

	// ���������򴰿ڲ��� ȫ��������ɫ������ɫ
	BOOL Create(LPTSTR imgpath=NULL,BOOL fullscreen=TRUE,COLORREF bk=RGB(0,0,0) ,COLORREF fontc=RGB(255,255,255));
	void Run();

protected:
	HWND m_hWnd;
	LPTSTR img;
	HINSTANCE m_hInstance;
	INT x,y,width,height;
	COLORREF m_bk,m_fontcolor;

	// ϵͳ�ص�����������Ϊ��̬ȫ�ֵģ�ϵͳ�����ҵõ�
	static LRESULT CALLBACK	VTWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void VTLoop( float deltatime );
};
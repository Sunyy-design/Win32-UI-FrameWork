// VT.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "SystemFace.h"
#include "VT.h"


int APIENTRY _tWinMain(HINSTANCE hInstance,
					   HINSTANCE hPrevInstance,
					   LPTSTR    lpCmdLine,
					   int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	g_hInstance = hInstance;
	g_GDIP.GdiplusStartup();

	VTwindow system(hInstance);
	if( !system.Create(L"img\\五庄观.png",TRUE))
	{
		return -1;
	}
	system.Run();

	g_GDIP.GdiplusShutdown();

	return 0;
}

// 系统全局变量
HINSTANCE g_hInstance;
FGDIPlus g_GDIP;
GameTimer g_Timer;

// 在主系统创建的时候做的事情
void OnCreate(HWND hwnd)
{
	new FaceLogOn(hwnd);
	//new FaceTest(hwnd);
}

// 玩家ESC退出系统时
void OnESC( HINSTANCE hinstance , HWND hwnd )
{
	// 从窗口获取实例指针
	VTwindow* pthis = reinterpret_cast<VTwindow*>(GetWindowLongPtr(hwnd,GWLP_USERDATA));
	
	// 退出前销毁进程
	unitywnd *unity = (unitywnd *)GetVTObject(0x32FF5E);
	delete unity;
}

bool isUIMoving = false;
int UIstate = 1;

// 系统的空闲刷新函数，消息循环之外的，实时函数
void OnVTLoop( HINSTANCE hinstance , HWND hwnd ,float deltatime )
{
	// 从窗口获取实例指针
	VTwindow* pthis = reinterpret_cast<VTwindow*>(GetWindowLongPtr(hwnd,GWLP_USERDATA));


	// 轮询模式
	// 判断是否退出系统，放这里可以避免在各个弹出窗口都写判断
	if(KEY_DOWN(VK_ESCAPE))
	{
		if( IDOK == MessageBox(hwnd,L"您确认要退出系统?",L"消息",MB_OKCANCEL))
		{
			::OnESC(g_hInstance,hwnd);
			PostQuitMessage(0);
		}
	}

	// 界面动画部分，初步测试。
	if(!isUIMoving)
	{
		if(KEY_DOWN(VK_TAB))
		{
			isUIMoving = true;
		}
	}else{
		// 让一个指定窗口移动动画
		wnd *xds = (wnd*)GetVTObject(WND_XDS);
		wnd *kzq = (wnd*)GetVTObject(WND_KZQ);
		wnd *xxq = (wnd*)GetVTObject(WND_XXQ);

		if(UIstate)
		{
			if(xds&&kzq&&xxq)
			{
				if(!(xds->x<=-xds->w))
				{
					xds->x -= 600*deltatime;
					SetWindowPos(xds->GetSafeWnd(),NULL,xds->x,xds->y,xds->w,xds->h,SWP_SHOWWINDOW);
				}

				if(!(kzq->x>=GetSystemMetrics(SM_CXSCREEN)))
				{
					kzq->x += 900*deltatime;
					SetWindowPos(kzq->GetSafeWnd(),NULL,kzq->x,kzq->y,kzq->w,kzq->h,SWP_SHOWWINDOW);
				}

				if(!(xxq->y>=GetSystemMetrics(SM_CYSCREEN)))
				{
					xxq->y += 400*deltatime;
					SetWindowPos(xxq->GetSafeWnd(),NULL,xxq->x,xxq->y,xxq->w,xxq->h,SWP_SHOWWINDOW);
				}

				// 到位了就停止
				if(  (xds->x<=-xds->w) && (kzq->x>=GetSystemMetrics(SM_CXSCREEN)) && (xxq->y>=GetSystemMetrics(SM_CYSCREEN)) )
				{
					isUIMoving = false;
					xds->x = -xds->w;
					SetWindowPos(xds->GetSafeWnd(),NULL,xds->x,xds->y,xds->w,xds->h,SWP_SHOWWINDOW);
					kzq->x = GetSystemMetrics(SM_CXSCREEN);
					SetWindowPos(kzq->GetSafeWnd(),NULL,kzq->x,kzq->y,kzq->w,kzq->h,SWP_SHOWWINDOW);
					xxq->y = GetSystemMetrics(SM_CYSCREEN);
					SetWindowPos(xxq->GetSafeWnd(),NULL,xxq->x,xxq->y,xxq->w,xxq->h,SWP_SHOWWINDOW);

					UIstate = 0;
					isUIMoving = false;
				}
			}
		} 
		else
		{
			if(xds&&kzq&&xxq)
			{
				if(!(xds->x>=0))
				{
					xds->x += 600*deltatime;
					SetWindowPos(xds->GetSafeWnd(),NULL,xds->x,xds->y,xds->w,xds->h,SWP_SHOWWINDOW);
				}
				if(!(kzq->x<=GetSystemMetrics(SM_CXSCREEN)-kzq->w))
				{
					kzq->x -= 900*deltatime;
					SetWindowPos(kzq->GetSafeWnd(),NULL,kzq->x,kzq->y,kzq->w,kzq->h,SWP_SHOWWINDOW);
				}

				if(!(xxq->y<=GetSystemMetrics(SM_CYSCREEN)-xxq->h))
				{
					xxq->y -= 400*deltatime;
					SetWindowPos(xxq->GetSafeWnd(),NULL,xxq->x,xxq->y,xxq->w,xxq->h,SWP_SHOWWINDOW);
				}

				// 到位了就停止
				if( (xds->x>=0) && (kzq->x<=GetSystemMetrics(SM_CXSCREEN)-kzq->w) && (xxq->y<=GetSystemMetrics(SM_CYSCREEN)-xxq->h) )
				{
					isUIMoving = false;
					xds->x = 0;
					SetWindowPos(xds->GetSafeWnd(),NULL,xds->x,xds->y,xds->w,xds->h,SWP_SHOWWINDOW);
					kzq->x = GetSystemMetrics(SM_CXSCREEN)-kzq->w;
					SetWindowPos(kzq->GetSafeWnd(),NULL,kzq->x,kzq->y,kzq->w,kzq->h,SWP_SHOWWINDOW);
					xxq->y = GetSystemMetrics(SM_CYSCREEN)-xxq->h;
					SetWindowPos(xxq->GetSafeWnd(),NULL,xxq->x,xxq->y,xxq->w,xxq->h,SWP_SHOWWINDOW);
					UIstate = 1;
					isUIMoving = false;
				}
			}
		}
	}
	
}
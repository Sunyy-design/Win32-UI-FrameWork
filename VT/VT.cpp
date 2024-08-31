// VT.cpp : ����Ӧ�ó������ڵ㡣
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
	if( !system.Create(L"img\\��ׯ��.png",TRUE))
	{
		return -1;
	}
	system.Run();

	g_GDIP.GdiplusShutdown();

	return 0;
}

// ϵͳȫ�ֱ���
HINSTANCE g_hInstance;
FGDIPlus g_GDIP;
GameTimer g_Timer;

// ����ϵͳ������ʱ����������
void OnCreate(HWND hwnd)
{
	new FaceLogOn(hwnd);
	//new FaceTest(hwnd);
}

// ���ESC�˳�ϵͳʱ
void OnESC( HINSTANCE hinstance , HWND hwnd )
{
	// �Ӵ��ڻ�ȡʵ��ָ��
	VTwindow* pthis = reinterpret_cast<VTwindow*>(GetWindowLongPtr(hwnd,GWLP_USERDATA));
	
	// �˳�ǰ���ٽ���
	unitywnd *unity = (unitywnd *)GetVTObject(0x32FF5E);
	delete unity;
}

bool isUIMoving = false;
int UIstate = 1;

// ϵͳ�Ŀ���ˢ�º�������Ϣѭ��֮��ģ�ʵʱ����
void OnVTLoop( HINSTANCE hinstance , HWND hwnd ,float deltatime )
{
	// �Ӵ��ڻ�ȡʵ��ָ��
	VTwindow* pthis = reinterpret_cast<VTwindow*>(GetWindowLongPtr(hwnd,GWLP_USERDATA));


	// ��ѯģʽ
	// �ж��Ƿ��˳�ϵͳ����������Ա����ڸ����������ڶ�д�ж�
	if(KEY_DOWN(VK_ESCAPE))
	{
		if( IDOK == MessageBox(hwnd,L"��ȷ��Ҫ�˳�ϵͳ?",L"��Ϣ",MB_OKCANCEL))
		{
			::OnESC(g_hInstance,hwnd);
			PostQuitMessage(0);
		}
	}

	// ���涯�����֣��������ԡ�
	if(!isUIMoving)
	{
		if(KEY_DOWN(VK_TAB))
		{
			isUIMoving = true;
		}
	}else{
		// ��һ��ָ�������ƶ�����
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

				// ��λ�˾�ֹͣ
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

				// ��λ�˾�ֹͣ
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
#include "stdafx.h"
#include "VTwindow.h"

BOOL VTwindow::Create(LPTSTR imgpath,BOOL fullscreen,COLORREF bk,COLORREF fontc)
{
	img = imgpath;
	// ����ɫ
	m_bk = bk;
	// ������ɫ
	m_fontcolor = fontc;

	// ע��
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= VTWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= m_hInstance;
	wcex.hIcon			= LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_VT));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+3);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= _T("VTwindow");
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));	
	if( !RegisterClassEx(&wcex) )
	{
		// error ����ע�ᴰ��ʧ��
		return FALSE;
	}
	// Ĭ��ȫ��
	if(fullscreen)
	{
		m_hWnd = CreateWindow(_T("VTwindow"), _T("Virtual Traing System"), WS_POPUP|WS_VISIBLE,
			0, 0, width, height, NULL, NULL, m_hInstance, NULL);
	}else{
		m_hWnd = CreateWindow(_T("VTwindow"), _T("Virtual Traing System"), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, m_hInstance, NULL);
	}

	if (!m_hWnd)
	{
		// error �����ڴ���ʧ��
		return FALSE;
	}


	// �����ʵ��ָ���봰�ڹ��������ھ�̬�ص�����
	SetWindowLongPtr(m_hWnd,GWLP_USERDATA,reinterpret_cast<LONG_PTR>(this));

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	UnregisterClass(_T("VTwindow"), wcex.hInstance);

	return TRUE;
}

void VTwindow::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	g_Timer.reset();

	while(msg.message != WM_QUIT)
	{
		if(PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			g_Timer.tick();
			VTLoop(g_Timer.getDeltaTime());
		}
	}
}

// û����Ϣ���ͽ�����Ⱦ����
void VTwindow::VTLoop( float deltatime )
{
	// ���ڲ�ѭ������
	g_VTManager.OnLoop(deltatime);
	// ����������ѭ��
	::OnVTLoop(m_hInstance,m_hWnd,deltatime);
}

LRESULT CALLBACK VTwindow::VTWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// �Ӵ��ڻ�ȡʵ��ָ��
	VTwindow* pthis = reinterpret_cast<VTwindow*>(GetWindowLongPtr(hWnd,GWLP_USERDATA));

	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		::OnCreate(hWnd);
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);

			// ˫����
			HDC memDC = CreateCompatibleDC(hdc);
			HBITMAP hBitmap = CreateCompatibleBitmap(hdc,pthis->width,pthis->height);
			SelectObject(memDC,hBitmap);

			HBRUSH hTransparentBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
			RECT rect = {0,0,pthis->width,pthis->height};
			FillRect(memDC,&rect,hTransparentBrush);

			if(pthis->img)
			{
				Gdiplus::Graphics graphics(memDC);
				Gdiplus::Image image( pthis->img );
				graphics.DrawImage(&image,0,0,pthis->width,pthis->height);			
			}else{
				// ���Ʊ���
				HBRUSH hbrush = CreateSolidBrush(pthis->m_bk);
				FillRect(memDC,&ps.rcPaint,hbrush);
				DeleteObject(hbrush);
			}

			HFONT hFont = CreateFont(28,0,0,0,FW_MEDIUM,FALSE,FALSE,FALSE,
					ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
					DEFAULT_PITCH|FF_DONTCARE,_T("����"));
			HGDIOBJ hOldFont = SelectObject(memDC,hFont);
			SetBkMode(memDC,TRANSPARENT);
			SetTextColor(memDC,pthis->m_fontcolor);
			RECT rcText;
			GetClientRect(hWnd,&rcText);
			// DrawText(memDC,_T("����ѵ��ϵͳ"),-1,&rcText,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

			SelectObject(memDC,hOldFont);
			DeleteObject(hFont);

			BitBlt(hdc,0,0,pthis->width,pthis->height,memDC,0,0,SRCCOPY);
			DeleteObject(hBitmap);
			DeleteDC(memDC);

			EndPaint(hWnd, &ps);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
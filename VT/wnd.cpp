#include "stdafx.h"
#include "wnd.h"


wnd::wnd( INT i,HWND father ,LPTSTR imgpath,INT X,INT Y,INT W,INT H,BOOL drag,LPTSTR t,LPTSTR ts,INT fs,COLORREF bk, COLORREF fontc )
{
	id = i;
	AddSelfToManager();

	m_father = father;
	img = imgpath;
	if(img)
	{
		image = new Gdiplus::Image(img);
		w = image->GetWidth();
		h = image->GetHeight();
	} else {
		w=W;
		h=H;
	}

	x=X;
	y=Y;

	m_bkc = bk;
	m_fontc = fontc;
	text = t;
	text_style = ts;
	fontsize = fs;

	candrag = drag;
	isDragging = false;


	// 注册
	WNDCLASS wcex;
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= ChildWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= sizeof(long);
	wcex.hInstance		= g_hInstance;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)GetStockObject(NULL_BRUSH);
	wcex.lpszMenuName	= NULL;
	wcex.hIcon          = NULL;
	wcex.lpszClassName	= _T("wnd");

	// 这里可以重复注册，所以没有加if判断
	RegisterClass(&wcex);

	// 创建并显示
	m_wnd = CreateWindowEx(WS_EX_WINDOWEDGE,_T("wnd"),NULL,WS_VISIBLE|WS_POPUP,
		x, y, w, h,m_father, NULL,g_hInstance,NULL);


	if (!m_wnd)
	{
		// error 处理窗口创建失败
		MessageBox(NULL,L"创建窗体失败！",L"错误",MB_ICONERROR);
		return;
	}

	SetLayeredWindowAttributes(m_wnd,RGB(255,0,255),0,LWA_COLORKEY|LWA_ALPHA);

	// 将类的实例指针与窗口关联，用于静态回调函数
	SetWindowLongPtr(m_wnd,GWLP_USERDATA,reinterpret_cast<LONG_PTR>(this));

	ShowWindow(m_wnd, SW_SHOW);
	UpdateWindow(m_wnd);

	UnregisterClass(_T("wnd"), wcex.hInstance);
}

LRESULT CALLBACK wnd::ChildWndProc( HWND hwnd , UINT message , WPARAM wParam , LPARAM lParam )
{
	// 从窗口获取实例指针
	wnd* pthis = reinterpret_cast<wnd*>(GetWindowLongPtr(hwnd,GWLP_USERDATA));

	HDC hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_CREATE:
		break;
	case WM_ERASEBKGND:
		return 1;
	case WM_SIZE:		
		break;
	case WM_LBUTTONDOWN:
		if(pthis->candrag)
		{
			pthis->isDragging = true;
			pthis->startpos.x = LOWORD(lParam);
			pthis->startpos.y = HIWORD(lParam);
			SetCapture(hwnd);			
		}
		break;
	case WM_MOUSEMOVE:
		if(pthis->candrag)
		{
			if(pthis->isDragging)
			{
				int dx = LOWORD(lParam) - pthis->startpos.x;
				int dy = HIWORD(lParam) - pthis->startpos.y;
				pthis->x += dx;
				pthis->y += dy;

				SetWindowPos(hwnd,NULL,pthis->x,pthis->y,0,0,SWP_NOSIZE|SWP_NOZORDER);
			}
		}
		break;
	case WM_LBUTTONUP:
		{
			if(pthis->candrag)
			{
				int w = GetSystemMetrics(SM_CXSCREEN);
				int h = GetSystemMetrics(SM_CYSCREEN);
				pthis->isDragging = false;
				ReleaseCapture();

				if( (pthis->x < -pthis->w) || (pthis->x > w) || (pthis->y < -pthis->h) || (pthis->y > h) )
				{
					pthis->x = w/2-pthis->w/2;
					pthis->y = h/2-pthis->h/2;
					SetWindowPos(hwnd,NULL,pthis->x,pthis->y,0,0,SWP_NOSIZE|SWP_NOZORDER);
				}			
				break;
			}
		}
	case WM_SETFOCUS:
		break;
	case WM_KILLFOCUS:
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint (hwnd, &ps);
			HDC hdcMem = CreateCompatibleDC(hdc);
			HBITMAP hBitmap = CreateCompatibleBitmap(hdc,pthis->w,pthis->h);
			SelectObject(hdcMem,hBitmap);

			// 当wnd不带背景图的时候
			if(pthis->img )
			{
				Gdiplus::Graphics graphics(hdcMem);
				graphics.DrawImage(pthis->image,0,0,pthis->w,pthis->h);
				
			}
			else
			{
				// 绘制背景
				HBRUSH hbrush = CreateSolidBrush(pthis->m_bkc);
				FillRect(hdcMem,&ps.rcPaint,hbrush);
				DeleteObject(hbrush);				
			}

			if(pthis->text)
			{
				HFONT hFont = CreateFont(pthis->fontsize,0,0,0,FW_MEDIUM,FALSE,FALSE,FALSE,
					ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
					DEFAULT_PITCH|FF_DONTCARE,pthis->text_style);

				HGDIOBJ hOldFont = SelectObject(hdcMem,hFont);

				SetTextColor(hdcMem,pthis->m_fontc);
				SetBkMode(hdcMem,TRANSPARENT);
				RECT rcText;
				GetClientRect(hwnd,&rcText);
				DrawText(hdcMem,pthis->text,-1,&rcText,DT_LEFT|DT_TOP|DT_WORDBREAK);
			}

			BLENDFUNCTION blendFunction;
			blendFunction.BlendOp = AC_SRC_OVER;
			blendFunction.BlendFlags = 0;
			blendFunction.SourceConstantAlpha = 255;
			blendFunction.AlphaFormat = AC_SRC_ALPHA;

			POINT ptDst = {0,0};
			SIZE sizeWnd = {pthis->image->GetWidth(),pthis->image->GetHeight()};
			POINT ptSrc = {0,0};

			DWORD dwExStyle;
			dwExStyle=GetWindowLong(hwnd,GWL_EXSTYLE);

			// 异型窗口的神秘属性
			if((dwExStyle&WS_EX_LAYERED)!=WS_EX_LAYERED)
				SetWindowLong(hwnd,GWL_EXSTYLE,dwExStyle^WS_EX_LAYERED);

			UpdateLayeredWindow(hwnd,NULL,NULL,&sizeWnd,hdcMem,&ptSrc,0,&blendFunction,ULW_ALPHA);

			DeleteObject(hBitmap);
			DeleteDC(hdcMem);
			EndPaint (hwnd, &ps);
		}
		return 0;
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}
#include "stdafx.h"
#include "btn.h"

btn::btn( INT i,HWND father ,BOOL ispop,LPTSTR imgpath,btn_state s,INT X,INT Y,INT W,INT H,LPTSTR t,LPTSTR ts,INT fs,COLORREF bk, COLORREF fontc )
{
	id = i;
	AddSelfToManager();

	m_father = father;
	m_ispop = ispop;
	img = imgpath;
	if(img)
	{
		image = new Gdiplus::Image(img);
		w = image->GetWidth()/4;			// ��ť�Ŀ����ͼƬ��1/4
		h = image->GetHeight();
	} else {
		w=W;
		h=H;
	}

	if(ispop)
	{
		RECT rect;
		GetWindowRect(father,&rect);
		x=X+rect.left;
		y=Y+rect.top;
	}else
	{
		x=X;
		y=Y;
	}

	m_bkc = bk;
	m_fontc = fontc;
	text = t;
	text_style = ts;
	fontsize = fs;

	state = s;

	saveClickFun = NULL;

	// ע��
	WNDCLASS wcex;
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= BtnProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= sizeof(long);
	wcex.hInstance		= g_hInstance;
	wcex.hCursor		= LoadCursor(NULL, IDC_HAND);
	wcex.hbrBackground	= (HBRUSH)GetStockObject(NULL_BRUSH);
	wcex.lpszMenuName	= NULL;
	wcex.hIcon          = NULL;
	wcex.lpszClassName	= _T("btn");

	// ��������ظ�ע�ᣬ����û�м�if�ж�
	RegisterClass(&wcex);

	if(ispop)
		m_wnd = CreateWindowEx(WS_EX_TRANSPARENT,_T("btn"),NULL,WS_CHILD|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS|WS_POPUP,
			x, y, w, h,m_father, NULL,g_hInstance,NULL);
	else
		m_wnd = CreateWindowEx(WS_EX_LAYERED,_T("btn"),NULL,WS_OVERLAPPEDWINDOW,
			x, y, w, h,m_father, NULL,g_hInstance,NULL);

	if (!m_wnd)
	{
		// error �����ڴ���ʧ��
		return;
	}

	// �������趨Ϊ�Ӵ���
	if(!m_ispop)
		SetParent(m_wnd,m_father);
	
	// �����ʵ��ָ���봰�ڹ��������ھ�̬�ص�����
	SetWindowLongPtr(m_wnd,GWLP_USERDATA,reinterpret_cast<LONG_PTR>(this));

	ShowWindow(m_wnd, SW_SHOW);
	UpdateWindow(m_wnd);

	// ˢһ�����Լ��ػ�
	if(!m_ispop)
		InvalidateRect(m_wnd,NULL,0);

	UnregisterClass(_T("btn"), wcex.hInstance);
}

// ����ϵͳ�ص�����
LRESULT CALLBACK btn::BtnProc( HWND hwnd , UINT message , WPARAM wParam , LPARAM lParam )
{
	// �Ӵ��ڻ�ȡʵ��ָ��
	btn* pthis = reinterpret_cast<btn*>(GetWindowLongPtr(hwnd,GWLP_USERDATA));

	HDC hdc;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_LBUTTONDOWN:
		if( pthis->state == disable)
			break;

		pthis->state = m_btndown;
		InvalidateRect(hwnd,NULL,FALSE);
		break;
	case WM_LBUTTONUP:
		if( pthis->state == disable)
			break;

		pthis->state = m_enter;
		InvalidateRect(hwnd,NULL,FALSE);
		// ����Ҫִ�а�ť�ĳ���
		pthis->OnClick();		
		break;
	case WM_MOUSEMOVE:
		if( pthis->state == disable)
			break;
		if(pthis->state != m_btndown)
			pthis->state = m_enter;
		InvalidateRect(hwnd,NULL,FALSE);
		// ���������٣�������֪������Ƴ�����Ϣ
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(TRACKMOUSEEVENT);
		tme.dwFlags = TME_HOVER | TME_LEAVE;
		tme.hwndTrack = hwnd;
		tme.dwHoverTime = HOVER_DEFAULT;
		TrackMouseEvent(&tme);	
		break;
	case WM_MOUSELEAVE:
		if( pthis->state == disable)
			break;
		pthis->state = nomarl;
		InvalidateRect(hwnd,NULL,FALSE);
		break;
	case WM_PAINT:
		hdc = BeginPaint (hwnd, &ps);		

		if(!pthis->m_ispop)
		{
			LONG_PTR style = GetWindowLongPtr(hwnd,GWL_STYLE);
			style &= ~WS_OVERLAPPEDWINDOW;
			style |= WS_CHILD;
			SetWindowLongPtr(hwnd,GWL_STYLE,style);
			DWORD dwExStyle=GetWindowLong(hwnd,GWL_EXSTYLE);
			dwExStyle |= WS_EX_LAYERED;
			SetWindowLong(hwnd,GWL_EXSTYLE,dwExStyle);
			SetLayeredWindowAttributes(hwnd,0,255,LWA_ALPHA);		
			SetWindowPos(hwnd,NULL,pthis->x,pthis->y,pthis->w,pthis->h,SWP_SHOWWINDOW);
			BringWindowToTop(hwnd);
			SetLayeredWindowAttributes(hwnd,0,255,LWA_ALPHA);
		}

		// ��ť��ͬ״̬ʱ�����Ʋ�ͬͼƬ
		// ��wnd��������ͼ��ʱ��
		if(pthis->img )
		{
			// �б���ͼ�����Ʊ���ͼ
			Gdiplus::Graphics graphics(hdc);
			// ����״̬ȷ��Ҫ��ʾ�ĸ�����
			Gdiplus::Rect d(0,0,pthis->w,pthis->h);
			Gdiplus::Rect s(0,0,pthis->w,pthis->h);
			// ���ư�ť�Ĳ�ͬ״̬
			switch(pthis->state)
			{
			case nomarl:
				break;
			case m_enter:
				s.X = pthis->w;
				break;
			case m_btndown:
				s.X = 2*pthis->w;
				break;
			case disable:
				s.X = 3*pthis->w;
				break;
			}
			graphics.DrawImage(pthis->image,d,s.X,s.Y,s.Width,s.Height,UnitPixel);
		}
		else
		{
			// ���Ʊ���
			HBRUSH hbrush = CreateSolidBrush(pthis->m_bkc);
			FillRect(hdc,&ps.rcPaint,hbrush);
			DeleteObject(hbrush);				
		}

		if(pthis->text)
		{
			HFONT hFont = CreateFont(pthis->fontsize,0,0,0,FW_MEDIUM,FALSE,FALSE,FALSE,
				ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,
				DEFAULT_PITCH|FF_DONTCARE,pthis->text_style);
			HGDIOBJ hOldFont = SelectObject(hdc,hFont);
			SetBkMode(hdc,TRANSPARENT);
			SetTextColor(hdc,pthis->m_fontc);

			RECT rcText;
			GetClientRect(hwnd,&rcText);
			DrawText(hdc,pthis->text,-1,&rcText,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		}

		EndPaint (hwnd, &ps);
		return 0;
	}
	return DefWindowProc (hwnd, message, wParam, lParam) ;
}
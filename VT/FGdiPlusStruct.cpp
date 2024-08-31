//#include "StdAfx.h"
#include "FGdiPlusStruct.h"

ArgbPos::ArgbPos(void)
{
	a = r = g = b;
	position = 0.0f;
}

ArgbPos::ArgbPos(_ARGB_POS& iSrc)
{
	*this = iSrc;
}

ArgbPos::ArgbPos(unsigned char A, unsigned char R, unsigned char G, unsigned char B, float Pos)
{
	SetColor(A, R, G, B, Pos);
}

ArgbPos::~ArgbPos(void)
{

}

// 运算符
ArgbPos& ArgbPos::operator=(struct _ARGB_POS& iSrc)
{
	a = iSrc.a;
	r = iSrc.r;
	g = iSrc.g;
	b = iSrc.b;
	position = iSrc.position;
	return *this;
}

// 设置颜色
void ArgbPos::SetColor(unsigned char A, unsigned char R, unsigned char G, unsigned char B, float Pos)
{
	a = A;
	r = R;
	g = G;
	b = B;
	position = Pos;
}

// 转换为ARGB
unsigned long ArgbPos::MakeARGB()
{
	return (((unsigned long)(b) << BlueShift) |
		((unsigned long)(g) << GreenShift) |
		((unsigned long)(r) << RedShift) |
		((unsigned long)(a) << AlphaShift));
}

unsigned long ArgbPos::MakeARGB(struct _ARGB_POS& iSrc)
{
	return MakeARGB(iSrc.a, iSrc.r, iSrc.g, iSrc.b);
}

unsigned long ArgbPos::MakeARGB(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	return (((unsigned long)(b) << BlueShift) |
		((unsigned long)(g) << GreenShift) |
		((unsigned long)(r) << RedShift) |
		((unsigned long)(a) << AlphaShift));
}

// 获得过渡位置数据
float ArgbPos::GetPosition()
{
	return position;
}
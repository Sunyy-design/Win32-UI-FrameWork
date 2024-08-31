#pragma once
#ifndef FGDIPLUSSTRUCT_H
#define FGDIPLUSSTRUCT_H
// 存储颜色和比例的结构体
typedef struct _ARGB_POS
{
	unsigned char	a;			// 透明度
	unsigned char	r;			// 红
	unsigned char	g;			// 绿
	unsigned char	b;			// 蓝
	float			position;	// 过度开始位置
}ARGB_POS,*LPARGB_POS;
// 颜色和比例操作类
class ArgbPos:
	public _ARGB_POS
{

public:

	ArgbPos(void);
	ArgbPos(_ARGB_POS& iSrc);
	ArgbPos(ArgbPos& iSrc);
	ArgbPos(unsigned char A, unsigned char R, unsigned char G, unsigned char B, float Pos);
	~ArgbPos(void);

private:

    enum
    {
        AlphaShift  = 24,
        RedShift    = 16,
        GreenShift  = 8,
        BlueShift   = 0
    };

public:
	// 运算符
	ArgbPos& operator=(struct _ARGB_POS& iSrc);
	// 设置颜色
	void SetColor(unsigned char A, unsigned char R, unsigned char G, unsigned char B, float Pos);
	// 转换为ARGB
	unsigned long MakeARGB();
	static unsigned long MakeARGB(struct _ARGB_POS& iSrc);
	static unsigned long MakeARGB(unsigned char a, unsigned char r, unsigned char g, unsigned char b);
	// 获得过渡位置数据
	float GetPosition();
};
#endif
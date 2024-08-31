#pragma once
#ifndef FGDIPLUSSTRUCT_H
#define FGDIPLUSSTRUCT_H
// �洢��ɫ�ͱ����Ľṹ��
typedef struct _ARGB_POS
{
	unsigned char	a;			// ͸����
	unsigned char	r;			// ��
	unsigned char	g;			// ��
	unsigned char	b;			// ��
	float			position;	// ���ȿ�ʼλ��
}ARGB_POS,*LPARGB_POS;
// ��ɫ�ͱ���������
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
	// �����
	ArgbPos& operator=(struct _ARGB_POS& iSrc);
	// ������ɫ
	void SetColor(unsigned char A, unsigned char R, unsigned char G, unsigned char B, float Pos);
	// ת��ΪARGB
	unsigned long MakeARGB();
	static unsigned long MakeARGB(struct _ARGB_POS& iSrc);
	static unsigned long MakeARGB(unsigned char a, unsigned char r, unsigned char g, unsigned char b);
	// ��ù���λ������
	float GetPosition();
};
#endif
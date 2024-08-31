#ifndef FGDIPLUSITEMTYPE_H
#define FGDIPLUSITEMTYPE_H
#include<GdiPlus.h>

/*
����			��						����

������ͷñ		AdjustableArrowCap		�����Զ����ͷ��ñ
λͼ			Bitmap					�ṩװ��ͱ���ʸ���͹�դͼ��ķ����������Դ����Ͳ�����դͼ��
λͼ����		BitmapData				����λͼ������
ģ��			Blur					����˹ģ��Ч�����õ�ͼ��
���ȶԱȶ�		BrightnessContrast		�ı�ͼ������ȺͶԱȶ�
ˢ				Brush					����ˢ����
����ͼ��		CachedBitmap			��Ϊ�ص��豸��ʾ���Ż����ĸ�ʽ�洢λͼ
�ַ���Χ		CharacterRange			ָ�������ַ�λ�õķ�Χ
��ɫ			Color					�����ʾ��ɫ��32λֵ
ɫƽ��			ColorBalance			�ı�λͼ����ɫƽ��
��ɫ����		ColorCurve				�ɵ���λͼ���ع�ȡ��ܶȡ��Աȶȡ���������Ӱ��ɫ�����ױ��ͺͺڱ��͡�
��ɫ���ұ�		ColorLUT				���ڶ���λͼ����ɫ����
��ɫ����Ч��	ColorMatrixEffect		��λͼ���з���任
������ñ		CustomLineCap			��װ���Զ�����ñ
Ч��			Effect					������ͼ���Ч���͵�����Ļ���
����������		EncoderParameter		����ͼ��������Ĳ���
������������	EncoderParameters		ͼ�����������������
����			Font					��װ���������ϵ���߶ȡ���С�ͷ�������
���弯			FontCollection			����ö�����弯�е�������ϵ�ķ���
������			FontFamily				��װ�˹���һ������������弯��
GDI+����		GdiplusBase				�ṩ��GDI+����Ĵ洢�������ͷţ�������GDI+��Ļ���
ͼ��			Graphics				�ṩ����ͼ�Ρ�ͼ����ı��ķ������洢��ʾ�豸�ͱ�����Ŀ������
ͼ��·��		GraphicsPath			����һ������ͼ�õ�ֱ�ߡ����ߺ���״����
ͼ��·��������	GraphicsPathIterator	�ṩ�ӱ�����GraphicsPath�����е�·����ѡ������Ӽ��ķ���
Ӱ��ˢ			HatchBrush				�������Ӱ�߷���ǰ��ɫ/����ɫ�ľ���ˢ
ɫ�����Ͷ�����	HueSaturationLightness	�ı�λͼ��ɫ��H�����Ͷ�S������L
ͼ��			Image					�ṩװ��ͱ���ʸ���͹�դͼ��ķ���
ͼ������		ImageAttributes			����Ⱦʱ��β���λͼ��ͼԪ�ļ���ɫ����Ϣ
ͼ��������Ϣ	ImageCodecInfo			�洢��ͼ�������йص���Ϣ
ͼ��������		ImageItemData			���ڴ洢�ͻ�ȡ�Զ���ͼ���Ԫ����
��װ�����弯	InstalledFontCollection	�����ʾ��װ��ϵͳ�е����弯
����			Levels					�ɵ���λͼ�ļ�������Ӱ��ɫ��
�����ݶ�ˢ		LinearGradientBrush		�������Խ���ˢ
����			Matrix					��ʾ3��3�ķ���任����
ͼԪ�ļ�		Metafile				�����������һϵ��ͼ��API���ü�¼��ͼ��Ԫ�ļ����ɱ���¼�����죩�ͻطţ���ʾ��
ͼԪ�ļ�ͷ		MetafileHeader			�������ͼԪ�ļ�������
·������		PathData				GraphicsPath��GraphicsPathIterator��������࣬���ڻ�ȡ������·���е����ݵ㼰������
·���ݶ�ˢ		PathGradientBrush		������ɫ���ݶ����ԣ����ڽ���ɫ���·���ڲ�
��				Pen						���ڻ���ֱ�ߺ����ߵıʶ���
��				Point					��װ2D��������ϵͳ�еĵ�
�����			PointF					��װ2D��������ϵͳ�еĵ�
ר�����弯		PrivateFontCollection	���������ض�Ӧ�ó�������弯���ɺ�δװ��ϵͳ�е�����
������			PropertyItem			Image��Bitmap��������࣬����һ�飨piece��ͼ��Ԫ����
����			Rect					������ε����Ͻǡ���Ⱥ͸߶�֮����������
�������		RectF					������ε����Ͻǡ���Ⱥ͸߶�֮���󣨸�������
����У��		RedEyeCorrection		У����ʱ��������Ƭ�г��ֵĺ���
����			Region					������ʾ����ķ�Χ��������������״
��			Sharpen					����λͼ��������
��С			Size					��װ2D��������ϵͳ�еĿ�͸�
�����С		SizeF					��װ2D����������ϵͳ�еĿ�͸�
ʵ��ˢ			SolidBrush				����ʵ����ɫ��ˢ�Ӷ���
����ʽ			StringFormat			��װ�ı��ĸ�ʽ��layout����Ϣ����ʾ����
����ˢ			TextureBrush			�������İ���ͼ������ˢ��
Ũ��			Tint					�ı�λͼ��ɫ��Ũ��
*/

using namespace Gdiplus;

#define FAdjustableArrowCap			Gdiplus::AdjustableArrowCap			//�����Զ����ͷ��ñ
#define FBitmap						Gdiplus::Bitmap						//�ṩװ��ͱ���ʸ���͹�դͼ��ķ����������Դ����Ͳ�����դͼ��
#define FBitmapData					Gdiplus::BitmapData					//����λͼ������
#define FBrush						Gdiplus::Brush						//����ˢ����
#define FCachedBitmap				Gdiplus::CachedBitmap				//��Ϊ�ص��豸��ʾ���Ż����ĸ�ʽ�洢λͼ
#define FCharacterRange				Gdiplus::CharacterRange				//ָ�������ַ�λ�õķ�Χ
#define FColor						Gdiplus::Color						//�����ʾ��ɫ��32λֵ
#define FCustomLineCap				Gdiplus::CustomLineCap				//��װ���Զ�����ñ
#define FEncoderParameter			Gdiplus::EncoderParameter			//����ͼ��������Ĳ���
#define FEncoderParameters			Gdiplus::EncoderParameters			//ͼ�����������������
#define FFont						Gdiplus::Font						//��װ���������ϵ���߶ȡ���С�ͷ�������
#define FFontCollection				Gdiplus::FontCollection				//����ö�����弯�е�������ϵ�ķ���
#define FFontFamily					Gdiplus::FontFamily					//��װ�˹���һ������������弯��
#define FGdiplusBase				Gdiplus::GdiplusBase				//�ṩ��GDI+����Ĵ洢�������ͷţ�������GDI+��Ļ���
#define FGraphics					Gdiplus::Graphics					//�ṩ����ͼ�Ρ�ͼ����ı��ķ������洢��ʾ�豸�ͱ�����Ŀ������
#define FGraphicsPath				Gdiplus::GraphicsPath				//����һ������ͼ�õ�ֱ�ߡ����ߺ���״����
#define FGraphicsPathIterator		Gdiplus::GraphicsPathIterator		//�ṩ�ӱ�����GraphicsPath�����е�·����ѡ������Ӽ��ķ���
#define FGdiplusStartupInput		Gdiplus::GdiplusStartupInput		//GDI+ Input
#define FHatchBrush					Gdiplus::HatchBrush					//�������Ӱ�߷���ǰ��ɫ/����ɫ�ľ���ˢ
#define FImage						Gdiplus::Image						//�ṩװ��ͱ���ʸ���͹�դͼ��ķ���
#define FImageAttributes			Gdiplus::ImageAttributes			//����Ⱦʱ��β���λͼ��ͼԪ�ļ���ɫ����Ϣ
#define FImageCodecInfo				Gdiplus::ImageCodecInfo				//�洢��ͼ�������йص���Ϣ
#define FInstalledFontCollection	Gdiplus::InstalledFontCollection	//�����ʾ��װ��ϵͳ�е����弯
#define FLinearGradientBrush		Gdiplus::LinearGradientBrush		//�������Խ���ˢ
#define FMatrix						Gdiplus::Matrix						//��ʾ3��3�ķ���任����
#define FMetafile					Gdiplus::Metafile					//�����������һϵ��ͼ��API���ü�¼��ͼ��Ԫ�ļ����ɱ���¼�����죩�ͻطţ���ʾ��
#define FMetafileHeader				Gdiplus::MetafileHeader				//�������ͼԪ�ļ�������
#define FPathData					Gdiplus::PathData					//GraphicsPath��GraphicsPathIterator��������࣬���ڻ�ȡ������·���е����ݵ㼰������
#define FPathGradientBrush			Gdiplus::PathGradientBrush			//������ɫ���ݶ����ԣ����ڽ���ɫ���·���ڲ�
#define FPen						Gdiplus::Pen						//���ڻ���ֱ�ߺ����ߵıʶ���
#define FPoint						Gdiplus::Point						//��װ2D��������ϵͳ�еĵ�
#define FPointF						Gdiplus::PointF						//��װ2D��������ϵͳ�еĵ�
#define FPrivateFontCollection		Gdiplus::PrivateFontCollection		//���������ض�Ӧ�ó�������弯���ɺ�δװ��ϵͳ�е�����
#define FPropertyItem				Gdiplus::PropertyItem				//Image��Bitmap��������࣬����һ�飨piece��ͼ��Ԫ����
#define FRect						Gdiplus::Rect						//������ε����Ͻǡ���Ⱥ͸߶�֮����������
#define FRectF						Gdiplus::RectF						//������ε����Ͻǡ���Ⱥ͸߶�֮���󣨸�������
#define FRegion						Gdiplus::Region						//������ʾ����ķ�Χ��������������״
#define FSize						Gdiplus::Size						//��װ2D��������ϵͳ�еĿ�͸�
#define FSizeF						Gdiplus::SizeF						//��װ2D����������ϵͳ�еĿ�͸�
#define FSolidBrush					Gdiplus::SolidBrush					//����ʵ����ɫ��ˢ�Ӷ���
#define FStringFormat				Gdiplus::StringFormat				//��װ�ı��ĸ�ʽ��layout����Ϣ����ʾ����
#define FTextureBrush				Gdiplus::TextureBrush				//�������İ���ͼ������ˢ��

// GDI+ V1.1 ������
#if (GDIPVER >= 0x0110)

#define FBlur						Gdiplus::Blur						//����˹ģ��Ч�����õ�ͼ��(V1.1)
#define FBrightnessContrast			Gdiplus::BrightnessContrast			//�ı�ͼ������ȺͶԱȶ�(V1.1)
#define FColorBalance				Gdiplus::ColorBalance				//�ı�λͼ����ɫƽ��(V1.1)
#define FColorCurve					Gdiplus::ColorCurve					//�ɵ���λͼ���ع�ȡ��ܶȡ��Աȶȡ���������Ӱ��ɫ�����ױ��ͺͺڱ��͡�(V1.1)
#define FColorLUT					Gdiplus::ColorLUT					//���ڶ���λͼ����ɫ����(V1.1)
#define FColorMatrixEffect			Gdiplus::ColorMatrixEffect			//��λͼ���з���任(V1.1)
#define FEffect						Gdiplus::Effect						//������ͼ���Ч���͵�����Ļ���(V1.1)
#define FHueSaturationLightness		Gdiplus::HueSaturationLightness		//�ı�λͼ��ɫ��H�����Ͷ�S������L(V1.1)
#define FImageItemData				Gdiplus::ImageItemData				//���ڴ洢�ͻ�ȡ�Զ���ͼ���Ԫ����(V1.1)
#define FLevels						Gdiplus::Levels						//�ɵ���λͼ�ļ�������Ӱ��ɫ��(V1.1)
#define FRedEyeCorrection			Gdiplus::RedEyeCorrection			//У����ʱ��������Ƭ�г��ֵĺ���(V1.1)
#define FSharpen					Gdiplus::Sharpen					//����λͼ��������(V1.1)
#define FTint						Gdiplus::Tint						//�ı�λͼ��ɫ��Ũ��(V1.1)

#endif

#endif
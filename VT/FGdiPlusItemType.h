#ifndef FGDIPLUSITEMTYPE_H
#define FGDIPLUSITEMTYPE_H
#include<GdiPlus.h>

/*
名称			类						功能

调整箭头帽		AdjustableArrowCap		创建自定义箭头线帽
位图			Bitmap					提供装入和保存矢量和光栅图像的方法，并可以创建和操作光栅图像
位图数据		BitmapData				保存位图的属性
模糊			Blur					将高斯模糊效果作用到图像
亮度对比度		BrightnessContrast		改变图像的亮度和对比度
刷				Brush					定义刷对象
缓存图像		CachedBitmap			用为特点设备显示而优化过的格式存储位图
字符范围		CharacterRange			指定串内字符位置的范围
颜色			Color					保存表示颜色的32位值
色平衡			ColorBalance			改变位图的颜色平衡
颜色曲线		ColorCurve				可调整位图的曝光度、密度、对比度、加亮、阴影、色调、白饱和和黑饱和。
颜色查找表		ColorLUT				用于定制位图的颜色调整
颜色矩阵效果	ColorMatrixEffect		对位图进行仿射变换
定制线帽		CustomLineCap			封装了自定义线帽
效果			Effect					作用于图像的效果和调整类的基类
编码器参数		EncoderParameter		保存图像编码器的参数
编码器参数组	EncoderParameters		图像编码器参数的数组
字体			Font					封装了字体的族系、高度、大小和风格等特性
字体集			FontCollection			包含枚举字体集中的字体族系的方法
字体族			FontFamily				封装了构成一个字体族的字体集合
GDI+基类		GdiplusBase				提供对GDI+对象的存储分配与释放，是其它GDI+类的基类
图形			Graphics				提供绘制图形、图像和文本的方法，存储显示设备和被画项目的属性
图形路径		GraphicsPath			保存一个供绘图用的直线、曲线和形状序列
图形路径迭代器	GraphicsPathIterator	提供从保存在GraphicsPath对象中的路径里选择孤立子集的方法
影线刷			HatchBrush				定义具有影线风格和前景色/背景色的矩形刷
色调饱和度亮度	HueSaturationLightness	改变位图的色调H、饱和度S和亮度L
图像			Image					提供装入和保存矢量和光栅图像的方法
图像属性		ImageAttributes			含渲染时如何操作位图和图元文件颜色的信息
图像编解码信息	ImageCodecInfo			存储与图像编解码有关的信息
图像项数据		ImageItemData			用于存储和获取自定义图像的元数据
已装入字体集	InstalledFontCollection	定义表示已装入系统中的字体集
级别			Levels					可调整位图的加亮、阴影和色调
线形梯度刷		LinearGradientBrush		定义线性渐变刷
矩阵			Matrix					表示3×3的仿射变换矩阵
图元文件		Metafile				定义包含描述一系列图形API调用记录的图形元文件，可被记录（构造）和回放（显示）
图元文件头		MetafileHeader			保存关联图元文件的性质
路径数据		PathData				GraphicsPath和GraphicsPathIterator类的助手类，用于获取和设置路径中的数据点及其类型
路径梯度刷		PathGradientBrush		保存颜色的梯度属性，用于渐变色填充路径内部
笔				Pen						用于绘制直线和曲线的笔对象
点				Point					封装2D整数坐标系统中的点
浮点点			PointF					封装2D浮点坐标系统中的点
专用字体集		PrivateFontCollection	保存用于特定应用程序的字体集，可含未装入系统中的字体
特性项			PropertyItem			Image和Bitmap类的助手类，保存一块（piece）图像元数据
矩形			Rect					保存矩形的左上角、宽度和高度之对象（整数）
浮点矩形		RectF					保存矩形的左上角、宽度和高度之对象（浮点数）
红眼校正		RedEyeCorrection		校正有时在闪光照片中出现的红眼
区域			Region					描述显示表面的范围，可以是任意形状
锐化			Sharpen					调整位图的清晰度
大小			Size					封装2D整数坐标系统中的宽和高
浮点大小		SizeF					封装2D浮点数坐标系统中的宽和高
实心刷			SolidBrush				定义实心颜色的刷子对象
串格式			StringFormat			封装文本的格式（layout）信息和显示操作
纹理刷			TextureBrush			用于填充的包含图像对象的刷子
浓淡			Tint					改变位图的色彩浓淡
*/

using namespace Gdiplus;

#define FAdjustableArrowCap			Gdiplus::AdjustableArrowCap			//创建自定义箭头线帽
#define FBitmap						Gdiplus::Bitmap						//提供装入和保存矢量和光栅图像的方法，并可以创建和操作光栅图像
#define FBitmapData					Gdiplus::BitmapData					//保存位图的属性
#define FBrush						Gdiplus::Brush						//定义刷对象
#define FCachedBitmap				Gdiplus::CachedBitmap				//用为特点设备显示而优化过的格式存储位图
#define FCharacterRange				Gdiplus::CharacterRange				//指定串内字符位置的范围
#define FColor						Gdiplus::Color						//保存表示颜色的32位值
#define FCustomLineCap				Gdiplus::CustomLineCap				//封装了自定义线帽
#define FEncoderParameter			Gdiplus::EncoderParameter			//保存图像编码器的参数
#define FEncoderParameters			Gdiplus::EncoderParameters			//图像编码器参数的数组
#define FFont						Gdiplus::Font						//封装了字体的族系、高度、大小和风格等特性
#define FFontCollection				Gdiplus::FontCollection				//包含枚举字体集中的字体族系的方法
#define FFontFamily					Gdiplus::FontFamily					//封装了构成一个字体族的字体集合
#define FGdiplusBase				Gdiplus::GdiplusBase				//提供对GDI+对象的存储分配与释放，是其它GDI+类的基类
#define FGraphics					Gdiplus::Graphics					//提供绘制图形、图像和文本的方法，存储显示设备和被画项目的属性
#define FGraphicsPath				Gdiplus::GraphicsPath				//保存一个供绘图用的直线、曲线和形状序列
#define FGraphicsPathIterator		Gdiplus::GraphicsPathIterator		//提供从保存在GraphicsPath对象中的路径里选择孤立子集的方法
#define FGdiplusStartupInput		Gdiplus::GdiplusStartupInput		//GDI+ Input
#define FHatchBrush					Gdiplus::HatchBrush					//定义具有影线风格和前景色/背景色的矩形刷
#define FImage						Gdiplus::Image						//提供装入和保存矢量和光栅图像的方法
#define FImageAttributes			Gdiplus::ImageAttributes			//含渲染时如何操作位图和图元文件颜色的信息
#define FImageCodecInfo				Gdiplus::ImageCodecInfo				//存储与图像编解码有关的信息
#define FInstalledFontCollection	Gdiplus::InstalledFontCollection	//定义表示已装入系统中的字体集
#define FLinearGradientBrush		Gdiplus::LinearGradientBrush		//定义线性渐变刷
#define FMatrix						Gdiplus::Matrix						//表示3×3的仿射变换矩阵
#define FMetafile					Gdiplus::Metafile					//定义包含描述一系列图形API调用记录的图形元文件，可被记录（构造）和回放（显示）
#define FMetafileHeader				Gdiplus::MetafileHeader				//保存关联图元文件的性质
#define FPathData					Gdiplus::PathData					//GraphicsPath和GraphicsPathIterator类的助手类，用于获取和设置路径中的数据点及其类型
#define FPathGradientBrush			Gdiplus::PathGradientBrush			//保存颜色的梯度属性，用于渐变色填充路径内部
#define FPen						Gdiplus::Pen						//用于绘制直线和曲线的笔对象
#define FPoint						Gdiplus::Point						//封装2D整数坐标系统中的点
#define FPointF						Gdiplus::PointF						//封装2D浮点坐标系统中的点
#define FPrivateFontCollection		Gdiplus::PrivateFontCollection		//保存用于特定应用程序的字体集，可含未装入系统中的字体
#define FPropertyItem				Gdiplus::PropertyItem				//Image和Bitmap类的助手类，保存一块（piece）图像元数据
#define FRect						Gdiplus::Rect						//保存矩形的左上角、宽度和高度之对象（整数）
#define FRectF						Gdiplus::RectF						//保存矩形的左上角、宽度和高度之对象（浮点数）
#define FRegion						Gdiplus::Region						//描述显示表面的范围，可以是任意形状
#define FSize						Gdiplus::Size						//封装2D整数坐标系统中的宽和高
#define FSizeF						Gdiplus::SizeF						//封装2D浮点数坐标系统中的宽和高
#define FSolidBrush					Gdiplus::SolidBrush					//定义实心颜色的刷子对象
#define FStringFormat				Gdiplus::StringFormat				//封装文本的格式（layout）信息和显示操作
#define FTextureBrush				Gdiplus::TextureBrush				//用于填充的包含图像对象的刷子

// GDI+ V1.1 新特性
#if (GDIPVER >= 0x0110)

#define FBlur						Gdiplus::Blur						//将高斯模糊效果作用到图像(V1.1)
#define FBrightnessContrast			Gdiplus::BrightnessContrast			//改变图像的亮度和对比度(V1.1)
#define FColorBalance				Gdiplus::ColorBalance				//改变位图的颜色平衡(V1.1)
#define FColorCurve					Gdiplus::ColorCurve					//可调整位图的曝光度、密度、对比度、加亮、阴影、色调、白饱和和黑饱和。(V1.1)
#define FColorLUT					Gdiplus::ColorLUT					//用于定制位图的颜色调整(V1.1)
#define FColorMatrixEffect			Gdiplus::ColorMatrixEffect			//对位图进行仿射变换(V1.1)
#define FEffect						Gdiplus::Effect						//作用于图像的效果和调整类的基类(V1.1)
#define FHueSaturationLightness		Gdiplus::HueSaturationLightness		//改变位图的色调H、饱和度S和亮度L(V1.1)
#define FImageItemData				Gdiplus::ImageItemData				//用于存储和获取自定义图像的元数据(V1.1)
#define FLevels						Gdiplus::Levels						//可调整位图的加亮、阴影和色调(V1.1)
#define FRedEyeCorrection			Gdiplus::RedEyeCorrection			//校正有时在闪光照片中出现的红眼(V1.1)
#define FSharpen					Gdiplus::Sharpen					//调整位图的清晰度(V1.1)
#define FTint						Gdiplus::Tint						//改变位图的色彩浓淡(V1.1)

#endif

#endif
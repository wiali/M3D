﻿/**@file
 *@brief    背景节点
 *@author	XL
 *@date		2014-1-7
 *@version	1.0
 *
 */

#ifndef	   M3D_BACKGROUNDNODE_H_
#define    M3D_BACKGROUNDNODE_H_

#include "m3d/base/Color.h"
#include "m3d/scene/SceneNode.h"

namespace M3D
{
class Texture;

/**
 * 绘制背景颜色，支持颜色绘制和图片绘制两种方式
 */
class M3D_API BackgroundNode: public SceneNode
{
public:
	BackgroundNode();
	virtual ~BackgroundNode();
	virtual int GetType(void);
	virtual void FindVisiableObject(RenderAction* renderAction);
public:
	/**
	 * 设置绘制背景的宽和高
	 * @param width
	 * @param height
	 */
	void SetBackgroundSize(int width, int height);
    
	/**
	 * 设置背景色顶部颜色
	 * @param topColor
	 */
	void SetTopColor(const Color& topColor);

	/**
	 * 设置背景色底部颜色
	 * @param bottomColor
	 */
	void SetBottomColor(const Color& bottomColor);
    
	/**
	 * 获取绘制顶部颜色
	 * @param topColor
	 */
    void GetTopColor( Color& topColor);
    /**
     * 获取绘制底部颜色
     * @param bottomColor
     */
    void GetBottomColor( Color& bottomColor);

    /**
     * 获取绘制背景所需要的点
     * @return
     */
	Vector3* GetVertexs();


	/**
	 * 获取绘制背景图片所需的纹理坐标
	 * @return
	 */
	Vector2* GetTextureCoords();

    /**
     * 设置背景图片路径
     * @param filePath
     * @param mappingStyle
     */
    void SetImage(const string& filePath,int mappingStyle);

    /**
     * 设置是否使用背景图片
     * @param useImage true 使用背景图片 false不使用
     */
    void SetUseImage(bool useImage);

    /**
     * 获取当前是否使用背景图片
     * @return  true 使用背景图片 false不使用
     */
    bool IsUseImage();

	Texture* GetTexture();

protected:
//	virtual void FinalRelease(void); // Container.h
	void Initial();


private:
	void UpdateTopColor(void);
	void UpdateBottomColor(void);

public:
	Color m_topColor; //!<顶部颜色
	Color m_bottomColor; //!<底部颜色

	int m_iViewX; //!<视口宽
	int m_iViewY; //!<视口高
	int m_iWidth; //!<
	int m_iHeight; //!<
	float m_fAspectRatio; //!<背景平行投影裁剪窗口大小
	float m_ProArray[6]; //!<背景视口

	float m_BackColor[24]; //!<背景颜色
	float m_BackPnt[18]; //!<背景三角网格六个点

	vector<Vector3> points; //!<
	vector<Vector2> textCoords; //!<背景绘制所需纹理坐标

private:
	bool m_isImageDirty; //!<图片脏标记 当图片脏时 需要重构构纹理

	bool m_isUseImage;  //!<是否使用背景图片标志

	string m_imagePath;  //!<图片路径

	Texture* m_texture;  //!<背景纹理
};
}
#endif // BACKGROUNDCOLORNODE_H

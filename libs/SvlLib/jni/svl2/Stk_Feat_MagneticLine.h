﻿// All Rights Reserved. Copyright (C) 2014 HOTEAMSOFT, Ltd
/*****************************************************************************
 *	@file	Stk_Feat_MagneticLine.h
 *
 *	@brief	磁力线特征类
 *
 *	@par	历史:
 *		2015/04/08	创建。WangY@HOTEAMSOFT
****************************************************************************/

#ifndef _STK_FEAT_MAGNETICLINE_ENTITY_H_
#define _STK_FEAT_MAGNETICLINE_ENTITY_H_

#ifndef __MOBILE__
#pragma once
#endif

#include "Stk_Entity.h"
#include "Stk_Enum.h"
#include "Stk_File.h"

/****************************************************************************
	 *	@class	Stk_Feat_MagneticLine
	 *	@brief	磁力线特征类
	 *
	 *	创建用于存储磁力线特征的类库。<br>
	 *	继承自Stk_Entity 类。
 ****************************************************************************/

class DATAMANAGER_API Stk_Feat_MagneticLine :
	public Stk_Entity
{
private:
	STK_PNT32					m_pntStart;			//!< 起点
	STK_PNT32					m_pntEnd;			//!< 终点
	STK_BOOL					m_bEffective;		//!< 是否启用
	StkMagneticArrangementEnum	m_eArrangement;		//!< 排列方式
	STK_RGBA32					m_rgbaMagneticLine;	//!< 磁力线颜色
public:
	/****************************************************************************
	 *	@brief		磁力线特征构造函数
	 *	@param[in]	无
	 *	@retval		无
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	Stk_Feat_MagneticLine();
	
	/****************************************************************************
	 *	@brief		磁力线特征析构函数
	 *	@param[in]	无
	 *	@retval		无
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	~Stk_Feat_MagneticLine();
public:
	/****************************************************************************
	 *	@brief		设置磁力线起始点
	 *	@param[in]	i_pntStart	起始点
	 *	@param[out]	无
	 *	@retval		STK_SUCCESS	设置成功
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_STATUS					SetStartPoint(STK_PNT32& i_pntStart);
	
	/****************************************************************************
	 *	@brief		获取磁力线起始点
	 *	@param[in]	无
	 *	@param[out]	无
	 *	@retval		起始点
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_PNT32					GetStartPoint();

	/****************************************************************************
	 *	@brief		设置磁力线终止点
	 *	@param[in]	i_pntEnd	终止点
	 *	@param[out]	无
	 *	@retval		STK_SUCCESS	设置成功
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_STATUS					SetEndPoint(STK_PNT32& i_pntEnd);
	
	/****************************************************************************
	 *	@brief		获取磁力线终止点
	 *	@param[in]	无
	 *	@param[out]	无
	 *	@retval		终止点
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_PNT32					GetEndPoint();

	/****************************************************************************
	 *	@brief		设置磁体是否有效
	 *	@param[in]	i_bEffective	是否有效
	 *	@param[out]	无
	 *	@retval		STK_SUCCESS		设置成功
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_STATUS					SetEffective(STK_BOOL i_bEffective);
	
	/****************************************************************************
	 *	@brief		磁体是否有效
	 *	@param[in]	无
	 *	@param[out]	无
	 *	@retval		是否有效
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_BOOL					IsEffective();

	/****************************************************************************
	 *	@brief		设置磁力线关联的要素的排列方式
	 *	@param[in]	i_eArrangement	排列方式
	 *	@param[out]	无
	 *	@retval		STK_SUCCESS		设置成功
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_STATUS					SetArrangementType(StkMagneticArrangementEnum i_eArrangement);
	
	/****************************************************************************
	 *	@brief		获取磁力线关联的要素的排列方式
	 *	@param[in]	无
	 *	@param[out]	无
	 *	@retval		排列方式
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	StkMagneticArrangementEnum	GetArrangementType();

	/****************************************************************************
	 *	@brief		设置磁力线颜色
	 *	@param[in]	i_rgbaMagneticLine	磁力线颜色
	 *	@param[out]	无
	 *	@retval		STK_SUCCESS			设置成功
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_STATUS					SetColor(STK_RGBA32 i_rgbaMagneticLine);
	
	/****************************************************************************
	 *	@brief		获取磁力线颜色
	 *	@param[in]	无
	 *	@param[out]	无
	 *	@retval		磁力线颜色
	 *	@note		无
	 *	@attention	无
	 ****************************************************************************/
	STK_RGBA32					GetColor();

	/****************************************************************************
	 *	@brief		读取文件中的磁力线特征数据
	 *	@param[in]	i_FileP				文件对象指针
	 *	@param[in]	i_MagneticLineHeadP	PMI记录头指针
	 *	@param[out]	无
	 *	@retval		STK_SUCCESS			读取成功
	 *	@retval		STK_ERROR_MEMORY	内存申请失败
	 *	@retval		其他				读取失败
	 *	@note		无
	 *	@attention	内部接口
	 ****************************************************************************/
	STK_STATUS					ReadFile(Stk_File *i_FileP, StkSegmentHead *i_MagneticLineHeadP);
	
	/*****************************************************************************
	 *	@brief		写磁力线特征数据
	 *	@param[in]	i_stkFileP			文件对象指针
	 *	@param[out]	无
	 *	@retval		STK_SUCCESS			写入成功
	 *	@retval		其它				写入失败
	 *	@note		无
	 *	@attention	内部接口
	 ****************************************************************************/
	STK_STATUS					WriteFile(Stk_File *i_stkFileP);
};

#endif
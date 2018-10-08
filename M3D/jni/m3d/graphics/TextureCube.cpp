﻿#include "m3d/graphics/TextureCube.h"

#include "m3d/ResourceManager.h"

#include "prebuilt/soil/include/SOIL.h"
#include "m3d/utils/FileHelper.h"

namespace M3D
{

unsigned int TextureCube::LoadOGLTextureFromSixImage(vector<string>& filenames,
		int force_channels)
{

	unsigned char * image[6];
	int width[6];
	int height[6];
	int channels[6];

	for (int i = 0; i < 6; i++)

	{
		image[i] = SOIL_load_image(filenames.at(i).c_str(), &width[i],
				&height[i], &channels[i], force_channels);

		LOGI("CUBE IMAGE %s LOADED", filenames.at(i).c_str());
	}

	unsigned int cubeId;
	glGenTextures(1, &cubeId);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeId);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S,
			GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T,
			GL_CLAMP_TO_EDGE);
#ifdef __ANDROID__
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R_OES,
			GL_CLAMP_TO_EDGE);
#endif
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA, width[0],
			height[0], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA, width[1],
			height[1], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[1]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA, width[2],
			height[2], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[2]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA, width[3],
			height[3], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[3]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA, width[4],
			height[4], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[4]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA, width[5],
			height[5], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[5]);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	unsigned int OGLObj = cubeId;
	LOGI("cubeId is %d", cubeId);

	return OGLObj;
}

unsigned int TextureCube::LoadOGLTexture(const string& filename,
		const char face_order[6], int force_channels,
		unsigned int reuse_texture_ID, unsigned int flags)
{
	if (!FileHelper::FileExist(filename))
	{
		LOGE("CubeMapping fiel not exist");
	}

	unsigned char * image[6];
	int width[6];
	int height[6];
	int channels[6];

#ifdef __ANDROID__
	for (int i = 0; i < 6; i++)
		image[i] = SOIL_load_image(filename.c_str(), &width[i], &height[i],
				&channels[i], force_channels);

	unsigned int cubeId;
	glGenTextures(1, &cubeId);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubeId);

	// glBindTexture(GL_TEXTURE_2D,cubeId);
	LOGI("cubeId %d", cubeId);
	LOGI("filename.c_str() %s", filename.c_str());

	/*-------------------------------------cube map-------------------------------*/
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S,
			GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T,
			GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R_OES,
			GL_CLAMP_TO_EDGE);
	

    /*----------------------------------------------------------------------------------*/
//    	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R_OES, GL_CLAMP_TO_EDGE);
//
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width[0], height[0], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)image[0]);
	/*-------------------------------------cube map-------------------------------*/
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_OES, 0, GL_RGBA, width[0],
			height[0], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_OES, 0, GL_RGBA, width[1],
			height[1], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[1]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_OES, 0, GL_RGBA, width[2],
			height[2], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[2]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_OES, 0, GL_RGBA, width[3],
			height[3], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[3]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_OES, 0, GL_RGBA, width[4],
			height[4], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[4]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_OES, 0, GL_RGBA, width[5],
			height[5], 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*) image[5]);
	/*----------------------------------------------------------------------------------*/

	//  glTexGeniOES(0x2001,GL_TEXTURE_GEN_MODE_OES, GL_REFLECTION_MAP_OES);
	//glTexGeniOES(0x2002,GL_TEXTURE_GEN_MODE_OES, GL_REFLECTION_MAP_OES);
	unsigned int OGLObj = cubeId;
	LOGI("return OGLObj %d", OGLObj);
	return OGLObj;
    #endif
    
    return 0;
}

bool TextureCube::FreeOGLTexture(unsigned int OGLObj)
{
	bool freeState = false;

	return freeState;
}

TextureCube::TextureCube() :
		Texture()
{
	Init();
}

TextureCube::TextureCube(const string& imagePath) :
		Texture()
{
	Init();
	this->SetImagePath(imagePath);
}

TextureCube::TextureCube(vector<string>& imagePathes)
{
	Init();
	//for(int i=0;i<imagePathes.size();i++)

	m_imagePaths = imagePathes;

}

TextureCube::TextureCube(const string& imagePath, int forceChannels,
		unsigned int flags) :
		Texture()
{
	Init();

	this->SetImagePath(imagePath);

	this->SetImageParameter(forceChannels, flags);
}

TextureCube::~TextureCube()
{

}

void TextureCube::Init()
{
	m_imagePath = "";
	m_image = NULL;
	this->m_textures[0] = 0;

	this->SetImageParameter(TEXTURE_LOAD_RGBA, TEXTURE_FLAG_MIPMAPS);
	this->MarkDirty();
}

void TextureCube::UpdataOGLObj()
{
	//路径有值，根据路径去生成纹理
	if(m_imagePaths.size() > 0)
	{
//	if (m_imagePath.length() > 0)//一个纹理的
//	{
		ResourceManager* resourceMgr = this->m_resourceMgr;

		unsigned int OGLObj = this->m_textures[0];
//		resourceMgr->GetOGLTexture(this->m_imagePath);
		//根据路径在资源管理器中没有找到资源，则创建OGL对象加入资源管理器中
		unsigned int objid = 0;
		if (OGLObj == 0)
		{
			char face_order[6] =
			{ 'N', 'S', 'W', 'E', 'U', 'D' };
			objid = LoadOGLTextureFromSixImage(m_imagePaths,m_forceChannels);//6个面的
			LOGI("OGLObj = LoadOGLTexture %d", objid);
			if (objid != 0)
			{
				resourceMgr->AddOGLTexture(m_imagePaths[0], objid);
				this->m_textures[0] = objid;
			}
			else
			{
				LOGE("create TextureCube error!!");
			}

		}

	}
}

}


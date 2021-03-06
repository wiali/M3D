﻿#include "m3d/renderer/gl10/GL10Context.h"
#include "sview/views/Parameters.h"
namespace M3D
{

GL10Context::GL10Context()
{
	this->initialized = false;
	m_deviceSupportMsaaNum = 0;
}

GL10Context::~GL10Context()
{

}

void GL10Context::OptimizeContext()
{
	if (!this->initialized)
	{
		this->initialized = true;
#ifdef _WIN32
		//检测多重采样支持情况
		int m_originalFBO = 0;
		glGetIntegerv(GL_FRAMEBUFFER_BINDING_EXT, &m_originalFBO);

		unsigned m_object = 0;
		unsigned m_frameBufferMS = 0;
		unsigned m_renderBufferColorMS = 0;
		unsigned m_renderBufferDepthMS = 0;

		unsigned m_subImageWidth = 20;
		unsigned m_subImageHeight = 20;

		if (RenderContext::CheckExtension("GL_EXT_framebuffer_object", glGetString(GL_EXTENSIONS)) == GL_TRUE)
		{
			if (RenderContext::CheckExtension("GL_EXT_packed_depth_stencil", glGetString(GL_EXTENSIONS)) == GL_TRUE)
			{
				IsFramebufferSupported = true;
			}
		}

		if (CheckExtension("GL_EXT_framebuffer_multisample", glGetString(GL_EXTENSIONS)) == GL_FALSE)
		{
			SVIEW::Parameters::Instance()->m_msaaNum = 0;
			return;
		}

		glGenFramebuffersEXT(1, &m_frameBufferMS);
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, m_frameBufferMS);

		glGenRenderbuffersEXT(1, &m_renderBufferColorMS);
		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, m_renderBufferColorMS);
		glRenderbufferStorageMultisampleEXT(GL_RENDERBUFFER_EXT, 4,
			GL_RGB, m_subImageWidth, m_subImageHeight);
		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, 0);
		glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT,
			GL_RENDERBUFFER_EXT, m_renderBufferColorMS);

		glGenRenderbuffersEXT(1, &m_renderBufferDepthMS);
		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, m_renderBufferDepthMS);
		glRenderbufferStorageMultisampleEXT(GL_RENDERBUFFER_EXT, 4,
			GL_DEPTH24_STENCIL8_EXT, m_subImageWidth, m_subImageHeight);
		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, 0);
		glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT,
			GL_RENDERBUFFER_EXT, m_renderBufferDepthMS);
		glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_STENCIL_ATTACHMENT_EXT,
			GL_RENDERBUFFER_EXT, m_renderBufferDepthMS);

		if (glCheckFramebufferStatusEXT(GL_FRAMEBUFFER_EXT) != GL_FRAMEBUFFER_COMPLETE_EXT)
		{
			glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
			//如果不支持多重采样，关闭
			m_deviceSupportMsaaNum = 0;
		}
		else
		{
			m_deviceSupportMsaaNum = 4;
		}

		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, 0);
		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

		glDeleteRenderbuffersEXT(1, &m_renderBufferColorMS);
		glDeleteRenderbuffersEXT(1, &m_renderBufferDepthMS);
		glDeleteFramebuffersEXT(1, &m_frameBufferMS);

		glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, m_originalFBO);
#endif
	}

	if (this->m_deviceSupportMsaaNum == 0)
	{
		SVIEW::Parameters::Instance()->m_msaaNum = 0;
	}
}

int GL10Context::GetContextType()
{
	return 1;
}

void GL10Context::GetDoublev(GLenum pname, double *params)
{
	float tM[16];
	glGetFloatv(pname, tM);
	for (int i = 0; i < 16; i++)
	{
		params[i] = tM[i];
	}
}

void GL10Context::GetFloatv(GLenum pname, float *params)
{
	glGetFloatv(pname, params);
}

void GL10Context::GetDoublev(GLenum pname, Matrix4& m)
{
	// this->GetDoublev(pname,*m.m);
}
void GL10Context::GetFloatv(GLenum pname, Matrix4& m)
{
	this->GetFloatv(pname, (float*) m.Data());
}

}

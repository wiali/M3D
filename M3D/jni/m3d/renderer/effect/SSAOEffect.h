#ifndef M3D_SSAO_EFFECT_H_
#define M3D_SSAO_EFFECT_H_
#include "m3d/renderer/effect/Effect.h"
#include "m3d/graphics/HardWareFrameBuffer.h"
namespace M3D
{
	/************************************************************************/
	/*        屏幕空间环境光遮蔽，测试用。根据threejs上的方法实现，效果不好。可采用延迟着色中
	常用的方法来实现*/
	/************************************************************************/
	class M3D_API SSAOEffect:public Effect
	{
	public:
		SSAOEffect(RenderAction* action);
		void Render();
		void Render(RenderQueue* RenderStateQueue);
		void ClearResource();
		void SetSize(int w, int h);
		GLint GetSSAOTextureObject();
		GeometryBuffer* GetSSAOTexture();
	private:
		void RenderModel(RenderQueue * RenderStateArray);
		void RenderSSAO();
		void RenderBlur();
		//void RenderGaussianBlurWidth();
		//void RenderGaussianBlurHeight();
		void InnerRender(vector<RenderQueue*>& RenderStateArray);

		void DrawFrameBufferDebug();
	private:
		bool m_firstTime;
		GLuint m_ssaoTextureObj;
		GeometryBuffer* m_ssaoTexture;
	};
}
#endif//M3D_SSAO_EFFECT_H_
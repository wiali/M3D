//
//  StlWriter.h
//  M3D
//
//  Created by administrator on 15/3/2.
//  Copyright (c) 2015年 hoteam. All rights reserved.
//

#ifndef __M3D__SceneLoader__
#define __M3D__SceneLoader__
#include "m3d/M3D.h"
#include "Writer.h"
 
namespace SVIEW
{
	class View;

    class M3D_API SceneLoader{
    public:
		SceneLoader(View* view);
        virtual ~SceneLoader();
 
		void Load(const string &sceneInfo);
		void Loadbackground(const string& backgrondInfo);
		//void Loadbackground(const string& backgrondInfo);
		//void Loadbackground(const string& backgrondInfo);
	private:
		View* m_view;
    };
}

#endif /* defined(__M3D__StlWriter__) */

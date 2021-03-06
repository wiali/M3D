
MY_PATH := $(call my-dir)
LOCAL_PATH := $(MY_PATH)
#加载uuid的prebuilt
include $(CLEAR_VARS)
LOCAL_MODULE := uuid
LOCAL_SRC_FILES := prebuilt/uuid/libuuid.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/prebuilt/uuid/include
include $(PREBUILT_STATIC_LIBRARY)

#加载svl的prebuilt
include $(CLEAR_VARS)
LOCAL_MODULE := svlLib
LOCAL_SRC_FILES := prebuilt/svl2/libsvlLib.a
#LOCAL_SRC_FILES := prebuilt/svl2/libsvlLib.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/prebuilt/svl2/include
include $(PREBUILT_STATIC_LIBRARY)
#include $(PREBUILT_SHARED_LIBRARY)

#1.需要加载的库的预编译
#加载svlx的prebuilt
include $(CLEAR_VARS)
LOCAL_MODULE := SVLLib2
LOCAL_SRC_FILES := prebuilt/SVLLib2/libSVLLib2.a
#LOCAL_SRC_FILES := prebuilt/SVLLib2/libSVLLib2.so
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/prebuilt/SVLLib2/include
include $(PREBUILT_STATIC_LIBRARY)

#加载freetype的prebuilt
include $(CLEAR_VARS)
LOCAL_MODULE := freetypeLib
LOCAL_SRC_FILES := prebuilt/freetype/libFreetypeLib.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/prebuilt/freetype/include
include $(PREBUILT_STATIC_LIBRARY)

#加载SOIL图片解析为GL纹理库
include $(CLEAR_VARS)
LOCAL_MODULE := libSOIL
LOCAL_SRC_FILES := prebuilt/soil/libSOIL.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/prebuilt/soil/include
include $(PREBUILT_STATIC_LIBRARY)

#加载assimp的prebuilt
include $(CLEAR_VARS)
LOCAL_MODULE := libassimp
LOCAL_SRC_FILES := prebuilt/assimp/libassimp_static.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/prebuilt/assimp/include
include $(PREBUILT_STATIC_LIBRARY)

#编译SviewCore
include $(CLEAR_VARS) 
LOCAL_MODULE    := M3D
#加载路径下所有要编译的资源
#LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
#LOCAL_C_INCLUDES += $(shell ls -FR $(LOCAL_C_INCLUDES) | grep $(LOCAL_PATH)/$ )
#LOCAL_C_INCLUDES := $(LOCAL_C_INCLUDES:$(LOCAL_PATH)/%:=$(LOCAL_PATH)/%)

LOCAL_C_INCLUDES += $(LOCAL_PATH)/m3d/render/include		
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/assimp/include	
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/svl2/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/svl2/include/3rdParty/7Zip
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/svl2/include/3rdParty/LZ4
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/assimp/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/uuid/include		
#2.增加预编译头文件路径
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/SVLLib2/include	
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/SVLLib2/include/rapidjson
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/SVLLib2/include/SVLLib
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/SVLLib2/include/rapidjson
LOCAL_C_INCLUDES += $(LOCAL_PATH)/prebuilt/rapidjson
 #-Wno-psabi to remove warning about GCC 4.4 va_list warning
 
 
 ifeq ($(APP_OPTIM),debug)
  APP_CFLAGS := -O0 -g $(APP_CFLAGS)
  LOCAL_CPPFLAGS:=-O0 -g $(LOCAL_CPPFLAGS)
else
  APP_CFLAGS := -O2 -DNDEBUG -g $(APP_CFLAGS)
  LOCAL_CPPFLAGS := -O2 -DNDEBUG -g $(LOCAL_CPPFLAGS)
endif
 
LOCAL_CFLAGS += -D__ANDROID__ -DFT2_BUILD_LIBRARY -Wno-psabi -DDEBUG
LOCAL_CPPFLAGS += -D__ANDROID__ -DFT2_BUILD_LIBRARY

LOCAL_CFLAGS += -D__MOBILE__
LOCAL_CPPFLAGS += -D__MOBILE__

LOCAL_CFLAGS += -D__ANDROID__
LOCAL_CPPFLAGS += -D__ANDROID__

LOCAL_CPPFLAGS += -DJSON_IS_AMALGAMATION -fexceptions 
#IOSTODO 为IOS没有完全移植暂时定义
LOCAL_CFLAGS += -D__IOSTODO__ -DGL_GLEXT_PROTOTYPES -DGL_EGLEXT_PROTOTYPES
LOCAL_CPPFLAGS += -D__IOSTODO__ -DDEBUG

LOCAL_CFLAGS += -D_UNICODE
LOCAL_CPPFLAGS += -D_UNICODE


LOCAL_CFLAGS += -DSVLLIB_EXPORT
LOCAL_CPPFLAGS += -DSVLLIB_EXPORT

LOCAL_CFLAGS += -DRAPIDJSON_HAS_STDSTRING
LOCAL_CPPFLAGS += -DRAPIDJSON_HAS_STDSTRING


LOCAL_LDLIBS    := -llog -lGLESv1_CM -lGLESv2 -ldl -lz -luuid
LOCAL_ARM_MODE  := arm
#3.增加需要编译的静态库
LOCAL_STATIC_LIBRARIES := svlLib freetypeLib libassimp SVLLib2 uuid

LOCAL_SRC_FILES +=\
 animation\AnimationControl\animationController.cpp\
		 animation\AnimationControl\animationControlParser.cpp\
 		animation\AnimationControl\animationNode.cpp\
 		animation\SimulationAnimation\AnimationSound.cpp\
 		animation\SimulationAnimation\AnimationStepManager.cpp\
 		animation\SimulationAnimation\AnimationAPI.cpp\
 		animation\SimulationAnimation\CProcess.cpp\
 		animation\SimulationAnimation\Group.cpp\
 		animation\SimulationAnimation\GroupItem.cpp\
 		animation\simulationAnimation\GroupManager.cpp\
 		animation\SimulationAnimation\IOSExternDef.cpp\
 		animation\SimulationAnimation\KeyFrame.cpp\
 		animation\SimulationAnimation\Mutex.cpp\
 		animation\SimulationAnimation\ProcessManager.cpp\
 		animation\SimulationAnimation\SAnimation.cpp\
 		animation\SimulationAnimation\SBehaviorAction.cpp\
 		animation\SimulationAnimation\SimulationAnimationManager.cpp\
 		animation\SimulationAnimation\SInterpolator.cpp\
 		animation\SimulationAnimation\stdafx.cpp\
 		animation\SimulationAnimation\STimeline.cpp\
		 animation\SimulationAnimation\TickTimer.cpp\
		 animation\SimulationAnimation\CTimer.cpp \
		 animation\SimulationAnimation\TimerManager.cpp\
		animation\SimulationCommon\MatrixOperation.cpp\
 		animation\SimulationCommon\SATools.cpp\
 		animation\SimulationCommon\SAUtility.cpp\
		 animation\SimulationCommon\utf_utils.cpp\
 		animation\SimulationCommon\UtilityTextParser.cpp\
 		animation\SimulationCommon\UtilityXMLParser.cpp\
 		animation\SimulationCommon\vhash.cpp\
 	animation\SimulationCommon\vlist.cpp\
	animation\SimulationAnimationPlay\AnimationHelper.cpp \
    animation\SimulationAnimationPlay\AnimationPlayApi.cpp \
    animation\SimulationAnimationPlay\AnimationCallBack.cpp\
    animation\SimulationAnimationPlay\AnimationCallBackFunction.cpp\
    m3d\ResourceManager.cpp \
    m3d\action\Action.cpp \
    m3d\action\CallBackAction.cpp \
    m3d\action\RayPickAction.cpp \
    m3d\action\RenderAction.cpp \
    m3d\base\AreaAllocator.cpp \
    m3d\base\Any.cpp \
    m3d\base\Holder.cpp \
    m3d\base\BoundingBox.cpp \
    m3d\base\Color.cpp \
    m3d\base\ControlInfo.cpp \
    m3d\base\CTimer.cpp \
    m3d\base\event\BaseEvent.cpp \
    m3d\base\event\CameraEvent.cpp \
    m3d\base\FileCacheManager.cpp \
    m3d\base\Frustum.cpp \
    m3d\base\glue\GlueObj.cpp \
    m3d\base\json\jsoncpp.cpp \
    m3d\base\Matrix3.cpp \
    m3d\base\Matrix3x4.cpp \
    m3d\base\Matrix4.cpp \
    m3d\base\Mutex.cpp \
    m3d\base\Object.cpp \
    m3d\base\Plane.cpp \
    m3d\base\poly2tri\common\shapes.cpp \
    m3d\base\poly2tri\sweep\advancing_front.cpp \
    m3d\base\poly2tri\sweep\cdt.cpp \
    m3d\base\poly2tri\sweep\sweep.cpp \
    m3d\base\poly2tri\sweep\sweep_context.cpp \
    m3d\base\Quaternion.cpp \
    m3d\base\Random.cpp \
    m3d\base\Ray.cpp \
    m3d\base\Rect.cpp \
    m3d\base\Sphere.cpp \
    m3d\base\StringHash.cpp \
    m3d\base\Thread.cpp \
    m3d\base\Vector2.cpp \
    m3d\base\Vector3.cpp \
    m3d\base\Vector4.cpp \
    m3d\base\Viewport.cpp \
    m3d\extras\measure\Measure.cpp \
    m3d\extras\measure\MeasureAngle.cpp \
    m3d\extras\measure\MeasureDistance.cpp \
    m3d\extras\measure\MeasureDiametre.cpp \
    m3d\extras\measure\MeasureFactory.cpp \
    m3d\extras\measure\MeasureGroup.cpp \
    m3d\extras\measure\MeasureProperty.cpp \
    m3d\extras\measure\MeasureTools.cpp \
    m3d\extras\measure\tools\GeometryHelper.cpp \
    m3d\extras\measure\tools\MeasureCalculateHelper.cpp \
    m3d\extras\measure\tools\MeasureDisplayHelper.cpp \
    m3d\extras\modelmanager\AddFileOperation.cpp \
    m3d\extras\modelmanager\CopyModelOperation.cpp \
    m3d\extras\modelmanager\DraggerCallbacks.cpp \
    m3d\extras\modelmanager\ModelAssemblyHelper.cpp \
    m3d\extras\modelmanager\ModelManager.cpp \
     m3d\extras\modelmanager\ExplosionDragerCallBack.cpp \
    m3d\extras\modelmanager\MoveModelOperation.cpp \
    m3d\extras\modelmanager\RemoveModelOperation.cpp \
    m3d\extras\modelmanager\RenameOperation.cpp \
     m3d\extras\modelmanager\ReplaceModelOperation.cpp \
    m3d\extras\note\NoteFactory.cpp \
    m3d\extras\note\NoteGroup.cpp \
    m3d\extras\note\SequenceNumberNote.cpp \
    m3d\extras\note\TextNote.cpp \
    m3d\extras\note\ThreeDGesturesNote.cpp \
    m3d\extras\note\VoiceNote.cpp \
    m3d\extras\Operation.cpp \
    m3d\extras\OperationHistoryManager.cpp \
    m3d\extras\annotation\Annotation.cpp \
    m3d\extras\annotation\AnnotationDisplayHelper.cpp \
    m3d\extras\annotation\AnnotationFactory.cpp \
    m3d\extras\annotation\AnnotationGroup.cpp \
    m3d\graphics\AmbientLight.cpp \
    m3d\graphics\BaseLight.cpp \
    m3d\graphics\MaterialData.cpp \
    m3d\graphics\MaterialTemplateManager.cpp \
    m3d\graphics\BaseMaterial.cpp \
    m3d\graphics\Billboard.cpp \
    m3d\graphics\CameraNode.cpp \
    m3d\graphics\CrossSection.cpp \
    m3d\graphics\DirectionalLight.cpp \
    m3d\graphics\DirectionalLightShadow.cpp \
    m3d\graphics\GeometryBuffer.cpp \
    m3d\graphics\GPUObject.cpp \
     m3d\graphics\DepthMaterial.cpp \
    m3d\graphics\GraphicsDefs.cpp \
     m3d\graphics\HemisphereLight.cpp\
    m3d\graphics\HardWareFrameBuffer.cpp \
    m3d\graphics\HardWareIndexBuffer.cpp \
    m3d\graphics\HardWareRenderBuffer.cpp \
    m3d\graphics\HardWareVertexBuffer.cpp \
    m3d\graphics\ImageBoard.cpp \
    m3d\graphics\LightDraggerCallback.cpp\
    m3d\graphics\LightShadow.cpp \
    m3d\graphics\Material.cpp \
    m3d\graphics\MeshBoard.cpp \
    m3d\graphics\PbrMaterial.cpp \
    m3d\graphics\MatCapMaterial.cpp \
     m3d\graphics\InnerMaterial.cpp \
    m3d\graphics\PointLight.cpp \
    m3d\graphics\MovedMatrixInfo.cpp \
    m3d\graphics\Renderable.cpp \
    m3d\graphics\Resource.cpp \
    m3d\graphics\Section.cpp \
    m3d\graphics\ShaderMaterial.cpp \
    m3d\graphics\SpotLight.cpp \
    m3d\graphics\SectionGroupNode.cpp \
    m3d\graphics\SectionLine.cpp \
    m3d\graphics\SectionLineHelper.cpp \
    m3d\graphics\SectionPlane.cpp \
    m3d\graphics\TextNode.cpp \
    m3d\graphics\Texture.cpp \
    m3d\graphics\Texture2D.cpp \
    m3d\graphics\TextureCube.cpp \
    m3d\handler\Command.cpp \
    m3d\handler\Dragger.cpp \
    m3d\handler\DraggerManager.cpp \
    m3d\handler\Handler.cpp \
    m3d\handler\HandlerGroup.cpp \
    m3d\handler\HandlerNode.cpp \
    m3d\handler\HandlerPoint.cpp \
    m3d\handler\HandlerRotateCenter.cpp \
    m3d\handler\Projector.cpp \
    m3d\handler\RotateCylinderAxisDragger.cpp \
    m3d\handler\RotateCylinderDragger.cpp \
    m3d\handler\RotateSphereDragger.cpp \
    m3d\handler\Scale1DDragger.cpp \
    m3d\handler\Scale2DDragger.cpp \
    m3d\handler\ScaleAxisDragger.cpp \
    m3d\handler\Translate1DDragger.cpp \
    m3d\handler\Translate2DDragger.cpp \
     m3d\handler\Translate3DDragger.cpp \
    m3d\handler\TranslateAxisDragger.cpp \
    m3d\handler\TranslatePlaneDragger.cpp \
    m3d\handler\TranslateMinusAxisDragger.cpp \
    m3d\handler\TranslateBoxDragger.cpp \
    m3d\M3DMacros.cpp \
    m3d\model\ComText.cpp \
    m3d\model\CText.cpp \
    m3d\model\Curve.cpp \
    m3d\model\Edge.cpp \
    m3d\model\ExtendInfoManager.cpp \
    m3d\model\GeoAttribute.cpp \
    m3d\model\geometry\Cylinder.cpp \
    m3d\model\Image.cpp \
    m3d\model\Body.cpp \
    m3d\model\Face.cpp \
    m3d\model\IShape.cpp \
    m3d\model\Line3D.cpp \
    m3d\model\Model.cpp \
    m3d\model\ModelShape.cpp \
    m3d\model\LODData.cpp \
    m3d\model\MeshData.cpp \
    m3d\model\ModelView.cpp \
    m3d\model\Note.cpp \
    m3d\model\PMIData.cpp \
    m3d\model\Point.cpp \
    m3d\model\PolyLine.cpp \
    m3d\model\Shape.cpp \
    m3d\model\ShapeProperty.cpp \
    m3d\model\ShapeSet.cpp \
    m3d\renderer\LightManager.cpp \
    m3d\renderer\UniformHelper.cpp \
    m3d\renderer\effect\Effect.cpp \
    m3d\renderer\effect\EffectManager.cpp \
    m3d\renderer\effect\JewelEffect.cpp \
    m3d\renderer\effect\OutlineEffect.cpp \
    m3d\renderer\effect\SAOEffect.cpp \
    m3d\renderer\effect\SSAOEffect.cpp \
    m3d\renderer\effect\XRayEffect.cpp\
    m3d\renderer\gl10\GL10Context.cpp \
    m3d\renderer\gl10\GLDrawer.cpp \
    m3d\renderer\gl10\GLShapeDrawer.cpp \
    m3d\renderer\gl20\GL20Context.cpp \
    m3d\renderer\gl20\GLDrawer20.cpp \
    m3d\renderer\gl20\GLRenderTarget.cpp \
    m3d\renderer\gl20\GLShapeDrawer20.cpp \
    m3d\renderer\gl20\GLShapeDrawerHelper.cpp \
    m3d\renderer\gl20\Shader.cpp \
    m3d\renderer\gl20\ShaderManager.cpp \
    m3d\renderer\gl20\ShaderParameter.cpp \
    m3d\renderer\gl20\ShaderProgram.cpp \
    m3d\renderer\gl20\ShaderSrcCode.cpp \
    m3d\renderer\gl20\ShaderChunk.cpp \
    m3d\renderer\gl20\ShaderLib.cpp \
    m3d\renderer\RenderContext.cpp \
    m3d\RenderManager.cpp \
    m3d\SceneManager.cpp \
    m3d\scene\AxisNode.cpp \
    m3d\scene\GroundNode.cpp \
    m3d\scene\BackgroundNode.cpp \
    m3d\scene\FPSNode.cpp \
    m3d\scene\GroupNode.cpp \
    m3d\scene\Octree.cpp \
    m3d\scene\OctreeQuery.cpp \
    m3d\scene\SceneGroundNode.cpp \
    m3d\scene\SceneNode.cpp \
    m3d\scene\SectionNode.cpp \
    m3d\scene\ShapeNode.cpp \
    m3d\scene\CameraGroup.cpp \
    m3d\scene\LightGroup.cpp \
	m3d\scene\ScreenUILayerGroup.cpp\
    m3d\section\SectionManager.cpp \
    m3d\utils\AnimationCreator.cpp \
    m3d\utils\CullerHelper.cpp \
    m3d\utils\FileHelper.cpp \
    m3d\utils\IDCreator.cpp \
    m3d\utils\ImageHelper.cpp \
    m3d\utils\M3DTools.cpp \
    m3d\utils\MemoryHelper.cpp \
    m3d\utils\mem_leak_detector.cpp \
    m3d\utils\MeshHelper.cpp \
    m3d\utils\MeshTools.cpp \
    m3d\utils\PathHelper.cpp \
    m3d\utils\Platform.cpp \
    m3d\utils\ShapeHelper.cpp \
    m3d\utils\StringHelper.cpp \
    m3d\utils\Trackball.cpp \
    sview\extern\AnimationOperator.cpp \
    sview\extern\BaseAnimation.cpp \
    sview\extern\ExplosiveViewOperator.cpp \
    sview\extern\NormalAnimation.cpp \
    sview\extern\PerspectiveData.cpp \
    sview\extern\PerspectiveOperator.cpp \
    sview\extern\SectionOperator.cpp \
    sview\extern\SpecialEffectOperator.cpp \
    sview\extern\ViewOperator.cpp \
    sview\extern\WorkNodes.cpp \
    sview\io\AssimpReader.cpp \
    sview\io\MatrixOperation.cpp \
    sview\io\Reader.cpp \
    sview\io\SceneLoader.cpp \
    sview\io\StlWriter.cpp \
    sview\io\SVL1ToSVL2.cpp \
    sview\io\SVL2AsynReader.cpp \
    sview\io\Svlreader.cpp \
    sview\io\SVLVersionConvertIF.cpp \
    sview\io\SvlWriter.cpp \
    sview\io\SVLXWriter.cpp \
    sview\io\Writer.cpp \
    sview\io\XmlSceneSerializer.cpp \
    sview\manipulator\CommonTouchHandler.cpp \
    sview\manipulator\DraggerHandler.cpp \
    sview\manipulator\OribitControlHandler.cpp \
    sview\manipulator\TouchHandler.cpp \
    sview\manipulator\WalkthroughHandler.cpp \
    sview\pmiAnalysis\PMICreator.cpp \
    sview\pmiAnalysis\PMIUtilityLib.cpp \
    sview\pmiAnalysis\SVLXPMICreator.cpp \
    sview\pmiAnalysis\SVLXPMIUtilityLib.cpp \
    sview\pmiAnalysis\TessCircle.cpp \
    sview\pmiAnalysis\TessSvlxCircle.cpp \
    sview\pmiAnalysis\toolkit\MathGeolib.cpp \
    sview\pmiAnalysis\toolkit\MathVector.cpp \
    sview\pmiAnalysis\toolkit\PMIESymbol.cpp \
    tinyxml\tinyxml2.cpp \
    sview\utils\SAES.cpp \
    sview\utils\SAESHelper.cpp \
    sview\utils\ViewHelper.cpp \
    sview\views\IView.cpp \
    sview\views\LicenseManager.cpp \
    sview\views\Parameters.cpp \
    sview\views\Selector.cpp \
    sview\views\View.cpp \
    Utility.cpp\
#include $(BUILD_SHARED_LIBRARY) 
include $(BUILD_STATIC_LIBRARY)


# The ARMv7 is significanly faster due to the use of the hardware FPU
APP_ABI := armeabi-v7a
APP_PLATFORM := android-8
APP_CPPFLAGS += -frtti
APP_CPPFLAGS += -fexceptions
APP_STL := gnustl_static
APP_MODULES := FreetypeLib
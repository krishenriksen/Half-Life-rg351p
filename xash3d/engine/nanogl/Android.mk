# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := NanoGL

include $(XASH3D_CONFIG)

LOCAL_CFLAGS += -D__MULTITEXTURE_SUPPORT__

LOCAL_C_INCLUDES := $(LOCAL_PATH)/GL

LOCAL_SRC_FILES := \
	nanogl.cpp \
	nanoWrap.cpp \
	eglwrap.cpp

LOCAL_LDLIBS := -llog

include $(BUILD_STATIC_LIBRARY)


/*
 * Copyright (c) 2023 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */
#ifndef DRM_FRAMEBUFFER_BASE_H
#define DRM_FRAMEBUFFER_BASE_H

#include <stdlib.h>
#include <stdio.h>
#include <mutex>

#include "DrmTypes.h"
#include "BasicTypes.h"


/* buffer for display or render.*/

class DrmFramebufferBase {
public:
    DrmFramebufferBase();
    virtual ~DrmFramebufferBase();

    virtual int32_t setAcquireFence(int32_t fenceFd);
    virtual int32_t getAcquireFenceFd();
    virtual void setBufferInfo(int fd, int32_t acquireFence);
    virtual void reset();
    virtual bool haveValidBuffer() {return true;}
    virtual bool isAfbcBuffer() {return false;}

public:
    virtual const char * getDebugInfo() {return mDebugInfo;}

    virtual int getVideoType() {return 0;}
    virtual int getBufferFd() {return mFd;}

    drm_fb_type_t getFbType();
    virtual int32_t setFbType(drm_fb_type_t type);

    virtual drm_rect_t getDisplayFrame();
    virtual int32_t setDisplayFrame(drm_rect_t dispFrame);

    virtual drm_rect_t getSourceCrop();
    virtual int32_t setSourceCrop(drm_rect_t crop);

    virtual drm_blend_mode_t getBlendMode() {return mBlendMode;}
    virtual int32_t setBlendMode (drm_blend_mode_t mode);

    float getPlaneAlpha() {return mPlaneAlpha; }
    virtual int32_t setPlaneAlpha(float alpha);

    int32_t getTransform() {return mTransform; }
    virtual int32_t setTransform(int32_t transform);

    uint32_t getZorder() {return mZorder; }
    virtual int32_t setZorder(uint32_t z);

    int32_t getDataspace() {return mDataspace; }
    virtual int32_t setDataspace(int32_t data);

    bool getSecureFlag() {return mSecure; }
    virtual int32_t setSecureFlag(bool flag);

    int32_t getCompositionType() {return mCompositionType;}
    virtual void setCompositionType(int32_t type) {mCompositionType = type;};

//protected:
public:
    int mFd;
    drm_fb_type_t mFbType;
    drm_rect_t mDisplayFrame;
    drm_rect_t mSourceCrop;
    drm_blend_mode_t mBlendMode;
    int32_t mCompositionType;
    float mPlaneAlpha;
    int32_t mTransform;
    uint32_t mZorder;
    int32_t mDataspace;
    bool mSecure;

    bool mUpdated;

    char mDebugInfo[32];

    std::mutex mMutex;
};

#endif/*DRM_FRAMEBUFFER_BASE_H*/

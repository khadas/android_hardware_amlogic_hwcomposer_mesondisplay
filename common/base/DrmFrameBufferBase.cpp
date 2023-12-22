/*
 * Copyright (c) 2023 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#include "DrmFrameBufferBase.h"

DrmFramebufferBase::DrmFramebufferBase() {
    snprintf(mDebugInfo, 32, "DrmFramebufferBase");
    reset();
}

DrmFramebufferBase::~DrmFramebufferBase() {
    if (mFd >= 0)
        close(mFd);

    mFd = -1;
}

int32_t DrmFramebufferBase::setAcquireFence(int32_t fenceFd) {
    UNUSED(fenceFd);
    return 0;
}

int32_t DrmFramebufferBase::getAcquireFenceFd() {
    return -1;
}

void DrmFramebufferBase::setBufferInfo(int fd, int32_t acquireFence) {
    mFd = fd;
    UNUSED(acquireFence);
}

void DrmFramebufferBase::reset() {
    mFd              = -1;
    mFbType          = DRM_FB_UNDEFINED;
    mBlendMode       = DRM_BLEND_MODE_INVALID;
    mCompositionType = 0; //MESON_COMPOSITION_UNDETERMINED
    mPlaneAlpha      = 1.0;
    mTransform       = 0;
    mZorder          = 0xFFFFFFFF; //set to special value for debug.
    mDataspace       = 0;
    mUpdated         = false;

    memset(&mDisplayFrame, 0, sizeof(mDisplayFrame));
    memset(&mSourceCrop, 0, sizeof(mSourceCrop));
}

drm_fb_type_t DrmFramebufferBase::getFbType() {
    std::lock_guard<std::mutex> lock(mMutex);
    return mFbType;
}

int32_t DrmFramebufferBase::setFbType(drm_fb_type_t type) {
    std::lock_guard<std::mutex> lock(mMutex);
    mFbType = type;
    mUpdated = true;

    return 0;
}

drm_rect_t DrmFramebufferBase::getDisplayFrame() {
    std::lock_guard<std::mutex> lock(mMutex);
    return mDisplayFrame;
}

int32_t DrmFramebufferBase::setDisplayFrame(drm_rect_t dispFrame) {
    std::lock_guard<std::mutex> lock(mMutex);
    mDisplayFrame = dispFrame;

    return 0;
}

drm_rect_t DrmFramebufferBase::getSourceCrop() {
    std::lock_guard<std::mutex> lock(mMutex);

    return mSourceCrop;
}

int32_t DrmFramebufferBase::setSourceCrop(drm_rect_t crop) {
    std::lock_guard<std::mutex> lock(mMutex);
    mSourceCrop = crop;
    mUpdated = true;

    return 0;
}

int32_t DrmFramebufferBase::setPlaneAlpha(float alpha) {
    mPlaneAlpha = alpha;
    mUpdated = true;

    return 0;
}

int32_t DrmFramebufferBase::setTransform(int32_t transform) {
    mTransform = transform;
    mUpdated = true;

    return 0;
}

int32_t DrmFramebufferBase::setZorder(uint32_t z) {
    mZorder = z;
    mUpdated = true;

    return 0;
}

int32_t DrmFramebufferBase::setDataspace(int32_t dataSpace) {
    mDataspace = dataSpace;
    mUpdated = true;

    return 0;
}
int32_t DrmFramebufferBase::setSecureFlag(bool flag) {
    mSecure = flag;
    mUpdated = true;

    return 0;
}

int32_t DrmFramebufferBase::setBlendMode (drm_blend_mode_t mode) {
    mBlendMode = mode;
    mUpdated = true;

    return 0;
}


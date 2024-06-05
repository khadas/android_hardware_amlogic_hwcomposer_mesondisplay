/*
 * Copyright (c) 2021 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#define LOG_NDEBUG 1
#define UVM_DETACH_HOLD_MAX_BUFFER (8)

#include <MesonLog.h>
#include "UvmDetach.h"
#include "HwcConfig.h"

UvmDetach::UvmDetach(hwc2_layer_t layerId) {
    snprintf(mName, 20, "layer-%d", (int)layerId);
    mUvmBufferQueue.clear();
    mEnable = true;
}

UvmDetach::UvmDetach(int tunnelId) {
    snprintf(mName, 20, "layer-%d", tunnelId);
    mUvmBufferQueue.clear();
    mEnable = true;
}

UvmDetach::~UvmDetach() {
    releaseUvmResource();
}

int32_t UvmDetach::getVideoInfo(struct uvm_fd_info & videoInfo) {
    return UvmDev::getInstance().getVideoInfo(videoInfo);
}

int32_t UvmDetach::setEnable(bool enable) {
    MESON_LOGV("%s, setEnable %s", __func__, enable ? "true" : "false");
    mEnable = enable;
    return 0;
}

int32_t UvmDetach::attachUvmBuffer(int bufferFd) {
    if (bufferFd < 0)
        return -1;

    if (HwcConfig::UvmDetachEnabled() && mEnable) {
        return UvmDev::getInstance().attachBuffer(bufferFd);
    } else {
        return 0;
    }
}

int32_t UvmDetach::detachUvmBuffer() {
    if (HwcConfig::UvmDetachEnabled() && mEnable) {
        int signalCount = 0;
        if (mUvmBufferQueue.size() <= 0)
            return -EAGAIN;

        for (auto it = mUvmBufferQueue.begin(); it != mUvmBufferQueue.end(); it++) {
            auto currentStatus = it->releaseFence->getStatus();
            /* fence was signal */
            if (currentStatus == DrmFence::Status::Invalid ||
                currentStatus == DrmFence::Status::Signaled)
                signalCount ++;
        }

        MESON_LOGV("%s: %s UvmBufferQueue size:%zu, signalCount:%d",
                __func__, mName, mUvmBufferQueue.size(), signalCount);

        while (signalCount > 0) {
            auto item = mUvmBufferQueue.front();
            MESON_LOGV("%s: %s bufferFd:%d, fenceStatus:%d",
                    __func__, mName, item.bufferFd, item.releaseFence->getStatus());

            UvmDev::getInstance().detachBuffer(item.bufferFd);
            if (item.bufferFd >= 0)
                close(item.bufferFd);

            mUvmBufferQueue.pop_front();

            signalCount --;
        }
    }

    return 0;
}

int32_t UvmDetach::collectUvmBuffer(const int fd, const int fenceFd) {
    if (HwcConfig::UvmDetachEnabled() && mEnable) {
        if (fd < 0) {
            MESON_LOGV("%s: %s get an invalid fd", __func__, mName);
            if (fenceFd >=0 )
                close(fenceFd);

            return -EINVAL;
        }

        if (fenceFd < 0) {
            MESON_LOGV("%s: %s get an invalid fenceFd", __func__, mName);
            UvmDev::getInstance().detachBuffer(fd);
            close(fd);
            return 0;
        }

        if (mUvmBufferQueue.size() >= UVM_DETACH_HOLD_MAX_BUFFER) {
            int count = mUvmBufferQueue.size() - UVM_DETACH_HOLD_MAX_BUFFER;
            for (int i = 0; i <= count; i++) {
                auto item = mUvmBufferQueue.front();
                if (item.bufferFd >= 0)
                    close(item.bufferFd);

                mUvmBufferQueue.pop_front();
            }
        }

        UvmBuffer item = {fd, std::move(std::make_shared<DrmFence>(fenceFd))};
        mUvmBufferQueue.push_back(item);
    } else {
        if (fd >= 0) {
            close(fd);
        }
        if (fenceFd >= 0) {
            close(fenceFd);
        }
    }

    return 0;
}

int32_t UvmDetach::releaseUvmResource() {
    if (HwcConfig::UvmDetachEnabled()) {
        for (auto it = mUvmBufferQueue.begin(); it != mUvmBufferQueue.end(); it++) {
            if (it->bufferFd >= 0)
                close(it->bufferFd);
        }
        mUvmBufferQueue.clear();
    }

    return 0;
}


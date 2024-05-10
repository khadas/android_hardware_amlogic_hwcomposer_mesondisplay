/*
 * Copyright (c) 2021 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description:
 */

#ifndef HWC_UVM_DETACH_H
#define HWC_UVM_DETACH_H

#include <deque>
#include <hardware/hwcomposer2.h>

#include <DrmSync.h>

#include "UvmDev.h"

class UvmDetach {
public:
    UvmDetach(hwc2_layer_t layerId);
    UvmDetach(int tunnelId);
    ~UvmDetach();

    int32_t attachUvmBuffer(int bufferFd);
    int32_t detachUvmBuffer();
    int32_t collectUvmBuffer(const int fd, const int fence);
    int32_t releaseUvmResource();
    int32_t getVideoInfo(struct uvm_fd_info & videoInfo);
    int32_t setEnable(bool enable);

    char *getDebugName() {return mName;};

protected:
    char mName[20];

    struct UvmBuffer {
        int bufferFd;
        std::shared_ptr<DrmFence> releaseFence;
    };

    std::deque<UvmBuffer> mUvmBufferQueue;
    bool mEnable;
};
#endif /* HWC_UVM_DETACH_H */

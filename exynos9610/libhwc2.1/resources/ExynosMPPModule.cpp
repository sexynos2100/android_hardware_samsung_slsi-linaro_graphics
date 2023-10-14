/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ExynosMPPModule.h"
#include "ExynosHWCDebug.h"

ExynosMPPModule::ExynosMPPModule(uint32_t physicalType, uint32_t logicalType,
        const char *name, uint32_t physicalIndex, uint32_t logicalIndex,
        uint32_t preAssignInfo, uint32_t mppType)
    : ExynosMPP(physicalType, logicalType, name, physicalIndex, logicalIndex, preAssignInfo, mppType)
{
}

ExynosMPPModule::~ExynosMPPModule()
{
}

uint32_t ExynosMPPModule::getMPPClock()
{
    if (mPhysicalType == MPP_G2D)
        return 667000;
    else
        return 0;
}

bool ExynosMPPModule::isDataspaceSupportedByMPP(struct exynos_image &src, struct exynos_image &dst)
{
    if ((mLogicalType == MPP_LOGICAL_G2D_YUV) &&
        (hasHdrInfo(src)) && (dst.exynosFormat == HAL_PIXEL_FORMAT_YCBCR_P010) &&
        (src.dataSpace == dst.dataSpace))
        return false;
    return ExynosMPP::isDataspaceSupportedByMPP(src, dst);
}

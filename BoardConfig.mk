#
# Copyright (C) 2018 The LineageOS Project
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

DEVICE_PATH := device/lge/h930

# inherit from common v30
-include device/lge/joan-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := v30,joan,h930

# Kernel
TARGET_KERNEL_CONFIG := jolla-kernel_kr_defconfig

# inherit from the proprietary version
-include vendor/lge/h930/BoardConfigVendor.mk

# Used for build MultiROM recovery
BOARD_MKBOOTIMG_ARGS := --board mrom$(shell date -u +%Y%m%d)-00

# MultiROM
DEVICE_RESOLUTION := 1440x2560
TARGET_RECOVERY_IS_MULTIROM := true
MR_INPUT_TYPE := type_b
MR_INIT_DEVICES := device/lge/h930/multirom/mr_init_devices.c
MR_DPI := hdpi
MR_DPI_FONT := 220
MR_FSTAB := device/lge/h930/twrp.fstab
MR_USE_MROM_FSTAB := false
MR_KEXEC_MEM_MIN := 0x0
MR_DEVICE_HOOKS := device/lge/h930/multirom/mr_hooks.c
MR_DEVICE_HOOKS_VER := 6
MR_PIXEL_FORMAT := "ABGR_8888"
MR_DEFAULT_BRIGHTNESS := 149
MR_ENCRYPTION := false
#MR_ENCRYPTION := true
#MR_ENCRYPTION_SETUP_SCRIPT := device/lge/h930/multirom/mr_cp_crypto.sh
#MR_ENCRYPTION_FAKE_PROPERTIES := true

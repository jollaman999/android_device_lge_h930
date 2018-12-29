#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    "/sys/class/graphics/fb0",

    "/sys/block/sda",
    "/sys/block/sde",
    "/sys/devices/soc/1da4000.ufshc/",
    "/sys/devices/soc/1da4000.ufshc/host0/",
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/",
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/",
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/",
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/",
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/",
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde11", // boot
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda23", // cache
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde16", // modem
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda18", // persist
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda22", // system
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda24", // userdata
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda12", // encrypt
    "/sys/devices/soc/1da4000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda15", // ssd

    "/sys/bus/platform/devices/1da4000.ufshc",
    "/sys/bus/platform/drivers/ufshcd-qcom",
    "/sys/module/ufshcd",
    "/sys/module/ufshcd_pltfrm",

    "/sys/block/mmcblk0",

    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    "/sys/class/input/input0",
    "/sys/class/input/input0/event0",
    "/sys/class/input/input1",
    "/sys/class/input/input1/event1",
    "/sys/class/input/input2",
    "/sys/class/input/input2/event2",
    "/sys/class/input/input3",
    "/sys/class/input/input3/event3",
    "/sys/class/input/lge_fingerprint",
    "/sys/class/input/lge_fingerprint/event4",
    "/sys/class/input/input5",
    "/sys/class/input/input5/event5",
    
    // for adb
    "/sys/class/tty/ptmx",
    "/config/usb_gadget/g1/functions/ffs.adb",
    "/config/usb_gadget/g1/configs/b.1/f2",
    "/config/usb_gadget/g1/UDC",
    "/sys/bus/usb",

    // OTG
    "/sys/devices/soc/c0a4900.sdhci*",

    // Encryption
    "/sys/devices/virtual/misc/device-mapper",
    "/sys/devices/virtual/misc/ion",
    "/sys/devices/virtual/qseecom/qseecom",

    // exfat requires fuse device
    "/sys/devices/virtual/misc/fuse",

    NULL
};

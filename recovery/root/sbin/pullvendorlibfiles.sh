#!/sbin/sh

# This pulls the files out of /system/vendor that are needed for decrypt
# This allows us to decrypt the device in recovery and still be
# able to unmount /system when we are done.

if [ -e "/dev/block/platform/soc/1da4000.ufshc/by-name/vendor" ] ; then
  mkdir -p /vendor
  mount -t ext4 -o ro /dev/block/platform/soc/1da4000.ufshc/by-name/vendor /vendor
else
  mkdir -p /system
  mkdir -p /tmp/vendor_pull_lib

  mount -t ext4 -o ro /dev/block/platform/soc/1da4000.ufshc/by-name/system /system

  cp -Rp /system/vendor/lib64 /tmp/vendor_pull_lib

  umount /system

  ln -s /tmp/vendor_pull_lib /vendor
fi

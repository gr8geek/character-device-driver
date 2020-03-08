# character-device-driver
A simple linux character device driver
# Building the module
make -C /lib/modules/$(uname -r)/build M=$PWD modules

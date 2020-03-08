# character-device-driver
A simple linux character device driver
# Building the module
make -C /lib/modules/$(uname -r)/build M=$PWD modules


sudo insmod ./ex07_simple_module.ko


ls -l /dev/simple_char_device 


Note I would recommend first that we list all the character drivers currently in execution and
then appropriately decide the major number of the character device driver by making some minor changes and then rebuilding the module
ls -l /dev/simple_char_device 
Also the major number must be more than the major number of the character devices listed by the above command
sudo mknod -m 666 /dev/simple_char_device c 300 0
_____________
For viewing the functions calls use:
 sudo tail -f /var/log/syslog

For interacting with the driver use:
echo "I Am Iron Man!" >/dev/simple_char_device

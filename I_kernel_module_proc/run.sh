set -x
sudo rmmod hello.ko
make clean
make 
sudo dmesg -C
sudo insmod hello.ko
dmesg
sudo cat /proc/rf_status

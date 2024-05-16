

* EEPROM 原廠文件

https://www.dropbox.com/transfer/cap_pid_ft:AAAAAB_PxduPZYo6V5jqy5hk8NmJA1rnfJXmmtjizCH9tEDrnrIKW40

* rasp-config enable i2c
https://www.raspberrypi-spy.co.uk/2014/11/enabling-the-i2c-interface-on-the-raspberry-pi/

* i2cdump 
https://coldnew.github.io/f0528f55/

* 
https://lektiondestages.art.blog/2020/03/20/using-a-24c256-24lc256-eeprom-on-raspberry-pi-with-device-overlays/

*　將at24c256 加入device tree
(1) dtc -O dtb -o at24c256.dtbo -b 0 -@ at24c256.dts ; sudo  cp at24c256.dtbo  /boot/overlays
(2) sudo vim /boot/config.txt 加入這行
dtoverlay=at24c256


*　重開機後kernel log 可以看到
ruby@raspberrypi:~/git/raspberrypi_example/5_i2c $ dmesg |grep at24
[    9.390589] at24 1-0050: 32768 byte 24c256 EEPROM, writable, 64 bytes/write


*可以對EEPROM 當成檔案操作 
sudo hexdump /sys/class/i2c-dev/i2c-1/device/1-0050/eeprom


*Exercise:
寫一個程式類似産測可以寫入SN，MAC，Project code
(1) ./at24c256_16 -p "ODSCXXX" -m "2312323422" -s "ADFQDWQFWF"
(2) 也可以讀出寫入的SN，MAC，Project code
./at24c256_16 -r


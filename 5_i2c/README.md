

* EEPROM 原廠文件

https://www.dropbox.com/transfer/cap_pid_ft:AAAAAB_PxduPZYo6V5jqy5hk8NmJA1rnfJXmmtjizCH9tEDrnrIKW40

* rasp-config enable i2c
https://www.raspberrypi-spy.co.uk/2014/11/enabling-the-i2c-interface-on-the-raspberry-pi/

* i2cdump 
https://coldnew.github.io/f0528f55/

* 
https://lektiondestages.art.blog/2020/03/20/using-a-24c256-24lc256-eeprom-on-raspberry-pi-with-device-overlays/

dtc -O dtb -o at24c256.dtbo -b 0 -@ at24c256.dts ; sudo  cp at24c256.dtbo  /boot/overlays

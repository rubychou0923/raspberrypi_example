* youtube on i2c <br>
https://www.youtube.com/watch?v=5PP96eBzOjg<br>
https://www.youtube.com/watch?v=u62_Rjd5oMY<br>

* rasp-config enable i2c
https://www.raspberrypi-spy.co.uk/2014/11/enabling-the-i2c-interface-on-the-raspberry-pi/<br>

* i2cdump <br>
https://coldnew.github.io/f0528f55/<br>

* 
https://lektiondestages.art.blog/2020/03/20/using-a-24c256-24lc256-eeprom-on-raspberry-pi-with-device-overlays/<br>

*　將at24c256 加入device tree<br>
(1) dtc -O dtb -o at24c256.dtbo -b 0 -@ at24c256.dts ; sudo  cp at24c256.dtbo  /boot/overlays<br>
(2) sudo vim /boot/config.txt 加入這行<br>
dtoverlay=at24c256<br>


*　重開機後kernel log 可以看到<br>
ruby@raspberrypi:~/git/raspberrypi_example/5_i2c $ dmesg |grep at24<br>
[    9.390589] at24 1-0050: 32768 byte 24c256 EEPROM, writable, 64 bytes/write<br>


* 可以對EEPROM 當成檔案操作 <br>
sudo hexdump /sys/class/i2c-dev/i2c-1/device/1-0050/eeprom<br>


* Exercise:<br>
寫一個程式類似産測可以寫入SN，MAC，Project code　<br>
(1) ./at24c256_16 -p "ODSCXXX" -m "2312323422" -s "ADFQDWQFWF"<br>
(2) 也可以讀出寫入的SN，MAC，Project code<br>
./at24c256_16 -r<br>


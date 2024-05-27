
* spi
https://www.youtube.com/watch?v=0nVNwozXsIc

* UART/SPI/I2C
https://www.youtube.com/watch?v=UGKT2OPyz1U

* sudo raspi-config
3 Interface option -> I4 SPI enable

* /boot/config.txt 
found dtparam=spi=on

* reboot

* reference link
https://www.waveshare.com/wiki/Template:Raspberry_Pi_Guides_for_SPI_e-Paper

* #Open the Raspberry Pi terminal and run the following command
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.71.tar.gz
tar zxvf bcm2835-1.71.tar.gz
cd bcm2835-1.71/
sudo ./configure && sudo make && sudo make check && sudo make install
# For more information, please refer to the official website: http://www.airspayce.com/mikem/bcm2835/

* git clone https://github.com/waveshare/e-Paper.git
cd e-Paper/RaspberryPi_JetsonNano/
```
# At this point in the e-Paper/RaspberryPi_JetsonNano 
cd c
sudo make clean
sudo make -j4 EPD=epd2in13V4
```
Run the demo:
```
./epd
```


* python3 library
sudo apt-get update
sudo apt-get install python3-pip
sudo apt-get install python3-pil
sudo apt-get install python3-numpy
sudo pip3 install RPi.GPIO
sudo pip3 install spidev


* python library
sudo apt-get update
sudo apt-get install python-pip
sudo apt-get install python-pil
sudo apt-get install python-numpy
sudo pip install RPi.GPIO
sudo pip install spidev

* cd e-Paper/RaspberryPi_JetsonNano/python/examples/
python3 epd_2in13_V4_test.py 

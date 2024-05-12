#!/bin/sh


dd if=/dev/zero of=/tmp/zero.img bs=1 count=20
dd if=/tmp/zero.img of=/sys/bus/i2c/devices/1-0050/eeprom bs=1 count=20

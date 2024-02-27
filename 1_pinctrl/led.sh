#!/bin/bash

init=1
pinctrl set 2 op
pinctrl set 3 op
pinctrl set 4 op
pinctrl set 2 dl
pinctrl set 3 dl
pinctrl set 4 dl

while [ $init -eq 1 ]
do
pinctrl set 2 dh

sleep 1
pinctrl set 3 dh

sleep 1

pinctrl set 4 dh
sleep 1

pinctrl set 2 dl
pinctrl set 3 dl
pinctrl set 4 dl

sleep 1
done

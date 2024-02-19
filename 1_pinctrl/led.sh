#!/bin/bash

init=1
pinctrl set 2 op
pinctrl set 3 op
pinctrl set 4 op

while [ $init -eq 1 ]
do
pinctrl set 2 ip
pinctrl set 2 pu

sleep 1

pinctrl set 3 ip
pinctrl set 3 pu

sleep 1

pinctrl set 4 ip
pinctrl set 4 pu
sleep 1

pinctrl set 2 op
pinctrl set 3 op
pinctrl set 4 op

sleep 1
done
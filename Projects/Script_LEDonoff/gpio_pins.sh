#!/bin/bash 
#gave 2 arugments with file line eg [./gpio_pins <pin_number> <value>] eg[ ./gpio_pins 60 1]
argument=$#
if [ "$argument" -ne 2 ]
then 
  echo "please provide argument with this "
  exit 1
fi 
pin_number=$1
status=$2

cd /sys/class/gpio/gpio$1
fdirection="in"
dir=`cat direction`

if [ "$dir" == "$fdirection" ]
then
   echo out > direction
fi

if [ "$status" -ne 0 ]
then 
 echo 1 > value
else
 echo 0 > value
fi





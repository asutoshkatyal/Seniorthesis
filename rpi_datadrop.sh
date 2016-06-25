#!/bin/bash
#run  this script in the same directory that holds the text file
declare -i h_s=1
declare -i h_e=1
declare -i t_s=1
declare -i t_e=1
echo $hel
while test $h_s -le 30 #This is no of data points in the text file change this number as it fits to your needs

do

h_s=$h_s+1;
t_s=$t_s+4;
hel=$(<sensordata.txt) #change the name of the file
#$hel= `cat sensordata.txt` #name of the text file 

hum="$(echo $hel | cut -d ':' -f $h_s|cut -d ',' -f $h_e)"
echo $hum

temp="$(echo $hel | cut -d ',' -f $t_s|cut -d 'H' -f $t_e)"
echo $temp
echo $h_s


curl --data "humidity=$hum&temp=$temp" https://datadrop.wolframcloud.com/objects/6f90692b-7da4-417d-9b58-6839b9f0ce48

done

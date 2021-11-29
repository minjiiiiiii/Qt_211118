#!/bin/bash
#ssh ftp 
#Pre-requisite : make ssh-key and copy it to the server

server=192.168.0.192
user=jo
pass=1234
Port=21
ID=${1}
dir=Desktop/Ultrasound/

mkdir ./Ultrasound/
mkdir ./Ultrasound/${ID}
sftp jo@192.168.0.192 <<< "get -r ${dir}/${ID} ./Ultrasound/${ID}/"
#ftpget -P ${Port} -u ${user} -p ${pass} ${server} * ${dir}/${ID}

#!/bin/bash

saveIFS="$IFS"

error=0

assetsFolder="../media/"

for line in `cat .list`
do
    if [[ -f "$assetsFolder$line" ]]
    then
	echo -e "$assetsFolder$line : \033[32mOK\033[0m"
    else  
	echo -e "$assetsFolder$line : \033[31mMISSING\033[0m"
	wget --progress=bar:force -O "$assetsFolder$line" "https://indiestudio.000webhostapp.com/media/$line"
	sleep 1
	if [[ $? -eq 0 ]]
	then
	   echo -e "../$line : \033[33mDownloaded ...\033[0m"
	else   
	    echo -e "../$line : \033[31mNO INTERNET\033[0m"
	    let "error++"
	fi
    fi
done

if [[ ${error} -ne 0 ]]
then
    echo -e "\033[31mYou don't have all files needed to launch the game, try to correct your internet connection and retry\033[0m"
else
    cd .. && ./bomberman
fi

IFS="$savIFS"

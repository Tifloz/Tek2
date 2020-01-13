#!/usr/bin/env bash

saveIFS="$IFS"

error=0

assetsFolder="expected/"
dictionary="../ExampleDict"

rm .failed
for line in `cat .list`
do
    if [[ -f "$assetsFolder$line" ]]
    then
    `../autoCompletion ${dictionary} 2>/dev/null <${line} > res${line}`
        echo -e "\033[34m~~~~~~~~~~~~~~~~~~~\033[0m"
        echo -e "\033[93mSuject Test\033[0m"
        echo -e "\033[34m~~~~~~~~~~~~~~~~~~~\033[0m"
        if git --no-pager diff --no-index res${line} ${assetsFolder}${line} ;
        then
	    echo -e "$assetsFolder$line : \033[42mOK\033[0m"
        else
	    echo -e "$assetsFolder$line : \033[41mKO\033[0m"
	    echo ${line} >> .failed
	    fi

	sleep 1

	    echo -e "\033[34m~~~~~~~~~~~~~~~~~~~\033[0m"
	    echo -e "\033[93mExit Code\033[0m"
	    echo -e "$\033[34m~~~~~~~~~~~~~~~~~~~\033[0m"

	    if [[ $? -eq 0 ]]
	    then
	        echo -e "../$line : \033[42mNormal\033[0m"
	    else
	        echo -e "../$line : \033[41mERROR\033[0m"
	        let "error++"
	    fi
    fi
done

echo -e "\033[34m~~~~~~~~~~~~~~~~~~~\033[0m"
echo -e "\033[31m FAILED TESTS\033[0m"
echo -e "\033[34m~~~~~~~~~~~~~~~~~~~\033[0m"

cat .failed
IFS="$savIFS"

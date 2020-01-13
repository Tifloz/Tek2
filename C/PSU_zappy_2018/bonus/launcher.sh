#!/bin/bash
killall zappy_ai
read -p "Combien d'IA ? : " count
read -p "Quel port ? : " port
read -p "Team 1 : " name
read -p "Machine : " machine

cd ../src/AI && make

nb=1
while [[ ${nb} -lt ${count} ]]
do
    nohup ../../zappy_ai -p ${port} -n ${name} -h ${machine} &
    sleep 0.4s
    nb=`expr ${nb} + 1`
done
wait
echo "All processes done!"
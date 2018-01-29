#!/bin/bash

ver=$(tmux -V)
#tmux 2.7
echo $ver
echo "${ver:5:3}"

if [[ "${ver:5:3}" != '2.6' ]]
then 
    echo "you are using a later version of tmux"
   
    read -r -p "Are you sure? [y/n] " response
    if [[ ! "$response" =~ ^([yY][eE][sS]|[yY])+$ ]]
    then
	exit
    fi
fi
    echo yes



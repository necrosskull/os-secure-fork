#!/bin/bash

l_data="john"
p_data="doe"

echo -n "login: "
read login
echo -n "password: "
read password

if [[ $login == $l_data ]] && [[ $password == $p_data ]]
then
    echo "permission granted"
else
    echo "permission denied"
fi

#!/bin/bash

log="boris"
pass="123"

echo -n "Enter login: "

read login

echo -n "Enter password: "

read password
 
if [ $log = $login ] && [ $pass = $password ]
then 

 echo "success auth!"
else 
 echo "auth failed!"
fi

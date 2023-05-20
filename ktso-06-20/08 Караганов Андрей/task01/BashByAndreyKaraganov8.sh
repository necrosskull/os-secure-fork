#!/bin/bash
echo "Enter login"
read login
echo "Enter password"
read password
if [ $login = "Dron" ] && [ $password = "Dron" ]
then
echo "success auth!"
else
echo "auth failed!"
fi 

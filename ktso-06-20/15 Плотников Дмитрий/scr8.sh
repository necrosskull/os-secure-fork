#!/bin/bash
echo "Enter login"
read login
echo "Enter password"
read password
if [ $login = "Duke" ] && [ $password = "qwerty" ]
then
echo "success auth!"
else
echo "auth failed!"
fi

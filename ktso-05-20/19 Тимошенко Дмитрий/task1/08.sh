#!/bin/bash
echo "Enter login"
read login
echo "Enter password"
read password

if [ $login = "joshiax1" ] && [ $password = "1" ]
then
echo "success auth!"
else
echo "auth failed!"
fi

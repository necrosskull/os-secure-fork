#!/bin/bash
echo "Enter login"
read login
echo "Enter password"
read password
if [ $login = "flor4i" ] && [ $password = "5468" ]
then
echo "success auth!"
else
echo "auth failed!"
fi

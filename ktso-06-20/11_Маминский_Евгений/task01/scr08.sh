#!/bin/bash
echo "Enter login"
read login
echo "Enter password"
read password
if [ $login = "eugene" ] && [ $password = "toor" ]
then
echo "success auth!"
else
echo "auth failed!"
fi

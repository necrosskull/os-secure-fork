#!/bin/bash
echo "Enter login"
read login
echo "Enter password"
read password
if [ $login = "useless" ] && [ $password = "12345" ]
then
echo "success auth!"
else
echo "auth failed!"
fi


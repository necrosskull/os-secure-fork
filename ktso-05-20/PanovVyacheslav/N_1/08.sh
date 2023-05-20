#!/bin/bash
echo "Enter login"
read login
echo "Enter password"
read password
if [ $login = "hud0shnik" ] && [ $password = "toor" ]
then
echo "success auth!"
else
echo "auth failed!"
fi
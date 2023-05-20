#!/bin/bash

echo -n "Login: "
read login
echo -n "Password: "
read pass

if [ $login = "root" ] && [ $pass = "12345" ]; then
    echo "success auth!💚"
else 
    echo "auth faild!❤️"
fi
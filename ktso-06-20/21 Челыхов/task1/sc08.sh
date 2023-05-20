#!/bin/bash
echo "Enter Login"
read login
echo "Enter Password"
read password
if [ $login = "lemonchelo" ] && [ $password = "lemon" ]
then
echo "Auth completed"
else
echo "Wrong Password or Login"
fi 

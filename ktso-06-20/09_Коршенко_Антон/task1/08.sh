#!/bin/bash
echo "Enter Login"
read login
echo "Enter Password"
read password
if [ $login = "retr0" ] && [ $password = "retr0" ]
then
echo "Auth completed"
else
echo "Wrong Password or Login"
fi 

#!/bin/bash

off_login="admin"
off_password="12345"

echo "Enter Login"
read login
echo "Enter Password"
read pass
if [[ $login = $off_login ]] && [[ $pass == $off_password ]]
then
echo "success"
else
echo "faild"
fi
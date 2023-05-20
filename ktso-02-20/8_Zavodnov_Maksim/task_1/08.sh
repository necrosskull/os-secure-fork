#!/bin/bash
echo -n "Login: "
read login
echo -n "Password: "
read pass
if( [[ $login == admin ]] && [[ $pass -eq 12345 ]]) then
echo "success"
else echo "fail"
fi
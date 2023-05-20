#!/bin/bash

 echo "Enter login"
 read login
 echo "Enter password"
 read password

 true_login="admin"
 true_password="12345"
 if [[ $login = $true_login ]] && [[ $password = $true_password ]]
 then 
    echo "Welcome, admin!"
 else
    echo "You are not authenticated!"
 fi
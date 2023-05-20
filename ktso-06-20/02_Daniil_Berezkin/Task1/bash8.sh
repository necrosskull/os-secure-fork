#!/bin/bash
	echo "Enter login"
	read login
	echo "Enter password"
	read password
	if [ $login = "deny" ] && [ $password = "id" ]
	then
	echo "success auth!"
	else
	echo "auth failed!"
	fi

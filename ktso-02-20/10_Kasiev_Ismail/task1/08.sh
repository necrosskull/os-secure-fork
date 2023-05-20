#!/bin/bash

log="admin"
pas="123456"

echo -n "Enter login: "
read login

echo -n "Enter password: "
read password

if [ $log = $login ] && [ $pas = $password ]
then
	echo "success auth!"
else
	echo "auth failed!"
fi


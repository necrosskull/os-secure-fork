#!/bin/bash
echo Enter login
read log
echo Enter password
read pas
if [ $log = "admin" ] && [ $pas = "1234" ]
then
echo success auth!
else
echo auth failed!
fi

#!/bin/bash
echo Enter login
read log
echo Enter pass
read pas
if [ $log = "sergey" ] && [ $pas = "1" ]
then
echo success auth!
else
echo auth failed!
fi

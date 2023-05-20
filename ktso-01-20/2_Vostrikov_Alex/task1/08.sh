#!/bin/bash
echo Enter login
read log
echo Enter pass
read pas
if [ $log = "alex" ] && [ $pas = "123" ]
then
echo success auth!
else
echo auth failed!
fi


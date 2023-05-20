#!/bin/bash
echo Enter login
read log
echo Enter pass
read pas
if [ $log = "Aboba" ] && [ $pas = "man" ]
then
echo success auth!
else
echo auth failed!
fi


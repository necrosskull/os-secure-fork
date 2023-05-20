#!/bin/bash

echo "введите любой сезон года"
read season

case $season in 
    "summer" | "autumn" | "spring")
        echo "Correct"
        ;;  
    "winter")
        echo "Это мое любимое время года"
    ;;
    *)
        echo "Incorrect!"
    ;;

esac


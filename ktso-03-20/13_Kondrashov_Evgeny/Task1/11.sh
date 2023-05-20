#!/bin/bash

echo -n "Enter season of year: "
read season

case $season in

    "winter")
        echo "let it snow"
    ;;

    "autumn")
        echo "leaves drift by the window!"
    ;;
    
    "summer")
        echo "it's the summer time!"
    ;;
    
    "spring")
        echo "framework"
    ;;
    
    *)
        echo "Incorrect!"
    ;;
esac

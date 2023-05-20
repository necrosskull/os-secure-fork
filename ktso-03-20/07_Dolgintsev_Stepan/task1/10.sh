echo "Enter seasons name"
read input

if [ $input = "winter" ] || [ $input = "autumn" ] || [ $input = "summer" ] || [ $input = "spring" ]
then
    if [ $input = "autumn" ]
    then
    echo "Correct & my favorite one!"
    else
    echo "Correct!"
    fi
else
echo "Incorrect!"
fi
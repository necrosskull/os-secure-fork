echo "Enter seasons name"
read input

if [ $input = "winter" ] || [ $input = "autumn" ] || [ $input = "summer" ] || [ $input = "spring" ]
then
echo "Correct!"
else
echo "Incorrect!"
fi
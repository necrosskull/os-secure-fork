echo -n "Enter season: "
read season


if [[ $season = "winter" ]] || [[ $season = "spring" ]] || [[ $season = "summer" ]] || [[ $season = "autumn" ]]
then
	echo "Correct!"
	if [[ $season = "summer" ]]
	then
		echo "My favourite one"
	fi
else 
	echo "Incorrect!"
fi

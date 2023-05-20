echo -n "Enter season: "
read season


if [[ $season = "winter" ]] || [[ $season = "spring" ]] || [[ $season = "summer" ]] || [[ $season = "autumn" ]]
then
	echo "Correct!"
	if [[ $season = "winter" ]]
	then
		echo "My favourite season"
	fi
else 
	echo "Incorrect!"
fi

echo -n "Enter season: "
read season


if [[ $season = "winter" ]] || [[ $season = "spring" ]] || [[ $season = "summer" ]] || [[ $season = "autumn" ]]
then
	echo "Correct!"
	if [[ $season = "spring" ]]
	then
		echo "Best season"
	fi
else 
	echo "Incorrect!"
fi

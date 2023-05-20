echo -n "Enter season: "
read season


case $season in

	"spring" | "summer" | "autumn")
		echo "Correct!"
		;;
	
	"winter")
		echo "Correct!"
		echo "My favourite season"
		;;
	*)
		echo "Incorrect!"
		;;
esac

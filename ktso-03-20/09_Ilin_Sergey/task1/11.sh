echo -n "Enter season: "
read season


case $season in

	"winter" | "summer" | "autumn")
		echo "Correct!"
		;;
	
	"spring")
		echo "Correct!"
		echo "Best one"
		;;
	*)
		echo "Incorrect!"
		;;
esac

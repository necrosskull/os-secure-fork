echo -n "Enter season: "
read season

case $season in

	"winter" | "spring" | "autumn")
		echo "Correct!"
		;;
	
	"summer")
		echo "Correct!"
		echo "My favourite one"
		;;
	*)
		echo "Incorrect!"
		;;
esac
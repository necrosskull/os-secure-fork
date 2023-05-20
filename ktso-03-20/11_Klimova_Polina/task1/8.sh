dlogin="polina"
dpassword="skeplor"

echo -n "enter login: "
read login 

echo -n "enter password: "
read password 

if [[ $login = $dlogin ]] && [[ $password == $dpassword ]]
then
	echo "success"
else 
	echo "failed"
fi

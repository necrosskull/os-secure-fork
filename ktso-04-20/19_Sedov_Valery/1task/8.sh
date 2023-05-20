dlogin="admin"
dpassword="123456"

echo -n "Enter login: "
read login 

echo -n "enter password: "
read password 

if [[ $login = $dlogin ]] && [[ $password == $dpassword ]]
then
	echo "success"
else 
	echo "failed"
fi

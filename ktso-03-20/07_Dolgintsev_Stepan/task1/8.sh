echo "Enter login"
read login
echo "Enter password"
read password

if [ $login = "axidex" ] && [ $password = "123" ]
then
echo "success auth!"
else
echo "auth failed!"
fi
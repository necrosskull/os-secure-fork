 #!/bin/bash
 echo "enter login"
 read log
 echo "enter password"
 read pass
 val1="admin"
 val2="12345"
 if [[ $log = $val1 ]] && [[ $pass = $val2 ]]
 then 
 echo "good job"
 else
 echo "mistake!"
 fi

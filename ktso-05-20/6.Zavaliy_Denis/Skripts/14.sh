    #!/bin/bash
    sum()
    {
    echo $(( $1 + $2 ))
    }

    echo -n "Enter first num: "
    read n1
    echo -n "Enter second num: "
    read n2

    sum n1 n2


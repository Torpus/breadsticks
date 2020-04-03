#!/bin/bash
RANDOM=$$
for ((i=1; i <= $1; i++))
do
        NUMGEN=$RANDOM
        let "NUMGEN %= 1000"
        if [[ $(($RANDOM%10)) -ne 0 ]]
        then
                if [[ $i -ge $(($1 - $NUMGEN)) ]]
                then
                        NUMGEN=$(($1-i+1))
                fi
                WORDS=$(shuf -n$NUMGEN /usr/share/dict/american-english-huge)
                for WORD in $WORDS
                do
                        WORD=${WORD%\'*}
                        echo $WORD $RANDOM >> randoms.txt
                done
                i=$(($i + $NUMGEN - 1))
        else
                echo "breadsticks" $RANDOM >> randoms.txt
        fi
done


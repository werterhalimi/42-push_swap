for ((n=0;n<1;n++))
do

ARG=`ruby random.ruby`
./push_swap "$ARG" | ./check "$ARG"

done


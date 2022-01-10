# ! /usr/bin/env bash
# File: test_algo.sh

n_tries=100
max_res=0
min_res=$(echo "$1 * $1" | bc)
mean_res=0

count=0
while [[ $count -lt $n_tries ]]
do
    arg=$(python3 rand_in.py $1)
    res=$(./push_swap $arg | wc -l)

    if [[ $res -gt $max_res ]]
    then
        let max_res=$res
    fi 
    if [[ $res -lt $min_res ]]
    then
        let min_res=$res
    fi
    let mean_res=$mean_res+$res
    
    let count=$count+1
done

echo "Best case: $min_res"
echo "Worst case: $max_res"
echo "average case: $(echo "$mean_res  / $n_tries" | bc)"


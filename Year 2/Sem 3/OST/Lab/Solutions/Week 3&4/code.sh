# PART 1
echo "enter a number" 
read number if [ `expr $((number%2))` -eq 0 ] 
then 
echo "even" elif [ `expr $((number%2))` -eq 1 ] 
then 
echo "odd" fi

# PART 2
echo "enter a number" 
read number x=0 y=0 while [ $x -lt $number ] 
do y=`expr $x \* 2 + 1` 
echo $y x=$((x+1)) done

# PART 3
echo "enter a number" 
read number x=1 y=1 while [ $x -lt $number ] 
do x=$((x+1)) y=`expr $x \* $y` done echo $y

# PART 4
echo "Enter a,b and c" 
read a 
read b 
read c 
d=`expr $b \* $b - 4 \* $a \* $c` 
if [ $d -ge 0 ] 
then quad="r" 
else quad="i" 
fi 
case $quad in "r") 
sqt=`echo "scale=4;sqrt($d)" | bc` r1=`echo "( -1 * $b + $sqt ) / ( 2 * $a )" | bc` r2=`echo "( -1 * $b - $sqt ) / ( 2 * $a )" | bc` 
echo "Root1: $r1 Root2: $r2" ;; "i") 
de=`expr -1 \* $d` 
sq=`echo "scale=4;sqrt($de)" | bc` 
re=`echo "( -1 * $b ) / ( 2 * $a )" | bc` 
im=`echo "$sq / (2 * $a)" | bc` 
echo "Root1 : $re + i$im Root2 : $re - i$im " ;; 
esac
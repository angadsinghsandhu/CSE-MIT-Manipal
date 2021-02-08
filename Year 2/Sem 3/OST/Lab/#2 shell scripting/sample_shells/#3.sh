#******************************************************************************
    
                    #3 : Third Sample Lab Exersize (pg. 16)

#*******************************************************************************

cat > script.sh
echo the name of this script is $0
echo the first arguement is $1
echo the list of arguements is $*
echo the date of this file is in the file $1.$$

date > $1.$$
ls $1.$$
rm $1.$$

chmod +x script.sh
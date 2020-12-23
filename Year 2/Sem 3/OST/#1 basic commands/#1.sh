#******************************************************************************
    
                    #1 : First Lab Exersize (pg. 13)

#*******************************************************************************

# part 1
mkdir home/sub1 home/sub2

# part 2
cd home/sub1
touch file1.txt file2.txt file3.txt

echo "this is file1" >> file1.txt
echo "this is file2" >> file2.txt
echo "this is file3" >> file3.txt

# part 3
cd ../..
cp home/sub1/file1.txt home/sub2

# part 4
cd home/sub2
touch info.txt
echo "`who --count`" >> info.txt
echo "`la | wc -l`" >> info.txt

# part 5
ls -lL .[aA]

# part 6
ls -lL --count

# part 7
if cat file1.txt -o "this is file1"; then 
echo cat file1.txt -o;

# part 8
wc -l info.txt
read -p "Please enter your folder:" t_PATH
read -p "Please enter your file(.exe):" RPOGRAM_FILE
pwd
all_correct=true
for f in $(find $t_PATH -name "*.in")
do
    echo "${f%.*}.ans"
    $RPOGRAM_FILE < $f > tmp
    cmp -s tmp ${f%.*}.ans
    if [ $? != 0 ]; then
        all_correct=false
        break
    fi
done
if [ $all_correct == true ]
then
    echo ""
    echo "Accept"
    echo ""
else
    echo ""
    echo "Wrong Answer"
    echo ""
fi
rm tmp
read -p "Press ENTER to exit." enter
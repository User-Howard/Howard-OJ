read -p "Please enter your folder:" t_PATH
read -p "Please enter your file(.exe):" RPOGRAM_FILE
echo $RPOGRAM_FILE

all_correct=true
for f in $t_PATH/*/*/*.in
do
    echo "${f}"
    $RPOGRAM_FILE < $f > tmp
    diff --side-by-side tmp ${f%.*}.ans
    if [ $? != 0 ]; then
        all_correct=false
        break
    fi
done
if [ $all_correct == true ]; then
    echo ""
    echo "ALL PASS"
    echo ""
fi
echo ""
rm tmp
read -p "Press ENTER to exit." enter
#!/bin/bash

input="[ZeroJudge] a001"

# 解析文字
folder_path=$(echo "$input" | grep -o '\[.*\]' | tr -d '[]')
file_name=$(echo "$input" | awk '{print $2}')

echo "folder_path = $folder_path"
echo "file_name = $file_name"

if [ -f "$folder_path/$file_name.cpp" ]; then
    echo "File exists in $folder_path folder."
else
    echo "File does not exist in $folder_path folder."
fi
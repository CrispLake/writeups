#!/bin/bash

folder_path="./files"

for file in "$folder_path"/*; do
    if [ -f "$file" ]; then
        ./decrypt.sh "$file"
    fi
done

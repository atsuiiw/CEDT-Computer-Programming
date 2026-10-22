# !/bin/bash

read fileName
trimmed="${fileName%.*}.bin"
g++ "${fileName}" -o ${trimmed}

echo "Hello World!"

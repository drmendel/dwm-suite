#!/bin/bash

DIR="$HOME/utils/dwmblocks/scripts"

# List files and iterate
ls "$DIR" | while read -r f; do
    start=$(date +%s%N)
    "$f" >/dev/null
    end=$(date +%s%N)
    elapsed=$(( (end - start)/1000000 ))  # milliseconds
    echo "$f took ${elapsed}ms"
done | sort -nr -k5


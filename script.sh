#!/bin/bash

# Check for input
if [ -z "$1" ]; then
  echo "Usage: $0 <ending_letter>"
  exit 1
fi

end_letter=$1

# Get ASCII values for 'a' and the input letter
start_ord=$(printf "%d" "'A")
end_ord=$(printf "%d" "'$end_letter")

# Loop from 'a' to the input letter
for ((i=start_ord; i<=end_ord; i++)); do
  char=$(printf "\\$(printf "%03o" "$i")")
  mkdir "${char}test"
  touch "$char.cpp"
  cp template.cpp "$char.cpp"

  for ((j=1; j<=7; j++)) do
    touch "${char}test/${char}test$j.txt"
  done
done
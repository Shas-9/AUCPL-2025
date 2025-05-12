#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <ending_letter>"
  exit 1
fi

end_letter=$1

start_ord=$(printf "%d" "'A")
end_ord=$(printf "%d" "'$end_letter")

for ((i=start_ord; i<=end_ord; i++)); do
  char=$(printf "\\$(printf "%03o" "$i")")
  mkdir "${char}"
  touch "${char}/${char}.cpp"
  touch "${char}/${char}.py"
  cp template.cpp "${char}/${char}.cpp"

  for ((j=1; j<=7; j++)) do
    touch "${char}/${char}test$j.txt"
  done
done
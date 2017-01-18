#!/bin/bash
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "Making golden images"
input='script/input/golden.txt'
while IFS= read -r var
do
  echo "./../build/MIA/bin/MIA $var"
  ../$var
  echo "program exit with code $?"
  echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
done < "$input"

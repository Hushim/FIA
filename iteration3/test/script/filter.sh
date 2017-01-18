#!/bin/bash
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "Test Filter"
input='script/input/input-filter.txt'
while IFS= read -r var
do
  echo "./../build/MIA/bin/MIA $var"
  ../$var
  echo "program exit with code $?"
  echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
done < "$input"

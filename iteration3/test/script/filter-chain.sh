#!/bin/bash
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo "Test filter chain"
input='script/input/input-chain.txt'
while IFS= read -r var
do
  echo "./../build/MIA/bin/MIA $var"
  ../$var
  if [ $? = 0 ]; then
     echo "pass"
  else
     echo "YOU FAILED !!!!!!!!!!!: program exit with status $?"
  fi
  echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
done < "$input"
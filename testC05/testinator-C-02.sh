#!/bin/sh

#REMOVE 'EVAL'S BEFORE POSTING

#script by tzenyatt for School 21
#improved by: (place your name here if you make any improvements)

#READ IT FIRST
#you can pass number of exercise in format like "00" or "01" etc.
#place this folder into your classmate's project folder (where ex00 ex01 etc lies)
#make sure that ex00 ex01 etc. (turn-in directories) contains only files to turn in (this is what "ls -l" line here for)

evaluate_test()
{
  echo "\n$1"

  turn_in_directory="../$1"
  file_to_turn_in=`ls $turn_in_directory`

  cp ../$1/$file_to_turn_in $1

  gcc -Wall -Werror -Wextra $1/*.c
  norminette -R CheckForbiddenSourceHeader $1/$file_to_turn_in
  ./a.out

  rm $1/$file_to_turn_in
}

ex_num=${1-nafin}

if [ $ex_num == nafin ]; then
  # Make sure that turn-in directories contains only files to turn in with appropriate permissions
  ls -la ../*
  
  for test_directory in ex*; do
    evaluate_test $test_directory
  done

  rm a.out
elif [[ $ex_num =~ [[:digit:]]{2} ]]; then
  evaluate_test ex$ex_num
else
  echo 'incorrect input'
fi

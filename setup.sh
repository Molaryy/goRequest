#!/bin/bash

clear

if [ "$1" != "clear" ]; then
  cmake -S . -B build/
  cd build/ || exit 1
  make
  cd ..
fi

if [ $# -eq 1 ]; then
  if [ "$1" = "up" ]; then
    echo
    echo "----------------------"
    echo "|      goRequest     |"
    echo "----------------------"
    echo
    ./goRequest
  fi
  if [ "$1" = "clear" ]; then
      rm build/* -rf
      rm build/.cmake/ -rf
      rm -f goRequest
    fi
fi

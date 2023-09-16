#!/bin/bash

if [ "$1" != "clear" ]; then
  cmake -S . -B build/
  cd build/ || exit 1
  make
  cd ..
fi

clear
if [ $# -eq 1 ]; then
  if [ "$1" = "up" ]; then
    ./goRequest
  fi
  if [ "$1" = "clear" ]; then
      rm build/* -rf
      rm -f goRequest
    fi
fi

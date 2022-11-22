#!/usr/bin/env bash

expr="1+2+3+4*4*89-4*5*6/3"

# cmake -B build && cmake --build build

build/c100 "$expr" >build/tmp.s
clang build/tmp.s src/driver.c -o build/cal.out
build/cal.out

# Ninja
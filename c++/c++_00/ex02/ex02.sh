#!/bin/bash
clang++ -std=c++98 -pedantic-errors -Werror -Wextra -Wall -o a Account.cpp test.cpp;
./a > log2


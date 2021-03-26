#!/bin/bash

norminette_ver2 ./gnl* ./includes/* ./libft/* ./srcs/*
git clone https://github.com/daumtto53/cub3d.git cub_diff
diff -rub ./cub_diff ./cub -x '.git' -x '.vscode'

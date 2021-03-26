#!/bin/zsh

# change to norminette_ver 2 plz
git clone https://github.com/daumtto53/cub3d.git cub_diff

#enter intra's git directory to compare

diff -rub ./cub_diff {dir_name} -x '.git' -x '.vscode'

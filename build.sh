#!/bin/sh


gcc $(find src/ -name "*.c" | xargs echo) -Isrc/ -o build/debug || (echo -e "\x1b[33m" Faild; exit 1)
build/debug




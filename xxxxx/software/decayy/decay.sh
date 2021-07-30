#!/bin/sh
for file in $1/*
do
./decay $file 1000000 &
done

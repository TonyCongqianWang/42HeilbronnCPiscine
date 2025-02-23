@echo off
rem taken from https://stackoverflow.com/questions/9922498/calculate-time-difference-in-windows-batch-file
setlocal
setlocal EnableDelayedExpansion

set "startTime=%time: =0%"

rush-01c "3 1 4 3 3 2 2 4 2 3 1 2 2 2 5 4 2 3 1 3 4 3 3 2 4 2 3 1 3 2 2 3"
rush-01c "2 2 3 5 4 2 1 4 3 3 3 1 3 2 4 2 3 1 2 2 4 3 2 3 2 4 3 3 2 1 3 2"
rush-01c "3 1 2 2 3 3 2 3 4 3 1 2 3 2 3 4 2 5 2 3 1 2 4 3 6 2 1 3 4 2 2 4"
rush-01c "3 3 2 2 2 4 1 3 3 1 3 2 2 3 4 3 4 2 3 1 3 2 3 2 2 3 2 4 2 1 3 4"
rush-01c "4 2 2 3 3 5 1 4 2 6 2 2 3 1 4 4 3 2 3 2 1 4 2 3 2 6 2 1 3 3 4 2"
rush-01c "4 2 3 1 3 2 3 2 4 4 2 5 1 2 2 2 2 2 2 4 1 2 4 4 4 5 3 1 4 2 2 2"
rush-01c "1 3 3 2 4 3 2 2 5 3 3 2 1 2 5 3 1 3 4 2 2 4 3 4 2 2 1 4 3 4 2 3"
rush-01c "2 2 1 4 2 2 3 4 3 5 2 4 3 3 2 1 3 1 2 3 2 4 6 3 4 3 2 3 2 2 2 1"
rush-01c "2 2 4 3 2 1 6 3 3 2 1 5 3 3 2 3 3 3 3 2 1 6 2 3 2 2 4 5 5 1 2 3"
rush-01c "2 1 3 2 2 4 4 5 2 3 3 3 2 2 4 1 2 1 3 2 3 4 3 2 4 4 3 5 2 2 2 1"
rush-01c "2 1 2 4 2 3 4 2 3 4 3 2 3 1 2 2 2 1 5 4 3 2 3 2 3 4 1 4 4 2 3 2"
rush-01c "3 2 4 5 2 2 1 4 3 3 2 3 3 3 2 1 4 2 3 2 1 4 3 5 2 2 3 3 4 2 3 1"
rush-01c "4 2 2 4 2 1 4 3 1 4 3 2 2 4 3 3 3 2 2 4 2 4 3 1 2 2 4 1 2 2 3 3"
rush-01c "4 4 3 4 2 1 2 4 1 2 2 2 3 4 3 4 4 4 2 4 2 2 2 1 3 2 2 1 5 3 3 5"
rush-01c "3 3 4 2 4 1 3 2 2 3 2 2 1 5 3 3 4 2 1 3 2 4 2 3 3 1 3 4 3 2 2 3"
rush-01c "3 3 2 3 2 3 1 2 1 3 3 3 4 2 4 2 3 2 2 4 4 2 3 1 2 3 4 1 4 4 2 2"
rush-01c "4 2 3 4 2 2 4 1 1 2 2 2 4 4 3 5 4 2 4 4 5 2 2 1 1 2 3 2 2 3 3 7"
rush-01c "1 4 2 2 3 5 3 2 3 2 4 3 4 2 3 1 1 3 4 2 3 2 5 3 2 3 2 4 3 5 2 1"
rush-01c "2 3 1 5 3 3 2 2 4 4 4 1 3 2 4 2 3 1 2 5 2 3 5 2 2 5 4 2 3 2 1 3"
rush-01c "2 3 3 3 2 4 1 3 5 4 2 1 3 2 4 4 2 3 1 2 4 3 4 4 2 3 3 4 1 2 2 4"
rush-01c "2 3 4 1 3 3 2 4 2 1 2 6 3 2 4 2 2 5 4 1 3 3 4 2 3 2 2 2 3 3 1 5"
rush-01c "2 4 2 3 1 3 2 3 2 2 3 2 3 1 4 3 2 1 3 4 2 2 4 3 3 3 2 1 3 3 2 3"
rush-01c "4 3 2 5 4 1 3 2 3 3 3 1 2 4 2 4 4 4 2 1 2 3 3 4 2 1 3 5 3 3 2 5"
rush-01c "3 1 5 3 2 3 2 2 4 3 2 2 2 3 1 3 2 3 3 1 2 3 2 5 3 4 1 5 3 2 2 2"
rush-01c "3 2 4 2 2 3 3 1 1 4 3 2 2 3 2 3 4 2 4 2 3 2 4 1 1 4 2 3 2 2 4 4"
rush-01c "3 3 3 2 6 2 4 1 3 3 3 4 1 3 2 2 4 2 3 4 1 2 3 3 1 3 2 3 5 4 2 2"
rush-01c "3 4 4 5 1 4 2 2 2 2 3 2 5 1 3 2 2 5 3 2 2 1 4 3 3 1 2 4 2 4 4 2"
rush-01c "2 3 3 1 2 3 3 3 3 3 2 4 2 1 2 3 4 1 3 4 3 2 2 2 5 3 2 1 3 3 2 3"
rush-01c "4 2 3 2 1 3 4 4 2 2 3 4 5 2 2 1 3 4 2 2 3 4 1 4 3 5 3 2 2 2 4 1"
rush-01c "3 3 2 4 4 4 3 1 2 2 2 2 2 1 5 4 4 2 3 2 2 2 1 5 1 6 2 4 3 2 3 3"
rush-01c "6 1 2 3 2 3 3 4 2 5 1 2 3 4 2 2 2 4 4 3 3 2 1 2 6 3 2 2 1 3 4 3"
rush-01c "2 2 2 2 4 2 3 1 5 5 3 4 1 2 2 6 5 2 1 2 3 3 3 3 1 2 3 4 3 2 2 3"
rush-01c "3 4 2 3 1 2 3 2 3 2 2 2 3 3 1 3 2 4 4 2 1 2 4 4 2 1 3 5 6 3 4 2"
rush-01c "3 3 2 4 2 4 2 1 2 4 2 2 1 3 4 3 4 3 2 2 3 1 3 3 1 2 5 2 3 2 4 2"
rush-01c "3 1 5 2 2 4 4 2 3 5 1 3 2 2 2 5 2 3 3 4 1 2 4 2 2 3 1 3 3 2 2 5"
rush-01c "1 2 3 4 5 3 2 3 2 3 3 4 2 1 2 3 1 2 2 2 3 5 3 2 3 2 4 4 3 1 2 3"
rush-01c "3 3 2 3 3 2 4 1 2 1 2 2 4 4 3 4 4 2 3 5 2 1 2 2 1 2 3 3 2 3 3 3"
rush-01c "3 4 1 5 2 2 2 3 4 2 2 2 3 1 4 4 2 2 1 5 2 3 2 4 3 2 3 1 2 3 4 3"
rush-01c "3 2 3 2 3 2 6 1 4 3 3 3 1 2 2 3 3 2 2 1 2 4 3 4 1 3 4 2 3 3 2 3"
rush-01c "2 1 3 2 2 2 4 3 4 2 2 4 2 5 1 3 2 4 1 3 5 2 2 3 5 2 4 3 3 1 2 2"
rush-01c "4 2 2 6 4 4 1 3 3 4 2 2 1 2 3 3 3 2 2 2 1 3 3 3 2 2 4 3 3 1 3 3"
rush-01c "3 3 4 3 1 2 3 2 2 2 3 4 3 1 3 3 3 3 3 2 1 2 2 2 4 1 4 3 5 2 4 2"
rush-01c "4 1 2 2 2 3 3 5 1 3 3 4 3 2 4 2 2 2 2 3 3 3 3 1 4 3 2 2 2 2 1 4"
rush-01c "4 2 5 3 3 3 1 2 2 3 3 4 1 2 2 3 3 3 2 4 4 2 1 3 2 1 4 4 2 3 2 3"
rush-01c "2 3 2 1 3 3 2 3 5 1 2 4 3 3 2 3 3 7 1 4 2 3 2 2 3 2 5 2 1 2 2 3"
rush-01c "1 2 3 5 4 3 2 4 2 3 3 2 2 4 3 1 1 3 2 3 4 2 3 2 4 2 3 3 3 2 3 1"
rush-01c "2 6 4 3 1 4 2 3 5 1 2 2 4 2 3 3 2 1 3 4 3 2 2 2 3 3 2 1 3 2 3 4"
rush-01c "2 3 2 6 1 4 4 2 4 2 2 1 4 3 2 3 3 3 1 3 2 6 2 3 2 1 3 3 2 2 5 3"
rush-01c "4 3 3 3 2 3 5 1 2 1 2 3 4 4 3 2 4 3 2 4 3 2 1 2 1 2 2 4 2 5 3 2"
rush-01c "4 3 3 3 2 2 1 4 2 4 3 3 3 2 2 1 4 4 2 4 2 3 1 5 2 3 2 3 2 3 4 1"
rush-01c "3 3 3 3 2 3 3 1 2 2 3 4 5 1 2 4 4 3 3 2 1 2 6 2 1 4 3 3 2 3 2 3"
rush-01c "5 2 1 2 4 4 3 2 3 2 3 3 4 2 1 3 3 2 5 3 2 1 2 3 3 3 1 3 4 3 2 2"
rush-01c "3 3 3 5 3 2 2 1 3 3 2 1 3 3 2 5 5 3 3 1 2 3 2 3 1 2 2 4 4 3 2 3"
rush-01c "3 3 1 2 2 3 4 2 2 3 4 4 5 2 1 2 2 2 4 1 2 4 3 2 2 4 4 4 3 3 1 2"
rush-01c "3 1 4 2 2 3 2 3 4 5 1 2 2 3 3 4 2 2 4 1 2 2 2 2 5 2 1 6 4 2 3 5"
rush-01c "1 2 4 2 3 3 3 4 4 5 4 3 2 2 1 2 1 2 2 2 4 4 3 4 5 3 2 4 5 2 1 2"
rush-01c "3 1 3 2 4 2 2 4 2 4 2 3 3 2 4 1 2 3 5 3 3 2 1 3 4 2 2 3 3 2 5 1"
rush-01c "3 3 2 3 3 3 1 3 3 3 5 3 2 1 4 2 3 3 2 3 2 1 3 5 2 4 3 3 1 4 3 2"
rush-01c "2 4 1 2 3 4 2 3 4 1 3 2 2 3 2 3 2 1 2 4 3 4 2 2 4 3 1 2 4 2 4 3"
rush-01c "3 2 1 2 3 4 2 5 3 4 3 4 1 2 3 2 3 2 2 1 4 2 4 2 3 4 4 5 2 2 1 2"
rush-01c "1 2 3 2 2 5 3 5 5 5 3 2 3 1 2 3 1 2 3 4 4 4 2 3 5 5 3 2 2 1 3 3"
rush-01c "2 1 2 2 4 3 5 3 4 3 1 5 3 2 2 2 2 1 4 2 3 4 3 3 4 2 3 4 1 2 3 3"
rush-01c "3 2 3 4 4 2 2 1 1 4 2 2 3 4 3 2 4 2 3 2 4 3 3 1 1 2 2 5 4 2 3 2"
rush-01c "4 4 1 4 3 2 2 4 2 2 4 2 4 2 3 1 3 3 4 3 2 1 4 2 4 2 3 3 4 3 2 1"
rush-01c "2 2 4 1 3 3 4 2 5 3 3 3 3 2 1 3 3 1 2 3 4 2 3 5 2 4 4 1 3 3 2 2"
rush-01c "3 3 3 2 2 4 1 3 2 2 4 2 1 2 3 3 4 2 2 3 2 3 1 4 2 3 2 1 4 3 3 3"
rush-01c "2 3 2 3 2 3 3 1 2 3 3 4 3 1 4 3 3 2 5 3 4 2 1 2 1 4 2 5 2 3 2 2"
rush-01c "4 1 2 3 5 2 3 2 4 3 2 1 3 2 3 4 2 5 2 3 1 2 3 3 4 2 1 2 2 3 5 4"
rush-01c "3 4 4 2 3 2 1 2 2 2 2 1 4 5 2 3 3 2 3 3 3 2 1 3 2 1 3 3 3 4 2 3"
rush-01c "5 2 4 4 4 2 1 3 3 3 2 1 2 4 3 3 3 2 3 5 2 1 2 3 2 2 1 3 2 3 3 4"
rush-01c "3 5 3 4 2 2 3 1 2 3 2 3 5 1 3 5 3 3 2 3 3 2 1 3 1 2 2 3 3 3 4 3"
rush-01c "4 2 1 2 2 5 4 4 2 5 4 3 4 1 2 2 3 2 2 2 6 5 1 3 5 3 2 3 1 2 4 3"
rush-01c "2 3 3 2 4 2 1 2 3 1 3 5 3 2 4 3 4 3 3 1 3 4 2 2 2 5 3 3 1 3 3 4"
rush-01c "5 3 2 1 2 4 2 3 2 2 3 4 4 1 3 2 4 4 3 3 3 1 2 2 4 2 4 3 1 4 3 2"
rush-01c "2 2 2 1 3 4 3 3 3 4 2 4 2 2 4 1 3 1 3 2 2 4 2 3 2 5 4 2 4 3 2 1"
rush-01c "5 4 2 1 4 3 3 2 1 2 2 2 4 3 4 3 4 4 3 4 2 2 2 1 3 1 2 3 4 3 2 3"
rush-01c "4 3 3 1 3 2 5 3 2 1 2 4 3 3 2 4 3 3 3 2 2 3 1 2 3 2 4 1 3 2 4 5"
rush-01c "2 1 2 3 5 3 3 3 3 2 2 3 1 2 3 3 2 1 2 2 4 2 4 3 3 4 6 2 1 4 3 3"
rush-01c "3 2 2 2 2 5 1 3 3 4 2 3 2 1 3 2 4 4 2 3 1 5 2 3 2 2 2 5 3 1 3 3"
rush-01c "4 4 2 1 4 2 5 2 2 3 2 5 1 2 3 4 3 4 3 2 2 2 1 3 3 3 1 4 2 2 3 4"
rush-01c "4 1 2 3 3 2 2 2 2 2 3 1 2 3 3 4 2 3 3 3 2 1 3 3 3 1 2 3 2 3 4 4"
rush-01c "2 3 3 1 4 3 4 2 3 1 3 5 3 3 2 4 2 3 3 3 1 4 4 2 3 1 4 2 2 3 2 3"
rush-01c "3 2 2 3 1 4 4 2 1 4 3 2 2 2 2 3 2 3 2 2 6 3 4 1 2 5 3 2 1 2 2 4"
rush-01c "3 3 2 1 2 5 4 3 3 3 4 3 3 1 2 3 2 3 2 2 3 1 3 5 4 4 2 2 1 3 2 3"
rush-01c "4 2 3 4 5 1 2 2 3 1 2 3 2 2 5 4 3 4 3 2 1 2 3 2 3 2 3 1 2 3 2 4"
rush-01c "3 2 1 3 2 3 4 2 2 5 3 3 1 4 2 3 3 2 3 3 3 1 4 3 3 3 1 4 2 4 2 3"
rush-01c "3 4 2 2 3 4 1 5 2 3 4 2 5 2 3 1 4 2 3 3 2 1 2 3 2 4 3 4 2 3 3 1"
rush-01c "4 2 3 1 3 3 2 3 3 4 3 4 1 2 4 2 3 2 3 4 2 1 2 3 3 2 2 3 3 4 1 4"
rush-01c "7 3 5 3 2 3 1 2 1 3 2 2 2 2 4 3 5 4 5 4 2 3 2 1 2 1 4 3 3 3 2 4"
rush-01c "3 4 3 1 5 2 2 2 2 1 3 4 2 2 3 5 3 4 1 2 4 4 3 2 4 1 5 2 3 2 3 3"
rush-01c "1 3 3 3 2 4 2 2 2 2 1 2 4 3 4 3 1 4 3 3 2 5 2 2 3 3 1 2 3 2 4 3"
rush-01c "4 2 4 3 3 2 4 1 3 5 3 2 3 2 1 4 3 2 4 3 3 1 2 5 1 4 2 3 3 2 2 2"
rush-01c "1 4 2 2 4 3 3 4 3 1 3 4 2 3 2 2 1 3 2 5 5 3 4 2 4 3 3 2 2 2 1 4"
rush-01c "2 4 3 1 2 4 3 3 2 1 2 3 3 3 3 3 2 1 4 3 5 3 3 2 4 5 1 3 2 3 5 3"
rush-01c "4 3 2 4 3 4 2 1 1 2 3 2 3 3 3 5 3 4 2 4 2 3 2 1 1 2 3 4 3 3 5 5"
rush-01c "3 3 3 2 4 1 5 2 4 2 2 2 3 5 1 2 4 2 1 2 4 2 3 4 2 4 4 3 4 2 1 2"
rush-01c "2 3 3 1 3 4 2 4 3 3 2 3 4 2 2 1 3 1 3 2 3 2 2 4 3 3 2 4 3 3 2 1"
rush-01c "2 2 3 3 3 2 1 4 3 3 3 1 2 2 4 2 4 1 2 2 2 3 3 2 2 4 2 4 1 3 3 3"
rush-01c "2 3 2 3 2 1 3 5 3 2 3 2 3 4 3 1 6 1 2 2 2 4 3 3 2 3 5 2 2 3 5 1"
rush-01c "3 2 3 2 1 2 2 4 2 5 3 4 5 3 1 2 3 2 2 3 3 1 3 2 3 2 3 3 5 5 1 2"
rush-01c "3 1 3 2 2 4 2 5 3 5 4 3 2 1 4 2 2 2 3 4 1 3 3 5 4 4 3 2 3 3 1 2"
rush-01c "1 6 4 2 2 3 3 3 4 1 2 4 2 2 2 5 1 2 4 3 2 4 3 2 5 2 1 2 4 2 2 3"
rush-01c "2 4 2 3 3 1 2 4 4 2 4 3 1 4 2 2 2 5 2 1 3 4 2 3 3 2 2 3 1 4 4 3"
rush-01c "2 2 3 1 4 2 3 4 3 3 3 4 1 2 2 2 2 2 5 1 2 3 3 2 3 4 2 3 5 1 2 3"
rush-01c "4 2 4 1 4 2 5 3 2 3 2 6 3 3 1 2 3 5 2 1 4 3 2 2 3 2 2 4 1 3 4 2"
rush-01c "3 3 2 2 3 1 3 3 3 1 2 3 2 4 3 4 4 2 4 1 3 6 2 2 3 3 1 3 3 2 3 6"
rush-01c "3 3 4 2 3 1 4 2 4 3 1 2 2 3 2 4 4 3 1 2 2 2 3 2 2 1 4 4 5 2 3 3"
rush-01c "5 2 1 2 4 3 2 2 1 2 3 4 3 2 2 3 3 5 2 2 4 3 3 1 2 2 3 1 2 3 3 3"
rush-01c "3 2 3 2 3 3 1 3 2 3 2 3 3 1 3 4 3 2 3 2 5 1 3 4 2 2 3 4 1 3 3 3"
rush-01c "2 2 3 2 3 4 5 1 4 2 3 2 3 1 3 4 4 2 1 2 2 3 3 3 1 5 3 2 2 2 3 3"
rush-01c "2 2 3 4 3 3 1 2 3 2 2 3 1 3 5 4 3 1 4 2 2 4 2 3 2 3 1 2 2 5 3 2"
rush-01c "3 3 4 1 4 2 3 2 2 1 3 3 2 3 4 3 3 5 1 2 4 2 3 2 4 1 4 2 2 4 4 2"
rush-01c "5 3 2 4 2 3 2 1 3 3 3 1 3 2 3 2 5 4 3 2 2 1 3 3 1 2 4 3 4 4 2 2"
rush-01c "3 3 2 2 1 3 3 2 3 2 3 5 2 1 2 2 3 2 3 2 1 3 2 4 2 3 3 4 3 2 1 3"
rush-01c "2 2 3 1 3 3 3 3 4 5 1 3 3 2 3 2 2 2 4 1 4 2 4 2 2 4 2 3 4 3 1 2"
rush-01c "3 2 2 5 2 1 4 3 2 3 2 3 3 5 1 4 4 3 2 4 1 3 2 2 2 2 4 1 5 2 3 2"
rush-01c "2 5 3 3 3 1 2 3 2 1 3 5 3 6 2 4 2 1 4 3 4 2 3 2 3 3 1 4 2 2 2 3"
rush-01c "4 2 4 2 5 2 2 1 2 4 2 4 1 2 2 5 5 3 2 1 3 2 4 2 1 2 4 4 3 3 2 3"
rush-01c "2 4 5 3 1 2 2 3 4 2 3 4 3 1 2 2 4 1 3 2 3 3 2 3 3 2 2 3 4 1 4 3"
rush-01c "3 3 3 3 2 2 1 2 2 1 2 5 2 3 4 3 4 4 3 2 3 1 2 2 2 3 1 3 5 3 2 5"
rush-01c "4 3 1 4 3 5 2 2 3 3 3 3 2 1 3 3 2 3 2 4 2 1 4 4 3 2 1 2 2 3 3 3"
rush-01c "1 4 5 2 4 2 2 4 3 1 3 3 2 3 2 3 1 2 5 4 4 3 4 2 4 3 2 1 2 4 3 3"
rush-01c "2 1 2 2 2 3 5 4 4 5 4 2 2 3 1 2 2 3 4 1 3 2 5 4 3 4 2 2 4 2 1 2"
rush-01c "4 4 2 2 1 3 3 3 1 2 3 3 4 2 2 3 5 2 4 3 3 4 2 1 3 2 3 2 1 2 6 3"
rush-01c "2 1 3 4 2 2 3 4 4 4 3 2 3 1 2 2 2 1 2 2 4 3 3 5 3 5 2 2 3 2 1 3"
rush-01c "4 3 3 2 1 4 2 2 3 2 2 2 3 1 3 4 3 3 2 3 1 2 2 4 2 2 1 4 2 3 3 3"
rush-01c "3 2 4 3 2 3 2 1 3 4 2 2 3 2 1 4 5 2 4 1 3 3 2 5 1 2 3 4 4 3 2 2"
rush-01c "2 1 3 2 2 3 2 4 2 6 2 4 4 1 3 3 2 3 3 4 3 4 1 3 3 3 4 2 3 1 2 2"
rush-01c "4 3 2 2 3 2 5 1 1 3 4 3 3 3 2 7 6 3 2 2 4 3 3 1 1 2 3 4 3 2 2 3"
rush-01c "5 2 2 1 2 4 3 3 2 5 2 3 2 3 1 4 4 3 2 3 2 1 3 4 3 3 2 1 2 4 4 2"
rush-01c "2 3 4 2 2 4 3 1 4 2 1 3 4 2 3 2 3 1 2 3 3 3 2 2 1 3 2 4 3 2 6 2"
rush-01c "2 4 1 3 2 3 3 2 2 2 5 1 2 3 4 3 2 1 3 5 3 3 2 2 4 3 1 2 3 3 2 3"
rush-01c "2 4 3 5 3 2 3 1 4 3 3 1 2 2 2 4 2 1 3 2 3 2 3 4 1 3 3 5 2 2 2 4"
rush-01c "2 2 1 2 2 4 2 4 6 4 6 3 2 3 2 1 2 2 1 2 2 4 4 5 3 3 4 2 4 3 2 1"
rush-01c "4 1 3 5 3 2 2 2 3 3 2 1 3 2 2 5 2 4 3 2 3 1 3 4 3 1 2 5 2 5 2 4"
rush-01c "3 2 4 2 1 2 5 2 3 5 2 2 6 2 1 3 3 2 3 1 3 2 3 3 3 3 3 3 1 3 2 2"
rush-01c "1 5 6 2 2 2 3 4 3 1 2 4 2 4 3 2 1 2 3 3 3 2 3 2 4 3 2 4 2 1 4 3"
rush-01c "2 4 1 3 2 3 3 2 5 2 4 3 1 3 2 2 2 1 3 3 2 4 2 4 3 3 4 2 3 1 3 2"
rush-01c "4 2 2 3 1 3 2 7 1 3 2 4 3 4 2 2 3 2 4 2 4 2 3 1 3 5 2 2 3 2 1 3"
rush-01c "2 3 6 3 2 1 2 4 3 2 2 2 5 4 3 1 2 3 2 5 4 1 2 4 3 2 4 2 2 4 3 1"
rush-01c "4 3 4 4 2 1 3 2 3 2 2 1 3 3 2 5 4 3 3 1 4 2 2 3 3 3 1 2 2 2 3 3"
rush-01c "4 1 2 2 7 2 2 4 3 5 3 3 1 2 3 2 2 3 3 2 1 3 4 4 3 2 2 4 6 2 1 3"
rush-01c "5 3 2 2 4 3 1 4 2 4 2 3 1 2 5 3 5 3 2 2 4 2 1 3 2 3 3 5 1 3 2 2"
rush-01c "4 3 1 3 3 2 3 2 2 1 3 3 2 3 3 3 3 3 3 3 4 2 1 2 2 2 3 2 1 3 4 4"
rush-01c "4 3 3 3 4 2 1 2 2 2 3 2 3 3 5 1 5 3 2 2 2 2 1 4 2 3 3 3 3 4 3 1"
rush-01c "1 2 3 2 2 5 3 4 4 3 3 3 2 2 1 3 1 3 2 2 3 3 5 4 4 2 4 2 1 3 3 2"
rush-01c "3 1 2 2 2 2 3 3 4 4 2 3 5 1 2 3 2 3 3 1 2 3 2 4 4 4 3 4 1 3 2 3"
rush-01c "4 1 2 5 2 2 3 2 3 2 3 2 1 3 2 5 2 4 2 5 3 1 3 3 3 1 3 2 5 3 3 3"
rush-01c "2 4 2 4 1 2 3 2 4 1 2 2 3 2 4 3 2 4 3 1 2 3 3 2 3 3 1 4 2 4 2 4"
rush-01c "3 2 4 4 1 3 3 2 2 1 2 2 4 2 4 3 3 2 5 1 3 4 2 2 2 1 2 5 3 3 2 3"
rush-01c "3 1 3 2 4 3 2 2 2 4 3 4 3 3 1 2 2 4 4 2 3 2 1 5 3 3 1 3 4 3 3 2"
rush-01c "4 2 3 2 3 2 1 2 2 2 5 2 1 3 3 5 4 3 2 4 2 4 1 3 2 2 4 1 2 3 3 3"
rush-01c "3 3 2 1 4 5 2 3 1 4 4 4 2 2 3 3 3 3 2 3 5 2 4 1 3 2 3 4 1 3 2 4"
rush-01c "2 1 2 2 3 5 4 3 3 2 4 3 3 1 2 3 2 1 2 2 4 3 3 3 5 3 3 3 4 1 2 2"
rush-01c "4 3 3 6 2 2 2 1 1 5 3 2 5 3 3 2 5 3 4 2 3 3 2 1 1 2 2 5 2 3 4 2"
rush-01c "4 1 2 3 3 3 2 4 1 5 2 3 3 2 4 4 2 3 3 2 3 2 3 1 5 2 3 1 2 3 3 3"
rush-01c "2 3 2 2 1 3 4 4 3 3 6 2 3 3 1 3 2 2 3 1 2 3 2 4 4 3 2 4 2 1 3 2"
rush-01c "4 2 2 3 2 2 1 4 2 4 5 1 3 3 2 3 6 2 2 2 3 3 1 2 2 3 2 1 3 3 3 3"
rush-01c "4 2 4 5 4 3 2 1 3 5 3 2 2 1 3 4 3 2 4 1 4 2 4 3 1 3 2 5 2 4 3 2"
rush-01c "2 2 4 3 3 3 1 2 2 4 2 3 3 1 3 2 2 2 4 3 1 3 3 2 2 5 4 3 3 1 3 2"
rush-01c "3 3 4 2 4 1 3 3 2 2 3 4 5 4 2 1 3 3 2 3 1 3 4 2 2 4 3 3 4 2 2 1"
rush-01c "1 4 3 2 4 3 2 2 5 3 2 3 1 4 2 3 1 4 3 2 2 3 4 4 3 1 3 2 3 4 2 2"
rush-01c "3 4 4 2 3 2 4 1 5 2 3 3 2 3 1 4 3 2 1 3 2 3 4 3 1 3 3 4 5 2 2 2"
rush-01c "2 3 1 3 2 4 2 5 4 2 4 3 2 1 4 3 3 1 2 4 3 4 2 4 3 5 2 2 2 1 3 2"
rush-01c "3 3 4 2 4 4 1 2 4 4 3 3 1 2 6 2 3 2 1 2 3 3 5 3 2 1 3 4 3 4 3 2"
rush-01c "3 4 4 2 3 2 3 1 2 1 3 3 2 3 3 3 4 3 2 3 2 2 1 2 1 3 2 3 2 4 6 3"
rush-01c "3 2 4 3 2 3 4 1 2 3 3 2 3 2 1 5 3 2 3 3 2 4 1 4 1 3 3 2 3 2 4 2"
rush-01c "2 3 2 4 2 3 3 1 2 3 4 3 1 2 3 5 3 1 2 3 3 3 3 2 1 4 2 4 2 2 3 3"
rush-01c "2 1 3 2 3 4 4 3 4 3 1 3 2 2 3 3 2 3 3 4 1 5 4 3 5 2 3 1 6 2 2 3"
rush-01c "2 2 4 1 2 3 3 3 1 3 2 4 4 4 2 2 2 2 4 2 6 4 3 1 2 3 2 4 1 2 4 2"
rush-01c "3 2 3 5 1 3 2 2 2 3 2 2 3 1 4 5 3 4 4 2 1 4 3 3 2 1 2 4 4 3 4 3"
rush-01c "3 2 2 3 2 1 3 3 1 4 2 3 3 4 2 3 3 2 3 3 3 4 2 1 3 3 3 1 2 4 2 3"
rush-01c "2 1 2 4 3 5 4 4 4 4 3 2 2 1 2 3 2 1 3 3 3 3 4 5 3 4 2 2 1 3 2 3"
rush-01c "3 4 4 2 4 2 5 1 3 3 2 5 2 3 1 5 4 2 1 2 5 3 2 4 1 2 4 3 2 3 3 2"
rush-01c "3 2 1 4 2 3 2 3 3 3 4 1 2 2 2 2 2 2 2 1 4 3 3 4 3 3 2 4 2 1 2 4"
rush-01c "3 3 3 2 4 3 1 2 2 2 1 2 4 3 3 3 4 3 1 3 2 4 3 2 2 1 4 2 5 2 3 4"
rush-01c "3 4 4 2 1 3 3 2 4 1 3 2 3 2 3 2 3 3 3 1 2 3 3 2 2 3 2 4 3 1 2 3"
rush-01c "3 2 4 2 1 3 2 2 1 2 3 3 3 4 2 3 3 2 5 2 4 3 3 1 3 4 1 3 2 5 2 3"
rush-01c "3 2 5 3 3 1 2 2 6 5 2 2 3 2 3 1 6 2 1 3 3 3 3 5 2 4 4 3 2 4 3 1"
rush-01c "2 1 3 3 2 3 3 3 1 5 3 3 2 2 3 3 2 4 3 3 3 3 3 1 3 3 4 2 1 2 3 3"
rush-01c "5 2 4 2 4 1 3 2 3 3 2 2 4 3 1 2 4 4 4 2 2 1 3 4 2 1 4 6 2 4 4 2"
rush-01c "2 6 3 5 3 4 2 1 2 2 4 1 3 3 3 2 2 1 6 5 3 4 2 2 1 4 2 2 3 2 3 2"
rush-01c "3 2 1 4 3 3 2 3 1 2 3 2 3 4 3 3 3 4 2 4 3 2 3 1 3 2 2 1 3 4 2 4"
rush-01c "2 3 2 4 3 1 3 3 3 1 3 2 3 3 3 2 2 3 3 3 1 4 3 2 2 3 2 3 2 1 3 4"
rush-01c "4 3 3 4 3 1 2 2 3 4 2 1 3 3 2 2 4 3 2 2 4 1 3 4 2 2 4 4 3 6 1 3"
rush-01c "3 2 3 3 2 1 3 4 1 3 4 2 4 6 2 3 4 2 4 4 3 2 3 1 3 3 3 1 2 3 2 3"
rush-01c "3 1 3 3 2 3 3 2 2 3 3 3 6 2 4 1 2 4 3 1 3 3 3 2 2 3 5 4 2 3 3 1"
rush-01c "3 2 1 3 2 4 2 3 4 2 4 3 3 1 3 2 3 5 2 3 1 3 2 3 4 2 3 4 3 1 3 2"
rush-01c "2 1 2 3 3 2 5 3 3 5 1 2 2 4 3 3 2 5 1 4 5 2 2 3 6 3 5 1 2 2 3 3"
rush-01c "2 1 4 4 2 4 2 2 4 5 2 4 3 1 3 2 2 3 4 1 2 4 2 3 3 4 1 4 2 2 4 2"
rush-01c "2 3 1 3 3 2 3 3 3 3 3 2 1 2 4 3 3 1 3 5 2 2 4 3 3 2 2 1 3 5 3 3"
rush-01c "2 4 1 3 2 3 5 3 3 1 5 2 2 2 3 3 2 1 3 4 2 3 3 2 3 5 3 3 2 1 2 4"
rush-01c "2 5 3 1 2 3 3 2 5 1 4 4 3 3 2 2 2 3 3 1 3 3 5 2 2 3 4 4 2 1 2 2"
rush-01c "1 2 2 4 5 3 2 2 3 4 5 2 2 1 2 2 1 2 3 3 5 4 2 4 2 3 2 2 1 4 4 3"
rush-01c "4 3 1 2 3 6 2 4 2 2 4 4 4 2 4 1 3 3 3 2 2 1 4 4 3 2 2 3 4 3 2 1"
rush-01c "2 4 3 2 4 1 4 2 3 3 4 2 1 5 2 3 4 1 3 2 2 4 3 2 2 4 4 4 2 1 2 3"
rush-01c "3 4 4 1 3 3 2 2 2 3 2 3 3 1 4 4 3 2 5 3 3 2 1 3 2 2 1 3 3 4 5 3"
rush-01c "3 1 2 3 3 3 2 2 4 2 3 1 2 3 4 2 2 3 3 1 2 4 4 3 2 2 3 3 2 1 4 3"
rush-01c "4 3 2 4 3 2 1 3 2 3 2 3 3 3 4 1 5 3 2 4 2 2 1 3 2 3 2 3 2 3 4 1"
rush-01c "3 2 3 2 3 6 1 5 2 2 2 4 3 1 4 2 3 2 2 4 1 3 3 2 2 3 5 3 2 1 4 2"
rush-01c "2 3 1 2 2 3 3 3 4 2 3 5 1 2 2 4 2 3 1 5 3 2 2 3 4 4 3 1 2 2 5 4"
rush-01c "2 4 3 4 1 3 3 2 3 2 3 3 2 3 1 4 2 4 1 3 4 3 2 5 4 1 2 3 3 4 4 2"
rush-01c "2 1 4 3 2 2 4 3 4 3 1 2 3 2 3 4 2 3 1 3 4 3 3 3 2 2 4 2 1 2 4 4"
rush-01c "2 3 3 3 2 3 4 1 2 3 3 2 1 4 2 5 6 1 3 2 2 3 4 2 1 4 2 3 5 3 2 2"
rush-01c "3 2 5 3 2 1 2 2 2 2 1 2 4 4 4 3 3 2 1 4 6 2 3 3 2 2 3 4 1 3 3 4"
rush-01c "3 2 3 3 1 2 3 4 2 4 3 5 3 3 2 1 3 2 2 3 3 2 1 3 3 4 4 2 2 2 5 1"
rush-01c "3 2 3 4 2 4 2 1 1 4 2 3 4 3 3 2 3 2 2 3 4 4 3 1 1 2 4 4 3 3 3 2"
rush-01c "3 3 4 2 2 1 3 2 4 3 2 1 3 3 2 4 3 3 2 4 1 2 3 4 3 3 5 1 3 2 2 4"
rush-01c "2 3 3 2 2 4 3 1 2 3 4 4 4 1 2 2 2 3 4 2 1 2 3 2 1 3 3 4 5 5 2 2"
rush-01c "3 2 2 2 3 1 4 4 4 3 1 4 2 3 2 3 4 2 2 1 3 5 3 3 3 5 4 2 1 3 2 5"
rush-01c "4 3 2 3 3 3 2 1 2 2 3 1 3 4 2 3 4 4 3 2 1 3 2 3 1 2 2 2 4 2 5 3"
rush-01c "3 1 3 4 2 2 3 3 2 2 5 1 5 2 4 2 2 5 2 2 3 1 4 3 3 2 3 3 2 3 1 3"
rush-01c "4 4 3 3 1 2 3 2 3 1 2 3 3 2 4 2 4 4 3 1 2 3 2 2 3 1 2 5 3 3 3 2"
rush-01c "3 3 4 1 2 2 5 2 3 3 2 3 2 4 1 4 2 3 4 1 2 2 2 5 2 2 1 3 4 3 3 2"
rush-01c "3 3 3 4 3 1 2 2 2 2 4 1 3 3 2 3 4 2 2 3 2 5 1 3 3 1 3 4 4 2 3 2"
rush-01c "2 3 4 2 6 3 1 2 3 3 2 3 2 1 5 3 3 3 4 1 2 2 2 3 2 3 1 3 3 5 4 2"
rush-01c "3 3 2 3 1 2 3 4 1 3 4 2 2 3 3 2 2 2 2 3 3 2 4 1 3 4 4 2 2 2 1 5"
rush-01c "3 3 3 2 1 7 3 2 2 3 1 5 4 2 2 2 4 4 2 1 3 3 3 2 2 2 3 5 2 1 2 3"
rush-01c "6 3 2 2 3 2 1 3 1 2 3 4 3 3 2 3 4 3 2 3 3 3 2 1 2 2 4 4 1 2 4 3"
rush-01c "3 5 1 2 2 4 3 3 4 1 4 2 3 2 2 3 2 4 3 1 3 2 5 2 3 3 2 2 1 2 3 4"
rush-01c "5 2 5 2 4 2 1 2 1 3 2 4 3 3 3 2 3 4 3 2 4 2 3 1 2 1 3 2 4 4 3 2"
rush-01c "3 3 2 2 3 1 3 2 2 3 3 1 2 4 4 4 4 4 2 1 3 2 4 2 2 1 2 3 2 4 3 2"
rush-01c "2 1 2 4 3 3 4 2 5 3 2 3 3 3 2 1 2 1 2 2 4 2 4 4 2 4 3 3 3 4 2 1"
rush-01c "2 3 1 6 2 4 2 3 2 3 4 1 5 2 2 3 2 3 2 4 4 1 2 2 3 3 5 1 2 3 2 4"
rush-01c "2 3 1 5 2 5 4 4 4 3 3 2 5 2 2 1 2 4 1 2 2 2 3 4 5 3 3 2 2 3 2 1"
rush-01c "2 1 4 3 3 2 2 4 1 3 3 4 2 3 3 3 2 5 2 3 4 2 2 1 3 2 2 2 1 3 3 5"
rush-01c "3 2 3 1 2 2 4 5 2 2 4 5 3 3 2 1 2 2 3 4 1 4 3 3 5 4 6 3 4 4 2 1"
rush-01c "2 2 3 1 2 5 3 4 3 3 3 5 2 1 2 2 2 4 2 2 1 3 3 4 4 3 2 4 4 2 1 2"
rush-01c "3 2 3 2 1 2 3 2 1 3 4 2 7 4 2 3 3 2 2 3 2 4 3 1 2 5 3 2 3 1 2 3"
rush-01c "3 1 2 3 3 2 4 3 3 2 4 4 3 2 2 1 2 2 3 1 3 4 3 3 3 4 3 2 2 2 2 1"
rush-01c "2 3 4 3 3 3 1 5 2 2 1 3 2 2 4 3 2 1 2 3 3 6 3 3 2 4 4 2 3 1 3 4"
rush-01c "2 3 2 3 1 2 4 5 3 3 4 2 4 2 1 3 3 1 2 2 2 5 3 4 4 4 4 2 2 1 3 2"
rush-01c "2 3 4 2 4 2 2 1 1 2 2 2 4 3 5 3 2 3 4 3 2 3 2 1 1 2 2 2 3 4 2 5"
rush-01c "2 3 2 4 2 5 6 1 4 3 3 1 3 3 2 2 4 1 2 2 5 2 4 3 1 4 3 3 3 3 2 2"
rush-01c "6 3 3 2 1 2 2 3 2 3 4 2 3 3 2 1 4 4 2 3 2 2 1 5 2 2 4 2 3 4 4 1"
rush-01c "2 5 1 4 4 2 2 3 4 2 4 1 4 3 3 3 2 4 1 2 4 5 2 3 4 2 4 3 1 3 3 3"
rush-01c "3 4 2 3 2 3 1 4 3 3 1 3 4 3 3 2 3 3 3 2 4 1 2 2 2 4 2 5 2 3 1 2"
rush-01c "3 5 2 4 3 2 1 3 4 1 2 2 2 4 3 3 4 3 5 2 1 3 3 2 2 2 1 3 5 2 3 4"
rush-01c "2 3 5 3 2 3 1 3 2 5 3 1 2 3 3 3 2 2 2 3 3 3 1 2 2 3 4 2 1 2 5 4"
rush-01c "3 1 2 4 2 4 3 2 2 4 3 3 4 2 2 1 2 3 2 2 1 3 4 5 2 3 4 2 5 3 2 1"
rush-01c "4 2 4 4 3 2 3 1 1 3 3 3 3 2 2 3 3 3 2 4 3 2 2 1 1 3 4 3 3 3 2 3"
rush-01c "4 4 3 2 2 3 2 1 3 3 2 4 4 1 2 2 5 3 2 2 4 1 2 3 1 3 3 3 2 4 4 2"
rush-01c "4 2 5 1 2 4 3 2 3 3 2 5 4 1 3 2 3 3 2 4 1 2 3 3 4 1 2 2 3 3 4 2"
rush-01c "3 5 2 5 1 3 2 3 2 2 3 3 4 2 1 3 3 3 1 3 4 3 2 2 3 4 2 2 1 2 5 2"
rush-01c "2 3 4 2 3 3 1 4 2 1 3 3 2 3 2 3 2 4 4 3 3 2 1 2 2 4 2 4 1 3 2 3"
rush-01c "3 3 2 2 2 3 1 3 2 1 3 3 4 3 3 3 4 2 3 4 3 5 1 2 2 4 3 2 3 1 3 5"
rush-01c "3 3 4 2 2 1 5 2 3 3 2 3 2 2 1 4 4 2 2 3 1 2 3 5 2 1 4 2 3 4 2 2"
rush-01c "3 2 3 2 4 1 2 4 2 2 3 3 3 4 3 1 2 3 2 2 3 4 1 3 3 2 2 4 2 4 4 1"
rush-01c "3 2 2 1 2 3 5 3 1 4 3 5 2 3 2 3 3 2 2 3 2 3 4 1 3 2 3 3 5 1 2 5"
rush-01c "4 4 2 2 2 3 4 1 2 1 4 3 3 2 4 2 4 3 2 3 2 4 1 2 1 3 3 2 3 3 4 2"


set "endTime=%time: =0%"

set "end=!endTime:%time:~8,1%=%%100)*100+1!"  &  set "start=!startTime:%time:~8,1%=%%100)*100+1!"
set /A "elap=((((10!end:%time:~2,1%=%%100)*60+1!%%100)-((((10!start:%time:~2,1%=%%100)*60+1!%%100), elap-=(elap>>31)*24*60*60*100"

set /A "cc=elap%%100+100,elap/=100,ss=elap%%60+100,elap/=60,mm=elap%%60+100,hh=elap/60+100"

echo Start:    %startTime%
echo End:      %endTime%
echo Elapsed:  %hh:~1%%time:~2,1%%mm:~1%%time:~2,1%%ss:~1%%time:~8,1%%cc:~1%

endlocal
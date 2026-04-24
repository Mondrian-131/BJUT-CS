@echo off
 
g++ bf.cpp -o bf.exe
g++ test.cpp -o test.exe
g++ data.cpp -o data.exe
 
:loop
data.exe > data.txt
test.exe < data.txt > test.txt
bf.exe < data.txt > bf.txt
 
fc test.txt bf.txt
 
if not errorlevel 1 goto loop
 
pause
g++ -o num.o ../src/main.cpp
touch ../output/number.cpp
./num.o > ../output/number.cpp
rm num.o

g++ -o num.o ../src/main.cpp
touch ../output/number.cpp
cat ../src/default.cpp > ../output/number.cpp
./num.o >> ../output/number.cpp
rm num.o

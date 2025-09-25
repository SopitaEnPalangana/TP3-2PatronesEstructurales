g++ -I./include -c ./src/decorators.cpp
g++ -I./include -c ./src/hotel.cpp
g++ -I./include -c main.cpp

g++ decorators.o hotel.o main.o -o app.exe

DEL *.o

app.exe
COMPILER = g++
FLAGS = -I include -std=c++11 -Wall

exec: main.o Diary.o Time.o Date.o App.o
	$(COMPILER) $(FLAGS) -o exec main.o Diary.o Time.o Date.o App.o

main.o: src/main.cpp
	$(COMPILER) $(FLAGS) -c src/main.cpp

Diary.o: src/Diary.cpp include/Diary.h
	$(COMPILER) $(FLAGS) -c src/Diary.cpp

Time.o: src/Time.cpp include/Time.h
	$(COMPILER) $(FLAGS) -c src/Time.cpp

Date.o: src/Date.cpp include/Date.h
	$(COMPILER) $(FLAGS) -c src/Date.cpp

App.o: src/App.cpp include/App.h
	$(COMPILER) $(FLAGS) -c src/App.cpp

clean:
	rm -f *.o
	rm exec

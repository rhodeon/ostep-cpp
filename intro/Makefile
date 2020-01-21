
all: cpu mem threads io

clean:
	rm -f cpu mem threads io

cpu: cpu.cpp common.h
	gcc -o cpu cpu.cpp -Wall

mem: mem.cpp common.h
	gcc -o mem mem.cpp -Wall

threads: threads.cpp common.h common_threads.h
	gcc -o threads threads.cpp -Wall -pthread

io: io.cpp common.h
	gcc -o io io.cpp -Wall


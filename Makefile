.PHONY: clean

main: main.cpp
	g++ main.cpp -o main -Wall -Wextra

clean:
	rm main
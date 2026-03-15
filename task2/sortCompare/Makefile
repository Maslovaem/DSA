.PHONY: build clean all

build: bubbleSort.c buildMain.c
	gcc -fsanitize=address $^ -o sortCompareBuild
	./sortCompareBuild

all: clean build

clean:
	rm -rf sortCompareBuild sortCompareTest
	rm -f *.csv

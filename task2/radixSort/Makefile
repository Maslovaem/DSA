.PHONY: build

build: radixSort.c buildMain.c
	g++ -fsanitize=address $^ -o radixSortBuild
	./radixSortBuild

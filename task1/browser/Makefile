.PHONY: build tests

build: doublyLinkedList.c browser.c build_main.c
	gcc $^ -o browser_build
	./browser_build

tests: doublyLinkedList.c browser.c tests_main.c
	gcc -fsanitize=address $^ -o browser_test
	./browser_test

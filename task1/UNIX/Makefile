.PHONY: build tests

build: stack.c parser.c build_main.c
	gcc -fsanitize=address $^ -o UNIX_build
	./UNIX_build

tests: stack.c parser.c tests_main.c tests.c
	gcc -fsanitize=address $^ -o UNIX_test
	./UNIX_test

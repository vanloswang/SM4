all:
	gcc main.c sm4.c -o sm4_test
	gcc block_sm4_test.c sm4.c -o block_sm4_test

clean:
	rm -rf sm4_test block_sm4_test

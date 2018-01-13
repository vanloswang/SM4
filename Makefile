OUTPUT = sm4_test

all:
	gcc main.c sm4.c -o $(OUTPUT)

clean:
	rm -rf $(OUTPUT)

test:test.o main.o
	gcc -g $^ -o $@
test.o:test.c
	gcc -c -g $< -o $@
main.o:main.c
	gcc -c -g $< -o $@
.PHONY:clean
clean:
	rm -f *.o test

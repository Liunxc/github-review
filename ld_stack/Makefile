all:main

main: main.c pop.o push.o is_empty.o stack.o
	gcc -g $^ -o $@
pop.o: pop.c
	gcc -c -g -fPIC $^ -o $@
push.o:push.c
	gcc -c -g -fPIC $^ -o $@
stack.o:stack.c
	gcc -c -g -fPIC $^ -o $@
is_empty.o:is_empty.c
	gcc -c -g -fPIC $^ -o $@
clean:
	rm *.o *.dis

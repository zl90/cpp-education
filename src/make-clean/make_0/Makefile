add.o: add.cpp
	g++ -c $^

print_add.o: print_add.cpp
	g++ -c $^

print_add: add.o print_add.o
	g++ $^ -o $@

clean:
	rm print_add *.o

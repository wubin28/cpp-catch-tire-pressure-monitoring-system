run.tests.output : makefile run.tests
	./run.tests

run.tests : makefile *.cpp *.hpp
	g++ -std=c++11 -Wall -Werror -O *.cpp -o run.tests



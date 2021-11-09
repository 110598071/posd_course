.PHONY: clean

TEST= test/test_square.h test/test_circle.h test/test_shape.h \
 	  test/test_compound_shape.h test/test_iterator.h \
	  test/test_utility.h test/test_visitor.h
SRC= src/shape.h src/square.h src/circle.h src/compound_shape.h src/iterator.h \
     src/utility.h src/null_iterator.h src/compound_iterator.h
OBJ = obj/shape_visitor.o

bin/test: test/test.cpp $(TEST) $(SRC) $(OBJ)# what
	g++ -std=c++11 test/test.cpp $(OBJ) -o bin/test -lgtest -lpthread

obj/shape_visitor.o: src/shape_visitor.cpp src/shape_visitor.h
	g++ -std=c++11 -Wfatal-errors -Wall -c src/shape_visitor.cpp -o obj/shape_visitor.o

clean:
	rm -f bin/test obj/shape_visitor.o

.PHONY: clean

TEST= test/test_square.h test/test_circle.h test/test_shape.h \
 	  test/test_compound_shape.h test/test_iterator.h \
	  test/test_utility.h test/test_visitor.h test/test_builder.h test/test_parser.h
SRC= src/shape.h src/square.h src/circle.h src/compound_shape.h src/iterator.h \
     src/utility.h src/null_iterator.h src/compound_iterator.h src/select_shape_visitor.h \
	 src/shape_parser.h src/scanner.h src/mock_scanner.h src/shape_scanner.h
# OBJ = obj/select_shape_visitor.o

bin/test: test/test.cpp $(TEST) $(SRC)
	g++ -std=c++17 test/test.cpp -o bin/test -lgtest -lpthread

# obj/select_shape_visitor.o: src/select_shape_visitor.cpp src/select_shape_visitor.h
# 	g++ -std=c++11 -Wfatal-errors -Wall -c src/select_shape_visitor.cpp -o obj/select_shape_visitor.o

clean:
	rm -f bin/test

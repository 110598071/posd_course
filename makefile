.PHONY: clean

TEST = test/test_square.h test/test_circle.h test/test_shape.h test/test_compound_shape.h test/test_iterator.h
SRC = src/shape.h src/square.h src/circle.h src/compound_shape.h src/utility.h src/iterator.h src/null_iterator.h

bin/test: test/test.cpp $(TEST) $(SRC) # 相依性檔案 -> [目標檔案(欲產生的檔案)]: [相依檔案]
	g++ -std=c++11 test/test.cpp -o bin/test -lgtest -lpthread

clean:
	rm -f bin/test
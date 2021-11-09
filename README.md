## Pattern Oriented Software Design, Fall 2021
- Instructor: Prof. Y C Cheng
- Office hours: 1:30pm - 4:30pm, Wed 
- Class meeting time: Wed 2-3-4
- Class meeting place: 
  - CB2-207 (when physical class resumes)
  - [Microsoft Teams](https://teams.microsoft.com/l/team/19%3aVgURaz5E9ggyNsJ5txN0xtBb3KA05czf8-h2DKot7F01%40thread.tacv2/conversations?groupId=06658c8d-9640-47a5-a33f-4ce8d6c1df57&tenantId=dfb5e216-2b8a-4b32-b1cb-e786a1095218) (when distance learning is in effect)
- TA: Sandy Chen, Rui Chen (rm 1324 S&T)
- Office hours: TBA

### Synopsis


This course aims to build a foundation for students to build software with design patterns and mainstream programming paradigms used in modern software development. We will also cover the SOLID principles of object-oriented design. These topics will be threaded with a long running example developed in the classroom with participation from students and with state-of-the-art engineering practices. A real-world example to illustrate the use of design patterns wraps up this course. This will take place on Saturday, Dec 18, 2021, by guest lecturer Kurt Hsu of VeryBuy.

Design patterns examines reusable solutions to object oriented design problems (maintainable, extendable, etc.) in software developed in object-oriented languages like C++, Java, Python, Ruby, OCaml and so on.  

  - design patterns
    - individual patterns by category as they are encountered in the running example
    - application of multiple patterns
    - real-world examples  

The programming paradigms affect how design patterns are implemented. Although object orientation is the the main paradigm, other paradigms that contribute to a cleaner implementation are examined in the context of design patterns implementation.

  - programming paradigms
    - procedure (ad hoc polymorphism, c, python)
    - function (math functions lisp, scheme, ...)
    - generics and templates (static polymorphism)
    - object orientation (dynamic polymorphism)
    - static typing vs dynamic typing

SOLID principles examine object-oriented design principles behind software design, patterns and beyond, to achieves _separation of concerns_.

  - source level principles
  - component level principles
  - review of their use in the running example  

The main part of lectures is threaded with a long running example involving the creation,  manipulation, and storage of geometric shapes. Development of the example is done mostly (if not entirely) in class meetings; it is done iteratively and incrementally and with test-driven development, mob programming, and continuous integration. Source code is available to class participants through a repository.

  - engineering practices
    - HTSI: _understanding the problem_, _devising a plan_, _carrying out the plan_, and _looking back_
    - mob programming with strong style pair programming
      - class participants will take turn playing the roles of _driver_ and _navigator_
    - code proceeded by tests: _failing test-passing test-refactoring_ _TDD_
    - source control through git
    - program builds through builders and continuous integration

Lastly, an outside lecture from industry will give a 3-hour lecture on real-world application of design patterns. This is followed by an outlook to further deepening and broadening design knowledge and skills by touching upon architecture and design.

## Problems 

**Problem 1 : sorting shapes**
A simple geometry application called _geo_ is needed to sort shapes such as triangles, circles, rectangles and others. As a command line application, _geo_ reads shapes from an input file, sorts the shapes by area or perimeter in increasing order or decreasing order, and write the result to an output file. For example,
```
geo input.txt output.txt area inc
```
sorts the shapes in file _input.txt_ in increasing order by area, and writes the result to the file _output.txt_. And
```
geo input.txt output.txt perimeter dec
```
sorts the shapes in file _input.txt_ in decreasing order by perimeter, and writes the result to the file _output.txt_.

**Problem 2: Shape manipulation**

A program for manipulating geometric shapes is needed. With the program, the user creates/deletes/modifies simple shapes such as square, circle, triangle, and convex polygons. Individual shapes will have properties such as area, perimeter, color and so on. Compound shapes can be formed from individual shapes. Area and perimeter properties are still needed on compound shapes. A compound shape can include other compound shapes. The following operations on shapes are needed.

- Add shapes to a compound shape;
- Delete shapes from a compound shape;
- Group and ungroup;
- Move shapes out of a compound shape;
- Move shapes from a compound shape to another compound shape;
- Select shapes by Boolean expression on the properties area, perimeter, color and type; and
- Load/store shapes from/into a file.

**Week1**

Problem space
- Read the problem together
- Find the main subproblems
- Organized subproblem by a tree
```
Sorting shapes
├── console IO
├── file IO
├── representation
│   ├── square 1
│   ├── circle 5
│   └── shape 6
└── computation
    ├── area 2
    ├── perimeter
    └── sorting 3
        └── stl sort 4
```

Solution space
- Folder structure: src, test and bin
- Builder: make and makefile

TDD
- google test


**Week2**

Polymorphism
- base class(Shape) with virtual method(area)
- inheritance Square:Shape Circle:Shape with override
- use pointer or reference the base class

```
Shape composition and manipulation
├── console IO
├── file IO
├── representation
│   ├── square
│   ├── circle
│   ├── compound shape
│   └── shape
└── computation
    ├── area
    ├── perimeter
    ├── add
    ├── delete
    ├── move
    └── select
        └── select by area
```

Solution space

**Week3**
- remove of Circle deqendencies

```
.PHONY: clean

TEST = test/test_square.h test/test_circle.h test/test_shape.h test/test_compound_shape.h test/test_iterator.h test/test_utility.h test/test_visitor.h 
SRC = src/shape.h src/square.h src/circle.h src/compound_shape.h src/utility.h src/iterator.h src/null_iterator.h src/shape_visitor.h

bin/test: test/test.cpp $(TEST) $(SRC) # 相依性檔案 -> [目標檔案(欲產生的檔案)]: [相依檔案]
	g++ -std=c++11 test/test.cpp -o bin/test -lgtest -lpthread

clean:
	rm -f bin/test
```
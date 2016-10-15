all:
	flex -o lexer.cpp lang.lex && bison -o parser.cpp -d lang.y
	g++ -std=gnu++11 -Wno-write-strings lexer.cpp parser.cpp -o MiniValgrind

parser:
	flex -o lexer.cpp lang.lex && bison -o parser.cpp -d lang.y

valg:
	g++ -std=gnu++11 -Wno-write-strings lexer.cpp parser.cpp -o MiniValgrind
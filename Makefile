all:
	flex -o Generated/lexer.cpp lang.lex && bison -o Generated/parser.cpp -d lang.y
	g++ -g -std=gnu++11 -Wno-write-strings Generated/lexer.cpp Generated/parser.cpp Src/Variable.cpp Src/Operators.cpp -o MiniValgrind

parser:
	flex -o Generated/lexer.cpp lang.lex && bison -o Generated/parser.cpp -d lang.y

valg:
	g++ -std=gnu++11 -Wno-write-strings Generated/lexer.cpp Generated/parser.cpp Src/Variable.cpp Src/Operators.cpp -o MiniValgrind

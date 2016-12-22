all:
	flex -o Generated/lexer.cpp -l MiniC.lex && bison -o Generated/parser.cpp -vd MiniC.y
	g++ -g -std=gnu++11 -Wno-write-strings Generated/lexer.cpp Generated/parser.cpp Src/Variable.cpp Src/Statements.cpp -o MiniValgrind -lm

parser:
	flex -o Generated/lexer.cpp MiniC.lex && bison -o Generated/parser.cpp -d MiniC.y

valg:
	g++ -std=gnu++11 -Wno-write-strings Generated/lexer.cpp Generated/parser.cpp Src/Variable.cpp Src/Statements.cpp -o MiniValgrind -lm


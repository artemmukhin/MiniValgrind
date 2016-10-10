all:
	flex lang.lex && bison -d lang.y
	g++ -std=gnu++11 -Wno-write-strings lex.yy.c lang.tab.c

all:
	flex lang.lex && bison -d lang.y
	g++ -Wno-write-strings lex.yy.c lang.tab.c

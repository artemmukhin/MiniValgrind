/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 9 "MiniC.y" /* yacc.c:339  */

    #define YYSTYPE MyDataType
    #include <iostream>
    #include <string>
    #include "../Src/Types.h"
    #include "../Src/Variable.h"
    #include "../Src/Statements.h"
    extern int yylineno;
    int yylex();
    void yyerror(char *s) {
       std::cerr << s << ", line " << yylineno << std::endl;
       exit(1);
    }

#line 81 "Generated/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_GENERATED_PARSER_HPP_INCLUDED
# define YY_YY_GENERATED_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    FOR = 261,
    RETURN = 262,
    P_BEGIN = 263,
    P_END = 264,
    EQ = 265,
    LE = 266,
    GE = 267,
    NE = 268,
    AND = 269,
    OR = 270,
    INC = 271,
    DEC = 272,
    NUM = 273,
    ID = 274,
    GLOBAL = 275,
    INT = 276,
    PTR = 277,
    ARR = 278
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GENERATED_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 151 "Generated/parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  163

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,    38,    41,     2,
      24,    25,    33,    36,    26,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
      35,    30,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    44,    44,    52,    60,    62,    63,    66,    67,    68,
      71,    72,    73,    76,    77,    78,    80,    81,    83,    84,
      87,    88,    89,    90,    91,    92,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   117,   118,   119,   120,   123,   124,
     125,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   143,   144,   145,   148
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "RETURN",
  "P_BEGIN", "P_END", "EQ", "LE", "GE", "NE", "AND", "OR", "INC", "DEC",
  "NUM", "ID", "GLOBAL", "INT", "PTR", "ARR", "'('", "')'", "','", "'{'",
  "'}'", "';'", "'='", "'['", "']'", "'*'", "'>'", "'<'", "'+'", "'-'",
  "'%'", "'/'", "'!'", "'&'", "$accept", "PROGRAM", "GLOBALS", "FUNCS",
  "FUNC", "PARAM", "PARAMS", "BLOCK", "STATS", "STAT", "STAT1", "EXPR",
  "EXPR2", "TERM", "VAL", "ARGS", "ARG", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    40,    41,    44,   123,   125,    59,
      61,    91,    93,    42,    62,    60,    43,    45,    37,    47,
      33,    38
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,   172,    44,    22,    61,    65,    70,    98,    73,   -83,
     -83,    34,   -83,    30,    39,    63,   134,   -83,   -83,    69,
      74,    76,   121,   121,   121,   -83,    -2,    86,    92,   112,
     121,   -83,   147,   121,   121,   121,    85,   -83,   -83,   162,
     145,    46,   -11,   209,   209,   209,   -83,   121,   121,   111,
       7,   121,   188,   -11,   -11,   121,   121,   121,   -20,     6,
     105,   194,    35,   -11,   -11,   -11,   -11,   -83,   -83,   121,
     121,   121,   121,   121,   121,   -83,   121,   121,   121,   121,
     121,   121,   121,   -83,   -83,   140,   151,   166,   -83,    51,
     116,   124,   200,   226,   121,   121,   -83,   307,   153,   -83,
     233,    32,   -83,   121,   -83,   121,    99,   -83,   121,   145,
     145,   145,   145,   145,   145,   145,   145,    46,    46,   145,
     -11,   -11,   -83,   -83,   -83,    22,   209,    22,    22,    22,
      22,   242,    78,   -83,   121,   -83,   123,   268,   275,   154,
     301,   -83,   -83,   -83,   -83,   185,   -83,   111,   -83,   -83,
     121,   -83,   -83,   161,   -83,    22,   191,   131,   -83,   -83,
      22,   -83,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       1,     0,     4,     0,     0,     0,     0,     3,     6,     0,
       0,     0,     0,     0,     0,    51,    59,     0,     0,     0,
       0,    17,     0,     0,     0,     0,     0,    18,    20,     0,
      35,    44,    48,    13,    13,    13,     2,     0,     0,     0,
      59,     0,     0,    56,    57,    64,     0,     0,     0,     0,
       0,     0,    59,    62,    52,    53,    61,    16,    19,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    54,    55,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,    25,    67,     0,    65,
       0,     0,    26,     0,    28,     0,     0,    58,     0,    36,
      37,    38,    39,    42,    43,    40,    41,    45,    46,    47,
      49,    50,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,    31,    63,     0,     0,     0,
       0,     7,    15,     8,     9,    22,    23,     0,    63,    66,
       0,    27,    29,     0,    32,     0,     0,     0,    30,    21,
       0,    33,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,   211,    -1,    94,    79,   -82,   -83,   190,
     -48,   -22,   -53,    68,   -21,   -83,    87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,     9,    88,    89,    12,    36,    37,
      38,    39,    40,    41,    42,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    94,    53,    54,   101,    83,    84,    18,    61,   102,
     103,    63,    64,    65,    66,    18,   109,   110,   111,   112,
     113,   114,    55,   115,   116,    92,    93,   119,    56,    57,
      63,    55,     1,    97,   100,   104,   105,    19,    95,    20,
      21,    22,   132,   141,    10,   143,   144,   145,   146,    11,
      23,    24,    25,    26,    43,    27,    28,    29,    30,    55,
     120,   121,    31,    44,   136,   108,    95,    32,    78,    79,
      80,    33,   131,   159,    34,    35,   125,   126,   162,    81,
      13,   137,    17,   138,    14,    82,   140,    45,    19,    15,
      20,    21,    22,    47,     4,     5,     6,   157,    48,   156,
      49,    23,    24,    25,    26,    58,    27,    28,    29,    30,
     148,    59,    97,    67,    78,    79,    80,   139,    32,     4,
       5,     6,    33,    90,    91,    34,    35,    23,    24,    25,
      26,    60,    27,    28,    29,    30,   106,    23,    24,    25,
      50,   127,   126,    46,    32,    30,   117,   118,    33,   128,
     126,    34,    35,   150,    51,     4,     5,     6,    33,   122,
     161,    34,    35,    23,    24,    25,    62,    78,    79,    80,
     123,    30,    69,    70,    71,    72,    73,    74,   133,   134,
      51,    78,    79,    80,    33,   124,   153,    34,    35,   155,
     158,    75,     3,     4,     5,     6,    76,    77,    69,    70,
      71,    72,    73,    74,    69,    70,    71,    72,    73,    74,
      69,    70,    71,    72,    73,    74,   160,    96,    16,   107,
     142,   149,    76,    77,     0,   129,    68,     0,    76,    77,
      85,    86,    87,     0,    76,    77,    69,    70,    71,    72,
      73,    74,     0,    69,    70,    71,    72,    73,    74,     0,
       0,   130,    69,    70,    71,    72,    73,    74,     0,     0,
      76,    77,   135,     0,     0,     0,     0,    76,    77,     0,
       0,   147,     0,     0,     0,     0,    76,    77,    69,    70,
      71,    72,    73,    74,     0,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,   151,     0,     0,
       0,     0,    76,    77,   152,     0,     0,     0,     0,    76,
      77,    69,    70,    71,    72,    73,    74,    69,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,    76,    77
};

static const yytype_int16 yycheck[] =
{
      22,    49,    23,    24,    57,    16,    17,     8,    30,    29,
      30,    32,    33,    34,    35,    16,    69,    70,    71,    72,
      73,    74,    24,    76,    77,    47,    48,    80,    30,    31,
      51,    24,     8,    55,    56,    29,    30,     3,    31,     5,
       6,     7,    95,   125,     0,   127,   128,   129,   130,    27,
      16,    17,    18,    19,    24,    21,    22,    23,    24,    24,
      81,    82,    28,    24,    32,    30,    31,    33,    36,    37,
      38,    37,    94,   155,    40,    41,    25,    26,   160,    33,
      19,   103,     9,   105,    19,    39,   108,    24,     3,    19,
       5,     6,     7,    24,    21,    22,    23,   150,    24,   147,
      24,    16,    17,    18,    19,    19,    21,    22,    23,    24,
      32,    19,   134,    28,    36,    37,    38,    18,    33,    21,
      22,    23,    37,    44,    45,    40,    41,    16,    17,    18,
      19,    19,    21,    22,    23,    24,    31,    16,    17,    18,
      19,    25,    26,     9,    33,    24,    78,    79,    37,    25,
      26,    40,    41,    30,    33,    21,    22,    23,    37,    19,
      29,    40,    41,    16,    17,    18,    19,    36,    37,    38,
      19,    24,    10,    11,    12,    13,    14,    15,    25,    26,
      33,    36,    37,    38,    37,    19,    32,    40,    41,     4,
      29,    29,    20,    21,    22,    23,    34,    35,    10,    11,
      12,    13,    14,    15,    10,    11,    12,    13,    14,    15,
      10,    11,    12,    13,    14,    15,    25,    29,     7,    25,
     126,   134,    34,    35,    -1,    25,    36,    -1,    34,    35,
      21,    22,    23,    -1,    34,    35,    10,    11,    12,    13,
      14,    15,    -1,    10,    11,    12,    13,    14,    15,    -1,
      -1,    25,    10,    11,    12,    13,    14,    15,    -1,    -1,
      34,    35,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    34,    35,    10,    11,
      12,    13,    14,    15,    -1,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    35,    29,    -1,    -1,    -1,    -1,    34,
      35,    10,    11,    12,    13,    14,    15,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    43,    20,    21,    22,    23,    44,    45,    46,
       0,    27,    49,    19,    19,    19,    45,     9,    46,     3,
       5,     6,     7,    16,    17,    18,    19,    21,    22,    23,
      24,    28,    33,    37,    40,    41,    50,    51,    52,    53,
      54,    55,    56,    24,    24,    24,     9,    24,    24,    24,
      19,    33,    53,    56,    56,    24,    30,    31,    19,    19,
      19,    53,    19,    56,    56,    56,    56,    28,    51,    10,
      11,    12,    13,    14,    15,    29,    34,    35,    36,    37,
      38,    33,    39,    16,    17,    21,    22,    23,    47,    48,
      48,    48,    53,    53,    52,    31,    29,    53,    57,    58,
      53,    54,    29,    30,    29,    30,    31,    25,    30,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    54,
      56,    56,    19,    19,    19,    25,    26,    25,    25,    25,
      25,    53,    54,    25,    26,    29,    32,    53,    53,    18,
      53,    49,    47,    49,    49,    49,    49,    29,    32,    58,
      30,    29,    29,    32,    29,     4,    52,    54,    29,    49,
      25,    29,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    45,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    54,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     2,     6,     6,     6,
       2,     2,     2,     0,     1,     3,     3,     2,     1,     2,
       1,     7,     5,     5,     8,     3,     3,     5,     3,     5,
       6,     4,     5,     7,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     2,     2,     2,     2,     2,     2,     3,     1,
       4,     2,     2,     4,     0,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 44 "MiniC.y" /* yacc.c:1646  */
    {
                                                    Program& p = Program::Instance();
                                                    p.setGlobals((yyvsp[-2].globs));
                                                    p.setFuncs((yyvsp[-1].funcs));
                                                    p.run();
                                                    p.finalize();
                                                    delete (yyvsp[-2].globs);
                                                }
#line 1370 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "MiniC.y" /* yacc.c:1646  */
    {
                                                    Program& p = Program::Instance();
                                                    p.setFuncs((yyvsp[-1].funcs));
                                                    p.run();
                                                    p.finalize();
                                                }
#line 1381 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 60 "MiniC.y" /* yacc.c:1646  */
    { (yyval.globs) = new Globals((yyvsp[0].block)); }
#line 1387 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 62 "MiniC.y" /* yacc.c:1646  */
    { (yyval.funcs).clear(); (yyval.funcs).push_back((yyvsp[0].func)); }
#line 1393 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 63 "MiniC.y" /* yacc.c:1646  */
    { (yyval.funcs) = (yyvsp[-1].funcs); (yyval.funcs).push_back((yyvsp[0].func)); }
#line 1399 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "MiniC.y" /* yacc.c:1646  */
    { (yyval.func) = new Function((yyvsp[-4].str), T_INT, (yyvsp[-2].params), (yyvsp[0].block)); }
#line 1405 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 67 "MiniC.y" /* yacc.c:1646  */
    { (yyval.func) = new Function((yyvsp[-4].str), T_PTR, (yyvsp[-2].params), (yyvsp[0].block)); }
#line 1411 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 68 "MiniC.y" /* yacc.c:1646  */
    { (yyval.func) = new Function((yyvsp[-4].str), T_ARR, (yyvsp[-2].params), (yyvsp[0].block)); }
#line 1417 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "MiniC.y" /* yacc.c:1646  */
    { (yyval.param) = new Parameter(T_INT, (yyvsp[0].str)); }
#line 1423 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 72 "MiniC.y" /* yacc.c:1646  */
    { (yyval.param) = new Parameter(T_PTR, (yyvsp[0].str)); }
#line 1429 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 73 "MiniC.y" /* yacc.c:1646  */
    { (yyval.param) = new Parameter(T_ARR, (yyvsp[0].str)); }
#line 1435 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 76 "MiniC.y" /* yacc.c:1646  */
    { (yyval.params).clear(); }
#line 1441 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 77 "MiniC.y" /* yacc.c:1646  */
    { (yyval.params).clear(); (yyval.params).push_back((yyvsp[0].param)); }
#line 1447 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 78 "MiniC.y" /* yacc.c:1646  */
    { (yyval.params) = (yyvsp[-2].params); (yyval.params).push_back((yyvsp[0].param)); }
#line 1453 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 80 "MiniC.y" /* yacc.c:1646  */
    { (yyval.block) = new Block((yyvsp[-1].statements)); }
#line 1459 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 81 "MiniC.y" /* yacc.c:1646  */
    { (yyval.block) = new Block(); }
#line 1465 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statements).clear(); (yyval.statements).push_back((yyvsp[0].statement)); }
#line 1471 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 84 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statements) = (yyvsp[-1].statements); (yyval.statements).push_back((yyvsp[0].statement)); }
#line 1477 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 87 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyval.statement); }
#line 1483 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 88 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<IfStatement>((yyvsp[-4].expr), (yyvsp[-2].block), (yyvsp[0].block)); }
#line 1489 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 89 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<IfStatement>((yyvsp[-2].expr), (yyvsp[0].block), nullptr); }
#line 1495 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 90 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<WhileStatement>((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1501 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 91 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<ForStatement>((yyvsp[-5].statement), (yyvsp[-4].expr), (yyvsp[-2].statement), (yyvsp[0].block)); }
#line 1507 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 92 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<ReturnStatement>((yyvsp[-1].expr)); }
#line 1513 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 95 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<DefStatement>(T_INT, (yyvsp[-1].str), nullptr); }
#line 1519 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 96 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<DefStatement>(T_INT, (yyvsp[-3].str), (yyvsp[-1].expr)); }
#line 1525 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 97 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<DefStatement>(T_PTR, (yyvsp[-1].str), nullptr); }
#line 1531 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 98 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<DefStatement>(T_PTR, (yyvsp[-3].str), (yyvsp[-1].expr)); }
#line 1537 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 99 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<DefStatement>(T_ARR, (yyvsp[-4].str), (yyvsp[-2].str), nullptr); }
#line 1543 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 100 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<AssignStatement>((yyvsp[-3].str), (yyvsp[-1].expr)); }
#line 1549 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 101 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<AssignStatement>((yyvsp[-3].str), (yyvsp[-1].expr), true); }
#line 1555 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 102 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<AssignStatement>((yyvsp[-6].str), (yyvsp[-1].expr), (yyvsp[-4].expr)); }
#line 1561 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 103 "MiniC.y" /* yacc.c:1646  */
    { (yyval.statement) = std::make_shared<ExprStatement>((yyvsp[-1].expr)); }
#line 1567 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 107 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("==", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1573 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 108 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("<=", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1579 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 109 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression(">=", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1585 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 110 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("!=", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1591 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 111 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression(">", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1597 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 112 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("<", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1603 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 113 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("&&", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1609 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 114 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("||", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1615 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 118 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("+", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1621 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 119 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("-", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1627 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 120 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("%", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1633 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 124 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("*", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1639 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 125 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression("/", (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1645 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 128 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new ValueExpression((yyvsp[0].str)); }
#line 1651 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 129 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryExpression("-", (yyvsp[0].expr)); }
#line 1657 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 130 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryExpression("!", (yyvsp[0].expr)); }
#line 1663 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 131 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryExpression(".++", (yyvsp[-1].expr)); }
#line 1669 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 132 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryExpression(".--", (yyvsp[-1].expr)); }
#line 1675 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 133 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryExpression("++.", (yyvsp[0].expr)); }
#line 1681 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 134 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryExpression("--.", (yyvsp[0].expr)); }
#line 1687 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 135 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1693 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 136 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new VarExpression((yyvsp[0].str)); }
#line 1699 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 137 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunCallExpression((yyvsp[-3].str), (yyvsp[-1].args)); }
#line 1705 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 138 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryExpression("&", (yyvsp[0].expr)); }
#line 1711 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 139 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new UnaryExpression("*", (yyvsp[0].expr)); }
#line 1717 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 140 "MiniC.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrayAtExpression((yyvsp[-3].str), (yyvsp[-1].expr)); }
#line 1723 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 143 "MiniC.y" /* yacc.c:1646  */
    { (yyval.args).clear(); }
#line 1729 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 144 "MiniC.y" /* yacc.c:1646  */
    { (yyval.args).clear(); (yyval.args).push_back((yyvsp[0].expr)); }
#line 1735 "Generated/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 145 "MiniC.y" /* yacc.c:1646  */
    { (yyval.args) = (yyvsp[-2].args); (yyval.args).push_back((yyvsp[0].expr)); }
#line 1741 "Generated/parser.cpp" /* yacc.c:1646  */
    break;


#line 1745 "Generated/parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 152 "MiniC.y" /* yacc.c:1906  */

int main() { return yyparse(); }


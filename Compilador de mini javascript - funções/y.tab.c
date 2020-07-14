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
#line 1 "mini_js.y" /* yacc.c:339  */

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>


using namespace std;

struct Atributos {
	vector<string> v;
	int id;
};

#define YYSTYPE Atributos

#define st first
#define nd second

#define jump "#"
#define get "@"
#define set "="
#define jumpTrue "?"
#define let "&"
#define getProp "[@]"
#define setProp "[=]"
#define callFunc "$"
#define retFunc "~"
#define pop "^"
#define halt "."

void erro( string msg );
void New_Inst( string st ); //nova instrução
void New_Inst( vector<string> &st );

void New_FInst( string st ); //nova instrução dentro de funcao
void New_FInst( vector<string> &st );

void New_Line();

void New_Func_Line();

void imprime_codigo();
void get_var(vector<string> v);
void let_var(vector<string> v);
void empilha_escopo();
void desempilha_escopo();
string gera_ini_label(string pref,int id);
string gera_fim_label(string pref,int id);
int get_id();
int get_func_id();

void lista_arg(string k, int arg_num);

string trim(string s, char l, char r);
vector<string> tokeniza(string s);


// protótipo para o analisador léxico (gerado pelo lex)
int yylex();
void yyerror( const char* );
int retorna( int tk );

int linha = 1;
int coluna = 1;


vector<string> codigo;
vector<string> func_codigo;
vector<map<string,int>> var_globais;

vector<string> operator+( vector<string> a, vector<string> b ) {
	a.insert( a.end(), b.begin(), b.end() );
	return a;
}

vector<string> operator+( vector<string> a, string b ) {
	a.push_back(b);
	return a;
}
vector<string> operator+( string a, vector<string> b ) {
	return b+a;
}


#line 153 "y.tab.c" /* yacc.c:339  */

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
    NUM = 258,
    NEGNUM = 259,
    STR = 260,
    ID = 261,
    LET = 262,
    NEWOBJ = 263,
    NEWARRAY = 264,
    IF = 265,
    ELSE = 266,
    IGUAL = 267,
    MAI_IG = 268,
    MEN_IG = 269,
    RETURN = 270,
    FUNCTION = 271,
    ASM = 272
  };
#endif
/* Tokens.  */
#define NUM 258
#define NEGNUM 259
#define STR 260
#define ID 261
#define LET 262
#define NEWOBJ 263
#define NEWARRAY 264
#define IF 265
#define ELSE 266
#define IGUAL 267
#define MAI_IG 268
#define MEN_IG 269
#define RETURN 270
#define FUNCTION 271
#define ASM 272

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 235 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   482

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  187
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  333

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    23,     2,     2,
      26,    27,    21,    19,    30,    20,    18,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      33,    24,    34,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      15,    16,    17
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   100,   100,   100,   103,   104,   105,   106,   106,   108,
     108,   109,   128,   109,   129,   130,   133,   136,   137,   138,
     139,   139,   142,   143,   144,   147,   148,   154,   156,   147,
     160,   161,   164,   164,   165,   165,   166,   167,   170,   170,
     173,   174,   177,   177,   178,   181,   182,   182,   183,   185,
     186,   186,   187,   187,   188,   188,   192,   195,   196,   197,
     198,   199,   201,   202,   203,   204,   205,   206,   209,   210,
     211,   212,   213,   216,   217,   218,   219,   220,   221,   224,
     225,   226,   227,   228,   229,   233,   234,   235,   236,   237,
     238,   242,   243,   246,   247,   250,   251,   253,   254,   262,
     263,   264,   265,   265,   267,   267,   271,   278,   279,   280,
     281,   283,   283,   288,   289,   290,   293,   294,   300,   302,
     293,   306,   307,   310,   310,   311,   311,   312,   313,   316,
     316,   319,   320,   323,   323,   324,   328,   329,   329,   330,
     332,   333,   333,   333,   334,   334,   334,   335,   335,   335,
     339,   340,   341,   342,   343,   345,   346,   347,   348,   349,
     350,   353,   354,   355,   356,   357,   360,   361,   362,   363,
     364,   365,   368,   369,   370,   371,   372,   373,   377,   378,
     379,   380,   381,   382,   385,   386,   389,   390
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "NEGNUM", "STR", "ID", "LET",
  "NEWOBJ", "NEWARRAY", "IF", "ELSE", "IGUAL", "MAI_IG", "MEN_IG",
  "RETURN", "FUNCTION", "ASM", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'='", "';'", "'('", "')'", "'{'", "'}'", "','", "'['", "']'", "'<'",
  "'>'", "$accept", "START", "$@1", "CMD", "$@2", "$@3", "$@4", "$@5",
  "FUNCTION_CALL", "CMD_LINHA", "$@6", "BLOCO", "IF_LINHA", "$@7", "$@8",
  "$@9", "$@10", "ELSE_LINHA", "Decl", "$@11", "$@12", "Adecl", "$@13",
  "P", "A", "$@14", "LVALUEPROP", "$@15", "LVALUEPROPSUFFIX", "$@16",
  "$@17", "$@18", "FIM_LVALUE", "RVALUE", "E", "COND", "ELPROP", "FLPROP",
  "F", "PARAM_CHA", "ARGs_CHA", "PARAM_FUN", "ARGs_FUN", "CMD_FUN", "$@19",
  "$@20", "CMD_FUN_LINHA_FUN", "$@21", "BLOCO_FUN", "IF_LINHA_FUN", "$@22",
  "$@23", "$@24", "$@25", "ELSE_LINHA_FUN", "Decl_FUN", "$@26", "$@27",
  "Adecl_FUN", "$@28", "P_FUN", "A_FUN", "$@29", "LVALUEPROP_FUN", "$@30",
  "LVALUEPROP_FUNSUFFIX", "$@31", "$@32", "$@33", "$@34", "$@35", "$@36",
  "RVALUE_FUN", "E_FUN", "COND_FUN", "ELPROP_FUN", "FLPROP_FUN", "F_FUN",
  "PARAM_CHA_FUN", "ARGs_CHA_FUN", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    46,    43,
      45,    42,    47,    37,    61,    59,    40,    41,   123,   125,
      44,    91,    93,    60,    62
};
# endif

#define YYPACT_NINF -270

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-270)))

#define YYTABLE_NINF -134

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -270,     7,   257,  -270,  -270,  -270,  -270,     0,    12,    11,
      22,    64,  -270,    32,   257,   257,    41,    47,   352,  -270,
      64,    54,   -10,   257,    -3,    50,  -270,  -270,  -270,  -270,
    -270,    56,   416,  -270,  -270,  -270,   155,    64,    72,    64,
      50,    50,    50,    50,    50,   257,    50,    51,    80,  -270,
      64,    81,    83,    86,  -270,  -270,    12,  -270,  -270,   322,
      87,    90,  -270,   257,    98,  -270,   416,  -270,  -270,  -270,
     111,  -270,   133,   133,   102,   102,   102,  -270,   366,    64,
    -270,  -270,    12,  -270,    64,  -270,    50,    50,    50,    50,
      50,  -270,   129,  -270,   257,  -270,   107,   121,  -270,  -270,
    -270,   416,   416,   416,   416,   416,  -270,  -270,   114,   112,
    -270,    64,    64,   251,  -270,   169,   116,   141,  -270,   117,
    -270,  -270,  -270,   125,    64,   328,  -270,    64,    12,   257,
    -270,  -270,   257,   143,   373,   311,  -270,   251,    64,   139,
     251,   251,   251,   251,   251,  -270,  -270,  -270,   148,   159,
    -270,  -270,   166,  -270,  -270,  -270,   156,   187,   173,    97,
      97,   165,   311,   311,   176,   180,   388,  -270,   423,   188,
    -270,   103,   103,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
     193,    70,   311,    33,   276,    24,  -270,  -270,  -270,  -270,
     430,   191,  -270,  -270,  -270,   302,    97,   194,   214,   276,
     276,   276,   276,   276,   276,  -270,  -270,   169,   257,    97,
     192,   199,   207,  -270,  -270,   187,  -270,  -270,   345,   209,
      97,   218,  -270,   257,  -270,   430,  -270,  -270,  -270,  -270,
     167,   167,   203,   203,   203,   394,  -270,  -270,  -270,   187,
    -270,    97,  -270,   276,   276,   276,   276,   276,  -270,   215,
     220,  -270,   311,  -270,   311,  -270,   241,   247,   250,  -270,
    -270,   430,   430,   430,   430,   430,  -270,    97,  -270,  -270,
    -270,   239,  -270,  -270,  -270,   294,  -270,   326,   214,   214,
     214,   187,    97,   311,  -270,  -270,   311,   246,   410,  -270,
    -270,  -270,   248,    97,   437,  -270,  -270,   244,  -270,  -270,
    -270,   243,   265,  -270,  -270,   253,    97,   262,   326,   326,
     326,   326,   326,  -270,   326,   266,  -270,  -270,  -270,  -270,
     263,  -270,   186,   186,  -270,  -270,  -270,   443,  -270,   294,
    -270,  -270,  -270
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    15,     1,    86,    87,    88,    85,     0,     0,
       0,     0,     3,     0,    15,    15,     0,    90,     0,    67,
      92,     0,    32,    15,     0,     0,    11,    58,    59,    61,
      60,     0,    57,     9,     6,     5,    41,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,    94,     0,    91,
       0,     0,     0,     0,     4,    37,     0,    85,    90,     0,
       0,     0,    89,    15,    85,    40,     0,    44,     7,    45,
      49,    56,    62,    63,    64,    65,    66,    14,     0,     0,
      16,    43,     0,    35,     0,    36,     0,     0,     0,     0,
       0,    25,    96,    10,    15,    52,     0,    48,    93,    33,
      39,    70,    71,    72,    68,    69,    26,    98,     0,    95,
       8,     0,     0,     0,    46,    24,     0,     0,    53,     0,
      80,    81,    82,    79,     0,     0,    78,     0,     0,    15,
      22,    27,    15,     0,     0,   106,    97,     0,    92,     0,
       0,     0,     0,     0,     0,    51,    47,    18,     0,    30,
      19,    17,     0,   179,   180,   181,   178,     0,     0,     0,
       0,     0,   106,   106,     0,   183,     0,   160,     0,     0,
      83,    73,    74,    75,    76,    77,    23,    31,    28,    20,
       0,   123,   106,     0,     0,   178,   151,   152,   153,   104,
     150,     0,    12,   101,   100,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    84,    24,    15,     0,
       0,     0,     0,    99,   128,     0,   178,   183,     0,     0,
     185,     0,   182,    15,   131,     0,   135,   102,   140,   136,
     155,   156,   157,   158,   159,     0,    29,    21,   134,     0,
     126,     0,   127,     0,     0,     0,     0,     0,   116,   187,
       0,   184,   106,    13,   106,   142,     0,     0,   139,   124,
     130,   163,   164,   165,   161,   162,   117,     0,   154,   105,
     103,     0,   145,   148,   137,   115,   186,     0,     0,     0,
       0,     0,     0,   106,   113,   118,   106,     0,     0,   173,
     174,   175,   172,     0,     0,   171,   146,     0,   138,   108,
     111,     0,   121,   109,   107,     0,   185,     0,     0,     0,
       0,     0,     0,   143,     0,     0,   114,   122,   119,   110,
       0,   176,   166,   167,   168,   169,   170,     0,   112,   115,
     177,   149,   120
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -270,  -270,   -12,  -270,  -270,  -270,  -270,     2,  -270,
    -270,    96,  -114,  -270,  -270,  -270,  -270,  -270,   -51,  -270,
    -270,  -270,  -270,   274,    25,  -270,   198,  -270,   -92,  -270,
    -270,  -270,  -270,    78,    -2,  -270,   330,  -270,  -270,   175,
     232,  -270,  -270,  -133,  -270,  -270,  -270,  -270,    -6,  -269,
    -270,  -270,  -270,  -270,  -270,  -207,  -270,  -270,  -270,  -270,
     124,   -83,  -270,    49,  -270,   -66,  -270,  -270,  -270,  -270,
    -270,  -270,  -150,   -17,  -270,   168,  -270,  -270,    18,    58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    12,    94,    63,    61,   223,    29,   130,
     208,   131,    14,   106,   115,   149,   207,   178,    23,    51,
      52,    24,    53,    15,    16,    21,    17,   127,    69,    96,
     111,   112,    70,    71,    32,    60,   125,   126,    19,    48,
      49,   108,   109,   161,   254,   221,   284,   315,   285,   162,
     266,   275,   302,   329,   318,   182,   210,   211,   183,   212,
     163,   188,   180,   165,   280,   229,   255,   271,   256,   278,
     257,   279,   249,   190,   219,   294,   295,   167,   250,   251
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,   132,    34,    35,    13,    85,   286,     3,   242,   189,
     191,    54,    18,    18,   -38,   -34,    13,    13,    22,   118,
     119,    18,    55,    59,   -42,    13,    20,    56,    26,   193,
     194,    99,   259,    77,    66,   146,    30,    25,    72,    73,
      74,    75,    76,    18,    78,    30,   226,    13,  -133,   213,
     220,    93,   164,     4,     5,     6,    57,    33,   214,   238,
     286,    18,    30,   215,    30,    13,    36,     4,     5,     6,
       7,    37,    27,    28,   299,    30,    11,   147,    50,   164,
     164,    79,   110,    62,   101,   102,   103,   104,   105,    31,
      11,   260,    18,   132,  -129,  -125,    13,    68,    47,   164,
     153,   154,   155,   185,    30,   186,   187,    80,    83,    30,
      84,    82,   164,   134,    91,    67,    92,   148,   166,   269,
     150,   270,   -42,   160,   142,   143,   144,    18,    81,    95,
      18,    13,   300,    46,    13,   107,    30,    30,   113,   114,
     133,   116,   117,   307,   135,   166,   166,   136,   137,    30,
     301,   138,    30,   303,    42,    43,    44,    47,     4,     5,
       6,    64,   100,    30,    46,   166,   170,   218,   151,   164,
     177,   164,     4,     5,     6,    64,   128,   176,   225,     9,
    -133,    11,   230,   231,   232,   233,   234,   235,   201,   202,
     203,   179,   287,   181,   192,    11,   237,   129,   204,   184,
     164,   195,   139,   164,   196,   134,    18,   310,   311,   312,
      13,   253,   296,   297,   298,   206,    47,   209,   222,   227,
     228,    18,   239,    58,   240,    13,   261,   262,   263,   264,
     265,   241,   133,   217,   204,   166,   248,   166,    58,    58,
      58,    58,    58,   252,    58,   267,   287,   268,   217,   217,
     217,   217,   217,   217,   120,   121,   122,   123,   288,   272,
       4,     5,     6,     7,     8,   273,   166,     9,   274,   166,
     277,   304,   316,    10,   306,   314,   317,   124,   319,   153,
     154,   155,   216,    11,    58,    58,    58,    58,    58,   321,
     330,   328,   217,   217,   217,   217,   217,   153,   154,   155,
     156,   281,   160,   236,   158,   153,   154,   155,   156,   282,
      65,    98,   288,   169,   153,   154,   155,   156,   157,   224,
     160,   158,   283,   332,   320,   276,   159,     0,   160,   289,
     290,   291,   292,     0,    86,    87,    88,   160,     0,     0,
      39,    40,    41,    42,    43,    44,     0,   140,   141,   142,
     143,   144,   293,    46,     0,    89,    90,   243,   244,   245,
     145,     0,     0,   198,   199,   200,   201,   202,   203,    38,
      39,    40,    41,    42,    43,    44,   204,    45,   246,   247,
       0,     0,     0,    46,    39,    40,    41,    42,    43,    44,
     152,    39,    40,    41,    42,    43,    44,    46,    97,     0,
       0,     0,     0,     0,    46,   197,   198,   199,   200,   201,
     202,   203,   198,   199,   200,   201,   202,   203,     0,   204,
       0,     0,     0,     0,     0,   204,   258,   305,   198,   199,
     200,   201,   202,   203,    39,    40,    41,    42,    43,    44,
       0,   204,   140,   141,   142,   143,   144,    46,   198,   199,
     200,   201,   202,   203,     0,   205,   308,   309,   310,   311,
     312,   204,   308,   309,   310,   311,   312,   168,     0,   313,
     171,   172,   173,   174,   175,   331,   322,   323,   324,   325,
     326,     0,   327
};

static const yytype_int16 yycheck[] =
{
       2,   115,    14,    15,     2,    56,   275,     0,   215,   159,
     160,    23,    14,    15,    24,    25,    14,    15,     6,   111,
     112,    23,    25,    25,    24,    23,    26,    30,     6,   162,
     163,    82,   239,    45,    36,   127,    11,    26,    40,    41,
      42,    43,    44,    45,    46,    20,   196,    45,    24,   182,
      26,    63,   135,     3,     4,     5,     6,    25,    25,   209,
     329,    63,    37,    30,    39,    63,    25,     3,     4,     5,
       6,    24,     8,     9,   281,    50,    26,   128,    24,   162,
     163,    30,    94,    27,    86,    87,    88,    89,    90,    11,
      26,   241,    94,   207,    24,    25,    94,    25,    20,   182,
       3,     4,     5,     6,    79,     8,     9,    27,    25,    84,
      24,    30,   195,   115,    27,    37,    26,   129,   135,   252,
     132,   254,    24,    26,    21,    22,    23,   129,    50,    18,
     132,   129,   282,    31,   132,     6,   111,   112,    31,    18,
     115,    27,    30,   293,    28,   162,   163,     6,    31,   124,
     283,    26,   127,   286,    21,    22,    23,    79,     3,     4,
       5,     6,    84,   138,    31,   182,    27,   184,    25,   252,
      11,   254,     3,     4,     5,     6,     7,    29,   195,    10,
      24,    26,   199,   200,   201,   202,   203,   204,    21,    22,
      23,    25,   275,     6,    29,    26,   208,    28,    31,    26,
     283,    25,   124,   286,    24,   207,   208,    21,    22,    23,
     208,   223,   278,   279,   280,    27,   138,    24,    27,    25,
       6,   223,    30,    25,    25,   223,   243,   244,   245,   246,
     247,    24,   207,   184,    31,   252,    27,   254,    40,    41,
      42,    43,    44,    25,    46,    30,   329,    27,   199,   200,
     201,   202,   203,   204,     3,     4,     5,     6,   275,    18,
       3,     4,     5,     6,     7,    18,   283,    10,    18,   286,
      31,    25,    29,    16,    26,    31,    11,    26,    25,     3,
       4,     5,     6,    26,    86,    87,    88,    89,    90,    27,
      27,    25,   243,   244,   245,   246,   247,     3,     4,     5,
       6,     7,    26,   207,    10,     3,     4,     5,     6,    15,
      36,    79,   329,   138,     3,     4,     5,     6,     7,   195,
      26,    10,    28,   329,   306,   267,    15,    -1,    26,     3,
       4,     5,     6,    -1,    12,    13,    14,    26,    -1,    -1,
      18,    19,    20,    21,    22,    23,    -1,    19,    20,    21,
      22,    23,    26,    31,    -1,    33,    34,    12,    13,    14,
      32,    -1,    -1,    18,    19,    20,    21,    22,    23,    17,
      18,    19,    20,    21,    22,    23,    31,    25,    33,    34,
      -1,    -1,    -1,    31,    18,    19,    20,    21,    22,    23,
      17,    18,    19,    20,    21,    22,    23,    31,    32,    -1,
      -1,    -1,    -1,    -1,    31,    17,    18,    19,    20,    21,
      22,    23,    18,    19,    20,    21,    22,    23,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    31,    32,    17,    18,    19,
      20,    21,    22,    23,    18,    19,    20,    21,    22,    23,
      -1,    31,    19,    20,    21,    22,    23,    31,    18,    19,
      20,    21,    22,    23,    -1,    32,    19,    20,    21,    22,
      23,    31,    19,    20,    21,    22,    23,   137,    -1,    32,
     140,   141,   142,   143,   144,    32,   308,   309,   310,   311,
     312,    -1,   314
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    37,     0,     3,     4,     5,     6,     7,    10,
      16,    26,    38,    43,    47,    58,    59,    61,    69,    73,
      26,    60,     6,    53,    56,    26,     6,     8,     9,    43,
      59,    68,    69,    25,    38,    38,    25,    24,    17,    18,
      19,    20,    21,    22,    23,    25,    31,    68,    74,    75,
      24,    54,    55,    57,    38,    25,    30,     6,    61,    69,
      70,    41,    27,    40,     6,    58,    69,    68,    25,    63,
      67,    68,    69,    69,    69,    69,    69,    38,    69,    30,
      27,    68,    30,    25,    24,    53,    12,    13,    14,    33,
      34,    27,    26,    38,    39,    18,    64,    32,    75,    53,
      68,    69,    69,    69,    69,    69,    48,     6,    76,    77,
      38,    65,    66,    31,    18,    49,    27,    30,    63,    63,
       3,     4,     5,     6,    26,    71,    72,    62,     7,    28,
      44,    46,    47,    59,    69,    28,     6,    31,    26,    68,
      19,    20,    21,    22,    23,    32,    63,    53,    38,    50,
      38,    25,    17,     3,     4,     5,     6,     7,    10,    15,
      26,    78,    84,    95,    96,    98,   108,   112,    71,    74,
      27,    71,    71,    71,    71,    71,    29,    11,    52,    25,
      97,     6,    90,    93,    26,     6,     8,     9,    96,   107,
     108,   107,    29,    78,    78,    25,    24,    17,    18,    19,
      20,    21,    22,    23,    31,    32,    27,    51,    45,    24,
      91,    92,    94,    78,    25,    30,     6,    98,   108,   109,
      26,    80,    27,    42,    95,   108,   107,    25,     6,   100,
     108,   108,   108,   108,   108,   108,    46,    38,   107,    30,
      25,    24,    90,    12,    13,    14,    33,    34,    27,   107,
     113,   114,    25,    38,    79,   101,   103,   105,    32,    90,
     107,   108,   108,   108,   108,   108,    85,    30,    27,    78,
      78,   102,    18,    18,    18,    86,   114,    31,   104,   106,
      99,     7,    15,    28,    81,    83,    84,    96,   108,     3,
       4,     5,     6,    26,   110,   111,   100,   100,   100,    90,
     107,    78,    87,    78,    25,    17,    26,   107,    19,    20,
      21,    22,    23,    32,    31,    82,    29,    11,    89,    25,
     113,    27,   110,   110,   110,   110,   110,   110,    25,    88,
      27,    32,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    37,    36,    38,    38,    38,    39,    38,    40,
      38,    41,    42,    38,    38,    38,    43,    44,    44,    44,
      45,    44,    46,    46,    46,    48,    49,    50,    51,    47,
      52,    52,    54,    53,    55,    53,    53,    53,    57,    56,
      58,    58,    60,    59,    59,    61,    62,    61,    61,    63,
      64,    63,    65,    63,    66,    63,    67,    68,    68,    68,
      68,    68,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    78,    79,    78,    80,    78,    78,    81,    81,    81,
      81,    82,    81,    83,    83,    83,    85,    86,    87,    88,
      84,    89,    89,    91,    90,    92,    90,    90,    90,    94,
      93,    95,    95,    97,    96,    96,    98,    99,    98,    98,
     100,   101,   102,   100,   103,   104,   100,   105,   106,   100,
     107,   107,   107,   107,   107,   108,   108,   108,   108,   108,
     108,   109,   109,   109,   109,   109,   110,   110,   110,   110,
     110,   110,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   112,   112,   113,   113,   114,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     2,     2,     0,     5,     0,
       4,     0,     0,    11,     3,     0,     4,     2,     2,     2,
       0,     5,     1,     3,     0,     0,     0,     0,     0,    11,
       0,     1,     0,     4,     0,     3,     3,     2,     0,     4,
       3,     2,     0,     4,     3,     3,     0,     7,     4,     1,
       0,     5,     0,     4,     0,     7,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     4,     1,     1,     1,     1,     3,
       1,     1,     0,     3,     1,     1,     0,     3,     1,     3,
       2,     2,     0,     5,     0,     5,     0,     2,     2,     2,
       3,     0,     4,     1,     3,     0,     0,     0,     0,     0,
      11,     0,     1,     0,     4,     0,     3,     3,     2,     0,
       4,     3,     2,     0,     4,     3,     3,     0,     7,     4,
       1,     0,     0,     6,     0,     0,     5,     0,     0,     8,
       1,     1,     1,     1,     4,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     3,     4,     1,     1,
       1,     1,     3,     1,     1,     0,     3,     1
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
#line 100 "mini_js.y" /* yacc.c:1646  */
    {empilha_escopo();}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 106 "mini_js.y" /* yacc.c:1646  */
    { for(auto i:(yyvsp[-1]).v)New_Inst(i);
	New_Line();}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 108 "mini_js.y" /* yacc.c:1646  */
    {New_Line();}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "mini_js.y" /* yacc.c:1646  */
    { 
	   
	   let_var((yyvsp[0]).v);
	
	   New_Inst( (yyvsp[0]).v ); 
	   New_Inst(let); 
	   New_Inst( (yyvsp[0]).v );
	   New_Inst("{}");
	   New_Inst(set);
	   New_Inst("'&funcao'");
	   (yyvsp[-1]).id=get_func_id();
	   New_Inst(gera_ini_label("FUNC",(yyvsp[-1]).id));
	   New_Inst(setProp);
	   New_Inst(pop);
	   New_Line();
	   New_FInst(gera_fim_label("FUNC",(yyvsp[-1]).id));
	   New_Func_Line();
	   empilha_escopo();
	  }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 128 "mini_js.y" /* yacc.c:1646  */
    {desempilha_escopo();New_Line();}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 133 "mini_js.y" /* yacc.c:1646  */
    {New_Inst((yyvsp[-3]).v); New_Inst(get); New_Inst(callFunc);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 139 "mini_js.y" /* yacc.c:1646  */
    { for(auto i:(yyvsp[-1]).v)New_Inst(i);
	New_Line();}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 147 "mini_js.y" /* yacc.c:1646  */
    {(yyvsp[-3]).id=get_id();}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 148 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(gera_ini_label("INI_IF",(yyvsp[-4]).id));New_Inst(jumpTrue);
           New_Line();
           New_Inst(gera_ini_label("ELSE_IF",(yyvsp[-4]).id));New_Inst(jump);
           New_Line();
           New_Inst(gera_fim_label("INI_IF",(yyvsp[-4]).id));}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(gera_ini_label("FIM_IF",(yyvsp[-6]).id));New_Inst(jump);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 156 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(gera_fim_label("ELSE_IF",(yyvsp[-8]).id));}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 157 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(gera_fim_label("FIM_IF",(yyvsp[-10]).id));}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 164 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( (yyvsp[0]).v ); let_var((yyvsp[0]).v); New_Inst(let); New_Line();}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 165 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( (yyvsp[0]).v ); let_var((yyvsp[0]).v); New_Inst(let); New_Line();}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 170 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( (yyvsp[0]).v ); let_var((yyvsp[0]).v); New_Inst(let); New_Inst( (yyvsp[0]).v ); }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 170 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( set ); New_Inst( pop ); New_Line(); }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 177 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( (yyvsp[0]).v ); get_var((yyvsp[0]).v);}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 177 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( set ); New_Inst( pop ); New_Line(); }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 178 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( setProp ); New_Inst( pop ); New_Line(); }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 182 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(getProp);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 186 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(getProp);}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 187 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(getProp);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 188 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(getProp);}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 196 "mini_js.y" /* yacc.c:1646  */
    {New_Inst("{}");}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 197 "mini_js.y" /* yacc.c:1646  */
    {New_Inst("[]");}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 198 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( (yyvsp[0]).v ); get_var((yyvsp[0]).v); New_Inst(get);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 201 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "+" ); }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 202 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "-" ); }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 203 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "*" ); }
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 204 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "/" ); }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 205 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "%" ); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 209 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "<" ); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 210 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( ">" ); }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 211 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "==" ); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 212 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( ">=" ); }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 213 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "<=" ); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 216 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "+" ); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 217 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "-" ); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 218 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "*" ); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 219 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "/" ); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 220 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( "%" ); }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 224 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( (yyvsp[0]).v ); }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 225 "mini_js.y" /* yacc.c:1646  */
    { New_Inst(	(yyvsp[0]).v ); }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 226 "mini_js.y" /* yacc.c:1646  */
    {int sz=(yyvsp[0]).v.size()-1; (yyvsp[0]).v[sz]=(yyvsp[0]).v[sz].substr(1);New_Inst("0"); New_Inst((yyvsp[0]).v[sz] ); New_Inst("-");}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 227 "mini_js.y" /* yacc.c:1646  */
    { New_Inst(	(yyvsp[0]).v ); }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 229 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( (yyvsp[-3]).v ); New_Inst(jump) ;}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 233 "mini_js.y" /* yacc.c:1646  */
    { New_Inst( (yyvsp[0]).v ); get_var((yyvsp[0]).v); New_Inst(get); }
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 234 "mini_js.y" /* yacc.c:1646  */
    { New_Inst(	(yyvsp[0]).v ); }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 235 "mini_js.y" /* yacc.c:1646  */
    {int sz=(yyvsp[0]).v.size()-1; (yyvsp[0]).v[sz]=(yyvsp[0]).v[sz].substr(1);New_Inst("0"); New_Inst((yyvsp[0]).v[sz] ); New_Inst("-");}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 236 "mini_js.y" /* yacc.c:1646  */
    { New_Inst(	(yyvsp[0]).v ); }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 238 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(getProp);}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 242 "mini_js.y" /* yacc.c:1646  */
    {New_Inst(to_string((yyval).id));}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 243 "mini_js.y" /* yacc.c:1646  */
    {New_Inst("0");}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 246 "mini_js.y" /* yacc.c:1646  */
    {(yyval).id=1+(yyvsp[0]).id;}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 247 "mini_js.y" /* yacc.c:1646  */
    {(yyval).id=1;}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 253 "mini_js.y" /* yacc.c:1646  */
    {(yyval).id+=1; lista_arg((yyvsp[0]).v[(yyvsp[0]).v.size()-1],(yyval).id);}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 254 "mini_js.y" /* yacc.c:1646  */
    {
	 	(yyval).id=0;
	 	lista_arg((yyval).v[(yyval).v.size()-1],(yyval).id);
		}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 265 "mini_js.y" /* yacc.c:1646  */
    { for(auto i:(yyvsp[-1]).v)New_FInst(i);
	New_Func_Line();}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 267 "mini_js.y" /* yacc.c:1646  */
    {
	New_FInst("'&retorno'"); New_FInst(get); New_FInst(retFunc);
	New_Func_Line();
	}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 271 "mini_js.y" /* yacc.c:1646  */
    {
	     New_FInst("undefined"); New_FInst(get); New_FInst("'&retorno'"); New_FInst(get); New_FInst(retFunc);
	     New_Func_Line();
	  }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 281 "mini_js.y" /* yacc.c:1646  */
    { for(auto i:(yyvsp[-1]).v)New_FInst(i);
	New_Func_Line();}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 283 "mini_js.y" /* yacc.c:1646  */
    {
	New_FInst("'&retorno'"); New_FInst(get); New_FInst(retFunc);
	New_Func_Line();
	}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 293 "mini_js.y" /* yacc.c:1646  */
    {(yyvsp[-3]).id=get_id();}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 294 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(gera_ini_label("INI_IF",(yyvsp[-4]).id));New_FInst(jumpTrue);
           New_Func_Line();
           New_FInst(gera_ini_label("ELSE_IF",(yyvsp[-4]).id));New_FInst(jump);
           New_Func_Line();
           New_FInst(gera_fim_label("INI_IF",(yyvsp[-4]).id));}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 300 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(gera_ini_label("FIM_IF",(yyvsp[-6]).id));New_FInst(jump);}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 302 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(gera_fim_label("ELSE_IF",(yyvsp[-8]).id));}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 303 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(gera_fim_label("FIM_IF",(yyvsp[-10]).id));}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 310 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v ); let_var((yyvsp[0]).v); New_FInst(let); New_Func_Line();}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 311 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v ); let_var((yyvsp[0]).v); New_FInst(let); New_Func_Line();}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 316 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v );let_var((yyvsp[0]).v); New_FInst(let); New_FInst( (yyvsp[0]).v ); }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 316 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( set ); New_FInst( pop ); New_Func_Line(); }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 323 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v ); get_var((yyvsp[0]).v);}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 323 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( set ); New_FInst( pop ); New_Func_Line(); }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 324 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( setProp ); New_FInst( pop ); New_Func_Line(); }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 329 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(getProp);}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 332 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v );}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 333 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v );}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 333 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(getProp);}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 334 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v );}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 334 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(getProp);}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 335 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v );}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 335 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(getProp);}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 340 "mini_js.y" /* yacc.c:1646  */
    {New_FInst("{}");}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 341 "mini_js.y" /* yacc.c:1646  */
    {New_FInst("[]");}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 342 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v ); get_var((yyvsp[0]).v); New_FInst(get);}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 343 "mini_js.y" /* yacc.c:1646  */
    {New_FInst((yyvsp[-3]).v); New_FInst(get); New_FInst(callFunc);}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 345 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "+" ); }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 346 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "-" ); }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 347 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "*" ); }
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 348 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "/" ); }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 349 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "%" ); }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 353 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "<" ); }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 354 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( ">" ); }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 355 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "==" ); }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 356 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( ">=" ); }
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 357 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "<=" ); }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 360 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "+" ); }
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 361 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "-" ); }
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 362 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "*" ); }
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 363 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "/" ); }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 364 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( "%" ); }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 368 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v ); }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 369 "mini_js.y" /* yacc.c:1646  */
    { New_FInst(	(yyvsp[0]).v ); }
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 370 "mini_js.y" /* yacc.c:1646  */
    {int sz=(yyvsp[0]).v.size()-1; (yyvsp[0]).v[sz]=(yyvsp[0]).v[sz].substr(1);New_FInst("0"); New_FInst((yyvsp[0]).v[sz] ); New_FInst("-");}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 371 "mini_js.y" /* yacc.c:1646  */
    { New_FInst(	(yyvsp[0]).v ); }
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 373 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[-3]).v ); New_FInst(jump) ;}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 377 "mini_js.y" /* yacc.c:1646  */
    { New_FInst( (yyvsp[0]).v ); get_var((yyvsp[0]).v); New_FInst(get); }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 378 "mini_js.y" /* yacc.c:1646  */
    { New_FInst(	(yyvsp[0]).v ); }
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 379 "mini_js.y" /* yacc.c:1646  */
    {int sz=(yyvsp[0]).v.size()-1; (yyvsp[0]).v[sz]=(yyvsp[0]).v[sz].substr(1);New_FInst("0"); New_FInst((yyvsp[0]).v[sz] ); New_FInst("-");}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 380 "mini_js.y" /* yacc.c:1646  */
    { New_FInst(	(yyvsp[0]).v ); }
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 382 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(getProp);}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 385 "mini_js.y" /* yacc.c:1646  */
    {New_FInst(to_string((yyval).id));}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 389 "mini_js.y" /* yacc.c:1646  */
    {(yyval).id=1+(yyvsp[0]).id;}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 390 "mini_js.y" /* yacc.c:1646  */
    {(yyval).id=1;}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2306 "y.tab.c" /* yacc.c:1646  */
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
#line 394 "mini_js.y" /* yacc.c:1906  */


#include "lex.yy.c"

map<int,string> nome_tokens = {
	{ STR, "string" },
	{ ID, "nome de identificador" },
	{ NUM, "número" }
};

string nome_token( int token ) {
	if( nome_tokens.find( token ) != nome_tokens.end() )
		return nome_tokens[token];
	else {
		string r;
		
		r = token;
		return r;
	}
}

int retorna( int tk ) {	
	yylval.v.push_back(yytext); 
	coluna += strlen( yytext ); 

	return tk;
}

void yyerror( const char* msg ) {
	cerr << msg << endl;
	exit( 1 );
}



void New_Line(){
	codigo.push_back("\n");
}

void New_Func_Line(){
	func_codigo.push_back("\n");
}

void imprime_codigo(vector<string> &codigo){
	int cont=0;
	for(unsigned int i=0;i<codigo.size();i++){
		//if(codigo[i]!="\n")
			//cerr<<cont++<<":";
		cout<<codigo[i];
		if(codigo[i]!="\n")
			cout<<' ';
	}
}

void get_var(vector<string> v){
	/*
	string w = v[v.size()-1];
	
	bool flag=false;
	
	
	
	for(int esc=var_globais.size()-1;esc>=0;esc--){
		map<string,int> &var = var_globais[esc];
		if(var.count(w)!=0){
			flag=true; break;
		}
	}
	
	if(!flag){
		string msg = "Erro: a variável '"+w+"' não foi declarada.";
		yyerror(msg.c_str());
	}*/

}
void let_var(vector<string> v){
	/*string w = v[v.size()-1];
	
	map<string,int> &var = var_globais[var_globais.size()-1];
	
	if(var.count(w)!=0){
		string msg = "Erro: a variável '"+w+"' já foi declarada na linha "+to_string(var[w])+halt;
		yyerror(msg.c_str());
	}
	else{
		var[w]=linha;
	}*/
}

void empilha_escopo(){
	//map<string,int> var;
	//var_globais.push_back(var);
}
void desempilha_escopo(){
	//var_globais.pop_back();
}

void New_Inst( string st ) {
	codigo.push_back(st);
}


void New_Inst( vector<string> &st ){
	New_Inst(st[st.size()-1]);
}


void New_FInst( string st ) {
	func_codigo.push_back(st);
}


void New_FInst( vector<string> &st ){
	New_FInst(st[st.size()-1]);
}

int get_id(){
	static int id;
	return id++;
}
int get_func_id(){
	static int id;
	return id++;
}

void lista_arg(string k, int arg_num){
 	
		New_FInst(k);
		New_FInst(let);
		New_FInst(k);
		New_FInst("arguments");
		New_FInst(get);
		New_FInst(to_string(arg_num));
		New_FInst(getProp);
		New_FInst(set);
		New_FInst(pop);
		New_Func_Line();

}

string gera_ini_label(string pref,int id){
	return pref+to_string(id)+":";
}
string gera_fim_label(string pref, int id){
	return ":"+pref+to_string(id)+":";

}

vector<string> resolve_enderecos( vector<string> &entrada ) {
  map<string,int> label;
  vector<string> saida;
  int cont=0;

  for( unsigned int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = cont;
    else{
      if(entrada[i]!="\n")cont++;
      saida.push_back( entrada[i] );
  	}
  for( unsigned int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}


string trim(string s, char l, char r){
	auto i=s.begin();
	auto j=s.end()-1;
	while(*i==l)i++;
	while(*j==r)j--;
	return string(i,j+1);
}

vector<string> tokeniza(string s){
	istringstream iss(s);
	vector<string> tks;
	string token;	
	while(iss>>token) tks.push_back(token);
	return tks;
}

int main() {
	yyparse();
	//imprime_codigo(codigo); cout<<"\n\n";
	New_Inst(halt);
	New_Line();
	codigo = codigo + func_codigo;
	codigo = resolve_enderecos(codigo);
	imprime_codigo(codigo);
	//cout<<endl<<endl;
	desempilha_escopo();
	
	
	
	return 0;
}

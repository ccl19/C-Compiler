/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

  #include "ast.hpp"
  #include <iostream>
  #include <cassert>

  extern const Node *g_root; // A way of getting the AST out
  
  int yylex(void);
  void yyerror(const char *);

#line 122 "src/parser.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INT_LITERAL = 259,
    STRING_LITERAL = 260,
    FLOAT_LITERAL = 261,
    CHAR_LITERAL = 262,
    INC_OP = 263,
    LEFT_OP = 264,
    RIGHT_OP = 265,
    LE_OP = 266,
    GE_OP = 267,
    EQ_OP = 268,
    NEQ_OP = 269,
    AND_OP = 270,
    OR_OP = 271,
    SIZEOF = 272,
    DEC_OP = 273,
    CHAR = 274,
    INT = 275,
    FLOAT = 276,
    UNSIGNED = 277,
    ENUM = 278,
    DOUBLE = 279,
    CASE = 280,
    DEFAULT = 281,
    IF = 282,
    ELSE = 283,
    SWITCH = 284,
    WHILE = 285,
    DO = 286,
    FOR = 287,
    BREAK = 288,
    RETURN = 289
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "src/parser.y"

    Node* expr;
    std::string *string;
    double number;
    CompoundStatement* statementList;
    ParameterList* paramList;
    translation_unit* extDec;
    FunctionList* functionList;
    PrimExpression* primList;
    EnumStatement* enumList;

#line 180 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   975

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,     2,     2,    51,    45,     2,
      35,    36,    49,    47,    40,    46,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    37,
      52,    44,    53,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    55,    42,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    67,    68,    71,    72,    78,    79,    80,
      83,    84,    85,    86,    89,    90,    91,    92,    93,    97,
     100,   101,   104,   107,   108,   109,   112,   113,   114,   115,
     116,   117,   118,   119,   122,   123,   124,   125,   126,   127,
     128,   131,   132,   133,   136,   137,   140,   141,   142,   145,
     146,   149,   152,   156,   157,   160,   162,   163,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   181,   182,   183,   186,   187,   190,   191,   194,   195,
     198,   199,   202,   203,   206,   210,   211,   212,   213,   214,
     217,   218,   219,   220,   223,   224,   225,   226,   227,   230,
     231,   232,   233,   235,   236,   237,   240,   241,   242,   245,
     246,   247,   248,   249,   252,   253,   254,   257,   258,   261,
     262,   265,   266,   269,   270,   273,   274,   277,   278
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT_LITERAL",
  "STRING_LITERAL", "FLOAT_LITERAL", "CHAR_LITERAL", "INC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NEQ_OP", "AND_OP", "OR_OP",
  "SIZEOF", "DEC_OP", "CHAR", "INT", "FLOAT", "UNSIGNED", "ENUM", "DOUBLE",
  "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "BREAK",
  "RETURN", "'('", "')'", "';'", "'['", "']'", "','", "'{'", "'}'", "':'",
  "'='", "'&'", "'-'", "'+'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "$accept", "top", "translation_unit",
  "external_declaration", "function_definition", "function_declarator",
  "type_specifier", "direct_declarator", "parameter_list", "brackets",
  "compound_statement", "statement", "statementCASE",
  "compound_statementCASE", "if_statement", "while_statement",
  "for_statement", "skip_statement", "switch_statement", "case_statement",
  "break", "expression_statement", "expression", "enum_specifier",
  "enumerator_list", "enumerator", "sizeOf", "primary_expression_list",
  "function_call", "parameter_declaration", "primary_expression",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    40,    41,    59,    91,    93,
      44,   123,   125,    58,    61,    38,    45,    43,    33,    42,
      47,    37,    60,    62,    94,   124,    63
};
# endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     192,  -163,  -163,  -163,  -163,     2,  -163,    49,   192,  -163,
    -163,  -163,    13,  -163,    -1,    13,  -163,  -163,  -163,     0,
      13,    22,     5,  -163,   118,    56,   738,  -163,   147,   926,
      13,    50,    30,    13,    36,  -163,    31,    53,   205,   271,
    -163,    63,   926,    66,    98,   108,   111,    89,   115,   123,
     891,   926,  -163,  -163,  -163,  -163,  -163,  -163,    13,   -13,
     252,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
     156,  -163,  -163,  -163,   190,   215,   128,    55,    69,     1,
     182,   157,   150,   154,   202,   191,   164,   187,  -163,  -163,
    -163,  -163,  -163,  -163,    40,   152,   197,    33,     8,   184,
     856,   926,   926,   926,   738,   891,  -163,  -163,   203,     4,
     926,   926,   738,  -163,  -163,  -163,  -163,   208,  -163,  -163,
     211,   190,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     738,  -163,  -163,  -163,  -163,  -163,  -163,    44,  -163,   221,
     229,   856,  -163,   820,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,   230,   231,   234,   299,   891,  -163,   247,   215,   236,
    -163,   346,   926,   190,   190,   190,   128,   128,    55,    55,
      69,    69,    69,    69,     1,     1,   182,   157,   150,   154,
     202,   393,  -163,    16,  -163,  -163,   820,   856,  -163,   239,
     249,   250,   258,   926,   253,   191,   125,  -163,   256,   738,
    -163,   773,   738,  -163,   628,   261,   268,  -163,   215,  -163,
     665,  -163,   440,  -163,   487,   926,   274,   191,   281,  -163,
     276,   701,   286,   280,  -163,   534,   738,  -163,  -163,   581,
    -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    16,    14,    15,    17,     0,    18,     0,     2,     3,
       5,     6,     0,    13,    73,     0,     1,     4,    19,     0,
       0,    76,     0,    74,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     0,    20,     0,    87,    85,    86,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    94,    95,    96,    97,    98,     0,    65,
       0,    23,    28,    29,    30,    26,    32,    31,    33,    27,
       0,    70,    64,    93,    99,     0,   103,   106,   109,   114,
     117,   119,   121,   123,   125,   127,    63,     0,    77,    75,
      71,    10,     9,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    51,     0,    62,
       0,     0,     0,    22,    24,    57,    90,    87,    85,    86,
       0,    92,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    11,     8,    21,    12,    82,     0,    80,     0,
       0,     0,    41,    54,    36,    37,    38,    34,    39,    40,
      35,     0,     0,     0,     0,     0,    89,     0,     0,     0,
      58,     0,     0,   100,   101,   102,   105,   104,   107,   108,
     112,   113,   110,   111,   116,   115,   118,   120,   122,   124,
     126,     0,    83,     0,    79,    78,    53,     0,    42,     0,
       0,     0,     0,     0,     0,    66,    88,    25,     0,     0,
      81,     0,     0,    52,     0,     0,     0,    67,     0,    88,
     128,    43,     0,    48,     0,     0,     0,    68,    44,    46,
       0,     0,     0,     0,    50,     0,     0,    47,    49,     0,
      45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,   314,  -163,  -163,     9,   -12,  -163,   -30,
     -78,   -36,  -146,  -136,   -48,   -45,    29,    32,    41,  -163,
      57,    -6,   -28,  -163,   315,   307,  -163,  -163,  -163,   243,
     -93,   -65,  -163,    75,    95,   101,   102,   204,   206,   214,
     216,   217,  -162,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    58,    59,    34,    27,
      60,    61,   152,   153,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    13,    22,    23,    71,   147,    72,    35,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    88,    92,    21,   148,    14,   205,   198,    21,    12,
     121,    18,   129,   130,    99,   196,    18,    12,    21,   117,
     118,    93,   119,   108,   114,   110,   164,     1,     2,     3,
       4,   111,     6,    33,   171,    24,   117,   118,    25,   119,
      20,    26,   167,    15,   107,    30,   109,    31,   168,    16,
     198,    51,   154,   131,   132,   155,   227,   173,   174,   175,
      36,   211,   191,   120,   143,   198,    29,    91,    51,   146,
      96,    26,    94,   161,   162,   163,    95,   142,   127,   128,
     192,    26,   169,   170,   193,   120,   150,    90,    97,   -19,
     -19,   -19,   -19,   -19,   160,   -19,   -19,   -19,    98,   165,
     210,   125,   126,   154,    33,   154,   155,   149,   155,   100,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   114,   156,
     104,   220,   157,   101,   222,   114,   224,     1,     2,     3,
       4,   158,     6,   102,   208,   160,   103,   160,   154,   154,
     105,   155,   155,   235,    32,   114,   120,   159,   239,   203,
     106,   -69,   -69,   154,   -69,   -69,   155,   -69,   -69,   218,
     213,     1,     2,     3,     4,   216,     6,   122,   123,   124,
     156,   120,   156,   157,   114,   157,   114,    30,   114,    87,
     160,   160,   158,   115,   158,   133,   134,   230,   116,   114,
     176,   177,   135,   114,   136,   160,   120,   139,   159,   137,
     159,     1,     2,     3,     4,     5,     6,   138,   117,   118,
     140,   119,   178,   179,   141,   156,   156,   151,   157,   157,
     180,   181,   182,   183,   145,   184,   185,   158,   158,   166,
     156,   -59,   -59,   157,   -59,   -59,   -19,   -59,   -59,   172,
      51,   204,   158,   159,   159,    37,    38,   194,    39,    40,
      53,    54,    55,    56,    57,   195,   199,   200,   159,    41,
     201,     1,     2,     3,     4,   206,     6,    42,    43,    44,
     212,    45,    46,    47,    48,    49,    50,    51,   215,    52,
      26,   214,   217,   112,   113,   219,   225,    53,    54,    55,
      56,    57,    37,    38,   226,    39,    40,   -60,   -60,   232,
     -60,   -60,   233,   -60,   -60,   231,    41,   237,     1,     2,
       3,     4,    17,     6,    42,    43,    44,   236,    45,    46,
      47,    48,    49,    50,    51,    28,    52,    89,   144,   186,
     112,   202,   187,     0,    53,    54,    55,    56,    57,    37,
      38,   188,    39,    40,   189,     0,   190,     0,     0,     0,
       0,     0,     0,    41,     0,     1,     2,     3,     4,     0,
       6,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,     0,    52,     0,     0,     0,   112,   207,     0,
       0,    53,    54,    55,    56,    57,    37,    38,     0,    39,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     1,     2,     3,     4,     0,     6,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,     0,
      52,     0,     0,     0,   112,     0,   209,     0,    53,    54,
      55,    56,    57,    37,    38,     0,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     1,
       2,     3,     4,     0,     6,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,     0,    52,     0,     0,
       0,   112,   228,     0,     0,    53,    54,    55,    56,    57,
      37,    38,     0,    39,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     1,     2,     3,     4,
       0,     6,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,     0,    52,     0,     0,     0,   112,   229,
       0,     0,    53,    54,    55,    56,    57,    37,    38,     0,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     1,     2,     3,     4,     0,     6,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
       0,    52,     0,     0,     0,   112,   238,     0,     0,    53,
      54,    55,    56,    57,    37,    38,     0,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       1,     2,     3,     4,     0,     6,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,     0,    52,     0,
       0,     0,   112,   240,     0,     0,    53,    54,    55,    56,
      57,    37,    38,     0,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     1,     2,     3,
       4,     0,     6,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,     0,    52,     0,     0,    37,    38,
     223,    39,    40,    53,    54,    55,    56,    57,     0,     0,
       0,     0,    41,     0,     1,     2,     3,     4,     0,     6,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,     0,    52,     0,    37,    38,   112,    39,    40,     0,
      53,    54,    55,    56,    57,     0,     0,     0,    41,     0,
       1,     2,     3,     4,     0,     6,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,     0,    52,     0,
       0,    37,    38,   234,    39,    40,    53,    54,    55,    56,
      57,     0,     0,     0,     0,    41,     0,     1,     2,     3,
       4,     0,     6,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,     0,    52,    37,    38,     0,    39,
      40,     0,     0,    53,    54,    55,    56,    57,     0,     0,
      41,     0,     1,     2,     3,     4,     0,     6,     0,     0,
      44,     0,    45,    46,    47,    48,    49,    50,    51,     0,
      52,     0,     0,     0,   197,   221,     0,     0,    53,    54,
      55,    56,    57,    37,    38,     0,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     1,
       2,     3,     4,     0,     6,     0,     0,    44,     0,    45,
      46,    47,    48,    49,    50,    51,     0,    52,     0,    37,
      38,   197,    39,    40,     0,    53,    54,    55,    56,    57,
       0,     0,     0,    41,     0,     1,     2,     3,     4,     0,
       6,     0,     0,    44,     0,    45,    46,    47,    48,    49,
      50,    51,     0,    52,    37,    38,     0,    39,    40,     0,
       0,    53,    54,    55,    56,    57,     0,     0,    41,     0,
       1,     2,     3,     4,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,     0,    52,    37,
      38,     0,    39,    40,     0,     0,    53,    54,    55,    56,
      57,     0,     0,    41,     0,     1,     2,     3,     4,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,    54,    55,    56,    57
};

static const yytype_int16 yycheck[] =
{
      12,    29,    32,    15,    97,     3,   168,   153,    20,     0,
      75,     3,    11,    12,    42,   151,     3,     8,    30,     3,
       4,    33,     6,    51,    60,    38,   104,    19,    20,    21,
      22,    44,    24,    24,   112,    35,     3,     4,    38,     6,
      41,    41,    38,    41,    50,    40,    58,    42,    44,     0,
     196,    35,   100,    52,    53,   100,   218,   122,   123,   124,
       4,   197,   140,    75,    94,   211,    44,    37,    35,    36,
      39,    41,    36,   101,   102,   103,    40,    37,     9,    10,
      36,    41,   110,   111,    40,    97,    98,    37,    35,    36,
      37,    38,    39,    40,   100,    42,    43,    44,    35,   105,
     193,    46,    47,   151,    95,   153,   151,    98,   153,    43,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   164,   100,
      41,   209,   100,    35,   212,   171,   214,    19,    20,    21,
      22,   100,    24,    35,   172,   151,    35,   153,   196,   197,
      35,   196,   197,   231,    36,   191,   168,   100,   236,   165,
      37,    36,    37,   211,    39,    40,   211,    42,    43,    44,
     200,    19,    20,    21,    22,   203,    24,    49,    50,    51,
     151,   193,   153,   151,   220,   153,   222,    40,   224,    42,
     196,   197,   151,    37,   153,    13,    14,   225,     8,   235,
     125,   126,    45,   239,    54,   211,   218,    16,   151,    55,
     153,    19,    20,    21,    22,    23,    24,    15,     3,     4,
      56,     6,   127,   128,    37,   196,   197,    43,   196,   197,
     129,   130,   131,   132,    37,   133,   134,   196,   197,    36,
     211,    36,    37,   211,    39,    40,    38,    42,    43,    38,
      35,     4,   211,   196,   197,     3,     4,    36,     6,     7,
      45,    46,    47,    48,    49,    36,    36,    36,   211,    17,
      36,    19,    20,    21,    22,    39,    24,    25,    26,    27,
      41,    29,    30,    31,    32,    33,    34,    35,    30,    37,
      41,    41,    39,    41,    42,    39,    35,    45,    46,    47,
      48,    49,     3,     4,    36,     6,     7,    36,    37,    28,
      39,    40,    36,    42,    43,    41,    17,    37,    19,    20,
      21,    22,     8,    24,    25,    26,    27,    41,    29,    30,
      31,    32,    33,    34,    35,    20,    37,    30,    95,   135,
      41,    42,   136,    -1,    45,    46,    47,    48,    49,     3,
       4,   137,     6,     7,   138,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    -1,    37,    -1,    -1,    -1,    41,    42,    -1,
      -1,    45,    46,    47,    48,    49,     3,     4,    -1,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,    -1,    43,    -1,    45,    46,
      47,    48,    49,     3,     4,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    24,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,    -1,    -1,
      -1,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
       3,     4,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      -1,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    -1,    -1,    -1,    41,    42,
      -1,    -1,    45,    46,    47,    48,    49,     3,     4,    -1,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      -1,    37,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,
      46,    47,    48,    49,     3,     4,    -1,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    -1,
      -1,    -1,    41,    42,    -1,    -1,    45,    46,    47,    48,
      49,     3,     4,    -1,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,    -1,    -1,     3,     4,
      42,     6,     7,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    -1,     3,     4,    41,     6,     7,    -1,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    -1,
      -1,     3,     4,    42,     6,     7,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    -1,    37,     3,     4,    -1,     6,
       7,    -1,    -1,    45,    46,    47,    48,    49,    -1,    -1,
      17,    -1,    19,    20,    21,    22,    -1,    24,    -1,    -1,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,    46,
      47,    48,    49,     3,     4,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    -1,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    -1,    37,    -1,     3,
       4,    41,     6,     7,    -1,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    -1,    37,     3,     4,    -1,     6,     7,    -1,
      -1,    45,    46,    47,    48,    49,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    37,     3,
       4,    -1,     6,     7,    -1,    -1,    45,    46,    47,    48,
      49,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    20,    21,    22,    23,    24,    58,    59,    60,
      61,    62,    63,    80,     3,    41,     0,    60,     3,    64,
      41,    64,    81,    82,    35,    38,    41,    66,    81,    44,
      40,    42,    36,    63,    65,    86,     4,     3,     4,     6,
       7,    17,    25,    26,    27,    29,    30,    31,    32,    33,
      34,    35,    37,    45,    46,    47,    48,    49,    63,    64,
      67,    68,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    83,    85,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    42,    79,    82,
      37,    37,    66,    64,    36,    40,    39,    35,    35,    79,
      43,    35,    35,    35,    41,    35,    37,    78,    79,    64,
      38,    44,    41,    42,    68,    37,     8,     3,     4,     6,
      64,    88,    49,    50,    51,    46,    47,     9,    10,    11,
      12,    52,    53,    13,    14,    45,    54,    55,    15,    16,
      56,    37,    37,    66,    86,    37,    36,    84,    87,    63,
      64,    43,    69,    70,    71,    72,    73,    74,    75,    77,
      78,    79,    79,    79,    67,    78,    36,    38,    44,    79,
      79,    67,    38,    88,    88,    88,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    94,    95,    96,    97,
      98,    67,    36,    40,    36,    36,    70,    41,    69,    36,
      36,    36,    42,    78,     4,    99,    39,    42,    79,    43,
      87,    70,    41,    66,    41,    30,    79,    39,    44,    39,
      67,    42,    67,    42,    67,    35,    36,    99,    42,    42,
      79,    41,    28,    36,    42,    67,    41,    37,    42,    67,
      42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    72,    72,    72,    73,
      73,    74,    75,    76,    76,    77,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    87,    87,    87,    87,    87,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    91,    91,    91,    92,    92,    92,    93,
      93,    93,    93,    93,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     5,
       5,     6,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     7,    11,     7,     9,     6,     9,
       8,     2,     5,     4,     3,     2,     1,     2,     3,     1,
       1,     1,     2,     1,     1,     1,     4,     5,     6,     4,
       1,     5,     6,     2,     1,     3,     1,     3,     4,     4,
       1,     3,     3,     4,     2,     1,     1,     1,     4,     3,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 65 "src/parser.y"
                       { g_root = (yyvsp[0].extDec); }
#line 1679 "src/parser.tab.cpp"
    break;

  case 3:
#line 67 "src/parser.y"
                                        { (yyval.extDec) = new translation_unit((yyvsp[0].expr));}
#line 1685 "src/parser.tab.cpp"
    break;

  case 4:
#line 68 "src/parser.y"
                                                         { (yyval.extDec) -> addExtDec((yyvsp[0].expr));}
#line 1691 "src/parser.tab.cpp"
    break;

  case 5:
#line 71 "src/parser.y"
                                           { (yyval.expr) = (yyvsp[0].expr); }
#line 1697 "src/parser.tab.cpp"
    break;

  case 6:
#line 72 "src/parser.y"
                                           {(yyval.expr) = (yyvsp[0].expr);}
#line 1703 "src/parser.tab.cpp"
    break;

  case 7:
#line 78 "src/parser.y"
                                                                {(yyval.expr) = new Function(*(yyvsp[-2].string),(yyvsp[-1].expr),(yyvsp[0].expr));}
#line 1709 "src/parser.tab.cpp"
    break;

  case 8:
#line 79 "src/parser.y"
                                                                                       {(yyval.expr) = new Function(*(yyvsp[-5].string),(yyvsp[-4].expr),(yyvsp[-2].paramList),(yyvsp[0].expr));}
#line 1715 "src/parser.tab.cpp"
    break;

  case 9:
#line 80 "src/parser.y"
                                                                       {(yyval.expr) = new Function(*(yyvsp[-4].string),(yyvsp[-3].expr),(yyvsp[0].expr));}
#line 1721 "src/parser.tab.cpp"
    break;

  case 10:
#line 83 "src/parser.y"
                                                                   {(yyval.expr) = new FunctionDeclaration((yyvsp[-3].expr));}
#line 1727 "src/parser.tab.cpp"
    break;

  case 11:
#line 84 "src/parser.y"
                                                                                 {(yyval.expr) = new FunctionDeclaration((yyvsp[-4].expr),(yyvsp[-2].paramList));}
#line 1733 "src/parser.tab.cpp"
    break;

  case 12:
#line 85 "src/parser.y"
                                                                              {(yyval.expr) = new Array(*(yyvsp[-5].string), (yyvsp[-4].expr), (yyvsp[-2].number), false, true);}
#line 1739 "src/parser.tab.cpp"
    break;

  case 13:
#line 86 "src/parser.y"
                                     {(yyval.expr) =(yyvsp[0].expr);}
#line 1745 "src/parser.tab.cpp"
    break;

  case 14:
#line 89 "src/parser.y"
                     { (yyval.string) = new std::string("int");}
#line 1751 "src/parser.tab.cpp"
    break;

  case 15:
#line 90 "src/parser.y"
                       { (yyval.string) = new std::string("float");}
#line 1757 "src/parser.tab.cpp"
    break;

  case 16:
#line 91 "src/parser.y"
                      { (yyval.string) = new std::string("char");}
#line 1763 "src/parser.tab.cpp"
    break;

  case 17:
#line 92 "src/parser.y"
                          { (yyval.string) = new std::string("unsigned");}
#line 1769 "src/parser.tab.cpp"
    break;

  case 18:
#line 93 "src/parser.y"
                        { (yyval.string) = new std::string("double");}
#line 1775 "src/parser.tab.cpp"
    break;

  case 19:
#line 97 "src/parser.y"
                                {(yyval.expr) = new Variable(*(yyvsp[0].string));}
#line 1781 "src/parser.tab.cpp"
    break;

  case 20:
#line 100 "src/parser.y"
                                       {(yyval.paramList) = new ParameterList((yyvsp[0].expr));}
#line 1787 "src/parser.tab.cpp"
    break;

  case 21:
#line 101 "src/parser.y"
                                                          {(yyval.paramList) -> AddParam((yyvsp[0].expr));}
#line 1793 "src/parser.tab.cpp"
    break;

  case 22:
#line 104 "src/parser.y"
                                      {(yyval.expr) = (yyvsp[-1].statementList);}
#line 1799 "src/parser.tab.cpp"
    break;

  case 23:
#line 107 "src/parser.y"
                               {(yyval.statementList) = new CompoundStatement((yyvsp[0].expr));}
#line 1805 "src/parser.tab.cpp"
    break;

  case 24:
#line 108 "src/parser.y"
                                                  {(yyval.statementList) -> AddStatement((yyvsp[0].expr));}
#line 1811 "src/parser.tab.cpp"
    break;

  case 26:
#line 112 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);}
#line 1817 "src/parser.tab.cpp"
    break;

  case 27:
#line 113 "src/parser.y"
                                 {(yyval.expr) = (yyvsp[0].expr);}
#line 1823 "src/parser.tab.cpp"
    break;

  case 28:
#line 114 "src/parser.y"
                         {(yyval.expr) = (yyvsp[0].expr);}
#line 1829 "src/parser.tab.cpp"
    break;

  case 29:
#line 115 "src/parser.y"
                            {(yyval.expr) = (yyvsp[0].expr);}
#line 1835 "src/parser.tab.cpp"
    break;

  case 30:
#line 116 "src/parser.y"
                          {(yyval.expr) = (yyvsp[0].expr);}
#line 1841 "src/parser.tab.cpp"
    break;

  case 31:
#line 117 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);}
#line 1847 "src/parser.tab.cpp"
    break;

  case 32:
#line 118 "src/parser.y"
                             {(yyval.expr) = (yyvsp[0].expr);}
#line 1853 "src/parser.tab.cpp"
    break;

  case 33:
#line 119 "src/parser.y"
                  {(yyval.expr) = (yyvsp[0].expr);}
#line 1859 "src/parser.tab.cpp"
    break;

  case 34:
#line 122 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr);}
#line 1865 "src/parser.tab.cpp"
    break;

  case 35:
#line 123 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[0].expr);}
#line 1871 "src/parser.tab.cpp"
    break;

  case 36:
#line 124 "src/parser.y"
                             {(yyval.expr) = (yyvsp[0].expr);}
#line 1877 "src/parser.tab.cpp"
    break;

  case 37:
#line 125 "src/parser.y"
                                {(yyval.expr) = (yyvsp[0].expr);}
#line 1883 "src/parser.tab.cpp"
    break;

  case 38:
#line 126 "src/parser.y"
                              {(yyval.expr) = (yyvsp[0].expr);}
#line 1889 "src/parser.tab.cpp"
    break;

  case 39:
#line 127 "src/parser.y"
                                 {(yyval.expr) = (yyvsp[0].expr);}
#line 1895 "src/parser.tab.cpp"
    break;

  case 40:
#line 128 "src/parser.y"
                      {(yyval.expr) = (yyvsp[0].expr);}
#line 1901 "src/parser.tab.cpp"
    break;

  case 41:
#line 131 "src/parser.y"
                                       {(yyval.statementList) = new CompoundStatement((yyvsp[0].expr));}
#line 1907 "src/parser.tab.cpp"
    break;

  case 42:
#line 132 "src/parser.y"
                                                              {(yyval.statementList) -> AddStatement((yyvsp[0].expr));}
#line 1913 "src/parser.tab.cpp"
    break;

  case 44:
#line 136 "src/parser.y"
                                                                {(yyval.expr) = new IfElseStatement((yyvsp[-4].expr), (yyvsp[-1].statementList), NULL);}
#line 1919 "src/parser.tab.cpp"
    break;

  case 45:
#line 137 "src/parser.y"
                                                                                                      {(yyval.expr) = new IfElseStatement((yyvsp[-8].expr), (yyvsp[-5].statementList), (yyvsp[-1].statementList));}
#line 1925 "src/parser.tab.cpp"
    break;

  case 46:
#line 140 "src/parser.y"
                                                                      {(yyval.expr) = new WhileStatement((yyvsp[-4].expr), (yyvsp[-1].statementList), false);}
#line 1931 "src/parser.tab.cpp"
    break;

  case 47:
#line 141 "src/parser.y"
                                                                            {(yyval.expr) = new WhileStatement((yyvsp[-2].expr), (yyvsp[-6].statementList), true);}
#line 1937 "src/parser.tab.cpp"
    break;

  case 48:
#line 142 "src/parser.y"
                                                   {(yyval.expr) = new WhileStatement((yyvsp[-3].expr), false);}
#line 1943 "src/parser.tab.cpp"
    break;

  case 49:
#line 145 "src/parser.y"
                                                                                                             {(yyval.expr) = new ForStatement((yyvsp[-6].expr),(yyvsp[-5].expr),(yyvsp[-4].expr),(yyvsp[-1].statementList));}
#line 1949 "src/parser.tab.cpp"
    break;

  case 50:
#line 146 "src/parser.y"
                                                                                         {(yyval.expr) = new ForStatement((yyvsp[-5].expr),(yyvsp[-4].expr),(yyvsp[-3].expr));}
#line 1955 "src/parser.tab.cpp"
    break;

  case 51:
#line 149 "src/parser.y"
                                             {(yyval.expr) = new ReturnStatement((yyvsp[0].expr));}
#line 1961 "src/parser.tab.cpp"
    break;

  case 52:
#line 152 "src/parser.y"
                                                      {(yyval.expr) = new SwitchStatement((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 1967 "src/parser.tab.cpp"
    break;

  case 53:
#line 156 "src/parser.y"
                                                            {(yyval.expr) = new CaseStatement((yyvsp[-2].expr), (yyvsp[0].statementList));}
#line 1973 "src/parser.tab.cpp"
    break;

  case 54:
#line 157 "src/parser.y"
                                                    {(yyval.expr) = new DefaultStatement((yyvsp[0].statementList));}
#line 1979 "src/parser.tab.cpp"
    break;

  case 55:
#line 160 "src/parser.y"
                  {(yyval.expr) = new Break();}
#line 1985 "src/parser.tab.cpp"
    break;

  case 57:
#line 163 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[-1].expr);}
#line 1991 "src/parser.tab.cpp"
    break;

  case 58:
#line 166 "src/parser.y"
                                              {(yyval.expr) = new VarDeclaration((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 1997 "src/parser.tab.cpp"
    break;

  case 59:
#line 167 "src/parser.y"
                         {(yyval.expr) = new Constant("int",(yyvsp[0].number));}
#line 2003 "src/parser.tab.cpp"
    break;

  case 60:
#line 168 "src/parser.y"
                           {(yyval.expr) = new Constant("float",(yyvsp[0].number));}
#line 2009 "src/parser.tab.cpp"
    break;

  case 61:
#line 169 "src/parser.y"
                         {(yyval.expr) = new String(*(yyvsp[0].string));}
#line 2015 "src/parser.tab.cpp"
    break;

  case 62:
#line 170 "src/parser.y"
                                              {(yyval.expr) = new Declaration_Specifier(*(yyvsp[-1].string), (yyvsp[0].expr));}
#line 2021 "src/parser.tab.cpp"
    break;

  case 63:
#line 171 "src/parser.y"
                                    {(yyval.expr) = (yyvsp[0].expr);}
#line 2027 "src/parser.tab.cpp"
    break;

  case 64:
#line 172 "src/parser.y"
                           {(yyval.expr) = (yyvsp[0].expr);}
#line 2033 "src/parser.tab.cpp"
    break;

  case 65:
#line 173 "src/parser.y"
                                {(yyval.expr) = (yyvsp[0].expr);}
#line 2039 "src/parser.tab.cpp"
    break;

  case 66:
#line 174 "src/parser.y"
                                                                        {(yyval.expr) = new VarDeclaration(*(yyvsp[-3].string), (yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2045 "src/parser.tab.cpp"
    break;

  case 67:
#line 175 "src/parser.y"
                                                                  {(yyval.expr) = new Array(*(yyvsp[-4].string), (yyvsp[-3].expr), (yyvsp[-1].number), true, false);}
#line 2051 "src/parser.tab.cpp"
    break;

  case 68:
#line 176 "src/parser.y"
                                                                            {(yyval.expr) = new ArrayAssignment((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[0].expr));}
#line 2057 "src/parser.tab.cpp"
    break;

  case 69:
#line 177 "src/parser.y"
                                                  {(yyval.expr) = (yyvsp[-3].expr);}
#line 2063 "src/parser.tab.cpp"
    break;

  case 70:
#line 178 "src/parser.y"
                    {(yyval.expr) = (yyvsp[0].expr);}
#line 2069 "src/parser.tab.cpp"
    break;

  case 71:
#line 181 "src/parser.y"
                                                  {(yyval.expr) = new Enum((yyvsp[-2].enumList));}
#line 2075 "src/parser.tab.cpp"
    break;

  case 72:
#line 182 "src/parser.y"
                                                             {(yyval.expr) = new Enum(*(yyvsp[-4].string),(yyvsp[-2].enumList));}
#line 2081 "src/parser.tab.cpp"
    break;

  case 73:
#line 183 "src/parser.y"
                                 {(yyval.expr) = new Enum (*(yyvsp[0].string));}
#line 2087 "src/parser.tab.cpp"
    break;

  case 74:
#line 186 "src/parser.y"
                             {(yyval.enumList) = new EnumStatement((yyvsp[0].expr));}
#line 2093 "src/parser.tab.cpp"
    break;

  case 75:
#line 187 "src/parser.y"
                                                 {(yyval.enumList) -> AddEnum((yyvsp[0].expr));}
#line 2099 "src/parser.tab.cpp"
    break;

  case 76:
#line 190 "src/parser.y"
                               {(yyval.expr) = (yyvsp[0].expr);}
#line 2105 "src/parser.tab.cpp"
    break;

  case 77:
#line 191 "src/parser.y"
                                              {(yyval.expr) = new VarDeclaration((yyvsp[-2].expr),(yyvsp[0].expr));}
#line 2111 "src/parser.tab.cpp"
    break;

  case 78:
#line 194 "src/parser.y"
                                          {(yyval.expr) = new SizeOf((yyvsp[-1].expr));}
#line 2117 "src/parser.tab.cpp"
    break;

  case 79:
#line 195 "src/parser.y"
                                       {(yyval.expr) = new SizeOfInst(*(yyvsp[-1].string));}
#line 2123 "src/parser.tab.cpp"
    break;

  case 80:
#line 198 "src/parser.y"
                                             {(yyval.primList) = new PrimExpression((yyvsp[0].expr));}
#line 2129 "src/parser.tab.cpp"
    break;

  case 81:
#line 199 "src/parser.y"
                                                                         {(yyval.primList) -> AddExpr((yyvsp[0].expr));}
#line 2135 "src/parser.tab.cpp"
    break;

  case 82:
#line 202 "src/parser.y"
                                   {(yyval.expr) = new FunctionCall(*(yyvsp[-2].string));}
#line 2141 "src/parser.tab.cpp"
    break;

  case 83:
#line 203 "src/parser.y"
                                                           {(yyval.expr) = new FunctionCall(*(yyvsp[-3].string),(yyvsp[-1].primList));}
#line 2147 "src/parser.tab.cpp"
    break;

  case 84:
#line 206 "src/parser.y"
                                                         {(yyval.expr) = new Parameter(*(yyvsp[-1].string),(yyvsp[0].expr));}
#line 2153 "src/parser.tab.cpp"
    break;

  case 85:
#line 210 "src/parser.y"
                                 {(yyval.expr) = new Constant("int", (yyvsp[0].number));}
#line 2159 "src/parser.tab.cpp"
    break;

  case 86:
#line 211 "src/parser.y"
                                   {(yyval.expr) = new Constant("float", (yyvsp[0].number));}
#line 2165 "src/parser.tab.cpp"
    break;

  case 87:
#line 212 "src/parser.y"
                                {(yyval.expr) = new Variable(*(yyvsp[0].string));}
#line 2171 "src/parser.tab.cpp"
    break;

  case 88:
#line 213 "src/parser.y"
                                                          {(yyval.expr) = (yyvsp[-3].expr);}
#line 2177 "src/parser.tab.cpp"
    break;

  case 90:
#line 217 "src/parser.y"
                                           {(yyval.expr) = new IncrementOperator((yyvsp[-1].expr));}
#line 2183 "src/parser.tab.cpp"
    break;

  case 91:
#line 218 "src/parser.y"
                                           {(yyval.expr) = new DecrementOperator((yyvsp[-1].expr));}
#line 2189 "src/parser.tab.cpp"
    break;

  case 92:
#line 219 "src/parser.y"
                                                   {(yyval.expr) = (yyvsp[0].expr);}
#line 2195 "src/parser.tab.cpp"
    break;

  case 93:
#line 220 "src/parser.y"
                                      {(yyval.expr) = (yyvsp[0].expr);}
#line 2201 "src/parser.tab.cpp"
    break;

  case 99:
#line 230 "src/parser.y"
                                             {(yyval.expr) = (yyvsp[0].expr);}
#line 2207 "src/parser.tab.cpp"
    break;

  case 100:
#line 231 "src/parser.y"
                                                                           {(yyval.expr) = new MultOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2213 "src/parser.tab.cpp"
    break;

  case 101:
#line 232 "src/parser.y"
                                                                           {(yyval.expr) = new DivOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2219 "src/parser.tab.cpp"
    break;

  case 102:
#line 233 "src/parser.y"
                                                                           {(yyval.expr) = new ModOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2225 "src/parser.tab.cpp"
    break;

  case 103:
#line 235 "src/parser.y"
                                                {(yyval.expr) = (yyvsp[0].expr);}
#line 2231 "src/parser.tab.cpp"
    break;

  case 104:
#line 236 "src/parser.y"
                                                                        {(yyval.expr) = new AddOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2237 "src/parser.tab.cpp"
    break;

  case 105:
#line 237 "src/parser.y"
                                                                        {(yyval.expr) = new SubOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2243 "src/parser.tab.cpp"
    break;

  case 106:
#line 240 "src/parser.y"
                                       {(yyval.expr) = (yyvsp[0].expr);}
#line 2249 "src/parser.tab.cpp"
    break;

  case 107:
#line 241 "src/parser.y"
                                                                {(yyval.expr) = new ShiftLeftOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2255 "src/parser.tab.cpp"
    break;

  case 108:
#line 242 "src/parser.y"
                                                                 {(yyval.expr) = new ShiftRightOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2261 "src/parser.tab.cpp"
    break;

  case 109:
#line 245 "src/parser.y"
                                         {(yyval.expr) = (yyvsp[0].expr);}
#line 2267 "src/parser.tab.cpp"
    break;

  case 110:
#line 246 "src/parser.y"
                                                                   {(yyval.expr) = new LessThanOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2273 "src/parser.tab.cpp"
    break;

  case 111:
#line 247 "src/parser.y"
                                                                   {(yyval.expr) = new GreaterThanOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2279 "src/parser.tab.cpp"
    break;

  case 112:
#line 248 "src/parser.y"
                                                                     {(yyval.expr) = new LessThanEqOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2285 "src/parser.tab.cpp"
    break;

  case 113:
#line 249 "src/parser.y"
                                                                     {(yyval.expr) = new GreaterThanEqOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2291 "src/parser.tab.cpp"
    break;

  case 114:
#line 252 "src/parser.y"
                                            {(yyval.expr) = (yyvsp[0].expr);}
#line 2297 "src/parser.tab.cpp"
    break;

  case 115:
#line 253 "src/parser.y"
                                                                       {(yyval.expr) = new NotEqualOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2303 "src/parser.tab.cpp"
    break;

  case 116:
#line 254 "src/parser.y"
                                                                      {(yyval.expr) = new EqualOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2309 "src/parser.tab.cpp"
    break;

  case 117:
#line 257 "src/parser.y"
                                     {(yyval.expr) = (yyvsp[0].expr);}
#line 2315 "src/parser.tab.cpp"
    break;

  case 118:
#line 258 "src/parser.y"
                                                        {(yyval.expr) = new AndOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2321 "src/parser.tab.cpp"
    break;

  case 119:
#line 261 "src/parser.y"
                                         {(yyval.expr) = (yyvsp[0].expr);}
#line 2327 "src/parser.tab.cpp"
    break;

  case 120:
#line 262 "src/parser.y"
                                                                     {(yyval.expr) = new XorOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2333 "src/parser.tab.cpp"
    break;

  case 121:
#line 265 "src/parser.y"
                                                  {(yyval.expr) = (yyvsp[0].expr);}
#line 2339 "src/parser.tab.cpp"
    break;

  case 122:
#line 266 "src/parser.y"
                                                                              {(yyval.expr) = new OrOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2345 "src/parser.tab.cpp"
    break;

  case 123:
#line 269 "src/parser.y"
                                                 {(yyval.expr) = (yyvsp[0].expr);}
#line 2351 "src/parser.tab.cpp"
    break;

  case 124:
#line 270 "src/parser.y"
                                                                               {(yyval.expr) = new LogicalAndOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2357 "src/parser.tab.cpp"
    break;

  case 125:
#line 273 "src/parser.y"
                                               {(yyval.expr) = (yyvsp[0].expr);}
#line 2363 "src/parser.tab.cpp"
    break;

  case 126:
#line 274 "src/parser.y"
                                                                           {(yyval.expr) = new LogicalOrOperator((yyvsp[-2].expr), (yyvsp[0].expr));}
#line 2369 "src/parser.tab.cpp"
    break;

  case 127:
#line 277 "src/parser.y"
                                               {(yyval.expr) = (yyvsp[0].expr);}
#line 2375 "src/parser.tab.cpp"
    break;

  case 128:
#line 278 "src/parser.y"
                                                                                              {(yyval.expr) = new ConditionalOperator((yyvsp[-4].expr), (yyvsp[-2].statementList), (yyvsp[0].statementList));}
#line 2381 "src/parser.tab.cpp"
    break;


#line 2385 "src/parser.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 281 "src/parser.y"


const Node *g_root; // Definition of variable (to match declaration earlier)

const Node *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}

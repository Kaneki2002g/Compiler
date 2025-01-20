/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

//C++ part WIP
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include "brainpart.hpp"
#include "structs.h"
extern int yylineno;

int yylex();
void yyerror(const char* msg);
int digitCount(long long num);
Component* lastnext(Component* comp);

#line 87 "grammar.cpp"

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

#include "grammar.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EQ = 3,                         /* EQ  */
  YYSYMBOL_NEQ = 4,                        /* NEQ  */
  YYSYMBOL_GEQ = 5,                        /* GEQ  */
  YYSYMBOL_LEQ = 6,                        /* LEQ  */
  YYSYMBOL_GT = 7,                         /* GT  */
  YYSYMBOL_LT = 8,                         /* LT  */
  YYSYMBOL_SET = 9,                        /* SET  */
  YYSYMBOL_PROCEDURE = 10,                 /* PROCEDURE  */
  YYSYMBOL_IS = 11,                        /* IS  */
  YYSYMBOL_T_BEGIN = 12,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 13,                     /* T_END  */
  YYSYMBOL_PROGRAM = 14,                   /* PROGRAM  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_THEN = 16,                      /* THEN  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_ENDIF = 18,                     /* ENDIF  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_ENDWHILE = 21,                  /* ENDWHILE  */
  YYSYMBOL_REPEAT = 22,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 23,                     /* UNTIL  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_FROM = 25,                      /* FROM  */
  YYSYMBOL_TO = 26,                        /* TO  */
  YYSYMBOL_ENDFOR = 27,                    /* ENDFOR  */
  YYSYMBOL_DOWNTO = 28,                    /* DOWNTO  */
  YYSYMBOL_T = 29,                         /* T  */
  YYSYMBOL_READ = 30,                      /* READ  */
  YYSYMBOL_WRITE = 31,                     /* WRITE  */
  YYSYMBOL_COMMA = 32,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_SLB = 34,                       /* SLB  */
  YYSYMBOL_SRB = 35,                       /* SRB  */
  YYSYMBOL_LB = 36,                        /* LB  */
  YYSYMBOL_RB = 37,                        /* RB  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_pidentifier = 39,               /* pidentifier  */
  YYSYMBOL_NUMBER = 40,                    /* NUMBER  */
  YYSYMBOL_ADD = 41,                       /* ADD  */
  YYSYMBOL_SUB = 42,                       /* SUB  */
  YYSYMBOL_MUL = 43,                       /* MUL  */
  YYSYMBOL_DIV = 44,                       /* DIV  */
  YYSYMBOL_MOD = 45,                       /* MOD  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_program_all = 47,               /* program_all  */
  YYSYMBOL_procedures = 48,                /* procedures  */
  YYSYMBOL_main = 49,                      /* main  */
  YYSYMBOL_commands = 50,                  /* commands  */
  YYSYMBOL_command = 51,                   /* command  */
  YYSYMBOL_proc_head = 52,                 /* proc_head  */
  YYSYMBOL_proc_call = 53,                 /* proc_call  */
  YYSYMBOL_declarations = 54,              /* declarations  */
  YYSYMBOL_args_decl = 55,                 /* args_decl  */
  YYSYMBOL_args = 56,                      /* args  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_condition = 58,                 /* condition  */
  YYSYMBOL_value = 59,                     /* value  */
  YYSYMBOL_identifier = 60,                /* identifier  */
  YYSYMBOL_num = 61                        /* num  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    71,    89,   106,   116,   126,   136,   140,
     150,   160,   171,   181,   191,   201,   222,   243,   252,   261,
     271,   288,   305,   317,   330,   347,   366,   378,   390,   407,
     425,   437,   455,   464,   474,   484,   508,   525,   544,   554,
     564,   574,   584,   594,   605,   614,   624,   641,   667,   685,
     694
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EQ", "NEQ", "GEQ",
  "LEQ", "GT", "LT", "SET", "PROCEDURE", "IS", "T_BEGIN", "T_END",
  "PROGRAM", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "REPEAT", "UNTIL", "FOR", "FROM", "TO", "ENDFOR", "DOWNTO", "T", "READ",
  "WRITE", "COMMA", "SEMICOLON", "SLB", "SRB", "LB", "RB", "COLON",
  "pidentifier", "NUMBER", "ADD", "SUB", "MUL", "DIV", "MOD", "$accept",
  "program_all", "procedures", "main", "commands", "command", "proc_head",
  "proc_call", "declarations", "args_decl", "args", "expression",
  "condition", "value", "identifier", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-29)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -29,    16,     3,   -29,    -6,    45,   -29,     9,    60,   -10,
     -21,    -3,   236,    19,    -7,    33,   -29,   -22,   236,    -5,
      21,    21,   236,    36,    43,    21,    -8,   131,   -29,    40,
      65,     4,   236,    46,   -29,   -17,   -29,   141,   236,    52,
     -29,    47,    72,    35,   -29,   -29,    69,   177,    66,    61,
      63,    25,    54,   -29,   -29,   -29,    21,    59,   154,    75,
      71,   -29,   -29,   164,   -29,   236,    21,    21,    21,    21,
      21,    21,   236,    21,    21,   -29,   -29,    64,    83,   -29,
     -13,    87,     7,     4,   -29,     4,   -29,   -29,   104,   -29,
     -29,   -29,   -29,   -29,   -29,   190,    94,    42,   -29,   -29,
      90,   -29,   -29,    21,    21,    21,    21,    21,    95,    93,
     236,   -29,   -29,   -29,    21,    21,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,     4,   200,   112,   113,   101,   -29,   236,
     236,   -29,   213,   223,   -29,   -29
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     2,     0,     0,     0,
       0,     0,     0,    24,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     0,     9,     0,
       0,     0,     0,     0,    29,     0,    20,     0,     0,    46,
      49,     0,     0,     0,    45,    44,     0,     0,     0,     0,
       0,     0,     0,     7,     8,    17,     0,     0,     0,    22,
       0,    26,     4,     0,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,    31,
       0,     0,    32,     0,     6,     0,    27,     3,     0,    38,
      39,    42,    43,    40,    41,     0,     0,     0,    47,    48,
       0,    21,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,    14,     0,     0,    30,    33,    34,    35,
      36,    37,    25,     0,     0,     0,     0,     0,    11,     0,
       0,    23,     0,     0,    15,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -29,   -29,   -29,   -29,   -18,   -26,   -29,   -29,   134,   -29,
     -29,   -29,   -15,    34,    10,   -28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    27,    28,     8,    29,    14,    17,
      80,    81,    42,    43,    30,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      37,    54,    12,    57,    47,    32,    46,    38,    15,    18,
      35,    54,    60,     4,    58,    36,     3,     5,    16,   100,
      63,    54,    61,    78,   101,    33,    51,    33,    52,    13,
      44,    44,    54,     7,    49,    44,    13,    54,    66,    67,
      68,    69,    70,    71,    40,    10,    41,    88,   103,   104,
     105,   106,   107,    31,    95,   108,     9,   109,    96,    50,
      39,    40,    54,    41,    77,    40,    44,    41,   114,    54,
     115,    11,    34,    55,    56,    48,    44,    44,    44,    44,
      44,    44,    39,    44,    44,    59,    51,    64,    65,    72,
      82,    74,   124,    79,    75,   127,    76,    83,    54,    98,
      89,    90,    91,    92,    93,    94,    54,    54,    97,    85,
      86,   132,   133,    44,    44,    44,    44,    44,    99,    20,
     102,   110,   111,    21,    44,    44,    22,   113,    23,   116,
     122,   123,   129,   130,    24,    25,   131,   117,   118,   119,
     120,   121,     0,    26,    53,    19,    20,     0,   125,   126,
      21,     0,     0,    22,    62,    23,    20,     0,     0,     0,
      21,    24,    25,    22,     0,    23,     0,    84,     0,    20,
      26,    24,    25,    21,     0,     0,    22,    87,    23,    20,
      26,     0,     0,    21,    24,    25,    22,     0,    23,     0,
       0,     0,    20,    26,    24,    25,    21,     0,     0,    22,
      73,    23,     0,    26,     0,    20,     0,    24,    25,    21,
       0,   112,    22,     0,    23,    20,    26,     0,   128,    21,
      24,    25,    22,     0,    23,     0,     0,     0,    20,    26,
      24,    25,    21,     0,     0,    22,     0,    23,    20,    26,
     134,     0,    21,    24,    25,    22,     0,    23,     0,     0,
     135,    20,    26,    24,    25,    21,     0,     0,    22,     0,
      23,     0,    26,     0,     0,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,    26
};

static const yytype_int16 yycheck[] =
{
      18,    27,    12,    31,    22,    12,    21,    12,    29,    12,
      32,    37,    29,    10,    32,    37,     0,    14,    39,    32,
      38,    47,    39,    51,    37,    32,    34,    32,    36,    39,
      20,    21,    58,    39,    24,    25,    39,    63,     3,     4,
       5,     6,     7,     8,    40,    36,    42,    65,    41,    42,
      43,    44,    45,    34,    72,    83,    11,    85,    73,    25,
      39,    40,    88,    42,    39,    40,    56,    42,    26,    95,
      28,    11,    39,    33,     9,    39,    66,    67,    68,    69,
      70,    71,    39,    73,    74,    39,    34,    40,    16,    20,
      56,    25,   110,    39,    33,   123,    33,    38,   124,    35,
      66,    67,    68,    69,    70,    71,   132,   133,    74,    34,
      39,   129,   130,   103,   104,   105,   106,   107,    35,    15,
      33,    17,    18,    19,   114,   115,    22,    33,    24,    39,
      35,    38,    20,    20,    30,    31,    35,   103,   104,   105,
     106,   107,    -1,    39,    13,    11,    15,    -1,   114,   115,
      19,    -1,    -1,    22,    13,    24,    15,    -1,    -1,    -1,
      19,    30,    31,    22,    -1,    24,    -1,    13,    -1,    15,
      39,    30,    31,    19,    -1,    -1,    22,    13,    24,    15,
      39,    -1,    -1,    19,    30,    31,    22,    -1,    24,    -1,
      -1,    -1,    15,    39,    30,    31,    19,    -1,    -1,    22,
      23,    24,    -1,    39,    -1,    15,    -1,    30,    31,    19,
      -1,    21,    22,    -1,    24,    15,    39,    -1,    18,    19,
      30,    31,    22,    -1,    24,    -1,    -1,    -1,    15,    39,
      30,    31,    19,    -1,    -1,    22,    -1,    24,    15,    39,
      27,    -1,    19,    30,    31,    22,    -1,    24,    -1,    -1,
      27,    15,    39,    30,    31,    19,    -1,    -1,    22,    -1,
      24,    -1,    39,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,    10,    14,    49,    39,    52,    11,
      36,    11,    12,    39,    54,    29,    39,    55,    12,    54,
      15,    19,    22,    24,    30,    31,    39,    50,    51,    53,
      60,    34,    12,    32,    39,    32,    37,    50,    12,    39,
      40,    42,    58,    59,    60,    61,    58,    50,    39,    60,
      59,    34,    36,    13,    51,    33,     9,    61,    50,    39,
      29,    39,    13,    50,    40,    16,     3,     4,     5,     6,
       7,     8,    20,    23,    25,    33,    33,    39,    61,    39,
      56,    57,    59,    38,    13,    34,    39,    13,    50,    59,
      59,    59,    59,    59,    59,    50,    58,    59,    35,    35,
      32,    37,    33,    41,    42,    43,    44,    45,    61,    61,
      17,    18,    21,    33,    26,    28,    39,    59,    59,    59,
      59,    59,    35,    38,    50,    59,    59,    61,    18,    20,
      20,    35,    50,    50,    27,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      52,    53,    54,    54,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    60,    60,    61,
      61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     8,     7,     0,     6,     5,     2,     1,
       4,     7,     5,     5,     5,     9,     9,     2,     3,     3,
       4,     4,     3,     8,     1,     6,     3,     4,     1,     2,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     4,     4,     1,
       2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program_all: procedures main  */
#line 58 "grammar.y"
                                        {
										(yyval.component) = new Component();
										(yyval.component)->code_line=0;
										(yyval.component)->type=16;
										(yyval.component)->number_value=0;
										(yyval.component)->pid_name=nullptr;
										(yyval.component)->children=(yyvsp[-1].component);
										(yyvsp[-1].component)->next = (yyvsp[0].component);
										(yyval.component)->next=nullptr;
										buildProgram((yyval.component));
										buildFile();
									}
#line 1254 "grammar.cpp"
    break;

  case 3: /* procedures: procedures PROCEDURE proc_head IS declarations T_BEGIN commands T_END  */
#line 71 "grammar.y"
                                                                                        {	
																							(yyval.component)=(yyvsp[-7].component);
																							Component* proc = new Component();
																							proc->code_line=yylineno;
																							proc->type=151;
																							proc->number_value=0;
																							proc->pid_name=nullptr;
																							proc->children=(yyvsp[-5].component);
																							proc->next=nullptr;
																							(yyvsp[-5].component)->next=(yyvsp[-3].component);
																							(yyvsp[-3].component)->next=(yyvsp[-1].component);
																							if((yyval.component)->children==nullptr){
																								(yyval.component)->children=proc; //first procedure
																							} else {
																								lastnext((yyval.component)->children)->next=proc;
																							}
																							useProc();
																						}
#line 1277 "grammar.cpp"
    break;

  case 4: /* procedures: procedures PROCEDURE proc_head IS T_BEGIN commands T_END  */
#line 89 "grammar.y"
                                                                                                        {	
																							(yyval.component)=(yyvsp[-6].component); //procedures
																							Component* proc = new Component();
																							proc->code_line=yylineno;
																							proc->type=152;
																							proc->number_value=0;
																							proc->pid_name=nullptr;
																							proc->children=(yyvsp[-4].component);
																							proc->next=nullptr;
																							(yyvsp[-4].component)->next=(yyvsp[-1].component);
																							if((yyval.component)->children==nullptr){
																								(yyval.component)->children=proc; //first procedure
																							} else {
																								lastnext((yyval.component)->children)->next=proc;
																							}
																							useProc();
																						}
#line 1299 "grammar.cpp"
    break;

  case 5: /* procedures: %empty  */
#line 106 "grammar.y"
                                                                                                                                                                {
																							(yyval.component) = new Component();
																							(yyval.component)->code_line=0;
																							(yyval.component)->type=15;
																							(yyval.component)->number_value=0;
																							(yyval.component)->pid_name=nullptr;
																							(yyval.component)->children=nullptr;
																							(yyval.component)->next=nullptr;
																						}
#line 1313 "grammar.cpp"
    break;

  case 6: /* main: PROGRAM IS declarations T_BEGIN commands T_END  */
#line 116 "grammar.y"
                                                                {	
																	(yyval.component) = new Component();
																	(yyval.component)->code_line=yylineno;
																	(yyval.component)->type=141;
																	(yyval.component)->number_value=0;
																	(yyval.component)->pid_name=nullptr;
																	(yyval.component)->children=(yyvsp[-3].component);
																	(yyvsp[-3].component)->next=(yyvsp[-1].component);
																	(yyval.component)->next=nullptr;
																}
#line 1328 "grammar.cpp"
    break;

  case 7: /* main: PROGRAM IS T_BEGIN commands T_END  */
#line 126 "grammar.y"
                                                                                {	
																	(yyval.component) = new Component();
																	(yyval.component)->code_line=yylineno;
																	(yyval.component)->type=142;
																	(yyval.component)->number_value=0;
																	(yyval.component)->pid_name=nullptr;
																	(yyval.component)->children=(yyvsp[-1].component);
																	(yyval.component)->next=nullptr;
																}
#line 1342 "grammar.cpp"
    break;

  case 8: /* commands: commands command  */
#line 136 "grammar.y"
                                        {	
										(yyval.component)=(yyvsp[-1].component);
										lastnext((yyval.component)->children)->next=(yyvsp[0].component);
									}
#line 1351 "grammar.cpp"
    break;

  case 9: /* commands: command  */
#line 140 "grammar.y"
                                                {	
										(yyval.component) = new Component();
										(yyval.component)->code_line=yylineno;
										(yyval.component)->type=13;
										(yyval.component)->number_value=0;
										(yyval.component)->pid_name=nullptr;
										(yyval.component)->children=(yyvsp[0].component);
										(yyval.component)->next=nullptr;
									}
#line 1365 "grammar.cpp"
    break;

  case 10: /* command: identifier SET expression SEMICOLON  */
#line 150 "grammar.y"
                                                                                                        {	
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=121;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=(yyvsp[-3].component);
																				(yyvsp[-3].component)->next=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																			}
#line 1380 "grammar.cpp"
    break;

  case 11: /* command: IF condition THEN commands ELSE commands ENDIF  */
#line 160 "grammar.y"
                                                                                        {	
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=122;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=(yyvsp[-5].component);
																				(yyvsp[-5].component)->next=(yyvsp[-3].component);
																				(yyvsp[-3].component)->next=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																			}
#line 1396 "grammar.cpp"
    break;

  case 12: /* command: IF condition THEN commands ENDIF  */
#line 171 "grammar.y"
                                                                                                        {	
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=123;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=(yyvsp[-3].component);
																				(yyvsp[-3].component)->next=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																			}
#line 1411 "grammar.cpp"
    break;

  case 13: /* command: WHILE condition DO commands ENDWHILE  */
#line 181 "grammar.y"
                                                                                                        {	
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=124;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=(yyvsp[-3].component);
																				(yyvsp[-3].component)->next=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																			}
#line 1426 "grammar.cpp"
    break;

  case 14: /* command: REPEAT commands UNTIL condition SEMICOLON  */
#line 191 "grammar.y"
                                                                                                {	
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=125;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=(yyvsp[-3].component);
																				(yyvsp[-3].component)->next=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																			}
#line 1441 "grammar.cpp"
    break;

  case 15: /* command: FOR pidentifier FROM value TO value DO commands ENDFOR  */
#line 201 "grammar.y"
                                                                                {	
																				Component* pid = new Component();
																				pid->code_line=yylineno;
																				pid->type=2; //type=pidentifier;
																				pid->number_value=0;
																				pid->pid_name=strdup((yyvsp[-7].stringid));
																				pid->children=nullptr;
																				pid->next=nullptr;
			 
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=126;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=pid;
																				pid->next=(yyvsp[-5].component);
																				(yyvsp[-5].component)->next=(yyvsp[-3].component);
																				(yyvsp[-3].component)->next=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																				useFor();
																			}
#line 1467 "grammar.cpp"
    break;

  case 16: /* command: FOR pidentifier FROM value DOWNTO value DO commands ENDFOR  */
#line 222 "grammar.y"
                                                                                {		
																				Component* pid = new Component();
																				pid->code_line=yylineno;
																				pid->type=2; //type=pidentifier;
																				pid->number_value=0;
																				pid->pid_name=strdup((yyvsp[-7].stringid));
																				pid->children=nullptr;
																				pid->next=nullptr;
																				
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=127;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=pid;
																				pid->next=(yyvsp[-5].component);
																				(yyvsp[-5].component)->next=(yyvsp[-3].component);
																				(yyvsp[-3].component)->next=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																				useFor();
																			}
#line 1493 "grammar.cpp"
    break;

  case 17: /* command: proc_call SEMICOLON  */
#line 243 "grammar.y"
                                                                                                                        {	
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=128;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																			}
#line 1507 "grammar.cpp"
    break;

  case 18: /* command: READ identifier SEMICOLON  */
#line 252 "grammar.y"
                                                                                                                {	
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=129;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																			}
#line 1521 "grammar.cpp"
    break;

  case 19: /* command: WRITE value SEMICOLON  */
#line 261 "grammar.y"
                                                                                                                {	
																				(yyval.component) = new Component();
																				(yyval.component)->code_line=yylineno;
																				(yyval.component)->type=1210;
																				(yyval.component)->number_value=0;
																				(yyval.component)->pid_name=nullptr;
																				(yyval.component)->children=(yyvsp[-1].component);
																				(yyval.component)->next=nullptr;
																			}
#line 1535 "grammar.cpp"
    break;

  case 20: /* proc_head: pidentifier LB args_decl RB  */
#line 271 "grammar.y"
                                                {	
												Component* pid = new Component();
												pid->code_line=yylineno;
												pid->type=2; //type=pidentifier;
												pid->number_value=0;
												pid->pid_name=strdup((yyvsp[-3].stringid));
												pid->children=nullptr;
												pid->next=(yyvsp[-1].component);
												
												(yyval.component) = new Component();
												(yyval.component)->code_line=yylineno;
												(yyval.component)->type=11;
												(yyval.component)->number_value=0;
												(yyval.component)->pid_name=nullptr;
												(yyval.component)->children=pid;
											}
#line 1556 "grammar.cpp"
    break;

  case 21: /* proc_call: pidentifier LB args RB  */
#line 288 "grammar.y"
                                                {	
												Component* pid = new Component();
												pid->code_line=yylineno;
												pid->type=2; //type=pidentifier;
												pid->number_value=0;
												pid->pid_name=strdup((yyvsp[-3].stringid));
												pid->children=nullptr;
												pid->next=(yyvsp[-1].component);
												
												(yyval.component) = new Component();
												(yyval.component)->code_line=yylineno;
												(yyval.component)->type=10;
												(yyval.component)->number_value=0;
												(yyval.component)->pid_name=nullptr;
												(yyval.component)->children=pid;
											}
#line 1577 "grammar.cpp"
    break;

  case 22: /* declarations: declarations COMMA pidentifier  */
#line 305 "grammar.y"
                                                                                        {	
																		Component* pid = new Component();
																		pid->code_line=yylineno;
																		pid->type=21; //type=pidentifier;
																		pid->number_value=0;
																		pid->pid_name=strdup((yyvsp[0].stringid));
																		pid->children=nullptr;
																		pid->next=nullptr;
																		
																		(yyval.component)=(yyvsp[-2].component);
																		lastnext((yyval.component)->children)->next=pid;
																	}
#line 1594 "grammar.cpp"
    break;

  case 23: /* declarations: declarations COMMA pidentifier SLB num COLON num SRB  */
#line 317 "grammar.y"
                                                                        {	
																		Component* pid = new Component();
																		pid->code_line=yylineno;
																		pid->type=22; //type=pidentifier;
																		pid->number_value=0;
																		pid->pid_name=strdup((yyvsp[-5].stringid));
																		pid->children=(yyvsp[-3].component);
																		pid->next=nullptr;
																		(yyvsp[-3].component)->next=(yyvsp[-1].component);
																		
																		(yyval.component)=(yyvsp[-7].component);
																		lastnext((yyval.component)->children)->next=pid;
																	}
#line 1612 "grammar.cpp"
    break;

  case 24: /* declarations: pidentifier  */
#line 330 "grammar.y"
                                                                                                                {	
																		Component* pid = new Component();
																		pid->code_line=yylineno;
																		pid->type=21; //type=pidentifier;
																		pid->number_value=0;
																		pid->pid_name=strdup((yyvsp[0].stringid));
																		pid->children=nullptr;
																		pid->next=nullptr;
																		
																		(yyval.component) = new Component();
																		(yyval.component)->code_line=yylineno;
																		(yyval.component)->type=9;
																		(yyval.component)->number_value=0;
																		(yyval.component)->pid_name=nullptr;
																		(yyval.component)->children=pid;
																		(yyval.component)->next=nullptr;
																	}
#line 1634 "grammar.cpp"
    break;

  case 25: /* declarations: pidentifier SLB num COLON num SRB  */
#line 347 "grammar.y"
                                                                                        {	
																		Component* pid = new Component();
																		pid->code_line=yylineno;
																		pid->type=22; //type=pidentifier;
																		pid->number_value=0;
																		pid->pid_name=strdup((yyvsp[-5].stringid));
																		pid->children=(yyvsp[-3].component);
																		pid->next=nullptr;
																		(yyvsp[-3].component)->next=(yyvsp[-1].component);
																		
																		(yyval.component) = new Component();
																		(yyval.component)->code_line=yylineno;
																		(yyval.component)->type=9;
																		(yyval.component)->number_value=0;
																		(yyval.component)->pid_name=nullptr;
																		(yyval.component)->children=pid;
																		(yyval.component)->next=nullptr;
																	}
#line 1657 "grammar.cpp"
    break;

  case 26: /* args_decl: args_decl COMMA pidentifier  */
#line 366 "grammar.y"
                                                        {	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=21; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup((yyvsp[0].stringid));
													pid->children=nullptr;
													pid->next=nullptr;
													
													(yyval.component)=(yyvsp[-2].component);
													lastnext((yyval.component)->children)->next = pid;//NIEPEWNY JESTEM
												}
#line 1674 "grammar.cpp"
    break;

  case 27: /* args_decl: args_decl COMMA T pidentifier  */
#line 378 "grammar.y"
                                                {	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=22; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup((yyvsp[0].stringid));
													pid->children=nullptr;
													pid->next=nullptr;
													
													(yyval.component)=(yyvsp[-3].component);
													lastnext((yyval.component)->children)->next = pid;//NIEPEWNY JESTEM
												}
#line 1691 "grammar.cpp"
    break;

  case 28: /* args_decl: pidentifier  */
#line 390 "grammar.y"
                                                                        {	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=21; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup((yyvsp[0].stringid));
													pid->children=nullptr;
													pid->next=nullptr;
													
													(yyval.component) = new Component();
													(yyval.component)->code_line=yylineno;
													(yyval.component)->type=8;
													(yyval.component)->number_value=0;
													(yyval.component)->pid_name=nullptr;
													(yyval.component)->children=pid;
													(yyval.component)->next=nullptr;
												}
#line 1713 "grammar.cpp"
    break;

  case 29: /* args_decl: T pidentifier  */
#line 407 "grammar.y"
                                                                {	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=22; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup((yyvsp[0].stringid));
													pid->children=nullptr;
													pid->next=nullptr;
													
													(yyval.component) = new Component();
													(yyval.component)->code_line=yylineno;
													(yyval.component)->type=8;
													(yyval.component)->number_value=0;
													(yyval.component)->pid_name=nullptr;
													(yyval.component)->children=pid;
													(yyval.component)->next=nullptr;
												}
#line 1735 "grammar.cpp"
    break;

  case 30: /* args: args COMMA pidentifier  */
#line 425 "grammar.y"
                                        {	
											Component* pid = new Component();
											pid->code_line=yylineno;
											pid->type=2; //type=pidentifier;
											pid->number_value=0;
											pid->pid_name=strdup((yyvsp[0].stringid));
											pid->children=nullptr;
											pid->next=nullptr;
											
											(yyval.component)=(yyvsp[-2].component);
											lastnext((yyval.component)->children)->next=pid;
										}
#line 1752 "grammar.cpp"
    break;

  case 31: /* args: pidentifier  */
#line 437 "grammar.y"
                                                        {		
											Component* pid = new Component();
											pid->code_line=yylineno;
											pid->type=2; //type=pidentifier;
											pid->number_value=0;
											pid->pid_name=strdup((yyvsp[0].stringid));
											pid->children=nullptr;
											pid->next=nullptr;
											
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=7;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=pid;
											(yyval.component)->next=nullptr;
										}
#line 1774 "grammar.cpp"
    break;

  case 32: /* expression: value  */
#line 455 "grammar.y"
                                                        {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=61;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1788 "grammar.cpp"
    break;

  case 33: /* expression: value ADD value  */
#line 464 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=62;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next=(yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1803 "grammar.cpp"
    break;

  case 34: /* expression: value SUB value  */
#line 474 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=63;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next=(yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1818 "grammar.cpp"
    break;

  case 35: /* expression: value MUL value  */
#line 484 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=64;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next=(yyvsp[0].component);
											(yyval.component)->next=nullptr;
											if((yyvsp[-2].component)->children->type!=1 && (yyvsp[0].component)->children->type!=1){
												useMul();
											} else{
												if((yyvsp[-2].component)->children->type==1){
													if((yyvsp[-2].component)->children->number_value>49 && (yyvsp[-2].component)->children->number_value<(-49)){
														useMul();
													}
												}
												if((yyvsp[0].component)->children->type==1){
													if((yyvsp[0].component)->children->number_value>49 && (yyvsp[0].component)->children->number_value<(-49)){
														useMul();
													}
												}
											}
										}
#line 1847 "grammar.cpp"
    break;

  case 36: /* expression: value DIV value  */
#line 508 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=65;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next=(yyvsp[0].component);
											(yyval.component)->next=nullptr;
											if((yyvsp[-2].component)->children->type==1 && (yyvsp[0].component)->children->type==1){
												//dont use div just place a number here
											} else if ((yyvsp[0].component)->children->number_value==2){
												//use half
											} else {
												useDiv();
											}
										}
#line 1869 "grammar.cpp"
    break;

  case 37: /* expression: value MOD value  */
#line 525 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=66;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next=(yyvsp[0].component);
											(yyval.component)->next=nullptr;
											if((yyvsp[-2].component)->children->type==1 && (yyvsp[0].component)->children->type==1){
												//dont use div just place a number here
											} else if ((yyvsp[0].component)->children->number_value==2){
												//use half
												//and sub
											} else {
												useMod();
											}
										}
#line 1892 "grammar.cpp"
    break;

  case 38: /* condition: value EQ value  */
#line 544 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=51;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next = (yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1907 "grammar.cpp"
    break;

  case 39: /* condition: value NEQ value  */
#line 554 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=52;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next = (yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1922 "grammar.cpp"
    break;

  case 40: /* condition: value GT value  */
#line 564 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=53;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next = (yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1937 "grammar.cpp"
    break;

  case 41: /* condition: value LT value  */
#line 574 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=54;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next = (yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1952 "grammar.cpp"
    break;

  case 42: /* condition: value GEQ value  */
#line 584 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=55;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next = (yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1967 "grammar.cpp"
    break;

  case 43: /* condition: value LEQ value  */
#line 594 "grammar.y"
                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=56;
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[-2].component);
											(yyvsp[-2].component)->next = (yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1982 "grammar.cpp"
    break;

  case 44: /* value: num  */
#line 605 "grammar.y"
                                                                {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=41; //type=value ale moze mozna by robic odrazu skoierowanie na num
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 1996 "grammar.cpp"
    break;

  case 45: /* value: identifier  */
#line 614 "grammar.y"
                                                        {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=42; //type=value ale moznaby robic odrazu skoierowanie na num
											(yyval.component)->number_value=0;
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=(yyvsp[0].component);
											(yyval.component)->next=nullptr;
										}
#line 2010 "grammar.cpp"
    break;

  case 46: /* identifier: pidentifier  */
#line 624 "grammar.y"
                                                                        {	
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=2; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup((yyvsp[0].stringid));
													pid->children=nullptr;
													pid->next=nullptr;
													
													(yyval.component) = new Component();
													(yyval.component)->code_line=yylineno;
													(yyval.component)->type=31; //type=identifier;
													(yyval.component)->number_value=0;
													(yyval.component)->pid_name=nullptr;
													(yyval.component)->children=pid;
													(yyval.component)->next=nullptr;
												}
#line 2032 "grammar.cpp"
    break;

  case 47: /* identifier: pidentifier SLB pidentifier SRB  */
#line 641 "grammar.y"
                                                {
													Component* pid1 = new Component();
													pid1->code_line=yylineno;
													pid1->type=2; //type=pidentifier;
													pid1->number_value=0;
													pid1->pid_name=strdup((yyvsp[-3].stringid));
													pid1->children=nullptr;
													
													Component* pid2 = new Component();
													pid2->code_line=yylineno;
													pid2->type=2; //type=pidentifier;
													pid2->number_value=0;
													pid2->pid_name=strdup((yyvsp[-1].stringid));
													pid2->children=nullptr;
													pid2->next=nullptr;
													
													pid1->next=pid2;
													
													(yyval.component) = new Component();
													(yyval.component)->code_line=yylineno;
													(yyval.component)->type=32; //type=identifier;
													(yyval.component)->number_value=0;
													(yyval.component)->pid_name=nullptr;
													(yyval.component)->children=pid1;
													(yyval.component)->next=nullptr;
												}
#line 2063 "grammar.cpp"
    break;

  case 48: /* identifier: pidentifier SLB num SRB  */
#line 667 "grammar.y"
                                                        {
													Component* pid = new Component();
													pid->code_line=yylineno;
													pid->type=2; //type=pidentifier;
													pid->number_value=0;
													pid->pid_name=strdup((yyvsp[-3].stringid));
													pid->children=nullptr;
													pid->next=(yyvsp[-1].component);
													
													(yyval.component) = new Component();
													(yyval.component)->code_line=yylineno;
													(yyval.component)->type=33; //type=identifier;
													(yyval.component)->number_value=0;
													(yyval.component)->pid_name=nullptr;
													(yyval.component)->children=pid;
													(yyval.component)->next=nullptr;
													}
#line 2085 "grammar.cpp"
    break;

  case 49: /* num: NUMBER  */
#line 685 "grammar.y"
                                                                        {	
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=1; //type=num;
											(yyval.component)->number_value=(yyvsp[0].number);
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=nullptr;
											(yyval.component)->next=nullptr;
										}
#line 2099 "grammar.cpp"
    break;

  case 50: /* num: SUB NUMBER  */
#line 694 "grammar.y"
                                                                {
											(yyval.component) = new Component();
											(yyval.component)->code_line=yylineno;
											(yyval.component)->type=1; //type=1;
											(yyval.component)->number_value=-(yyvsp[0].number);
											(yyval.component)->pid_name=nullptr;
											(yyval.component)->children=nullptr;
											(yyval.component)->next=nullptr;
										}
#line 2113 "grammar.cpp"
    break;


#line 2117 "grammar.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 704 "grammar.y"

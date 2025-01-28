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
#line 1 "cmm.y"

/**
   The cmm compiler
   2004.08.18
   2005.06.13
   Hisashi Nakai, University of Tsukuba
**/
  
#include <stdio.h>
#include <stdlib.h>

#include "env.h"
#include "code.h"

FILE *ofile;

int level = 0;
int offset = 0; 

typedef struct Codeval {
  cptr* code;
  int   val;
  char* name;
} codeval;

#define YYSTYPE codeval
int yylex();
int yyerror(char const *);

#line 101 "y.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VAR = 258,                     /* VAR  */
    MAIN = 259,                    /* MAIN  */
    ID = 260,                      /* ID  */
    LPAR = 261,                    /* LPAR  */
    RPAR = 262,                    /* RPAR  */
    COMMA = 263,                   /* COMMA  */
    LBRA = 264,                    /* LBRA  */
    RBRA = 265,                    /* RBRA  */
    WRITE = 266,                   /* WRITE  */
    WRITELN = 267,                 /* WRITELN  */
    SEMI = 268,                    /* SEMI  */
    PLUS = 269,                    /* PLUS  */
    MINUS = 270,                   /* MINUS  */
    MULT = 271,                    /* MULT  */
    DIV = 272,                     /* DIV  */
    NUMBER = 273,                  /* NUMBER  */
    IF = 274,                      /* IF  */
    THEN = 275,                    /* THEN  */
    ELSE = 276,                    /* ELSE  */
    ENDIF = 277,                   /* ENDIF  */
    WHILE = 278,                   /* WHILE  */
    DO = 279,                      /* DO  */
    READ = 280,                    /* READ  */
    COLEQ = 281,                   /* COLEQ  */
    GE = 282,                      /* GE  */
    GT = 283,                      /* GT  */
    LE = 284,                      /* LE  */
    LT = 285,                      /* LT  */
    NE = 286,                      /* NE  */
    EQ = 287,                      /* EQ  */
    RETURN = 288                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VAR 258
#define MAIN 259
#define ID 260
#define LPAR 261
#define RPAR 262
#define COMMA 263
#define LBRA 264
#define RBRA 265
#define WRITE 266
#define WRITELN 267
#define SEMI 268
#define PLUS 269
#define MINUS 270
#define MULT 271
#define DIV 272
#define NUMBER 273
#define IF 274
#define THEN 275
#define ELSE 276
#define ENDIF 277
#define WHILE 278
#define DO 279
#define READ 280
#define COLEQ 281
#define GE 282
#define GT 283
#define LE 284
#define LT 285
#define NE 286
#define EQ 287
#define RETURN 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VAR = 3,                        /* VAR  */
  YYSYMBOL_MAIN = 4,                       /* MAIN  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_LPAR = 6,                       /* LPAR  */
  YYSYMBOL_RPAR = 7,                       /* RPAR  */
  YYSYMBOL_COMMA = 8,                      /* COMMA  */
  YYSYMBOL_LBRA = 9,                       /* LBRA  */
  YYSYMBOL_RBRA = 10,                      /* RBRA  */
  YYSYMBOL_WRITE = 11,                     /* WRITE  */
  YYSYMBOL_WRITELN = 12,                   /* WRITELN  */
  YYSYMBOL_SEMI = 13,                      /* SEMI  */
  YYSYMBOL_PLUS = 14,                      /* PLUS  */
  YYSYMBOL_MINUS = 15,                     /* MINUS  */
  YYSYMBOL_MULT = 16,                      /* MULT  */
  YYSYMBOL_DIV = 17,                       /* DIV  */
  YYSYMBOL_NUMBER = 18,                    /* NUMBER  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_THEN = 20,                      /* THEN  */
  YYSYMBOL_ELSE = 21,                      /* ELSE  */
  YYSYMBOL_ENDIF = 22,                     /* ENDIF  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_READ = 25,                      /* READ  */
  YYSYMBOL_COLEQ = 26,                     /* COLEQ  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_GT = 28,                        /* GT  */
  YYSYMBOL_LE = 29,                        /* LE  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_NE = 31,                        /* NE  */
  YYSYMBOL_EQ = 32,                        /* EQ  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_main = 36,                      /* main  */
  YYSYMBOL_fdecls = 37,                    /* fdecls  */
  YYSYMBOL_fdecl = 38,                     /* fdecl  */
  YYSYMBOL_fhead = 39,                     /* fhead  */
  YYSYMBOL_fid = 40,                       /* fid  */
  YYSYMBOL_params = 41,                    /* params  */
  YYSYMBOL_body = 42,                      /* body  */
  YYSYMBOL_vdaction = 43,                  /* vdaction  */
  YYSYMBOL_vardecls = 44,                  /* vardecls  */
  YYSYMBOL_vardecl = 45,                   /* vardecl  */
  YYSYMBOL_ids = 46,                       /* ids  */
  YYSYMBOL_stmts = 47,                     /* stmts  */
  YYSYMBOL_st = 48,                        /* st  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_ifstmt = 50,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 51,                 /* whilestmt  */
  YYSYMBOL_cond = 52,                      /* cond  */
  YYSYMBOL_E = 53,                         /* E  */
  YYSYMBOL_T = 54,                         /* T  */
  YYSYMBOL_F = 55,                         /* F  */
  YYSYMBOL_fparams = 56,                   /* fparams  */
  YYSYMBOL_ac_params = 57,                 /* ac_params  */
  YYSYMBOL_fparam = 58                     /* fparam  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   93

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    68,    74,    77,    82,    93,   107,   119,
     131,   144,   150,   158,   169,   175,   180,   187,   199,   213,
     223,   230,   235,   240,   259,   277,   278,   279,   279,   286,
     297,   310,   329,   350,   355,   360,   365,   370,   375,   382,
     387,   392,   398,   403,   408,   414,   431,   453,   457,   464,
     468,   475,   480,   487
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
  "\"end of file\"", "error", "\"invalid token\"", "VAR", "MAIN", "ID",
  "LPAR", "RPAR", "COMMA", "LBRA", "RBRA", "WRITE", "WRITELN", "SEMI",
  "PLUS", "MINUS", "MULT", "DIV", "NUMBER", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "READ", "COLEQ", "GE", "GT", "LE", "LT", "NE", "EQ",
  "RETURN", "$accept", "program", "main", "fdecls", "fdecl", "fhead",
  "fid", "params", "body", "vdaction", "vardecls", "vardecl", "ids",
  "stmts", "st", "$@1", "ifstmt", "whilestmt", "cond", "E", "T", "F",
  "fparams", "ac_params", "fparam", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-20)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -20,     3,     6,   -20,     5,   -20,   -20,   -20,     5,    30,
     -20,   -20,   -20,     7,    46,    52,   -20,    56,    24,    13,
      55,    13,    13,    54,    13,    -3,   -20,     5,   -20,   -20,
      65,   -20,   -20,    72,    13,    77,    13,   -20,    19,    50,
     -20,   -20,    58,    10,    60,    73,    39,   -20,   -20,   -20,
     -20,    -7,   -20,    47,    13,    14,   -20,    13,    13,    13,
      13,    46,    13,    13,    13,    13,    13,    13,    46,   -20,
     -20,    80,   -20,   -20,    12,    81,    79,   -20,   -20,    50,
      50,   -20,   -20,    51,    12,    12,    12,    12,    12,    12,
     -20,   -20,   -20,    13,    46,    76,   -20,    68,   -20,    78,
     -20
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     8,     2,     4,     0,     0,
      15,     3,     6,    11,    27,    13,    10,     0,     0,     0,
       0,     0,     0,     0,     0,    27,    20,     0,    25,    26,
       0,    14,     7,     0,     0,    45,     0,    47,     0,    41,
      44,    22,     0,     0,     0,     0,     0,    12,    19,    28,
      18,     0,     9,     0,    49,     0,    21,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,    27,    23,
      29,     0,    16,    24,    53,     0,    50,    52,    48,    39,
      40,    42,    43,     0,    34,    33,    36,    35,    37,    38,
      32,    17,    46,     0,    27,     0,    51,     0,    30,     0,
      31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,    -4,   -20,
     -20,   -20,   -20,   -20,   -12,   -20,   -20,   -20,    70,   -19,
      18,    21,   -20,   -20,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     6,     2,     7,     8,     9,    17,    11,    14,
      15,    31,    51,    25,    26,    27,    28,    29,    42,    43,
      39,    40,    75,    76,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,    71,    18,     3,    12,    46,    72,    47,    19,    20,
       4,     5,    16,    48,    10,    53,    21,    55,    35,    36,
      22,    78,    23,    49,    57,    58,    57,    58,    57,    58,
      24,    37,    56,    57,    58,    74,    13,    62,    63,    64,
      65,    66,    67,    84,    85,    86,    87,    88,    89,    83,
      34,    18,    70,    57,    58,    30,    90,    19,    20,    45,
      73,    57,    58,    32,    33,    21,    59,    60,    41,    22,
      50,    23,    94,    95,    74,    79,    80,    52,    61,    24,
      81,    82,    97,    54,    68,    91,    69,    93,    92,    98,
      99,   100,    44,    96
};

static const yytype_int8 yycheck[] =
{
      19,     8,     5,     0,     8,    24,    13,    10,    11,    12,
       4,     5,     5,    25,     9,    34,    19,    36,     5,     6,
      23,     7,    25,    27,    14,    15,    14,    15,    14,    15,
      33,    18,    13,    14,    15,    54,     6,    27,    28,    29,
      30,    31,    32,    62,    63,    64,    65,    66,    67,    61,
      26,     5,    13,    14,    15,     3,    68,    11,    12,     5,
      13,    14,    15,     7,     8,    19,    16,    17,    13,    23,
       5,    25,    21,    22,    93,    57,    58,     5,    20,    33,
      59,    60,    94,     6,    24,     5,    13,     8,     7,    13,
      22,    13,    22,    93
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    35,    37,     0,     4,     5,    36,    38,    39,    40,
       9,    42,    42,     6,    43,    44,     5,    41,     5,    11,
      12,    19,    23,    25,    33,    47,    48,    49,    50,    51,
       3,    45,     7,     8,    26,     5,     6,    18,    53,    54,
      55,    13,    52,    53,    52,     5,    53,    10,    48,    42,
       5,    46,     5,    53,     6,    53,    13,    14,    15,    16,
      17,    20,    27,    28,    29,    30,    31,    32,    24,    13,
      13,     8,    13,    13,    53,    56,    57,    58,     7,    54,
      54,    55,    55,    48,    53,    53,    53,    53,    53,    53,
      48,     5,     7,     8,    21,    22,    58,    48,    13,    22,
      13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    38,    39,    40,    41,
      41,    41,    42,    43,    44,    44,    45,    46,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    49,    48,    48,
      50,    50,    51,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     4,     1,     3,
       1,     0,     4,     1,     2,     0,     3,     3,     1,     2,
       1,     3,     2,     3,     4,     1,     1,     0,     2,     3,
       6,     8,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     4,     1,     3,     0,
       1,     3,     1,     1
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
  case 2: /* program: fdecls main  */
#line 51 "cmm.y"
                      {
            cptr *tmp;
	    int label0;

	    label0 = makelabel();

            tmp = makecode(O_JMP, 0, label0);
	    tmp = mergecode(tmp, yyvsp[-1].code);
	    tmp = mergecode(tmp, makecode(O_LAB, 0, label0));
	    tmp = mergecode(tmp, makecode(O_INT, 0, yyvsp[0].val + SYSTEM_AREA));
	    tmp = mergecode(tmp, yyvsp[0].code);
            tmp = mergecode(tmp, makecode(O_OPR, 0, 0));

            printcode(ofile, tmp);
	  }
#line 1325 "y.tab.c"
    break;

  case 3: /* main: MAIN body  */
#line 68 "cmm.y"
                    {
	    yyval.code = yyvsp[0].code;
	    yyval.val = yyvsp[0].val;
	  }
#line 1334 "y.tab.c"
    break;

  case 4: /* fdecls: fdecls fdecl  */
#line 74 "cmm.y"
                       {
	    yyval.code = mergecode(yyvsp[-1].code, yyvsp[0].code);
	  }
#line 1342 "y.tab.c"
    break;

  case 5: /* fdecls: %empty  */
#line 77 "cmm.y"
                        {
	    yyval.code = NULL;
	  }
#line 1350 "y.tab.c"
    break;

  case 6: /* fdecl: fhead body  */
#line 83 "cmm.y"
          {
            cptr *tmp, *tmp2;

            tmp = makecode(O_LAB, 0, yyvsp[-1].val);
            tmp2 = makecode(O_INT, 0, yyvsp[0].val + SYSTEM_AREA);
	    yyval.code = mergecode(mergecode(tmp, tmp2), yyvsp[0].code);
	    delete_block();
	  }
#line 1363 "y.tab.c"
    break;

  case 7: /* fhead: fid LPAR params RPAR  */
#line 94 "cmm.y"
          {
	    int   label;
	    int   i;
	    list *tmp;

	    label = makelabel();

	    make_params(yyvsp[-1].val+1, label);

	    yyval.val = label;
	  }
#line 1379 "y.tab.c"
    break;

  case 8: /* fid: ID  */
#line 108 "cmm.y"
          {
	    if (search_all(yyvsp[0].name) == NULL){
	      addlist(yyvsp[0].name, FUNC, 0, level, 0);
	    }
	    else {
	      sem_error1("fid");
	    }
	    addlist("block", BLOCK, 0, 0, 0);
	  }
#line 1393 "y.tab.c"
    break;

  case 9: /* params: params COMMA ID  */
#line 120 "cmm.y"
          {
	    if (search_block(yyvsp[0].name) == NULL){
	      addlist(yyvsp[0].name, VARIABLE, 0, level, 0);
	    }
	    else {
	      sem_error1("params");
	    }

	    yyval.code = NULL;
	    yyval.val = yyvsp[-2].val + 1;
	  }
#line 1409 "y.tab.c"
    break;

  case 10: /* params: ID  */
#line 132 "cmm.y"
          {
	    if (search_block(yyvsp[0].name) == NULL){
	      addlist(yyvsp[0].name, VARIABLE, 0, level, 0);
	    }
	    else {
	      sem_error1("params2");
	    }

	    yyval.code = NULL;
	    yyval.val = 1;
	  }
#line 1425 "y.tab.c"
    break;

  case 11: /* params: %empty  */
#line 144 "cmm.y"
          {
	    yyval.val = 0;
	    yyval.code = NULL;
	  }
#line 1434 "y.tab.c"
    break;

  case 12: /* body: LBRA vdaction stmts RBRA  */
#line 151 "cmm.y"
          {
	    yyval.code = yyvsp[-1].code;
	    yyval.val = yyvsp[-2].val + yyvsp[-1].val;
	    offset = offset - yyvsp[-2].val;
	  }
#line 1444 "y.tab.c"
    break;

  case 13: /* vdaction: vardecls  */
#line 159 "cmm.y"
          {
	    int i;

	    vd_backpatch(yyvsp[0].val, offset);

	    yyval.val = yyvsp[0].val;
	    offset = offset + yyvsp[0].val;
	  }
#line 1457 "y.tab.c"
    break;

  case 14: /* vardecls: vardecls vardecl  */
#line 170 "cmm.y"
          {
	    yyval.val = yyvsp[-1].val + yyvsp[0].val;
	    yyval.code = NULL;
	  }
#line 1466 "y.tab.c"
    break;

  case 15: /* vardecls: %empty  */
#line 175 "cmm.y"
          {
	    yyval.val = 0;
	  }
#line 1474 "y.tab.c"
    break;

  case 16: /* vardecl: VAR ids SEMI  */
#line 181 "cmm.y"
          {
	    yyval.val = yyvsp[-1].val;
	    yyval.code = NULL;
	  }
#line 1483 "y.tab.c"
    break;

  case 17: /* ids: ids COMMA ID  */
#line 188 "cmm.y"
          {
	    if (search_block(yyvsp[0].name) == NULL){
	      addlist(yyvsp[0].name, VARIABLE, 0, level, 0);
	    }
	    else {
	      sem_error1("var");
	    }

	    yyval.code = NULL;
	    yyval.val = yyvsp[-2].val + 1;
	  }
#line 1499 "y.tab.c"
    break;

  case 18: /* ids: ID  */
#line 200 "cmm.y"
          {
	    if (search_block(yyvsp[0].name) == NULL){
	      addlist(yyvsp[0].name, VARIABLE, 0, level, 0);
	    }
	    else {
	      sem_error1("var");
	    }

	    yyval.code = NULL;
	    yyval.val = 1;
	  }
#line 1515 "y.tab.c"
    break;

  case 19: /* stmts: stmts st  */
#line 214 "cmm.y"
          {
	    yyval.code = mergecode(yyvsp[-1].code, yyvsp[0].code);
	    if (yyvsp[-1].val < yyvsp[0].val){
	      yyval.val = yyvsp[0].val;
	    }
	    else {
	      yyval.val = yyvsp[-1].val;
	    }
	  }
#line 1529 "y.tab.c"
    break;

  case 20: /* stmts: st  */
#line 224 "cmm.y"
          {
	    yyval.code = yyvsp[0].code;
	    yyval.val = yyvsp[0].val;
	  }
#line 1538 "y.tab.c"
    break;

  case 21: /* st: WRITE E SEMI  */
#line 231 "cmm.y"
          {
	    yyval.code = mergecode(yyvsp[-1].code, makecode(O_CSP, 0, 1));
	    yyval.val = 0;
	  }
#line 1547 "y.tab.c"
    break;

  case 22: /* st: WRITELN SEMI  */
#line 236 "cmm.y"
          {
	    yyval.code = makecode(O_CSP, 0, 2);
	    yyval.val = 0;
	  }
#line 1556 "y.tab.c"
    break;

  case 23: /* st: READ ID SEMI  */
#line 241 "cmm.y"
          {
            cptr *tmp;
	    list *tmp2;

	    tmp2 = search_all(yyvsp[-1].name);

	    if (tmp2 == NULL){
	      sem_error2("read");
	    }

	    if (tmp2->kind != VARIABLE){
	      sem_error2("as function");
	    }

	    yyval.code = mergecode(makecode(O_CSP, 0, 0),
				makecode(O_STO, level - tmp2->l, tmp2->a));
	    yyval.val = 0;
	  }
#line 1579 "y.tab.c"
    break;

  case 24: /* st: ID COLEQ E SEMI  */
#line 260 "cmm.y"
          {
	    list *tmp;

	    tmp = search_all(yyvsp[-3].name);

	    if (tmp == NULL){
	      sem_error2("assignment");
	    }

	    if (tmp->kind != VARIABLE){
	      sem_error2("assignment2");
	    }

	    yyval.code = mergecode(yyvsp[-1].code,
				makecode(O_STO, level - tmp->l, tmp->a));
	    yyval.val = 0;
	  }
#line 1601 "y.tab.c"
    break;

  case 27: /* $@1: %empty  */
#line 279 "cmm.y"
          { addlist("block", BLOCK, 0, 0, 0); }
#line 1607 "y.tab.c"
    break;

  case 28: /* st: $@1 body  */
#line 281 "cmm.y"
          {
	    yyval.code = yyvsp[0].code;
	    yyval.val = yyvsp[0].val;
	    delete_block();
	  }
#line 1617 "y.tab.c"
    break;

  case 29: /* st: RETURN E SEMI  */
#line 287 "cmm.y"
          {
	    list* tmp2;

	    tmp2 = searchf(level);

	    yyval.code = mergecode(yyvsp[-1].code, makecode(O_RET, 0, tmp2->params));
	    yyval.val = 0;
	  }
#line 1630 "y.tab.c"
    break;

  case 30: /* ifstmt: IF cond THEN st ENDIF SEMI  */
#line 298 "cmm.y"
          {
	    cptr *tmp;
	    int label0, label1;

	    label0 = makelabel();

	    tmp = mergecode(yyvsp[-4].code, makecode(O_JPC, 0, label0));
	    tmp = mergecode(tmp, yyvsp[-2].code);

	    yyval.code = mergecode(tmp, makecode(O_LAB, 0, label0));
	    yyval.val = 0;
	  }
#line 1647 "y.tab.c"
    break;

  case 31: /* ifstmt: IF cond THEN st ELSE st ENDIF SEMI  */
#line 311 "cmm.y"
          {
	    cptr *tmp;
	    int label0, label1;

	    label0 = makelabel();
	    label1 = makelabel();

	    tmp = mergecode(yyvsp[-6].code, makecode(O_JPC, 0, label0));
	    tmp = mergecode(tmp, yyvsp[-4].code);
	    tmp = mergecode(tmp, makecode(O_JMP, 0, label1));
	    tmp = mergecode(tmp, makecode(O_LAB, 0, label0));
	    tmp = mergecode(tmp, yyvsp[-2].code);

	    yyval.code = mergecode(tmp, makecode(O_LAB, 0, label1));
	    yyval.val = 0;
	  }
#line 1668 "y.tab.c"
    break;

  case 32: /* whilestmt: WHILE cond DO st  */
#line 330 "cmm.y"
          {
	    int label0, label1;
	    cptr *tmp;

	    label0 = makelabel();
	    label1 = makelabel();

	    tmp = makecode(O_LAB, 0, label0);
	    tmp = mergecode(tmp, yyvsp[-2].code);
	    tmp = mergecode(tmp, makecode(O_JPC, 0, label1));
	    tmp = mergecode(tmp, yyvsp[0].code);
	    tmp = mergecode(tmp, makecode(O_JMP, 0, label0));
	    tmp = mergecode(tmp, makecode(O_LAB, 0, label1));

	    yyval.code = tmp; 
			
	    yyval.val = 0;
	  }
#line 1691 "y.tab.c"
    break;

  case 33: /* cond: E GT E  */
#line 351 "cmm.y"
          {
	    yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 12));
	  }
#line 1700 "y.tab.c"
    break;

  case 34: /* cond: E GE E  */
#line 356 "cmm.y"
          {
	    yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 11));
	  }
#line 1709 "y.tab.c"
    break;

  case 35: /* cond: E LT E  */
#line 361 "cmm.y"
          {
	    yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 10));
	  }
#line 1718 "y.tab.c"
    break;

  case 36: /* cond: E LE E  */
#line 366 "cmm.y"
          {
	    yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 13));
	  }
#line 1727 "y.tab.c"
    break;

  case 37: /* cond: E NE E  */
#line 371 "cmm.y"
          {
	    yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 9));
	  }
#line 1736 "y.tab.c"
    break;

  case 38: /* cond: E EQ E  */
#line 376 "cmm.y"
          {
	    yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 8));
	  }
#line 1745 "y.tab.c"
    break;

  case 39: /* E: E PLUS T  */
#line 383 "cmm.y"
          {
            yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 2));
          }
#line 1754 "y.tab.c"
    break;

  case 40: /* E: E MINUS T  */
#line 388 "cmm.y"
          {
            yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 3));
          }
#line 1763 "y.tab.c"
    break;

  case 41: /* E: T  */
#line 393 "cmm.y"
          {
            yyval.code = yyvsp[0].code;
          }
#line 1771 "y.tab.c"
    break;

  case 42: /* T: T MULT F  */
#line 399 "cmm.y"
          {
            yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 4));
          }
#line 1780 "y.tab.c"
    break;

  case 43: /* T: T DIV F  */
#line 404 "cmm.y"
          {
            yyval.code = mergecode(mergecode(yyvsp[-2].code, yyvsp[0].code),
				makecode(O_OPR, 0, 5));
          }
#line 1789 "y.tab.c"
    break;

  case 44: /* T: F  */
#line 409 "cmm.y"
          {
            yyval.code = yyvsp[0].code;
          }
#line 1797 "y.tab.c"
    break;

  case 45: /* F: ID  */
#line 415 "cmm.y"
          {
	    cptr *tmpc;
	    list* tmpl;

	    tmpl = search_all(yyvsp[0].name);
	    if (tmpl == NULL){
	      sem_error2("id");
	    }

	    if (tmpl->kind == VARIABLE){
	      yyval.code = makecode(O_LOD, level - tmpl->l, tmpl->a);
	    }
	    else {
	      sem_error2("id as variable");
	    }
	  }
#line 1818 "y.tab.c"
    break;

  case 46: /* F: ID LPAR fparams RPAR  */
#line 432 "cmm.y"
          {
	    list* tmpl;

	    tmpl = search_all(yyvsp[-3].name);
	    if (tmpl == NULL){
	      sem_error2("id as function");
	    }

	    if (tmpl->kind != FUNC){
	      sem_error2("id as function2");
	    }

	    if (tmpl->params != yyvsp[-1].val){
	      sem_error3(tmpl->name, tmpl->params, yyvsp[-1].val);
	    }

	    yyval.code = mergecode(yyvsp[-1].code,
				makecode(O_CAL,
					 level - tmpl->l,
					 tmpl->a));
	  }
#line 1844 "y.tab.c"
    break;

  case 47: /* F: NUMBER  */
#line 454 "cmm.y"
          {
	    yyval.code = makecode(O_LIT, 0, yylval.val);
	  }
#line 1852 "y.tab.c"
    break;

  case 48: /* F: LPAR E RPAR  */
#line 458 "cmm.y"
          {
	    yyval.code = yyvsp[-1].code;
	  }
#line 1860 "y.tab.c"
    break;

  case 49: /* fparams: %empty  */
#line 464 "cmm.y"
          {
	    yyval.val = 0;
	    yyval.code = NULL;
	  }
#line 1869 "y.tab.c"
    break;

  case 50: /* fparams: ac_params  */
#line 469 "cmm.y"
          {
	    yyval.val = yyvsp[0].val;
	    yyval.code = yyvsp[0].code;
	  }
#line 1878 "y.tab.c"
    break;

  case 51: /* ac_params: ac_params COMMA fparam  */
#line 476 "cmm.y"
          {
	    yyval.val = yyvsp[-2].val + 1;
	    yyval.code = mergecode(yyvsp[-2].code, yyvsp[0].code);
	  }
#line 1887 "y.tab.c"
    break;

  case 52: /* ac_params: fparam  */
#line 481 "cmm.y"
          {
	    yyval.val = 1;
	    yyval.code = yyvsp[0].code;
	  }
#line 1896 "y.tab.c"
    break;

  case 53: /* fparam: E  */
#line 488 "cmm.y"
          {
	    yyval.code = yyvsp[0].code;
	  }
#line 1904 "y.tab.c"
    break;


#line 1908 "y.tab.c"

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

#line 492 "cmm.y"


#include "lex.yy.c"

int main(void){
  ofile = fopen("code.output", "w");

  if (ofile == NULL){
    perror("ofile");
    exit(EXIT_FAILURE);
  }

  initialize();
  yyparse();

  if (fclose(ofile) != 0){
    perror("ofile");
    exit(EXIT_FAILURE);
  }
  return 0;
}

int yywrap(void)
{
	return 1;
}

int yyerror(char const *str)
{
	extern char *yytext;
	fprintf(stderr, "parser error near %s\n", yytext);
	return 0;
}


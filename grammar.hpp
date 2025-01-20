/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_HPP_INCLUDED
# define YY_YY_GRAMMAR_HPP_INCLUDED
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
    EQ = 258,                      /* EQ  */
    NEQ = 259,                     /* NEQ  */
    GEQ = 260,                     /* GEQ  */
    LEQ = 261,                     /* LEQ  */
    GT = 262,                      /* GT  */
    LT = 263,                      /* LT  */
    SET = 264,                     /* SET  */
    PROCEDURE = 265,               /* PROCEDURE  */
    IS = 266,                      /* IS  */
    T_BEGIN = 267,                 /* T_BEGIN  */
    T_END = 268,                   /* T_END  */
    PROGRAM = 269,                 /* PROGRAM  */
    IF = 270,                      /* IF  */
    THEN = 271,                    /* THEN  */
    ELSE = 272,                    /* ELSE  */
    ENDIF = 273,                   /* ENDIF  */
    WHILE = 274,                   /* WHILE  */
    DO = 275,                      /* DO  */
    ENDWHILE = 276,                /* ENDWHILE  */
    REPEAT = 277,                  /* REPEAT  */
    UNTIL = 278,                   /* UNTIL  */
    FOR = 279,                     /* FOR  */
    FROM = 280,                    /* FROM  */
    TO = 281,                      /* TO  */
    ENDFOR = 282,                  /* ENDFOR  */
    DOWNTO = 283,                  /* DOWNTO  */
    T = 284,                       /* T  */
    READ = 285,                    /* READ  */
    WRITE = 286,                   /* WRITE  */
    COMMA = 287,                   /* COMMA  */
    SEMICOLON = 288,               /* SEMICOLON  */
    SLB = 289,                     /* SLB  */
    SRB = 290,                     /* SRB  */
    LB = 291,                      /* LB  */
    RB = 292,                      /* RB  */
    COLON = 293,                   /* COLON  */
    pidentifier = 294,             /* pidentifier  */
    NUMBER = 295,                  /* NUMBER  */
    ADD = 296,                     /* ADD  */
    SUB = 297,                     /* SUB  */
    MUL = 298,                     /* MUL  */
    DIV = 299,                     /* DIV  */
    MOD = 300                      /* MOD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "grammar.y"

	char* stringid;
    long long number;
	struct Component* component;

#line 115 "grammar.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GRAMMAR_HPP_INCLUDED  */

/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    STRCONST = 258,
    INTCONST = 259,
    FLTCONST = 260,
    CHARCONST = 261,
    AUTO = 262,
    BREAK = 263,
    CASE = 264,
    CHAR = 265,
    CONST = 266,
    CONTINUE = 267,
    DEFAULT = 268,
    DO = 269,
    DOUBLE = 270,
    ELSE = 271,
    ENUM = 272,
    EXTERN = 273,
    FLOAT = 274,
    FOR = 275,
    IF = 276,
    INT = 277,
    LONG = 278,
    REGISTER = 279,
    RETURN = 280,
    SHORT = 281,
    SIGNED = 282,
    SIZEOF = 283,
    STATIC = 284,
    STRUCT = 285,
    SWITCH = 286,
    TYPEDEF = 287,
    UNION = 288,
    UNSIGNED = 289,
    VOID = 290,
    VOLATILE = 291,
    WHILE = 292,
    IDENTIFIER = 293,
    INCREMENT = 294,
    DECREMENT = 295,
    AND = 296,
    OR = 297,
    EQUAL = 298,
    GREATER = 299,
    LESSER = 300,
    NOTEQUAL = 301
  };
#endif
/* Tokens.  */
#define STRCONST 258
#define INTCONST 259
#define FLTCONST 260
#define CHARCONST 261
#define AUTO 262
#define BREAK 263
#define CASE 264
#define CHAR 265
#define CONST 266
#define CONTINUE 267
#define DEFAULT 268
#define DO 269
#define DOUBLE 270
#define ELSE 271
#define ENUM 272
#define EXTERN 273
#define FLOAT 274
#define FOR 275
#define IF 276
#define INT 277
#define LONG 278
#define REGISTER 279
#define RETURN 280
#define SHORT 281
#define SIGNED 282
#define SIZEOF 283
#define STATIC 284
#define STRUCT 285
#define SWITCH 286
#define TYPEDEF 287
#define UNION 288
#define UNSIGNED 289
#define VOID 290
#define VOLATILE 291
#define WHILE 292
#define IDENTIFIER 293
#define INCREMENT 294
#define DECREMENT 295
#define AND 296
#define OR 297
#define EQUAL 298
#define GREATER 299
#define LESSER 300
#define NOTEQUAL 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

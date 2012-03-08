
/*  A Bison parser, made from mdl.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	COMMENT	257
#define	DOUBLE	258
#define	LIGHT	259
#define	AMBIENT	260
#define	CONSTANTS	261
#define	SAVE_COORDS	262
#define	CAMERA	263
#define	SPHERE	264
#define	TORUS	265
#define	BOX	266
#define	LINE	267
#define	CS	268
#define	MESH	269
#define	TEXTURE	270
#define	STRING	271
#define	SET	272
#define	MOVE	273
#define	SCALE	274
#define	ROTATE	275
#define	BASENAME	276
#define	SAVE_KNOBS	277
#define	TWEEN	278
#define	FRAMES	279
#define	VARY	280
#define	PUSH	281
#define	POP	282
#define	SAVE	283
#define	GENERATE_RAYFILES	284
#define	SHADING	285
#define	SHADING_TYPE	286
#define	SETKNOBS	287
#define	FOCAL	288
#define	DISPLAY	289
#define	WEB	290
#define	CO	291

#line 1 "mdl.y"

  /* C declarations */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "matrix.h"

  SYMTAB *s;
  struct light *l;
  struct constants *c;
  struct command op[MAX_COMMANDS];
  struct matrix *m;
  int lastop=0;
  int lineno=0;
#define YYERROR_VERBOSE 1

  
#line 23 "mdl.y"
typedef union{
  double val;
  char string[255];

} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		176
#define	YYFLAG		-32768
#define	YYNTBASE	38

#define YYTRANSLATE(x) ((unsigned)(x) <= 291 ? yytranslate[x] : 40)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     6,    15,    21,    26,    38,    53,    56,
    64,    79,    85,    92,    99,   107,   114,   122,   130,   139,
   147,   156,   165,   175,   183,   192,   201,   211,   220,   230,
   240,   251,   255,   260,   266,   270,   276,   281,   286,   290,
   293,   296,   302,   305,   312,   314,   316,   318,   321,   324,
   327,   330,   332,   334
};

static const short yyrhs[] = {    -1,
    38,    39,     0,     3,     0,     5,    17,     4,     4,     4,
     4,     4,     4,     0,    19,     4,     4,     4,    17,     0,
    19,     4,     4,     4,     0,     7,    17,     4,     4,     4,
     4,     4,     4,     4,     4,     4,     0,     7,    17,     4,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     0,     8,    17,     0,     9,     4,     4,     4,     4,
     4,     4,     0,    16,    17,     4,     4,     4,     4,     4,
     4,     4,     4,     4,     4,     4,     4,     0,    10,     4,
     4,     4,     4,     0,    10,     4,     4,     4,     4,    17,
     0,    10,    17,     4,     4,     4,     4,     0,    10,    17,
     4,     4,     4,     4,    17,     0,    11,     4,     4,     4,
     4,     4,     0,    11,     4,     4,     4,     4,     4,    17,
     0,    11,    17,     4,     4,     4,     4,     4,     0,    11,
    17,     4,     4,     4,     4,     4,    17,     0,    12,     4,
     4,     4,     4,     4,     4,     0,    12,     4,     4,     4,
     4,     4,     4,    17,     0,    12,    17,     4,     4,     4,
     4,     4,     4,     0,    12,    17,     4,     4,     4,     4,
     4,     4,    17,     0,    13,     4,     4,     4,     4,     4,
     4,     0,    13,     4,     4,     4,    17,     4,     4,     4,
     0,    13,     4,     4,     4,     4,     4,     4,    17,     0,
    13,     4,     4,     4,    17,     4,     4,     4,    17,     0,
    13,    17,     4,     4,     4,     4,     4,     4,     0,    13,
    17,     4,     4,     4,    17,     4,     4,     4,     0,    13,
    17,     4,     4,     4,     4,     4,     4,    17,     0,    13,
    17,     4,     4,     4,    17,     4,     4,     4,    17,     0,
    15,    37,    17,     0,    15,    17,    37,    17,     0,    15,
    17,    37,    17,    17,     0,    18,    17,     4,     0,    20,
     4,     4,     4,    17,     0,    20,     4,     4,     4,     0,
    21,    17,     4,    17,     0,    21,    17,     4,     0,    22,
    17,     0,    23,    17,     0,    24,     4,     4,    17,    17,
     0,    25,     4,     0,    26,    17,     4,     4,     4,     4,
     0,    27,     0,    30,     0,    28,     0,    29,    17,     0,
    31,    32,     0,    33,     4,     0,    34,     4,     0,    35,
     0,    36,     0,     6,     4,     4,     4,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    42,    43,    46,    47,    67,    80,    91,   119,   146,   155,
   170,   192,   205,   219,   233,   249,   265,   280,   296,   313,
   330,   348,   365,   384,   403,   422,   440,   459,   478,   497,
   517,   537,   546,   556,   567,   576,   587,   598,   623,   646,
   653,   660,   670,   677,   688,   694,   700,   706,   713,   720,
   727,   734,   740,   746
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","COMMENT",
"DOUBLE","LIGHT","AMBIENT","CONSTANTS","SAVE_COORDS","CAMERA","SPHERE","TORUS",
"BOX","LINE","CS","MESH","TEXTURE","STRING","SET","MOVE","SCALE","ROTATE","BASENAME",
"SAVE_KNOBS","TWEEN","FRAMES","VARY","PUSH","POP","SAVE","GENERATE_RAYFILES",
"SHADING","SHADING_TYPE","SETKNOBS","FOCAL","DISPLAY","WEB","CO","input","command", NULL
};
#endif

static const short yyr1[] = {     0,
    38,    38,    39,    39,    39,    39,    39,    39,    39,    39,
    39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
    39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
    39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
    39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
    39,    39,    39,    39
};

static const short yyr2[] = {     0,
     0,     2,     1,     8,     5,     4,    11,    14,     2,     7,
    14,     5,     6,     6,     7,     6,     7,     7,     8,     7,
     8,     8,     9,     7,     8,     8,     9,     8,     9,     9,
    10,     3,     4,     5,     3,     5,     4,     4,     3,     2,
     2,     5,     2,     6,     1,     1,     1,     2,     2,     2,
     2,     1,     1,     4
};

static const short yydefact[] = {     1,
     0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    45,    47,     0,    46,     0,     0,     0,    52,
    53,     2,     0,     0,     0,     9,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,    40,    41,     0,    43,     0,    48,    49,    50,
    51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    32,     0,    35,     0,     0,    39,
     0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,    33,     0,     6,    37,    38,     0,
     0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
     0,     0,     0,    34,     0,     5,    36,    42,     0,     0,
     0,     0,    13,    14,    16,     0,     0,     0,     0,     0,
     0,     0,     0,    44,     0,     0,    10,    15,    17,    18,
    20,     0,    24,     0,     0,     0,     0,     4,     0,    19,
    21,    22,    26,    25,    28,     0,     0,     0,    23,    27,
    30,    29,     0,     0,    31,     0,     7,     0,     0,     0,
     0,     0,     8,    11,     0,     0
};

static const short yydefgoto[] = {     1,
    32
};

static const short yypact[] = {-32768,
     0,-32768,   -15,    13,   -13,    22,    39,    -3,    33,    34,
    36,    15,    27,    28,    42,    43,    31,    32,    40,    52,
    54,    44,-32768,-32768,    45,-32768,    35,    55,    56,-32768,
-32768,-32768,    59,    60,    61,-32768,    62,    64,    65,    66,
    67,    68,    69,    70,    71,    41,    63,    72,    73,    75,
    77,    78,-32768,-32768,    79,-32768,    80,-32768,-32768,-32768,
-32768,    81,    82,    83,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,-32768,    94,-32768,    95,    96,    97,
    98,    99,   100,-32768,   101,   102,   103,   104,   105,   107,
   108,   109,    37,   112,   106,   113,   110,   111,-32768,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   125,   126,
   128,   129,    38,-32768,   130,-32768,-32768,-32768,   131,   133,
   134,   135,-32768,   123,   124,   138,   139,   140,   141,   142,
   143,   144,   145,-32768,   146,   147,-32768,-32768,-32768,   136,
   137,   148,   149,   151,   152,   153,   154,-32768,   155,-32768,
-32768,   150,-32768,   156,   157,   158,   159,   160,-32768,-32768,
-32768,   161,   164,   165,-32768,   166,   167,   168,   171,   172,
   173,   175,-32768,-32768,   180,-32768
};

static const short yypgoto[] = {-32768,
-32768
};


#define	YYLAST		180


static const short yytable[] = {   175,
    38,    33,     2,    35,     3,     4,     5,     6,     7,     8,
     9,    10,    11,    39,    12,    13,    34,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    46,    28,    29,    30,    31,    40,    42,    36,    44,
   111,   131,    37,    48,    49,    50,    51,    52,    53,    41,
    43,    47,    45,   112,   132,    55,    54,    56,    60,    61,
    57,    58,    62,    63,    64,    65,    59,    66,    67,    68,
    69,    70,    71,    72,    73,    76,    77,    74,    78,    75,
    79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
    89,    90,    91,    92,    93,    94,     0,    96,    97,    98,
     0,     0,   101,   102,   103,   104,   105,   106,   107,    95,
   108,   109,   110,    99,   100,   113,   115,     0,   119,   120,
   121,   122,   114,   124,   125,   126,   116,   117,   127,   128,
   118,   129,   130,   133,   134,   123,   135,   136,   137,   138,
   139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
   149,   152,   150,   151,   154,   155,   156,   157,   158,     0,
     0,   162,   163,   164,     0,   153,   159,   166,   167,   168,
   169,   170,   160,   161,   171,   172,   173,   165,   174,   176
};

static const short yycheck[] = {     0,
     4,    17,     3,    17,     5,     6,     7,     8,     9,    10,
    11,    12,    13,    17,    15,    16,     4,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    17,    33,    34,    35,    36,     4,     4,    17,     4,
     4,     4,     4,    17,    17,     4,     4,    17,    17,    17,
    17,    37,    17,    17,    17,     4,    17,     4,     4,     4,
    17,    17,     4,     4,     4,     4,    32,     4,     4,     4,
     4,     4,     4,     4,     4,     4,     4,    37,     4,    17,
     4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     4,     4,     4,     4,     4,    -1,     4,     4,     4,
    -1,    -1,     4,     4,     4,     4,     4,     4,     4,    17,
     4,     4,     4,    17,    17,     4,     4,    -1,     4,     4,
     4,     4,    17,     4,     4,     4,    17,    17,     4,     4,
    17,     4,     4,     4,     4,    17,     4,     4,     4,    17,
    17,     4,     4,     4,     4,     4,     4,     4,     4,     4,
     4,     4,    17,    17,     4,     4,     4,     4,     4,    -1,
    -1,     4,     4,     4,    -1,    17,    17,     4,     4,     4,
     4,     4,    17,    17,     4,     4,     4,    17,     4,     0
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
#line 47 "mdl.y"
{;
    break;}
case 4:
#line 50 "mdl.y"
{
  lineno++;
  l = (struct light *)malloc(sizeof(struct light));
  l->l[0]= yyvsp[-5].val;
  l->l[1]= yyvsp[-4].val;
  l->l[2]= yyvsp[-3].val;
  l->l[3]= 0;
  l->c[0]= yyvsp[-2].val;
  l->c[1]= yyvsp[-1].val;
  l->c[2]= yyvsp[0].val;
  op[lastop].opcode=LIGHT;
  op[lastop].op.light.c[0] = yyvsp[-2].val; 
  op[lastop].op.light.c[1] = yyvsp[-1].val;
  op[lastop].op.light.c[2] = yyvsp[0].val;
  op[lastop].op.light.c[3] = 0;
  op[lastop].op.light.p = add_symbol(yyvsp[-6].string,SYM_LIGHT,l);
  lastop++;
;
    break;}
case 5:
#line 70 "mdl.y"
{ 
  lineno++;
  op[lastop].opcode = MOVE;
  op[lastop].op.move.d[0] = yyvsp[-3].val;
  op[lastop].op.move.d[1] = yyvsp[-2].val;
  op[lastop].op.move.d[2] = yyvsp[-1].val;
  op[lastop].op.move.d[3] = 0;
  op[lastop].op.move.p = add_symbol(yyvsp[0].string,SYM_VALUE,0);
  lastop++;
;
    break;}
case 6:
#line 82 "mdl.y"
{
  lineno++;
  op[lastop].opcode = MOVE;
  op[lastop].op.move.d[0] = yyvsp[-2].val;
  op[lastop].op.move.d[1] = yyvsp[-1].val;
  op[lastop].op.move.d[2] = yyvsp[0].val;
  op[lastop].op.move.d[3] = 0;
  op[lastop].op.move.p = NULL;
  lastop++;
;
    break;}
case 7:
#line 94 "mdl.y"
{
  lineno++;
  c = (struct constants *)malloc(sizeof(struct constants));
  c->r[0]=yyvsp[-8].val;
  c->r[1]=yyvsp[-7].val;
  c->r[2]=yyvsp[-6].val;
  c->r[3]=0;

  c->g[0]=yyvsp[-5].val;
  c->g[1]=yyvsp[-4].val;
  c->g[2]=yyvsp[-3].val;
  c->g[3]=0;

  c->b[0]=yyvsp[-2].val;
  c->b[1]=yyvsp[-1].val;
  c->b[2]=yyvsp[0].val;
  c->b[3]=0;

  c->red = 0;
  c->green = 0;
  c->blue = 0;

  op[lastop].op.constants.p =  add_symbol(yyvsp[-9].string,SYM_CONSTANTS,c);
  op[lastop].opcode=CONSTANTS;
  lastop++;
;
    break;}
case 8:
#line 122 "mdl.y"
{
  lineno++;
  c = (struct constants *)malloc(sizeof(struct constants));
  c->r[0]=yyvsp[-11].val;
  c->r[1]=yyvsp[-10].val;
  c->r[2]=yyvsp[-9].val;
  c->r[3]=0;

  c->g[0]=yyvsp[-8].val;
  c->g[1]=yyvsp[-7].val;
  c->g[2]=yyvsp[-6].val;
  c->g[3]=0;

  c->b[0]=yyvsp[-5].val;
  c->b[1]=yyvsp[-4].val;
  c->b[2]=yyvsp[-3].val;
  c->b[3]=0;

  c->red = yyvsp[-2].val;
  c->green = yyvsp[-1].val;
  c->blue = yyvsp[0].val;
  op[lastop].op.constants.p =  add_symbol(yyvsp[-12].string,SYM_CONSTANTS,c);
  op[lastop].opcode=CONSTANTS;
  lastop++;
;
    break;}
case 9:
#line 149 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SAVE_COORDS;
  m = new_matrix(4,4);
  op[lastop].op.save_coordinate_system.p = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 10:
#line 158 "mdl.y"
{
  lineno++;
  op[lastop].opcode = CAMERA;
  op[lastop].op.camera.eye[0] = yyvsp[-5].val;
  op[lastop].op.camera.eye[1] = yyvsp[-4].val;
  op[lastop].op.camera.eye[2] = yyvsp[-3].val;
  op[lastop].op.camera.eye[3] = 0;
  op[lastop].op.camera.aim[0] = yyvsp[-2].val;
  op[lastop].op.camera.aim[1] = yyvsp[-1].val;
  op[lastop].op.camera.aim[2] = yyvsp[0].val;
  op[lastop].op.camera.aim[3] = 0;
  lastop++;
;
    break;}
case 11:
#line 172 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TEXTURE;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.texture.d0[0] = yyvsp[-11].val;
  op[lastop].op.texture.d0[1] = yyvsp[-10].val;
  op[lastop].op.texture.d0[2] = yyvsp[-9].val;
  op[lastop].op.texture.d1[0] = yyvsp[-8].val;
  op[lastop].op.texture.d1[1] = yyvsp[-7].val;
  op[lastop].op.texture.d1[2] = yyvsp[-6].val;
  op[lastop].op.texture.d2[0] = yyvsp[-5].val;
  op[lastop].op.texture.d2[1] = yyvsp[-4].val;
  op[lastop].op.texture.d2[2] = yyvsp[-3].val;
  op[lastop].op.texture.d3[0] = yyvsp[-2].val;
  op[lastop].op.texture.d3[1] = yyvsp[-1].val;
  op[lastop].op.texture.d3[2] = yyvsp[0].val;
  op[lastop].op.texture.cs = NULL;
  op[lastop].op.texture.constants =  add_symbol("",SYM_CONSTANTS,c);
  op[lastop].op.texture.p = add_symbol(yyvsp[-12].string,SYM_FILE,0);
  lastop++;
;
    break;}
case 12:
#line 194 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = yyvsp[-3].val;
  op[lastop].op.sphere.d[1] = yyvsp[-2].val;
  op[lastop].op.sphere.d[2] = yyvsp[-1].val;
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = yyvsp[0].val;
  op[lastop].op.sphere.constants = NULL;
  op[lastop].op.sphere.cs = NULL;
  lastop++;
;
    break;}
case 13:
#line 207 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = yyvsp[-4].val;
  op[lastop].op.sphere.d[1] = yyvsp[-3].val;
  op[lastop].op.sphere.d[2] = yyvsp[-2].val;
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = yyvsp[-1].val;
  op[lastop].op.sphere.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.sphere.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 14:
#line 221 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = yyvsp[-3].val;
  op[lastop].op.sphere.d[1] = yyvsp[-2].val;
  op[lastop].op.sphere.d[2] = yyvsp[-1].val;
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = yyvsp[0].val;
  op[lastop].op.sphere.cs = NULL;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.sphere.constants = add_symbol(yyvsp[-4].string,SYM_CONSTANTS,c);
  lastop++;
;
    break;}
case 15:
#line 235 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SPHERE;
  op[lastop].op.sphere.d[0] = yyvsp[-4].val;
  op[lastop].op.sphere.d[1] = yyvsp[-3].val;
  op[lastop].op.sphere.d[2] = yyvsp[-2].val;
  op[lastop].op.sphere.d[3] = 0;
  op[lastop].op.sphere.r = yyvsp[-1].val;
  op[lastop].op.sphere.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.sphere.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.sphere.constants = add_symbol(yyvsp[-5].string,SYM_CONSTANTS,c);
  lastop++;
;
    break;}
case 16:
#line 252 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = yyvsp[-4].val;
  op[lastop].op.torus.d[1] = yyvsp[-3].val;
  op[lastop].op.torus.d[2] = yyvsp[-2].val;
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = yyvsp[-1].val;
  op[lastop].op.torus.r1 = yyvsp[0].val;
  op[lastop].op.torus.constants = NULL;
  op[lastop].op.torus.cs = NULL;

  lastop++;
;
    break;}
case 17:
#line 267 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = yyvsp[-5].val;
  op[lastop].op.torus.d[1] = yyvsp[-4].val;
  op[lastop].op.torus.d[2] = yyvsp[-3].val;
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = yyvsp[-2].val;
  op[lastop].op.torus.r1 = yyvsp[-1].val;
  op[lastop].op.torus.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.torus.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 18:
#line 282 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = yyvsp[-4].val;
  op[lastop].op.torus.d[1] = yyvsp[-3].val;
  op[lastop].op.torus.d[2] = yyvsp[-2].val;
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = yyvsp[-1].val;
  op[lastop].op.torus.r1 = yyvsp[0].val;
  op[lastop].op.torus.cs = NULL;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.torus.constants = add_symbol(yyvsp[-5].string,SYM_CONSTANTS,c);

  lastop++;
;
    break;}
case 19:
#line 298 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TORUS;
  op[lastop].op.torus.d[0] = yyvsp[-5].val;
  op[lastop].op.torus.d[1] = yyvsp[-4].val;
  op[lastop].op.torus.d[2] = yyvsp[-3].val;
  op[lastop].op.torus.d[3] = 0;
  op[lastop].op.torus.r0 = yyvsp[-2].val;
  op[lastop].op.torus.r1 = yyvsp[-1].val;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.torus.constants = add_symbol(yyvsp[-6].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.torus.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);

  lastop++;
;
    break;}
case 20:
#line 315 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = yyvsp[-5].val;
  op[lastop].op.box.d0[1] = yyvsp[-4].val;
  op[lastop].op.box.d0[2] = yyvsp[-3].val;
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = yyvsp[-2].val;
  op[lastop].op.box.d1[1] = yyvsp[-1].val;
  op[lastop].op.box.d1[2] = yyvsp[0].val;
  op[lastop].op.box.d1[3] = 0;

  op[lastop].op.box.constants = NULL;
  op[lastop].op.box.cs = NULL;
  lastop++;
;
    break;}
case 21:
#line 332 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = yyvsp[-6].val;
  op[lastop].op.box.d0[1] = yyvsp[-5].val;
  op[lastop].op.box.d0[2] = yyvsp[-4].val;
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = yyvsp[-3].val;
  op[lastop].op.box.d1[1] = yyvsp[-2].val;
  op[lastop].op.box.d1[2] = yyvsp[-1].val;
  op[lastop].op.box.d1[3] = 0;

  op[lastop].op.box.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.box.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 22:
#line 350 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = yyvsp[-5].val;
  op[lastop].op.box.d0[1] = yyvsp[-4].val;
  op[lastop].op.box.d0[2] = yyvsp[-3].val;
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = yyvsp[-2].val;
  op[lastop].op.box.d1[1] = yyvsp[-1].val;
  op[lastop].op.box.d1[2] = yyvsp[0].val;
  op[lastop].op.box.d1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.box.constants = add_symbol(yyvsp[-6].string,SYM_CONSTANTS,c);
  op[lastop].op.box.cs = NULL;
  lastop++;
;
    break;}
case 23:
#line 367 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BOX;
  op[lastop].op.box.d0[0] = yyvsp[-6].val;
  op[lastop].op.box.d0[1] = yyvsp[-5].val;
  op[lastop].op.box.d0[2] = yyvsp[-4].val;
  op[lastop].op.box.d0[3] = 0;
  op[lastop].op.box.d1[0] = yyvsp[-3].val;
  op[lastop].op.box.d1[1] = yyvsp[-2].val;
  op[lastop].op.box.d1[2] = yyvsp[-1].val;
  op[lastop].op.box.d1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.box.constants = add_symbol(yyvsp[-7].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.box.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);

  lastop++;
;
    break;}
case 24:
#line 388 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-5].val;
  op[lastop].op.line.p0[1] = yyvsp[-4].val;
  op[lastop].op.line.p0[2] = yyvsp[-3].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-2].val;
  op[lastop].op.line.p1[1] = yyvsp[-1].val;
  op[lastop].op.line.p1[2] = yyvsp[0].val;
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  op[lastop].op.line.cs0 = NULL;
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 25:
#line 406 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-6].val;
  op[lastop].op.line.p0[1] = yyvsp[-5].val;
  op[lastop].op.line.p0[2] = yyvsp[-4].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-2].val;
  op[lastop].op.line.p1[1] = yyvsp[-1].val;
  op[lastop].op.line.p1[2] = yyvsp[0].val;
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol(yyvsp[-3].string,SYM_MATRIX,m);
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 26:
#line 424 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-6].val;
  op[lastop].op.line.p0[1] = yyvsp[-5].val;
  op[lastop].op.line.p0[2] = yyvsp[-4].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-3].val;
  op[lastop].op.line.p1[1] = yyvsp[-2].val;
  op[lastop].op.line.p1[2] = yyvsp[-1].val;
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  op[lastop].op.line.cs0 = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 27:
#line 442 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-7].val;
  op[lastop].op.line.p0[1] = yyvsp[-6].val;
  op[lastop].op.line.p0[2] = yyvsp[-5].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-3].val;
  op[lastop].op.line.p1[1] = yyvsp[-2].val;
  op[lastop].op.line.p1[2] = yyvsp[-1].val;
  op[lastop].op.line.p1[3] = 0;
  op[lastop].op.line.constants = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol(yyvsp[-4].string,SYM_MATRIX,m);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 28:
#line 462 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-5].val;
  op[lastop].op.line.p0[1] = yyvsp[-4].val;
  op[lastop].op.line.p0[2] = yyvsp[-3].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-2].val;
  op[lastop].op.line.p1[1] = yyvsp[-1].val;
  op[lastop].op.line.p1[2] = yyvsp[0].val;
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol(yyvsp[-6].string,SYM_CONSTANTS,c);
  op[lastop].op.line.cs0 = NULL;
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 29:
#line 480 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-6].val;
  op[lastop].op.line.p0[1] = yyvsp[-5].val;
  op[lastop].op.line.p0[2] = yyvsp[-4].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-2].val;
  op[lastop].op.line.p1[1] = yyvsp[-1].val;
  op[lastop].op.line.p1[2] = yyvsp[0].val;
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol(yyvsp[-7].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol(yyvsp[-3].string,SYM_MATRIX,m);
  op[lastop].op.line.cs1 = NULL;
  lastop++;
;
    break;}
case 30:
#line 499 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-6].val;
  op[lastop].op.line.p0[1] = yyvsp[-5].val;
  op[lastop].op.line.p0[2] = yyvsp[-4].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-3].val;
  op[lastop].op.line.p1[1] = yyvsp[-2].val;
  op[lastop].op.line.p1[2] = yyvsp[-1].val;
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol(yyvsp[-7].string,SYM_CONSTANTS,c);
  op[lastop].op.line.cs0 = NULL;
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  op[lastop].op.line.cs0 = NULL;
  lastop++;
;
    break;}
case 31:
#line 519 "mdl.y"
{
  lineno++;
  op[lastop].opcode = LINE;
  op[lastop].op.line.p0[0] = yyvsp[-7].val;
  op[lastop].op.line.p0[1] = yyvsp[-6].val;
  op[lastop].op.line.p0[2] = yyvsp[-5].val;
  op[lastop].op.line.p0[3] = 0;
  op[lastop].op.line.p1[0] = yyvsp[-3].val;
  op[lastop].op.line.p1[1] = yyvsp[-2].val;
  op[lastop].op.line.p1[2] = yyvsp[-1].val;
  op[lastop].op.line.p1[3] = 0;
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.line.constants = add_symbol(yyvsp[-8].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs0 = add_symbol(yyvsp[-4].string,SYM_MATRIX,m);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.line.cs1 = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 32:
#line 539 "mdl.y"
{
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,yyvsp[0].string);
  op[lastop].op.mesh.constants = NULL;
  op[lastop].op.mesh.cs = NULL;
  lastop++;
;
    break;}
case 33:
#line 548 "mdl.y"
{ /* name and constants */
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,yyvsp[0].string);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.mesh.constants = add_symbol(yyvsp[-2].string,SYM_CONSTANTS,c);
  op[lastop].op.mesh.cs = NULL;
  lastop++;
;
    break;}
case 34:
#line 558 "mdl.y"
{
  lineno++;
  op[lastop].opcode = MESH;
  strcpy(op[lastop].op.mesh.name,yyvsp[-1].string);
  c = (struct constants *)malloc(sizeof(struct constants));
  op[lastop].op.mesh.constants = add_symbol(yyvsp[-3].string,SYM_CONSTANTS,c);
  m = (struct matrix *)new_matrix(4,4);
  op[lastop].op.mesh.cs = add_symbol(yyvsp[0].string,SYM_MATRIX,m);
  lastop++;
;
    break;}
case 35:
#line 569 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SET;
  op[lastop].op.set.p = add_symbol(yyvsp[-1].string,SYM_VALUE,0);
  set_value(op[lastop].op.set.p,yyvsp[0].val);
  op[lastop].op.set.val = yyvsp[0].val;
  lastop++;
;
    break;}
case 36:
#line 578 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SCALE;
  op[lastop].op.scale.d[0] = yyvsp[-3].val;
  op[lastop].op.scale.d[1] = yyvsp[-2].val;
  op[lastop].op.scale.d[2] = yyvsp[-1].val;
  op[lastop].op.scale.d[3] = 0;
  op[lastop].op.scale.p = add_symbol(yyvsp[0].string,SYM_VALUE,0);
  lastop++;
;
    break;}
case 37:
#line 589 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SCALE;
  op[lastop].op.scale.d[0] = yyvsp[-2].val;
  op[lastop].op.scale.d[1] = yyvsp[-1].val;
  op[lastop].op.scale.d[2] = yyvsp[0].val;
  op[lastop].op.scale.d[3] = 0;
  op[lastop].op.scale.p = NULL;
  lastop++;
;
    break;}
case 38:
#line 600 "mdl.y"
{
  lineno++;
  op[lastop].opcode = ROTATE;
  switch (*yyvsp[-2].string)
    {
    case 'x':
    case 'X': 
      op[lastop].op.rotate.axis = 0;
      break;
    case 'y':
    case 'Y': 
      op[lastop].op.rotate.axis = 1;
      break;
    case 'z':
    case 'Z': 
      op[lastop].op.rotate.axis = 2;
      break;
    }

  op[lastop].op.rotate.degrees = yyvsp[-1].val;
  op[lastop].op.rotate.p = add_symbol(yyvsp[0].string,SYM_VALUE,0);
  
  lastop++;
;
    break;}
case 39:
#line 625 "mdl.y"
{
  lineno++;
  op[lastop].opcode = ROTATE;
  switch (*yyvsp[-1].string)
    {
    case 'x':
    case 'X': 
      op[lastop].op.rotate.axis = 0;
      break;
    case 'y':
    case 'Y': 
      op[lastop].op.rotate.axis = 1;
      break;
    case 'z':
    case 'Z': 
      op[lastop].op.rotate.axis = 2;
      break;
    }
  op[lastop].op.rotate.degrees = yyvsp[0].val;
  op[lastop].op.rotate.p = NULL;
  lastop++;
;
    break;}
case 40:
#line 648 "mdl.y"
{
  lineno++;
  op[lastop].opcode = BASENAME;
  op[lastop].op.basename.p = add_symbol(yyvsp[0].string,SYM_STRING,0);
  lastop++;
;
    break;}
case 41:
#line 655 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SAVE_KNOBS;
  op[lastop].op.save_knobs.p = add_symbol(yyvsp[0].string,SYM_STRING,0);
  lastop++;
;
    break;}
case 42:
#line 662 "mdl.y"
{
  lineno++;
  op[lastop].opcode = TWEEN;
  op[lastop].op.tween.start_frame = yyvsp[-3].val;
  op[lastop].op.tween.end_frame = yyvsp[-2].val;
  op[lastop].op.tween.knob_list0 = add_symbol(yyvsp[-1].string,SYM_STRING,0);
  op[lastop].op.tween.knob_list1 = add_symbol(yyvsp[0].string,SYM_STRING,0);
  lastop++;
;
    break;}
case 43:
#line 672 "mdl.y"
{
  lineno++;
  op[lastop].opcode = FRAMES;
  op[lastop].op.frames.num_frames = yyvsp[0].val;
  lastop++;
;
    break;}
case 44:
#line 679 "mdl.y"
{
  lineno++;
  op[lastop].opcode = VARY;
  op[lastop].op.vary.p = add_symbol(yyvsp[-4].string,SYM_STRING,0);
  op[lastop].op.vary.start_frame = yyvsp[-3].val;
  op[lastop].op.vary.end_frame = yyvsp[-2].val;
  op[lastop].op.vary.start_val = yyvsp[-1].val;
  op[lastop].op.vary.end_val = yyvsp[0].val;
  lastop++;
;
    break;}
case 45:
#line 690 "mdl.y"
{
  lineno++;
  op[lastop].opcode = PUSH;
  lastop++;
;
    break;}
case 46:
#line 696 "mdl.y"
{
  lineno++;
  op[lastop].opcode = GENERATE_RAYFILES;
  lastop++;
;
    break;}
case 47:
#line 702 "mdl.y"
{
  lineno++;
  op[lastop].opcode = POP;
  lastop++;
;
    break;}
case 48:
#line 708 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SAVE;
  op[lastop].op.save.p = add_symbol(yyvsp[0].string,SYM_FILE,0);
  lastop++;
;
    break;}
case 49:
#line 715 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SHADING;
  op[lastop].op.shading.p = add_symbol(yyvsp[0].string,SYM_STRING,0);
  lastop++;
;
    break;}
case 50:
#line 722 "mdl.y"
{
  lineno++;
  op[lastop].opcode = SETKNOBS;
  op[lastop].op.setknobs.value = yyvsp[0].val;
  lastop++;
;
    break;}
case 51:
#line 729 "mdl.y"
{
  lineno++;
  op[lastop].opcode = FOCAL;
  op[lastop].op.focal.value = yyvsp[0].val;
  lastop++;
;
    break;}
case 52:
#line 736 "mdl.y"
{
  lineno++;
  op[lastop].opcode = DISPLAY;
  lastop++;
;
    break;}
case 53:
#line 742 "mdl.y"
{
  lineno++;
  op[lastop].opcode = WEB;
  lastop++;
;
    break;}
case 54:
#line 748 "mdl.y"
{
  lineno++;
  op[lastop].opcode = AMBIENT;
  op[lastop].op.ambient.c[0] = yyvsp[-2].val;
  op[lastop].op.ambient.c[1] = yyvsp[-1].val;
  op[lastop].op.ambient.c[2] = yyvsp[0].val;
  lastop++;
;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 761 "mdl.y"


/* Other C stuff */



int yyerror(char *s)
{
  printf("Error in line %d:%s\n",lineno,s);
  return 0;
}

int yywrap()
{
  return 1;
}


extern FILE *yyin;

int main(int argc, char **argv)
{
  int i;
  
  if (argc > 1)
    {
      yyin = fopen(argv[1],"r");
    }
  
  yyparse();

  my_main();

  return 0;    
}

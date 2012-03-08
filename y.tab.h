typedef union{
  double val;
  char string[255];

} YYSTYPE;
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


extern YYSTYPE yylval;

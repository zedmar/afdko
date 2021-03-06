/*
 * proto.h
 *
 * SOFTWARE RIGHTS
 *
 * We reserve no LEGAL rights to SORCERER -- SORCERER is in the public
 * domain.  An individual or company may do whatever they wish with
 * source code distributed with SORCERER or the code generated by
 * SORCERER, including the incorporation of SORCERER, or its output, into
 * commerical software.
 *
 * We encourage users to develop software with SORCERER.  However, we do
 * ask that credit is given to us for developing SORCERER.  By "credit",
 * we mean that if you incorporate our source code into one of your
 * programs (commercial product, research project, or otherwise) that you
 * acknowledge this fact somewhere in the documentation, research report,
 * etc...  If you like SORCERER and have developed a nice tool with the
 * output, please mention that you developed it using SORCERER.  In
 * addition, we ask that this header remain intact in our source code.
 * As long as these guidelines are kept, we expect to continue enhancing
 * this system and expect to make other tools available as they are
 * completed.
 *
 * SORCERER 1.00B
 * Terence Parr
 * AHPCRC, University of Minnesota
 * 1992-2001
 */

				/* G l o b a l s */

extern char	*VersionNumber;
extern char	*VersionText;
extern char *FileStr[];
extern int  NumFiles;
extern int  action_file;
extern int  action_line;
extern int  CurFile;
extern char *CurRule;
extern char *CurRetDef;
extern char *CurParmDef;
extern FILE *output;
extern FILE *input;
extern Entry **symbols;
extern int token_table_size;
extern char **token_dict;
extern int token_type;
extern int end_of_input;
extern int epsilon;
extern int last_valid_token;
extern char *OutputDirectory;
extern ListNode *before_actions, *after_actions, *class_actions;
extern char	translator[];
extern char	tokdefs_file[];
extern char *header_action;
extern struct _ast *rules;
extern int print_guts;
extern int transform;
extern int found_guess_block;
extern ListNode *token_list;
extern char	*def_token_file;
extern int def_tokens;
extern int found_error;
extern set referenced_tokens;
extern int wild_card;
extern int UserDefdTokens;
extern int Inline;
extern char	*Prefix;
extern int GenAnsiProtos;
extern int GenKRProtos;
extern FILE *ProtoFILE;
extern char *GenProtoFile;
extern ListNode *RefVars;
extern ListNode *AllRefVars;
extern ListNode *AllGlobVars;
extern char	CurRefVarType[];
extern char	CurRefVarLabel[];
extern char	CurClassName[];
extern int GenCPP;
extern int NoCtor; /* MR23 */

#ifdef __VMS
#define STRICMP strcasecmp
#else
#define STRICMP stricmp
#endif
                           /* F u n c t i o n s */

#ifdef __USE_PROTOS
extern int main( int, char *[] );
extern int STRICMP(const char *, const char *);   /* MR20 */
extern void help( void );
extern FILE * NextFile( void );
extern void pushint( int );
extern int popint( void );
extern int istacksize( void );
extern void istackreset( void );
extern int istackempty( void );
extern int topint( void );
extern char * eMsg3( char *, char *, char *, char * );
extern char * eMsgd( char *, int );
extern void fatalFL( char *, char *, int );
extern void list_add( ListNode **, void * );
extern Entry * newEntry( char *, int );
extern void token_association( int, char * );
extern char * outname( char * );
extern char * OutMetaName( char * );
extern void set_fprint( FILE *, set );
extern void gen_info_hdr( FILE * );
extern void gen_hdr( void );
extern void gen_hdr1( void );
extern void gen( AST * );
extern void gen_header( AST * );
extern void gen_rule( AST * );
extern void gen_block( AST *, int );
extern void gen_alt( AST * );
extern void gen_tree_pattern( AST * );
extern void gen_element( AST * );
extern void define_labels_in_block( AST * );
extern void define_labels_in_alt( AST * );
extern void define_labels_in_tree( AST * );
extern void define_labels_in_element( AST * );
extern void dumpAction( char *, FILE *, int, int, int, int );
extern char * find_predicate( AST * );
extern set gen_prediction_expr( AST *, GLA * );
extern void GenRulePrototypes( FILE *, int );
extern void gen_tokens_file( void );
extern void code_for_guess_block( AST *, int * );
extern set Lookahead( GLA * );
extern void build_GLA( AST * );
extern GLA * build_GLA_for_block( AST *, GLA ** );
extern GLA * build_GLA_for_ALT( AST *, GLA ** );
extern GLA * build_GLA_for_tree( AST *, GLA ** );
extern GLA * build_GLA_for_element( AST *, GLA ** );
extern void build_follow_links( GLA *, ListNode * );
extern void dump_GLAs( AST * );
extern void dump_GLA( GLA * );
extern void test_block_consistency( AST *, int );
extern void GenRulePrototype(FILE *f, AST *p, SymEntry *s, int decl_not_def);
extern void DumpOldStyleParms( char *pdecl, FILE *output );
extern int DumpNextNameInDef( char **q, FILE *output );
extern void DumpListOfParmNames( char *pdecl, FILE *output );
extern SymEntry *define_token(char *text);
extern char *actiondup(char *s);
extern AST *read_sor_desc(FILE *f);
extern void DumpType( char *s, FILE *f, char *file, int line );
extern AST *first_guess_block(AST *q);
extern RefVarRec *refVarRec(char *);
extern char *cvt_token_str(char *, char *);
extern char *id_in_decl( char *decl );
extern void dump_prefixed_decl( char *prefix, char *s, FILE *f );
extern void ensure_no_C_file_collisions(char *class_c_file);
extern void GenCPPClassHeader(void);
extern void GenCPPClassCode(void);
#else
extern int main( );
extern int STRICMP();   /* MR20 */
extern void help( );
extern FILE * NextFile( );
extern void pushint( );
extern int popint( );
extern int istacksize( );
extern void istackreset( );
extern int istackempty( );
extern int topint( );
extern char * eMsg3( );
extern char * eMsgd( );
extern void fatalFL( );
extern void list_add( );
extern Entry * newEntry( );
extern void token_association( );
extern char * outname( );
extern char * OutMetaName( );
extern void set_fprint( );
extern void gen_info_hdr( );
extern void gen_hdr( );
extern void gen_hdr1( );
extern void gen( );
extern void gen_header( );
extern void gen_rule( );
extern void gen_block( );
extern void gen_alt( );
extern void gen_tree_pattern( );
extern void gen_element( );
extern void define_labels_in_block( );
extern void define_labels_in_alt( );
extern void define_labels_in_tree( );
extern void define_labels_in_element( );
extern void dumpAction( );
extern char * find_predicate( );
extern set gen_prediction_expr( );
extern void GenRulePrototypes( );
extern void gen_tokens_file( );
extern void code_for_guess_block( );
extern set Lookahead( );
extern void build_GLA( );
extern GLA * build_GLA_for_block( );
extern GLA * build_GLA_for_ALT( );
extern GLA * build_GLA_for_tree( );
extern GLA * build_GLA_for_element( );
extern void build_follow_links( );
extern void dump_GLAs( );
extern void dump_GLA( );
extern void test_block_consistency( );
extern void GenRulePrototype();
extern void GenRulePrototype();
extern void DumpOldStyleParms();
extern int DumpNextNameInDef();
extern void DumpListOfParmNames();
extern SymEntry *define_token();
extern char *actiondup();
extern AST *read_sor_desc();
extern void DumpType();
extern AST *first_guess_block();
extern RefVarRec *refVarRec();
extern char *cvt_token_str();
extern char *id_in_decl();
extern void dump_prefixed_decl();
extern void ensure_no_C_file_collisions();
extern void GenCPPClassHeader();
extern void GenCPPClassCode();
#endif

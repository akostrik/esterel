/* sscc : C CODE OF SORTED EQUATIONS serrure - SIMULATION MODE */

/* AUXILIARY DECLARATIONS */

#ifndef STRLEN
#define STRLEN 81
#endif
#define _COND(A,B,C) ((A)?(B):(C))
#ifdef TRACE_ACTION
#include <stdio.h>
#endif
#ifndef NULL
#define NULL ((char*)0)
#endif

#ifndef __EXEC_STATUS_H_LOADED
#define __EXEC_STATUS_H_LOADED

typedef struct {
unsigned int start:1;
unsigned int kill:1;
unsigned int active:1;
unsigned int suspended:1;
unsigned int prev_active:1;
unsigned int prev_suspended:1;
unsigned int exec_index;
unsigned int task_exec_index;
void (*pStart)();
void (*pRet)();
} __ExecStatus;

#endif
#define __ResetExecStatus(status) {\
   status.prev_active = status.active; \
   status.prev_suspended = status.suspended; \
   status.start = status.kill = status.active = status.suspended = 0; }
#define __DSZ(V) (--(V)<=0)
#define BASIC_TYPES_DEFINED
typedef int boolean;
typedef int integer;
typedef char* string;
#define CSIMUL_H_LOADED
typedef struct {char text[STRLEN];} symbolic;
extern void _boolean(boolean*, boolean);
extern boolean _eq_boolean(boolean, boolean);
extern boolean _ne_boolean(boolean, boolean);
extern boolean _cond_boolean(boolean ,boolean ,boolean);
extern char* _boolean_to_text(boolean);
extern int _check_boolean(char*);
extern void _text_to_boolean(boolean*, char*);
extern void _integer(integer*, integer);
extern boolean _eq_integer(integer, integer);
extern boolean _ne_integer(integer, integer);
extern integer _cond_integer(boolean ,integer ,integer);
extern char* _integer_to_text(integer);
extern int _check_integer(char*);
extern void _text_to_integer(integer*, char*);
extern void _string(string, string);
extern boolean _eq_string(string, string);
extern boolean _ne_string(string, string);
extern string _cond_string(boolean ,string ,string);
extern char* _string_to_text(string);
extern int _check_string(char*);
extern void _text_to_string(string, char*);
extern void _float(float*, float);
extern boolean _eq_float(float, float);
extern boolean _ne_float(float, float);
extern float _cond_float(boolean ,float ,float);
extern char* _float_to_text(float);
extern int _check_float(char*);
extern void _text_to_float(float*, char*);
extern void _double(double*, double);
extern boolean _eq_double(double, double);
extern boolean _ne_double(double, double);
extern double _cond_double(boolean ,double ,double);
extern char* _double_to_text(double);
extern int _check_double(char*);
extern void _text_to_double(double*, char*);
extern void _symbolic(symbolic*, symbolic);
extern boolean _eq_symbolic(symbolic, symbolic);
extern boolean _ne_symbolic(symbolic, symbolic);
extern symbolic _cond_symbolic(boolean ,symbolic ,symbolic);
extern char* _symbolic_to_text(symbolic);
extern int _check_symbolic(char*);
extern void _text_to_symbolic(symbolic*, char*);
extern char* __PredefinedTypeToText(int, char*);
#define _true 1
#define _false 0
#define __serrure_GENERIC_TEST(TEST) return TEST;
typedef void (*__serrure_APF)();
static __serrure_APF *__serrure_PActionArray;
static int **__serrure_PCheckArray;
struct __SourcePoint {
int linkback;
int line;
int column;
int instance_index;
};
struct __InstanceEntry {
char *module_name;
int father_index;
char *dir_name;
char *file_name;
struct __SourcePoint source_point;
struct __SourcePoint end_point;
struct __SourcePoint instance_point;
};
struct __TaskEntry {
char *name;
int   nb_args_ref;
int   nb_args_val;
int  *type_codes_array;
struct __SourcePoint source_point;
};
struct __SignalEntry {
char *name;
int code;
int variable_index;
int present;
struct __SourcePoint source_point;
int number_of_emit_source_points;
struct __SourcePoint* emit_source_point_array;
int number_of_present_source_points;
struct __SourcePoint* present_source_point_array;
int number_of_access_source_points;
struct __SourcePoint* access_source_point_array;
};
struct __InputEntry {
char *name;
int hash;
char *type_name;
int is_a_sensor;
int type_code;
int multiple;
int signal_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ReturnEntry {
char *name;
int hash;
char *type_name;
int type_code;
int signal_index;
int exec_index;
int (*p_check_input)(char*);
void (*p_input_function)();
int present;
struct __SourcePoint source_point;
};
struct __ImplicationEntry {
int master;
int slave;
struct __SourcePoint source_point;
};
struct __ExclusionEntry {
int *exclusion_list;
struct __SourcePoint source_point;
};
struct __VariableEntry {
char *full_name;
char *short_name;
char *type_name;
int type_code;
int comment_kind;
int is_initialized;
char *p_variable;
char *source_name;
int written;
unsigned char written_in_transition;
unsigned char read_in_transition;
struct __SourcePoint source_point;
};
struct __ExecEntry {
int task_index;
int *var_indexes_array;
char **p_values_array;
struct __SourcePoint source_point;
};
struct __HaltEntry {
struct __SourcePoint source_point;
};
struct __NetEntry {
int known;
int value;
int number_of_source_points;
struct __SourcePoint* source_point_array;
};
struct __ModuleEntry {
char *version_id;
char *name;
int number_of_instances;
int number_of_tasks;
int number_of_signals;
int number_of_inputs;
int number_of_returns;
int number_of_sensors;
int number_of_outputs;
int number_of_locals;
int number_of_exceptions;
int number_of_implications;
int number_of_exclusions;
int number_of_variables;
int number_of_execs;
int number_of_halts;
int number_of_nets;
int number_of_states;
int state;
unsigned short *halt_list;
unsigned short *awaited_list;
unsigned short *emitted_list;
unsigned short *started_list;
unsigned short *killed_list;
unsigned short *suspended_list;
unsigned short *active_list;
int run_time_error_code;
int error_info;
void (*init)();
int (*run)();
int (*reset)();
char *(*show_variable)(int);
void (*set_variable)(int, char*, char*);
int (*check_value)(int, char*);
int (*execute_action)();
struct __InstanceEntry* instance_table;
struct __TaskEntry* task_table;
struct __SignalEntry* signal_table;
struct __InputEntry* input_table;
struct __ReturnEntry* return_table;
struct __ImplicationEntry* implication_table;
struct __ExclusionEntry* exclusion_table;
struct __VariableEntry* variable_table;
struct __ExecEntry* exec_table;
struct __HaltEntry* halt_table;
struct __NetEntry* net_table;
};

                     
/* EXTERN DECLARATIONS */

extern int __CheckVariables(int*);
extern void __ResetInput();
extern void __ResetExecs();
extern void __ResetVariables();
extern void __ResetVariableStatus();
extern void __AppendToList(unsigned short*, unsigned short);
extern void __ListCopy(unsigned short*, unsigned short**);
extern void __WriteVariable(int);
extern void __ResetVariable(int);
extern void __ResetModuleEntry();
extern void __ResetModuleEntryBeforeReaction();
extern void __ResetModuleEntryAfterReaction();
#ifndef _NO_EXTERN_DEFINITIONS
#ifndef _NO_CONSTANT_DEFINITIONS
#endif
#endif

/* INITIALIZED CONSTANTS */
static integer code1 = 1;
static integer code2 = 2;
static integer code3 = 3;
static integer code4 = 4;
static integer duree = 10;

/* MEMORY ALLOCATION */

static integer __serrure_V0;
static boolean __serrure_V1;
static integer __serrure_V2;
static integer __serrure_V3;
static integer __serrure_V4;
static integer __serrure_V5;
static integer __serrure_V6;
static integer __serrure_V7;
static integer __serrure_V8;
static integer __serrure_V9;
static integer __serrure_V10;
static integer __serrure_V11;

static unsigned short __serrure_HaltList[11];
static unsigned short __serrure_AwaitedList[9];
static unsigned short __serrure_EmittedList[9];
static unsigned short __serrure_StartedList[1];
static unsigned short __serrure_KilledList[1];
static unsigned short __serrure_SuspendedList[1];
static unsigned short __serrure_ActiveList[1];
static unsigned short __serrure_AllAwaitedList[9]={1,0};


/* INPUT FUNCTIONS */

void serrure_I_CODE (integer __V) {
__WriteVariable(0);
__serrure_V0 = __V;
__serrure_V1 = _true;
}
void serrure_IS_CODE (string __V) {
__WriteVariable(0);
_text_to_integer(&__serrure_V0,__V);
__serrure_V1 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int serrure_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __serrure_A1 () {
__serrure_GENERIC_TEST(__serrure_V1);
}
static int __serrure_Check1 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __serrure_A2 () {
#ifdef __OUTPUT
serrure_O_ROUGE();
#endif
__AppendToList(__serrure_EmittedList,1);
}
static int __serrure_Check2 [] = {1,0,0};
static void __serrure_A3 () {
#ifdef __OUTPUT
serrure_O_VERT();
#endif
__AppendToList(__serrure_EmittedList,2);
}
static int __serrure_Check3 [] = {1,0,0};
static void __serrure_A4 () {
#ifdef __OUTPUT
serrure_O_ATTENTE();
#endif
__AppendToList(__serrure_EmittedList,3);
}
static int __serrure_Check4 [] = {1,0,0};
static void __serrure_A5 () {
#ifdef __OUTPUT
serrure_O_T(__serrure_V2);
#endif
__AppendToList(__serrure_EmittedList,4);
}
static int __serrure_Check5 [] = {1,0,0};
static void __serrure_A6 () {
#ifdef __OUTPUT
serrure_O_CODE_EST_LA_SIG();
#endif
__AppendToList(__serrure_EmittedList,5);
}
static int __serrure_Check6 [] = {1,0,0};

/* ASSIGNMENTS */

static void __serrure_A7 () {
__serrure_V1 = _false;
}
static int __serrure_Check7 [] = {1,0,1,1};
static void __serrure_A8 () {
__serrure_V3 = 0;
}
static int __serrure_Check8 [] = {1,0,1,3};
static void __serrure_A9 () {
__serrure_V3 = __serrure_V3+1;
}
static int __serrure_Check9 [] = {1,1,3,1,3};
static void __serrure_A10 () {
__serrure_V2 = __serrure_V3;
}
static int __serrure_Check10 [] = {1,1,3,1,2};
static void __serrure_A11 () {
__serrure_V4 = 0;
}
static int __serrure_Check11 [] = {1,0,1,4};
static void __serrure_A12 () {
__serrure_V5 = __serrure_V0;
}
static int __serrure_Check12 [] = {1,1,0,1,5};
static void __serrure_A13 () {
__serrure_V9 = duree;
}
static int __serrure_Check13 [] = {1,0,1,9};
static void __serrure_A14 () {
__serrure_V6 = __serrure_V0;
}
static int __serrure_Check14 [] = {1,1,0,1,6};
static void __serrure_A15 () {
__serrure_V7 = __serrure_V0;
}
static int __serrure_Check15 [] = {1,1,0,1,7};
static void __serrure_A16 () {
__serrure_V8 = __serrure_V0;
}
static int __serrure_Check16 [] = {1,1,0,1,8};
static void __serrure_A17 () {
__serrure_V10 = 10;
}
static int __serrure_Check17 [] = {1,0,1,10};
static void __serrure_A18 () {
__serrure_V4 = __serrure_V4+1;
}
static int __serrure_Check18 [] = {1,1,4,1,4};
static void __serrure_A19 () {
__serrure_V11 = duree*__serrure_V4;
}
static int __serrure_Check19 [] = {1,1,4,1,11};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __serrure_A20 () {
__serrure_GENERIC_TEST(__serrure_V9>0);
}
static int __serrure_Check20 [] = {1,1,9,0};
static int __serrure_A21 () {
__serrure_GENERIC_TEST((__serrure_V5==code1)&&(__serrure_V6==code2)&&(__serrure_V7==code3)&&(__serrure_V8==code4));
}
static int __serrure_Check21 [] = {1,4,5,6,7,8,0};
static int __serrure_A22 () {
__serrure_GENERIC_TEST(__serrure_V10>0);
}
static int __serrure_Check22 [] = {1,1,10,0};
static int __serrure_A23 () {
__serrure_GENERIC_TEST(__serrure_V11>0);
}
static int __serrure_Check23 [] = {1,1,11,0};

/* DECREMENTS */

static int __serrure_A24 () {
__serrure_GENERIC_TEST(__DSZ(__serrure_V9));
}
static int __serrure_Check24 [] = {1,1,9,1,9};
static int __serrure_A25 () {
__serrure_GENERIC_TEST(__DSZ(__serrure_V10));
}
static int __serrure_Check25 [] = {1,1,10,1,10};
static int __serrure_A26 () {
__serrure_GENERIC_TEST(__DSZ(__serrure_V11));
}
static int __serrure_Check26 [] = {1,1,11,1,11};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __serrure_A27 () {
;
__ResetVariable(0);
}
static int __serrure_Check27 [] = {1,0,0};
static void __serrure_A28 () {
;
__ResetVariable(2);
}
static int __serrure_Check28 [] = {1,0,0};
static void __serrure_A29 () {
;
__ResetVariable(5);
}
static int __serrure_Check29 [] = {1,0,0};
static void __serrure_A30 () {
;
__ResetVariable(6);
}
static int __serrure_Check30 [] = {1,0,0};
static void __serrure_A31 () {
;
__ResetVariable(7);
}
static int __serrure_Check31 [] = {1,0,0};
static void __serrure_A32 () {
;
__ResetVariable(8);
}
static int __serrure_Check32 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__serrure_CheckArray[] = {
0,
__serrure_Check1,
__serrure_Check2,
__serrure_Check3,
__serrure_Check4,
__serrure_Check5,
__serrure_Check6,
__serrure_Check7,
__serrure_Check8,
__serrure_Check9,
__serrure_Check10,
__serrure_Check11,
__serrure_Check12,
__serrure_Check13,
__serrure_Check14,
__serrure_Check15,
__serrure_Check16,
__serrure_Check17,
__serrure_Check18,
__serrure_Check19,
__serrure_Check20,
__serrure_Check21,
__serrure_Check22,
__serrure_Check23,
__serrure_Check24,
__serrure_Check25,
__serrure_Check26,
__serrure_Check27,
__serrure_Check28,
__serrure_Check29,
__serrure_Check30,
__serrure_Check31,
__serrure_Check32
};
static int **__serrure_PCheckArray =  __serrure_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void serrure_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __serrure_show_variable (int __V) {
extern struct __VariableEntry __serrure_VariableTable[];
struct __VariableEntry* p_var = &__serrure_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __serrure_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __serrure_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __serrure_InstanceTable [] = {
{"serrure",0,"","serrure.strl",{1,4,1,0},{1,74,1,0},{0,0,0,0}},
};

struct __SignalEntry __serrure_SignalTable [] = {
{"CODE",1,0,0,{1,10,7,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ROUGE",34,0,0,{1,11,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"VERT",34,0,0,{1,12,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ATTENTE",34,0,0,{1,13,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"T",2,2,0,{1,14,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CODE_EST_LA_SIG",34,0,0,{1,15,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TEMPS_ECOULE",48,0,0,{1,38,10,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CODE_EST_LA",48,0,0,{1,38,24,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __serrure_InputTable [] = {
{"CODE",81,"integer",0,-3,0,0,_check_integer,serrure_IS_CODE,0,{1,10,7,0}}};

struct __VariableEntry __serrure_VariableTable [] = {
{"__serrure_V0","V0","integer",-3,1,0,(char*)&__serrure_V0,"CODE",0,0,0,{1,10,7,0}},
{"__serrure_V1","V1","boolean",-2,2,0,(char*)&__serrure_V1,"CODE",0,0,0,{1,10,7,0}},
{"__serrure_V2","V2","integer",-3,1,0,(char*)&__serrure_V2,"T",0,0,0,{1,14,8,0}},
{"__serrure_V3","V3","integer",-3,0,0,(char*)&__serrure_V3,"tick",0,0,0,{1,17,7,0}},
{"__serrure_V4","V4","integer",-3,0,0,(char*)&__serrure_V4,"nb_tentatives",0,0,0,{1,26,5,0}},
{"__serrure_V5","V5","integer",-3,0,0,(char*)&__serrure_V5,"c1",0,0,0,{1,32,9,0}},
{"__serrure_V6","V6","integer",-3,0,0,(char*)&__serrure_V6,"c2",0,0,0,{1,33,9,0}},
{"__serrure_V7","V7","integer",-3,0,0,(char*)&__serrure_V7,"c3",0,0,0,{1,34,9,0}},
{"__serrure_V8","V8","integer",-3,0,0,(char*)&__serrure_V8,"c4",0,0,0,{1,35,9,0}},
{"__serrure_V9","V9","integer",-3,3,0,(char*)&__serrure_V9,"0",0,0,0,{1,39,16,0}},
{"__serrure_V10","V10","integer",-3,3,0,(char*)&__serrure_V10,"0",0,0,0,{1,54,16,0}},
{"__serrure_V11","V11","integer",-3,3,0,(char*)&__serrure_V11,"0",0,0,0,{1,60,21,0}}
};

struct __HaltEntry __serrure_HaltTable [] = {
{{1,74,1,0}},
{{1,21,5,0}},
{{1,29,7,0}},
{{1,36,5,0}},
{{1,40,11,0}},
{{1,44,9,0}},
{{1,46,9,0}},
{{1,48,9,0}},
{{1,56,11,0}},
{{1,62,11,0}}
};


static void __serrure__reset_input () {
__serrure_V1 = _false;
}


/* MODULE DATA FOR SIMULATION */

int serrure();
int serrure_reset();

static struct __ModuleEntry __serrure_ModuleData = {
"Simulation interface release 5","serrure",
1,0,8,1,0,0,5,0,2,0,0,12,0,10,0,0,0,
__serrure_HaltList,
__serrure_AwaitedList,
__serrure_EmittedList,
__serrure_StartedList,
__serrure_KilledList,
__serrure_SuspendedList,
__serrure_ActiveList,
0,0,
serrure_initialize,serrure,serrure_reset,
__serrure_show_variable,__serrure_set_variable,__serrure_check_value,0,
__serrure_InstanceTable,
0,
__serrure_SignalTable,__serrure_InputTable,0,
0,0,
__serrure_VariableTable,
0,
__serrure_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __serrure_R[10] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int serrure () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[25];

__serrure_ModuleData.awaited_list = __serrure_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __serrure_R[2]&&!(__serrure_R[0]);
E[1] = __serrure_R[4]&&!(__serrure_R[0]);
E[2] = E[1]&&(__CheckVariables(__serrure_CheckArray[24]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 24\n"),
#endif
__serrure_A24());
E[3] = __serrure_R[3]&&!(__serrure_R[0]);
E[4] = E[3]&&(__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1());
if (E[4]) {
__CheckVariables(__serrure_CheckArray[12]);__serrure_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A12\n");
#endif
}
if (E[4]) {
__CheckVariables(__serrure_CheckArray[13]);__serrure_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A13\n");
#endif
}
E[5] = E[4]&&(__CheckVariables(__serrure_CheckArray[20]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 20\n"),
#endif
__serrure_A20());
E[6] = E[2]||(E[4]&&!(E[5]));
if (E[6]) {
__AppendToList(__serrure_EmittedList,6);
}
E[7] = __serrure_R[7]&&!(__serrure_R[0]);
E[8] = E[7]&&(__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1());
if (E[8]) {
__AppendToList(__serrure_EmittedList,5);
__AppendToList(__serrure_EmittedList,7);
}
if (E[8]) {
__CheckVariables(__serrure_CheckArray[16]);__serrure_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A16\n");
#endif
}
E[9] = __serrure_R[5]||__serrure_R[6]||__serrure_R[7];
E[10] = __serrure_R[4]||E[9];
E[2] = E[5]||(E[1]&&!(E[2]));
E[1] = (E[10]&&!(__serrure_R[4]))||E[2];
E[5] = __serrure_R[5]&&!(__serrure_R[0]);
E[11] = E[5]&&!((__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1()));
E[11] = E[4]||(__serrure_R[5]&&E[11]);
E[5] = E[5]&&(__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1());
if (E[5]) {
__CheckVariables(__serrure_CheckArray[14]);__serrure_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A14\n");
#endif
}
E[12] = __serrure_R[6]&&!(__serrure_R[0]);
E[13] = E[12]&&!((__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1()));
E[13] = E[5]||(__serrure_R[6]&&E[13]);
E[12] = E[12]&&(__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1());
if (E[12]) {
__CheckVariables(__serrure_CheckArray[15]);__serrure_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A15\n");
#endif
}
E[7] = E[7]&&!((__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1()));
E[7] = E[12]||(__serrure_R[7]&&E[7]);
E[9] = (E[10]&&!(E[9]))||E[11]||E[13]||E[7];
E[6] = (E[6]||E[8])&&(E[1]||E[6])&&(E[9]||E[8]);
E[14] = E[6]&&E[8];
E[15] = E[14]&&(__CheckVariables(__serrure_CheckArray[21]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 21\n"),
#endif
__serrure_A21());
if (E[15]) {
__CheckVariables(__serrure_CheckArray[17]);__serrure_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A17\n");
#endif
}
E[16] = E[15]&&(__CheckVariables(__serrure_CheckArray[22]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 22\n"),
#endif
__serrure_A22());
E[17] = __serrure_R[8]&&!(__serrure_R[0]);
E[18] = E[17]&&(__CheckVariables(__serrure_CheckArray[25]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 25\n"),
#endif
__serrure_A25());
E[17] = E[16]||(E[17]&&!(E[18]));
if (E[17]) {
__AppendToList(__serrure_EmittedList,2);
}
E[19] = E[0]&&E[17];
E[20] = __serrure_R[9]&&!(__serrure_R[0]);
E[21] = E[20]&&(__CheckVariables(__serrure_CheckArray[26]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 26\n"),
#endif
__serrure_A26());
E[14] = E[14]&&!(E[15]);
if (E[14]) {
__CheckVariables(__serrure_CheckArray[18]);__serrure_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A18\n");
#endif
}
if (E[14]) {
__CheckVariables(__serrure_CheckArray[19]);__serrure_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A19\n");
#endif
}
E[22] = E[14]&&(__CheckVariables(__serrure_CheckArray[23]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 23\n"),
#endif
__serrure_A23());
E[16] = E[18]||(E[15]&&!(E[16]))||E[21]||(E[14]&&!(E[22]))||(E[6]&&!(E[8]));
E[10] = __serrure_R[3]||__serrure_R[8]||__serrure_R[9]||E[10];
E[18] = __serrure_R[2]||E[10];
E[23] = (E[18]&&!(__serrure_R[2]))||E[19];
E[10] = (E[18]&&!(E[10]))||E[16];
E[24] = __serrure_R[0]&&!((__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1()));
if (E[24]) {
__CheckVariables(__serrure_CheckArray[27]);__serrure_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A27\n");
#endif
}
if (__serrure_R[0]) {
__CheckVariables(__serrure_CheckArray[28]);__serrure_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A28\n");
#endif
}
if (__serrure_R[0]) {
__CheckVariables(__serrure_CheckArray[11]);__serrure_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A11\n");
#endif
}
E[16] = ((E[19]||E[16])&&E[23]&&E[10])||__serrure_R[0];
E[0] = __serrure_R[2]&&E[0]&&!(E[17]);
if (E[16]||E[0]) {
__AppendToList(__serrure_EmittedList,1);
}
if (E[16]||E[0]) {
__CheckVariables(__serrure_CheckArray[2]);__serrure_A2();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A2\n");
#endif
}
if (E[17]) {
__CheckVariables(__serrure_CheckArray[3]);__serrure_A3();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A3\n");
#endif
}
__serrure_R[9] = E[22]||(E[20]&&!(E[21]));
if (__serrure_R[9]) {
__AppendToList(__serrure_EmittedList,3);
}
if (__serrure_R[9]) {
__CheckVariables(__serrure_CheckArray[4]);__serrure_A4();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A4\n");
#endif
}
if (__serrure_R[0]) {
__CheckVariables(__serrure_CheckArray[8]);__serrure_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A8\n");
#endif
}
E[21] = __serrure_R[0]||(__serrure_R[1]&&!(__serrure_R[0]));
if (E[21]) {
__AppendToList(__serrure_EmittedList,4);
}
if (E[21]) {
__CheckVariables(__serrure_CheckArray[9]);__serrure_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A9\n");
#endif
}
if (E[21]) {
__CheckVariables(__serrure_CheckArray[10]);__serrure_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A10\n");
#endif
}
if (E[21]) {
__CheckVariables(__serrure_CheckArray[5]);__serrure_A5();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A5\n");
#endif
}
if (E[8]) {
__CheckVariables(__serrure_CheckArray[6]);__serrure_A6();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A6\n");
#endif
}
E[20] = !(_true);
if (E[16]) {
__CheckVariables(__serrure_CheckArray[29]);__serrure_A29();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A29\n");
#endif
}
if (E[16]) {
__CheckVariables(__serrure_CheckArray[30]);__serrure_A30();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A30\n");
#endif
}
if (E[16]) {
__CheckVariables(__serrure_CheckArray[31]);__serrure_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A31\n");
#endif
}
if (E[16]) {
__CheckVariables(__serrure_CheckArray[32]);__serrure_A32();
#ifdef TRACE_ACTION
fprintf(stderr, "__serrure_A32\n");
#endif
}
E[3] = E[3]&&!((__CheckVariables(__serrure_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__serrure_A1()));
E[3] = __serrure_R[3]&&E[3];
E[9] = ((E[2]||E[11]||E[13]||E[7])&&E[1]&&E[9])||E[17]||__serrure_R[9];
E[9] = (E[0]||E[3]||E[9])&&(E[23]||E[0])&&(E[10]||E[3]||E[9]);
E[10] = __serrure_R[1]||E[18];
E[9] = (E[21]||E[16]||E[9])&&((E[10]&&!(__serrure_R[1]))||E[21])&&((E[10]&&!(E[18]))||E[16]||E[9]);
__serrure_R[2] = E[16]||E[0];
__serrure_R[3] = E[16]||E[3];
__serrure_R[4] = E[2]&&!(E[6]);
__serrure_R[5] = E[11]&&!(E[6]);
__serrure_R[6] = E[13]&&!(E[6]);
__serrure_R[7] = E[7]&&!(E[6]);
__serrure_R[0] = !(_true);
__serrure_R[1] = E[21];
if (__serrure_R[1]) { __AppendToList(__serrure_HaltList,1); }
if (__serrure_R[2]) { __AppendToList(__serrure_HaltList,2); }
if (__serrure_R[3]) { __AppendToList(__serrure_HaltList,3); }
if (__serrure_R[4]) { __AppendToList(__serrure_HaltList,4); }
if (__serrure_R[5]) { __AppendToList(__serrure_HaltList,5); }
if (__serrure_R[6]) { __AppendToList(__serrure_HaltList,6); }
if (__serrure_R[7]) { __AppendToList(__serrure_HaltList,7); }
__serrure_R[8] = E[17];
if (__serrure_R[8]) { __AppendToList(__serrure_HaltList,8); }
if (__serrure_R[9]) { __AppendToList(__serrure_HaltList,9); }
if (!E[9]) { __AppendToList(__serrure_HaltList,0); }
__ResetModuleEntryAfterReaction();
__serrure_ModuleData.awaited_list = __serrure_AllAwaitedList;
__serrure__reset_input();
return E[9];
}

/* AUTOMATON RESET */

int serrure_reset () {
__serrure_ModuleData.awaited_list = __serrure_AwaitedList;
__ResetModuleEntry();
__serrure_ModuleData.awaited_list = __serrure_AllAwaitedList;
__serrure_ModuleData.state = 0;
__serrure_R[0] = _true;
__serrure_R[1] = _false;
__serrure_R[2] = _false;
__serrure_R[3] = _false;
__serrure_R[4] = _false;
__serrure_R[5] = _false;
__serrure_R[6] = _false;
__serrure_R[7] = _false;
__serrure_R[8] = _false;
__serrure_R[9] = _false;
__serrure__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__serrure_ModuleData
};

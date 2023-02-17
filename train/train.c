/* sscc : C CODE OF SORTED EQUATIONS train - SIMULATION MODE */

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
#define __train_GENERIC_TEST(TEST) return TEST;
typedef void (*__train_APF)();
static __train_APF *__train_PActionArray;
static int **__train_PCheckArray;
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
#endif

/* INITIALIZED CONSTANTS */

/* MEMORY ALLOCATION */

static integer __train_V0;
static boolean __train_V1;
static integer __train_V2;
static boolean __train_V3;
static integer __train_V4;
static boolean __train_V5;
static boolean __train_V6;
static boolean __train_V7;
static integer __train_V8;
static integer __train_V9;
static integer __train_V10;
static integer __train_V11;
static integer __train_V12;
static integer __train_V13;

static unsigned short __train_HaltList[7];
static unsigned short __train_AwaitedList[9];
static unsigned short __train_EmittedList[9];
static unsigned short __train_StartedList[1];
static unsigned short __train_KilledList[1];
static unsigned short __train_SuspendedList[1];
static unsigned short __train_ActiveList[1];
static unsigned short __train_AllAwaitedList[9]={5,0,1,2,3,4};


/* INPUT FUNCTIONS */

void train_I_ACCELERER (integer __V) {
__WriteVariable(0);
__train_V0 = __V;
__train_V1 = _true;
}
void train_IS_ACCELERER (string __V) {
__WriteVariable(0);
_text_to_integer(&__train_V0,__V);
__train_V1 = _true;
}
void train_I_FREINER (integer __V) {
__WriteVariable(2);
__train_V2 = __V;
__train_V3 = _true;
}
void train_IS_FREINER (string __V) {
__WriteVariable(2);
_text_to_integer(&__train_V2,__V);
__train_V3 = _true;
}
void train_I_VITESSE (integer __V) {
__WriteVariable(4);
__train_V4 = __V;
__train_V5 = _true;
}
void train_IS_VITESSE (string __V) {
__WriteVariable(4);
_text_to_integer(&__train_V4,__V);
__train_V5 = _true;
}
void train_I_PRESENCE () {
__train_V6 = _true;
}
void train_IS_PRESENCE () {
__train_V6 = _true;
}
void train_I_SOS () {
__train_V7 = _true;
}
void train_IS_SOS () {
__train_V7 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int train_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __train_A1 () {
__train_GENERIC_TEST(__train_V1);
}
static int __train_Check1 [] = {1,0,0};
static int __train_A2 () {
__train_GENERIC_TEST(__train_V3);
}
static int __train_Check2 [] = {1,0,0};
static int __train_A3 () {
__train_GENERIC_TEST(__train_V5);
}
static int __train_Check3 [] = {1,0,0};
static int __train_A4 () {
__train_GENERIC_TEST(__train_V6);
}
static int __train_Check4 [] = {1,0,0};
static int __train_A5 () {
__train_GENERIC_TEST(__train_V7);
}
static int __train_Check5 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __train_A6 () {
#ifdef __OUTPUT
train_O_ACCELERER(__train_V0);
#endif
__AppendToList(__train_EmittedList,0);
}
static int __train_Check6 [] = {1,0,0};
static void __train_A7 () {
#ifdef __OUTPUT
train_O_FREINER(__train_V2);
#endif
__AppendToList(__train_EmittedList,1);
}
static int __train_Check7 [] = {1,0,0};
static void __train_A8 () {
#ifdef __OUTPUT
train_O_VITESSE(__train_V4);
#endif
__AppendToList(__train_EmittedList,2);
}
static int __train_Check8 [] = {1,0,0};
static void __train_A9 () {
#ifdef __OUTPUT
train_O_PRESENCE();
#endif
__AppendToList(__train_EmittedList,3);
}
static int __train_Check9 [] = {1,0,0};
static void __train_A10 () {
#ifdef __OUTPUT
train_O_SOS();
#endif
__AppendToList(__train_EmittedList,4);
}
static int __train_Check10 [] = {1,0,0};

/* ASSIGNMENTS */

static void __train_A11 () {
__train_V1 = _false;
}
static int __train_Check11 [] = {1,0,1,1};
static void __train_A12 () {
__train_V3 = _false;
}
static int __train_Check12 [] = {1,0,1,3};
static void __train_A13 () {
__train_V5 = _false;
}
static int __train_Check13 [] = {1,0,1,5};
static void __train_A14 () {
__train_V6 = _false;
}
static int __train_Check14 [] = {1,0,1,6};
static void __train_A15 () {
__train_V7 = _false;
}
static int __train_Check15 [] = {1,0,1,7};
static void __train_A16 () {
__train_V8 = 0;
}
static int __train_Check16 [] = {1,0,1,8};
static void __train_A17 () {
__train_V8 = 0;
}
static int __train_Check17 [] = {1,0,1,8};
static void __train_A18 () {
__train_V8 = __train_V8+1;
}
static int __train_Check18 [] = {1,1,8,1,8};
static void __train_A19 () {
__train_V2 = 3;
}
static int __train_Check19 [] = {1,0,1,2};
static void __train_A20 () {
__train_V9 = 0;
}
static int __train_Check20 [] = {1,0,1,9};
static void __train_A21 () {
__train_V10 = 0;
}
static int __train_Check21 [] = {1,0,1,10};
static void __train_A22 () {
__train_V11 = 0;
}
static int __train_Check22 [] = {1,0,1,11};
static void __train_A23 () {
__train_V12 = 0;
}
static int __train_Check23 [] = {1,0,1,12};
static void __train_A24 () {
__train_V10 = 1;
}
static int __train_Check24 [] = {1,0,1,10};
static void __train_A25 () {
__train_V11 = 1;
}
static int __train_Check25 [] = {1,0,1,11};
static void __train_A26 () {
__train_V10 = 5;
}
static int __train_Check26 [] = {1,0,1,10};
static void __train_A27 () {
__train_V11 = 2;
}
static int __train_Check27 [] = {1,0,1,11};
static void __train_A28 () {
__train_V10 = 10;
}
static int __train_Check28 [] = {1,0,1,10};
static void __train_A29 () {
__train_V11 = 2;
}
static int __train_Check29 [] = {1,0,1,11};
static void __train_A30 () {
__train_V12 = 0;
}
static int __train_Check30 [] = {1,0,1,12};
static void __train_A31 () {
__train_V10 = 0;
}
static int __train_Check31 [] = {1,0,1,10};
static void __train_A32 () {
__train_V11 = -(1)*__train_V2;
}
static int __train_Check32 [] = {1,1,2,1,11};
static void __train_A33 () {
__train_V12 = 0;
}
static int __train_Check33 [] = {1,0,1,12};
static void __train_A34 () {
__train_V9 = __train_V9+__train_V11;
}
static int __train_Check34 [] = {1,2,9,11,1,9};
static void __train_A35 () {
__train_V9 = __train_V10;
}
static int __train_Check35 [] = {1,1,10,1,9};
static void __train_A36 () {
__train_V9 = __train_V9+__train_V11;
}
static int __train_Check36 [] = {1,2,9,11,1,9};
static void __train_A37 () {
__train_V9 = __train_V10;
}
static int __train_Check37 [] = {1,1,10,1,9};
static void __train_A38 () {
__train_V4 = __train_V9;
}
static int __train_Check38 [] = {1,1,9,1,4};
static void __train_A39 () {
__train_V12 = __train_V12+1;
}
static int __train_Check39 [] = {1,1,12,1,12};
static void __train_A40 () {
__train_V12 = 0;
}
static int __train_Check40 [] = {1,0,1,12};
static void __train_A41 () {
__train_V13 = 4;
}
static int __train_Check41 [] = {1,0,1,13};
static void __train_A42 () {
__train_V9 = __train_V9-3;
}
static int __train_Check42 [] = {1,1,9,1,9};
static void __train_A43 () {
__train_V9 = 0;
}
static int __train_Check43 [] = {1,0,1,9};
static void __train_A44 () {
__train_V4 = __train_V9;
}
static int __train_Check44 [] = {1,1,9,1,4};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __train_A45 () {
__train_GENERIC_TEST(__train_V8>10);
}
static int __train_Check45 [] = {1,1,8,0};
static int __train_A46 () {
__train_GENERIC_TEST(__train_V0==1);
}
static int __train_Check46 [] = {1,1,0,0};
static int __train_A47 () {
__train_GENERIC_TEST(__train_V0==2);
}
static int __train_Check47 [] = {1,1,0,0};
static int __train_A48 () {
__train_GENERIC_TEST(__train_V0==3);
}
static int __train_Check48 [] = {1,1,0,0};
static int __train_A49 () {
__train_GENERIC_TEST(__train_V9>__train_V10);
}
static int __train_Check49 [] = {1,2,9,10,0};
static int __train_A50 () {
__train_GENERIC_TEST((__train_V9+__train_V11)>=__train_V10);
}
static int __train_Check50 [] = {1,3,9,11,10,0};
static int __train_A51 () {
__train_GENERIC_TEST(__train_V9<__train_V10);
}
static int __train_Check51 [] = {1,2,9,10,0};
static int __train_A52 () {
__train_GENERIC_TEST((__train_V9+__train_V11)<=__train_V10);
}
static int __train_Check52 [] = {1,3,9,11,10,0};
static int __train_A53 () {
__train_GENERIC_TEST(__train_V12==10);
}
static int __train_Check53 [] = {1,1,12,0};
static int __train_A54 () {
__train_GENERIC_TEST(__train_V13>0);
}
static int __train_Check54 [] = {1,1,13,0};
static int __train_A55 () {
__train_GENERIC_TEST(__train_V9>0);
}
static int __train_Check55 [] = {1,1,9,0};
static int __train_A56 () {
__train_GENERIC_TEST((__train_V9-3)>0);
}
static int __train_Check56 [] = {1,1,9,0};

/* DECREMENTS */

static int __train_A57 () {
__train_GENERIC_TEST(__DSZ(__train_V13));
}
static int __train_Check57 [] = {1,1,13,1,13};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __train_A58 () {
;
__ResetVariable(0);
}
static int __train_Check58 [] = {1,0,0};
static void __train_A59 () {
;
__ResetVariable(2);
}
static int __train_Check59 [] = {1,0,0};
static void __train_A60 () {
;
__ResetVariable(4);
}
static int __train_Check60 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__train_CheckArray[] = {
0,
__train_Check1,
__train_Check2,
__train_Check3,
__train_Check4,
__train_Check5,
__train_Check6,
__train_Check7,
__train_Check8,
__train_Check9,
__train_Check10,
__train_Check11,
__train_Check12,
__train_Check13,
__train_Check14,
__train_Check15,
__train_Check16,
__train_Check17,
__train_Check18,
__train_Check19,
__train_Check20,
__train_Check21,
__train_Check22,
__train_Check23,
__train_Check24,
__train_Check25,
__train_Check26,
__train_Check27,
__train_Check28,
__train_Check29,
__train_Check30,
__train_Check31,
__train_Check32,
__train_Check33,
__train_Check34,
__train_Check35,
__train_Check36,
__train_Check37,
__train_Check38,
__train_Check39,
__train_Check40,
__train_Check41,
__train_Check42,
__train_Check43,
__train_Check44,
__train_Check45,
__train_Check46,
__train_Check47,
__train_Check48,
__train_Check49,
__train_Check50,
__train_Check51,
__train_Check52,
__train_Check53,
__train_Check54,
__train_Check55,
__train_Check56,
__train_Check57,
__train_Check58,
__train_Check59,
__train_Check60
};
static int **__train_PCheckArray =  __train_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void train_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __train_show_variable (int __V) {
extern struct __VariableEntry __train_VariableTable[];
struct __VariableEntry* p_var = &__train_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __train_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __train_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __train_InstanceTable [] = {
{"train",0,"","train.strl",{1,149,1,0},{1,162,1,0},{0,0,0,0}},
{"securite",0,"","train.strl",{1,28,1,1},{1,50,1,1},{1,156,1,0}},
{"presence",0,"","train.strl",{1,53,1,2},{1,69,1,2},{1,158,1,0}},
{"controle",0,"","train.strl",{1,72,1,3},{1,146,1,3},{1,160,1,0}},
};

struct __SignalEntry __train_SignalTable [] = {
{"ACCELERER",3,0,0,{1,150,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"FREINER",3,2,0,{1,151,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"VITESSE",3,4,0,{1,152,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PRESENCE",35,0,0,{1,153,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"SOS",35,0,0,{1,154,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_SOS",48,0,0,{1,34,6,1},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_SOS",48,0,0,{1,59,6,2},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_SOS",48,0,0,{1,80,6,3},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __train_InputTable [] = {
{"ACCELERER",40,"integer",0,-3,0,0,_check_integer,train_IS_ACCELERER,0,{1,150,13,0}},
{"FREINER",18,"integer",0,-3,0,1,_check_integer,train_IS_FREINER,0,{1,151,13,0}},
{"VITESSE",42,"integer",0,-3,0,2,_check_integer,train_IS_VITESSE,0,{1,152,13,0}},
{"PRESENCE",92,0,0,-1,0,3,0,train_IS_PRESENCE,0,{1,153,13,0}},
{"SOS",43,0,0,-1,0,4,0,train_IS_SOS,0,{1,154,13,0}}};

struct __VariableEntry __train_VariableTable [] = {
{"__train_V0","V0","integer",-3,1,0,(char*)&__train_V0,"ACCELERER",0,0,0,{1,150,13,0}},
{"__train_V1","V1","boolean",-2,2,0,(char*)&__train_V1,"ACCELERER",0,0,0,{1,150,13,0}},
{"__train_V2","V2","integer",-3,1,0,(char*)&__train_V2,"FREINER",0,0,0,{1,151,13,0}},
{"__train_V3","V3","boolean",-2,2,0,(char*)&__train_V3,"FREINER",0,0,0,{1,151,13,0}},
{"__train_V4","V4","integer",-3,1,0,(char*)&__train_V4,"VITESSE",0,0,0,{1,152,13,0}},
{"__train_V5","V5","boolean",-2,2,0,(char*)&__train_V5,"VITESSE",0,0,0,{1,152,13,0}},
{"__train_V6","V6","boolean",-2,2,0,(char*)&__train_V6,"PRESENCE",0,0,0,{1,153,13,0}},
{"__train_V7","V7","boolean",-2,2,0,(char*)&__train_V7,"SOS",0,0,0,{1,154,13,0}},
{"__train_V8","V8","integer",-3,0,0,(char*)&__train_V8,"cpt",0,0,0,{1,33,5,1}},
{"__train_V9","V9","integer",-3,0,0,(char*)&__train_V9,"vitesse",0,0,0,{1,79,5,3}},
{"__train_V10","V10","integer",-3,0,0,(char*)&__train_V10,"vitesseBut",0,0,0,{1,81,5,3}},
{"__train_V11","V11","integer",-3,0,0,(char*)&__train_V11,"deltaVitesse",0,0,0,{1,82,5,3}},
{"__train_V12","V12","integer",-3,0,0,(char*)&__train_V12,"cpt",0,0,0,{1,83,5,3}},
{"__train_V13","V13","integer",-3,3,0,(char*)&__train_V13,"0",0,0,0,{1,133,8,3}}
};

struct __HaltEntry __train_HaltTable [] = {
{{1,162,1,0}},
{{1,43,1,1}},
{{1,45,1,1}},
{{1,67,1,2}},
{{1,128,3,3}},
{{1,141,3,3}}
};


static void __train__reset_input () {
__train_V1 = _false;
__train_V3 = _false;
__train_V5 = _false;
__train_V6 = _false;
__train_V7 = _false;
}


/* MODULE DATA FOR SIMULATION */

int train();
int train_reset();

static struct __ModuleEntry __train_ModuleData = {
"Simulation interface release 5","train",
4,0,8,5,0,0,5,0,3,0,0,14,0,6,0,0,0,
__train_HaltList,
__train_AwaitedList,
__train_EmittedList,
__train_StartedList,
__train_KilledList,
__train_SuspendedList,
__train_ActiveList,
0,0,
train_initialize,train,train_reset,
__train_show_variable,__train_set_variable,__train_check_value,0,
__train_InstanceTable,
0,
__train_SignalTable,__train_InputTable,0,
0,0,
__train_VariableTable,
0,
__train_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __train_R[6] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int train () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[35];

__train_ModuleData.awaited_list = __train_AwaitedList;
__ResetModuleEntryBeforeReaction();
if ((__CheckVariables(__train_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__train_A1())) {
__CheckVariables(__train_CheckArray[6]);__train_A6();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A6\n");
#endif
}
E[0] = __train_R[2]&&!(__train_R[0]);
if (E[0]) {
__CheckVariables(__train_CheckArray[19]);__train_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A19\n");
#endif
}
E[1] = (__CheckVariables(__train_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__train_A2())||E[0];
if (E[1]) {
__AppendToList(__train_EmittedList,1);
}
if (E[1]) {
__CheckVariables(__train_CheckArray[7]);__train_A7();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A7\n");
#endif
}
E[2] = __train_R[5]&&!(__train_R[0]);
E[3] = E[2]&&(__CheckVariables(__train_CheckArray[57]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 57\n"),
#endif
__train_A57());
E[4] = __train_R[0]&&!((__CheckVariables(__train_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__train_A1()));
if (E[4]) {
__CheckVariables(__train_CheckArray[58]);__train_A58();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A58\n");
#endif
}
E[5] = __train_R[0]&&!((__CheckVariables(__train_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__train_A2()));
if (E[5]) {
__CheckVariables(__train_CheckArray[59]);__train_A59();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A59\n");
#endif
}
E[6] = __train_R[0]&&!((__CheckVariables(__train_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__train_A3()));
if (E[6]) {
__CheckVariables(__train_CheckArray[60]);__train_A60();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A60\n");
#endif
}
if (__train_R[0]) {
__CheckVariables(__train_CheckArray[20]);__train_A20();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A20\n");
#endif
}
if (__train_R[0]) {
__CheckVariables(__train_CheckArray[21]);__train_A21();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A21\n");
#endif
}
if (__train_R[0]) {
__CheckVariables(__train_CheckArray[22]);__train_A22();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A22\n");
#endif
}
if (__train_R[0]) {
__CheckVariables(__train_CheckArray[23]);__train_A23();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A23\n");
#endif
}
E[7] = (__train_R[4]&&!(__train_R[0]))||__train_R[0];
E[8] = (__CheckVariables(__train_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__train_A5())||E[0];
if (E[8]) {
__AppendToList(__train_EmittedList,4);
}
E[9] = E[7]&&E[8];
if (E[9]) {
__AppendToList(__train_EmittedList,7);
}
if (E[9]) {
__CheckVariables(__train_CheckArray[41]);__train_A41();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A41\n");
#endif
}
E[10] = E[9]&&(__CheckVariables(__train_CheckArray[54]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 54\n"),
#endif
__train_A54());
E[2] = (E[2]&&!(E[3]))||E[10];
E[11] = E[2]&&(__CheckVariables(__train_CheckArray[55]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 55\n"),
#endif
__train_A55());
E[12] = E[11]&&(__CheckVariables(__train_CheckArray[56]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 56\n"),
#endif
__train_A56());
if (E[12]) {
__CheckVariables(__train_CheckArray[42]);__train_A42();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A42\n");
#endif
}
E[13] = E[11]&&!(E[12]);
if (E[13]) {
__CheckVariables(__train_CheckArray[43]);__train_A43();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A43\n");
#endif
}
E[11] = E[12]||E[13]||(E[2]&&!(E[11]));
if (E[11]) {
__CheckVariables(__train_CheckArray[44]);__train_A44();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A44\n");
#endif
}
E[7] = E[7]&&!(E[8]);
E[2] = E[7]&&(__CheckVariables(__train_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__train_A1());
E[14] = E[2]&&(__CheckVariables(__train_CheckArray[46]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 46\n"),
#endif
__train_A46());
if (E[14]) {
__CheckVariables(__train_CheckArray[24]);__train_A24();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A24\n");
#endif
}
if (E[14]) {
__CheckVariables(__train_CheckArray[25]);__train_A25();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A25\n");
#endif
}
E[2] = E[14]||(E[2]&&!(E[14]));
E[15] = E[2]&&(__CheckVariables(__train_CheckArray[47]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 47\n"),
#endif
__train_A47());
if (E[15]) {
__CheckVariables(__train_CheckArray[26]);__train_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A26\n");
#endif
}
if (E[15]) {
__CheckVariables(__train_CheckArray[27]);__train_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A27\n");
#endif
}
E[2] = E[15]||(E[2]&&!(E[15]));
E[16] = E[2]&&(__CheckVariables(__train_CheckArray[48]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 48\n"),
#endif
__train_A48());
if (E[16]) {
__CheckVariables(__train_CheckArray[28]);__train_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A28\n");
#endif
}
if (E[16]) {
__CheckVariables(__train_CheckArray[29]);__train_A29();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A29\n");
#endif
}
E[2] = E[16]||(E[2]&&!(E[16]));
if (E[2]) {
__CheckVariables(__train_CheckArray[30]);__train_A30();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A30\n");
#endif
}
E[7] = E[7]&&!((__CheckVariables(__train_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__train_A1()));
E[7] = E[2]||E[7];
E[17] = E[7]&&E[1];
if (E[17]) {
__CheckVariables(__train_CheckArray[31]);__train_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A31\n");
#endif
}
if (E[17]) {
__CheckVariables(__train_CheckArray[32]);__train_A32();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A32\n");
#endif
}
if (E[17]) {
__CheckVariables(__train_CheckArray[33]);__train_A33();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A33\n");
#endif
}
E[7] = E[17]||(E[7]&&!(E[1]));
E[18] = E[7]&&(__CheckVariables(__train_CheckArray[49]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 49\n"),
#endif
__train_A49());
E[19] = E[18]&&(__CheckVariables(__train_CheckArray[50]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 50\n"),
#endif
__train_A50());
if (E[19]) {
__CheckVariables(__train_CheckArray[34]);__train_A34();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A34\n");
#endif
}
E[20] = E[18]&&!(E[19]);
if (E[20]) {
__CheckVariables(__train_CheckArray[35]);__train_A35();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A35\n");
#endif
}
E[18] = E[19]||E[20]||(E[7]&&!(E[18]));
E[7] = E[18]&&(__CheckVariables(__train_CheckArray[51]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 51\n"),
#endif
__train_A51());
E[21] = E[7]&&(__CheckVariables(__train_CheckArray[52]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 52\n"),
#endif
__train_A52());
if (E[21]) {
__CheckVariables(__train_CheckArray[36]);__train_A36();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A36\n");
#endif
}
E[22] = E[7]&&!(E[21]);
if (E[22]) {
__CheckVariables(__train_CheckArray[37]);__train_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A37\n");
#endif
}
E[7] = E[21]||E[22]||(E[18]&&!(E[7]));
if (E[7]) {
__CheckVariables(__train_CheckArray[38]);__train_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A38\n");
#endif
}
E[18] = (__CheckVariables(__train_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__train_A3())||E[11]||E[7];
if (E[18]) {
__AppendToList(__train_EmittedList,2);
}
if (E[18]) {
__CheckVariables(__train_CheckArray[8]);__train_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A8\n");
#endif
}
E[23] = (__train_R[3]&&!(__train_R[0]))||__train_R[0];
E[24] = E[23]&&!(E[8]);
E[25] = (__CheckVariables(__train_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__train_A1())||E[1];
E[26] = E[24]&&E[25];
if (E[7]) {
__CheckVariables(__train_CheckArray[39]);__train_A39();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A39\n");
#endif
}
E[27] = E[7]&&(__CheckVariables(__train_CheckArray[53]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 53\n"),
#endif
__train_A53());
E[28] = (__CheckVariables(__train_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__train_A4())||E[26]||E[27];
if (E[28]) {
__AppendToList(__train_EmittedList,3);
}
if (E[28]) {
__CheckVariables(__train_CheckArray[9]);__train_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A9\n");
#endif
}
if (E[8]) {
__CheckVariables(__train_CheckArray[10]);__train_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A10\n");
#endif
}
if (__train_R[0]) {
__CheckVariables(__train_CheckArray[16]);__train_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A16\n");
#endif
}
E[29] = (__train_R[1]&&!(__train_R[0]))||__train_R[0];
E[30] = E[29]&&E[28];
if (E[30]) {
__CheckVariables(__train_CheckArray[17]);__train_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A17\n");
#endif
}
E[29] = E[30]||(E[29]&&!(E[28]));
if (E[29]) {
__CheckVariables(__train_CheckArray[18]);__train_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A18\n");
#endif
}
E[31] = E[29]&&(__CheckVariables(__train_CheckArray[45]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 45\n"),
#endif
__train_A45());
if (E[31]) {
__AppendToList(__train_EmittedList,5);
}
E[23] = E[23]&&E[8];
if (E[23]) {
__AppendToList(__train_EmittedList,6);
}
E[10] = E[3]||(E[9]&&!(E[10]));
E[3] = __train_R[2]||__train_R[1];
E[32] = __train_R[5]||__train_R[4];
E[33] = E[3]||__train_R[3]||E[32];
E[3] = (E[33]&&!(E[3]))||E[0];
E[34] = (E[33]&&!(__train_R[3]))||E[23];
E[32] = (E[33]&&!(E[32]))||E[10];
E[10] = (E[0]||E[23]||E[10])&&E[3]&&E[34]&&E[32];
__train_R[1] = E[29]&&!(E[31]);
__train_R[3] = E[26]||(E[24]&&!(E[25]));
if (E[27]) {
__CheckVariables(__train_CheckArray[40]);__train_A40();
#ifdef TRACE_ACTION
fprintf(stderr, "__train_A40\n");
#endif
}
__train_R[4] = E[27]||(E[7]&&!(E[27]));
E[25] = E[11]||__train_R[4];
E[25] = (E[31]||__train_R[1]||__train_R[3]||E[25])&&(E[3]||E[31]||__train_R[1])&&(E[34]||__train_R[3])&&(E[32]||E[25]);
__train_R[0] = !(_true);
if (__train_R[1]) { __AppendToList(__train_HaltList,1); }
__train_R[2] = E[31];
if (__train_R[2]) { __AppendToList(__train_HaltList,2); }
if (__train_R[3]) { __AppendToList(__train_HaltList,3); }
if (__train_R[4]) { __AppendToList(__train_HaltList,4); }
__train_R[5] = E[11];
if (__train_R[5]) { __AppendToList(__train_HaltList,5); }
if (!E[25]) { __AppendToList(__train_HaltList,0); }
__ResetModuleEntryAfterReaction();
__train_ModuleData.awaited_list = __train_AllAwaitedList;
__train__reset_input();
return E[25];
}

/* AUTOMATON RESET */

int train_reset () {
__train_ModuleData.awaited_list = __train_AwaitedList;
__ResetModuleEntry();
__train_ModuleData.awaited_list = __train_AllAwaitedList;
__train_ModuleData.state = 0;
__train_R[0] = _true;
__train_R[1] = _false;
__train_R[2] = _false;
__train_R[3] = _false;
__train_R[4] = _false;
__train_R[5] = _false;
__train__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__train_ModuleData
};

/* sscc : C CODE OF SORTED EQUATIONS radar1 - SIMULATION MODE */

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
#define __radar1_GENERIC_TEST(TEST) return TEST;
typedef void (*__radar1_APF)();
static __radar1_APF *__radar1_PActionArray;
static int **__radar1_PCheckArray;
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
static integer vmax_initiale = 130;

/* MEMORY ALLOCATION */

static integer __radar1_V0;
static boolean __radar1_V1;
static integer __radar1_V2;
static integer __radar1_V3;
static integer __radar1_V4;
static boolean __radar1_V5;
static integer __radar1_V6;
static integer __radar1_V7;
static integer __radar1_V8;
static integer __radar1_V9;
static boolean __radar1_V10;
static boolean __radar1_V11;
static boolean __radar1_V12;
static integer __radar1_V13;
static integer __radar1_V14;
static integer __radar1_V15;

static unsigned short __radar1_HaltList[10];
static unsigned short __radar1_AwaitedList[16];
static unsigned short __radar1_EmittedList[16];
static unsigned short __radar1_StartedList[1];
static unsigned short __radar1_KilledList[1];
static unsigned short __radar1_SuspendedList[1];
static unsigned short __radar1_ActiveList[1];
static unsigned short __radar1_AllAwaitedList[16]={5,0,3,8,9,10};


/* INPUT FUNCTIONS */

void radar1_I_V (integer __V) {
__WriteVariable(0);
__radar1_V0 = __V;
__radar1_V1 = _true;
}
void radar1_IS_V (string __V) {
__WriteVariable(0);
_text_to_integer(&__radar1_V0,__V);
__radar1_V1 = _true;
}
void radar1_I_N (integer __V) {
__WriteVariable(4);
__radar1_V4 = __V;
__radar1_V5 = _true;
}
void radar1_IS_N (string __V) {
__WriteVariable(4);
_text_to_integer(&__radar1_V4,__V);
__radar1_V5 = _true;
}
void radar1_I_CONFIG (integer __V) {
__WriteVariable(9);
__radar1_V9 = __V;
__radar1_V10 = _true;
}
void radar1_IS_CONFIG (string __V) {
__WriteVariable(9);
_text_to_integer(&__radar1_V9,__V);
__radar1_V10 = _true;
}
void radar1_I_JOUR () {
__radar1_V11 = _true;
}
void radar1_IS_JOUR () {
__radar1_V11 = _true;
}
void radar1_I_NUIT () {
__radar1_V12 = _true;
}
void radar1_IS_NUIT () {
__radar1_V12 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int radar1_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __radar1_A1 () {
__radar1_GENERIC_TEST(__radar1_V1);
}
static int __radar1_Check1 [] = {1,0,0};
static int __radar1_A2 () {
__radar1_GENERIC_TEST(__radar1_V5);
}
static int __radar1_Check2 [] = {1,0,0};
static int __radar1_A3 () {
__radar1_GENERIC_TEST(__radar1_V10);
}
static int __radar1_Check3 [] = {1,0,0};
static int __radar1_A4 () {
__radar1_GENERIC_TEST(__radar1_V11);
}
static int __radar1_Check4 [] = {1,0,0};
static int __radar1_A5 () {
__radar1_GENERIC_TEST(__radar1_V12);
}
static int __radar1_Check5 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __radar1_A6 () {
#ifdef __OUTPUT
radar1_O_D(__radar1_V2);
#endif
__AppendToList(__radar1_EmittedList,1);
}
static int __radar1_Check6 [] = {1,0,0};
static void __radar1_A7 () {
#ifdef __OUTPUT
radar1_O_RECORD_V(__radar1_V3);
#endif
__AppendToList(__radar1_EmittedList,2);
}
static int __radar1_Check7 [] = {1,0,0};
static void __radar1_A8 () {
#ifdef __OUTPUT
radar1_O_RECORD_N(__radar1_V6);
#endif
__AppendToList(__radar1_EmittedList,4);
}
static int __radar1_Check8 [] = {1,0,0};
static void __radar1_A9 () {
#ifdef __OUTPUT
radar1_O_PV(__radar1_V7);
#endif
__AppendToList(__radar1_EmittedList,5);
}
static int __radar1_Check9 [] = {1,0,0};
static void __radar1_A10 () {
#ifdef __OUTPUT
radar1_O_F();
#endif
__AppendToList(__radar1_EmittedList,6);
}
static int __radar1_Check10 [] = {1,0,0};
static void __radar1_A11 () {
#ifdef __OUTPUT
radar1_O_POL(__radar1_V8);
#endif
__AppendToList(__radar1_EmittedList,7);
}
static int __radar1_Check11 [] = {1,0,0};

/* ASSIGNMENTS */

static void __radar1_A12 () {
__radar1_V1 = _false;
}
static int __radar1_Check12 [] = {1,0,1,1};
static void __radar1_A13 () {
__radar1_V5 = _false;
}
static int __radar1_Check13 [] = {1,0,1,5};
static void __radar1_A14 () {
__radar1_V10 = _false;
}
static int __radar1_Check14 [] = {1,0,1,10};
static void __radar1_A15 () {
__radar1_V11 = _false;
}
static int __radar1_Check15 [] = {1,0,1,11};
static void __radar1_A16 () {
__radar1_V12 = _false;
}
static int __radar1_Check16 [] = {1,0,1,12};
static void __radar1_A17 () {
__radar1_V13 = vmax_initiale;
}
static int __radar1_Check17 [] = {1,0,1,13};
static void __radar1_A18 () {
__radar1_V13 = __radar1_V9;
}
static int __radar1_Check18 [] = {1,1,9,1,13};
static void __radar1_A19 () {
__radar1_V2 = __radar1_V0;
}
static int __radar1_Check19 [] = {1,1,0,1,2};
static void __radar1_A20 () {
__radar1_V14 = 0;
}
static int __radar1_Check20 [] = {1,0,1,14};
static void __radar1_A21 () {
__radar1_V14 = __radar1_V14+1;
}
static int __radar1_Check21 [] = {1,1,14,1,14};
static void __radar1_A22 () {
__radar1_V3 = __radar1_V0;
}
static int __radar1_Check22 [] = {1,1,0,1,3};
static void __radar1_A23 () {
__radar1_V6 = __radar1_V4;
}
static int __radar1_Check23 [] = {1,1,4,1,6};
static void __radar1_A24 () {
__radar1_V7 = __radar1_V4;
}
static int __radar1_Check24 [] = {1,1,4,1,7};
static void __radar1_A25 () {
__radar1_V15 = vmax_initiale;
}
static int __radar1_Check25 [] = {1,0,1,15};
static void __radar1_A26 () {
__radar1_V15 = __radar1_V9;
}
static int __radar1_Check26 [] = {1,1,9,1,15};
static void __radar1_A27 () {
__radar1_V8 = __radar1_V4;
}
static int __radar1_Check27 [] = {1,1,4,1,8};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __radar1_A28 () {
__radar1_GENERIC_TEST(__radar1_V0>__radar1_V13);
}
static int __radar1_Check28 [] = {1,2,0,13,0};
static int __radar1_A29 () {
__radar1_GENERIC_TEST(__radar1_V14>30);
}
static int __radar1_Check29 [] = {1,1,14,0};
static int __radar1_A30 () {
__radar1_GENERIC_TEST(__radar1_V0>(__radar1_V15+50));
}
static int __radar1_Check30 [] = {1,2,0,15,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __radar1_A31 () {
;
__ResetVariable(0);
}
static int __radar1_Check31 [] = {1,0,0};
static void __radar1_A32 () {
;
__ResetVariable(2);
}
static int __radar1_Check32 [] = {1,0,0};
static void __radar1_A33 () {
;
__ResetVariable(3);
}
static int __radar1_Check33 [] = {1,0,0};
static void __radar1_A34 () {
;
__ResetVariable(4);
}
static int __radar1_Check34 [] = {1,0,0};
static void __radar1_A35 () {
;
__ResetVariable(6);
}
static int __radar1_Check35 [] = {1,0,0};
static void __radar1_A36 () {
;
__ResetVariable(7);
}
static int __radar1_Check36 [] = {1,0,0};
static void __radar1_A37 () {
;
__ResetVariable(8);
}
static int __radar1_Check37 [] = {1,0,0};
static void __radar1_A38 () {
;
__ResetVariable(9);
}
static int __radar1_Check38 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__radar1_CheckArray[] = {
0,
__radar1_Check1,
__radar1_Check2,
__radar1_Check3,
__radar1_Check4,
__radar1_Check5,
__radar1_Check6,
__radar1_Check7,
__radar1_Check8,
__radar1_Check9,
__radar1_Check10,
__radar1_Check11,
__radar1_Check12,
__radar1_Check13,
__radar1_Check14,
__radar1_Check15,
__radar1_Check16,
__radar1_Check17,
__radar1_Check18,
__radar1_Check19,
__radar1_Check20,
__radar1_Check21,
__radar1_Check22,
__radar1_Check23,
__radar1_Check24,
__radar1_Check25,
__radar1_Check26,
__radar1_Check27,
__radar1_Check28,
__radar1_Check29,
__radar1_Check30,
__radar1_Check31,
__radar1_Check32,
__radar1_Check33,
__radar1_Check34,
__radar1_Check35,
__radar1_Check36,
__radar1_Check37,
__radar1_Check38
};
static int **__radar1_PCheckArray =  __radar1_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void radar1_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __radar1_show_variable (int __V) {
extern struct __VariableEntry __radar1_VariableTable[];
struct __VariableEntry* p_var = &__radar1_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __radar1_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __radar1_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __radar1_InstanceTable [] = {
{"radar1",0,"","radar2.strl",{1,6,1,0},{1,28,1,0},{0,0,0,0}},
{"detect",0,"","detect.strl",{1,1,1,1},{1,28,1,1},{1,20,1,0}},
{"record",0,"","record.strl",{1,1,1,2},{1,30,1,2},{1,22,1,0}},
{"flash",0,"","flash.strl",{1,1,1,3},{1,14,1,3},{1,24,1,0}},
{"police",0,"","police.strl",{1,1,1,4},{1,31,1,4},{1,26,1,0}},
};

struct __SignalEntry __radar1_SignalTable [] = {
{"V",1,0,0,{1,7,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"D",2,2,0,{1,8,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RECORD_V",2,3,0,{1,9,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"N",1,4,0,{1,10,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RECORD_N",2,6,0,{1,11,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PV",2,7,0,{1,12,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"F",34,0,0,{1,13,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"POL",2,8,0,{1,14,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CONFIG",1,9,0,{1,15,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"JOUR",33,0,0,{1,16,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"NUIT",33,0,0,{1,17,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,11,8,1},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_FIN_RECORD",48,0,0,{1,10,6,2},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,12,8,2},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,14,8,4},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __radar1_InputTable [] = {
{"V",86,"integer",0,-3,0,0,_check_integer,radar1_IS_V,0,{1,7,8,0}},
{"N",78,"integer",0,-3,0,3,_check_integer,radar1_IS_N,0,{1,10,8,0}},
{"CONFIG",34,"integer",0,-3,0,8,_check_integer,radar1_IS_CONFIG,0,{1,15,8,0}},
{"JOUR",17,0,0,-1,0,9,0,radar1_IS_JOUR,0,{1,16,8,0}},
{"NUIT",17,0,0,-1,0,10,0,radar1_IS_NUIT,0,{1,17,8,0}}};

struct __VariableEntry __radar1_VariableTable [] = {
{"__radar1_V0","V0","integer",-3,1,0,(char*)&__radar1_V0,"V",0,0,0,{1,7,8,0}},
{"__radar1_V1","V1","boolean",-2,2,0,(char*)&__radar1_V1,"V",0,0,0,{1,7,8,0}},
{"__radar1_V2","V2","integer",-3,1,0,(char*)&__radar1_V2,"D",0,0,0,{1,8,8,0}},
{"__radar1_V3","V3","integer",-3,1,0,(char*)&__radar1_V3,"RECORD_V",0,0,0,{1,9,8,0}},
{"__radar1_V4","V4","integer",-3,1,0,(char*)&__radar1_V4,"N",0,0,0,{1,10,8,0}},
{"__radar1_V5","V5","boolean",-2,2,0,(char*)&__radar1_V5,"N",0,0,0,{1,10,8,0}},
{"__radar1_V6","V6","integer",-3,1,0,(char*)&__radar1_V6,"RECORD_N",0,0,0,{1,11,8,0}},
{"__radar1_V7","V7","integer",-3,1,0,(char*)&__radar1_V7,"PV",0,0,0,{1,12,8,0}},
{"__radar1_V8","V8","integer",-3,1,0,(char*)&__radar1_V8,"POL",0,0,0,{1,14,8,0}},
{"__radar1_V9","V9","integer",-3,1,0,(char*)&__radar1_V9,"CONFIG",0,0,0,{1,15,8,0}},
{"__radar1_V10","V10","boolean",-2,2,0,(char*)&__radar1_V10,"CONFIG",0,0,0,{1,15,8,0}},
{"__radar1_V11","V11","boolean",-2,2,0,(char*)&__radar1_V11,"JOUR",0,0,0,{1,16,8,0}},
{"__radar1_V12","V12","boolean",-2,2,0,(char*)&__radar1_V12,"NUIT",0,0,0,{1,17,8,0}},
{"__radar1_V13","V13","integer",-3,0,0,(char*)&__radar1_V13,"vmax",0,0,0,{1,9,5,1}},
{"__radar1_V14","V14","integer",-3,0,0,(char*)&__radar1_V14,"cptJours",0,0,0,{1,9,5,2}},
{"__radar1_V15","V15","integer",-3,0,0,(char*)&__radar1_V15,"vmax",0,0,0,{1,12,5,4}}
};

struct __HaltEntry __radar1_HaltTable [] = {
{{1,28,1,0}},
{{1,12,3,1}},
{{1,10,1,1}},
{{1,13,3,2}},
{{1,11,1,2}},
{{1,11,3,3}},
{{1,9,1,3}},
{{1,15,3,4}},
{{1,13,1,4}}
};


static void __radar1__reset_input () {
__radar1_V1 = _false;
__radar1_V5 = _false;
__radar1_V10 = _false;
__radar1_V11 = _false;
__radar1_V12 = _false;
}


/* MODULE DATA FOR SIMULATION */

int radar1();
int radar1_reset();

static struct __ModuleEntry __radar1_ModuleData = {
"Simulation interface release 5","radar1",
5,0,15,5,0,0,6,0,4,0,0,16,0,9,0,0,0,
__radar1_HaltList,
__radar1_AwaitedList,
__radar1_EmittedList,
__radar1_StartedList,
__radar1_KilledList,
__radar1_SuspendedList,
__radar1_ActiveList,
0,0,
radar1_initialize,radar1,radar1_reset,
__radar1_show_variable,__radar1_set_variable,__radar1_check_value,0,
__radar1_InstanceTable,
0,
__radar1_SignalTable,__radar1_InputTable,0,
0,0,
__radar1_VariableTable,
0,
__radar1_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __radar1_R[9] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int radar1 () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[39];

__radar1_ModuleData.awaited_list = __radar1_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __radar1_R[2]||__radar1_R[1];
E[1] = E[0]&&!(__radar1_R[0]);
E[2] = E[1]&&!((__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5()));
E[3] = __radar1_R[1]&&E[2];
E[4] = (__CheckVariables(__radar1_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radar1_A1())||(__CheckVariables(__radar1_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radar1_A3())||(__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4());
E[5] = E[3]&&E[4];
E[6] = E[5]&&!((__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4()));
E[7] = E[6]&&(__CheckVariables(__radar1_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radar1_A3());
if (E[7]) {
__CheckVariables(__radar1_CheckArray[18]);__radar1_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A18\n");
#endif
}
E[6] = E[6]&&!((__CheckVariables(__radar1_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radar1_A3()));
E[6] = E[7]||E[6];
E[8] = E[6]&&(__CheckVariables(__radar1_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radar1_A1());
E[9] = E[8]&&(__CheckVariables(__radar1_CheckArray[28]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 28\n"),
#endif
__radar1_A28());
if (E[9]) {
__AppendToList(__radar1_EmittedList,1);
}
if (E[9]) {
__CheckVariables(__radar1_CheckArray[19]);__radar1_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A19\n");
#endif
}
if (E[9]) {
__CheckVariables(__radar1_CheckArray[6]);__radar1_A6();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A6\n");
#endif
}
E[10] = __radar1_R[4]||__radar1_R[3];
E[11] = E[10]&&!(__radar1_R[0]);
E[12] = E[11]&&!((__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5()));
E[13] = __radar1_R[3]&&E[12];
E[14] = (__CheckVariables(__radar1_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radar1_A1())||(__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4());
E[15] = E[13]&&E[14];
E[16] = E[15]&&!((__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4()));
E[17] = E[16]&&(__CheckVariables(__radar1_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radar1_A1());
if (E[17]) {
__AppendToList(__radar1_EmittedList,2);
__AppendToList(__radar1_EmittedList,4);
}
if (E[17]) {
__CheckVariables(__radar1_CheckArray[22]);__radar1_A22();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A22\n");
#endif
}
if (E[17]) {
__CheckVariables(__radar1_CheckArray[7]);__radar1_A7();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A7\n");
#endif
}
if (E[17]) {
__CheckVariables(__radar1_CheckArray[23]);__radar1_A23();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A23\n");
#endif
}
if (E[17]) {
__CheckVariables(__radar1_CheckArray[8]);__radar1_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A8\n");
#endif
}
E[18] = __radar1_R[0]&&!((__CheckVariables(__radar1_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radar1_A1()));
if (E[18]) {
__CheckVariables(__radar1_CheckArray[31]);__radar1_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A31\n");
#endif
}
E[19] = __radar1_R[0]&&!((__CheckVariables(__radar1_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radar1_A2()));
if (E[19]) {
__CheckVariables(__radar1_CheckArray[34]);__radar1_A34();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A34\n");
#endif
}
E[20] = __radar1_R[0]&&!((__CheckVariables(__radar1_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radar1_A3()));
if (E[20]) {
__CheckVariables(__radar1_CheckArray[38]);__radar1_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A38\n");
#endif
}
if (__radar1_R[0]) {
__CheckVariables(__radar1_CheckArray[32]);__radar1_A32();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A32\n");
#endif
}
if (__radar1_R[0]) {
__CheckVariables(__radar1_CheckArray[33]);__radar1_A33();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A33\n");
#endif
}
if (__radar1_R[0]) {
__CheckVariables(__radar1_CheckArray[35]);__radar1_A35();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A35\n");
#endif
}
if (__radar1_R[0]) {
__CheckVariables(__radar1_CheckArray[36]);__radar1_A36();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A36\n");
#endif
}
if (__radar1_R[0]) {
__CheckVariables(__radar1_CheckArray[37]);__radar1_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A37\n");
#endif
}
E[21] = __radar1_R[6]||__radar1_R[5];
E[22] = E[21]&&!(__radar1_R[0]);
E[23] = (__radar1_R[0]&&E[9])||(E[22]&&E[9]);
if (E[23]) {
__AppendToList(__radar1_EmittedList,6);
}
E[24] = E[23]&&(__CheckVariables(__radar1_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radar1_A2());
E[22] = E[22]&&!(E[9]);
E[25] = __radar1_R[5]&&E[22];
E[26] = E[25]&&(__CheckVariables(__radar1_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radar1_A2());
E[26] = E[24]||E[26];
if (E[26]) {
__AppendToList(__radar1_EmittedList,5);
}
if (E[26]) {
__CheckVariables(__radar1_CheckArray[24]);__radar1_A24();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A24\n");
#endif
}
if (E[26]) {
__CheckVariables(__radar1_CheckArray[9]);__radar1_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A9\n");
#endif
}
if (E[23]) {
__CheckVariables(__radar1_CheckArray[10]);__radar1_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A10\n");
#endif
}
E[24] = __radar1_R[8]||__radar1_R[7];
E[27] = E[24]&&!(__radar1_R[0]);
E[28] = E[27]&&!((__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5()));
E[29] = __radar1_R[7]&&E[28];
E[30] = E[26]||(__CheckVariables(__radar1_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radar1_A3())||(__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4());
E[31] = E[29]&&E[30];
E[32] = E[31]&&!((__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4()));
E[33] = E[32]&&(__CheckVariables(__radar1_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radar1_A3());
if (E[33]) {
__CheckVariables(__radar1_CheckArray[26]);__radar1_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A26\n");
#endif
}
E[32] = E[32]&&!((__CheckVariables(__radar1_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radar1_A3()));
E[32] = E[33]||E[32];
E[34] = E[32]&&E[26];
E[35] = E[34]&&(__CheckVariables(__radar1_CheckArray[30]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 30\n"),
#endif
__radar1_A30());
if (E[35]) {
__AppendToList(__radar1_EmittedList,7);
}
if (E[35]) {
__CheckVariables(__radar1_CheckArray[27]);__radar1_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A27\n");
#endif
}
if (E[35]) {
__CheckVariables(__radar1_CheckArray[11]);__radar1_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A11\n");
#endif
}
E[5] = E[5]&&(__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4());
if (E[5]) {
__AppendToList(__radar1_EmittedList,11);
}
E[15] = E[15]&&(__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4());
if (E[15]) {
__CheckVariables(__radar1_CheckArray[21]);__radar1_A21();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A21\n");
#endif
}
E[36] = E[15]&&(__CheckVariables(__radar1_CheckArray[29]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 29\n"),
#endif
__radar1_A29());
if (E[36]) {
__AppendToList(__radar1_EmittedList,12);
}
if (E[15]&&!(E[36])) {
__AppendToList(__radar1_EmittedList,13);
}
E[31] = E[31]&&(__CheckVariables(__radar1_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radar1_A4());
if (E[31]) {
__AppendToList(__radar1_EmittedList,14);
}
E[37] = !(_true);
E[1] = E[1]&&(__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5());
if (__radar1_R[0]) {
__CheckVariables(__radar1_CheckArray[17]);__radar1_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A17\n");
#endif
}
E[38] = __radar1_R[0]&&(__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5());
E[6] = E[6]&&!((__CheckVariables(__radar1_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radar1_A1()));
__radar1_R[1] = E[1]||E[38]||E[9]||(E[8]&&!(E[9]))||E[6]||(__radar1_R[1]&&E[3]&&!(E[4]));
E[4] = __radar1_R[0]&&!((__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5()));
__radar1_R[2] = E[5]||(__radar1_R[2]&&E[2])||E[4];
E[11] = E[11]&&(__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5());
if (__radar1_R[0]) {
__CheckVariables(__radar1_CheckArray[20]);__radar1_A20();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A20\n");
#endif
}
E[4] = __radar1_R[0]&&(__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5());
E[16] = E[16]&&!((__CheckVariables(__radar1_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radar1_A1()));
E[14] = E[11]||E[4]||E[17]||E[16]||(__radar1_R[3]&&E[13]&&!(E[14]));
E[13] = __radar1_R[0]&&!((__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5()));
__radar1_R[4] = (E[15]&&!(E[36]))||(__radar1_R[4]&&E[12])||E[13];
E[13] = E[14]||__radar1_R[4];
__radar1_R[6] = E[26]||(__radar1_R[6]&&E[22])||(__radar1_R[0]&&!(E[9]));
E[22] = E[23]&&!((__CheckVariables(__radar1_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radar1_A2()));
E[25] = E[25]&&!((__CheckVariables(__radar1_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radar1_A2()));
__radar1_R[5] = E[22]||(__radar1_R[5]&&E[25]);
E[27] = E[27]&&(__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5());
if (__radar1_R[0]) {
__CheckVariables(__radar1_CheckArray[25]);__radar1_A25();
#ifdef TRACE_ACTION
fprintf(stderr, "__radar1_A25\n");
#endif
}
E[25] = __radar1_R[0]&&(__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5());
__radar1_R[7] = E[27]||E[25]||E[35]||(E[34]&&!(E[35]))||(E[32]&&!(E[26]))||(__radar1_R[7]&&E[29]&&!(E[30]));
E[30] = __radar1_R[0]&&!((__CheckVariables(__radar1_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radar1_A5()));
__radar1_R[8] = E[31]||(__radar1_R[8]&&E[28])||E[30];
E[30] = E[0]||E[10]||E[21]||E[24];
E[24] = (__radar1_R[1]||__radar1_R[2]||E[13]||__radar1_R[6]||__radar1_R[5]||__radar1_R[7]||__radar1_R[8])&&((E[30]&&!(E[0]))||__radar1_R[1]||__radar1_R[2])&&((E[30]&&!(E[10]))||E[36]||E[13])&&((E[30]&&!(E[21]))||__radar1_R[6]||__radar1_R[5])&&((E[30]&&!(E[24]))||__radar1_R[7]||__radar1_R[8]);
__radar1_R[3] = E[14]&&!(E[36]);
__radar1_R[0] = !(_true);
if (__radar1_R[1]) { __AppendToList(__radar1_HaltList,1); }
if (__radar1_R[2]) { __AppendToList(__radar1_HaltList,2); }
if (__radar1_R[3]) { __AppendToList(__radar1_HaltList,3); }
if (__radar1_R[4]) { __AppendToList(__radar1_HaltList,4); }
if (__radar1_R[5]) { __AppendToList(__radar1_HaltList,5); }
if (__radar1_R[6]) { __AppendToList(__radar1_HaltList,6); }
if (__radar1_R[7]) { __AppendToList(__radar1_HaltList,7); }
if (__radar1_R[8]) { __AppendToList(__radar1_HaltList,8); }
if (!E[24]) { __AppendToList(__radar1_HaltList,0); }
__ResetModuleEntryAfterReaction();
__radar1_ModuleData.awaited_list = __radar1_AllAwaitedList;
__radar1__reset_input();
return E[24];
}

/* AUTOMATON RESET */

int radar1_reset () {
__radar1_ModuleData.awaited_list = __radar1_AwaitedList;
__ResetModuleEntry();
__radar1_ModuleData.awaited_list = __radar1_AllAwaitedList;
__radar1_ModuleData.state = 0;
__radar1_R[0] = _true;
__radar1_R[1] = _false;
__radar1_R[2] = _false;
__radar1_R[3] = _false;
__radar1_R[4] = _false;
__radar1_R[5] = _false;
__radar1_R[6] = _false;
__radar1_R[7] = _false;
__radar1_R[8] = _false;
__radar1__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__radar1_ModuleData
};

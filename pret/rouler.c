/* sscc : C CODE OF SORTED EQUATIONS rouler - SIMULATION MODE */

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
#define __rouler_GENERIC_TEST(TEST) return TEST;
typedef void (*__rouler_APF)();
static __rouler_APF *__rouler_PActionArray;
static int **__rouler_PCheckArray;
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
static integer MAX = 3;

/* MEMORY ALLOCATION */

static boolean __rouler_V0;
static boolean __rouler_V1;
static boolean __rouler_V2;
static boolean __rouler_V3;
static boolean __rouler_V4;
static boolean __rouler_V5;
static boolean __rouler_V6;
static boolean __rouler_V7;
static boolean __rouler_V8;
static integer __rouler_V9;
static integer __rouler_V10;

static unsigned short __rouler_HaltList[8];
static unsigned short __rouler_AwaitedList[12];
static unsigned short __rouler_EmittedList[12];
static unsigned short __rouler_StartedList[1];
static unsigned short __rouler_KilledList[1];
static unsigned short __rouler_SuspendedList[1];
static unsigned short __rouler_ActiveList[1];
static unsigned short __rouler_AllAwaitedList[12]={9,0,1,2,3,4,5,6,7,8};


/* INPUT FUNCTIONS */

void rouler_I_TOUCH () {
__rouler_V0 = _true;
}
void rouler_IS_TOUCH () {
__rouler_V0 = _true;
}
void rouler_I_ARRET () {
__rouler_V1 = _true;
}
void rouler_IS_ARRET () {
__rouler_V1 = _true;
}
void rouler_I_G () {
__rouler_V2 = _true;
}
void rouler_IS_G () {
__rouler_V2 = _true;
}
void rouler_I_D () {
__rouler_V3 = _true;
}
void rouler_IS_D () {
__rouler_V3 = _true;
}
void rouler_I_G_Avance () {
__rouler_V4 = _true;
}
void rouler_IS_G_Avance () {
__rouler_V4 = _true;
}
void rouler_I_D_Avance () {
__rouler_V5 = _true;
}
void rouler_IS_D_Avance () {
__rouler_V5 = _true;
}
void rouler_I_G_Stop () {
__rouler_V6 = _true;
}
void rouler_IS_G_Stop () {
__rouler_V6 = _true;
}
void rouler_I_D_Stop () {
__rouler_V7 = _true;
}
void rouler_IS_D_Stop () {
__rouler_V7 = _true;
}
void rouler_I_SOS () {
__rouler_V8 = _true;
}
void rouler_IS_SOS () {
__rouler_V8 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int rouler_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __rouler_A1 () {
__rouler_GENERIC_TEST(__rouler_V0);
}
static int __rouler_Check1 [] = {1,0,0};
static int __rouler_A2 () {
__rouler_GENERIC_TEST(__rouler_V1);
}
static int __rouler_Check2 [] = {1,0,0};
static int __rouler_A3 () {
__rouler_GENERIC_TEST(__rouler_V2);
}
static int __rouler_Check3 [] = {1,0,0};
static int __rouler_A4 () {
__rouler_GENERIC_TEST(__rouler_V3);
}
static int __rouler_Check4 [] = {1,0,0};
static int __rouler_A5 () {
__rouler_GENERIC_TEST(__rouler_V4);
}
static int __rouler_Check5 [] = {1,0,0};
static int __rouler_A6 () {
__rouler_GENERIC_TEST(__rouler_V5);
}
static int __rouler_Check6 [] = {1,0,0};
static int __rouler_A7 () {
__rouler_GENERIC_TEST(__rouler_V6);
}
static int __rouler_Check7 [] = {1,0,0};
static int __rouler_A8 () {
__rouler_GENERIC_TEST(__rouler_V7);
}
static int __rouler_Check8 [] = {1,0,0};
static int __rouler_A9 () {
__rouler_GENERIC_TEST(__rouler_V8);
}
static int __rouler_Check9 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __rouler_A10 () {
#ifdef __OUTPUT
rouler_O_TOUCH();
#endif
__AppendToList(__rouler_EmittedList,0);
}
static int __rouler_Check10 [] = {1,0,0};
static void __rouler_A11 () {
#ifdef __OUTPUT
rouler_O_ARRET();
#endif
__AppendToList(__rouler_EmittedList,1);
}
static int __rouler_Check11 [] = {1,0,0};
static void __rouler_A12 () {
#ifdef __OUTPUT
rouler_O_G_Avance();
#endif
__AppendToList(__rouler_EmittedList,4);
}
static int __rouler_Check12 [] = {1,0,0};
static void __rouler_A13 () {
#ifdef __OUTPUT
rouler_O_D_Avance();
#endif
__AppendToList(__rouler_EmittedList,5);
}
static int __rouler_Check13 [] = {1,0,0};
static void __rouler_A14 () {
#ifdef __OUTPUT
rouler_O_G_Stop();
#endif
__AppendToList(__rouler_EmittedList,6);
}
static int __rouler_Check14 [] = {1,0,0};
static void __rouler_A15 () {
#ifdef __OUTPUT
rouler_O_D_Stop();
#endif
__AppendToList(__rouler_EmittedList,7);
}
static int __rouler_Check15 [] = {1,0,0};
static void __rouler_A16 () {
#ifdef __OUTPUT
rouler_O_SOS();
#endif
__AppendToList(__rouler_EmittedList,8);
}
static int __rouler_Check16 [] = {1,0,0};

/* ASSIGNMENTS */

static void __rouler_A17 () {
__rouler_V0 = _false;
}
static int __rouler_Check17 [] = {1,0,1,0};
static void __rouler_A18 () {
__rouler_V1 = _false;
}
static int __rouler_Check18 [] = {1,0,1,1};
static void __rouler_A19 () {
__rouler_V2 = _false;
}
static int __rouler_Check19 [] = {1,0,1,2};
static void __rouler_A20 () {
__rouler_V3 = _false;
}
static int __rouler_Check20 [] = {1,0,1,3};
static void __rouler_A21 () {
__rouler_V4 = _false;
}
static int __rouler_Check21 [] = {1,0,1,4};
static void __rouler_A22 () {
__rouler_V5 = _false;
}
static int __rouler_Check22 [] = {1,0,1,5};
static void __rouler_A23 () {
__rouler_V6 = _false;
}
static int __rouler_Check23 [] = {1,0,1,6};
static void __rouler_A24 () {
__rouler_V7 = _false;
}
static int __rouler_Check24 [] = {1,0,1,7};
static void __rouler_A25 () {
__rouler_V8 = _false;
}
static int __rouler_Check25 [] = {1,0,1,8};
static void __rouler_A26 () {
__rouler_V9 = MAX;
}
static int __rouler_Check26 [] = {1,0,1,9};
static void __rouler_A27 () {
__rouler_V10 = MAX;
}
static int __rouler_Check27 [] = {1,0,1,10};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __rouler_A28 () {
__rouler_GENERIC_TEST(__rouler_V9>0);
}
static int __rouler_Check28 [] = {1,1,9,0};
static int __rouler_A29 () {
__rouler_GENERIC_TEST(__rouler_V10>0);
}
static int __rouler_Check29 [] = {1,1,10,0};

/* DECREMENTS */

static int __rouler_A30 () {
__rouler_GENERIC_TEST(__DSZ(__rouler_V9));
}
static int __rouler_Check30 [] = {1,1,9,1,9};
static int __rouler_A31 () {
__rouler_GENERIC_TEST(__DSZ(__rouler_V10));
}
static int __rouler_Check31 [] = {1,1,10,1,10};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

/* ACTION SEQUENCES */


static int *__rouler_CheckArray[] = {
0,
__rouler_Check1,
__rouler_Check2,
__rouler_Check3,
__rouler_Check4,
__rouler_Check5,
__rouler_Check6,
__rouler_Check7,
__rouler_Check8,
__rouler_Check9,
__rouler_Check10,
__rouler_Check11,
__rouler_Check12,
__rouler_Check13,
__rouler_Check14,
__rouler_Check15,
__rouler_Check16,
__rouler_Check17,
__rouler_Check18,
__rouler_Check19,
__rouler_Check20,
__rouler_Check21,
__rouler_Check22,
__rouler_Check23,
__rouler_Check24,
__rouler_Check25,
__rouler_Check26,
__rouler_Check27,
__rouler_Check28,
__rouler_Check29,
__rouler_Check30,
__rouler_Check31
};
static int **__rouler_PCheckArray =  __rouler_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void rouler_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __rouler_show_variable (int __V) {
extern struct __VariableEntry __rouler_VariableTable[];
struct __VariableEntry* p_var = &__rouler_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __rouler_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __rouler_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __rouler_InstanceTable [] = {
{"rouler",0,"","rouler.strl",{1,6,1,0},{1,43,1,0},{0,0,0,0}},
};

struct __SignalEntry __rouler_SignalTable [] = {
{"TOUCH",35,0,0,{1,8,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"ARRET",35,0,0,{1,9,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"G",33,0,0,{1,10,7,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"D",33,0,0,{1,10,10,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"G_Avance",35,0,0,{1,11,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"D_Avance",35,0,0,{1,11,23,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"G_Stop",35,0,0,{1,12,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"D_Stop",35,0,0,{1,12,21,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"SOS",35,0,0,{1,13,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_SOS",48,0,0,{1,17,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_ARRET",48,0,0,{1,17,17,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __rouler_InputTable [] = {
{"TOUCH",84,0,0,-1,0,0,0,rouler_IS_TOUCH,0,{1,8,13,0}},
{"ARRET",79,0,0,-1,0,1,0,rouler_IS_ARRET,0,{1,9,13,0}},
{"G",71,0,0,-1,0,2,0,rouler_IS_G,0,{1,10,7,0}},
{"D",68,0,0,-1,0,3,0,rouler_IS_D,0,{1,10,10,0}},
{"G_Avance",49,0,0,-1,0,4,0,rouler_IS_G_Avance,0,{1,11,13,0}},
{"D_Avance",46,0,0,-1,0,5,0,rouler_IS_D_Avance,0,{1,11,23,0}},
{"G_Stop",83,0,0,-1,0,6,0,rouler_IS_G_Stop,0,{1,12,13,0}},
{"D_Stop",80,0,0,-1,0,7,0,rouler_IS_D_Stop,0,{1,12,21,0}},
{"SOS",43,0,0,-1,0,8,0,rouler_IS_SOS,0,{1,13,13,0}}};

struct __VariableEntry __rouler_VariableTable [] = {
{"__rouler_V0","V0","boolean",-2,2,0,(char*)&__rouler_V0,"TOUCH",0,0,0,{1,8,13,0}},
{"__rouler_V1","V1","boolean",-2,2,0,(char*)&__rouler_V1,"ARRET",0,0,0,{1,9,13,0}},
{"__rouler_V2","V2","boolean",-2,2,0,(char*)&__rouler_V2,"G",0,0,0,{1,10,7,0}},
{"__rouler_V3","V3","boolean",-2,2,0,(char*)&__rouler_V3,"D",0,0,0,{1,10,10,0}},
{"__rouler_V4","V4","boolean",-2,2,0,(char*)&__rouler_V4,"G_Avance",0,0,0,{1,11,13,0}},
{"__rouler_V5","V5","boolean",-2,2,0,(char*)&__rouler_V5,"D_Avance",0,0,0,{1,11,23,0}},
{"__rouler_V6","V6","boolean",-2,2,0,(char*)&__rouler_V6,"G_Stop",0,0,0,{1,12,13,0}},
{"__rouler_V7","V7","boolean",-2,2,0,(char*)&__rouler_V7,"D_Stop",0,0,0,{1,12,21,0}},
{"__rouler_V8","V8","boolean",-2,2,0,(char*)&__rouler_V8,"SOS",0,0,0,{1,13,13,0}},
{"__rouler_V9","V9","integer",-3,3,0,(char*)&__rouler_V9,"0",0,0,0,{1,25,14,0}},
{"__rouler_V10","V10","integer",-3,3,0,(char*)&__rouler_V10,"0",0,0,0,{1,30,14,0}}
};

struct __HaltEntry __rouler_HaltTable [] = {
{{1,43,1,0}},
{{1,15,1,0}},
{{1,25,24,0}},
{{1,30,24,0}},
{{1,33,5,0}},
{{1,36,5,0}},
{{1,41,1,0}}
};


static void __rouler__reset_input () {
__rouler_V0 = _false;
__rouler_V1 = _false;
__rouler_V2 = _false;
__rouler_V3 = _false;
__rouler_V4 = _false;
__rouler_V5 = _false;
__rouler_V6 = _false;
__rouler_V7 = _false;
__rouler_V8 = _false;
}


/* MODULE DATA FOR SIMULATION */

int rouler();
int rouler_reset();

static struct __ModuleEntry __rouler_ModuleData = {
"Simulation interface release 5","rouler",
1,0,11,9,0,0,7,0,2,0,0,11,0,7,0,0,0,
__rouler_HaltList,
__rouler_AwaitedList,
__rouler_EmittedList,
__rouler_StartedList,
__rouler_KilledList,
__rouler_SuspendedList,
__rouler_ActiveList,
0,0,
rouler_initialize,rouler,rouler_reset,
__rouler_show_variable,__rouler_set_variable,__rouler_check_value,0,
__rouler_InstanceTable,
0,
__rouler_SignalTable,__rouler_InputTable,0,
0,0,
__rouler_VariableTable,
0,
__rouler_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __rouler_R[7] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false};

/* AUTOMATON ENGINE */

int rouler () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[25];

__rouler_ModuleData.awaited_list = __rouler_AwaitedList;
__ResetModuleEntryBeforeReaction();
if ((__CheckVariables(__rouler_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__rouler_A1())) {
__CheckVariables(__rouler_CheckArray[10]);__rouler_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A10\n");
#endif
}
if ((__CheckVariables(__rouler_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__rouler_A2())) {
__CheckVariables(__rouler_CheckArray[11]);__rouler_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A11\n");
#endif
}
E[0] = __rouler_R[6]||__rouler_R[5]||__rouler_R[2]||__rouler_R[3]||__rouler_R[4];
E[1] = E[0]&&!(__rouler_R[0]);
E[2] = E[1]&&(__CheckVariables(__rouler_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__rouler_A1());
E[3] = __rouler_R[0]&&(__CheckVariables(__rouler_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__rouler_A1());
E[4] = __rouler_R[1]&&!(__rouler_R[0]);
E[5] = E[4]&&(__CheckVariables(__rouler_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__rouler_A1());
E[5] = E[2]||E[3]||E[5];
E[1] = E[1]&&!((__CheckVariables(__rouler_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__rouler_A1()));
E[3] = __rouler_R[2]&&E[1];
E[2] = E[3]&&(__CheckVariables(__rouler_CheckArray[30]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 30\n"),
#endif
__rouler_A30());
E[6] = (__rouler_R[4]&&E[1])||E[5];
E[7] = E[6]&&!((__CheckVariables(__rouler_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__rouler_A2()));
E[8] = !((__CheckVariables(__rouler_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__rouler_A3()))&&!((__CheckVariables(__rouler_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__rouler_A4()));
E[9] = E[7]&&!(E[8]);
E[10] = (__CheckVariables(__rouler_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__rouler_A3())&&!((__CheckVariables(__rouler_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__rouler_A4()));
E[11] = E[9]&&E[10];
if (E[11]) {
__CheckVariables(__rouler_CheckArray[26]);__rouler_A26();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A26\n");
#endif
}
E[12] = E[11]&&(__CheckVariables(__rouler_CheckArray[28]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 28\n"),
#endif
__rouler_A28());
E[13] = E[2]||(E[11]&&!(E[12]));
E[14] = (__CheckVariables(__rouler_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__rouler_A5())||E[5]||E[13];
if (E[14]) {
__AppendToList(__rouler_EmittedList,4);
}
if (E[14]) {
__CheckVariables(__rouler_CheckArray[12]);__rouler_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A12\n");
#endif
}
E[15] = __rouler_R[3]&&E[1];
E[16] = E[15]&&(__CheckVariables(__rouler_CheckArray[31]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 31\n"),
#endif
__rouler_A31());
E[10] = E[13]||(E[9]&&!(E[10]));
E[9] = (__CheckVariables(__rouler_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__rouler_A4())&&!((__CheckVariables(__rouler_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__rouler_A3()));
E[13] = E[10]&&E[9];
if (E[13]) {
__CheckVariables(__rouler_CheckArray[27]);__rouler_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A27\n");
#endif
}
E[17] = E[13]&&(__CheckVariables(__rouler_CheckArray[29]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 29\n"),
#endif
__rouler_A29());
E[18] = E[16]||(E[13]&&!(E[17]));
E[5] = (__CheckVariables(__rouler_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__rouler_A6())||E[5]||E[18];
if (E[5]) {
__AppendToList(__rouler_EmittedList,5);
}
if (E[5]) {
__CheckVariables(__rouler_CheckArray[13]);__rouler_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A13\n");
#endif
}
E[6] = E[6]&&(__CheckVariables(__rouler_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__rouler_A2());
if (E[6]) {
__AppendToList(__rouler_EmittedList,10);
}
E[8] = E[7]&&E[8];
if (E[8]) {
__AppendToList(__rouler_EmittedList,9);
}
E[7] = E[6]||E[8];
E[19] = E[7]&&E[6];
E[20] = (__CheckVariables(__rouler_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__rouler_A7())||E[19]||E[11];
if (E[20]) {
__AppendToList(__rouler_EmittedList,6);
}
if (E[20]) {
__CheckVariables(__rouler_CheckArray[14]);__rouler_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A14\n");
#endif
}
E[21] = (__CheckVariables(__rouler_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__rouler_A8())||E[19]||E[13];
if (E[21]) {
__AppendToList(__rouler_EmittedList,7);
}
if (E[21]) {
__CheckVariables(__rouler_CheckArray[15]);__rouler_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A15\n");
#endif
}
E[22] = (E[7]&&E[8])||(__rouler_R[5]&&E[1]);
E[23] = (__CheckVariables(__rouler_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__rouler_A9())||E[22];
if (E[23]) {
__AppendToList(__rouler_EmittedList,8);
}
if (E[23]) {
__CheckVariables(__rouler_CheckArray[16]);__rouler_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__rouler_A16\n");
#endif
}
E[24] = !(_true);
E[8] = E[7]&&!(E[8]);
E[6] = E[7]&&!(E[6]);
E[7] = __rouler_R[5]||E[19]||E[6];
__rouler_R[6] = ((E[8]||E[19]||E[6])&&E[8]&&E[7])||(__rouler_R[6]&&E[1]);
__rouler_R[2] = E[12]||(E[3]&&!(E[2]));
__rouler_R[3] = E[17]||(E[15]&&!(E[16]));
__rouler_R[4] = E[18]||(E[10]&&!(E[9]));
E[9] = __rouler_R[0]&&!((__CheckVariables(__rouler_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__rouler_A1()));
E[4] = E[4]&&!((__CheckVariables(__rouler_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__rouler_A1()));
E[4] = E[9]||(__rouler_R[1]&&E[4]);
E[7] = __rouler_R[6]||(E[22]&&(E[8]||E[22])&&E[7])||__rouler_R[2]||__rouler_R[3]||__rouler_R[4]||E[4];
E[0] = E[0]||__rouler_R[1];
__rouler_R[0] = !(_true);
__rouler_R[1] = E[4];
if (__rouler_R[1]) { __AppendToList(__rouler_HaltList,1); }
if (__rouler_R[2]) { __AppendToList(__rouler_HaltList,2); }
if (__rouler_R[3]) { __AppendToList(__rouler_HaltList,3); }
if (__rouler_R[4]) { __AppendToList(__rouler_HaltList,4); }
__rouler_R[5] = E[22];
if (__rouler_R[5]) { __AppendToList(__rouler_HaltList,5); }
if (__rouler_R[6]) { __AppendToList(__rouler_HaltList,6); }
if (!E[7]) { __AppendToList(__rouler_HaltList,0); }
__ResetModuleEntryAfterReaction();
__rouler_ModuleData.awaited_list = __rouler_AllAwaitedList;
__rouler__reset_input();
return E[7];
}

/* AUTOMATON RESET */

int rouler_reset () {
__rouler_ModuleData.awaited_list = __rouler_AwaitedList;
__ResetModuleEntry();
__rouler_ModuleData.awaited_list = __rouler_AllAwaitedList;
__rouler_ModuleData.state = 0;
__rouler_R[0] = _true;
__rouler_R[1] = _false;
__rouler_R[2] = _false;
__rouler_R[3] = _false;
__rouler_R[4] = _false;
__rouler_R[5] = _false;
__rouler_R[6] = _false;
__rouler__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__rouler_ModuleData
};

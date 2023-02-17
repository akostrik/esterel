/* sscc : C CODE OF SORTED EQUATIONS detect - SIMULATION MODE */

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
#define __detect_GENERIC_TEST(TEST) return TEST;
typedef void (*__detect_APF)();
static __detect_APF *__detect_PActionArray;
static int **__detect_PCheckArray;
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

static integer __detect_V0;
static boolean __detect_V1;
static integer __detect_V2;
static integer __detect_V3;
static boolean __detect_V4;
static boolean __detect_V5;
static boolean __detect_V6;
static integer __detect_V7;

static unsigned short __detect_HaltList[4];
static unsigned short __detect_AwaitedList[7];
static unsigned short __detect_EmittedList[7];
static unsigned short __detect_StartedList[1];
static unsigned short __detect_KilledList[1];
static unsigned short __detect_SuspendedList[1];
static unsigned short __detect_ActiveList[1];
static unsigned short __detect_AllAwaitedList[7]={4,0,2,3,4};


/* INPUT FUNCTIONS */

void detect_I_V (integer __V) {
__WriteVariable(0);
__detect_V0 = __V;
__detect_V1 = _true;
}
void detect_IS_V (string __V) {
__WriteVariable(0);
_text_to_integer(&__detect_V0,__V);
__detect_V1 = _true;
}
void detect_I_CONFIG (integer __V) {
__WriteVariable(3);
__detect_V3 = __V;
__detect_V4 = _true;
}
void detect_IS_CONFIG (string __V) {
__WriteVariable(3);
_text_to_integer(&__detect_V3,__V);
__detect_V4 = _true;
}
void detect_I_JOUR () {
__detect_V5 = _true;
}
void detect_IS_JOUR () {
__detect_V5 = _true;
}
void detect_I_NUIT () {
__detect_V6 = _true;
}
void detect_IS_NUIT () {
__detect_V6 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int detect_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __detect_A1 () {
__detect_GENERIC_TEST(__detect_V1);
}
static int __detect_Check1 [] = {1,0,0};
static int __detect_A2 () {
__detect_GENERIC_TEST(__detect_V4);
}
static int __detect_Check2 [] = {1,0,0};
static int __detect_A3 () {
__detect_GENERIC_TEST(__detect_V5);
}
static int __detect_Check3 [] = {1,0,0};
static int __detect_A4 () {
__detect_GENERIC_TEST(__detect_V6);
}
static int __detect_Check4 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __detect_A5 () {
#ifdef __OUTPUT
detect_O_D(__detect_V2);
#endif
__AppendToList(__detect_EmittedList,1);
}
static int __detect_Check5 [] = {1,0,0};

/* ASSIGNMENTS */

static void __detect_A6 () {
__detect_V1 = _false;
}
static int __detect_Check6 [] = {1,0,1,1};
static void __detect_A7 () {
__detect_V4 = _false;
}
static int __detect_Check7 [] = {1,0,1,4};
static void __detect_A8 () {
__detect_V5 = _false;
}
static int __detect_Check8 [] = {1,0,1,5};
static void __detect_A9 () {
__detect_V6 = _false;
}
static int __detect_Check9 [] = {1,0,1,6};
static void __detect_A10 () {
__detect_V7 = vmax_initiale;
}
static int __detect_Check10 [] = {1,0,1,7};
static void __detect_A11 () {
__detect_V7 = __detect_V3;
}
static int __detect_Check11 [] = {1,1,3,1,7};
static void __detect_A12 () {
__detect_V2 = __detect_V0;
}
static int __detect_Check12 [] = {1,1,0,1,2};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __detect_A13 () {
__detect_GENERIC_TEST(__detect_V0>__detect_V7);
}
static int __detect_Check13 [] = {1,2,0,7,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __detect_A14 () {
;
__ResetVariable(0);
}
static int __detect_Check14 [] = {1,0,0};
static void __detect_A15 () {
;
__ResetVariable(2);
}
static int __detect_Check15 [] = {1,0,0};
static void __detect_A16 () {
;
__ResetVariable(3);
}
static int __detect_Check16 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__detect_CheckArray[] = {
0,
__detect_Check1,
__detect_Check2,
__detect_Check3,
__detect_Check4,
__detect_Check5,
__detect_Check6,
__detect_Check7,
__detect_Check8,
__detect_Check9,
__detect_Check10,
__detect_Check11,
__detect_Check12,
__detect_Check13,
__detect_Check14,
__detect_Check15,
__detect_Check16
};
static int **__detect_PCheckArray =  __detect_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void detect_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __detect_show_variable (int __V) {
extern struct __VariableEntry __detect_VariableTable[];
struct __VariableEntry* p_var = &__detect_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __detect_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __detect_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __detect_InstanceTable [] = {
{"detect",0,"","detect.strl",{1,1,1,0},{1,28,1,0},{0,0,0,0}},
};

struct __SignalEntry __detect_SignalTable [] = {
{"V",1,0,0,{1,2,7,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"D",2,2,0,{1,3,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CONFIG",1,3,0,{1,4,7,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"JOUR",33,0,0,{1,5,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"NUIT",33,0,0,{1,6,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,11,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __detect_InputTable [] = {
{"V",86,"integer",0,-3,0,0,_check_integer,detect_IS_V,0,{1,2,7,0}},
{"CONFIG",34,"integer",0,-3,0,2,_check_integer,detect_IS_CONFIG,0,{1,4,7,0}},
{"JOUR",17,0,0,-1,0,3,0,detect_IS_JOUR,0,{1,5,8,0}},
{"NUIT",17,0,0,-1,0,4,0,detect_IS_NUIT,0,{1,6,8,0}}};

struct __VariableEntry __detect_VariableTable [] = {
{"__detect_V0","V0","integer",-3,1,0,(char*)&__detect_V0,"V",0,0,0,{1,2,7,0}},
{"__detect_V1","V1","boolean",-2,2,0,(char*)&__detect_V1,"V",0,0,0,{1,2,7,0}},
{"__detect_V2","V2","integer",-3,1,0,(char*)&__detect_V2,"D",0,0,0,{1,3,8,0}},
{"__detect_V3","V3","integer",-3,1,0,(char*)&__detect_V3,"CONFIG",0,0,0,{1,4,7,0}},
{"__detect_V4","V4","boolean",-2,2,0,(char*)&__detect_V4,"CONFIG",0,0,0,{1,4,7,0}},
{"__detect_V5","V5","boolean",-2,2,0,(char*)&__detect_V5,"JOUR",0,0,0,{1,5,8,0}},
{"__detect_V6","V6","boolean",-2,2,0,(char*)&__detect_V6,"NUIT",0,0,0,{1,6,8,0}},
{"__detect_V7","V7","integer",-3,0,0,(char*)&__detect_V7,"vmax",0,0,0,{1,9,5,0}}
};

struct __HaltEntry __detect_HaltTable [] = {
{{1,28,1,0}},
{{1,12,3,0}},
{{1,10,1,0}}
};


static void __detect__reset_input () {
__detect_V1 = _false;
__detect_V4 = _false;
__detect_V5 = _false;
__detect_V6 = _false;
}


/* MODULE DATA FOR SIMULATION */

int detect();
int detect_reset();

static struct __ModuleEntry __detect_ModuleData = {
"Simulation interface release 5","detect",
1,0,6,4,0,0,1,0,1,0,0,8,0,3,0,0,0,
__detect_HaltList,
__detect_AwaitedList,
__detect_EmittedList,
__detect_StartedList,
__detect_KilledList,
__detect_SuspendedList,
__detect_ActiveList,
0,0,
detect_initialize,detect,detect_reset,
__detect_show_variable,__detect_set_variable,__detect_check_value,0,
__detect_InstanceTable,
0,
__detect_SignalTable,__detect_InputTable,0,
0,0,
__detect_VariableTable,
0,
__detect_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __detect_R[3] = {_true,
 _false,
 _false};

/* AUTOMATON ENGINE */

int detect () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[13];

__detect_ModuleData.awaited_list = __detect_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = (__detect_R[2]||__detect_R[1])&&!(__detect_R[0]);
E[1] = E[0]&&!((__CheckVariables(__detect_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__detect_A4()));
E[2] = __detect_R[1]&&E[1];
E[3] = (__CheckVariables(__detect_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__detect_A1())||(__CheckVariables(__detect_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__detect_A2())||(__CheckVariables(__detect_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__detect_A3());
E[4] = E[2]&&E[3];
E[5] = E[4]&&!((__CheckVariables(__detect_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__detect_A3()));
E[6] = E[5]&&(__CheckVariables(__detect_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__detect_A2());
if (E[6]) {
__CheckVariables(__detect_CheckArray[11]);__detect_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__detect_A11\n");
#endif
}
E[5] = E[5]&&!((__CheckVariables(__detect_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__detect_A2()));
E[5] = E[6]||E[5];
E[7] = E[5]&&(__CheckVariables(__detect_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__detect_A1());
E[8] = E[7]&&(__CheckVariables(__detect_CheckArray[13]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 13\n"),
#endif
__detect_A13());
if (E[8]) {
__AppendToList(__detect_EmittedList,1);
}
if (E[8]) {
__CheckVariables(__detect_CheckArray[12]);__detect_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__detect_A12\n");
#endif
}
if (E[8]) {
__CheckVariables(__detect_CheckArray[5]);__detect_A5();
#ifdef TRACE_ACTION
fprintf(stderr, "__detect_A5\n");
#endif
}
E[4] = E[4]&&(__CheckVariables(__detect_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__detect_A3());
if (E[4]) {
__AppendToList(__detect_EmittedList,5);
}
E[9] = __detect_R[0]&&!((__CheckVariables(__detect_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__detect_A1()));
if (E[9]) {
__CheckVariables(__detect_CheckArray[14]);__detect_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__detect_A14\n");
#endif
}
if (__detect_R[0]) {
__CheckVariables(__detect_CheckArray[15]);__detect_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__detect_A15\n");
#endif
}
E[10] = __detect_R[0]&&!((__CheckVariables(__detect_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__detect_A2()));
if (E[10]) {
__CheckVariables(__detect_CheckArray[16]);__detect_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__detect_A16\n");
#endif
}
E[11] = !(_true);
E[0] = E[0]&&(__CheckVariables(__detect_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__detect_A4());
if (__detect_R[0]) {
__CheckVariables(__detect_CheckArray[10]);__detect_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__detect_A10\n");
#endif
}
E[12] = __detect_R[0]&&(__CheckVariables(__detect_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__detect_A4());
E[5] = E[5]&&!((__CheckVariables(__detect_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__detect_A1()));
__detect_R[1] = E[0]||E[12]||E[8]||(E[7]&&!(E[8]))||E[5]||(__detect_R[1]&&E[2]&&!(E[3]));
E[3] = __detect_R[0]&&!((__CheckVariables(__detect_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__detect_A4()));
__detect_R[2] = E[4]||(__detect_R[2]&&E[1])||E[3];
E[3] = __detect_R[1]||__detect_R[2];
__detect_R[0] = !(_true);
if (__detect_R[1]) { __AppendToList(__detect_HaltList,1); }
if (__detect_R[2]) { __AppendToList(__detect_HaltList,2); }
if (!E[3]) { __AppendToList(__detect_HaltList,0); }
__ResetModuleEntryAfterReaction();
__detect_ModuleData.awaited_list = __detect_AllAwaitedList;
__detect__reset_input();
return E[3];
}

/* AUTOMATON RESET */

int detect_reset () {
__detect_ModuleData.awaited_list = __detect_AwaitedList;
__ResetModuleEntry();
__detect_ModuleData.awaited_list = __detect_AllAwaitedList;
__detect_ModuleData.state = 0;
__detect_R[0] = _true;
__detect_R[1] = _false;
__detect_R[2] = _false;
__detect__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__detect_ModuleData
};

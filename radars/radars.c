/* sscc : C CODE OF SORTED EQUATIONS radars - SIMULATION MODE */

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
#define __radars_GENERIC_TEST(TEST) return TEST;
typedef void (*__radars_APF)();
static __radars_APF *__radars_PActionArray;
static int **__radars_PCheckArray;
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

static integer __radars_V0;
static boolean __radars_V1;
static integer __radars_V2;
static boolean __radars_V3;
static integer __radars_V4;
static integer __radars_V5;
static integer __radars_V6;
static integer __radars_V7;
static integer __radars_V8;
static boolean __radars_V9;
static integer __radars_V10;
static boolean __radars_V11;
static integer __radars_V12;
static integer __radars_V13;
static integer __radars_V14;
static integer __radars_V15;
static integer __radars_V16;
static integer __radars_V17;
static integer __radars_V18;
static boolean __radars_V19;
static boolean __radars_V20;
static boolean __radars_V21;
static integer __radars_V22;
static integer __radars_V23;
static integer __radars_V24;
static integer __radars_V25;
static integer __radars_V26;
static integer __radars_V27;

static unsigned short __radars_HaltList[18];
static unsigned short __radars_AwaitedList[28];
static unsigned short __radars_EmittedList[28];
static unsigned short __radars_StartedList[1];
static unsigned short __radars_KilledList[1];
static unsigned short __radars_SuspendedList[1];
static unsigned short __radars_ActiveList[1];
static unsigned short __radars_AllAwaitedList[28]={7,0,1,6,7,16,17,18};


/* INPUT FUNCTIONS */

void radars_I_V1 (integer __V) {
__WriteVariable(0);
__radars_V0 = __V;
__radars_V1 = _true;
}
void radars_IS_V1 (string __V) {
__WriteVariable(0);
_text_to_integer(&__radars_V0,__V);
__radars_V1 = _true;
}
void radars_I_V2 (integer __V) {
__WriteVariable(2);
__radars_V2 = __V;
__radars_V3 = _true;
}
void radars_IS_V2 (string __V) {
__WriteVariable(2);
_text_to_integer(&__radars_V2,__V);
__radars_V3 = _true;
}
void radars_I_N1 (integer __V) {
__WriteVariable(8);
__radars_V8 = __V;
__radars_V9 = _true;
}
void radars_IS_N1 (string __V) {
__WriteVariable(8);
_text_to_integer(&__radars_V8,__V);
__radars_V9 = _true;
}
void radars_I_N2 (integer __V) {
__WriteVariable(10);
__radars_V10 = __V;
__radars_V11 = _true;
}
void radars_IS_N2 (string __V) {
__WriteVariable(10);
_text_to_integer(&__radars_V10,__V);
__radars_V11 = _true;
}
void radars_I_CONFIG (integer __V) {
__WriteVariable(18);
__radars_V18 = __V;
__radars_V19 = _true;
}
void radars_IS_CONFIG (string __V) {
__WriteVariable(18);
_text_to_integer(&__radars_V18,__V);
__radars_V19 = _true;
}
void radars_I_JOUR () {
__radars_V20 = _true;
}
void radars_IS_JOUR () {
__radars_V20 = _true;
}
void radars_I_NUIT () {
__radars_V21 = _true;
}
void radars_IS_NUIT () {
__radars_V21 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int radars_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __radars_A1 () {
__radars_GENERIC_TEST(__radars_V1);
}
static int __radars_Check1 [] = {1,0,0};
static int __radars_A2 () {
__radars_GENERIC_TEST(__radars_V3);
}
static int __radars_Check2 [] = {1,0,0};
static int __radars_A3 () {
__radars_GENERIC_TEST(__radars_V9);
}
static int __radars_Check3 [] = {1,0,0};
static int __radars_A4 () {
__radars_GENERIC_TEST(__radars_V11);
}
static int __radars_Check4 [] = {1,0,0};
static int __radars_A5 () {
__radars_GENERIC_TEST(__radars_V19);
}
static int __radars_Check5 [] = {1,0,0};
static int __radars_A6 () {
__radars_GENERIC_TEST(__radars_V20);
}
static int __radars_Check6 [] = {1,0,0};
static int __radars_A7 () {
__radars_GENERIC_TEST(__radars_V21);
}
static int __radars_Check7 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __radars_A8 () {
#ifdef __OUTPUT
radars_O_D1(__radars_V4);
#endif
__AppendToList(__radars_EmittedList,2);
}
static int __radars_Check8 [] = {1,0,0};
static void __radars_A9 () {
#ifdef __OUTPUT
radars_O_D2(__radars_V5);
#endif
__AppendToList(__radars_EmittedList,3);
}
static int __radars_Check9 [] = {1,0,0};
static void __radars_A10 () {
#ifdef __OUTPUT
radars_O_RECORD_V1(__radars_V6);
#endif
__AppendToList(__radars_EmittedList,4);
}
static int __radars_Check10 [] = {1,0,0};
static void __radars_A11 () {
#ifdef __OUTPUT
radars_O_RECORD_V2(__radars_V7);
#endif
__AppendToList(__radars_EmittedList,5);
}
static int __radars_Check11 [] = {1,0,0};
static void __radars_A12 () {
#ifdef __OUTPUT
radars_O_RECORD_N1(__radars_V12);
#endif
__AppendToList(__radars_EmittedList,8);
}
static int __radars_Check12 [] = {1,0,0};
static void __radars_A13 () {
#ifdef __OUTPUT
radars_O_RECORD_N2(__radars_V13);
#endif
__AppendToList(__radars_EmittedList,9);
}
static int __radars_Check13 [] = {1,0,0};
static void __radars_A14 () {
#ifdef __OUTPUT
radars_O_PV1(__radars_V14);
#endif
__AppendToList(__radars_EmittedList,10);
}
static int __radars_Check14 [] = {1,0,0};
static void __radars_A15 () {
#ifdef __OUTPUT
radars_O_PV2(__radars_V15);
#endif
__AppendToList(__radars_EmittedList,11);
}
static int __radars_Check15 [] = {1,0,0};
static void __radars_A16 () {
#ifdef __OUTPUT
radars_O_F1();
#endif
__AppendToList(__radars_EmittedList,12);
}
static int __radars_Check16 [] = {1,0,0};
static void __radars_A17 () {
#ifdef __OUTPUT
radars_O_F2();
#endif
__AppendToList(__radars_EmittedList,13);
}
static int __radars_Check17 [] = {1,0,0};
static void __radars_A18 () {
#ifdef __OUTPUT
radars_O_POL1(__radars_V16);
#endif
__AppendToList(__radars_EmittedList,14);
}
static int __radars_Check18 [] = {1,0,0};
static void __radars_A19 () {
#ifdef __OUTPUT
radars_O_POL2(__radars_V17);
#endif
__AppendToList(__radars_EmittedList,15);
}
static int __radars_Check19 [] = {1,0,0};

/* ASSIGNMENTS */

static void __radars_A20 () {
__radars_V1 = _false;
}
static int __radars_Check20 [] = {1,0,1,1};
static void __radars_A21 () {
__radars_V3 = _false;
}
static int __radars_Check21 [] = {1,0,1,3};
static void __radars_A22 () {
__radars_V9 = _false;
}
static int __radars_Check22 [] = {1,0,1,9};
static void __radars_A23 () {
__radars_V11 = _false;
}
static int __radars_Check23 [] = {1,0,1,11};
static void __radars_A24 () {
__radars_V19 = _false;
}
static int __radars_Check24 [] = {1,0,1,19};
static void __radars_A25 () {
__radars_V20 = _false;
}
static int __radars_Check25 [] = {1,0,1,20};
static void __radars_A26 () {
__radars_V21 = _false;
}
static int __radars_Check26 [] = {1,0,1,21};
static void __radars_A27 () {
__radars_V22 = vmax_initiale;
}
static int __radars_Check27 [] = {1,0,1,22};
static void __radars_A28 () {
__radars_V22 = __radars_V18;
}
static int __radars_Check28 [] = {1,1,18,1,22};
static void __radars_A29 () {
__radars_V4 = __radars_V0;
}
static int __radars_Check29 [] = {1,1,0,1,4};
static void __radars_A30 () {
__radars_V23 = 0;
}
static int __radars_Check30 [] = {1,0,1,23};
static void __radars_A31 () {
__radars_V23 = __radars_V23+1;
}
static int __radars_Check31 [] = {1,1,23,1,23};
static void __radars_A32 () {
__radars_V6 = __radars_V0;
}
static int __radars_Check32 [] = {1,1,0,1,6};
static void __radars_A33 () {
__radars_V12 = __radars_V8;
}
static int __radars_Check33 [] = {1,1,8,1,12};
static void __radars_A34 () {
__radars_V14 = __radars_V8;
}
static int __radars_Check34 [] = {1,1,8,1,14};
static void __radars_A35 () {
__radars_V24 = vmax_initiale;
}
static int __radars_Check35 [] = {1,0,1,24};
static void __radars_A36 () {
__radars_V24 = __radars_V18;
}
static int __radars_Check36 [] = {1,1,18,1,24};
static void __radars_A37 () {
__radars_V16 = __radars_V8;
}
static int __radars_Check37 [] = {1,1,8,1,16};
static void __radars_A38 () {
__radars_V25 = vmax_initiale;
}
static int __radars_Check38 [] = {1,0,1,25};
static void __radars_A39 () {
__radars_V25 = __radars_V18;
}
static int __radars_Check39 [] = {1,1,18,1,25};
static void __radars_A40 () {
__radars_V5 = __radars_V2;
}
static int __radars_Check40 [] = {1,1,2,1,5};
static void __radars_A41 () {
__radars_V26 = 0;
}
static int __radars_Check41 [] = {1,0,1,26};
static void __radars_A42 () {
__radars_V26 = __radars_V26+1;
}
static int __radars_Check42 [] = {1,1,26,1,26};
static void __radars_A43 () {
__radars_V7 = __radars_V2;
}
static int __radars_Check43 [] = {1,1,2,1,7};
static void __radars_A44 () {
__radars_V13 = __radars_V10;
}
static int __radars_Check44 [] = {1,1,10,1,13};
static void __radars_A45 () {
__radars_V15 = __radars_V10;
}
static int __radars_Check45 [] = {1,1,10,1,15};
static void __radars_A46 () {
__radars_V27 = vmax_initiale;
}
static int __radars_Check46 [] = {1,0,1,27};
static void __radars_A47 () {
__radars_V27 = __radars_V18;
}
static int __radars_Check47 [] = {1,1,18,1,27};
static void __radars_A48 () {
__radars_V17 = __radars_V10;
}
static int __radars_Check48 [] = {1,1,10,1,17};

/* PROCEDURE CALLS */

/* CONDITIONS */

static int __radars_A49 () {
__radars_GENERIC_TEST(__radars_V0>__radars_V22);
}
static int __radars_Check49 [] = {1,2,0,22,0};
static int __radars_A50 () {
__radars_GENERIC_TEST(__radars_V23>30);
}
static int __radars_Check50 [] = {1,1,23,0};
static int __radars_A51 () {
__radars_GENERIC_TEST(__radars_V0>(__radars_V24+50));
}
static int __radars_Check51 [] = {1,2,0,24,0};
static int __radars_A52 () {
__radars_GENERIC_TEST(__radars_V2>__radars_V25);
}
static int __radars_Check52 [] = {1,2,2,25,0};
static int __radars_A53 () {
__radars_GENERIC_TEST(__radars_V26>30);
}
static int __radars_Check53 [] = {1,1,26,0};
static int __radars_A54 () {
__radars_GENERIC_TEST(__radars_V2>(__radars_V27+50));
}
static int __radars_Check54 [] = {1,2,2,27,0};

/* DECREMENTS */

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __radars_A55 () {
;
__ResetVariable(0);
}
static int __radars_Check55 [] = {1,0,0};
static void __radars_A56 () {
;
__ResetVariable(2);
}
static int __radars_Check56 [] = {1,0,0};
static void __radars_A57 () {
;
__ResetVariable(4);
}
static int __radars_Check57 [] = {1,0,0};
static void __radars_A58 () {
;
__ResetVariable(5);
}
static int __radars_Check58 [] = {1,0,0};
static void __radars_A59 () {
;
__ResetVariable(6);
}
static int __radars_Check59 [] = {1,0,0};
static void __radars_A60 () {
;
__ResetVariable(7);
}
static int __radars_Check60 [] = {1,0,0};
static void __radars_A61 () {
;
__ResetVariable(8);
}
static int __radars_Check61 [] = {1,0,0};
static void __radars_A62 () {
;
__ResetVariable(10);
}
static int __radars_Check62 [] = {1,0,0};
static void __radars_A63 () {
;
__ResetVariable(12);
}
static int __radars_Check63 [] = {1,0,0};
static void __radars_A64 () {
;
__ResetVariable(13);
}
static int __radars_Check64 [] = {1,0,0};
static void __radars_A65 () {
;
__ResetVariable(14);
}
static int __radars_Check65 [] = {1,0,0};
static void __radars_A66 () {
;
__ResetVariable(15);
}
static int __radars_Check66 [] = {1,0,0};
static void __radars_A67 () {
;
__ResetVariable(16);
}
static int __radars_Check67 [] = {1,0,0};
static void __radars_A68 () {
;
__ResetVariable(17);
}
static int __radars_Check68 [] = {1,0,0};
static void __radars_A69 () {
;
__ResetVariable(18);
}
static int __radars_Check69 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__radars_CheckArray[] = {
0,
__radars_Check1,
__radars_Check2,
__radars_Check3,
__radars_Check4,
__radars_Check5,
__radars_Check6,
__radars_Check7,
__radars_Check8,
__radars_Check9,
__radars_Check10,
__radars_Check11,
__radars_Check12,
__radars_Check13,
__radars_Check14,
__radars_Check15,
__radars_Check16,
__radars_Check17,
__radars_Check18,
__radars_Check19,
__radars_Check20,
__radars_Check21,
__radars_Check22,
__radars_Check23,
__radars_Check24,
__radars_Check25,
__radars_Check26,
__radars_Check27,
__radars_Check28,
__radars_Check29,
__radars_Check30,
__radars_Check31,
__radars_Check32,
__radars_Check33,
__radars_Check34,
__radars_Check35,
__radars_Check36,
__radars_Check37,
__radars_Check38,
__radars_Check39,
__radars_Check40,
__radars_Check41,
__radars_Check42,
__radars_Check43,
__radars_Check44,
__radars_Check45,
__radars_Check46,
__radars_Check47,
__radars_Check48,
__radars_Check49,
__radars_Check50,
__radars_Check51,
__radars_Check52,
__radars_Check53,
__radars_Check54,
__radars_Check55,
__radars_Check56,
__radars_Check57,
__radars_Check58,
__radars_Check59,
__radars_Check60,
__radars_Check61,
__radars_Check62,
__radars_Check63,
__radars_Check64,
__radars_Check65,
__radars_Check66,
__radars_Check67,
__radars_Check68,
__radars_Check69
};
static int **__radars_PCheckArray =  __radars_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void radars_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __radars_show_variable (int __V) {
extern struct __VariableEntry __radars_VariableTable[];
struct __VariableEntry* p_var = &__radars_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __radars_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __radars_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __radars_InstanceTable [] = {
{"radars",0,"","radars.strl",{1,7,1,0},{1,32,1,0},{0,0,0,0}},
{"radar1",0,"","radar1.strl",{1,5,1,1},{1,27,1,1},{1,28,1,0}},
{"detect",1,"","detect.strl",{1,1,1,2},{1,28,1,2},{1,19,1,1}},
{"record",1,"","record.strl",{1,1,1,3},{1,30,1,3},{1,21,1,1}},
{"flash",1,"","flash.strl",{1,1,1,4},{1,14,1,4},{1,23,1,1}},
{"police",1,"","police.strl",{1,1,1,5},{1,31,1,5},{1,25,1,1}},
{"radar2",0,"","radar2.strl",{1,1,1,6},{1,23,1,6},{1,30,1,0}},
{"detect",6,"","detect.strl",{1,1,1,7},{1,28,1,7},{1,15,1,6}},
{"record",6,"","record.strl",{1,1,1,8},{1,30,1,8},{1,17,1,6}},
{"flash",6,"","flash.strl",{1,1,1,9},{1,14,1,9},{1,19,1,6}},
{"police",6,"","police.strl",{1,1,1,10},{1,31,1,10},{1,21,1,6}},
};

struct __SignalEntry __radars_SignalTable [] = {
{"V1",1,0,0,{1,8,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"V2",1,2,0,{1,9,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"D1",2,4,0,{1,10,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"D2",2,5,0,{1,11,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RECORD_V1",2,6,0,{1,12,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RECORD_V2",2,7,0,{1,13,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"N1",1,8,0,{1,14,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"N2",1,10,0,{1,15,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RECORD_N1",2,12,0,{1,16,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"RECORD_N2",2,13,0,{1,17,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PV1",2,14,0,{1,18,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PV2",2,15,0,{1,19,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"F1",34,0,0,{1,20,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"F2",34,0,0,{1,21,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"POL1",2,16,0,{1,22,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"POL2",2,17,0,{1,23,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"CONFIG",1,18,0,{1,24,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"JOUR",33,0,0,{1,25,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"NUIT",33,0,0,{1,26,8,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,11,8,2},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_FIN_RECORD",48,0,0,{1,10,6,3},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,12,8,3},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,14,8,5},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,11,8,7},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_FIN_RECORD",48,0,0,{1,10,6,8},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,12,8,8},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"TRAP_JOUR",48,0,0,{1,14,8,10},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __radars_InputTable [] = {
{"V1",34,"integer",0,-3,0,0,_check_integer,radars_IS_V1,0,{1,8,8,0}},
{"V2",35,"integer",0,-3,0,1,_check_integer,radars_IS_V2,0,{1,9,8,0}},
{"N1",26,"integer",0,-3,0,6,_check_integer,radars_IS_N1,0,{1,14,8,0}},
{"N2",27,"integer",0,-3,0,7,_check_integer,radars_IS_N2,0,{1,15,8,0}},
{"CONFIG",34,"integer",0,-3,0,16,_check_integer,radars_IS_CONFIG,0,{1,24,8,0}},
{"JOUR",17,0,0,-1,0,17,0,radars_IS_JOUR,0,{1,25,8,0}},
{"NUIT",17,0,0,-1,0,18,0,radars_IS_NUIT,0,{1,26,8,0}}};

struct __VariableEntry __radars_VariableTable [] = {
{"__radars_V0","V0","integer",-3,1,0,(char*)&__radars_V0,"V1",0,0,0,{1,8,8,0}},
{"__radars_V1","V1","boolean",-2,2,0,(char*)&__radars_V1,"V1",0,0,0,{1,8,8,0}},
{"__radars_V2","V2","integer",-3,1,0,(char*)&__radars_V2,"V2",0,0,0,{1,9,8,0}},
{"__radars_V3","V3","boolean",-2,2,0,(char*)&__radars_V3,"V2",0,0,0,{1,9,8,0}},
{"__radars_V4","V4","integer",-3,1,0,(char*)&__radars_V4,"D1",0,0,0,{1,10,8,0}},
{"__radars_V5","V5","integer",-3,1,0,(char*)&__radars_V5,"D2",0,0,0,{1,11,8,0}},
{"__radars_V6","V6","integer",-3,1,0,(char*)&__radars_V6,"RECORD_V1",0,0,0,{1,12,8,0}},
{"__radars_V7","V7","integer",-3,1,0,(char*)&__radars_V7,"RECORD_V2",0,0,0,{1,13,8,0}},
{"__radars_V8","V8","integer",-3,1,0,(char*)&__radars_V8,"N1",0,0,0,{1,14,8,0}},
{"__radars_V9","V9","boolean",-2,2,0,(char*)&__radars_V9,"N1",0,0,0,{1,14,8,0}},
{"__radars_V10","V10","integer",-3,1,0,(char*)&__radars_V10,"N2",0,0,0,{1,15,8,0}},
{"__radars_V11","V11","boolean",-2,2,0,(char*)&__radars_V11,"N2",0,0,0,{1,15,8,0}},
{"__radars_V12","V12","integer",-3,1,0,(char*)&__radars_V12,"RECORD_N1",0,0,0,{1,16,8,0}},
{"__radars_V13","V13","integer",-3,1,0,(char*)&__radars_V13,"RECORD_N2",0,0,0,{1,17,8,0}},
{"__radars_V14","V14","integer",-3,1,0,(char*)&__radars_V14,"PV1",0,0,0,{1,18,8,0}},
{"__radars_V15","V15","integer",-3,1,0,(char*)&__radars_V15,"PV2",0,0,0,{1,19,8,0}},
{"__radars_V16","V16","integer",-3,1,0,(char*)&__radars_V16,"POL1",0,0,0,{1,22,8,0}},
{"__radars_V17","V17","integer",-3,1,0,(char*)&__radars_V17,"POL2",0,0,0,{1,23,8,0}},
{"__radars_V18","V18","integer",-3,1,0,(char*)&__radars_V18,"CONFIG",0,0,0,{1,24,8,0}},
{"__radars_V19","V19","boolean",-2,2,0,(char*)&__radars_V19,"CONFIG",0,0,0,{1,24,8,0}},
{"__radars_V20","V20","boolean",-2,2,0,(char*)&__radars_V20,"JOUR",0,0,0,{1,25,8,0}},
{"__radars_V21","V21","boolean",-2,2,0,(char*)&__radars_V21,"NUIT",0,0,0,{1,26,8,0}},
{"__radars_V22","V22","integer",-3,0,0,(char*)&__radars_V22,"vmax",0,0,0,{1,9,5,2}},
{"__radars_V23","V23","integer",-3,0,0,(char*)&__radars_V23,"cptJours",0,0,0,{1,9,5,3}},
{"__radars_V24","V24","integer",-3,0,0,(char*)&__radars_V24,"vmax",0,0,0,{1,12,5,5}},
{"__radars_V25","V25","integer",-3,0,0,(char*)&__radars_V25,"vmax",0,0,0,{1,9,5,7}},
{"__radars_V26","V26","integer",-3,0,0,(char*)&__radars_V26,"cptJours",0,0,0,{1,9,5,8}},
{"__radars_V27","V27","integer",-3,0,0,(char*)&__radars_V27,"vmax",0,0,0,{1,12,5,10}}
};

struct __HaltEntry __radars_HaltTable [] = {
{{1,32,1,0}},
{{1,12,3,2}},
{{1,10,1,2}},
{{1,13,3,3}},
{{1,11,1,3}},
{{1,11,3,4}},
{{1,9,1,4}},
{{1,15,3,5}},
{{1,13,1,5}},
{{1,12,3,7}},
{{1,10,1,7}},
{{1,13,3,8}},
{{1,11,1,8}},
{{1,11,3,9}},
{{1,9,1,9}},
{{1,15,3,10}},
{{1,13,1,10}}
};


static void __radars__reset_input () {
__radars_V1 = _false;
__radars_V3 = _false;
__radars_V9 = _false;
__radars_V11 = _false;
__radars_V19 = _false;
__radars_V20 = _false;
__radars_V21 = _false;
}


/* MODULE DATA FOR SIMULATION */

int radars();
int radars_reset();

static struct __ModuleEntry __radars_ModuleData = {
"Simulation interface release 5","radars",
11,0,27,7,0,0,12,0,8,0,0,28,0,17,0,0,0,
__radars_HaltList,
__radars_AwaitedList,
__radars_EmittedList,
__radars_StartedList,
__radars_KilledList,
__radars_SuspendedList,
__radars_ActiveList,
0,0,
radars_initialize,radars,radars_reset,
__radars_show_variable,__radars_set_variable,__radars_check_value,0,
__radars_InstanceTable,
0,
__radars_SignalTable,__radars_InputTable,0,
0,0,
__radars_VariableTable,
0,
__radars_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __radars_R[17] = {_true,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
 _false,
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

int radars () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[75];

__radars_ModuleData.awaited_list = __radars_AwaitedList;
__ResetModuleEntryBeforeReaction();
E[0] = __radars_R[2]||__radars_R[1];
E[1] = E[0]&&!(__radars_R[0]);
E[2] = E[1]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
E[3] = __radars_R[1]&&E[2];
E[4] = (__CheckVariables(__radars_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radars_A1())||(__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5())||(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
E[5] = E[3]&&E[4];
E[6] = E[5]&&!((__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6()));
E[7] = E[6]&&(__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5());
if (E[7]) {
__CheckVariables(__radars_CheckArray[28]);__radars_A28();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A28\n");
#endif
}
E[6] = E[6]&&!((__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5()));
E[6] = E[7]||E[6];
E[8] = E[6]&&(__CheckVariables(__radars_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radars_A1());
E[9] = E[8]&&(__CheckVariables(__radars_CheckArray[49]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 49\n"),
#endif
__radars_A49());
if (E[9]) {
__AppendToList(__radars_EmittedList,2);
}
if (E[9]) {
__CheckVariables(__radars_CheckArray[29]);__radars_A29();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A29\n");
#endif
}
if (E[9]) {
__CheckVariables(__radars_CheckArray[8]);__radars_A8();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A8\n");
#endif
}
E[10] = __radars_R[10]||__radars_R[9];
E[11] = E[10]&&!(__radars_R[0]);
E[12] = E[11]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
E[13] = __radars_R[9]&&E[12];
E[14] = (__CheckVariables(__radars_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radars_A2())||(__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5())||(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
E[15] = E[13]&&E[14];
E[16] = E[15]&&!((__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6()));
E[17] = E[16]&&(__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5());
if (E[17]) {
__CheckVariables(__radars_CheckArray[39]);__radars_A39();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A39\n");
#endif
}
E[16] = E[16]&&!((__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5()));
E[16] = E[17]||E[16];
E[18] = E[16]&&(__CheckVariables(__radars_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radars_A2());
E[19] = E[18]&&(__CheckVariables(__radars_CheckArray[52]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 52\n"),
#endif
__radars_A52());
if (E[19]) {
__AppendToList(__radars_EmittedList,3);
}
if (E[19]) {
__CheckVariables(__radars_CheckArray[40]);__radars_A40();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A40\n");
#endif
}
if (E[19]) {
__CheckVariables(__radars_CheckArray[9]);__radars_A9();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A9\n");
#endif
}
E[20] = __radars_R[4]||__radars_R[3];
E[21] = E[20]&&!(__radars_R[0]);
E[22] = E[21]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
E[23] = __radars_R[3]&&E[22];
E[24] = (__CheckVariables(__radars_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radars_A1())||(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
E[25] = E[23]&&E[24];
E[26] = E[25]&&!((__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6()));
E[27] = E[26]&&(__CheckVariables(__radars_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radars_A1());
if (E[27]) {
__AppendToList(__radars_EmittedList,4);
__AppendToList(__radars_EmittedList,8);
}
if (E[27]) {
__CheckVariables(__radars_CheckArray[32]);__radars_A32();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A32\n");
#endif
}
if (E[27]) {
__CheckVariables(__radars_CheckArray[10]);__radars_A10();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A10\n");
#endif
}
E[28] = __radars_R[12]||__radars_R[11];
E[29] = E[28]&&!(__radars_R[0]);
E[30] = E[29]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
E[31] = __radars_R[11]&&E[30];
E[32] = (__CheckVariables(__radars_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radars_A2())||(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
E[33] = E[31]&&E[32];
E[34] = E[33]&&!((__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6()));
E[35] = E[34]&&(__CheckVariables(__radars_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radars_A2());
if (E[35]) {
__AppendToList(__radars_EmittedList,5);
__AppendToList(__radars_EmittedList,9);
}
if (E[35]) {
__CheckVariables(__radars_CheckArray[43]);__radars_A43();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A43\n");
#endif
}
if (E[35]) {
__CheckVariables(__radars_CheckArray[11]);__radars_A11();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A11\n");
#endif
}
if (E[27]) {
__CheckVariables(__radars_CheckArray[33]);__radars_A33();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A33\n");
#endif
}
if (E[27]) {
__CheckVariables(__radars_CheckArray[12]);__radars_A12();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A12\n");
#endif
}
if (E[35]) {
__CheckVariables(__radars_CheckArray[44]);__radars_A44();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A44\n");
#endif
}
if (E[35]) {
__CheckVariables(__radars_CheckArray[13]);__radars_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A13\n");
#endif
}
E[36] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radars_A1()));
if (E[36]) {
__CheckVariables(__radars_CheckArray[55]);__radars_A55();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A55\n");
#endif
}
E[37] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radars_A2()));
if (E[37]) {
__CheckVariables(__radars_CheckArray[56]);__radars_A56();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A56\n");
#endif
}
E[38] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radars_A3()));
if (E[38]) {
__CheckVariables(__radars_CheckArray[61]);__radars_A61();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A61\n");
#endif
}
E[39] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radars_A4()));
if (E[39]) {
__CheckVariables(__radars_CheckArray[62]);__radars_A62();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A62\n");
#endif
}
E[40] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5()));
if (E[40]) {
__CheckVariables(__radars_CheckArray[69]);__radars_A69();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A69\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[57]);__radars_A57();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A57\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[58]);__radars_A58();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A58\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[59]);__radars_A59();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A59\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[60]);__radars_A60();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A60\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[63]);__radars_A63();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A63\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[64]);__radars_A64();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A64\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[65]);__radars_A65();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A65\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[66]);__radars_A66();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A66\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[67]);__radars_A67();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A67\n");
#endif
}
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[68]);__radars_A68();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A68\n");
#endif
}
E[41] = __radars_R[6]||__radars_R[5];
E[42] = E[41]&&!(__radars_R[0]);
E[43] = (__radars_R[0]&&E[9])||(E[42]&&E[9]);
if (E[43]) {
__AppendToList(__radars_EmittedList,12);
}
E[44] = E[43]&&(__CheckVariables(__radars_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radars_A3());
E[42] = E[42]&&!(E[9]);
E[45] = __radars_R[5]&&E[42];
E[46] = E[45]&&(__CheckVariables(__radars_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radars_A3());
E[46] = E[44]||E[46];
if (E[46]) {
__AppendToList(__radars_EmittedList,10);
}
if (E[46]) {
__CheckVariables(__radars_CheckArray[34]);__radars_A34();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A34\n");
#endif
}
if (E[46]) {
__CheckVariables(__radars_CheckArray[14]);__radars_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A14\n");
#endif
}
E[44] = __radars_R[14]||__radars_R[13];
E[47] = E[44]&&!(__radars_R[0]);
E[48] = (__radars_R[0]&&E[19])||(E[47]&&E[19]);
if (E[48]) {
__AppendToList(__radars_EmittedList,13);
}
E[49] = E[48]&&(__CheckVariables(__radars_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radars_A4());
E[47] = E[47]&&!(E[19]);
E[50] = __radars_R[13]&&E[47];
E[51] = E[50]&&(__CheckVariables(__radars_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radars_A4());
E[51] = E[49]||E[51];
if (E[51]) {
__AppendToList(__radars_EmittedList,11);
}
if (E[51]) {
__CheckVariables(__radars_CheckArray[45]);__radars_A45();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A45\n");
#endif
}
if (E[51]) {
__CheckVariables(__radars_CheckArray[15]);__radars_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A15\n");
#endif
}
if (E[43]) {
__CheckVariables(__radars_CheckArray[16]);__radars_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A16\n");
#endif
}
if (E[48]) {
__CheckVariables(__radars_CheckArray[17]);__radars_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A17\n");
#endif
}
E[49] = __radars_R[8]||__radars_R[7];
E[52] = E[49]&&!(__radars_R[0]);
E[53] = E[52]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
E[54] = __radars_R[7]&&E[53];
E[55] = E[46]||(__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5())||(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
E[56] = E[54]&&E[55];
E[57] = E[56]&&!((__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6()));
E[58] = E[57]&&(__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5());
if (E[58]) {
__CheckVariables(__radars_CheckArray[36]);__radars_A36();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A36\n");
#endif
}
E[57] = E[57]&&!((__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5()));
E[57] = E[58]||E[57];
E[59] = E[57]&&E[46];
E[60] = E[59]&&(__CheckVariables(__radars_CheckArray[51]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 51\n"),
#endif
__radars_A51());
if (E[60]) {
__AppendToList(__radars_EmittedList,14);
}
if (E[60]) {
__CheckVariables(__radars_CheckArray[37]);__radars_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A37\n");
#endif
}
if (E[60]) {
__CheckVariables(__radars_CheckArray[18]);__radars_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A18\n");
#endif
}
E[61] = __radars_R[16]||__radars_R[15];
E[62] = E[61]&&!(__radars_R[0]);
E[63] = E[62]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
E[64] = __radars_R[15]&&E[63];
E[65] = E[51]||(__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5())||(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
E[66] = E[64]&&E[65];
E[67] = E[66]&&!((__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6()));
E[68] = E[67]&&(__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5());
if (E[68]) {
__CheckVariables(__radars_CheckArray[47]);__radars_A47();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A47\n");
#endif
}
E[67] = E[67]&&!((__CheckVariables(__radars_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__radars_A5()));
E[67] = E[68]||E[67];
E[69] = E[67]&&E[51];
E[70] = E[69]&&(__CheckVariables(__radars_CheckArray[54]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 54\n"),
#endif
__radars_A54());
if (E[70]) {
__AppendToList(__radars_EmittedList,15);
}
if (E[70]) {
__CheckVariables(__radars_CheckArray[48]);__radars_A48();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A48\n");
#endif
}
if (E[70]) {
__CheckVariables(__radars_CheckArray[19]);__radars_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A19\n");
#endif
}
E[5] = E[5]&&(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
if (E[5]) {
__AppendToList(__radars_EmittedList,19);
}
E[25] = E[25]&&(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
if (E[25]) {
__CheckVariables(__radars_CheckArray[31]);__radars_A31();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A31\n");
#endif
}
E[71] = E[25]&&(__CheckVariables(__radars_CheckArray[50]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 50\n"),
#endif
__radars_A50());
if (E[71]) {
__AppendToList(__radars_EmittedList,20);
}
if (E[25]&&!(E[71])) {
__AppendToList(__radars_EmittedList,21);
}
E[56] = E[56]&&(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
if (E[56]) {
__AppendToList(__radars_EmittedList,22);
}
E[15] = E[15]&&(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
if (E[15]) {
__AppendToList(__radars_EmittedList,23);
}
E[33] = E[33]&&(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
if (E[33]) {
__CheckVariables(__radars_CheckArray[42]);__radars_A42();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A42\n");
#endif
}
E[72] = E[33]&&(__CheckVariables(__radars_CheckArray[53]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 53\n"),
#endif
__radars_A53());
if (E[72]) {
__AppendToList(__radars_EmittedList,24);
}
if (E[33]&&!(E[72])) {
__AppendToList(__radars_EmittedList,25);
}
E[66] = E[66]&&(__CheckVariables(__radars_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__radars_A6());
if (E[66]) {
__AppendToList(__radars_EmittedList,26);
}
E[73] = !(_true);
E[1] = E[1]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[27]);__radars_A27();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A27\n");
#endif
}
E[74] = __radars_R[0]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
E[6] = E[6]&&!((__CheckVariables(__radars_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radars_A1()));
__radars_R[1] = E[1]||E[74]||E[9]||(E[8]&&!(E[9]))||E[6]||(__radars_R[1]&&E[3]&&!(E[4]));
E[4] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
__radars_R[2] = E[5]||(__radars_R[2]&&E[2])||E[4];
E[21] = E[21]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[30]);__radars_A30();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A30\n");
#endif
}
E[4] = __radars_R[0]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
E[26] = E[26]&&!((__CheckVariables(__radars_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__radars_A1()));
E[24] = E[21]||E[4]||E[27]||E[26]||(__radars_R[3]&&E[23]&&!(E[24]));
E[23] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
__radars_R[4] = (E[25]&&!(E[71]))||(__radars_R[4]&&E[22])||E[23];
E[23] = E[24]||__radars_R[4];
__radars_R[6] = E[46]||(__radars_R[6]&&E[42])||(__radars_R[0]&&!(E[9]));
E[42] = E[43]&&!((__CheckVariables(__radars_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radars_A3()));
E[45] = E[45]&&!((__CheckVariables(__radars_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__radars_A3()));
__radars_R[5] = E[42]||(__radars_R[5]&&E[45]);
E[52] = E[52]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[35]);__radars_A35();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A35\n");
#endif
}
E[45] = __radars_R[0]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
__radars_R[7] = E[52]||E[45]||E[60]||(E[59]&&!(E[60]))||(E[57]&&!(E[46]))||(__radars_R[7]&&E[54]&&!(E[55]));
E[55] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
__radars_R[8] = E[56]||(__radars_R[8]&&E[53])||E[55];
E[55] = E[0]||E[20]||E[41]||E[49];
E[49] = (__radars_R[1]||__radars_R[2]||E[23]||__radars_R[6]||__radars_R[5]||__radars_R[7]||__radars_R[8])&&((E[55]&&!(E[0]))||__radars_R[1]||__radars_R[2])&&((E[55]&&!(E[20]))||E[71]||E[23])&&((E[55]&&!(E[41]))||__radars_R[6]||__radars_R[5])&&((E[55]&&!(E[49]))||__radars_R[7]||__radars_R[8]);
E[11] = E[11]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[38]);__radars_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A38\n");
#endif
}
E[41] = __radars_R[0]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
E[16] = E[16]&&!((__CheckVariables(__radars_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radars_A2()));
__radars_R[9] = E[11]||E[41]||E[19]||(E[18]&&!(E[19]))||E[16]||(__radars_R[9]&&E[13]&&!(E[14]));
E[14] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
__radars_R[10] = E[15]||(__radars_R[10]&&E[12])||E[14];
E[29] = E[29]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[41]);__radars_A41();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A41\n");
#endif
}
E[14] = __radars_R[0]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
E[34] = E[34]&&!((__CheckVariables(__radars_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__radars_A2()));
E[32] = E[29]||E[14]||E[35]||E[34]||(__radars_R[11]&&E[31]&&!(E[32]));
E[31] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
__radars_R[12] = (E[33]&&!(E[72]))||(__radars_R[12]&&E[30])||E[31];
E[31] = E[32]||__radars_R[12];
__radars_R[14] = E[51]||(__radars_R[14]&&E[47])||(__radars_R[0]&&!(E[19]));
E[47] = E[48]&&!((__CheckVariables(__radars_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radars_A4()));
E[50] = E[50]&&!((__CheckVariables(__radars_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__radars_A4()));
__radars_R[13] = E[47]||(__radars_R[13]&&E[50]);
E[62] = E[62]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
if (__radars_R[0]) {
__CheckVariables(__radars_CheckArray[46]);__radars_A46();
#ifdef TRACE_ACTION
fprintf(stderr, "__radars_A46\n");
#endif
}
E[50] = __radars_R[0]&&(__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7());
__radars_R[15] = E[62]||E[50]||E[70]||(E[69]&&!(E[70]))||(E[67]&&!(E[51]))||(__radars_R[15]&&E[64]&&!(E[65]));
E[65] = __radars_R[0]&&!((__CheckVariables(__radars_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__radars_A7()));
__radars_R[16] = E[66]||(__radars_R[16]&&E[63])||E[65];
E[65] = E[10]||E[28]||E[44]||E[61];
E[61] = (__radars_R[9]||__radars_R[10]||E[31]||__radars_R[14]||__radars_R[13]||__radars_R[15]||__radars_R[16])&&((E[65]&&!(E[10]))||__radars_R[9]||__radars_R[10])&&((E[65]&&!(E[28]))||E[72]||E[31])&&((E[65]&&!(E[44]))||__radars_R[14]||__radars_R[13])&&((E[65]&&!(E[61]))||__radars_R[15]||__radars_R[16]);
E[44] = E[55]||E[65];
E[61] = (E[49]||E[61])&&((E[44]&&!(E[55]))||E[49])&&((E[44]&&!(E[65]))||E[61]);
__radars_R[3] = E[24]&&!(E[71]);
__radars_R[11] = E[32]&&!(E[72]);
__radars_R[0] = !(_true);
if (__radars_R[1]) { __AppendToList(__radars_HaltList,1); }
if (__radars_R[2]) { __AppendToList(__radars_HaltList,2); }
if (__radars_R[3]) { __AppendToList(__radars_HaltList,3); }
if (__radars_R[4]) { __AppendToList(__radars_HaltList,4); }
if (__radars_R[5]) { __AppendToList(__radars_HaltList,5); }
if (__radars_R[6]) { __AppendToList(__radars_HaltList,6); }
if (__radars_R[7]) { __AppendToList(__radars_HaltList,7); }
if (__radars_R[8]) { __AppendToList(__radars_HaltList,8); }
if (__radars_R[9]) { __AppendToList(__radars_HaltList,9); }
if (__radars_R[10]) { __AppendToList(__radars_HaltList,10); }
if (__radars_R[11]) { __AppendToList(__radars_HaltList,11); }
if (__radars_R[12]) { __AppendToList(__radars_HaltList,12); }
if (__radars_R[13]) { __AppendToList(__radars_HaltList,13); }
if (__radars_R[14]) { __AppendToList(__radars_HaltList,14); }
if (__radars_R[15]) { __AppendToList(__radars_HaltList,15); }
if (__radars_R[16]) { __AppendToList(__radars_HaltList,16); }
if (!E[61]) { __AppendToList(__radars_HaltList,0); }
__ResetModuleEntryAfterReaction();
__radars_ModuleData.awaited_list = __radars_AllAwaitedList;
__radars__reset_input();
return E[61];
}

/* AUTOMATON RESET */

int radars_reset () {
__radars_ModuleData.awaited_list = __radars_AwaitedList;
__ResetModuleEntry();
__radars_ModuleData.awaited_list = __radars_AllAwaitedList;
__radars_ModuleData.state = 0;
__radars_R[0] = _true;
__radars_R[1] = _false;
__radars_R[2] = _false;
__radars_R[3] = _false;
__radars_R[4] = _false;
__radars_R[5] = _false;
__radars_R[6] = _false;
__radars_R[7] = _false;
__radars_R[8] = _false;
__radars_R[9] = _false;
__radars_R[10] = _false;
__radars_R[11] = _false;
__radars_R[12] = _false;
__radars_R[13] = _false;
__radars_R[14] = _false;
__radars_R[15] = _false;
__radars_R[16] = _false;
__radars__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__radars_ModuleData
};

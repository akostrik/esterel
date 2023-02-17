/* sscc : C CODE OF SORTED EQUATIONS Examen_Esterel - SIMULATION MODE */

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
#define __Examen_Esterel_GENERIC_TEST(TEST) return TEST;
typedef void (*__Examen_Esterel_APF)();
static __Examen_Esterel_APF *__Examen_Esterel_PActionArray;
static int **__Examen_Esterel_PCheckArray;
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

static integer __Examen_Esterel_V0;
static boolean __Examen_Esterel_V1;
static integer __Examen_Esterel_V2;
static boolean __Examen_Esterel_V3;
static integer __Examen_Esterel_V4;
static boolean __Examen_Esterel_V5;
static integer __Examen_Esterel_V6;
static boolean __Examen_Esterel_V7;
static integer __Examen_Esterel_V8;
static boolean __Examen_Esterel_V9;
static integer __Examen_Esterel_V10;
static boolean __Examen_Esterel_V11;
static integer __Examen_Esterel_V12;
static boolean __Examen_Esterel_V13;
static integer __Examen_Esterel_V14;
static boolean __Examen_Esterel_V15;
static boolean __Examen_Esterel_V16;
static boolean __Examen_Esterel_V17;
static boolean __Examen_Esterel_V18;
static integer __Examen_Esterel_V19;
static boolean __Examen_Esterel_V20;
static integer __Examen_Esterel_V21;
static integer __Examen_Esterel_V22;
static integer __Examen_Esterel_V23;
static integer __Examen_Esterel_V24;
static integer __Examen_Esterel_V25;
static integer __Examen_Esterel_V26;
static integer __Examen_Esterel_V27;
static integer __Examen_Esterel_V28;
static integer __Examen_Esterel_V29;
static integer __Examen_Esterel_V30;

static unsigned short __Examen_Esterel_HaltList[26];
static unsigned short __Examen_Esterel_AwaitedList[15];
static unsigned short __Examen_Esterel_EmittedList[15];
static unsigned short __Examen_Esterel_StartedList[1];
static unsigned short __Examen_Esterel_KilledList[1];
static unsigned short __Examen_Esterel_SuspendedList[1];
static unsigned short __Examen_Esterel_ActiveList[1];
static unsigned short __Examen_Esterel_AllAwaitedList[15]={12,0,1,2,3,4,5,6,7,8,9,10,11};


/* INPUT FUNCTIONS */

void Examen_Esterel_I_REMPLIR_DEBUT (integer __V) {
__WriteVariable(0);
__Examen_Esterel_V0 = __V;
__Examen_Esterel_V1 = _true;
}
void Examen_Esterel_IS_REMPLIR_DEBUT (string __V) {
__WriteVariable(0);
_text_to_integer(&__Examen_Esterel_V0,__V);
__Examen_Esterel_V1 = _true;
}
void Examen_Esterel_I_REMPLIR_A (integer __V) {
__WriteVariable(2);
__Examen_Esterel_V2 = __V;
__Examen_Esterel_V3 = _true;
}
void Examen_Esterel_IS_REMPLIR_A (string __V) {
__WriteVariable(2);
_text_to_integer(&__Examen_Esterel_V2,__V);
__Examen_Esterel_V3 = _true;
}
void Examen_Esterel_I_REMPLIR_B (integer __V) {
__WriteVariable(4);
__Examen_Esterel_V4 = __V;
__Examen_Esterel_V5 = _true;
}
void Examen_Esterel_IS_REMPLIR_B (string __V) {
__WriteVariable(4);
_text_to_integer(&__Examen_Esterel_V4,__V);
__Examen_Esterel_V5 = _true;
}
void Examen_Esterel_I_REMPLIR_FIN (integer __V) {
__WriteVariable(6);
__Examen_Esterel_V6 = __V;
__Examen_Esterel_V7 = _true;
}
void Examen_Esterel_IS_REMPLIR_FIN (string __V) {
__WriteVariable(6);
_text_to_integer(&__Examen_Esterel_V6,__V);
__Examen_Esterel_V7 = _true;
}
void Examen_Esterel_I_PANIER_PLEIN_DEBUT (integer __V) {
__WriteVariable(8);
__Examen_Esterel_V8 = __V;
__Examen_Esterel_V9 = _true;
}
void Examen_Esterel_IS_PANIER_PLEIN_DEBUT (string __V) {
__WriteVariable(8);
_text_to_integer(&__Examen_Esterel_V8,__V);
__Examen_Esterel_V9 = _true;
}
void Examen_Esterel_I_PANIER_PLEIN_A (integer __V) {
__WriteVariable(10);
__Examen_Esterel_V10 = __V;
__Examen_Esterel_V11 = _true;
}
void Examen_Esterel_IS_PANIER_PLEIN_A (string __V) {
__WriteVariable(10);
_text_to_integer(&__Examen_Esterel_V10,__V);
__Examen_Esterel_V11 = _true;
}
void Examen_Esterel_I_PANIER_PLEIN_B (integer __V) {
__WriteVariable(12);
__Examen_Esterel_V12 = __V;
__Examen_Esterel_V13 = _true;
}
void Examen_Esterel_IS_PANIER_PLEIN_B (string __V) {
__WriteVariable(12);
_text_to_integer(&__Examen_Esterel_V12,__V);
__Examen_Esterel_V13 = _true;
}
void Examen_Esterel_I_PANIER_PLEIN_SORTIE (integer __V) {
__WriteVariable(14);
__Examen_Esterel_V14 = __V;
__Examen_Esterel_V15 = _true;
}
void Examen_Esterel_IS_PANIER_PLEIN_SORTIE (string __V) {
__WriteVariable(14);
_text_to_integer(&__Examen_Esterel_V14,__V);
__Examen_Esterel_V15 = _true;
}
void Examen_Esterel_I_VIDER_DEBUT () {
__Examen_Esterel_V16 = _true;
}
void Examen_Esterel_IS_VIDER_DEBUT () {
__Examen_Esterel_V16 = _true;
}
void Examen_Esterel_I_VIDER_A () {
__Examen_Esterel_V17 = _true;
}
void Examen_Esterel_IS_VIDER_A () {
__Examen_Esterel_V17 = _true;
}
void Examen_Esterel_I_VIDER_B () {
__Examen_Esterel_V18 = _true;
}
void Examen_Esterel_IS_VIDER_B () {
__Examen_Esterel_V18 = _true;
}
void Examen_Esterel_I_FIN (integer __V) {
__WriteVariable(19);
__Examen_Esterel_V19 = __V;
__Examen_Esterel_V20 = _true;
}
void Examen_Esterel_IS_FIN (string __V) {
__WriteVariable(19);
_text_to_integer(&__Examen_Esterel_V19,__V);
__Examen_Esterel_V20 = _true;
}

/* FUNCTIONS RETURNING NUMBER OF EXEC */

int Examen_Esterel_number_of_execs () {
return (0);
}


/* AUTOMATON (STATE ACTION-TREES) */

/* ACTIONS */

/* PREDEFINED ACTIONS */

/* PRESENT SIGNAL TESTS */

static int __Examen_Esterel_A1 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V1);
}
static int __Examen_Esterel_Check1 [] = {1,0,0};
static int __Examen_Esterel_A2 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V3);
}
static int __Examen_Esterel_Check2 [] = {1,0,0};
static int __Examen_Esterel_A3 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V5);
}
static int __Examen_Esterel_Check3 [] = {1,0,0};
static int __Examen_Esterel_A4 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V7);
}
static int __Examen_Esterel_Check4 [] = {1,0,0};
static int __Examen_Esterel_A5 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V9);
}
static int __Examen_Esterel_Check5 [] = {1,0,0};
static int __Examen_Esterel_A6 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V11);
}
static int __Examen_Esterel_Check6 [] = {1,0,0};
static int __Examen_Esterel_A7 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V13);
}
static int __Examen_Esterel_Check7 [] = {1,0,0};
static int __Examen_Esterel_A8 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V15);
}
static int __Examen_Esterel_Check8 [] = {1,0,0};
static int __Examen_Esterel_A9 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V16);
}
static int __Examen_Esterel_Check9 [] = {1,0,0};
static int __Examen_Esterel_A10 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V17);
}
static int __Examen_Esterel_Check10 [] = {1,0,0};
static int __Examen_Esterel_A11 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V18);
}
static int __Examen_Esterel_Check11 [] = {1,0,0};
static int __Examen_Esterel_A12 () {
__Examen_Esterel_GENERIC_TEST(__Examen_Esterel_V20);
}
static int __Examen_Esterel_Check12 [] = {1,0,0};

/* OUTPUT ACTIONS */

static void __Examen_Esterel_A13 () {
#ifdef __OUTPUT
Examen_Esterel_O_REMPLIR_DEBUT(__Examen_Esterel_V0);
#endif
__AppendToList(__Examen_Esterel_EmittedList,0);
}
static int __Examen_Esterel_Check13 [] = {1,0,0};
static void __Examen_Esterel_A14 () {
#ifdef __OUTPUT
Examen_Esterel_O_REMPLIR_A(__Examen_Esterel_V2);
#endif
__AppendToList(__Examen_Esterel_EmittedList,1);
}
static int __Examen_Esterel_Check14 [] = {1,0,0};
static void __Examen_Esterel_A15 () {
#ifdef __OUTPUT
Examen_Esterel_O_REMPLIR_B(__Examen_Esterel_V4);
#endif
__AppendToList(__Examen_Esterel_EmittedList,2);
}
static int __Examen_Esterel_Check15 [] = {1,0,0};
static void __Examen_Esterel_A16 () {
#ifdef __OUTPUT
Examen_Esterel_O_REMPLIR_FIN(__Examen_Esterel_V6);
#endif
__AppendToList(__Examen_Esterel_EmittedList,3);
}
static int __Examen_Esterel_Check16 [] = {1,0,0};
static void __Examen_Esterel_A17 () {
#ifdef __OUTPUT
Examen_Esterel_O_PANIER_PLEIN_DEBUT(__Examen_Esterel_V8);
#endif
__AppendToList(__Examen_Esterel_EmittedList,4);
}
static int __Examen_Esterel_Check17 [] = {1,0,0};
static void __Examen_Esterel_A18 () {
#ifdef __OUTPUT
Examen_Esterel_O_PANIER_PLEIN_A(__Examen_Esterel_V10);
#endif
__AppendToList(__Examen_Esterel_EmittedList,5);
}
static int __Examen_Esterel_Check18 [] = {1,0,0};
static void __Examen_Esterel_A19 () {
#ifdef __OUTPUT
Examen_Esterel_O_PANIER_PLEIN_B(__Examen_Esterel_V12);
#endif
__AppendToList(__Examen_Esterel_EmittedList,6);
}
static int __Examen_Esterel_Check19 [] = {1,0,0};
static void __Examen_Esterel_A20 () {
#ifdef __OUTPUT
Examen_Esterel_O_PANIER_PLEIN_SORTIE(__Examen_Esterel_V14);
#endif
__AppendToList(__Examen_Esterel_EmittedList,7);
}
static int __Examen_Esterel_Check20 [] = {1,0,0};
static void __Examen_Esterel_A21 () {
#ifdef __OUTPUT
Examen_Esterel_O_VIDER_DEBUT();
#endif
__AppendToList(__Examen_Esterel_EmittedList,8);
}
static int __Examen_Esterel_Check21 [] = {1,0,0};
static void __Examen_Esterel_A22 () {
#ifdef __OUTPUT
Examen_Esterel_O_VIDER_A();
#endif
__AppendToList(__Examen_Esterel_EmittedList,9);
}
static int __Examen_Esterel_Check22 [] = {1,0,0};
static void __Examen_Esterel_A23 () {
#ifdef __OUTPUT
Examen_Esterel_O_VIDER_B();
#endif
__AppendToList(__Examen_Esterel_EmittedList,10);
}
static int __Examen_Esterel_Check23 [] = {1,0,0};
static void __Examen_Esterel_A24 () {
#ifdef __OUTPUT
Examen_Esterel_O_FIN(__Examen_Esterel_V19);
#endif
__AppendToList(__Examen_Esterel_EmittedList,11);
}
static int __Examen_Esterel_Check24 [] = {1,0,0};

/* ASSIGNMENTS */

static void __Examen_Esterel_A25 () {
__Examen_Esterel_V1 = _false;
}
static int __Examen_Esterel_Check25 [] = {1,0,1,1};
static void __Examen_Esterel_A26 () {
__Examen_Esterel_V3 = _false;
}
static int __Examen_Esterel_Check26 [] = {1,0,1,3};
static void __Examen_Esterel_A27 () {
__Examen_Esterel_V5 = _false;
}
static int __Examen_Esterel_Check27 [] = {1,0,1,5};
static void __Examen_Esterel_A28 () {
__Examen_Esterel_V7 = _false;
}
static int __Examen_Esterel_Check28 [] = {1,0,1,7};
static void __Examen_Esterel_A29 () {
__Examen_Esterel_V9 = _false;
}
static int __Examen_Esterel_Check29 [] = {1,0,1,9};
static void __Examen_Esterel_A30 () {
__Examen_Esterel_V11 = _false;
}
static int __Examen_Esterel_Check30 [] = {1,0,1,11};
static void __Examen_Esterel_A31 () {
__Examen_Esterel_V13 = _false;
}
static int __Examen_Esterel_Check31 [] = {1,0,1,13};
static void __Examen_Esterel_A32 () {
__Examen_Esterel_V15 = _false;
}
static int __Examen_Esterel_Check32 [] = {1,0,1,15};
static void __Examen_Esterel_A33 () {
__Examen_Esterel_V16 = _false;
}
static int __Examen_Esterel_Check33 [] = {1,0,1,16};
static void __Examen_Esterel_A34 () {
__Examen_Esterel_V17 = _false;
}
static int __Examen_Esterel_Check34 [] = {1,0,1,17};
static void __Examen_Esterel_A35 () {
__Examen_Esterel_V18 = _false;
}
static int __Examen_Esterel_Check35 [] = {1,0,1,18};
static void __Examen_Esterel_A36 () {
__Examen_Esterel_V20 = _false;
}
static int __Examen_Esterel_Check36 [] = {1,0,1,20};
static void __Examen_Esterel_A37 () {
__Examen_Esterel_V21 = -(1);
}
static int __Examen_Esterel_Check37 [] = {1,0,1,21};
static void __Examen_Esterel_A38 () {
__Examen_Esterel_V21 = __Examen_Esterel_V0;
}
static int __Examen_Esterel_Check38 [] = {1,1,0,1,21};
static void __Examen_Esterel_A39 () {
__Examen_Esterel_V8 = __Examen_Esterel_V21;
}
static int __Examen_Esterel_Check39 [] = {1,1,21,1,8};
static void __Examen_Esterel_A40 () {
__Examen_Esterel_V21 = -(1);
}
static int __Examen_Esterel_Check40 [] = {1,0,1,21};
static void __Examen_Esterel_A41 () {
__Examen_Esterel_V22 = -(1);
}
static int __Examen_Esterel_Check41 [] = {1,0,1,22};
static void __Examen_Esterel_A42 () {
__Examen_Esterel_V22 = __Examen_Esterel_V2;
}
static int __Examen_Esterel_Check42 [] = {1,1,2,1,22};
static void __Examen_Esterel_A43 () {
__Examen_Esterel_V10 = __Examen_Esterel_V22;
}
static int __Examen_Esterel_Check43 [] = {1,1,22,1,10};
static void __Examen_Esterel_A44 () {
__Examen_Esterel_V22 = -(1);
}
static int __Examen_Esterel_Check44 [] = {1,0,1,22};
static void __Examen_Esterel_A45 () {
__Examen_Esterel_V23 = -(1);
}
static int __Examen_Esterel_Check45 [] = {1,0,1,23};
static void __Examen_Esterel_A46 () {
__Examen_Esterel_V23 = __Examen_Esterel_V4;
}
static int __Examen_Esterel_Check46 [] = {1,1,4,1,23};
static void __Examen_Esterel_A47 () {
__Examen_Esterel_V12 = __Examen_Esterel_V23;
}
static int __Examen_Esterel_Check47 [] = {1,1,23,1,12};
static void __Examen_Esterel_A48 () {
__Examen_Esterel_V23 = -(1);
}
static int __Examen_Esterel_Check48 [] = {1,0,1,23};
static void __Examen_Esterel_A49 () {
__Examen_Esterel_V24 = -(1);
}
static int __Examen_Esterel_Check49 [] = {1,0,1,24};
static void __Examen_Esterel_A50 () {
__Examen_Esterel_V24 = __Examen_Esterel_V6;
}
static int __Examen_Esterel_Check50 [] = {1,1,6,1,24};
static void __Examen_Esterel_A51 () {
__Examen_Esterel_V14 = __Examen_Esterel_V24;
}
static int __Examen_Esterel_Check51 [] = {1,1,24,1,14};
static void __Examen_Esterel_A52 () {
__Examen_Esterel_V19 = __Examen_Esterel_V24;
}
static int __Examen_Esterel_Check52 [] = {1,1,24,1,19};
static void __Examen_Esterel_A53 () {
__Examen_Esterel_V24 = -(1);
}
static int __Examen_Esterel_Check53 [] = {1,0,1,24};
static void __Examen_Esterel_A54 () {
__Examen_Esterel_V25 = -(1);
}
static int __Examen_Esterel_Check54 [] = {1,0,1,25};
static void __Examen_Esterel_A55 () {
__Examen_Esterel_V25 = __Examen_Esterel_V8;
}
static int __Examen_Esterel_Check55 [] = {1,1,8,1,25};
static void __Examen_Esterel_A56 () {
__Examen_Esterel_V26 = 2;
}
static int __Examen_Esterel_Check56 [] = {1,0,1,26};
static void __Examen_Esterel_A57 () {
__Examen_Esterel_V2 = __Examen_Esterel_V25;
}
static int __Examen_Esterel_Check57 [] = {1,1,25,1,2};
static void __Examen_Esterel_A58 () {
__Examen_Esterel_V27 = -(1);
}
static int __Examen_Esterel_Check58 [] = {1,0,1,27};
static void __Examen_Esterel_A59 () {
__Examen_Esterel_V27 = __Examen_Esterel_V10;
}
static int __Examen_Esterel_Check59 [] = {1,1,10,1,27};
static void __Examen_Esterel_A60 () {
__Examen_Esterel_V28 = 2;
}
static int __Examen_Esterel_Check60 [] = {1,0,1,28};
static void __Examen_Esterel_A61 () {
__Examen_Esterel_V4 = __Examen_Esterel_V27;
}
static int __Examen_Esterel_Check61 [] = {1,1,27,1,4};
static void __Examen_Esterel_A62 () {
__Examen_Esterel_V29 = -(1);
}
static int __Examen_Esterel_Check62 [] = {1,0,1,29};
static void __Examen_Esterel_A63 () {
__Examen_Esterel_V29 = __Examen_Esterel_V12;
}
static int __Examen_Esterel_Check63 [] = {1,1,12,1,29};
static void __Examen_Esterel_A64 () {
__Examen_Esterel_V30 = 2;
}
static int __Examen_Esterel_Check64 [] = {1,0,1,30};
static void __Examen_Esterel_A65 () {
__Examen_Esterel_V6 = __Examen_Esterel_V29;
}
static int __Examen_Esterel_Check65 [] = {1,1,29,1,6};

/* PROCEDURE CALLS */

/* CONDITIONS */

/* DECREMENTS */

static int __Examen_Esterel_A66 () {
__Examen_Esterel_GENERIC_TEST(__DSZ(__Examen_Esterel_V26));
}
static int __Examen_Esterel_Check66 [] = {1,1,26,1,26};
static int __Examen_Esterel_A67 () {
__Examen_Esterel_GENERIC_TEST(__DSZ(__Examen_Esterel_V28));
}
static int __Examen_Esterel_Check67 [] = {1,1,28,1,28};
static int __Examen_Esterel_A68 () {
__Examen_Esterel_GENERIC_TEST(__DSZ(__Examen_Esterel_V30));
}
static int __Examen_Esterel_Check68 [] = {1,1,30,1,30};

/* START ACTIONS */

/* KILL ACTIONS */

/* SUSPEND ACTIONS */

/* ACTIVATE ACTIONS */

/* WRITE ARGS ACTIONS */

/* RESET ACTIONS */

static void __Examen_Esterel_A69 () {
;
__ResetVariable(0);
}
static int __Examen_Esterel_Check69 [] = {1,0,0};
static void __Examen_Esterel_A70 () {
;
__ResetVariable(2);
}
static int __Examen_Esterel_Check70 [] = {1,0,0};
static void __Examen_Esterel_A71 () {
;
__ResetVariable(4);
}
static int __Examen_Esterel_Check71 [] = {1,0,0};
static void __Examen_Esterel_A72 () {
;
__ResetVariable(6);
}
static int __Examen_Esterel_Check72 [] = {1,0,0};
static void __Examen_Esterel_A73 () {
;
__ResetVariable(8);
}
static int __Examen_Esterel_Check73 [] = {1,0,0};
static void __Examen_Esterel_A74 () {
;
__ResetVariable(10);
}
static int __Examen_Esterel_Check74 [] = {1,0,0};
static void __Examen_Esterel_A75 () {
;
__ResetVariable(12);
}
static int __Examen_Esterel_Check75 [] = {1,0,0};
static void __Examen_Esterel_A76 () {
;
__ResetVariable(14);
}
static int __Examen_Esterel_Check76 [] = {1,0,0};
static void __Examen_Esterel_A77 () {
;
__ResetVariable(19);
}
static int __Examen_Esterel_Check77 [] = {1,0,0};

/* ACTION SEQUENCES */


static int *__Examen_Esterel_CheckArray[] = {
0,
__Examen_Esterel_Check1,
__Examen_Esterel_Check2,
__Examen_Esterel_Check3,
__Examen_Esterel_Check4,
__Examen_Esterel_Check5,
__Examen_Esterel_Check6,
__Examen_Esterel_Check7,
__Examen_Esterel_Check8,
__Examen_Esterel_Check9,
__Examen_Esterel_Check10,
__Examen_Esterel_Check11,
__Examen_Esterel_Check12,
__Examen_Esterel_Check13,
__Examen_Esterel_Check14,
__Examen_Esterel_Check15,
__Examen_Esterel_Check16,
__Examen_Esterel_Check17,
__Examen_Esterel_Check18,
__Examen_Esterel_Check19,
__Examen_Esterel_Check20,
__Examen_Esterel_Check21,
__Examen_Esterel_Check22,
__Examen_Esterel_Check23,
__Examen_Esterel_Check24,
__Examen_Esterel_Check25,
__Examen_Esterel_Check26,
__Examen_Esterel_Check27,
__Examen_Esterel_Check28,
__Examen_Esterel_Check29,
__Examen_Esterel_Check30,
__Examen_Esterel_Check31,
__Examen_Esterel_Check32,
__Examen_Esterel_Check33,
__Examen_Esterel_Check34,
__Examen_Esterel_Check35,
__Examen_Esterel_Check36,
__Examen_Esterel_Check37,
__Examen_Esterel_Check38,
__Examen_Esterel_Check39,
__Examen_Esterel_Check40,
__Examen_Esterel_Check41,
__Examen_Esterel_Check42,
__Examen_Esterel_Check43,
__Examen_Esterel_Check44,
__Examen_Esterel_Check45,
__Examen_Esterel_Check46,
__Examen_Esterel_Check47,
__Examen_Esterel_Check48,
__Examen_Esterel_Check49,
__Examen_Esterel_Check50,
__Examen_Esterel_Check51,
__Examen_Esterel_Check52,
__Examen_Esterel_Check53,
__Examen_Esterel_Check54,
__Examen_Esterel_Check55,
__Examen_Esterel_Check56,
__Examen_Esterel_Check57,
__Examen_Esterel_Check58,
__Examen_Esterel_Check59,
__Examen_Esterel_Check60,
__Examen_Esterel_Check61,
__Examen_Esterel_Check62,
__Examen_Esterel_Check63,
__Examen_Esterel_Check64,
__Examen_Esterel_Check65,
__Examen_Esterel_Check66,
__Examen_Esterel_Check67,
__Examen_Esterel_Check68,
__Examen_Esterel_Check69,
__Examen_Esterel_Check70,
__Examen_Esterel_Check71,
__Examen_Esterel_Check72,
__Examen_Esterel_Check73,
__Examen_Esterel_Check74,
__Examen_Esterel_Check75,
__Examen_Esterel_Check76,
__Examen_Esterel_Check77
};
static int **__Examen_Esterel_PCheckArray =  __Examen_Esterel_CheckArray;

/* INIT FUNCTION */

#ifndef NO_INIT
void Examen_Esterel_initialize () {
}
#endif

/* SHOW VARIABLE FUNCTION */

char* __Examen_Esterel_show_variable (int __V) {
extern struct __VariableEntry __Examen_Esterel_VariableTable[];
struct __VariableEntry* p_var = &__Examen_Esterel_VariableTable[__V];
if (p_var->type_code < 0) {return __PredefinedTypeToText(p_var->type_code, p_var->p_variable);
} else {
switch (p_var->type_code) {
default: return 0;
}
}
}

/* SET VARIABLE FUNCTION */

static void __Examen_Esterel_set_variable(int __Type, char* __pVar, char* __Text) {
}

/* CHECK VALUE FUNCTION */

static int __Examen_Esterel_check_value (int __Type, char* __Text) {
return 0;
}

/* SIMULATION TABLES */

struct __InstanceEntry __Examen_Esterel_InstanceTable [] = {
{"Examen_Esterel",0,"","Examen_Esterel1.strl",{1,156,1,0},{1,182,1,0},{0,0,0,0}},
{"Panier_DEBUT",0,"","Examen_Esterel1.strl",{1,5,1,1},{1,20,1,1},{1,168,1,0}},
{"Panier_A",0,"","Examen_Esterel1.strl",{1,23,1,2},{1,38,1,2},{1,170,1,0}},
{"Panier_B",0,"","Examen_Esterel1.strl",{1,41,1,3},{1,56,1,3},{1,172,1,0}},
{"Panier_FIN",0,"","Examen_Esterel1.strl",{1,59,1,4},{1,76,1,4},{1,174,1,0}},
{"Robot1",0,"","Examen_Esterel1.strl",{1,79,1,5},{1,103,1,5},{1,176,1,0}},
{"Robot2",0,"","Examen_Esterel1.strl",{1,106,1,6},{1,130,1,6},{1,178,1,0}},
{"Robot3",0,"","Examen_Esterel1.strl",{1,133,1,7},{1,153,1,7},{1,180,1,0}},
};

struct __SignalEntry __Examen_Esterel_SignalTable [] = {
{"REMPLIR_DEBUT",3,0,0,{1,157,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"REMPLIR_A",3,2,0,{1,158,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"REMPLIR_B",3,4,0,{1,159,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"REMPLIR_FIN",3,6,0,{1,160,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PANIER_PLEIN_DEBUT",3,8,0,{1,161,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PANIER_PLEIN_A",3,10,0,{1,162,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PANIER_PLEIN_B",3,12,0,{1,163,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PANIER_PLEIN_SORTIE",3,14,0,{1,164,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"VIDER_DEBUT",35,0,0,{1,165,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"VIDER_A",35,0,0,{1,165,26,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"VIDER_B",35,0,0,{1,165,35,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"FIN",3,19,0,{1,166,13,0},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PANIER_VIDE_A",48,0,0,{1,92,8,5},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL},
{"PANIER_VIDE_B",48,0,0,{1,119,8,6},0,(void*) NULL,0,(void*) NULL,0,(void*) NULL}};

struct __InputEntry __Examen_Esterel_InputTable [] = {
{"REMPLIR_DEBUT",97,"integer",0,-3,0,0,_check_integer,Examen_Esterel_IS_REMPLIR_DEBUT,0,{1,157,13,0}},
{"REMPLIR_A",93,"integer",0,-3,0,1,_check_integer,Examen_Esterel_IS_REMPLIR_A,0,{1,158,13,0}},
{"REMPLIR_B",94,"integer",0,-3,0,2,_check_integer,Examen_Esterel_IS_REMPLIR_B,0,{1,159,13,0}},
{"REMPLIR_FIN",47,"integer",0,-3,0,3,_check_integer,Examen_Esterel_IS_REMPLIR_FIN,0,{1,160,13,0}},
{"PANIER_PLEIN_DEBUT",72,"integer",0,-3,0,4,_check_integer,Examen_Esterel_IS_PANIER_PLEIN_DEBUT,0,{1,161,13,0}},
{"PANIER_PLEIN_A",68,"integer",0,-3,0,5,_check_integer,Examen_Esterel_IS_PANIER_PLEIN_A,0,{1,162,13,0}},
{"PANIER_PLEIN_B",69,"integer",0,-3,0,6,_check_integer,Examen_Esterel_IS_PANIER_PLEIN_B,0,{1,163,13,0}},
{"PANIER_PLEIN_SORTIE",69,"integer",0,-3,0,7,_check_integer,Examen_Esterel_IS_PANIER_PLEIN_SORTIE,0,{1,164,13,0}},
{"VIDER_DEBUT",37,0,0,-1,0,8,0,Examen_Esterel_IS_VIDER_DEBUT,0,{1,165,13,0}},
{"VIDER_A",33,0,0,-1,0,9,0,Examen_Esterel_IS_VIDER_A,0,{1,165,26,0}},
{"VIDER_B",34,0,0,-1,0,10,0,Examen_Esterel_IS_VIDER_B,0,{1,165,35,0}},
{"FIN",19,"integer",0,-3,0,11,_check_integer,Examen_Esterel_IS_FIN,0,{1,166,13,0}}};

struct __VariableEntry __Examen_Esterel_VariableTable [] = {
{"__Examen_Esterel_V0","V0","integer",-3,1,0,(char*)&__Examen_Esterel_V0,"REMPLIR_DEBUT",0,0,0,{1,157,13,0}},
{"__Examen_Esterel_V1","V1","boolean",-2,2,0,(char*)&__Examen_Esterel_V1,"REMPLIR_DEBUT",0,0,0,{1,157,13,0}},
{"__Examen_Esterel_V2","V2","integer",-3,1,0,(char*)&__Examen_Esterel_V2,"REMPLIR_A",0,0,0,{1,158,13,0}},
{"__Examen_Esterel_V3","V3","boolean",-2,2,0,(char*)&__Examen_Esterel_V3,"REMPLIR_A",0,0,0,{1,158,13,0}},
{"__Examen_Esterel_V4","V4","integer",-3,1,0,(char*)&__Examen_Esterel_V4,"REMPLIR_B",0,0,0,{1,159,13,0}},
{"__Examen_Esterel_V5","V5","boolean",-2,2,0,(char*)&__Examen_Esterel_V5,"REMPLIR_B",0,0,0,{1,159,13,0}},
{"__Examen_Esterel_V6","V6","integer",-3,1,0,(char*)&__Examen_Esterel_V6,"REMPLIR_FIN",0,0,0,{1,160,13,0}},
{"__Examen_Esterel_V7","V7","boolean",-2,2,0,(char*)&__Examen_Esterel_V7,"REMPLIR_FIN",0,0,0,{1,160,13,0}},
{"__Examen_Esterel_V8","V8","integer",-3,1,0,(char*)&__Examen_Esterel_V8,"PANIER_PLEIN_DEBUT",0,0,0,{1,161,13,0}},
{"__Examen_Esterel_V9","V9","boolean",-2,2,0,(char*)&__Examen_Esterel_V9,"PANIER_PLEIN_DEBUT",0,0,0,{1,161,13,0}},
{"__Examen_Esterel_V10","V10","integer",-3,1,0,(char*)&__Examen_Esterel_V10,"PANIER_PLEIN_A",0,0,0,{1,162,13,0}},
{"__Examen_Esterel_V11","V11","boolean",-2,2,0,(char*)&__Examen_Esterel_V11,"PANIER_PLEIN_A",0,0,0,{1,162,13,0}},
{"__Examen_Esterel_V12","V12","integer",-3,1,0,(char*)&__Examen_Esterel_V12,"PANIER_PLEIN_B",0,0,0,{1,163,13,0}},
{"__Examen_Esterel_V13","V13","boolean",-2,2,0,(char*)&__Examen_Esterel_V13,"PANIER_PLEIN_B",0,0,0,{1,163,13,0}},
{"__Examen_Esterel_V14","V14","integer",-3,1,0,(char*)&__Examen_Esterel_V14,"PANIER_PLEIN_SORTIE",0,0,0,{1,164,13,0}},
{"__Examen_Esterel_V15","V15","boolean",-2,2,0,(char*)&__Examen_Esterel_V15,"PANIER_PLEIN_SORTIE",0,0,0,{1,164,13,0}},
{"__Examen_Esterel_V16","V16","boolean",-2,2,0,(char*)&__Examen_Esterel_V16,"VIDER_DEBUT",0,0,0,{1,165,13,0}},
{"__Examen_Esterel_V17","V17","boolean",-2,2,0,(char*)&__Examen_Esterel_V17,"VIDER_A",0,0,0,{1,165,26,0}},
{"__Examen_Esterel_V18","V18","boolean",-2,2,0,(char*)&__Examen_Esterel_V18,"VIDER_B",0,0,0,{1,165,35,0}},
{"__Examen_Esterel_V19","V19","integer",-3,1,0,(char*)&__Examen_Esterel_V19,"FIN",0,0,0,{1,166,13,0}},
{"__Examen_Esterel_V20","V20","boolean",-2,2,0,(char*)&__Examen_Esterel_V20,"FIN",0,0,0,{1,166,13,0}},
{"__Examen_Esterel_V21","V21","integer",-3,0,0,(char*)&__Examen_Esterel_V21,"n",0,0,0,{1,10,5,1}},
{"__Examen_Esterel_V22","V22","integer",-3,0,0,(char*)&__Examen_Esterel_V22,"n",0,0,0,{1,28,5,2}},
{"__Examen_Esterel_V23","V23","integer",-3,0,0,(char*)&__Examen_Esterel_V23,"n",0,0,0,{1,46,5,3}},
{"__Examen_Esterel_V24","V24","integer",-3,0,0,(char*)&__Examen_Esterel_V24,"n",0,0,0,{1,64,5,4}},
{"__Examen_Esterel_V25","V25","integer",-3,0,0,(char*)&__Examen_Esterel_V25,"n",0,0,0,{1,85,5,5}},
{"__Examen_Esterel_V26","V26","integer",-3,3,0,(char*)&__Examen_Esterel_V26,"0",0,0,0,{1,91,9,5}},
{"__Examen_Esterel_V27","V27","integer",-3,0,0,(char*)&__Examen_Esterel_V27,"n",0,0,0,{1,112,5,6}},
{"__Examen_Esterel_V28","V28","integer",-3,3,0,(char*)&__Examen_Esterel_V28,"0",0,0,0,{1,118,9,6}},
{"__Examen_Esterel_V29","V29","integer",-3,0,0,(char*)&__Examen_Esterel_V29,"n",0,0,0,{1,139,5,7}},
{"__Examen_Esterel_V30","V30","integer",-3,3,0,(char*)&__Examen_Esterel_V30,"0",0,0,0,{1,145,9,7}}
};

struct __HaltEntry __Examen_Esterel_HaltTable [] = {
{{1,182,1,0}},
{{1,12,3,1}},
{{1,14,3,1}},
{{1,15,9,1}},
{{1,30,3,2}},
{{1,32,3,2}},
{{1,33,9,2}},
{{1,48,3,3}},
{{1,50,3,3}},
{{1,51,9,3}},
{{1,66,3,4}},
{{1,68,3,4}},
{{1,70,3,4}},
{{1,87,3,5}},
{{1,89,3,5}},
{{1,91,3,5}},
{{1,97,5,5}},
{{1,114,3,6}},
{{1,116,3,6}},
{{1,118,3,6}},
{{1,124,5,6}},
{{1,141,3,7}},
{{1,143,3,7}},
{{1,145,3,7}},
{{1,147,5,7}}
};


static void __Examen_Esterel__reset_input () {
__Examen_Esterel_V1 = _false;
__Examen_Esterel_V3 = _false;
__Examen_Esterel_V5 = _false;
__Examen_Esterel_V7 = _false;
__Examen_Esterel_V9 = _false;
__Examen_Esterel_V11 = _false;
__Examen_Esterel_V13 = _false;
__Examen_Esterel_V15 = _false;
__Examen_Esterel_V16 = _false;
__Examen_Esterel_V17 = _false;
__Examen_Esterel_V18 = _false;
__Examen_Esterel_V20 = _false;
}


/* MODULE DATA FOR SIMULATION */

int Examen_Esterel();
int Examen_Esterel_reset();

static struct __ModuleEntry __Examen_Esterel_ModuleData = {
"Simulation interface release 5","Examen_Esterel",
8,0,14,12,0,0,12,0,2,0,0,31,0,25,0,0,0,
__Examen_Esterel_HaltList,
__Examen_Esterel_AwaitedList,
__Examen_Esterel_EmittedList,
__Examen_Esterel_StartedList,
__Examen_Esterel_KilledList,
__Examen_Esterel_SuspendedList,
__Examen_Esterel_ActiveList,
0,0,
Examen_Esterel_initialize,Examen_Esterel,Examen_Esterel_reset,
__Examen_Esterel_show_variable,__Examen_Esterel_set_variable,__Examen_Esterel_check_value,0,
__Examen_Esterel_InstanceTable,
0,
__Examen_Esterel_SignalTable,__Examen_Esterel_InputTable,0,
0,0,
__Examen_Esterel_VariableTable,
0,
__Examen_Esterel_HaltTable,
0};

/* REDEFINABLE BIT TYPE */

#ifndef __SSC_BIT_TYPE_DEFINED
typedef char __SSC_BIT_TYPE;
#endif

/* REGISTER VARIABLES */

static __SSC_BIT_TYPE __Examen_Esterel_R[25] = {_true,
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

int Examen_Esterel () {
/* AUXILIARY VARIABLES */

static __SSC_BIT_TYPE E[63];

__Examen_Esterel_ModuleData.awaited_list = __Examen_Esterel_AwaitedList;
__ResetModuleEntryBeforeReaction();
if ((__CheckVariables(__Examen_Esterel_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__Examen_Esterel_A1())) {
__CheckVariables(__Examen_Esterel_CheckArray[13]);__Examen_Esterel_A13();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A13\n");
#endif
}
E[0] = __Examen_Esterel_R[15]&&!(__Examen_Esterel_R[0]);
E[1] = E[0]&&(__CheckVariables(__Examen_Esterel_CheckArray[66]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 66\n"),
#endif
__Examen_Esterel_A66());
E[2] = (__Examen_Esterel_R[16]&&!(__Examen_Esterel_R[0]))||E[1];
E[3] = __Examen_Esterel_R[6]&&!(__Examen_Esterel_R[0]);
E[4] = __Examen_Esterel_R[18]&&!(__Examen_Esterel_R[0]);
E[5] = (__CheckVariables(__Examen_Esterel_CheckArray[10]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 10\n"),
#endif
__Examen_Esterel_A10())||E[4];
if (E[5]) {
__AppendToList(__Examen_Esterel_EmittedList,9);
}
E[6] = (__Examen_Esterel_R[5]&&!(__Examen_Esterel_R[0]))||(__Examen_Esterel_R[6]&&E[3]&&!(E[5]));
E[7] = (__CheckVariables(__Examen_Esterel_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__Examen_Esterel_A6())||E[6];
if (E[7]) {
__AppendToList(__Examen_Esterel_EmittedList,5);
}
E[8] = E[2]&&!(E[7]);
if (E[8]) {
__AppendToList(__Examen_Esterel_EmittedList,12);
}
if (E[8]) {
__CheckVariables(__Examen_Esterel_CheckArray[57]);__Examen_Esterel_A57();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A57\n");
#endif
}
E[9] = (__CheckVariables(__Examen_Esterel_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__Examen_Esterel_A2())||E[8];
if (E[9]) {
__AppendToList(__Examen_Esterel_EmittedList,1);
}
if (E[9]) {
__CheckVariables(__Examen_Esterel_CheckArray[14]);__Examen_Esterel_A14();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A14\n");
#endif
}
E[10] = __Examen_Esterel_R[19]&&!(__Examen_Esterel_R[0]);
E[11] = E[10]&&(__CheckVariables(__Examen_Esterel_CheckArray[67]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 67\n"),
#endif
__Examen_Esterel_A67());
E[12] = (__Examen_Esterel_R[20]&&!(__Examen_Esterel_R[0]))||E[11];
E[13] = __Examen_Esterel_R[9]&&!(__Examen_Esterel_R[0]);
E[14] = __Examen_Esterel_R[22]&&!(__Examen_Esterel_R[0]);
E[15] = (__CheckVariables(__Examen_Esterel_CheckArray[11]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 11\n"),
#endif
__Examen_Esterel_A11())||E[14];
if (E[15]) {
__AppendToList(__Examen_Esterel_EmittedList,10);
}
E[16] = (__Examen_Esterel_R[8]&&!(__Examen_Esterel_R[0]))||(__Examen_Esterel_R[9]&&E[13]&&!(E[15]));
E[17] = (__CheckVariables(__Examen_Esterel_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__Examen_Esterel_A7())||E[16];
if (E[17]) {
__AppendToList(__Examen_Esterel_EmittedList,6);
}
E[18] = E[12]&&!(E[17]);
if (E[18]) {
__AppendToList(__Examen_Esterel_EmittedList,13);
}
if (E[18]) {
__CheckVariables(__Examen_Esterel_CheckArray[61]);__Examen_Esterel_A61();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A61\n");
#endif
}
E[19] = (__CheckVariables(__Examen_Esterel_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__Examen_Esterel_A3())||E[18];
if (E[19]) {
__AppendToList(__Examen_Esterel_EmittedList,2);
}
if (E[19]) {
__CheckVariables(__Examen_Esterel_CheckArray[15]);__Examen_Esterel_A15();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A15\n");
#endif
}
E[20] = __Examen_Esterel_R[23]&&!(__Examen_Esterel_R[0]);
E[21] = E[20]&&(__CheckVariables(__Examen_Esterel_CheckArray[68]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 68\n"),
#endif
__Examen_Esterel_A68());
E[22] = __Examen_Esterel_R[11]&&!(__Examen_Esterel_R[0]);
E[23] = (__CheckVariables(__Examen_Esterel_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__Examen_Esterel_A8())||E[22];
if (E[23]) {
__AppendToList(__Examen_Esterel_EmittedList,7);
}
E[24] = (__Examen_Esterel_R[24]&&!(__Examen_Esterel_R[0]))||(E[21]&&!(E[23]));
if (E[24]) {
__CheckVariables(__Examen_Esterel_CheckArray[65]);__Examen_Esterel_A65();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A65\n");
#endif
}
E[25] = (__CheckVariables(__Examen_Esterel_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__Examen_Esterel_A4())||E[24];
if (E[25]) {
__AppendToList(__Examen_Esterel_EmittedList,3);
}
if (E[25]) {
__CheckVariables(__Examen_Esterel_CheckArray[16]);__Examen_Esterel_A16();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A16\n");
#endif
}
E[26] = __Examen_Esterel_R[3]&&!(__Examen_Esterel_R[0]);
E[27] = __Examen_Esterel_R[14]&&!(__Examen_Esterel_R[0]);
E[28] = (__CheckVariables(__Examen_Esterel_CheckArray[9]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 9\n"),
#endif
__Examen_Esterel_A9())||E[27];
if (E[28]) {
__AppendToList(__Examen_Esterel_EmittedList,8);
}
E[29] = (__Examen_Esterel_R[2]&&!(__Examen_Esterel_R[0]))||(__Examen_Esterel_R[3]&&E[26]&&!(E[28]));
if (E[29]) {
__CheckVariables(__Examen_Esterel_CheckArray[39]);__Examen_Esterel_A39();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A39\n");
#endif
}
E[30] = (__CheckVariables(__Examen_Esterel_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__Examen_Esterel_A5())||E[29];
if (E[30]) {
__AppendToList(__Examen_Esterel_EmittedList,4);
}
if (E[30]) {
__CheckVariables(__Examen_Esterel_CheckArray[17]);__Examen_Esterel_A17();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A17\n");
#endif
}
if (E[6]) {
__CheckVariables(__Examen_Esterel_CheckArray[43]);__Examen_Esterel_A43();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A43\n");
#endif
}
if (E[7]) {
__CheckVariables(__Examen_Esterel_CheckArray[18]);__Examen_Esterel_A18();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A18\n");
#endif
}
if (E[16]) {
__CheckVariables(__Examen_Esterel_CheckArray[47]);__Examen_Esterel_A47();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A47\n");
#endif
}
if (E[17]) {
__CheckVariables(__Examen_Esterel_CheckArray[19]);__Examen_Esterel_A19();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A19\n");
#endif
}
if (E[22]) {
__CheckVariables(__Examen_Esterel_CheckArray[51]);__Examen_Esterel_A51();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A51\n");
#endif
}
if (E[23]) {
__CheckVariables(__Examen_Esterel_CheckArray[20]);__Examen_Esterel_A20();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A20\n");
#endif
}
if (E[28]) {
__CheckVariables(__Examen_Esterel_CheckArray[21]);__Examen_Esterel_A21();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A21\n");
#endif
}
if (E[5]) {
__CheckVariables(__Examen_Esterel_CheckArray[22]);__Examen_Esterel_A22();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A22\n");
#endif
}
if (E[15]) {
__CheckVariables(__Examen_Esterel_CheckArray[23]);__Examen_Esterel_A23();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A23\n");
#endif
}
E[31] = __Examen_Esterel_R[12]&&!(__Examen_Esterel_R[0]);
if (E[31]) {
__CheckVariables(__Examen_Esterel_CheckArray[52]);__Examen_Esterel_A52();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A52\n");
#endif
}
E[32] = (__CheckVariables(__Examen_Esterel_CheckArray[12]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 12\n"),
#endif
__Examen_Esterel_A12())||E[31];
if (E[32]) {
__AppendToList(__Examen_Esterel_EmittedList,11);
}
if (E[32]) {
__CheckVariables(__Examen_Esterel_CheckArray[24]);__Examen_Esterel_A24();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A24\n");
#endif
}
E[33] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__Examen_Esterel_A1()));
if (E[33]) {
__CheckVariables(__Examen_Esterel_CheckArray[69]);__Examen_Esterel_A69();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A69\n");
#endif
}
E[34] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[2]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 2\n"),
#endif
__Examen_Esterel_A2()));
if (E[34]) {
__CheckVariables(__Examen_Esterel_CheckArray[70]);__Examen_Esterel_A70();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A70\n");
#endif
}
E[35] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[3]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 3\n"),
#endif
__Examen_Esterel_A3()));
if (E[35]) {
__CheckVariables(__Examen_Esterel_CheckArray[71]);__Examen_Esterel_A71();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A71\n");
#endif
}
E[36] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[4]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 4\n"),
#endif
__Examen_Esterel_A4()));
if (E[36]) {
__CheckVariables(__Examen_Esterel_CheckArray[72]);__Examen_Esterel_A72();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A72\n");
#endif
}
E[37] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[5]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 5\n"),
#endif
__Examen_Esterel_A5()));
if (E[37]) {
__CheckVariables(__Examen_Esterel_CheckArray[73]);__Examen_Esterel_A73();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A73\n");
#endif
}
E[38] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[6]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 6\n"),
#endif
__Examen_Esterel_A6()));
if (E[38]) {
__CheckVariables(__Examen_Esterel_CheckArray[74]);__Examen_Esterel_A74();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A74\n");
#endif
}
E[39] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[7]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 7\n"),
#endif
__Examen_Esterel_A7()));
if (E[39]) {
__CheckVariables(__Examen_Esterel_CheckArray[75]);__Examen_Esterel_A75();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A75\n");
#endif
}
E[40] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[8]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 8\n"),
#endif
__Examen_Esterel_A8()));
if (E[40]) {
__CheckVariables(__Examen_Esterel_CheckArray[76]);__Examen_Esterel_A76();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A76\n");
#endif
}
E[41] = __Examen_Esterel_R[0]&&!((__CheckVariables(__Examen_Esterel_CheckArray[12]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 12\n"),
#endif
__Examen_Esterel_A12()));
if (E[41]) {
__CheckVariables(__Examen_Esterel_CheckArray[77]);__Examen_Esterel_A77();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A77\n");
#endif
}
E[42] = !(_true);
E[26] = E[26]&&E[28];
if (E[26]) {
__CheckVariables(__Examen_Esterel_CheckArray[40]);__Examen_Esterel_A40();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A40\n");
#endif
}
if (__Examen_Esterel_R[0]) {
__CheckVariables(__Examen_Esterel_CheckArray[37]);__Examen_Esterel_A37();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A37\n");
#endif
}
E[43] = E[26]||__Examen_Esterel_R[0];
E[44] = E[43]&&(__CheckVariables(__Examen_Esterel_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__Examen_Esterel_A1());
E[45] = __Examen_Esterel_R[1]&&!(__Examen_Esterel_R[0]);
E[46] = E[45]&&(__CheckVariables(__Examen_Esterel_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__Examen_Esterel_A1());
E[46] = E[44]||E[46];
if (E[46]) {
__CheckVariables(__Examen_Esterel_CheckArray[38]);__Examen_Esterel_A38();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A38\n");
#endif
}
E[43] = E[43]&&!((__CheckVariables(__Examen_Esterel_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__Examen_Esterel_A1()));
E[45] = E[45]&&!((__CheckVariables(__Examen_Esterel_CheckArray[1]),
#ifdef TRACE_ACTION
fprintf(stderr, "test 1\n"),
#endif
__Examen_Esterel_A1()));
E[45] = E[43]||(__Examen_Esterel_R[1]&&E[45]);
E[3] = E[3]&&E[5];
if (E[3]) {
__CheckVariables(__Examen_Esterel_CheckArray[44]);__Examen_Esterel_A44();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A44\n");
#endif
}
if (__Examen_Esterel_R[0]) {
__CheckVariables(__Examen_Esterel_CheckArray[41]);__Examen_Esterel_A41();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A41\n");
#endif
}
E[43] = E[3]||__Examen_Esterel_R[0];
E[44] = __Examen_Esterel_R[4]&&!(__Examen_Esterel_R[0]);
E[47] = (E[43]&&E[9])||(E[44]&&E[9]);
if (E[47]) {
__CheckVariables(__Examen_Esterel_CheckArray[42]);__Examen_Esterel_A42();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A42\n");
#endif
}
E[44] = (E[43]&&!(E[9]))||(__Examen_Esterel_R[4]&&E[44]&&!(E[9]));
E[13] = E[13]&&E[15];
if (E[13]) {
__CheckVariables(__Examen_Esterel_CheckArray[48]);__Examen_Esterel_A48();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A48\n");
#endif
}
if (__Examen_Esterel_R[0]) {
__CheckVariables(__Examen_Esterel_CheckArray[45]);__Examen_Esterel_A45();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A45\n");
#endif
}
E[43] = E[13]||__Examen_Esterel_R[0];
E[48] = __Examen_Esterel_R[7]&&!(__Examen_Esterel_R[0]);
E[49] = (E[43]&&E[19])||(E[48]&&E[19]);
if (E[49]) {
__CheckVariables(__Examen_Esterel_CheckArray[46]);__Examen_Esterel_A46();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A46\n");
#endif
}
E[48] = (E[43]&&!(E[19]))||(__Examen_Esterel_R[7]&&E[48]&&!(E[19]));
if (E[31]) {
__CheckVariables(__Examen_Esterel_CheckArray[53]);__Examen_Esterel_A53();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A53\n");
#endif
}
if (__Examen_Esterel_R[0]) {
__CheckVariables(__Examen_Esterel_CheckArray[49]);__Examen_Esterel_A49();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A49\n");
#endif
}
E[43] = E[31]||__Examen_Esterel_R[0];
E[50] = __Examen_Esterel_R[10]&&!(__Examen_Esterel_R[0]);
E[51] = (E[43]&&E[25])||(E[50]&&E[25]);
if (E[51]) {
__CheckVariables(__Examen_Esterel_CheckArray[50]);__Examen_Esterel_A50();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A50\n");
#endif
}
E[50] = (E[43]&&!(E[25]))||(__Examen_Esterel_R[10]&&E[50]&&!(E[25]));
if (__Examen_Esterel_R[0]) {
__CheckVariables(__Examen_Esterel_CheckArray[54]);__Examen_Esterel_A54();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A54\n");
#endif
}
E[43] = __Examen_Esterel_R[13]&&!(__Examen_Esterel_R[0]);
E[52] = __Examen_Esterel_R[0]||E[8]||(__Examen_Esterel_R[13]&&E[43]&&!(E[30]));
E[43] = E[43]&&E[30];
if (E[43]) {
__CheckVariables(__Examen_Esterel_CheckArray[55]);__Examen_Esterel_A55();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A55\n");
#endif
}
if (E[27]) {
__CheckVariables(__Examen_Esterel_CheckArray[56]);__Examen_Esterel_A56();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A56\n");
#endif
}
E[1] = E[27]||(__Examen_Esterel_R[15]&&E[0]&&!(E[1]));
E[2] = E[2]&&E[7];
if (__Examen_Esterel_R[0]) {
__CheckVariables(__Examen_Esterel_CheckArray[58]);__Examen_Esterel_A58();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A58\n");
#endif
}
E[0] = __Examen_Esterel_R[17]&&!(__Examen_Esterel_R[0]);
E[53] = __Examen_Esterel_R[0]||E[18]||(__Examen_Esterel_R[17]&&E[0]&&!(E[7]));
E[0] = E[0]&&E[7];
if (E[0]) {
__CheckVariables(__Examen_Esterel_CheckArray[59]);__Examen_Esterel_A59();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A59\n");
#endif
}
if (E[4]) {
__CheckVariables(__Examen_Esterel_CheckArray[60]);__Examen_Esterel_A60();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A60\n");
#endif
}
E[11] = E[4]||(__Examen_Esterel_R[19]&&E[10]&&!(E[11]));
E[12] = E[12]&&E[17];
if (__Examen_Esterel_R[0]) {
__CheckVariables(__Examen_Esterel_CheckArray[62]);__Examen_Esterel_A62();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A62\n");
#endif
}
E[10] = __Examen_Esterel_R[21]&&!(__Examen_Esterel_R[0]);
E[54] = __Examen_Esterel_R[0]||E[24]||(__Examen_Esterel_R[21]&&E[10]&&!(E[17]));
E[10] = E[10]&&E[17];
if (E[10]) {
__CheckVariables(__Examen_Esterel_CheckArray[63]);__Examen_Esterel_A63();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A63\n");
#endif
}
if (E[14]) {
__CheckVariables(__Examen_Esterel_CheckArray[64]);__Examen_Esterel_A64();
#ifdef TRACE_ACTION
fprintf(stderr, "__Examen_Esterel_A64\n");
#endif
}
E[20] = E[14]||(__Examen_Esterel_R[23]&&E[20]&&!(E[21]));
E[21] = E[21]&&E[23];
E[55] = __Examen_Esterel_R[2]||__Examen_Esterel_R[3]||__Examen_Esterel_R[1];
E[56] = __Examen_Esterel_R[5]||__Examen_Esterel_R[6]||__Examen_Esterel_R[4];
E[57] = __Examen_Esterel_R[8]||__Examen_Esterel_R[9]||__Examen_Esterel_R[7];
E[58] = __Examen_Esterel_R[11]||__Examen_Esterel_R[12]||__Examen_Esterel_R[10];
E[59] = __Examen_Esterel_R[13]||__Examen_Esterel_R[14]||__Examen_Esterel_R[15]||__Examen_Esterel_R[16];
E[60] = __Examen_Esterel_R[17]||__Examen_Esterel_R[18]||__Examen_Esterel_R[19]||__Examen_Esterel_R[20];
E[61] = __Examen_Esterel_R[21]||__Examen_Esterel_R[22]||__Examen_Esterel_R[23]||__Examen_Esterel_R[24];
E[62] = E[55]||E[56]||E[57]||E[58]||E[59]||E[60]||E[61];
E[61] = (E[46]||E[29]||E[45]||E[47]||E[6]||E[44]||E[49]||E[16]||E[48]||E[51]||E[22]||E[50]||E[52]||E[43]||E[1]||E[2]||E[53]||E[0]||E[11]||E[12]||E[54]||E[10]||E[20]||E[21])&&((E[62]&&!(E[55]))||E[46]||E[29]||E[45])&&((E[62]&&!(E[56]))||E[47]||E[6]||E[44])&&((E[62]&&!(E[57]))||E[49]||E[16]||E[48])&&((E[62]&&!(E[58]))||E[51]||E[22]||E[50])&&((E[62]&&!(E[59]))||E[52]||E[43]||E[1]||E[2])&&((E[62]&&!(E[60]))||E[53]||E[0]||E[11]||E[12])&&((E[62]&&!(E[61]))||E[54]||E[10]||E[20]||E[21]);
__Examen_Esterel_R[0] = !(_true);
__Examen_Esterel_R[1] = E[45];
if (__Examen_Esterel_R[1]) { __AppendToList(__Examen_Esterel_HaltList,1); }
__Examen_Esterel_R[2] = E[46];
if (__Examen_Esterel_R[2]) { __AppendToList(__Examen_Esterel_HaltList,2); }
__Examen_Esterel_R[3] = E[29];
if (__Examen_Esterel_R[3]) { __AppendToList(__Examen_Esterel_HaltList,3); }
__Examen_Esterel_R[4] = E[44];
if (__Examen_Esterel_R[4]) { __AppendToList(__Examen_Esterel_HaltList,4); }
__Examen_Esterel_R[5] = E[47];
if (__Examen_Esterel_R[5]) { __AppendToList(__Examen_Esterel_HaltList,5); }
__Examen_Esterel_R[6] = E[6];
if (__Examen_Esterel_R[6]) { __AppendToList(__Examen_Esterel_HaltList,6); }
__Examen_Esterel_R[7] = E[48];
if (__Examen_Esterel_R[7]) { __AppendToList(__Examen_Esterel_HaltList,7); }
__Examen_Esterel_R[8] = E[49];
if (__Examen_Esterel_R[8]) { __AppendToList(__Examen_Esterel_HaltList,8); }
__Examen_Esterel_R[9] = E[16];
if (__Examen_Esterel_R[9]) { __AppendToList(__Examen_Esterel_HaltList,9); }
__Examen_Esterel_R[10] = E[50];
if (__Examen_Esterel_R[10]) { __AppendToList(__Examen_Esterel_HaltList,10); }
__Examen_Esterel_R[11] = E[51];
if (__Examen_Esterel_R[11]) { __AppendToList(__Examen_Esterel_HaltList,11); }
__Examen_Esterel_R[12] = E[22];
if (__Examen_Esterel_R[12]) { __AppendToList(__Examen_Esterel_HaltList,12); }
__Examen_Esterel_R[13] = E[52];
if (__Examen_Esterel_R[13]) { __AppendToList(__Examen_Esterel_HaltList,13); }
__Examen_Esterel_R[14] = E[43];
if (__Examen_Esterel_R[14]) { __AppendToList(__Examen_Esterel_HaltList,14); }
__Examen_Esterel_R[15] = E[1];
if (__Examen_Esterel_R[15]) { __AppendToList(__Examen_Esterel_HaltList,15); }
__Examen_Esterel_R[16] = E[2];
if (__Examen_Esterel_R[16]) { __AppendToList(__Examen_Esterel_HaltList,16); }
__Examen_Esterel_R[17] = E[53];
if (__Examen_Esterel_R[17]) { __AppendToList(__Examen_Esterel_HaltList,17); }
__Examen_Esterel_R[18] = E[0];
if (__Examen_Esterel_R[18]) { __AppendToList(__Examen_Esterel_HaltList,18); }
__Examen_Esterel_R[19] = E[11];
if (__Examen_Esterel_R[19]) { __AppendToList(__Examen_Esterel_HaltList,19); }
__Examen_Esterel_R[20] = E[12];
if (__Examen_Esterel_R[20]) { __AppendToList(__Examen_Esterel_HaltList,20); }
__Examen_Esterel_R[21] = E[54];
if (__Examen_Esterel_R[21]) { __AppendToList(__Examen_Esterel_HaltList,21); }
__Examen_Esterel_R[22] = E[10];
if (__Examen_Esterel_R[22]) { __AppendToList(__Examen_Esterel_HaltList,22); }
__Examen_Esterel_R[23] = E[20];
if (__Examen_Esterel_R[23]) { __AppendToList(__Examen_Esterel_HaltList,23); }
__Examen_Esterel_R[24] = E[21];
if (__Examen_Esterel_R[24]) { __AppendToList(__Examen_Esterel_HaltList,24); }
if (!E[61]) { __AppendToList(__Examen_Esterel_HaltList,0); }
__ResetModuleEntryAfterReaction();
__Examen_Esterel_ModuleData.awaited_list = __Examen_Esterel_AllAwaitedList;
__Examen_Esterel__reset_input();
return E[61];
}

/* AUTOMATON RESET */

int Examen_Esterel_reset () {
__Examen_Esterel_ModuleData.awaited_list = __Examen_Esterel_AwaitedList;
__ResetModuleEntry();
__Examen_Esterel_ModuleData.awaited_list = __Examen_Esterel_AllAwaitedList;
__Examen_Esterel_ModuleData.state = 0;
__Examen_Esterel_R[0] = _true;
__Examen_Esterel_R[1] = _false;
__Examen_Esterel_R[2] = _false;
__Examen_Esterel_R[3] = _false;
__Examen_Esterel_R[4] = _false;
__Examen_Esterel_R[5] = _false;
__Examen_Esterel_R[6] = _false;
__Examen_Esterel_R[7] = _false;
__Examen_Esterel_R[8] = _false;
__Examen_Esterel_R[9] = _false;
__Examen_Esterel_R[10] = _false;
__Examen_Esterel_R[11] = _false;
__Examen_Esterel_R[12] = _false;
__Examen_Esterel_R[13] = _false;
__Examen_Esterel_R[14] = _false;
__Examen_Esterel_R[15] = _false;
__Examen_Esterel_R[16] = _false;
__Examen_Esterel_R[17] = _false;
__Examen_Esterel_R[18] = _false;
__Examen_Esterel_R[19] = _false;
__Examen_Esterel_R[20] = _false;
__Examen_Esterel_R[21] = _false;
__Examen_Esterel_R[22] = _false;
__Examen_Esterel_R[23] = _false;
__Examen_Esterel_R[24] = _false;
__Examen_Esterel__reset_input();
return 0;
}
char* CompilationType = "Compiled Sorted Equations";

int __NumberOfModules = 1;
struct __ModuleEntry* __ModuleTable[] = {
&__Examen_Esterel_ModuleData
};

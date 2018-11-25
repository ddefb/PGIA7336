/* --- Generated the 25/11/2018 at 0:9 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s controller irrigation.ept --- */

#ifndef IRRIGATION_TYPES_H
#define IRRIGATION_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
#include "controller_controller.h"
typedef enum {
  Irrigation__St_4_ON,
  Irrigation__St_4_OFF
} Irrigation__st_4;

Irrigation__st_4 Irrigation__st_4_of_string(char* s);

char* string_of_Irrigation__st_4(Irrigation__st_4 x, char* buf);

typedef enum {
  Irrigation__St_3_ON,
  Irrigation__St_3_OFF
} Irrigation__st_3;

Irrigation__st_3 Irrigation__st_3_of_string(char* s);

char* string_of_Irrigation__st_3(Irrigation__st_3 x, char* buf);

typedef enum {
  Irrigation__St_2_LOWER_STATE,
  Irrigation__St_2_HIGHER_STATE
} Irrigation__st_2;

Irrigation__st_2 Irrigation__st_2_of_string(char* s);

char* string_of_Irrigation__st_2(Irrigation__st_2 x, char* buf);

typedef enum {
  Irrigation__St_1_ON,
  Irrigation__St_1_OFF
} Irrigation__st_1;

Irrigation__st_1 Irrigation__st_1_of_string(char* s);

char* string_of_Irrigation__st_1(Irrigation__st_1 x, char* buf);

typedef enum {
  Irrigation__St_LOWER_STATE,
  Irrigation__St_HIGHER_STATE
} Irrigation__st;

Irrigation__st Irrigation__st_of_string(char* s);

char* string_of_Irrigation__st(Irrigation__st x, char* buf);

typedef enum {
  Irrigation__Lower,
  Irrigation__Higher
} Irrigation__modes;

Irrigation__modes Irrigation__modes_of_string(char* s);

char* string_of_Irrigation__modes(Irrigation__modes x, char* buf);

#endif // IRRIGATION_TYPES_H

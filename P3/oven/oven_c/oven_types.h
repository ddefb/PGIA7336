/* --- Generated the 17/10/2018 at 9:6 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s oven oven.ept --- */

#ifndef OVEN_TYPES_H
#define OVEN_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Oven__St_1_STANDBY,
  Oven__St_1_REHEAT,
  Oven__St_1_OFF,
  Oven__St_1_MAINTAIN,
  Oven__St_1_HEAT
} Oven__st_1;

Oven__st_1 Oven__st_1_of_string(char* s);

char* string_of_Oven__st_1(Oven__st_1 x, char* buf);

typedef enum {
  Oven__St_STANDBY,
  Oven__St_REHEAT,
  Oven__St_OFF,
  Oven__St_MAINTAIN,
  Oven__St_HEAT
} Oven__st;

Oven__st Oven__st_of_string(char* s);

char* string_of_Oven__st(Oven__st x, char* buf);

#endif // OVEN_TYPES_H

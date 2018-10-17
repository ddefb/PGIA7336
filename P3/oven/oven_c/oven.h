/* --- Generated the 17/10/2018 at 9:6 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s oven oven.ept --- */

#ifndef OVEN_H
#define OVEN_H

#include "oven_types.h"
typedef struct Oven__oven_mem {
  int v_55;
  int v_54;
  int v_53;
  int pnr;
} Oven__oven_mem;

typedef struct Oven__oven_out {
  int s1;
  int p1;
} Oven__oven_out;

void Oven__oven_reset(Oven__oven_mem* self);

void Oven__oven_step(int f, int s, int c, int cold, int temp_ok,
                     Oven__oven_out* _out, Oven__oven_mem* self);

typedef struct Oven__onetask_mem {
  int v_108;
  int v_107;
  int v_106;
  int pnr;
} Oven__onetask_mem;

typedef struct Oven__onetask_out {
  int s1;
  int p1;
} Oven__onetask_out;

void Oven__onetask_reset(Oven__onetask_mem* self);

void Oven__onetask_step(int f, int s, int c, int cold, int temp_ok,
                        Oven__onetask_out* _out, Oven__onetask_mem* self);

#endif // OVEN_H

/* --- Generated the 25/11/2018 at 0:9 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s controller irrigation.ept --- */

#ifndef IRRIGATION_H
#define IRRIGATION_H

#include "irrigation_types.h"
#include "controller_controller.h"
typedef struct Irrigation__threshold_checker_mem {
  int ck_1_2;
  int pnr;
} Irrigation__threshold_checker_mem;

typedef struct Irrigation__threshold_checker_out {
  int r;
  int mode_1;
} Irrigation__threshold_checker_out;

void Irrigation__threshold_checker_reset(Irrigation__threshold_checker_mem* self);

void Irrigation__threshold_checker_step(int h, int oi, int os, int cc,
                                        Irrigation__threshold_checker_out* _out,
                                        Irrigation__threshold_checker_mem* self);

typedef struct Irrigation__device_mem {
  int ck_1;
  int pnr;
} Irrigation__device_mem;

typedef struct Irrigation__device_out {
  int device_on;
} Irrigation__device_out;

void Irrigation__device_reset(Irrigation__device_mem* self);

void Irrigation__device_step(int c, Irrigation__device_out* _out,
                             Irrigation__device_mem* self);

typedef struct Irrigation__controller_mem {
  int ck_7_1;
  int ck_5_1;
  int ck_3_1;
  int pnr_2;
  int pnr_1;
  int pnr;
} Irrigation__controller_mem;

typedef struct Irrigation__controller_out {
  int bomb_on;
  int valve_on;
  int r;
  int threshold_1;
} Irrigation__controller_out;

void Irrigation__controller_reset(Irrigation__controller_mem* self);

void Irrigation__controller_step(int h, int oi, int os, int cc,
                                 Irrigation__controller_out* _out,
                                 Irrigation__controller_mem* self);

#endif // IRRIGATION_H

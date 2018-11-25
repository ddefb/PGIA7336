/* --- Generated the 25/11/2018 at 0:9 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c controller_controller.ept --- */

#ifndef CONTROLLER_CONTROLLER_H
#define CONTROLLER_CONTROLLER_H

#include "controller_controller_types.h"
typedef struct Controller_controller__controller_controller_controller_c1_valve_out {
  int controller_c1_valve;
} Controller_controller__controller_controller_controller_c1_valve_out;

void Controller_controller__controller_controller_controller_c1_valve_step(
int controller_v_7, int controller_v_8, int controller_v_9,
int controller_ck_3_1, int controller_pnr_2, int controller_ck_5_1,
int controller_pnr_1, int controller_ck_7_1, int controller_pnr,
int p_controller_c1_valve, int p_controller_c1_bomb, int controller_c1_bomb,
Controller_controller__controller_controller_controller_c1_valve_out* _out);

typedef struct Controller_controller__controller_controller_controller_c1_bomb_out {
  int controller_c1_bomb;
} Controller_controller__controller_controller_controller_c1_bomb_out;

void Controller_controller__controller_controller_controller_c1_bomb_step(
int controller_v_7, int controller_v_8, int controller_v_9,
int controller_ck_3_1, int controller_pnr_2, int controller_ck_5_1,
int controller_pnr_1, int controller_ck_7_1, int controller_pnr,
int p_controller_c1_valve, int p_controller_c1_bomb,
Controller_controller__controller_controller_controller_c1_bomb_out* _out);

typedef struct Controller_controller__controller_controller_out {
  int controller_c1_valve;
  int controller_c1_bomb;
} Controller_controller__controller_controller_out;

void Controller_controller__controller_controller_step(int controller_v_7,
                                                       int controller_v_8,
                                                       int controller_v_9,
                                                       int controller_ck_3_1,
                                                       int controller_pnr_2,
                                                       int controller_ck_5_1,
                                                       int controller_pnr_1,
                                                       int controller_ck_7_1,
                                                       int controller_pnr,
                                                       int p_controller_c1_valve,
                                                       int p_controller_c1_bomb,
                                                       Controller_controller__controller_controller_out* _out);

#endif // CONTROLLER_CONTROLLER_H

/* --- Generated the 25/11/2018 at 0:9 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c controller_controller.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controller_controller.h"

void Controller_controller__controller_controller_controller_c1_valve_step(
  int controller_v_7, int controller_v_8, int controller_v_9,
  int controller_ck_3_1, int controller_pnr_2, int controller_ck_5_1,
  int controller_pnr_1, int controller_ck_7_1, int controller_pnr,
  int p_controller_c1_valve, int p_controller_c1_bomb,
  int controller_c1_bomb,
  Controller_controller__controller_controller_controller_c1_valve_out* _out) {
  
  int v_11;
  int v_10;
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
  int sub_0;
  int sub_1;
  int sub_2;
  v_7 = !(controller_ck_7_1);
  v_8 = (v_7&&false);
  v_5 = !(controller_ck_7_1);
  v_6 = (v_5||false);
  if (controller_c1_bomb) {
    v_9 = v_6;
  } else {
    v_9 = v_8;
  };
  v_2 = (controller_c1_bomb||false);
  v_1 = (controller_ck_7_1&&false);
  v = (controller_ck_7_1||false);
  if (controller_c1_bomb) {
    sub_1 = v;
  } else {
    sub_1 = v_1;
  };
  if (controller_v_9) {
    v_3 = sub_1;
  } else {
    v_3 = v_2;
  };
  if (controller_v_8) {
    v_4 = sub_1;
  } else {
    v_4 = v_3;
  };
  sub_2 = (controller_c1_bomb&&false);
  if (controller_v_9) {
    v_10 = sub_2;
  } else {
    v_10 = v_9;
  };
  if (controller_v_8) {
    v_11 = sub_2;
  } else {
    v_11 = v_10;
  };
  if (controller_v_7) {
    sub_0 = v_4;
  } else {
    sub_0 = v_11;
  };
  _out->controller_c1_valve = sub_0;;
}

void Controller_controller__controller_controller_controller_c1_bomb_step(
  int controller_v_7, int controller_v_8, int controller_v_9,
  int controller_ck_3_1, int controller_pnr_2, int controller_ck_5_1,
  int controller_pnr_1, int controller_ck_7_1, int controller_pnr,
  int p_controller_c1_valve, int p_controller_c1_bomb,
  Controller_controller__controller_controller_controller_c1_bomb_out* _out) {
  
  int v_17;
  int v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v;
  int sub_0;
  int sub_1;
  v_15 = !(controller_ck_7_1);
  v_14 = !(controller_v_9);
  v_16 = (v_14&&v_15);
  if (controller_v_8) {
    v_17 = false;
  } else {
    v_17 = v_16;
  };
  v = !(controller_v_9);
  sub_1 = controller_ck_7_1;
  v_12 = (v||sub_1);
  if (controller_v_8) {
    v_13 = sub_1;
  } else {
    v_13 = v_12;
  };
  if (controller_v_7) {
    sub_0 = v_13;
  } else {
    sub_0 = v_17;
  };
  _out->controller_c1_bomb = sub_0;;
}

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
                                                       Controller_controller__controller_controller_out* _out) {
  Controller_controller__controller_controller_controller_c1_bomb_out Controller_controller__controller_controller_controller_c1_bomb_out_st;
  Controller_controller__controller_controller_controller_c1_valve_out Controller_controller__controller_controller_controller_c1_valve_out_st;
  Controller_controller__controller_controller_controller_c1_bomb_step(
  controller_v_7, controller_v_8, controller_v_9, controller_ck_3_1,
  controller_pnr_2, controller_ck_5_1, controller_pnr_1, controller_ck_7_1,
  controller_pnr, p_controller_c1_valve, p_controller_c1_bomb,
  &Controller_controller__controller_controller_controller_c1_bomb_out_st);
  _out->controller_c1_bomb = Controller_controller__controller_controller_controller_c1_bomb_out_st.controller_c1_bomb;
  Controller_controller__controller_controller_controller_c1_valve_step(
  controller_v_7, controller_v_8, controller_v_9, controller_ck_3_1,
  controller_pnr_2, controller_ck_5_1, controller_pnr_1, controller_ck_7_1,
  controller_pnr, p_controller_c1_valve, p_controller_c1_bomb,
  _out->controller_c1_bomb,
  &Controller_controller__controller_controller_controller_c1_valve_out_st);
  _out->controller_c1_valve = Controller_controller__controller_controller_controller_c1_valve_out_st.controller_c1_valve;
}


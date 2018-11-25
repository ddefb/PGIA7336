/* --- Generated the 25/11/2018 at 0:9 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s controller irrigation.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "irrigation.h"

void Irrigation__threshold_checker_reset(Irrigation__threshold_checker_mem* self) {
  self->pnr = false;
  self->ck_1_2 = false;
}

void Irrigation__threshold_checker_step(int h, int oi, int os, int cc,
                                        Irrigation__threshold_checker_out* _out,
                                        Irrigation__threshold_checker_mem* self) {
  
  int nr_St_HIGHER_STATE;
  int ns_St_HIGHER_STATE_1;
  int mode_St_HIGHER_STATE_1;
  int r_St_HIGHER_STATE;
  int nr_St_LOWER_STATE;
  int ns_St_LOWER_STATE_1;
  int mode_St_LOWER_STATE_1;
  int r_St_LOWER_STATE;
  int ck_1_1;
  int v_3;
  int v_2;
  int v_1;
  int v;
  int r_2_St_HIGHER_STATE;
  int s_St_HIGHER_STATE_1;
  int r_2_St_LOWER_STATE;
  int s_St_LOWER_STATE_1;
  int s_1;
  int ns_1;
  int r_2;
  int nr;
  if (self->ck_1_2) {
    v = (h<oi);
    if (v) {
      r_2_St_HIGHER_STATE = true;
    } else {
      r_2_St_HIGHER_STATE = self->pnr;
    };
    r_2 = r_2_St_HIGHER_STATE;
    if (v) {
      s_St_HIGHER_STATE_1 = false;
    } else {
      s_St_HIGHER_STATE_1 = true;
    };
    s_1 = s_St_HIGHER_STATE_1;
  } else {
    v_2 = (h>=cc);
    v_1 = (h>=os);
    v_3 = (v_1||v_2);
    if (v_3) {
      r_2_St_LOWER_STATE = true;
      s_St_LOWER_STATE_1 = true;
    } else {
      r_2_St_LOWER_STATE = self->pnr;
      s_St_LOWER_STATE_1 = false;
    };
    r_2 = r_2_St_LOWER_STATE;
    s_1 = s_St_LOWER_STATE_1;
  };
  ck_1_1 = s_1;
  if (ck_1_1) {
    r_St_HIGHER_STATE = h;
    _out->r = r_St_HIGHER_STATE;
    mode_St_HIGHER_STATE_1 = true;
    _out->mode_1 = mode_St_HIGHER_STATE_1;
    nr_St_HIGHER_STATE = false;
    nr = nr_St_HIGHER_STATE;
    ns_St_HIGHER_STATE_1 = true;
    ns_1 = ns_St_HIGHER_STATE_1;
  } else {
    r_St_LOWER_STATE = h;
    mode_St_LOWER_STATE_1 = false;
    nr_St_LOWER_STATE = false;
    ns_St_LOWER_STATE_1 = false;
    _out->r = r_St_LOWER_STATE;
    _out->mode_1 = mode_St_LOWER_STATE_1;
    nr = nr_St_LOWER_STATE;
    ns_1 = ns_St_LOWER_STATE_1;
  };
  self->pnr = nr;
  self->ck_1_2 = ns_1;;
}

void Irrigation__device_reset(Irrigation__device_mem* self) {
  self->pnr = false;
  self->ck_1 = true;
}

void Irrigation__device_step(int c, Irrigation__device_out* _out,
                             Irrigation__device_mem* self) {
  
  int nr_St_1_ON;
  int ns_St_1_ON_1;
  int device_on_St_1_ON;
  int nr_St_1_OFF;
  int ns_St_1_OFF_1;
  int device_on_St_1_OFF;
  int ck_2_1;
  int v;
  int r_St_1_ON;
  int s_St_1_ON_1;
  int r_St_1_OFF;
  int s_St_1_OFF_1;
  int s_1;
  int ns_1;
  int r;
  int nr;
  if (self->ck_1) {
    if (c) {
      r_St_1_OFF = true;
      s_St_1_OFF_1 = false;
    } else {
      r_St_1_OFF = self->pnr;
      s_St_1_OFF_1 = true;
    };
    r = r_St_1_OFF;
    s_1 = s_St_1_OFF_1;
  } else {
    v = !(c);
    if (v) {
      r_St_1_ON = true;
    } else {
      r_St_1_ON = self->pnr;
    };
    r = r_St_1_ON;
    if (v) {
      s_St_1_ON_1 = true;
    } else {
      s_St_1_ON_1 = false;
    };
    s_1 = s_St_1_ON_1;
  };
  ck_2_1 = s_1;
  if (ck_2_1) {
    device_on_St_1_OFF = false;
    nr_St_1_OFF = false;
    ns_St_1_OFF_1 = true;
    _out->device_on = device_on_St_1_OFF;
    nr = nr_St_1_OFF;
    ns_1 = ns_St_1_OFF_1;
  } else {
    device_on_St_1_ON = true;
    _out->device_on = device_on_St_1_ON;
    nr_St_1_ON = false;
    nr = nr_St_1_ON;
    ns_St_1_ON_1 = false;
    ns_1 = ns_St_1_ON_1;
  };
  self->pnr = nr;
  self->ck_1 = ns_1;;
}

void Irrigation__controller_reset(Irrigation__controller_mem* self) {
  self->pnr = false;
  self->ck_7_1 = false;
  self->pnr_1 = false;
  self->ck_5_1 = true;
  self->pnr_2 = false;
  self->ck_3_1 = true;
}

void Irrigation__controller_step(int h, int oi, int os, int cc,
                                 Irrigation__controller_out* _out,
                                 Irrigation__controller_mem* self) {
  Controller_controller__controller_controller_out Controller_controller__controller_controller_out_st;
  
  int nr_St_2_HIGHER_STATE;
  int ns_St_2_HIGHER_STATE_1;
  int mode_St_2_HIGHER_STATE_1;
  int r_1_St_2_HIGHER_STATE;
  int nr_St_2_LOWER_STATE;
  int ns_St_2_LOWER_STATE_1;
  int mode_St_2_LOWER_STATE_1;
  int r_1_St_2_LOWER_STATE;
  int ck_8_1;
  int v_10;
  int v_9;
  int v_8;
  int v_7;
  int r_3_St_2_HIGHER_STATE;
  int s_St_2_HIGHER_STATE_1;
  int r_3_St_2_LOWER_STATE;
  int s_St_2_LOWER_STATE_1;
  int nr_1_St_3_ON;
  int ns_1_St_3_ON_1;
  int device_on_1_St_3_ON;
  int nr_1_St_3_OFF;
  int ns_1_St_3_OFF_1;
  int device_on_1_St_3_OFF;
  int ck_6_1;
  int v_6;
  int r_4_St_3_ON;
  int s_1_St_3_ON_1;
  int r_4_St_3_OFF;
  int s_1_St_3_OFF_1;
  int nr_2_St_4_ON;
  int ns_2_St_4_ON_1;
  int device_on_St_4_ON;
  int nr_2_St_4_OFF;
  int ns_2_St_4_OFF_1;
  int device_on_St_4_OFF;
  int ck_4_1;
  int v_5;
  int r_5_St_4_ON;
  int s_2_St_4_ON_1;
  int r_5_St_4_OFF;
  int s_2_St_4_OFF_1;
  int s_2_1;
  int ns_2_1;
  int r_5;
  int nr_2;
  int s_1_1;
  int ns_1_1;
  int r_4;
  int nr_1;
  int s_1_2;
  int ns_1_2;
  int r_3;
  int nr;
  int h_1;
  int oi_1;
  int os_1;
  int cc_1;
  int r_1;
  int mode_1;
  int c_1;
  int device_on_1;
  int c;
  int device_on;
  int v;
  int v_4;
  int ck_1;
  int rule_Lower;
  int rule_Higher;
  int rule;
  int c1_valve;
  int c1_bomb;
  h_1 = h;
  oi_1 = oi;
  os_1 = os;
  cc_1 = cc;
  if (self->ck_7_1) {
    v_7 = (h_1<oi_1);
    if (v_7) {
      r_3_St_2_HIGHER_STATE = true;
    } else {
      r_3_St_2_HIGHER_STATE = self->pnr;
    };
    r_3 = r_3_St_2_HIGHER_STATE;
    if (v_7) {
      s_St_2_HIGHER_STATE_1 = false;
    } else {
      s_St_2_HIGHER_STATE_1 = true;
    };
    s_1_2 = s_St_2_HIGHER_STATE_1;
  } else {
    v_9 = (h_1>=cc_1);
    v_8 = (h_1>=os_1);
    v_10 = (v_8||v_9);
    if (v_10) {
      r_3_St_2_LOWER_STATE = true;
      s_St_2_LOWER_STATE_1 = true;
    } else {
      r_3_St_2_LOWER_STATE = self->pnr;
      s_St_2_LOWER_STATE_1 = false;
    };
    r_3 = r_3_St_2_LOWER_STATE;
    s_1_2 = s_St_2_LOWER_STATE_1;
  };
  ck_8_1 = s_1_2;
  Controller_controller__controller_controller_step(v_7, v_8, v_9,
                                                    self->ck_3_1,
                                                    self->pnr_2,
                                                    self->ck_5_1,
                                                    self->pnr_1,
                                                    self->ck_7_1, self->pnr,
                                                    true, true,
                                                    &Controller_controller__controller_controller_out_st);
  c1_valve = Controller_controller__controller_controller_out_st.controller_c1_valve;
  c1_bomb = Controller_controller__controller_controller_out_st.controller_c1_bomb;
  c_1 = c1_valve;
  c = c1_bomb;
  if (ck_8_1) {
    r_1_St_2_HIGHER_STATE = h_1;
    r_1 = r_1_St_2_HIGHER_STATE;
    mode_St_2_HIGHER_STATE_1 = true;
    mode_1 = mode_St_2_HIGHER_STATE_1;
    nr_St_2_HIGHER_STATE = false;
    nr = nr_St_2_HIGHER_STATE;
    ns_St_2_HIGHER_STATE_1 = true;
    ns_1_2 = ns_St_2_HIGHER_STATE_1;
  } else {
    r_1_St_2_LOWER_STATE = h_1;
    mode_St_2_LOWER_STATE_1 = false;
    nr_St_2_LOWER_STATE = false;
    ns_St_2_LOWER_STATE_1 = false;
    r_1 = r_1_St_2_LOWER_STATE;
    mode_1 = mode_St_2_LOWER_STATE_1;
    nr = nr_St_2_LOWER_STATE;
    ns_1_2 = ns_St_2_LOWER_STATE_1;
  };
  _out->threshold_1 = mode_1;
  ck_1 = _out->threshold_1;
  _out->r = r_1;
  if (self->ck_5_1) {
    if (c_1) {
      r_4_St_3_OFF = true;
      s_1_St_3_OFF_1 = false;
    } else {
      r_4_St_3_OFF = self->pnr_1;
      s_1_St_3_OFF_1 = true;
    };
    r_4 = r_4_St_3_OFF;
    s_1_1 = s_1_St_3_OFF_1;
  } else {
    v_6 = !(c_1);
    if (v_6) {
      r_4_St_3_ON = true;
    } else {
      r_4_St_3_ON = self->pnr_1;
    };
    r_4 = r_4_St_3_ON;
    if (v_6) {
      s_1_St_3_ON_1 = true;
    } else {
      s_1_St_3_ON_1 = false;
    };
    s_1_1 = s_1_St_3_ON_1;
  };
  ck_6_1 = s_1_1;
  if (ck_6_1) {
    device_on_1_St_3_OFF = false;
    nr_1_St_3_OFF = false;
    ns_1_St_3_OFF_1 = true;
    device_on_1 = device_on_1_St_3_OFF;
    nr_1 = nr_1_St_3_OFF;
    ns_1_1 = ns_1_St_3_OFF_1;
  } else {
    device_on_1_St_3_ON = true;
    device_on_1 = device_on_1_St_3_ON;
    nr_1_St_3_ON = false;
    nr_1 = nr_1_St_3_ON;
    ns_1_St_3_ON_1 = false;
    ns_1_1 = ns_1_St_3_ON_1;
  };
  _out->valve_on = device_on_1;
  if (ck_1) {
    v_4 = !(_out->valve_on);
  };
  if (self->ck_3_1) {
    if (c) {
      r_5_St_4_OFF = true;
      s_2_St_4_OFF_1 = false;
    } else {
      r_5_St_4_OFF = self->pnr_2;
      s_2_St_4_OFF_1 = true;
    };
    r_5 = r_5_St_4_OFF;
    s_2_1 = s_2_St_4_OFF_1;
  } else {
    v_5 = !(c);
    if (v_5) {
      r_5_St_4_ON = true;
    } else {
      r_5_St_4_ON = self->pnr_2;
    };
    r_5 = r_5_St_4_ON;
    if (v_5) {
      s_2_St_4_ON_1 = true;
    } else {
      s_2_St_4_ON_1 = false;
    };
    s_2_1 = s_2_St_4_ON_1;
  };
  ck_4_1 = s_2_1;
  if (ck_4_1) {
    device_on_St_4_OFF = false;
    nr_2_St_4_OFF = false;
    ns_2_St_4_OFF_1 = true;
    device_on = device_on_St_4_OFF;
    nr_2 = nr_2_St_4_OFF;
    ns_2_1 = ns_2_St_4_OFF_1;
  } else {
    device_on_St_4_ON = true;
    device_on = device_on_St_4_ON;
    nr_2_St_4_ON = false;
    nr_2 = nr_2_St_4_ON;
    ns_2_St_4_ON_1 = false;
    ns_2_1 = ns_2_St_4_ON_1;
  };
  _out->bomb_on = device_on;
  if (ck_1) {
    v = !(_out->bomb_on);
    rule_Higher = (v&&v_4);
    rule = rule_Higher;
  } else {
    rule_Lower = (_out->bomb_on&&_out->valve_on);
    rule = rule_Lower;
  };
  self->pnr = nr;
  self->ck_7_1 = ns_1_2;
  self->pnr_1 = nr_1;
  self->ck_5_1 = ns_1_1;
  self->pnr_2 = nr_2;
  self->ck_3_1 = ns_2_1;;
}


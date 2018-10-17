/* --- Generated the 17/10/2018 at 9:6 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s oven oven.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "oven.h"

void Oven__oven_reset(Oven__oven_mem* self) {
  self->pnr = false;
  self->v_53 = true;
  self->v_54 = false;
  self->v_55 = false;
}

void Oven__oven_step(int f, int s, int c, int cold, int temp_ok,
                     Oven__oven_out* _out, Oven__oven_mem* self) {
  
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_48;
  int v_47;
  int v_46;
  int v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v_35;
  int v_34;
  int v_33;
  int v_32;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int v_23;
  int ns_St_REHEAT_2_0;
  int ns_St_REHEAT_3_0_0;
  int ns_St_REHEAT_3_0_1;
  int ns_St_REHEAT_2_1;
  int ns_St_REHEAT_3_1_0;
  int ns_St_REHEAT_3_1_1;
  int ns_St_MAINTAIN_2_0;
  int ns_St_MAINTAIN_3_0_0;
  int ns_St_MAINTAIN_3_0_1;
  int ns_St_MAINTAIN_2_1;
  int ns_St_MAINTAIN_3_1_0;
  int ns_St_MAINTAIN_3_1_1;
  int ns_St_HEAT_2_0;
  int ns_St_HEAT_3_0_0;
  int ns_St_HEAT_3_0_1;
  int ns_St_HEAT_2_1;
  int ns_St_HEAT_3_1_0;
  int ns_St_HEAT_3_1_1;
  int ns_St_STANDBY_2_0;
  int ns_St_STANDBY_3_0_0;
  int ns_St_STANDBY_3_0_1;
  int ns_St_STANDBY_2_1;
  int ns_St_STANDBY_3_1_0;
  int ns_St_STANDBY_3_1_1;
  int ns_St_OFF_2_0;
  int ns_St_OFF_3_0_0;
  int ns_St_OFF_3_0_1;
  int ns_St_OFF_2_1;
  int ns_St_OFF_3_1_0;
  int ns_St_OFF_3_1_1;
  int ck_1_2_0;
  int ck_1_3_0_0;
  int ck_1_3_0_1;
  int ck_1_2_1;
  int ck_1_3_1_0;
  int ck_1_3_1_1;
  int nr_St_REHEAT;
  int ns_St_REHEAT_3;
  int ns_St_REHEAT_2;
  int ns_St_REHEAT_1;
  int p1_St_REHEAT;
  int s1_St_REHEAT;
  int nr_St_MAINTAIN;
  int ns_St_MAINTAIN_3;
  int ns_St_MAINTAIN_2;
  int ns_St_MAINTAIN_1;
  int p1_St_MAINTAIN;
  int s1_St_MAINTAIN;
  int nr_St_HEAT;
  int ns_St_HEAT_3;
  int ns_St_HEAT_2;
  int ns_St_HEAT_1;
  int p1_St_HEAT;
  int s1_St_HEAT;
  int nr_St_STANDBY;
  int ns_St_STANDBY_3;
  int ns_St_STANDBY_2;
  int ns_St_STANDBY_1;
  int p1_St_STANDBY;
  int s1_St_STANDBY;
  int nr_St_OFF;
  int ns_St_OFF_3;
  int ns_St_OFF_2;
  int ns_St_OFF_1;
  int p1_St_OFF;
  int s1_St_OFF;
  int ck_1_3;
  int ck_1_2;
  int ck_1_1;
  int v_10_2_0;
  int v_10_3_0_0;
  int v_10_3_0_1;
  int v_10_2_1;
  int v_10_3_1_0;
  int v_10_3_1_1;
  int v_11;
  int v_10_3;
  int v_10_2;
  int v_10_1;
  int v_9;
  int v_8;
  int v_7;
  int v_5_2_0;
  int v_5_3_0_0;
  int v_5_3_0_1;
  int v_5_2_1;
  int v_5_3_1_0;
  int v_5_3_1_1;
  int v_6;
  int v_5_3;
  int v_5_2;
  int v_5_1;
  int v_3_2_0;
  int v_3_3_0_0;
  int v_3_3_0_1;
  int v_3_2_1;
  int v_3_3_1_0;
  int v_3_3_1_1;
  int v_4;
  int v_3_3;
  int v_3_2;
  int v_3_1;
  int v_2;
  int v_2_1_0;
  int v_3_4_0_0;
  int v_3_4_0_1;
  int v_2_1_1;
  int v_3_4_1_0;
  int v_3_4_1_1;
  int v_1;
  int v_3_4;
  int v_2_1;
  int v_1_1;
  int v_75;
  int v_74;
  int v_73;
  int v_72;
  int v_71;
  int v_70;
  int v_69;
  int v_68;
  int v_67;
  int v_66;
  int v_65;
  int v_64;
  int v_63;
  int v_62;
  int v_61;
  int v_60;
  int v_59;
  int v_58;
  int v_57;
  int v_56;
  int s_2_St_REHEAT_2_0;
  int s_2_St_REHEAT_3_0_0;
  int s_2_St_REHEAT_3_0_1;
  int s_2_St_REHEAT_2_1;
  int s_2_St_REHEAT_3_1_0;
  int s_2_St_REHEAT_3_1_1;
  int s_2_St_MAINTAIN_2_0;
  int s_2_St_MAINTAIN_3_0_0;
  int s_2_St_MAINTAIN_3_0_1;
  int s_2_St_MAINTAIN_2_1;
  int s_2_St_MAINTAIN_3_1_0;
  int s_2_St_MAINTAIN_3_1_1;
  int s_2_St_HEAT_2_0;
  int s_2_St_HEAT_3_0_0;
  int s_2_St_HEAT_3_0_1;
  int s_2_St_HEAT_2_1;
  int s_2_St_HEAT_3_1_0;
  int s_2_St_HEAT_3_1_1;
  int s_2_St_STANDBY_2_0;
  int s_2_St_STANDBY_3_0_0;
  int s_2_St_STANDBY_3_0_1;
  int s_2_St_STANDBY_2_1;
  int s_2_St_STANDBY_3_1_0;
  int s_2_St_STANDBY_3_1_1;
  int s_2_St_OFF_2_0;
  int s_2_St_OFF_3_0_0;
  int s_2_St_OFF_3_0_1;
  int s_2_St_OFF_2_1;
  int s_2_St_OFF_3_1_0;
  int s_2_St_OFF_3_1_1;
  int ck_2_0;
  int ck_3_0_0;
  int ck_3_0_1;
  int ck_2_1;
  int ck_3_1_0;
  int ck_3_1_1;
  int r_St_REHEAT;
  int s_2_St_REHEAT_3;
  int s_2_St_REHEAT_2;
  int s_2_St_REHEAT_1;
  int r_St_MAINTAIN;
  int s_2_St_MAINTAIN_3;
  int s_2_St_MAINTAIN_2;
  int s_2_St_MAINTAIN_1;
  int r_St_HEAT;
  int s_2_St_HEAT_3;
  int s_2_St_HEAT_2;
  int s_2_St_HEAT_1;
  int r_St_STANDBY;
  int s_2_St_STANDBY_3;
  int s_2_St_STANDBY_2;
  int s_2_St_STANDBY_1;
  int r_St_OFF;
  int s_2_St_OFF_3;
  int s_2_St_OFF_2;
  int s_2_St_OFF_1;
  int ck_3;
  int ck_2;
  int ck_1_4;
  int s_2_2_0;
  int s_2_3_0_0;
  int s_2_3_0_1;
  int s_2_2_1;
  int s_2_3_1_0;
  int s_2_3_1_1;
  int ns_2_0;
  int ns_3_0_0;
  int ns_3_0_1;
  int ns_2_1;
  int ns_3_1_0;
  int ns_3_1_1;
  int s_2_3;
  int s_2_2;
  int s_2_1;
  int ns_3;
  int ns_2;
  int ns_1;
  int r;
  int nr;
  ck_1_4 = self->v_53;
  ck_2 = self->v_54;
  ck_3 = self->v_55;
  if (ck_1_4) {
    ck_2_1 = ck_2;
    if (ck_2_1) {
      ck_3_1_1 = ck_3;
      if (ck_3_1_1) {
        if (temp_ok) {
          v_6 = true;
        } else {
          v_6 = self->pnr;
        };
        if (f) {
          r_St_HEAT = true;
        } else {
          r_St_HEAT = v_6;
        };
        if (temp_ok) {
          v_5_1 = true;
        } else {
          v_5_1 = true;
        };
        if (f) {
          s_2_St_HEAT_1 = true;
        } else {
          s_2_St_HEAT_1 = v_5_1;
        };
        if (temp_ok) {
          v_5_2 = true;
        } else {
          v_5_2 = true;
        };
        if (f) {
          s_2_St_HEAT_2 = false;
        } else {
          s_2_St_HEAT_2 = v_5_2;
        };
        if (temp_ok) {
          v_5_3 = false;
        } else {
          v_5_3 = true;
        };
        if (f) {
          s_2_St_HEAT_3 = false;
        } else {
          s_2_St_HEAT_3 = v_5_3;
        };
        v_71 = r_St_HEAT;
        v_56 = s_2_St_HEAT_1;
        v_57 = s_2_St_HEAT_2;
        v_58 = s_2_St_HEAT_3;
      } else {
        if (f) {
          v_4 = true;
          v_3_1 = true;
          v_3_2 = false;
          v_3_3 = false;
        } else {
          v_4 = self->pnr;
          v_3_1 = true;
          v_3_2 = true;
          v_3_3 = false;
        };
        v_2 = (cold&&c);
        if (v_2) {
          r_St_MAINTAIN = true;
        } else {
          r_St_MAINTAIN = v_4;
        };
        v_71 = r_St_MAINTAIN;
        if (v_2) {
          s_2_St_MAINTAIN_1 = false;
        } else {
          s_2_St_MAINTAIN_1 = v_3_1;
        };
        v_56 = s_2_St_MAINTAIN_1;
        if (v_2) {
          s_2_St_MAINTAIN_2 = false;
        } else {
          s_2_St_MAINTAIN_2 = v_3_2;
        };
        v_57 = s_2_St_MAINTAIN_2;
        if (v_2) {
          s_2_St_MAINTAIN_3 = true;
        } else {
          s_2_St_MAINTAIN_3 = v_3_3;
        };
        v_58 = s_2_St_MAINTAIN_3;
      };
      v_65 = v_56;
      v_66 = v_57;
      v_67 = v_58;
      v_73 = v_71;
      if (ck_3_1_1) {
        if (v_5_1) {
          v_5_2_1 = v_5_2;
          if (v_5_2_1) {
            v_5_3_1_1 = v_5_3;
          } else {
            v_5_3_1_0 = v_5_3;
          };
        } else {
          v_5_2_0 = v_5_2;
          if (v_5_2_0) {
            v_5_3_0_1 = v_5_3;
          } else {
            v_5_3_0_0 = v_5_3;
          };
        };
        if (s_2_St_HEAT_1) {
          s_2_St_HEAT_2_1 = s_2_St_HEAT_2;
          if (s_2_St_HEAT_2_1) {
            s_2_St_HEAT_3_1_1 = s_2_St_HEAT_3;
          } else {
            s_2_St_HEAT_3_1_0 = s_2_St_HEAT_3;
          };
        } else {
          s_2_St_HEAT_2_0 = s_2_St_HEAT_2;
          if (s_2_St_HEAT_2_0) {
            s_2_St_HEAT_3_0_1 = s_2_St_HEAT_3;
          } else {
            s_2_St_HEAT_3_0_0 = s_2_St_HEAT_3;
          };
        };
      } else {
        if (v_3_1) {
          v_3_2_1 = v_3_2;
          if (v_3_2_1) {
            v_3_3_1_1 = v_3_3;
          } else {
            v_3_3_1_0 = v_3_3;
          };
        } else {
          v_3_2_0 = v_3_2;
          if (v_3_2_0) {
            v_3_3_0_1 = v_3_3;
          } else {
            v_3_3_0_0 = v_3_3;
          };
        };
        if (s_2_St_MAINTAIN_1) {
          s_2_St_MAINTAIN_2_1 = s_2_St_MAINTAIN_2;
          if (s_2_St_MAINTAIN_2_1) {
            s_2_St_MAINTAIN_3_1_1 = s_2_St_MAINTAIN_3;
          } else {
            s_2_St_MAINTAIN_3_1_0 = s_2_St_MAINTAIN_3;
          };
        } else {
          s_2_St_MAINTAIN_2_0 = s_2_St_MAINTAIN_2;
          if (s_2_St_MAINTAIN_2_0) {
            s_2_St_MAINTAIN_3_0_1 = s_2_St_MAINTAIN_3;
          } else {
            s_2_St_MAINTAIN_3_0_0 = s_2_St_MAINTAIN_3;
          };
        };
      };
    } else {
      ck_3_1_0 = ck_3;
      if (ck_3_1_0) {
        v_72 = true;
        v_59 = true;
        v_60 = true;
        v_61 = true;
      } else {
        v_9 = (s&&c);
        if (v_9) {
          v_11 = true;
          v_10_1 = true;
          v_10_2 = true;
          v_10_3 = true;
        } else {
          v_11 = self->pnr;
          v_10_1 = true;
          v_10_2 = false;
          v_10_3 = false;
        };
        v_7 = !(c);
        v_8 = (s&&v_7);
        if (v_8) {
          r_St_OFF = true;
        } else {
          r_St_OFF = v_11;
        };
        v_72 = r_St_OFF;
        if (v_8) {
          s_2_St_OFF_1 = false;
        } else {
          s_2_St_OFF_1 = v_10_1;
        };
        v_59 = s_2_St_OFF_1;
        if (v_8) {
          s_2_St_OFF_2 = false;
        } else {
          s_2_St_OFF_2 = v_10_2;
        };
        v_60 = s_2_St_OFF_2;
        if (v_8) {
          s_2_St_OFF_3 = false;
        } else {
          s_2_St_OFF_3 = v_10_3;
        };
        v_61 = s_2_St_OFF_3;
        if (v_10_1) {
          v_10_2_1 = v_10_2;
          if (v_10_2_1) {
            v_10_3_1_1 = v_10_3;
          } else {
            v_10_3_1_0 = v_10_3;
          };
        } else {
          v_10_2_0 = v_10_2;
          if (v_10_2_0) {
            v_10_3_0_1 = v_10_3;
          } else {
            v_10_3_0_0 = v_10_3;
          };
        };
        if (s_2_St_OFF_1) {
          s_2_St_OFF_2_1 = s_2_St_OFF_2;
          if (s_2_St_OFF_2_1) {
            s_2_St_OFF_3_1_1 = s_2_St_OFF_3;
          } else {
            s_2_St_OFF_3_1_0 = s_2_St_OFF_3;
          };
        } else {
          s_2_St_OFF_2_0 = s_2_St_OFF_2;
          if (s_2_St_OFF_2_0) {
            s_2_St_OFF_3_0_1 = s_2_St_OFF_3;
          } else {
            s_2_St_OFF_3_0_0 = s_2_St_OFF_3;
          };
        };
      };
      v_65 = v_59;
      v_66 = v_60;
      v_67 = v_61;
      v_73 = v_72;
    };
    s_2_1 = v_65;
    s_2_2 = v_66;
    s_2_3 = v_67;
    r = v_73;
  } else {
    ck_2_0 = ck_2;
    if (ck_2_0) {
      ck_3_0_1 = ck_3;
      v_68 = true;
      v_69 = true;
      v_70 = true;
      v_75 = true;
    } else {
      ck_3_0_0 = ck_3;
      if (ck_3_0_0) {
        if (f) {
          v_1 = true;
        } else {
          v_1 = self->pnr;
        };
        if (temp_ok) {
          r_St_REHEAT = true;
        } else {
          r_St_REHEAT = v_1;
        };
        v_74 = r_St_REHEAT;
        if (f) {
          v_1_1 = true;
        } else {
          v_1_1 = false;
        };
        if (temp_ok) {
          s_2_St_REHEAT_1 = true;
        } else {
          s_2_St_REHEAT_1 = v_1_1;
        };
        v_62 = s_2_St_REHEAT_1;
        if (f) {
          v_2_1 = false;
        } else {
          v_2_1 = false;
        };
        if (temp_ok) {
          s_2_St_REHEAT_2 = true;
        } else {
          s_2_St_REHEAT_2 = v_2_1;
        };
        v_63 = s_2_St_REHEAT_2;
        if (f) {
          v_3_4 = false;
        } else {
          v_3_4 = true;
        };
        if (temp_ok) {
          s_2_St_REHEAT_3 = false;
        } else {
          s_2_St_REHEAT_3 = v_3_4;
        };
        v_64 = s_2_St_REHEAT_3;
        if (v_1_1) {
          v_2_1_1 = v_2_1;
          if (v_2_1_1) {
            v_3_4_1_1 = v_3_4;
          } else {
            v_3_4_1_0 = v_3_4;
          };
        } else {
          v_2_1_0 = v_2_1;
          if (v_2_1_0) {
            v_3_4_0_1 = v_3_4;
          } else {
            v_3_4_0_0 = v_3_4;
          };
        };
      } else {
        if (c) {
          r_St_STANDBY = true;
          s_2_St_STANDBY_1 = true;
          s_2_St_STANDBY_2 = true;
          s_2_St_STANDBY_3 = true;
        } else {
          r_St_STANDBY = self->pnr;
          s_2_St_STANDBY_1 = false;
          s_2_St_STANDBY_2 = false;
          s_2_St_STANDBY_3 = false;
        };
        v_74 = r_St_STANDBY;
        v_62 = s_2_St_STANDBY_1;
        v_63 = s_2_St_STANDBY_2;
        v_64 = s_2_St_STANDBY_3;
      };
      v_68 = v_62;
      v_69 = v_63;
      v_70 = v_64;
      v_75 = v_74;
    };
    s_2_1 = v_68;
    s_2_2 = v_69;
    s_2_3 = v_70;
    r = v_75;
  };
  ck_1_1 = s_2_1;
  ck_1_2 = s_2_2;
  ck_1_3 = s_2_3;
  if (ck_1_1) {
    ck_1_2_1 = ck_1_2;
    if (ck_1_2_1) {
      ck_1_3_1_1 = ck_1_3;
      if (ck_1_3_1_1) {
        s1_St_HEAT = 2;
        p1_St_HEAT = 1500;
        nr_St_HEAT = false;
        ns_St_HEAT_1 = true;
        ns_St_HEAT_2 = true;
        ns_St_HEAT_3 = true;
        v_23 = s1_St_HEAT;
        v_28 = p1_St_HEAT;
        v_48 = nr_St_HEAT;
        v_33 = ns_St_HEAT_1;
        v_34 = ns_St_HEAT_2;
        v_35 = ns_St_HEAT_3;
      } else {
        s1_St_MAINTAIN = 3;
        v_23 = s1_St_MAINTAIN;
        p1_St_MAINTAIN = 300;
        v_28 = p1_St_MAINTAIN;
        nr_St_MAINTAIN = false;
        v_48 = nr_St_MAINTAIN;
        ns_St_MAINTAIN_1 = true;
        v_33 = ns_St_MAINTAIN_1;
        ns_St_MAINTAIN_2 = true;
        v_34 = ns_St_MAINTAIN_2;
        ns_St_MAINTAIN_3 = false;
        v_35 = ns_St_MAINTAIN_3;
      };
      v_25 = v_23;
      v_30 = v_28;
      v_42 = v_33;
      v_43 = v_34;
      v_44 = v_35;
      v_50 = v_48;
      if (ck_1_3_1_1) {
        if (ns_St_HEAT_1) {
          ns_St_HEAT_2_1 = ns_St_HEAT_2;
          if (ns_St_HEAT_2_1) {
            ns_St_HEAT_3_1_1 = ns_St_HEAT_3;
          } else {
            ns_St_HEAT_3_1_0 = ns_St_HEAT_3;
          };
        } else {
          ns_St_HEAT_2_0 = ns_St_HEAT_2;
          if (ns_St_HEAT_2_0) {
            ns_St_HEAT_3_0_1 = ns_St_HEAT_3;
          } else {
            ns_St_HEAT_3_0_0 = ns_St_HEAT_3;
          };
        };
      } else {
        if (ns_St_MAINTAIN_1) {
          ns_St_MAINTAIN_2_1 = ns_St_MAINTAIN_2;
          if (ns_St_MAINTAIN_2_1) {
            ns_St_MAINTAIN_3_1_1 = ns_St_MAINTAIN_3;
          } else {
            ns_St_MAINTAIN_3_1_0 = ns_St_MAINTAIN_3;
          };
        } else {
          ns_St_MAINTAIN_2_0 = ns_St_MAINTAIN_2;
          if (ns_St_MAINTAIN_2_0) {
            ns_St_MAINTAIN_3_0_1 = ns_St_MAINTAIN_3;
          } else {
            ns_St_MAINTAIN_3_0_0 = ns_St_MAINTAIN_3;
          };
        };
      };
    } else {
      ck_1_3_1_0 = ck_1_3;
      if (ck_1_3_1_0) {
        v_24 = 0;
        v_29 = 0;
        v_49 = true;
        v_36 = true;
        v_37 = true;
        v_38 = true;
      } else {
        s1_St_OFF = 0;
        v_24 = s1_St_OFF;
        p1_St_OFF = 0;
        v_29 = p1_St_OFF;
        nr_St_OFF = false;
        v_49 = nr_St_OFF;
        ns_St_OFF_1 = true;
        v_36 = ns_St_OFF_1;
        ns_St_OFF_2 = false;
        v_37 = ns_St_OFF_2;
        ns_St_OFF_3 = false;
        v_38 = ns_St_OFF_3;
        if (ns_St_OFF_1) {
          ns_St_OFF_2_1 = ns_St_OFF_2;
          if (ns_St_OFF_2_1) {
            ns_St_OFF_3_1_1 = ns_St_OFF_3;
          } else {
            ns_St_OFF_3_1_0 = ns_St_OFF_3;
          };
        } else {
          ns_St_OFF_2_0 = ns_St_OFF_2;
          if (ns_St_OFF_2_0) {
            ns_St_OFF_3_0_1 = ns_St_OFF_3;
          } else {
            ns_St_OFF_3_0_0 = ns_St_OFF_3;
          };
        };
      };
      v_25 = v_24;
      v_30 = v_29;
      v_42 = v_36;
      v_43 = v_37;
      v_44 = v_38;
      v_50 = v_49;
    };
    _out->s1 = v_25;
    _out->p1 = v_30;
    ns_1 = v_42;
    ns_2 = v_43;
    ns_3 = v_44;
    nr = v_50;
  } else {
    ck_1_2_0 = ck_1_2;
    if (ck_1_2_0) {
      ck_1_3_0_1 = ck_1_3;
      v_27 = 0;
      v_32 = 0;
      v_45 = true;
      v_46 = true;
      v_47 = true;
      v_52 = true;
    } else {
      ck_1_3_0_0 = ck_1_3;
      if (ck_1_3_0_0) {
        s1_St_REHEAT = 4;
        v_26 = s1_St_REHEAT;
        p1_St_REHEAT = 1000;
        v_31 = p1_St_REHEAT;
        nr_St_REHEAT = false;
        v_51 = nr_St_REHEAT;
        ns_St_REHEAT_1 = false;
        v_39 = ns_St_REHEAT_1;
        ns_St_REHEAT_2 = false;
        v_40 = ns_St_REHEAT_2;
        ns_St_REHEAT_3 = true;
        v_41 = ns_St_REHEAT_3;
      } else {
        s1_St_STANDBY = 1;
        p1_St_STANDBY = 0;
        nr_St_STANDBY = false;
        ns_St_STANDBY_1 = false;
        ns_St_STANDBY_2 = false;
        ns_St_STANDBY_3 = false;
        v_26 = s1_St_STANDBY;
        v_31 = p1_St_STANDBY;
        v_51 = nr_St_STANDBY;
        v_39 = ns_St_STANDBY_1;
        v_40 = ns_St_STANDBY_2;
        v_41 = ns_St_STANDBY_3;
      };
      v_27 = v_26;
      v_32 = v_31;
      v_45 = v_39;
      v_46 = v_40;
      v_47 = v_41;
      v_52 = v_51;
    };
    _out->s1 = v_27;
    _out->p1 = v_32;
    ns_1 = v_45;
    ns_2 = v_46;
    ns_3 = v_47;
    nr = v_52;
  };
  if (ns_1) {
    ns_2_1 = ns_2;
    if (ns_2_1) {
      ns_3_1_1 = ns_3;
    } else {
      ns_3_1_0 = ns_3;
    };
  } else {
    ns_2_0 = ns_2;
    if (ns_2_0) {
      ns_3_0_1 = ns_3;
    } else {
      ns_3_0_0 = ns_3;
    };
  };
  if (!(ck_1_1)) {
    if (!(ck_1_2_0)) {
      if (ck_1_3_0_0) {
        if (ns_St_REHEAT_1) {
          ns_St_REHEAT_2_1 = ns_St_REHEAT_2;
          if (ns_St_REHEAT_2_1) {
            ns_St_REHEAT_3_1_1 = ns_St_REHEAT_3;
          } else {
            ns_St_REHEAT_3_1_0 = ns_St_REHEAT_3;
          };
        } else {
          ns_St_REHEAT_2_0 = ns_St_REHEAT_2;
          if (ns_St_REHEAT_2_0) {
            ns_St_REHEAT_3_0_1 = ns_St_REHEAT_3;
          } else {
            ns_St_REHEAT_3_0_0 = ns_St_REHEAT_3;
          };
        };
      } else {
        if (ns_St_STANDBY_1) {
          ns_St_STANDBY_2_1 = ns_St_STANDBY_2;
          if (ns_St_STANDBY_2_1) {
            ns_St_STANDBY_3_1_1 = ns_St_STANDBY_3;
          } else {
            ns_St_STANDBY_3_1_0 = ns_St_STANDBY_3;
          };
        } else {
          ns_St_STANDBY_2_0 = ns_St_STANDBY_2;
          if (ns_St_STANDBY_2_0) {
            ns_St_STANDBY_3_0_1 = ns_St_STANDBY_3;
          } else {
            ns_St_STANDBY_3_0_0 = ns_St_STANDBY_3;
          };
        };
      };
    };
  };
  if (s_2_1) {
    s_2_2_1 = s_2_2;
    if (s_2_2_1) {
      s_2_3_1_1 = s_2_3;
    } else {
      s_2_3_1_0 = s_2_3;
    };
  } else {
    s_2_2_0 = s_2_2;
    if (s_2_2_0) {
      s_2_3_0_1 = s_2_3;
    } else {
      s_2_3_0_0 = s_2_3;
    };
  };
  if (!(ck_1_4)) {
    if (!(ck_2_0)) {
      if (ck_3_0_0) {
        if (s_2_St_REHEAT_1) {
          s_2_St_REHEAT_2_1 = s_2_St_REHEAT_2;
          if (s_2_St_REHEAT_2_1) {
            s_2_St_REHEAT_3_1_1 = s_2_St_REHEAT_3;
          } else {
            s_2_St_REHEAT_3_1_0 = s_2_St_REHEAT_3;
          };
        } else {
          s_2_St_REHEAT_2_0 = s_2_St_REHEAT_2;
          if (s_2_St_REHEAT_2_0) {
            s_2_St_REHEAT_3_0_1 = s_2_St_REHEAT_3;
          } else {
            s_2_St_REHEAT_3_0_0 = s_2_St_REHEAT_3;
          };
        };
      } else {
        if (s_2_St_STANDBY_1) {
          s_2_St_STANDBY_2_1 = s_2_St_STANDBY_2;
          if (s_2_St_STANDBY_2_1) {
            s_2_St_STANDBY_3_1_1 = s_2_St_STANDBY_3;
          } else {
            s_2_St_STANDBY_3_1_0 = s_2_St_STANDBY_3;
          };
        } else {
          s_2_St_STANDBY_2_0 = s_2_St_STANDBY_2;
          if (s_2_St_STANDBY_2_0) {
            s_2_St_STANDBY_3_0_1 = s_2_St_STANDBY_3;
          } else {
            s_2_St_STANDBY_3_0_0 = s_2_St_STANDBY_3;
          };
        };
      };
    };
  };
  self->pnr = nr;
  self->v_53 = ns_1;
  self->v_54 = ns_2;
  self->v_55 = ns_3;;
}

void Oven__onetask_reset(Oven__onetask_mem* self) {
  self->pnr = false;
  self->v_106 = true;
  self->v_107 = false;
  self->v_108 = false;
}

void Oven__onetask_step(int f, int s, int c, int cold, int temp_ok,
                        Oven__onetask_out* _out, Oven__onetask_mem* self) {
  
  int v_105;
  int v_104;
  int v_103;
  int v_102;
  int v_101;
  int v_100;
  int v_99;
  int v_98;
  int v_97;
  int v_96;
  int v_95;
  int v_94;
  int v_93;
  int v_92;
  int v_91;
  int v_90;
  int v_89;
  int v_88;
  int v_87;
  int v_86;
  int v_85;
  int v_84;
  int v_83;
  int v_82;
  int v_81;
  int v_80;
  int v_79;
  int v_78;
  int v_77;
  int v_76;
  int ns_St_1_REHEAT_2_0;
  int ns_St_1_REHEAT_3_0_0;
  int ns_St_1_REHEAT_3_0_1;
  int ns_St_1_REHEAT_2_1;
  int ns_St_1_REHEAT_3_1_0;
  int ns_St_1_REHEAT_3_1_1;
  int ns_St_1_MAINTAIN_2_0;
  int ns_St_1_MAINTAIN_3_0_0;
  int ns_St_1_MAINTAIN_3_0_1;
  int ns_St_1_MAINTAIN_2_1;
  int ns_St_1_MAINTAIN_3_1_0;
  int ns_St_1_MAINTAIN_3_1_1;
  int ns_St_1_HEAT_2_0;
  int ns_St_1_HEAT_3_0_0;
  int ns_St_1_HEAT_3_0_1;
  int ns_St_1_HEAT_2_1;
  int ns_St_1_HEAT_3_1_0;
  int ns_St_1_HEAT_3_1_1;
  int ns_St_1_STANDBY_2_0;
  int ns_St_1_STANDBY_3_0_0;
  int ns_St_1_STANDBY_3_0_1;
  int ns_St_1_STANDBY_2_1;
  int ns_St_1_STANDBY_3_1_0;
  int ns_St_1_STANDBY_3_1_1;
  int ns_St_1_OFF_2_0;
  int ns_St_1_OFF_3_0_0;
  int ns_St_1_OFF_3_0_1;
  int ns_St_1_OFF_2_1;
  int ns_St_1_OFF_3_1_0;
  int ns_St_1_OFF_3_1_1;
  int ck_2_2_0;
  int ck_2_3_0_0;
  int ck_2_3_0_1;
  int ck_2_2_1;
  int ck_2_3_1_0;
  int ck_2_3_1_1;
  int nr_St_1_REHEAT;
  int ns_St_1_REHEAT_3;
  int ns_St_1_REHEAT_2;
  int ns_St_1_REHEAT_1;
  int p1_1_St_1_REHEAT;
  int s1_1_St_1_REHEAT;
  int nr_St_1_MAINTAIN;
  int ns_St_1_MAINTAIN_3;
  int ns_St_1_MAINTAIN_2;
  int ns_St_1_MAINTAIN_1;
  int p1_1_St_1_MAINTAIN;
  int s1_1_St_1_MAINTAIN;
  int nr_St_1_HEAT;
  int ns_St_1_HEAT_3;
  int ns_St_1_HEAT_2;
  int ns_St_1_HEAT_1;
  int p1_1_St_1_HEAT;
  int s1_1_St_1_HEAT;
  int nr_St_1_STANDBY;
  int ns_St_1_STANDBY_3;
  int ns_St_1_STANDBY_2;
  int ns_St_1_STANDBY_1;
  int p1_1_St_1_STANDBY;
  int s1_1_St_1_STANDBY;
  int nr_St_1_OFF;
  int ns_St_1_OFF_3;
  int ns_St_1_OFF_2;
  int ns_St_1_OFF_1;
  int p1_1_St_1_OFF;
  int s1_1_St_1_OFF;
  int ck_2_3;
  int ck_2_2;
  int ck_2_1;
  int v_21_2_0;
  int v_21_3_0_0;
  int v_21_3_0_1;
  int v_21_2_1;
  int v_21_3_1_0;
  int v_21_3_1_1;
  int v_22;
  int v_21_3;
  int v_21_2;
  int v_21_1;
  int v_20;
  int v_19;
  int v_18;
  int v_16_2_0;
  int v_16_3_0_0;
  int v_16_3_0_1;
  int v_16_2_1;
  int v_16_3_1_0;
  int v_16_3_1_1;
  int v_17;
  int v_16_3;
  int v_16_2;
  int v_16_1;
  int v_14_2_0;
  int v_14_3_0_0;
  int v_14_3_0_1;
  int v_14_2_1;
  int v_14_3_1_0;
  int v_14_3_1_1;
  int v_15;
  int v_14_3;
  int v_14_2;
  int v_14_1;
  int v_13;
  int v_2_0;
  int v_3_0_0;
  int v_3_0_1;
  int v_2_1;
  int v_3_1_0;
  int v_3_1_1;
  int v_12;
  int v_3;
  int v_2;
  int v_1;
  int v_128;
  int v_127;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_122;
  int v_121;
  int v_120;
  int v_119;
  int v_118;
  int v_117;
  int v_116;
  int v_115;
  int v_114;
  int v_113;
  int v_112;
  int v_111;
  int v_110;
  int v_109;
  int s_3_St_1_REHEAT_2_0;
  int s_3_St_1_REHEAT_3_0_0;
  int s_3_St_1_REHEAT_3_0_1;
  int s_3_St_1_REHEAT_2_1;
  int s_3_St_1_REHEAT_3_1_0;
  int s_3_St_1_REHEAT_3_1_1;
  int s_3_St_1_MAINTAIN_2_0;
  int s_3_St_1_MAINTAIN_3_0_0;
  int s_3_St_1_MAINTAIN_3_0_1;
  int s_3_St_1_MAINTAIN_2_1;
  int s_3_St_1_MAINTAIN_3_1_0;
  int s_3_St_1_MAINTAIN_3_1_1;
  int s_3_St_1_HEAT_2_0;
  int s_3_St_1_HEAT_3_0_0;
  int s_3_St_1_HEAT_3_0_1;
  int s_3_St_1_HEAT_2_1;
  int s_3_St_1_HEAT_3_1_0;
  int s_3_St_1_HEAT_3_1_1;
  int s_3_St_1_STANDBY_2_0;
  int s_3_St_1_STANDBY_3_0_0;
  int s_3_St_1_STANDBY_3_0_1;
  int s_3_St_1_STANDBY_2_1;
  int s_3_St_1_STANDBY_3_1_0;
  int s_3_St_1_STANDBY_3_1_1;
  int s_3_St_1_OFF_2_0;
  int s_3_St_1_OFF_3_0_0;
  int s_3_St_1_OFF_3_0_1;
  int s_3_St_1_OFF_2_1;
  int s_3_St_1_OFF_3_1_0;
  int s_3_St_1_OFF_3_1_1;
  int ck_2_4_0;
  int ck_3_0_0;
  int ck_3_0_1;
  int ck_2_4_1;
  int ck_3_1_0;
  int ck_3_1_1;
  int r_St_1_REHEAT;
  int s_3_St_1_REHEAT_3;
  int s_3_St_1_REHEAT_2;
  int s_3_St_1_REHEAT_1;
  int r_St_1_MAINTAIN;
  int s_3_St_1_MAINTAIN_3;
  int s_3_St_1_MAINTAIN_2;
  int s_3_St_1_MAINTAIN_1;
  int r_St_1_HEAT;
  int s_3_St_1_HEAT_3;
  int s_3_St_1_HEAT_2;
  int s_3_St_1_HEAT_1;
  int r_St_1_STANDBY;
  int s_3_St_1_STANDBY_3;
  int s_3_St_1_STANDBY_2;
  int s_3_St_1_STANDBY_1;
  int r_St_1_OFF;
  int s_3_St_1_OFF_3;
  int s_3_St_1_OFF_2;
  int s_3_St_1_OFF_1;
  int ck_3;
  int ck_2_4;
  int ck_1;
  int s_3_2_0;
  int s_3_3_0_0;
  int s_3_3_0_1;
  int s_3_2_1;
  int s_3_3_1_0;
  int s_3_3_1_1;
  int ns_2_0;
  int ns_3_0_0;
  int ns_3_0_1;
  int ns_2_1;
  int ns_3_1_0;
  int ns_3_1_1;
  int s_3_3;
  int s_3_2;
  int s_3_1;
  int ns_3;
  int ns_2;
  int ns_1;
  int r;
  int nr;
  int f_1;
  int s_1;
  int c_1;
  int cold_1;
  int temp_ok_1;
  int s1_1;
  int p1_1;
  f_1 = f;
  s_1 = s;
  c_1 = c;
  cold_1 = cold;
  temp_ok_1 = temp_ok;
  ck_1 = self->v_106;
  ck_2_4 = self->v_107;
  ck_3 = self->v_108;
  if (ck_1) {
    ck_2_4_1 = ck_2_4;
    if (ck_2_4_1) {
      ck_3_1_1 = ck_3;
      if (ck_3_1_1) {
        if (temp_ok_1) {
          v_17 = true;
        } else {
          v_17 = self->pnr;
        };
        if (f_1) {
          r_St_1_HEAT = true;
        } else {
          r_St_1_HEAT = v_17;
        };
        if (temp_ok_1) {
          v_16_1 = true;
        } else {
          v_16_1 = true;
        };
        if (f_1) {
          s_3_St_1_HEAT_1 = true;
        } else {
          s_3_St_1_HEAT_1 = v_16_1;
        };
        if (temp_ok_1) {
          v_16_2 = true;
        } else {
          v_16_2 = true;
        };
        if (f_1) {
          s_3_St_1_HEAT_2 = false;
        } else {
          s_3_St_1_HEAT_2 = v_16_2;
        };
        if (temp_ok_1) {
          v_16_3 = false;
        } else {
          v_16_3 = true;
        };
        if (f_1) {
          s_3_St_1_HEAT_3 = false;
        } else {
          s_3_St_1_HEAT_3 = v_16_3;
        };
        v_124 = r_St_1_HEAT;
        v_109 = s_3_St_1_HEAT_1;
        v_110 = s_3_St_1_HEAT_2;
        v_111 = s_3_St_1_HEAT_3;
      } else {
        if (f_1) {
          v_15 = true;
          v_14_1 = true;
          v_14_2 = false;
          v_14_3 = false;
        } else {
          v_15 = self->pnr;
          v_14_1 = true;
          v_14_2 = true;
          v_14_3 = false;
        };
        v_13 = (cold_1&&c_1);
        if (v_13) {
          r_St_1_MAINTAIN = true;
        } else {
          r_St_1_MAINTAIN = v_15;
        };
        v_124 = r_St_1_MAINTAIN;
        if (v_13) {
          s_3_St_1_MAINTAIN_1 = false;
        } else {
          s_3_St_1_MAINTAIN_1 = v_14_1;
        };
        v_109 = s_3_St_1_MAINTAIN_1;
        if (v_13) {
          s_3_St_1_MAINTAIN_2 = false;
        } else {
          s_3_St_1_MAINTAIN_2 = v_14_2;
        };
        v_110 = s_3_St_1_MAINTAIN_2;
        if (v_13) {
          s_3_St_1_MAINTAIN_3 = true;
        } else {
          s_3_St_1_MAINTAIN_3 = v_14_3;
        };
        v_111 = s_3_St_1_MAINTAIN_3;
      };
      v_118 = v_109;
      v_119 = v_110;
      v_120 = v_111;
      v_126 = v_124;
      if (ck_3_1_1) {
        if (v_16_1) {
          v_16_2_1 = v_16_2;
          if (v_16_2_1) {
            v_16_3_1_1 = v_16_3;
          } else {
            v_16_3_1_0 = v_16_3;
          };
        } else {
          v_16_2_0 = v_16_2;
          if (v_16_2_0) {
            v_16_3_0_1 = v_16_3;
          } else {
            v_16_3_0_0 = v_16_3;
          };
        };
        if (s_3_St_1_HEAT_1) {
          s_3_St_1_HEAT_2_1 = s_3_St_1_HEAT_2;
          if (s_3_St_1_HEAT_2_1) {
            s_3_St_1_HEAT_3_1_1 = s_3_St_1_HEAT_3;
          } else {
            s_3_St_1_HEAT_3_1_0 = s_3_St_1_HEAT_3;
          };
        } else {
          s_3_St_1_HEAT_2_0 = s_3_St_1_HEAT_2;
          if (s_3_St_1_HEAT_2_0) {
            s_3_St_1_HEAT_3_0_1 = s_3_St_1_HEAT_3;
          } else {
            s_3_St_1_HEAT_3_0_0 = s_3_St_1_HEAT_3;
          };
        };
      } else {
        if (v_14_1) {
          v_14_2_1 = v_14_2;
          if (v_14_2_1) {
            v_14_3_1_1 = v_14_3;
          } else {
            v_14_3_1_0 = v_14_3;
          };
        } else {
          v_14_2_0 = v_14_2;
          if (v_14_2_0) {
            v_14_3_0_1 = v_14_3;
          } else {
            v_14_3_0_0 = v_14_3;
          };
        };
        if (s_3_St_1_MAINTAIN_1) {
          s_3_St_1_MAINTAIN_2_1 = s_3_St_1_MAINTAIN_2;
          if (s_3_St_1_MAINTAIN_2_1) {
            s_3_St_1_MAINTAIN_3_1_1 = s_3_St_1_MAINTAIN_3;
          } else {
            s_3_St_1_MAINTAIN_3_1_0 = s_3_St_1_MAINTAIN_3;
          };
        } else {
          s_3_St_1_MAINTAIN_2_0 = s_3_St_1_MAINTAIN_2;
          if (s_3_St_1_MAINTAIN_2_0) {
            s_3_St_1_MAINTAIN_3_0_1 = s_3_St_1_MAINTAIN_3;
          } else {
            s_3_St_1_MAINTAIN_3_0_0 = s_3_St_1_MAINTAIN_3;
          };
        };
      };
    } else {
      ck_3_1_0 = ck_3;
      if (ck_3_1_0) {
        v_125 = true;
        v_112 = true;
        v_113 = true;
        v_114 = true;
      } else {
        v_20 = (s_1&&c_1);
        if (v_20) {
          v_22 = true;
          v_21_1 = true;
          v_21_2 = true;
          v_21_3 = true;
        } else {
          v_22 = self->pnr;
          v_21_1 = true;
          v_21_2 = false;
          v_21_3 = false;
        };
        v_18 = !(c_1);
        v_19 = (s_1&&v_18);
        if (v_19) {
          r_St_1_OFF = true;
        } else {
          r_St_1_OFF = v_22;
        };
        v_125 = r_St_1_OFF;
        if (v_19) {
          s_3_St_1_OFF_1 = false;
        } else {
          s_3_St_1_OFF_1 = v_21_1;
        };
        v_112 = s_3_St_1_OFF_1;
        if (v_19) {
          s_3_St_1_OFF_2 = false;
        } else {
          s_3_St_1_OFF_2 = v_21_2;
        };
        v_113 = s_3_St_1_OFF_2;
        if (v_19) {
          s_3_St_1_OFF_3 = false;
        } else {
          s_3_St_1_OFF_3 = v_21_3;
        };
        v_114 = s_3_St_1_OFF_3;
        if (v_21_1) {
          v_21_2_1 = v_21_2;
          if (v_21_2_1) {
            v_21_3_1_1 = v_21_3;
          } else {
            v_21_3_1_0 = v_21_3;
          };
        } else {
          v_21_2_0 = v_21_2;
          if (v_21_2_0) {
            v_21_3_0_1 = v_21_3;
          } else {
            v_21_3_0_0 = v_21_3;
          };
        };
        if (s_3_St_1_OFF_1) {
          s_3_St_1_OFF_2_1 = s_3_St_1_OFF_2;
          if (s_3_St_1_OFF_2_1) {
            s_3_St_1_OFF_3_1_1 = s_3_St_1_OFF_3;
          } else {
            s_3_St_1_OFF_3_1_0 = s_3_St_1_OFF_3;
          };
        } else {
          s_3_St_1_OFF_2_0 = s_3_St_1_OFF_2;
          if (s_3_St_1_OFF_2_0) {
            s_3_St_1_OFF_3_0_1 = s_3_St_1_OFF_3;
          } else {
            s_3_St_1_OFF_3_0_0 = s_3_St_1_OFF_3;
          };
        };
      };
      v_118 = v_112;
      v_119 = v_113;
      v_120 = v_114;
      v_126 = v_125;
    };
    s_3_1 = v_118;
    s_3_2 = v_119;
    s_3_3 = v_120;
    r = v_126;
  } else {
    ck_2_4_0 = ck_2_4;
    if (ck_2_4_0) {
      ck_3_0_1 = ck_3;
      v_121 = true;
      v_122 = true;
      v_123 = true;
      v_128 = true;
    } else {
      ck_3_0_0 = ck_3;
      if (ck_3_0_0) {
        if (f_1) {
          v_12 = true;
        } else {
          v_12 = self->pnr;
        };
        if (temp_ok_1) {
          r_St_1_REHEAT = true;
        } else {
          r_St_1_REHEAT = v_12;
        };
        v_127 = r_St_1_REHEAT;
        if (f_1) {
          v_1 = true;
        } else {
          v_1 = false;
        };
        if (temp_ok_1) {
          s_3_St_1_REHEAT_1 = true;
        } else {
          s_3_St_1_REHEAT_1 = v_1;
        };
        v_115 = s_3_St_1_REHEAT_1;
        if (f_1) {
          v_2 = false;
        } else {
          v_2 = false;
        };
        if (temp_ok_1) {
          s_3_St_1_REHEAT_2 = true;
        } else {
          s_3_St_1_REHEAT_2 = v_2;
        };
        v_116 = s_3_St_1_REHEAT_2;
        if (f_1) {
          v_3 = false;
        } else {
          v_3 = true;
        };
        if (temp_ok_1) {
          s_3_St_1_REHEAT_3 = false;
        } else {
          s_3_St_1_REHEAT_3 = v_3;
        };
        v_117 = s_3_St_1_REHEAT_3;
        if (v_1) {
          v_2_1 = v_2;
          if (v_2_1) {
            v_3_1_1 = v_3;
          } else {
            v_3_1_0 = v_3;
          };
        } else {
          v_2_0 = v_2;
          if (v_2_0) {
            v_3_0_1 = v_3;
          } else {
            v_3_0_0 = v_3;
          };
        };
      } else {
        if (c_1) {
          r_St_1_STANDBY = true;
          s_3_St_1_STANDBY_1 = true;
          s_3_St_1_STANDBY_2 = true;
          s_3_St_1_STANDBY_3 = true;
        } else {
          r_St_1_STANDBY = self->pnr;
          s_3_St_1_STANDBY_1 = false;
          s_3_St_1_STANDBY_2 = false;
          s_3_St_1_STANDBY_3 = false;
        };
        v_127 = r_St_1_STANDBY;
        v_115 = s_3_St_1_STANDBY_1;
        v_116 = s_3_St_1_STANDBY_2;
        v_117 = s_3_St_1_STANDBY_3;
      };
      v_121 = v_115;
      v_122 = v_116;
      v_123 = v_117;
      v_128 = v_127;
    };
    s_3_1 = v_121;
    s_3_2 = v_122;
    s_3_3 = v_123;
    r = v_128;
  };
  ck_2_1 = s_3_1;
  ck_2_2 = s_3_2;
  ck_2_3 = s_3_3;
  if (ck_2_1) {
    ck_2_2_1 = ck_2_2;
    if (ck_2_2_1) {
      ck_2_3_1_1 = ck_2_3;
      if (ck_2_3_1_1) {
        s1_1_St_1_HEAT = 2;
        p1_1_St_1_HEAT = 1500;
        nr_St_1_HEAT = false;
        ns_St_1_HEAT_1 = true;
        ns_St_1_HEAT_2 = true;
        ns_St_1_HEAT_3 = true;
        v_76 = s1_1_St_1_HEAT;
        v_81 = p1_1_St_1_HEAT;
        v_101 = nr_St_1_HEAT;
        v_86 = ns_St_1_HEAT_1;
        v_87 = ns_St_1_HEAT_2;
        v_88 = ns_St_1_HEAT_3;
      } else {
        s1_1_St_1_MAINTAIN = 3;
        v_76 = s1_1_St_1_MAINTAIN;
        p1_1_St_1_MAINTAIN = 300;
        v_81 = p1_1_St_1_MAINTAIN;
        nr_St_1_MAINTAIN = false;
        v_101 = nr_St_1_MAINTAIN;
        ns_St_1_MAINTAIN_1 = true;
        v_86 = ns_St_1_MAINTAIN_1;
        ns_St_1_MAINTAIN_2 = true;
        v_87 = ns_St_1_MAINTAIN_2;
        ns_St_1_MAINTAIN_3 = false;
        v_88 = ns_St_1_MAINTAIN_3;
      };
      v_78 = v_76;
      v_83 = v_81;
      v_95 = v_86;
      v_96 = v_87;
      v_97 = v_88;
      v_103 = v_101;
      if (ck_2_3_1_1) {
        if (ns_St_1_HEAT_1) {
          ns_St_1_HEAT_2_1 = ns_St_1_HEAT_2;
          if (ns_St_1_HEAT_2_1) {
            ns_St_1_HEAT_3_1_1 = ns_St_1_HEAT_3;
          } else {
            ns_St_1_HEAT_3_1_0 = ns_St_1_HEAT_3;
          };
        } else {
          ns_St_1_HEAT_2_0 = ns_St_1_HEAT_2;
          if (ns_St_1_HEAT_2_0) {
            ns_St_1_HEAT_3_0_1 = ns_St_1_HEAT_3;
          } else {
            ns_St_1_HEAT_3_0_0 = ns_St_1_HEAT_3;
          };
        };
      } else {
        if (ns_St_1_MAINTAIN_1) {
          ns_St_1_MAINTAIN_2_1 = ns_St_1_MAINTAIN_2;
          if (ns_St_1_MAINTAIN_2_1) {
            ns_St_1_MAINTAIN_3_1_1 = ns_St_1_MAINTAIN_3;
          } else {
            ns_St_1_MAINTAIN_3_1_0 = ns_St_1_MAINTAIN_3;
          };
        } else {
          ns_St_1_MAINTAIN_2_0 = ns_St_1_MAINTAIN_2;
          if (ns_St_1_MAINTAIN_2_0) {
            ns_St_1_MAINTAIN_3_0_1 = ns_St_1_MAINTAIN_3;
          } else {
            ns_St_1_MAINTAIN_3_0_0 = ns_St_1_MAINTAIN_3;
          };
        };
      };
    } else {
      ck_2_3_1_0 = ck_2_3;
      if (ck_2_3_1_0) {
        v_77 = 0;
        v_82 = 0;
        v_102 = true;
        v_89 = true;
        v_90 = true;
        v_91 = true;
      } else {
        s1_1_St_1_OFF = 0;
        v_77 = s1_1_St_1_OFF;
        p1_1_St_1_OFF = 0;
        v_82 = p1_1_St_1_OFF;
        nr_St_1_OFF = false;
        v_102 = nr_St_1_OFF;
        ns_St_1_OFF_1 = true;
        v_89 = ns_St_1_OFF_1;
        ns_St_1_OFF_2 = false;
        v_90 = ns_St_1_OFF_2;
        ns_St_1_OFF_3 = false;
        v_91 = ns_St_1_OFF_3;
        if (ns_St_1_OFF_1) {
          ns_St_1_OFF_2_1 = ns_St_1_OFF_2;
          if (ns_St_1_OFF_2_1) {
            ns_St_1_OFF_3_1_1 = ns_St_1_OFF_3;
          } else {
            ns_St_1_OFF_3_1_0 = ns_St_1_OFF_3;
          };
        } else {
          ns_St_1_OFF_2_0 = ns_St_1_OFF_2;
          if (ns_St_1_OFF_2_0) {
            ns_St_1_OFF_3_0_1 = ns_St_1_OFF_3;
          } else {
            ns_St_1_OFF_3_0_0 = ns_St_1_OFF_3;
          };
        };
      };
      v_78 = v_77;
      v_83 = v_82;
      v_95 = v_89;
      v_96 = v_90;
      v_97 = v_91;
      v_103 = v_102;
    };
    s1_1 = v_78;
    p1_1 = v_83;
    ns_1 = v_95;
    ns_2 = v_96;
    ns_3 = v_97;
    nr = v_103;
  } else {
    ck_2_2_0 = ck_2_2;
    if (ck_2_2_0) {
      ck_2_3_0_1 = ck_2_3;
      v_80 = 0;
      v_85 = 0;
      v_98 = true;
      v_99 = true;
      v_100 = true;
      v_105 = true;
    } else {
      ck_2_3_0_0 = ck_2_3;
      if (ck_2_3_0_0) {
        s1_1_St_1_REHEAT = 4;
        v_79 = s1_1_St_1_REHEAT;
        p1_1_St_1_REHEAT = 1000;
        v_84 = p1_1_St_1_REHEAT;
        nr_St_1_REHEAT = false;
        v_104 = nr_St_1_REHEAT;
        ns_St_1_REHEAT_1 = false;
        v_92 = ns_St_1_REHEAT_1;
        ns_St_1_REHEAT_2 = false;
        v_93 = ns_St_1_REHEAT_2;
        ns_St_1_REHEAT_3 = true;
        v_94 = ns_St_1_REHEAT_3;
      } else {
        s1_1_St_1_STANDBY = 1;
        p1_1_St_1_STANDBY = 0;
        nr_St_1_STANDBY = false;
        ns_St_1_STANDBY_1 = false;
        ns_St_1_STANDBY_2 = false;
        ns_St_1_STANDBY_3 = false;
        v_79 = s1_1_St_1_STANDBY;
        v_84 = p1_1_St_1_STANDBY;
        v_104 = nr_St_1_STANDBY;
        v_92 = ns_St_1_STANDBY_1;
        v_93 = ns_St_1_STANDBY_2;
        v_94 = ns_St_1_STANDBY_3;
      };
      v_80 = v_79;
      v_85 = v_84;
      v_98 = v_92;
      v_99 = v_93;
      v_100 = v_94;
      v_105 = v_104;
    };
    s1_1 = v_80;
    p1_1 = v_85;
    ns_1 = v_98;
    ns_2 = v_99;
    ns_3 = v_100;
    nr = v_105;
  };
  _out->p1 = p1_1;
  _out->s1 = s1_1;
  if (ns_1) {
    ns_2_1 = ns_2;
    if (ns_2_1) {
      ns_3_1_1 = ns_3;
    } else {
      ns_3_1_0 = ns_3;
    };
  } else {
    ns_2_0 = ns_2;
    if (ns_2_0) {
      ns_3_0_1 = ns_3;
    } else {
      ns_3_0_0 = ns_3;
    };
  };
  if (!(ck_2_1)) {
    if (!(ck_2_2_0)) {
      if (ck_2_3_0_0) {
        if (ns_St_1_REHEAT_1) {
          ns_St_1_REHEAT_2_1 = ns_St_1_REHEAT_2;
          if (ns_St_1_REHEAT_2_1) {
            ns_St_1_REHEAT_3_1_1 = ns_St_1_REHEAT_3;
          } else {
            ns_St_1_REHEAT_3_1_0 = ns_St_1_REHEAT_3;
          };
        } else {
          ns_St_1_REHEAT_2_0 = ns_St_1_REHEAT_2;
          if (ns_St_1_REHEAT_2_0) {
            ns_St_1_REHEAT_3_0_1 = ns_St_1_REHEAT_3;
          } else {
            ns_St_1_REHEAT_3_0_0 = ns_St_1_REHEAT_3;
          };
        };
      } else {
        if (ns_St_1_STANDBY_1) {
          ns_St_1_STANDBY_2_1 = ns_St_1_STANDBY_2;
          if (ns_St_1_STANDBY_2_1) {
            ns_St_1_STANDBY_3_1_1 = ns_St_1_STANDBY_3;
          } else {
            ns_St_1_STANDBY_3_1_0 = ns_St_1_STANDBY_3;
          };
        } else {
          ns_St_1_STANDBY_2_0 = ns_St_1_STANDBY_2;
          if (ns_St_1_STANDBY_2_0) {
            ns_St_1_STANDBY_3_0_1 = ns_St_1_STANDBY_3;
          } else {
            ns_St_1_STANDBY_3_0_0 = ns_St_1_STANDBY_3;
          };
        };
      };
    };
  };
  if (s_3_1) {
    s_3_2_1 = s_3_2;
    if (s_3_2_1) {
      s_3_3_1_1 = s_3_3;
    } else {
      s_3_3_1_0 = s_3_3;
    };
  } else {
    s_3_2_0 = s_3_2;
    if (s_3_2_0) {
      s_3_3_0_1 = s_3_3;
    } else {
      s_3_3_0_0 = s_3_3;
    };
  };
  if (!(ck_1)) {
    if (!(ck_2_4_0)) {
      if (ck_3_0_0) {
        if (s_3_St_1_REHEAT_1) {
          s_3_St_1_REHEAT_2_1 = s_3_St_1_REHEAT_2;
          if (s_3_St_1_REHEAT_2_1) {
            s_3_St_1_REHEAT_3_1_1 = s_3_St_1_REHEAT_3;
          } else {
            s_3_St_1_REHEAT_3_1_0 = s_3_St_1_REHEAT_3;
          };
        } else {
          s_3_St_1_REHEAT_2_0 = s_3_St_1_REHEAT_2;
          if (s_3_St_1_REHEAT_2_0) {
            s_3_St_1_REHEAT_3_0_1 = s_3_St_1_REHEAT_3;
          } else {
            s_3_St_1_REHEAT_3_0_0 = s_3_St_1_REHEAT_3;
          };
        };
      } else {
        if (s_3_St_1_STANDBY_1) {
          s_3_St_1_STANDBY_2_1 = s_3_St_1_STANDBY_2;
          if (s_3_St_1_STANDBY_2_1) {
            s_3_St_1_STANDBY_3_1_1 = s_3_St_1_STANDBY_3;
          } else {
            s_3_St_1_STANDBY_3_1_0 = s_3_St_1_STANDBY_3;
          };
        } else {
          s_3_St_1_STANDBY_2_0 = s_3_St_1_STANDBY_2;
          if (s_3_St_1_STANDBY_2_0) {
            s_3_St_1_STANDBY_3_0_1 = s_3_St_1_STANDBY_3;
          } else {
            s_3_St_1_STANDBY_3_0_0 = s_3_St_1_STANDBY_3;
          };
        };
      };
    };
  };
  self->pnr = nr;
  self->v_106 = ns_1;
  self->v_107 = ns_2;
  self->v_108 = ns_3;;
}


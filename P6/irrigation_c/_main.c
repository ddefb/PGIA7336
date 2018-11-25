/* --- Generated the 25/11/2018 at 0:9 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s controller irrigation.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Irrigation__controller_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int h;
  int oi;
  int os;
  int cc;
  Irrigation__controller_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Irrigation__controller_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    printf("h ? ");
    scanf("%d", &h);;
    
    printf("oi ? ");
    scanf("%d", &oi);;
    
    printf("os ? ");
    scanf("%d", &os);;
    
    printf("cc ? ");
    scanf("%d", &cc);;
    Irrigation__controller_step(h, oi, os, cc, &_res, &mem);
    printf("=> ");
    printf("%d ", _res.bomb_on);
    printf("=> ");
    printf("%d ", _res.valve_on);
    printf("=> ");
    printf("%d ", _res.r);
    printf("=> ");
    printf("%d ", _res.threshold_1);
    puts("");
    fflush(stdout);
  };
  return 0;
}


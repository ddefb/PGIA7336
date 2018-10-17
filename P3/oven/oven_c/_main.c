/* --- Generated the 17/10/2018 at 9:6 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s oven oven.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Oven__oven_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int f;
  int s;
  int c;
  int cold;
  int temp_ok;
  Oven__oven_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Oven__oven_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    printf("f ? ");
    scanf("%d", &f);;
    
    printf("s ? ");
    scanf("%d", &s);;
    
    printf("c ? ");
    scanf("%d", &c);;
    
    printf("cold ? ");
    scanf("%d", &cold);;
    
    printf("temp_ok ? ");
    scanf("%d", &temp_ok);;
    Oven__oven_step(f, s, c, cold, temp_ok, &_res, &mem);
    printf("=> ");
    printf("%d ", _res.s1);
    printf("=> ");
    printf("%d ", _res.p1);
    puts("");
    fflush(stdout);
  };
  return 0;
}


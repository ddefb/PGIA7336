/* --- Generated the 17/10/2018 at 9:6 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s oven oven.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "oven_types.h"

Oven__st_1 Oven__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_STANDBY")==0)) {
    return Oven__St_1_STANDBY;
  };
  if ((strcmp(s, "St_1_REHEAT")==0)) {
    return Oven__St_1_REHEAT;
  };
  if ((strcmp(s, "St_1_OFF")==0)) {
    return Oven__St_1_OFF;
  };
  if ((strcmp(s, "St_1_MAINTAIN")==0)) {
    return Oven__St_1_MAINTAIN;
  };
  if ((strcmp(s, "St_1_HEAT")==0)) {
    return Oven__St_1_HEAT;
  };
}

char* string_of_Oven__st_1(Oven__st_1 x, char* buf) {
  switch (x) {
    case Oven__St_1_STANDBY:
      strcpy(buf, "St_1_STANDBY");
      break;
    case Oven__St_1_REHEAT:
      strcpy(buf, "St_1_REHEAT");
      break;
    case Oven__St_1_OFF:
      strcpy(buf, "St_1_OFF");
      break;
    case Oven__St_1_MAINTAIN:
      strcpy(buf, "St_1_MAINTAIN");
      break;
    case Oven__St_1_HEAT:
      strcpy(buf, "St_1_HEAT");
      break;
    default:
      break;
  };
  return buf;
}

Oven__st Oven__st_of_string(char* s) {
  if ((strcmp(s, "St_STANDBY")==0)) {
    return Oven__St_STANDBY;
  };
  if ((strcmp(s, "St_REHEAT")==0)) {
    return Oven__St_REHEAT;
  };
  if ((strcmp(s, "St_OFF")==0)) {
    return Oven__St_OFF;
  };
  if ((strcmp(s, "St_MAINTAIN")==0)) {
    return Oven__St_MAINTAIN;
  };
  if ((strcmp(s, "St_HEAT")==0)) {
    return Oven__St_HEAT;
  };
}

char* string_of_Oven__st(Oven__st x, char* buf) {
  switch (x) {
    case Oven__St_STANDBY:
      strcpy(buf, "St_STANDBY");
      break;
    case Oven__St_REHEAT:
      strcpy(buf, "St_REHEAT");
      break;
    case Oven__St_OFF:
      strcpy(buf, "St_OFF");
      break;
    case Oven__St_MAINTAIN:
      strcpy(buf, "St_MAINTAIN");
      break;
    case Oven__St_HEAT:
      strcpy(buf, "St_HEAT");
      break;
    default:
      break;
  };
  return buf;
}


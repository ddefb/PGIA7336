/* --- Generated the 25/11/2018 at 0:9 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s controller irrigation.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "irrigation_types.h"

Irrigation__st_4 Irrigation__st_4_of_string(char* s) {
  if ((strcmp(s, "St_4_ON")==0)) {
    return Irrigation__St_4_ON;
  };
  if ((strcmp(s, "St_4_OFF")==0)) {
    return Irrigation__St_4_OFF;
  };
}

char* string_of_Irrigation__st_4(Irrigation__st_4 x, char* buf) {
  switch (x) {
    case Irrigation__St_4_ON:
      strcpy(buf, "St_4_ON");
      break;
    case Irrigation__St_4_OFF:
      strcpy(buf, "St_4_OFF");
      break;
    default:
      break;
  };
  return buf;
}

Irrigation__st_3 Irrigation__st_3_of_string(char* s) {
  if ((strcmp(s, "St_3_ON")==0)) {
    return Irrigation__St_3_ON;
  };
  if ((strcmp(s, "St_3_OFF")==0)) {
    return Irrigation__St_3_OFF;
  };
}

char* string_of_Irrigation__st_3(Irrigation__st_3 x, char* buf) {
  switch (x) {
    case Irrigation__St_3_ON:
      strcpy(buf, "St_3_ON");
      break;
    case Irrigation__St_3_OFF:
      strcpy(buf, "St_3_OFF");
      break;
    default:
      break;
  };
  return buf;
}

Irrigation__st_2 Irrigation__st_2_of_string(char* s) {
  if ((strcmp(s, "St_2_LOWER_STATE")==0)) {
    return Irrigation__St_2_LOWER_STATE;
  };
  if ((strcmp(s, "St_2_HIGHER_STATE")==0)) {
    return Irrigation__St_2_HIGHER_STATE;
  };
}

char* string_of_Irrigation__st_2(Irrigation__st_2 x, char* buf) {
  switch (x) {
    case Irrigation__St_2_LOWER_STATE:
      strcpy(buf, "St_2_LOWER_STATE");
      break;
    case Irrigation__St_2_HIGHER_STATE:
      strcpy(buf, "St_2_HIGHER_STATE");
      break;
    default:
      break;
  };
  return buf;
}

Irrigation__st_1 Irrigation__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_ON")==0)) {
    return Irrigation__St_1_ON;
  };
  if ((strcmp(s, "St_1_OFF")==0)) {
    return Irrigation__St_1_OFF;
  };
}

char* string_of_Irrigation__st_1(Irrigation__st_1 x, char* buf) {
  switch (x) {
    case Irrigation__St_1_ON:
      strcpy(buf, "St_1_ON");
      break;
    case Irrigation__St_1_OFF:
      strcpy(buf, "St_1_OFF");
      break;
    default:
      break;
  };
  return buf;
}

Irrigation__st Irrigation__st_of_string(char* s) {
  if ((strcmp(s, "St_LOWER_STATE")==0)) {
    return Irrigation__St_LOWER_STATE;
  };
  if ((strcmp(s, "St_HIGHER_STATE")==0)) {
    return Irrigation__St_HIGHER_STATE;
  };
}

char* string_of_Irrigation__st(Irrigation__st x, char* buf) {
  switch (x) {
    case Irrigation__St_LOWER_STATE:
      strcpy(buf, "St_LOWER_STATE");
      break;
    case Irrigation__St_HIGHER_STATE:
      strcpy(buf, "St_HIGHER_STATE");
      break;
    default:
      break;
  };
  return buf;
}

Irrigation__modes Irrigation__modes_of_string(char* s) {
  if ((strcmp(s, "Lower")==0)) {
    return Irrigation__Lower;
  };
  if ((strcmp(s, "Higher")==0)) {
    return Irrigation__Higher;
  };
}

char* string_of_Irrigation__modes(Irrigation__modes x, char* buf) {
  switch (x) {
    case Irrigation__Lower:
      strcpy(buf, "Lower");
      break;
    case Irrigation__Higher:
      strcpy(buf, "Higher");
      break;
    default:
      break;
  };
  return buf;
}


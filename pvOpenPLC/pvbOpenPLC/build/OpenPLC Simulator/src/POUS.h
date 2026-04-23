#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

// FUNCTION_BLOCK OSC
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(TIME,T)
  __DECLARE_VAR(BOOL,OUT)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,A)
  TON TON0;
  TOF TOF0;
  __DECLARE_VAR(BOOL,_TMP_NOT1466428_OUT)

} OSC;

void OSC_init__(OSC *data__, BOOL retain);
// Code part
void OSC_body__(OSC *data__);
// PROGRAM MAIN
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  OSC OSC0;
  CTUD CTUD0;
  __DECLARE_LOCATED(BOOL,AUMENTA)
  __DECLARE_LOCATED(BOOL,DIMINUI)
  __DECLARE_LOCATED(INT,CONTAGEM)
  __DECLARE_VAR(BOOL,_TMP_AND5508925_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND10237510_OUT)

} MAIN;

void MAIN_init__(MAIN *data__, BOOL retain);
// Code part
void MAIN_body__(MAIN *data__);
#endif //__POUS_H

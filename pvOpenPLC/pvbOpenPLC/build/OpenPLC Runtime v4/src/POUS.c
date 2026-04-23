void OSC_init__(OSC *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->T,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->A,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TOF_init__(&data__->TOF0,retain);
  __INIT_VAR(data__->_TMP_NOT1466428_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void OSC_body__(OSC *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->A,));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->T,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,OUT,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->,_TMP_NOT1466428_OUT,,!(__GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->_TMP_NOT1466428_OUT,));
  __SET_VAR(data__->TOF0.,PT,,__GET_VAR(data__->T,));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,A,,__GET_VAR(data__->TOF0.Q,));

  goto __end;

__end:
  return;
} // OSC_body__() 





void MAIN_init__(MAIN *data__, BOOL retain) {
  OSC_init__(&data__->OSC0,retain);
  CTUD_init__(&data__->CTUD0,retain);
  __INIT_LOCATED(BOOL,__QX0_0,data__->AUMENTA,retain)
  __INIT_LOCATED_VALUE(data__->AUMENTA,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->DIMINUI,retain)
  __INIT_LOCATED_VALUE(data__->DIMINUI,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__QW0,data__->CONTAGEM,retain)
  __INIT_LOCATED_VALUE(data__->CONTAGEM,0)
  __INIT_VAR(data__->_TMP_AND5508925_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND10237510_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->OSC0.,T,,__time_to_timespec(1, 100, 0, 0, 0, 0));
  OSC_body__(&data__->OSC0);
  __SET_VAR(data__->,_TMP_AND5508925_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_LOCATED(data__->AUMENTA,),
    (BOOL)__GET_VAR(data__->OSC0.OUT,)));
  __SET_VAR(data__->,_TMP_AND10237510_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_LOCATED(data__->DIMINUI,),
    (BOOL)__GET_VAR(data__->OSC0.OUT,)));
  __SET_VAR(data__->CTUD0.,CU,,__GET_VAR(data__->_TMP_AND5508925_OUT,));
  __SET_VAR(data__->CTUD0.,CD,,__GET_VAR(data__->_TMP_AND10237510_OUT,));
  __SET_VAR(data__->CTUD0.,PV,,100);
  CTUD_body__(&data__->CTUD0);
  __SET_LOCATED(data__->,CONTAGEM,,__GET_VAR(data__->CTUD0.CV,));

  goto __end;

__end:
  return;
} // MAIN_body__() 






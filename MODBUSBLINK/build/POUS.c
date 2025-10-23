void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void BLINK_init__(BLINK *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__QX0_0,data__->BLINK_LED0,retain)
  __INIT_LOCATED_VALUE(data__->BLINK_LED0,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->BLINK_LED1,retain)
  __INIT_LOCATED_VALUE(data__->BLINK_LED1,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->BLINK_LED2,retain)
  __INIT_LOCATED_VALUE(data__->BLINK_LED2,__BOOL_LITERAL(FALSE))
  TON_init__(&data__->TON0,retain);
  TOF_init__(&data__->TOF0,retain);
  __INIT_LOCATED(INT,__QW0,data__->TIMER_PRESET_MS,retain)
  __INIT_LOCATED_VALUE(data__->TIMER_PRESET_MS,500)
  __INIT_VAR(data__->TIMER_PRESET_T,__time_to_timespec(1, 500, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->MSCONV,1000.0,retain)
  __INIT_VAR(data__->_TMP_INT_TO_REAL26_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV28_OUT,0,retain)
  __INIT_VAR(data__->_TMP_REAL_TO_TIME27_OUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void BLINK_body__(BLINK *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TON0.,IN,,!(__GET_LOCATED(data__->BLINK_LED0,)));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->TIMER_PRESET_T,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,EN,,__GET_VAR(data__->TON0.ENO,));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__GET_VAR(data__->TIMER_PRESET_T,));
  TOF_body__(&data__->TOF0);
  __SET_LOCATED(data__->,BLINK_LED0,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->,_TMP_INT_TO_REAL26_OUT,,INT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_LOCATED(data__->TIMER_PRESET_MS,)));
  __SET_VAR(data__->,_TMP_DIV28_OUT,,DIV__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_INT_TO_REAL26_OUT,),
    (REAL)__GET_VAR(data__->MSCONV,)));
  __SET_VAR(data__->,_TMP_REAL_TO_TIME27_OUT,,REAL_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_DIV28_OUT,)));
  __SET_VAR(data__->,TIMER_PRESET_T,,__GET_VAR(data__->_TMP_REAL_TO_TIME27_OUT,));

  goto __end;

__end:
  return;
} // BLINK_body__() 






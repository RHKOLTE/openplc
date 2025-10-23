#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM BLINK
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(BOOL,BLINK_LED0)
  __DECLARE_LOCATED(BOOL,BLINK_LED1)
  __DECLARE_LOCATED(BOOL,BLINK_LED2)
  TON TON0;
  TOF TOF0;
  __DECLARE_LOCATED(INT,TIMER_PRESET_MS)
  __DECLARE_VAR(TIME,TIMER_PRESET_T)
  __DECLARE_VAR(REAL,MSCONV)
  __DECLARE_VAR(REAL,_TMP_INT_TO_REAL26_OUT)
  __DECLARE_VAR(REAL,_TMP_DIV28_OUT)
  __DECLARE_VAR(TIME,_TMP_REAL_TO_TIME27_OUT)

} BLINK;

void BLINK_init__(BLINK *data__, BOOL retain);
// Code part
void BLINK_body__(BLINK *data__);
#endif //__POUS_H

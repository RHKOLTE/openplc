TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM Blink
  VAR
    blink_led0 AT %QX0.0 : BOOL;
    blink_led1 AT %QX0.1 : BOOL;
    blink_led2 AT %QX0.2 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    TOF0 : TOF;
  END_VAR
  VAR
    timer_preset_ms AT %QW0 : INT := 500;
  END_VAR
  VAR
    timer_preset_t : TIME := T#500ms;
    MSCONV : REAL := 1000.0;
    _TMP_INT_TO_REAL26_OUT : REAL;
    _TMP_DIV28_OUT : REAL;
    _TMP_REAL_TO_TIME27_OUT : TIME;
  END_VAR

  TON0(EN := TRUE, IN := NOT(blink_led0), PT := timer_preset_t);
  TOF0(EN := TON0.ENO, IN := TON0.Q, PT := timer_preset_t);
  blink_led0 := TOF0.Q;
  _TMP_INT_TO_REAL26_OUT := INT_TO_REAL(timer_preset_ms);
  _TMP_DIV28_OUT := DIV(_TMP_INT_TO_REAL26_OUT, MSCONV);
  _TMP_REAL_TO_TIME27_OUT := REAL_TO_TIME(_TMP_DIV28_OUT);
  timer_preset_t := _TMP_REAL_TO_TIME27_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Blink;
  END_RESOURCE
END_CONFIGURATION

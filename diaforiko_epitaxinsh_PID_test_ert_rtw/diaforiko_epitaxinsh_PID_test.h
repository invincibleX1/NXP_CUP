/*
 * diaforiko_epitaxinsh_PID_test.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "diaforiko_epitaxinsh_PID_test".
 *
 * Model version              : 1.3
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Mon Dec 11 11:14:43 2023
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_diaforiko_epitaxinsh_PID_test_h_
#define RTW_HEADER_diaforiko_epitaxinsh_PID_test_h_
#ifndef diaforiko_epitaxinsh_PID_test_COMMON_INCLUDES_
#define diaforiko_epitaxinsh_PID_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dcMotor_wrapper.h"
#include "dipSwitch_wrapper.h"
#include "camera_wrapper.h"
#include "pot_wrapper.h"
#include "servo_wrapper.h"
#include "digitalPin_wrapper.h"
#include "serial_wrapper.h"
#endif                      /* diaforiko_epitaxinsh_PID_test_COMMON_INCLUDES_ */

#include "diaforiko_epitaxinsh_PID_test_types.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define diaforiko_epitaxinsh_PID_test_M (diaforiko_epitaxinsh_PID_tes_M)

/* Block signals (default storage) */
typedef struct {
  uint16_T Add_b[128];                 /* '<S4>/Add' */
  uint16_T dataIn[128];
} B_diaforiko_epitaxinsh_PID_te_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomboard_Servo_diaforiko__T obj; /* '<S6>/Servo' */
  freedomboard_serialWrite_diaf_T obj_a;/* '<S9>/Serial Transmit' */
  freedomboard_DipSwitch_diafor_T obj_o;/* '<S3>/Dip Switch' */
  freedomboard_dcMotor_diaforik_T obj_k;/* '<S10>/DC Motor' */
  freedomboard_dcMotor_diaforik_T obj_p;/* '<S1>/DC Motor' */
  freedomboard_LinescanCamera_d_T obj_n;/* '<S4>/linescan Camera' */
  freedomboard_Potentiometer_di_T obj_m;/* '<S5>/MATLAB System' */
  freedomboard_digitalOut_diafo_T obj_h;/* '<S7>/Digital Output' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint16_T TmpRTBAtTransmitCameraDataOnUAR[128];/* synthesized block */
  boolean_T objisempty;                /* '<S10>/DC Motor' */
  boolean_T objisempty_h;              /* '<S9>/Serial Transmit' */
  boolean_T objisempty_e;              /* '<S7>/Digital Output' */
  boolean_T objisempty_k;              /* '<S6>/Servo' */
  boolean_T objisempty_hl;             /* '<S5>/MATLAB System' */
  boolean_T objisempty_eh;             /* '<S4>/linescan Camera' */
  boolean_T objisempty_i;              /* '<S3>/Dip Switch' */
  boolean_T objisempty_d;              /* '<S1>/DC Motor' */
} DW_diaforiko_epitaxinsh_PID_t_T;

/* Parameters (default storage) */
struct P_diaforiko_epitaxinsh_PID_te_T_ {
  real_T ServoWrite_maxAngle;          /* Mask Parameter: ServoWrite_maxAngle
                                        * Referenced by: '<S6>/Servo'
                                        */
  real_T ServoWrite_minAngle;          /* Mask Parameter: ServoWrite_minAngle
                                        * Referenced by: '<S6>/Servo'
                                        */
  real_T Exposuretime_Value;           /* Expression: 1
                                        * Referenced by: '<Root>/Exposure time'
                                        */
  real_T Constant_Value;               /* Expression: 64
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 1.5
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T uDLookupTable_tableData[4];   /* Expression: [1.8 1 0.8 0.2]
                                        * Referenced by: '<Root>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[4];    /* Expression: [0 10 20 60]
                                        * Referenced by: '<Root>/1-D Lookup Table'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T uDLookupTable2_tableData[17];
          /* Expression: [0.45 0.5 0.57 0.57 0.58 0.65 0.77 1 1 1 1 1 1 1 1 1 1]
           * Referenced by: '<Root>/1-D Lookup Table2'
           */
  real_T uDLookupTable2_bp01Data[17];
     /* Expression: [ -70 -60 -50 -40 -35 -30 -20 -10 0 10 20 30 35 40 50 60 70]
      * Referenced by: '<Root>/1-D Lookup Table2'
      */
  real_T uDLookupTable1_tableData[10];
                     /* Expression: [1 1  1 0.77 0.65 0.58 0.57 0.57 0.50 0.45 ]
                      * Referenced by: '<Root>/1-D Lookup Table1'
                      */
  real_T uDLookupTable1_bp01Data[10];
                                 /* Expression: [ -70 0 10 20 30 35 40 50 60 70]
                                  * Referenced by: '<Root>/1-D Lookup Table1'
                                  */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S5>/Constant'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint16_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S3>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_diaforiko_epitaxinsh__T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_diaforiko_epitaxinsh_PID_te_T diaforiko_epitaxinsh_PID_test_P;

/* Block signals (default storage) */
extern B_diaforiko_epitaxinsh_PID_te_T diaforiko_epitaxinsh_PID_test_B;

/* Block states (default storage) */
extern DW_diaforiko_epitaxinsh_PID_t_T diaforiko_epitaxinsh_PID_tes_DW;

/* External function called from main */
extern void diaforiko_epitaxinsh_PID_test_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void diaforiko_epitaxinsh_PID_test_initialize(void);
extern void diaforiko_epitaxinsh_PID_test_step0(void);
extern void diaforiko_epitaxinsh_PID_test_step1(void);
extern void diaforiko_epitaxinsh_PID_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_diaforiko_epitaxinsh_T *const diaforiko_epitaxinsh_PID_tes_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Constant' : Unused code path elimination
 * Block '<S37>/Derivative Gain' : Unused code path elimination
 * Block '<S38>/Filter' : Unused code path elimination
 * Block '<S38>/SumD' : Unused code path elimination
 * Block '<S40>/Integral Gain' : Unused code path elimination
 * Block '<S43>/Integrator' : Unused code path elimination
 * Block '<S46>/Filter Coefficient' : Unused code path elimination
 * Block '<S48>/Proportional Gain' : Unused code path elimination
 * Block '<S52>/Sum' : Unused code path elimination
 * Block '<S8>/Sum' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'diaforiko_epitaxinsh_PID_test'
 * '<S1>'   : 'diaforiko_epitaxinsh_PID_test/DC Motor3'
 * '<S2>'   : 'diaforiko_epitaxinsh_PID_test/Detect Path and Emit Index'
 * '<S3>'   : 'diaforiko_epitaxinsh_PID_test/Dip Switch'
 * '<S4>'   : 'diaforiko_epitaxinsh_PID_test/Line Scan Camera'
 * '<S5>'   : 'diaforiko_epitaxinsh_PID_test/Potentiometer'
 * '<S6>'   : 'diaforiko_epitaxinsh_PID_test/Servo Write'
 * '<S7>'   : 'diaforiko_epitaxinsh_PID_test/Shield LED D3'
 * '<S8>'   : 'diaforiko_epitaxinsh_PID_test/Steering'
 * '<S9>'   : 'diaforiko_epitaxinsh_PID_test/Transmit Camera Data On UART0 Once a Second'
 * '<S10>'  : 'diaforiko_epitaxinsh_PID_test/right'
 * '<S11>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller'
 * '<S12>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Anti-windup'
 * '<S13>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/D Gain'
 * '<S14>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Filter'
 * '<S15>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Filter ICs'
 * '<S16>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/I Gain'
 * '<S17>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Ideal P Gain'
 * '<S18>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S19>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Integrator'
 * '<S20>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Integrator ICs'
 * '<S21>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/N Copy'
 * '<S22>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/N Gain'
 * '<S23>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/P Copy'
 * '<S24>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Parallel P Gain'
 * '<S25>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Reset Signal'
 * '<S26>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Saturation'
 * '<S27>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Saturation Fdbk'
 * '<S28>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Sum'
 * '<S29>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Sum Fdbk'
 * '<S30>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Tracking Mode'
 * '<S31>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Tracking Mode Sum'
 * '<S32>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Tsamp - Integral'
 * '<S33>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Tsamp - Ngain'
 * '<S34>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/postSat Signal'
 * '<S35>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/preSat Signal'
 * '<S36>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S37>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S38>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S39>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S40>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S41>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S42>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Integrator/Discrete'
 * '<S44>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S45>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/N Copy/Disabled'
 * '<S46>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S47>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/P Copy/Disabled'
 * '<S48>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S49>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Reset Signal/Disabled'
 * '<S50>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Saturation/Passthrough'
 * '<S51>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S52>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Sum/Sum_PID'
 * '<S53>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S54>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S55>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S57>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S59>'  : 'diaforiko_epitaxinsh_PID_test/Steering/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                         /* RTW_HEADER_diaforiko_epitaxinsh_PID_test_h_ */

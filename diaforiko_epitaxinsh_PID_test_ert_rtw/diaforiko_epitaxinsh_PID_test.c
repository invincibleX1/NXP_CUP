/*
 * diaforiko_epitaxinsh_PID_test.c
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

#include "diaforiko_epitaxinsh_PID_test.h"
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "diaforiko_epitaxinsh_PID_test_private.h"

/* Block signals (default storage) */
B_diaforiko_epitaxinsh_PID_te_T diaforiko_epitaxinsh_PID_test_B;

/* Block states (default storage) */
DW_diaforiko_epitaxinsh_PID_t_T diaforiko_epitaxinsh_PID_tes_DW;

/* Real-time model */
static RT_MODEL_diaforiko_epitaxinsh_T diaforiko_epitaxinsh_PID_tes_M_;
RT_MODEL_diaforiko_epitaxinsh_T *const diaforiko_epitaxinsh_PID_tes_M =
  &diaforiko_epitaxinsh_PID_tes_M_;
static void rate_monotonic_scheduler(void);
real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T frac;
  real_T y;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void diaforiko_epitaxinsh_PID_test_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(diaforiko_epitaxinsh_PID_tes_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  diaforiko_epitaxinsh_PID_tes_M->Timing.RateInteraction.TID0_1 =
    (diaforiko_epitaxinsh_PID_tes_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (diaforiko_epitaxinsh_PID_tes_M->Timing.TaskCounters.TID[1])++;
  if ((diaforiko_epitaxinsh_PID_tes_M->Timing.TaskCounters.TID[1]) > 12) {/* Sample time: [0.26s, 0.0s] */
    diaforiko_epitaxinsh_PID_tes_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void diaforiko_epitaxinsh_PID_test_step0(void) /* Sample time: [0.02s, 0.0s] */
{
  real_T Threshold;
  real_T rtb_Product1;
  int32_T First_Edge;
  int32_T Second_Edge;
  int32_T i;
  int32_T k;
  real32_T rtb_centerIdx;
  uint8_T switchValues[4];
  boolean_T exitg1;

  {                                    /* Sample time: [0.02s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S4>/linescan Camera' incorporates:
   *  Constant: '<Root>/Exposure time'
   */
  MW_Set_Camera_Exposure(0.0, diaforiko_epitaxinsh_PID_test_P.Exposuretime_Value);
  MW_Refresh_Camera_Data(0.0);
  MW_Get_Camera_Image(0.0, &diaforiko_epitaxinsh_PID_test_B.Add_b[0]);

  /* Sum: '<S4>/Add' incorporates:
   *  Constant: '<S4>/Constant'
   *  MATLABSystem: '<S4>/linescan Camera'
   */
  for (First_Edge = 0; First_Edge < 128; First_Edge++) {
    diaforiko_epitaxinsh_PID_test_B.Add_b[First_Edge] = (uint16_T)(real32_T)fmod
      ((real32_T)(diaforiko_epitaxinsh_PID_test_B.Add_b[First_Edge] +
                  diaforiko_epitaxinsh_PID_test_P.Constant_Value_f), 65536.0);
  }

  /* End of Sum: '<S4>/Add' */

  /* RateTransition generated from: '<Root>/Transmit Camera Data On UART0 Once a Second' incorporates:
   *  Sum: '<S4>/Add'
   */
  if (diaforiko_epitaxinsh_PID_tes_M->Timing.RateInteraction.TID0_1) {
    memcpy(&diaforiko_epitaxinsh_PID_tes_DW.TmpRTBAtTransmitCameraDataOnUAR[0],
           &diaforiko_epitaxinsh_PID_test_B.Add_b[0], sizeof(uint16_T) << 7U);
  }

  /* End of RateTransition generated from: '<Root>/Transmit Camera Data On UART0 Once a Second' */

  /* MATLAB Function: '<Root>/Detect Path and Emit Index' incorporates:
   *  Sum: '<S4>/Add'
   */
  First_Edge = 1;
  Second_Edge = 128;
  i = diaforiko_epitaxinsh_PID_test_B.Add_b[39];
  for (k = 0; k < 40; k++) {
    i += diaforiko_epitaxinsh_PID_test_B.Add_b[k + 40];
  }

  Threshold = (real_T)i / 41.0 * 0.75;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 63)) {
    if (diaforiko_epitaxinsh_PID_test_B.Add_b[63 - i] < Threshold) {
      First_Edge = 64 - i;
      exitg1 = true;
    } else {
      i++;
    }
  }

  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 64)) {
    if (diaforiko_epitaxinsh_PID_test_B.Add_b[i + 63] < Threshold) {
      Second_Edge = i + 64;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if ((First_Edge > 1) && (Second_Edge < 128)) {
    rtb_centerIdx = (real32_T)(Second_Edge + First_Edge) / 2.0F;
  } else {
    rtb_centerIdx = 255.0F;
  }

  /* End of MATLAB Function: '<Root>/Detect Path and Emit Index' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  Threshold = rtb_centerIdx - diaforiko_epitaxinsh_PID_test_P.Constant_Value;

  /* MATLABSystem: '<S3>/Dip Switch' */
  MW_Get_Dip_Switch_Binary_Data(&switchValues[0]);

  /* MATLABSystem: '<S6>/Servo' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<S6>/toSingle'
   *  Gain: '<Root>/Gain'
   *  MATLABSystem: '<S3>/Dip Switch'
   *  Product: '<Root>/Product2'
   *  Sum: '<S3>/Add'
   */
  if (diaforiko_epitaxinsh_PID_tes_DW.obj.minAngle !=
      diaforiko_epitaxinsh_PID_test_P.ServoWrite_minAngle) {
    diaforiko_epitaxinsh_PID_tes_DW.obj.minAngle =
      diaforiko_epitaxinsh_PID_test_P.ServoWrite_minAngle;
  }

  if (diaforiko_epitaxinsh_PID_tes_DW.obj.maxAngle !=
      diaforiko_epitaxinsh_PID_test_P.ServoWrite_maxAngle) {
    diaforiko_epitaxinsh_PID_tes_DW.obj.maxAngle =
      diaforiko_epitaxinsh_PID_test_P.ServoWrite_maxAngle;
  }

  MW_Set_Servo_Angle(0.0, (real32_T)(diaforiko_epitaxinsh_PID_test_P.Gain_Gain *
    Threshold * (real_T)(uint8_T)(int32_T)(real32_T)fmod((real32_T)
    (switchValues[3] + diaforiko_epitaxinsh_PID_test_P.Constant_Value_d), 256.0)));

  /* End of MATLABSystem: '<S6>/Servo' */

  /* MATLABSystem: '<S5>/MATLAB System' */
  rtb_centerIdx = MW_Get_Potentiometer_Data(1);

  /* Product: '<Root>/Product3' incorporates:
   *  Abs: '<Root>/Abs'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S5>/Constant'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  Lookup_n-D: '<Root>/1-D Lookup Table'
   *  MATLABSystem: '<S3>/Dip Switch'
   *  MATLABSystem: '<S5>/MATLAB System'
   *  Product: '<Root>/Product'
   *  Sum: '<Root>/Sum1'
   *  Sum: '<S5>/Add'
   */
  rtb_Product1 = ((rtb_centerIdx +
                   diaforiko_epitaxinsh_PID_test_P.Constant_Value_j) *
                  diaforiko_epitaxinsh_PID_test_P.Gain2_Gain +
                  diaforiko_epitaxinsh_PID_test_P.Constant1_Value) *
    diaforiko_epitaxinsh_PID_test_P.Gain3_Gain * look1_binlcapw(fabs(Threshold),
    diaforiko_epitaxinsh_PID_test_P.uDLookupTable_bp01Data,
    diaforiko_epitaxinsh_PID_test_P.uDLookupTable_tableData, 3U) * (real_T)
    switchValues[2];

  /* MATLABSystem: '<S1>/DC Motor' incorporates:
   *  DataTypeConversion: '<S1>/toSingle'
   *  Lookup_n-D: '<Root>/1-D Lookup Table1'
   *  Lookup_n-D: '<Root>/1-D Lookup Table2'
   *  Product: '<Root>/Product4'
   */
  MW_Set_dcMotor_Speed(1.0, (real32_T)(look1_binlcapw(Threshold,
    diaforiko_epitaxinsh_PID_test_P.uDLookupTable2_bp01Data,
    diaforiko_epitaxinsh_PID_test_P.uDLookupTable2_tableData, 16U) *
    rtb_Product1));

  /* MATLABSystem: '<S10>/DC Motor' incorporates:
   *  DataTypeConversion: '<S10>/toSingle'
   *  Lookup_n-D: '<Root>/1-D Lookup Table1'
   *  Product: '<Root>/Product1'
   */
  MW_Set_dcMotor_Speed(0.0, (real32_T)(rtb_Product1 * look1_binlcapw(Threshold,
    diaforiko_epitaxinsh_PID_test_P.uDLookupTable1_bp01Data,
    diaforiko_epitaxinsh_PID_test_P.uDLookupTable1_tableData, 9U)));

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  Threshold = (diaforiko_epitaxinsh_PID_tes_DW.clockTickCounter <
               diaforiko_epitaxinsh_PID_test_P.PulseGenerator_Duty) &&
    (diaforiko_epitaxinsh_PID_tes_DW.clockTickCounter >= 0) ?
    diaforiko_epitaxinsh_PID_test_P.PulseGenerator_Amp : 0.0;
  if (diaforiko_epitaxinsh_PID_tes_DW.clockTickCounter >=
      diaforiko_epitaxinsh_PID_test_P.PulseGenerator_Period - 1.0) {
    diaforiko_epitaxinsh_PID_tes_DW.clockTickCounter = 0;
  } else {
    diaforiko_epitaxinsh_PID_tes_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S7>/Digital Output' */
  MW_Write_Digital_Pin(22, Threshold);
}

/* Model step function for TID1 */
void diaforiko_epitaxinsh_PID_test_step1(void) /* Sample time: [0.26s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Transmit Camera Data On UART0 Once a Second' */
  /* MATLABSystem: '<S9>/Serial Transmit' incorporates:
   *  RateTransition generated from: '<Root>/Transmit Camera Data On UART0 Once a Second'
   */
  memcpy(&diaforiko_epitaxinsh_PID_test_B.dataIn[0],
         &diaforiko_epitaxinsh_PID_tes_DW.TmpRTBAtTransmitCameraDataOnUAR[0],
         sizeof(uint16_T) << 7U);
  diaforiko_epitaxinsh_PID_tes_DW.obj_a.port = 1.0;
  diaforiko_epitaxinsh_PID_tes_DW.obj_a.dataType = 5.0;
  diaforiko_epitaxinsh_PID_tes_DW.obj_a.dataLength = 128U;
  MW_Serial_Transmit(1.0, &diaforiko_epitaxinsh_PID_test_B.dataIn[0], 128U, 5.0);

  /* End of Outputs for SubSystem: '<Root>/Transmit Camera Data On UART0 Once a Second' */
}

/* Model initialize function */
void diaforiko_epitaxinsh_PID_test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)diaforiko_epitaxinsh_PID_tes_M, 0,
                sizeof(RT_MODEL_diaforiko_epitaxinsh_T));

  /* states (dwork) */
  (void) memset((void *)&diaforiko_epitaxinsh_PID_tes_DW, 0,
                sizeof(DW_diaforiko_epitaxinsh_PID_t_T));

  /* Start for MATLABSystem: '<S4>/linescan Camera' */
  diaforiko_epitaxinsh_PID_tes_DW.obj_n.matlabCodegenIsDeleted = false;
  diaforiko_epitaxinsh_PID_tes_DW.objisempty_eh = true;
  diaforiko_epitaxinsh_PID_tes_DW.obj_n.isInitialized = 1;
  MW_Camera_Init(0.0);
  diaforiko_epitaxinsh_PID_tes_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/Dip Switch' */
  diaforiko_epitaxinsh_PID_tes_DW.obj_o.matlabCodegenIsDeleted = false;
  diaforiko_epitaxinsh_PID_tes_DW.objisempty_i = true;
  diaforiko_epitaxinsh_PID_tes_DW.obj_o.isInitialized = 1;
  diaforiko_epitaxinsh_PID_tes_DW.obj_o.simSampleNum = 0.0;
  MW_Dip_Switch_Init();
  diaforiko_epitaxinsh_PID_tes_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/Servo' */
  diaforiko_epitaxinsh_PID_tes_DW.obj.matlabCodegenIsDeleted = false;
  diaforiko_epitaxinsh_PID_tes_DW.objisempty_k = true;
  diaforiko_epitaxinsh_PID_tes_DW.obj.minAngle =
    diaforiko_epitaxinsh_PID_test_P.ServoWrite_minAngle;
  diaforiko_epitaxinsh_PID_tes_DW.obj.maxAngle =
    diaforiko_epitaxinsh_PID_test_P.ServoWrite_maxAngle;
  diaforiko_epitaxinsh_PID_tes_DW.obj.isInitialized = 1;
  MW_Servo_Init(0.0, diaforiko_epitaxinsh_PID_tes_DW.obj.minAngle,
                diaforiko_epitaxinsh_PID_tes_DW.obj.maxAngle);
  diaforiko_epitaxinsh_PID_tes_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S5>/MATLAB System' */
  diaforiko_epitaxinsh_PID_tes_DW.obj_m.matlabCodegenIsDeleted = false;
  diaforiko_epitaxinsh_PID_tes_DW.objisempty_hl = true;
  diaforiko_epitaxinsh_PID_tes_DW.obj_m.isInitialized = 1;
  MW_Pot_Init(1);
  diaforiko_epitaxinsh_PID_tes_DW.obj_m.isSetupComplete = true;

  /* Start for MATLABSystem: '<S1>/DC Motor' */
  diaforiko_epitaxinsh_PID_tes_DW.obj_p.matlabCodegenIsDeleted = false;
  diaforiko_epitaxinsh_PID_tes_DW.objisempty_d = true;
  diaforiko_epitaxinsh_PID_tes_DW.obj_p.isInitialized = 1;
  MW_dcMotor_Init(1.0);
  diaforiko_epitaxinsh_PID_tes_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S10>/DC Motor' */
  diaforiko_epitaxinsh_PID_tes_DW.obj_k.matlabCodegenIsDeleted = false;
  diaforiko_epitaxinsh_PID_tes_DW.objisempty = true;
  diaforiko_epitaxinsh_PID_tes_DW.obj_k.isInitialized = 1;
  MW_dcMotor_Init(0.0);
  diaforiko_epitaxinsh_PID_tes_DW.obj_k.isSetupComplete = true;

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  diaforiko_epitaxinsh_PID_tes_DW.clockTickCounter = 0;

  /* Start for MATLABSystem: '<S7>/Digital Output' */
  diaforiko_epitaxinsh_PID_tes_DW.obj_h.matlabCodegenIsDeleted = false;
  diaforiko_epitaxinsh_PID_tes_DW.objisempty_e = true;
  diaforiko_epitaxinsh_PID_tes_DW.obj_h.isInitialized = 1;
  MW_digitalOut_Init(22);
  diaforiko_epitaxinsh_PID_tes_DW.obj_h.isSetupComplete = true;

  /* Start for Atomic SubSystem: '<Root>/Transmit Camera Data On UART0 Once a Second' */
  /* Start for MATLABSystem: '<S9>/Serial Transmit' */
  diaforiko_epitaxinsh_PID_tes_DW.objisempty_h = true;
  diaforiko_epitaxinsh_PID_tes_DW.obj_a.isInitialized = 1;
  diaforiko_epitaxinsh_PID_tes_DW.obj_a.UartDataTypeWidth = 2U;
  diaforiko_epitaxinsh_PID_tes_DW.obj_a.dataLength = 256U;
  diaforiko_epitaxinsh_PID_tes_DW.obj_a.port = 1.0;
  MW_Serial_Init(1.0, 1.0, 0.0);

  /* End of Start for SubSystem: '<Root>/Transmit Camera Data On UART0 Once a Second' */

  /* InitializeConditions for MATLABSystem: '<S3>/Dip Switch' */
  diaforiko_epitaxinsh_PID_tes_DW.obj_o.simSampleNum = 0.0;
}

/* Model terminate function */
void diaforiko_epitaxinsh_PID_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/linescan Camera' */
  if (!diaforiko_epitaxinsh_PID_tes_DW.obj_n.matlabCodegenIsDeleted) {
    diaforiko_epitaxinsh_PID_tes_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((diaforiko_epitaxinsh_PID_tes_DW.obj_n.isInitialized == 1) &&
        diaforiko_epitaxinsh_PID_tes_DW.obj_n.isSetupComplete) {
      MW_Camera_Terminate(0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/linescan Camera' */

  /* Terminate for MATLABSystem: '<S3>/Dip Switch' */
  if (!diaforiko_epitaxinsh_PID_tes_DW.obj_o.matlabCodegenIsDeleted) {
    diaforiko_epitaxinsh_PID_tes_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((diaforiko_epitaxinsh_PID_tes_DW.obj_o.isInitialized == 1) &&
        diaforiko_epitaxinsh_PID_tes_DW.obj_o.isSetupComplete) {
      MW_Dip_Switch_Terminate();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Dip Switch' */

  /* Terminate for MATLABSystem: '<S6>/Servo' */
  if (!diaforiko_epitaxinsh_PID_tes_DW.obj.matlabCodegenIsDeleted) {
    diaforiko_epitaxinsh_PID_tes_DW.obj.matlabCodegenIsDeleted = true;
    if ((diaforiko_epitaxinsh_PID_tes_DW.obj.isInitialized == 1) &&
        diaforiko_epitaxinsh_PID_tes_DW.obj.isSetupComplete) {
      MW_Servo_Terminate(0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Servo' */

  /* Terminate for MATLABSystem: '<S5>/MATLAB System' */
  if (!diaforiko_epitaxinsh_PID_tes_DW.obj_m.matlabCodegenIsDeleted) {
    diaforiko_epitaxinsh_PID_tes_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((diaforiko_epitaxinsh_PID_tes_DW.obj_m.isInitialized == 1) &&
        diaforiko_epitaxinsh_PID_tes_DW.obj_m.isSetupComplete) {
      MW_Pot_Terminate(1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/MATLAB System' */

  /* Terminate for MATLABSystem: '<S1>/DC Motor' */
  if (!diaforiko_epitaxinsh_PID_tes_DW.obj_p.matlabCodegenIsDeleted) {
    diaforiko_epitaxinsh_PID_tes_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((diaforiko_epitaxinsh_PID_tes_DW.obj_p.isInitialized == 1) &&
        diaforiko_epitaxinsh_PID_tes_DW.obj_p.isSetupComplete) {
      MW_dcMotor_Terminate(1.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/DC Motor' */

  /* Terminate for MATLABSystem: '<S10>/DC Motor' */
  if (!diaforiko_epitaxinsh_PID_tes_DW.obj_k.matlabCodegenIsDeleted) {
    diaforiko_epitaxinsh_PID_tes_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((diaforiko_epitaxinsh_PID_tes_DW.obj_k.isInitialized == 1) &&
        diaforiko_epitaxinsh_PID_tes_DW.obj_k.isSetupComplete) {
      MW_dcMotor_Terminate(0.0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/DC Motor' */

  /* Terminate for MATLABSystem: '<S7>/Digital Output' */
  if (!diaforiko_epitaxinsh_PID_tes_DW.obj_h.matlabCodegenIsDeleted) {
    diaforiko_epitaxinsh_PID_tes_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((diaforiko_epitaxinsh_PID_tes_DW.obj_h.isInitialized == 1) &&
        diaforiko_epitaxinsh_PID_tes_DW.obj_h.isSetupComplete) {
      MW_digitalOut_Terminate(22);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Output' */
}

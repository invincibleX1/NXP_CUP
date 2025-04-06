/*
 * diaforiko_epitaxinsh_PID_test_data.c
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

/* Block parameters (default storage) */
P_diaforiko_epitaxinsh_PID_te_T diaforiko_epitaxinsh_PID_test_P = {
  /* Mask Parameter: ServoWrite_maxAngle
   * Referenced by: '<S6>/Servo'
   */
  70.0,

  /* Mask Parameter: ServoWrite_minAngle
   * Referenced by: '<S6>/Servo'
   */
  -70.0,

  /* Expression: 1
   * Referenced by: '<Root>/Exposure time'
   */
  1.0,

  /* Expression: 64
   * Referenced by: '<Root>/Constant'
   */
  64.0,

  /* Expression: 1.5
   * Referenced by: '<Root>/Gain'
   */
  1.5,

  /* Expression: [1.8 1 0.8 0.2]
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 1.8, 1.0, 0.8, 0.2 },

  /* Expression: [0 10 20 60]
   * Referenced by: '<Root>/1-D Lookup Table'
   */
  { 0.0, 10.0, 20.0, 60.0 },

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Gain3'
   */
  0.5,

  /* Expression: [0.45 0.5 0.57 0.57 0.58 0.65 0.77 1 1 1 1 1 1 1 1 1 1]
   * Referenced by: '<Root>/1-D Lookup Table2'
   */
  { 0.45, 0.5, 0.57, 0.57, 0.58, 0.65, 0.77, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    1.0, 1.0, 1.0 },

  /* Expression: [ -70 -60 -50 -40 -35 -30 -20 -10 0 10 20 30 35 40 50 60 70]
   * Referenced by: '<Root>/1-D Lookup Table2'
   */
  { -70.0, -60.0, -50.0, -40.0, -35.0, -30.0, -20.0, -10.0, 0.0, 10.0, 20.0,
    30.0, 35.0, 40.0, 50.0, 60.0, 70.0 },

  /* Expression: [1 1  1 0.77 0.65 0.58 0.57 0.57 0.50 0.45 ]
   * Referenced by: '<Root>/1-D Lookup Table1'
   */
  { 1.0, 1.0, 1.0, 0.77, 0.65, 0.58, 0.57, 0.57, 0.5, 0.45 },

  /* Expression: [ -70 0 10 20 30 35 40 50 60 70]
   * Referenced by: '<Root>/1-D Lookup Table1'
   */
  { -70.0, 0.0, 10.0, 20.0, 30.0, 35.0, 40.0, 50.0, 60.0, 70.0 },

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Computed Parameter: PulseGenerator_Period
   * Referenced by: '<Root>/Pulse Generator'
   */
  500.0,

  /* Computed Parameter: PulseGenerator_Duty
   * Referenced by: '<Root>/Pulse Generator'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S5>/Constant'
   */
  0.0F,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  -1.0F,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S4>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S3>/Constant'
   */
  0U
};

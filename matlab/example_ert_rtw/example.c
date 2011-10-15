/*
 * File: example.c
 *
 * Real-Time Workshop code generated for Simulink model example.
 *
 * Model version                        : 1.6
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Tue Oct 11 15:23:50 2011
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Tue Oct 11 15:23:52 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 10
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "example.h"
#include "example_private.h"

/* External inputs (root inport signals with auto storage) */
ExternalInputs_example example_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_example example_Y;

/* Real-time model */
RT_MODEL_example example_M_;
RT_MODEL_example *example_M = &example_M_;

/* Model step function */
void example_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Sum: '<Root>/Subtract'
   */
  example_Y.Out1 = (example_U.In1 - example_U.In2) * example_P.Gain_Gain;
}

/* Model initialize function */
void example_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(example_M, (NULL));

  /* external inputs */
  (void) memset((void *)&example_U, 0,
                sizeof(ExternalInputs_example));

  /* external outputs */
  example_Y.Out1 = 0.0;
}

/* Model terminate function */
void example_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */

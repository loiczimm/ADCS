/*
 * File: example.h
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

#ifndef RTW_HEADER_example_h_
#define RTW_HEADER_example_h_
#ifndef example_COMMON_INCLUDES_
# define example_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* example_COMMON_INCLUDES_ */

#include "example_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
  real_T In2;                          /* '<Root>/In2' */
} ExternalInputs_example;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExternalOutputs_example;

/* Parameters (auto storage) */
struct Parameters_example_ {
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_example {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_example example_P;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_example example_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_example example_Y;

/* Model entry point functions */
extern void example_initialize(void);
extern void example_step(void);
extern void example_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_example *example_M;

void matlabSet(int, int);
int matlabGet(void);
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
 * '<Root>' : example
 */
#endif                                 /* RTW_HEADER_example_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */

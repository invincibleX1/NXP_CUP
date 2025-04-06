#include "diaforiko_epitaxinsh_PID_test.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  diaforiko_epitaxinsh_PID_test_SetEventsForThisBaseStep(eventFlags);
  __enable_irq();
  diaforiko_epitaxinsh_PID_test_step0();

  /* Get model outputs here */
  __disable_irq();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    __enable_irq();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      diaforiko_epitaxinsh_PID_test_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

    __disable_irq();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.02;
  float systemClock = 48;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  BoardInit();
  rtmSetErrorStatus(diaforiko_epitaxinsh_PID_tes_M, 0);
  diaforiko_epitaxinsh_PID_test_initialize();

#ifdef EXT_MODE

  wait_ms(1000);

#endif

  (void) systemClock;
  ARMCM_SysTick_Config(modelBaseRate);
  runModel = rtmGetErrorStatus(diaforiko_epitaxinsh_PID_tes_M) == (NULL);
  __enable_irq();
  while (runModel) {
    stopRequested = !(rtmGetErrorStatus(diaforiko_epitaxinsh_PID_tes_M) == (NULL));
    runModel = !(stopRequested);
  }

  /* Terminate model */
  diaforiko_epitaxinsh_PID_test_terminate();

#ifdef EXT_MODE

  wait_ms(1000);

#endif

  (void) systemClock;
  return 0;
}

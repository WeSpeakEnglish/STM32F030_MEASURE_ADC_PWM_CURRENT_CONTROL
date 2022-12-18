#include "nortos.h"

volatile int F_last; // number of last element of fast-speed queue
int F_first; // number of first element of fast-speed queue

void SimpleF(){;};

void (*pFastQueue[Q_SIZE_FAST])();

inline void pFastQueueIni(void){ // initialization of Queue
  F_last = 0;
  F_first = 0;
}

inline int F_push(void (*pointerQ)(void) ){ // push element from the queue
  if ((F_last+1)%Q_SIZE_FAST == F_first)return 1;
  pFastQueue[F_last++] = pointerQ;
  F_last%=Q_SIZE_FAST;
  return 0;
}

inline void (*F_pull(void))(void){ // pull element from the queue
  void (*pullVar)(void);
  if (F_last == F_first)return SimpleF;
  pullVar = pFastQueue[F_first++];
  F_first%=Q_SIZE_FAST;
  return pullVar;
}

// ------ 8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----

volatile int FP_last; // number of last element of fast-speed queue
int FP_first; // number of first element of fast-speed queue

void SimpleFP(){;};

void (*FP_Queue[Q_SIZE_FAST])(struct fParams *);
struct fParams PARAMS_array[Q_SIZE_FAST];

void FP_QueueIni(void){ // initialization of Queue
  FP_last = 0;
  FP_first = 0;
}

int FP_push(void (*pointerQ)(struct fParams *), struct fParams * parameterQ){ // push element from the queue
  if ((FP_last+1)%Q_SIZE_FAST == FP_first)return 1;
  FP_Queue[FP_last] = pointerQ;
  PARAMS_array[FP_last++] = *parameterQ;
  FP_last%=Q_SIZE_FAST;
  return 0;
}

void FP_pull(void){ // pull element from the queue
  void (*pullVar)(struct fParams *);
  struct fParams * Params;
  if (FP_last == FP_first)return;
  Params = &PARAMS_array[FP_first];
  pullVar = FP_Queue[FP_first++];
  FP_first %= Q_SIZE_FAST;
  pullVar(Params);
}

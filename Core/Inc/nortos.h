/*
 * nortos.h
 *
 *  Created on: 18 дек. 2022 г.
 *      Author: Nutzer
 */

#ifndef INC_NORTOS_H_
#define INC_NORTOS_H_

#include <stdint.h>

#define Q_SIZE_FAST 16

void pFastQueueIni(void); // initialization of Queue
int F_push(void (*pointerQ)(void) ); // push element from the queue
void (*F_pull(void))(void); // pull element from the queue


// ------ 8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----8<----
struct fParams {
  uint8_t channel;
  int32_t value; //up+/down-
};

void FP_QueueIni(void); // initialization of Queue
int FP_push(void (*pointerQ)(struct fParams *), struct fParams * parameterQ);
void FP_pull(void); // pull element into the queue




#endif /* INC_NORTOS_H_ */

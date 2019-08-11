/*
 * Scheduler.h
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_SCHEDULER_SCHEDULER_H_
#define E15_REPO_SRC_SCHEDULER_SCHEDULER_H_

/*========================================
 * FUNCTIONS PROTOTYPES
 * ======================================*/
#include "../utils/STD_Types.h"

#define Active				true
#define Suspended			false
void Scheduler_createTask(Ptr2FuncType Task,uint32 TaskPeriodicity, boolean TaskStatus);
void Scheduler_init(void);
void Set_Periodicity(Ptr2FuncType Task,uint32 TaskPeriodicity);
void Set_Task_Status(Ptr2FuncType Task, boolean TaskStatus);

#endif /* E15_REPO_SRC_SCHEDULER_SCHEDULER_H_ */

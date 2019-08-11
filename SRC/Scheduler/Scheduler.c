/*
 * Scheduler.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */
/*========================================
 * INCLUDES
 * ======================================*/
#include "../utils/Bit_Math.h"
#include "../utils/STD_Types.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../config/Scheduler_cfg.h"
#include "Scheduler_types.h"
#include "Scheduler.h"

#include "../utils/Interrupts.h"
/*========================================
 * LOCAL PROTOTYPES FUNCTIONS
 * ======================================*/
inline static void Scheduler(void);

/*========================================
 * STATIC VARIABLE
 * ======================================*/
static Scheduler_TaskType TasksArr[SCHEDULER_MAX_NO_OF_TASKS];
static uint8 CurrentNumOfTasks =0;
/*========================================
 * FUNCTIONS Definitions
 * ======================================*/
void Scheduler_init(void)
{
	GI_EN();
	TIMER0_init();

}
void Scheduler_createTask(Ptr2FuncType TaskPtr,uint32 TaskPeriodicity, boolean TaskStatus)
{
	if(CurrentNumOfTasks < SCHEDULER_MAX_NO_OF_TASKS)
	{
		TasksArr[CurrentNumOfTasks].Ptr2Task = TaskPtr;
		TasksArr[CurrentNumOfTasks].Periodicity = TaskPeriodicity;
		TasksArr[CurrentNumOfTasks].Status = TaskStatus;
		CurrentNumOfTasks++;
	}
}
inline static void Scheduler(void)
{
	uint8 i;
	static uint32 Scheduler_Counter = 0;

	for(i=0;i<CurrentNumOfTasks;i++)
	{
		if(((Scheduler_Counter% TasksArr[i].Periodicity) == 0) && (TasksArr[i].Status))
		{
			TasksArr[i].Ptr2Task();
		}
	}
	Scheduler_Counter++;
}
void Set_Periodicity(Ptr2FuncType Task,uint32 TaskPeriodicity)
{
	uint8 i;
	for(i=0;i<CurrentNumOfTasks;i++)
	{
		if(Task == TasksArr[i].Ptr2Task)
		{
			TasksArr[i].Periodicity = TaskPeriodicity;
		}
	}
}
void Set_Task_Status(Ptr2FuncType Task, boolean TaskStatus)
{
	uint8 i;
	for(i=0;i<CurrentNumOfTasks;i++)
	{
		if(Task == TasksArr[i].Ptr2Task)
		{
			TasksArr[i].Periodicity = TaskStatus;
		}
	}
}

void ISR(TIMER0_COMP)
{
	Scheduler();

}

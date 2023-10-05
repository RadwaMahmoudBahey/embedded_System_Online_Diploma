* README
Introduction
My code represents implementation of My own real-time operating system (RTOS) . It includes functions for task management, task activation and termination, mutex management, OS activation, and task waiting ,..etc

Functions::



1. `Dispatch_Next_Task()`
   - Purpose: Dispatches the next task to be executed.
   - Checks if the ready queue is empty and the current task is not suspended.
   - If conditions are met, marks the current task as running, enqueues it in the ready queue, and sets the next task as the current task.
   - Otherwise, dequeues the next task from the ready queue, marks it as running, and performs additional checks for priority-based scheduling.

2. `OS_SVC(uint32_t *Stack_frame)`
   - Purpose: Handles OS service calls (SVC).
   - Called when an SVC instruction is executed.
   - Extracts the SVC number from the stack frame and performs different actions based on the number.
   - For SVC numbers related to task activation and termination, updates the task table, checks the OS state, dispatches the next task, and triggers a context switch.
   - For SVC numbers related to task waiting time, updates the task table.

3. `bubble_sort()`
   - Purpose: Implements the bubble sort algorithm to sort the task table based on task priorities.
   - Iterates through the task table and swaps tasks if they are out of order based on their priorities.

4. `PendSV_Handler()`
   - Purpose: Handles the context switching between tasks.
   - PendSV exception handler.
   - Saves the current task's context (registers r4-r11) manually.
   - Checks if there is a next task.
   - If a next task exists, updates the current task and restores its context.
   - Updates the PSP (Process Stack Pointer) to the new task's stack and returns.

5. `RadwaRTOS_Activate_OS()`
   - Purpose: Activates the OS.
   - Sets the OS state to running, initializes the current task as the idle task, activates the idle task.
   - Starts the system tick timer, sets the PSP to the current task's stack.
   - Switches CPU access to unprivileged mode.
   - Calls the idle task's entry point.

6. `RadwaRTOS_UpdateWaiting_time()`
   - Purpose: Updates the waiting time of tasks that are currently suspended and waiting actively.
   - Decrements the waiting time and checks if the waiting time has reached 1.
   - If so, changes the task's state to waiting and triggers an SVC call to handle the waiting time.

7. `SysTick_Handler()`
   - Purpose: Handler for the SysTick timer interrupt.
   - Toggles an LED (Systick_LED), updates the waiting time of tasks.
   - Dispatches the next task and triggers a context switch.


8. `void RadwaRTOS_CREATE_TASK_STACK(Taskref* task)`
   - This function is responsible for creating the stack frame for a task.
   - It initializes the task's stack by setting the initial values for the registers and the program counter.
   - The function takes a pointer to a `Taskref` structure representing the task for which the stack frame is being created.

9. `RadwaRTOS_error RadwaRTOS_CREATE_TASK(Taskref* task)`
   - This function creates a new task in the RTOS.
   - It sets up the stack for the task by calling the `RadwaRTOS_CREATE_TASK_STACK` function.
   - The task is added to the task table, and the task count is incremented.
   - The task's initial state is set to "Suspend."
   - The function returns a `RadwaRTOS_error` value indicating any errors encountered during task creation.

10. `void RadwaRTOS_CREATE_MAIN_STACK(void)`
   - This function creates the main stack for the RTOS.
   - It sets the start and end addresses of the main stack based on the `_estack` symbol and the `MainStack_Size` value.
   - The function also sets the initial value of the PSP locator.

11. `void RadwaRTOS_IDLE_TASK(void)`
   - This function represents the idle task, which runs when no other task is ready to execute.
   - It toggles the state of the `Idle_LED` (presumably a global variable) and enters a wait-for-event (WFE) instruction to put the processor into a low-power mode until an interrupt occurs.

12. `RadwaRTOS_error RadwaRTOS_CREATE_IDLE_TASK(void)`
   - This function creates the idle task in the RTOS.
   - It initializes the priority, task name, task entry point, and stack size of the idle task.
   - The function then calls `RadwaRTOS_CREATE_TASK` to create the idle task and returns any errors encountered during task creation.

13. `RadwaRTOS_error RadwaRTOS_Init(void)`
   - This function initializes the RadwaRTOS.
   - It sets the operating system state to "Suspend," initializes the main stack, creates the ready queue, and creates the idle task.
   - The function returns a `RadwaRTOS_error` value indicating any errors encountered during initialization.

14. `int OS_SVC_SET(int SVC_ID)`
   - This function is used to invoke specific services (SVC) provided by the RTOS.
   - It takes an SVC ID as a parameter and triggers a software interrupt (SVC instruction) with the corresponding ID.
   - The function allows tasks to request services from the RTOS, such as activating a task, terminating a task, or waiting for a specific time.

 
 
15. `void RadwaRTOS_UpdateTask_table()`
   - This function updates the task table and the ready queue based on the current state of tasks.
   - It first sorts the task table using the `bubble_sort()` function.
   - Then, it clears the ready queue by dequeuing all elements from it.
   - Next, it iterates through the task table, checks the task states, and adds the tasks with non-suspend states to the ready queue.
   - The tasks are enqueued in descending order of priority.
   - If a higher-priority task is found, the loop breaks to ensure that only the highest-priority task is added to the ready queue.
   - The function ensures that the ready queue is updated with the most up-to-date tasks.

16. `void RadwaRTOS_ACTIVATE_TASK(Taskref* task)`
   - This function activates a task by changing its state to "Waiting" and calling the `OS_SVC_SET()` function with the `SVC_ActivateTask` ID.
   - The task is marked as waiting and will be made ready by the scheduler when appropriate.

17. `void RadwaRTOS_TERMINATE_TASK(Taskref* task)`
   - This function terminates a task by changing its state to "Suspend" and calling the `OS_SVC_SET()` function with the `SVC_TerminateTask` ID.
   - The task is marked as suspended and will no longer be scheduled for execution.

18. `void RadwaRTOS_TASK_WAIT(Taskref* task, uint32_t delay)`
   - This function suspends a task for a specified delay period.
   - It changes the task's state to "Suspend" and sets the waiting time information.
   - The `blocking` flag is enabled to indicate that the task is waiting actively.
   - The `OS_SVC_SET()` function is called with the `SVC_TerminateTask` ID to initiate the waiting process.

19. `RadwaRTOS_error RadwaRTOS_ACQUIRE_MUTEX(Mutexref* mutex, Taskref* task)`
   - This function is used to acquire a mutex for a task.
   - It takes a pointer to a `Mutexref` structure and a pointer to the task as parameters.
   - If the mutex is not currently acquired by any task, the current task is assigned as the owner of the mutex.
   - If the mutex is already acquired, and there is no next task waiting for the mutex, the next task is set as the next owner of the mutex, and the current task is terminated.
   - If there is already a next task waiting for the mutex, an error (`Mutex_reached_max_users`) is returned.
   - The function returns a `RadwaRTOS_error` value indicating any errors encountered during the acquisition process.

20. `void RadwaRTOS_RELEASE_MUTEX(Mutexref* mutex)`
   - This function releases a mutex.
   - It takes a pointer to a `Mutexref` structure as a parameter.
   - If the current task is the owner of the mutex, the next task waiting for the mutex becomes the new owner.
   - The current task is activated by calling `RadwaRTOS_ACTIVATE_TASK()` with the current task as the parameter.

  


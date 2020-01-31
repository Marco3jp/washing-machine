#ifndef MANAGER_H
#define	MANAGER_H

void start_processing();

// continue processing for other layer functions.
int continue_processing(); 

// is there next process? for continueProcessing();
int is_continuable(); 

// do washing machine complete current processing? for continueProcessing();
int is_complete_current_processing();

// operate hardware. wash, rinse, spin. for continueProcessing();
void run_processing();

#endif
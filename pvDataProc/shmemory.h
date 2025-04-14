#ifndef _SHMEMORY_
#define _SHMEMORY_

#include "rlsharedmemory.h"

typedef struct{
	float F1,F2;
} shmdata_t;

#define SHMREAD  shm.read(0,&shmData,sizeof(shmdata_t));
#define SHMWRITE shm.write(0,&shmData,sizeof(shmdata_t));

#ifdef _MAIN_
rlSharedMemory shm("/srv/automation/shm/shmemory.shm",sizeof(shmdata_t));
shmdata_t shmData;
#else
extern rlSharedMemory shm;
extern shmdata_t shmData;
#endif

#endif

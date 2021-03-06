#ifndef MASTER_H
#define MASTER_H

#include "errors.h"
#include "semIPC.h"
#include "shm.h"
#include <fcntl.h> /* For O_* constants */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#define READ 0
#define WRITE 1
#define STDOUT 1
#define STDIN 0
#define SLAVES 7
#define SLAVE_PATH "./slave"

typedef struct slaveinfo {
	int fdAnswersRead;
	int fdTasksWrite;
	int tasks;
} slaveinfo;

void createSlaves(int slaveCount, int initialTasks, char *files[], slaveinfo *slave);
void closeSlaves(slaveinfo *slave, int slaveCount);
void assignTasks(slaveinfo *slave, int slaveCount, int remainingTasks, FILE *results, char *tasks[]);
int writeResult(FILE *results, slaveinfo slave);
void newTask(slaveinfo *slave, char *tasks[]);
char *createShm(int tasks);
void writeShm(char *results);
int assignProcesses(int fileCount);
void closeShm();

#endif
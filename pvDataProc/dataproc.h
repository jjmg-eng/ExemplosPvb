#include "mbox.h"
#include "shmemory.h"

#include "qtdatabase.h"
#include <QCoreApplication>
qtDatabase db;
const char *tableName="DataProc";
char buf[1024];
void setup();

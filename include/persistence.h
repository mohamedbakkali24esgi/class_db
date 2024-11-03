#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "table.h"

void save_table(const Table* table, const char* filename);
Table* load_table(const char* filename);

#endif
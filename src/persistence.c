#include <stdio.h>
#include <stdlib.h>
#include "persistence.h"

void save_table(const Table* table, const char* filename) {
    
    FILE* file = fopen(filename, "wb");
    
    if (file == NULL) {
        perror("Could not open file for writing");
        return;
    }

    fwrite(&table->num_rows, sizeof(size_t), 1, file);

    fwrite(table->rows, sizeof(Row), table->num_rows, file);
    fclose(file);
}

Table* load_table(const char* filename) {
    
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Could not open file for reading");
        return NULL;
    }

    Table* table = create_table(100); 
    if (table == NULL) {
        fclose(file);
        perror("Could not create table");
        return NULL;
    }

    size_t num_rows;
    if (fread(&num_rows, sizeof(size_t), 1, file) != 1) {
        fclose(file);
        free(table->rows);
        free(table);
        perror("Could not read number of rows");
        return NULL;
    }

    table->num_rows = num_rows;

    if (num_rows > table->capacity) {
        Row* new_rows = realloc(table->rows, sizeof(Row) * num_rows);
        if (new_rows == NULL) {
            fclose(file);
            free(table->rows);
            free(table);
            perror("Could not reallocate memory for rows");
            return NULL;
        }
        table->rows = new_rows;
        table->capacity = num_rows;
    }

    if (fread(table->rows, sizeof(Row), table->num_rows, file) != table->num_rows) {
        fclose(file);
        free(table->rows);
        free(table);
        perror("Could not read rows from file");
        return NULL;
    }

    fclose(file);
    return table;
}

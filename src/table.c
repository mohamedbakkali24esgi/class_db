#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

Table* create_table(size_t capacity) {
    Table* table = malloc(sizeof(Table));
    if (table == NULL) {
        perror("Could not allocate memory for table");
        exit(EXIT_FAILURE);
    }

    table->num_rows = 0;
    table->capacity = capacity;
    table->rows = malloc(sizeof(Row) * capacity);
    if (table->rows == NULL) {
        perror("Could not allocate memory for rows");
        free(table); // Free allocated table memory
        exit(EXIT_FAILURE);
    }
    return table;
}

void insert_row(Table* table, uint32_t id, const char* username, const char* email, const char* password) {
    if (table->num_rows >= table->capacity) {
        printf("Table is full. Cannot insert new row.\n");
        return; 
    }
    Row* row = &table->rows[table->num_rows++];
    
    row->id = id;
    strncpy(row->username, username, COLUMN_USERNAME_SIZE);
    row->username[COLUMN_USERNAME_SIZE - 1] = '\0'; 
    strncpy(row->email, email, COLUMN_EMAIL_SIZE);
    row->email[COLUMN_EMAIL_SIZE - 1] = '\0';
    strncpy(row->password, password, COLUMN_PASSWORD_SIZE);
    row->password[COLUMN_PASSWORD_SIZE - 1] = '\0';
}

void insert_row_autocrument(Table* table, const char* username, const char* email,const char* password) {
    if (table->num_rows >= table->capacity) {
        printf("Table is full. Cannot insert new row.\n");
        return; // Exit if the table is full
    }
    int nb = last_id(table)+1;
    printf("nb : %d\n",nb);
    Row* row = &table->rows[table->num_rows++];
    
    row->id =(uint32_t) nb ; 
    strncpy(row->username, username, COLUMN_USERNAME_SIZE);
    row->username[COLUMN_USERNAME_SIZE - 1] = '\0'; 
    strncpy(row->email, email, COLUMN_EMAIL_SIZE);
    row->email[COLUMN_EMAIL_SIZE - 1] = '\0';
    strncpy(row->password, password, COLUMN_PASSWORD_SIZE );
    row->password[COLUMN_PASSWORD_SIZE - 1] = '\0'; 
}

void select_statement(const Table* table) {
    for (size_t i = 0; i < table->num_rows; i++) {
        Row* row = &table->rows[i];
        printf("Row %zu: ID: %d, Username: %s, Email: %s , Password: %s\n", (unsigned long)(i + 1), row->id, row->username, row->email,row->password);
    }
}

int last_id(const Table* table) {
    if (table->num_rows == 0) {
        return 0; 
    }
    Row* row = &table->rows[table->num_rows - 1];
    printf("Last ID: %d\n", row->id);
    return row->id;
}

void free_table(Table* table) {
    free(table->rows);
    free(table);
}

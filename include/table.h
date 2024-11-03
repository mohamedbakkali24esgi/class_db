#ifndef TABLE_H
#define TABLE_H

#include <stddef.h> 
#include <stdint.h> 
#define COLUMN_USERNAME_SIZE 100
#define COLUMN_EMAIL_SIZE 100
#define COLUMN_PASSWORD_SIZE 100


typedef struct {
    uint32_t id;
    char username[COLUMN_USERNAME_SIZE];
    char email[COLUMN_EMAIL_SIZE];
    char password[COLUMN_PASSWORD_SIZE];
} Row;

typedef struct {
    Row* rows;
    size_t num_rows;
    size_t capacity;
} Table;

Table* create_table(size_t capacity);
void insert_row(Table* table, uint32_t id, const char* username, const char* email,const char* password);
void select_statement(const Table* table);
void free_table(Table* table);

#endif

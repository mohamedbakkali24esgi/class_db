#include <stdio.h>
#include <stdlib.h>
#include "table.h"
#include "persistence.h"

#define FILENAME "./data/database.dat"

int main() {
    Table* table = load_table(FILENAME); 
    if (table == NULL) {
        printf("Creating a new table\n");
        table = create_table(100); 
    }

   
    printf("\nbefore : %d %d  %d\n",last_id(table),table->capacity,table->num_rows);
    
    
    insert_row_autocrument(table, "test1", "test1@example.com","test1");
    insert_row_autocrument(table, "test1", "test1@example.com","test1");
    
    


    select_statement(table);

    save_table(table, FILENAME);
    free_table(table);
    return 0;
}

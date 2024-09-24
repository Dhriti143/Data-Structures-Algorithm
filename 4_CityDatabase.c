//City database using Linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LEN 100

typedef struct CityRecord {
    char name[MAX_NAME_LEN];
    int x, y;
    struct CityRecord *next;
} CityRecord;

// Function to insert a new record into the linked list
void insert_record(CityRecord **head, char *name, int x, int y) {
    CityRecord *new_record = (CityRecord *)malloc(sizeof(CityRecord));
    strncpy(new_record->name, name, MAX_NAME_LEN);
    new_record->x = x;
    new_record->y = y;
    new_record->next = NULL;
    if (*head == NULL) {
        *head = new_record;
    } else {
        CityRecord *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_record;
    }
}

// Function to delete a record by name or coordinate
void delete_record(CityRecord **head, char *name, int x, int y) {
    CityRecord *current = *head;
    CityRecord *prev = NULL;
    while (current != NULL) {
        if ((name != NULL && strcmp(current->name, name) == 0) ||
            (x != -1 && y != -1 && current->x == x && current->y == y)) {
            if (prev == NULL) {
                // Record is the head of the list
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to search for a record by name or coordinate
CityRecord *search_record(CityRecord *head, char *name, int x, int y) {
    CityRecord *current = head;
    while (current != NULL) {
        if ((name != NULL && strcmp(current->name, name) == 0) ||
            (x != -1 && y != -1 && current->x == x && current->y == y)){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print all records within a given distance of a specified point
void print_records_within_distance(CityRecord *head, int x, int y, double distance) {
    CityRecord *current = head;
    while (current != NULL) {
        double dx = current->x - x;
        double dy = current->y - y;
        double dist = sqrt(dx*dx + dy*dy);
        if (dist <= distance) {
            printf("%s (%d, %d)\n", current->name, current->x, current->y);
        }
        current = current->next;
    }
}

// Function to print all records
void print_records(CityRecord *head){
    while(head!=NULL){
        printf("%s %d %d, ",head->name,head->x,head->y);
        head=head->next;
    }
    printf("End\n");
}

// Main function to test the city database
int main() {
    CityRecord *head = NULL;
    insert_record(&head, "Delhi", 10, 20);
    insert_record(&head, "Mumbai", 30, 40);
    insert_record(&head, "Chennai", 50, 60);
    insert_record(&head, "Kolkata", 70, 80);
    insert_record(&head, "Ahmedabad", 90, 100);

    printf("All records:\n");
    print_records(head);

    printf("\nDelete record by name: Mumbai\n");
    delete_record(&head, "Mumbai", 0, 0);
    print_records(head);

    printf("\nDelete record by coordinates: (50, 60)\n");
    delete_record(&head, "", 50, 60);
    print_records(head);

    printf("\nSearch record by coordinates: (90, 100)\n");
    CityRecord *result2 = search_record(head, "", 90, 100);
    if (result2 != NULL) {
        printf("Record found: %s (%d, %d)\n", result2->name, result2->x, result2->y);
    } else {
        printf("Record not found\n");
    }

    printf("\nPrint all records within distance of (0, 0): 50.0\n");
    print_records_within_distance(head, 0, 0, 50.0);

    return 0;
}

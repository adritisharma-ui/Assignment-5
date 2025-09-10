#include <stdio.h>
#include <stdlib.h>
#define SIZE 7  

struct Node {
    int key;
    struct Node* next;
};

struct Node* table[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;
}

int search(int key) {
    int index = hashFunction(key);
    struct Node* temp = table[index];
    while (temp != NULL) {
        if (temp->key == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void deleteKey(int key) {
    int index = hashFunction(key);
    struct Node* temp = table[index];
    struct Node* prev = NULL;

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;  
    if (prev == NULL)
        table[index] = temp->next;
    else
        prev->next = temp->next;
    free(temp);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d --> ", i);
        struct Node* temp = table[i];
        while (temp != NULL) {
            printf("%d ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, key;
    do {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(key))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}

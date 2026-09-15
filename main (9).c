
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char *text;
    struct ListNode *next;
    struct ListNode *previous;
} ListNode;

ListNode *createNode(const char *text) {
    ListNode *newNode = malloc(sizeof(ListNode));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->text = malloc(strlen(text) + 1);

    if (newNode->text == NULL) {
        free(newNode);
        return NULL;
    }

    strcpy(newNode->text, text);

    newNode->next = NULL;
    newNode->previous = NULL;

    return newNode;
}

void insertItem(ListNode **head, const char *text) {
    ListNode *newNode = createNode(text);

    if (newNode == NULL) {
        printf("Unable to allocate memory.\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    ListNode *current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->previous = current;
}

ListNode *findItem(ListNode *head, const char *text) {
    ListNode *current = head;

    while (current != NULL) {
        if (strcmp(current->text, text) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void deleteItem(ListNode **head, ListNode *node) {
    if (node == NULL) {
        return;
    }

    if (node->previous != NULL) {
        node->previous->next = node->next;
    } else {
        *head = node->next;
    }

    if (node->next != NULL) {
        node->next->previous = node->previous;
    }

    free(node->text);
    free(node);
}

void printList(ListNode *head) {
    ListNode *current = head;

    printf("List: ");

    while (current != NULL) {
        printf("%s", current->text);

        if (current->next != NULL) {
            printf(" <-> ");
        }

        current = current->next;
    }

    printf("\n");
}

void freeList(ListNode **head) {
    ListNode *current = *head;

    while (current != NULL) {
        ListNode *nextNode = current->next;

        free(current->text);
        free(current);

        current = nextNode;
    }

    *head = NULL;
}

int main(void) {
    printf("Hello, World!\n\n");

    ListNode *head = NULL;

    insertItem(&head, "apple");
    insertItem(&head, "banana");
    insertItem(&head, "orange");
    insertItem(&head, "grape");

    printf("After inserting items:\n");
    printList(head);

    ListNode *result = findItem(head, "banana");

    if (result != NULL) {
        printf("\nFound: %s\n", result->text);
    } else {
        printf("\nItem was not found.\n");
    }

    printf("\nDeleting banana...\n");
    deleteItem(&head, findItem(head, "banana"));
    printList(head);

    printf("\nDeleting apple...\n");
    deleteItem(&head, findItem(head, "apple"));
    printList(head);

    result = findItem(head, "strawberry");

    if (result == NULL) {
        printf("\nstrawberry was not found in the list.\n");
    }

    freeList(&head);

    return 0;
}

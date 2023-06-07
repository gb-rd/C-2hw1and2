#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;
list *memlist = NULL;

void insert(list **head, void *address, size_t size, char *comment) {
    list *tmp = malloc(sizeof(list));
    tmp->next = *head;
    tmp->address = address;
    tmp->size = size;
    sprintf(tmp->comment,"%s",comment);
    *head = tmp;
}

void push(list **head, int size, char comment) {
    list *tmp = (list*) malloc(sizeof(list));
    tmp->next = (*head);
    tmp->size = size;
    sprintf(tmp->comment,"%d",comment);
    (*head) = tmp;
}

void printLinkedList(const list *head) {
    while (head) {
        printf("%ld:", (long)&head->address);
        printf("%3s:", head->comment);
        printf("%3lu\n", head->size);
        head = head->next;
    }
    printf("\n");
}

int pop(list **head) {
    list* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->size;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

void fromArray(list **head, int *arr, size_t size) {
    size_t i = size - 1;
    char comment = 'a';
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i], comment+i);
    } while(i--!=0);
}

/*
int deleteNth(Node **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        Node *prev = getNth(*head, n-1);
        Node *elm  = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;
    }
}
*/

void slist_clear(list **head){
    list *t, *p = *head;
    while(p != NULL){
        t = p;
        p = p->next;
        free(t);
    }
    *head = NULL;
}

void *findMaxBlock(list *head) {

    if (head == NULL) {
        return NULL;
    }
    else {
        unsigned int max = 0;
        long *addr = malloc(sizeof(long));

        max = head->size;
        *addr = (long)&head->address;
                printf("1: %ld\n", *addr);

        head = head->next;

        while (head != NULL) {
            if(head->size > max) {
                max = head->size;
                *addr = (long)&head->address;
            }
            head = head->next;
        }
        printf("2: %ld\n", *addr);
        return (long*)*addr;
    }
}

void *findMaxBlock2(list *head) {

    if (head == NULL) {
        return NULL;
    }
    else {
        size_t max = 0;
        void *addr;

        max = head->size;
        addr = head->address;
        head = head->next;

        while (head != NULL) {
            if(head->size > max) {
                max = head->size;
                addr = head->address;
            }
            head = head->next;
        }
       return addr;
    }
}

size_t totalMemoryUsage(list *head) {

    if (head == NULL) {
        return 0;
    }
    else {
        size_t total = 0;
        //void *addr;

        //max = head->size;
        //addr = head->address;
        //head = head->next;

        while (head != NULL) {
            //if(head->size > max) {
                total += head->size;
                //addr = head->address;
            //}
            head = head->next;
        }
       return total;
    }
}

int main() {
    int i, sum;
    list *head = NULL;

    int arr[] = {1002,30,100,10,9,1003,7,8,1003,11};
    fromArray(&head, arr, 10);
/*
    for(i = 0; i < 10; ++i){
        push(&head, rand() % 10, i);
        printf("%lu ", head->size);
    }
*/
    //long arr[] = {140525067852320, 140525067852328, 140525067852360};
    //push(head*, arr[0], 1, 1);
    printLinkedList(head);
//    findMaxBlock(head);
//    printf("r: %ld\n",(long *findMaxBlock(head)));
//    long test = (long*)findMaxBlock(head);
    printf("l: %ld\n", totalMemoryUsage(head));
    return 0;
}

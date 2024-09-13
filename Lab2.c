#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node Node;


struct Node {
    int value;
    struct Node * next;
};

int contains(Node * head, int value){
    
    while(head != NULL){
        
        if(head->value == value){
            return 1;
            
        }
        
        head = head->next;
    }
    
    return 0;
}

Node * removeByValue(Node * head, int value){
    if (head == NULL) return NULL;
    
    //check if the head should be removed
    if (head->value == value){
        Node * newHead = head-> next;
        free(head);
        return newHead;
    }
    
    Node * prev = head;
    while(prev->next != NULL &&prev->next->value != value){
        prev= prev->next;
    }
    
    if(prev->next !=NULL){
        Node * rem = prev->next;
        prev->next = rem->next;
        free(rem);
    }
    
    return head;
}
Node * removeAll(Node * head, int value){
    Node * prev = NULL;
    Node * cur = head;
    
    while(cur){
        
        if (cur-value == value){
            
            if(prev == NULL){
                
                cur = cur->next;
                free(head);
                head = cur;
            }else{
                
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }else{
            
            prev= cur;
            cur = cur->next;
        }
    }
    return head;
}
Node * createNode(int v){
    Node * res = (Node*) malloc(sizeof(Node));
    res->value = v;
    res->next = NULL;
    return res;
}
Node * insertHead(Node * head, int v){
    Node * newHead = createNode(v);
    newHead->next = head;
    return newHead;
}
void printList(Node * head){
    while(head){
        printf("%d ->", head->value);
        head = head->next;
    }
    printf("NULL\n");
}
/*
4) worst case is when you have numbers at the beginning that we don't 
want to delete followed by values you want to delete because it 
procts all functions
*/
int main()
{
    srand(time(0));
    Node * head = NULL;
    for (int i=0; i < 12; i++){
        printf("Removing %d.\n", i);
        head = removeAll(head, i);
        printList(head);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define 

struct node {
    char val[100];
    struct node *next;
};
struct node *add(struct node *list, char c[]) {
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->val, c);
    new_node->next = list;
    return new_node;
}
int ans = 0;
int exist(struct node *list, char c[]) {
    struct node *pointer = list;
    int cnt = 1;
    int existed = 0;
    fprintf(stderr, "Find %s: ", c);
    for(;pointer!=NULL;pointer = pointer->next) {
        fprintf(stderr, "%s->", pointer->val);
        if(strcmp(pointer->val, c)==0) {
            existed = 1;
            break;
        }
        cnt++;
    }
    fprintf(stderr, "\t%s, Index: %d\n", existed ? "True" : "False", cnt);
    if(!existed) return 0;
    if(cnt == 1) return 1;

    pointer = list;
    for(int i=0;i<cnt-2;++i) {
        pointer = pointer->next;
    }
    struct node *trashNode = pointer->next;
    pointer->next = pointer->next->next;
    free(trashNode);
    return cnt;
}
int main() {

    struct node *list = NULL;

    char c;
    while(scanf("%c", &c) && c!='0') {
        if(!isalpha(c)) {
            printf("%c", c);
            continue;
        }
        int pointer = 0;
        char buffer[100];
        do {
            buffer[pointer++] = c;
        } while(scanf("%c", &c) && c!='0' && isalpha(c));
        buffer[pointer] = '\0';
        // printf("'%s'%c", buffer, c);
        int existIndex = exist(list, buffer);
        if(existIndex) {
            printf("%d", existIndex);
        } else {
            printf("%s", buffer);
        }
        if(existIndex != 1)
            list = add(list, buffer);
        printf("%c", c);

    }
    return 0;
}
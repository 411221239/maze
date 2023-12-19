#include <stdio.h>
#include <stdlib.h>
#define MAX_N 10

typedef struct position{
    int x;
    int y;
    struct position *next;
} pos;

typedef struct queue{
    int size;
    pos *first, *last;
} q;

void init(q *qq){
    qq -> size = 0;
    qq -> first = NULL;
    qq -> last = NULL;
}

void add(q *qq, int x, int y){
    pos *tmp = (pos *)malloc(sizeof(pos));
    tmp -> x = x;
    tmp -> y = y;
    tmp -> next = NULL;
    if(qq -> first == NULL) qq -> first = tmp;
    else qq -> last -> next = tmp;
    qq -> last = tmp;
    qq -> size++;
}

pos del(q *qq){
    pos *tmp = qq -> first;
    qq -> first = tmp -> next;
    if(qq -> first == NULL) qq -> last = NULL;
    qq -> size--;
    return *tmp;
}

int maze[MAX_N][MAX_N] ={
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
    { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
    { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }};
    
int main()
{
    
    q remain;
    init(&remain);
    add(&remain, 1, 0);
    while(remain.size > 0){
        pos t = del(&remain);
        maze[t.x][t.y] = 1;
        if(t.x == 6 && t.y == 9){
            printf("Yes");
            return 0;
        }
        
        if(maze[t.x-1][t.y] == 0){
            add(&remain, t.x-1, t.y);
            maze[t.x-1][t.y] = 1;
        }
        if(maze[t.x+1][t.y] == 0){
            add(&remain, t.x+1, t.y);
            maze[t.x+1][t.y] = 1;
        }
        if(maze[t.x][t.y-1] == 0){
            add(&remain, t.x, t.y-1);
            maze[t.x][t.y-1] = 1;
        }
        if(maze[t.x][t.y+1] == 0){
            add(&remain, t.x, t.y+1);
            maze[t.x][t.y+1] = 1;
        }
    }
    printf("No");
}



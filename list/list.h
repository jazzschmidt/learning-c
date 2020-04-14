
typedef struct {
    long size;
    int* elements;
} intlist;

intlist il_create();

long il_push(intlist*, int);

int il_get(intlist*, long);

void il_pop(intlist*);

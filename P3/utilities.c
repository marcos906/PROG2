#include "utilities.h"

int int_cmp(const void *c1, const void *c2) {
    if (!c1 || !c2)
    return INT_MIN;
    return (*(int *)c1 - *(int *)c2);
}

int int_print (FILE *pf, const void *a) {
    if (!pf || !a) return -1;
    return fprintf(pf, "%d", *(int *)a);
}

/* textprinter.c */

#include <stdio.h>
#include "mingmond.h"

metric_group *text_printer(metric_group *mg) {
    int c = 0;
    metric m;

    for (c = 0; c < METRIC_GROUP_MAX_SIZE ; c++) {

        m = mg->metrics[c];

        if(metric_is_new(&m)) {
            break;
        }

        printf("%20s_%-20s : ",mg->name, m.name);
        switch(mg->type) {
            case VALUE_INT:
                printf("int:%d\n", m.val.i);
                break;
            case VALUE_LONG:
                printf("long:%lu\n", m.val.l);
                break;
            case VALUE_FLOAT:
                printf("float:%f\n", m.val.f);
                break;
            default:
                fatal_error("Unsupported metric type\n");
                break;
        }
    }



    return mg;
}
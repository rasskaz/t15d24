#ifndef SRC_LIBS_H_
#define SRC_LIBS_H_


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define levels_fpath "../materials/master_levels.db"
#define modules_fpath "../materials/master_modules.db"
#define events_fpath "../materials/master_status_events.db"

typedef struct modules modules;
typedef struct levels levels;
typedef struct events events;

struct modules {
    int id;
    char name[30];
    int level;
    int cell;
    int flag;   
};

struct levels {
    int level;
    int cells_num;
    int pr_flag;
};

struct events {
    int event_id;
    int module_id;
    int status;
    char date[11];
    char time [9];
};



#endif  // SRC_LIBS_H_

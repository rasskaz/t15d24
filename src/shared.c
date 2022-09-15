#include "libs.h"
#include "modules.h"
#include "levels.h"
#include "status_events.h"

int getChoice(int gap1, int gap2) {
    int num;
    while (1) {
        if (scanf("%d", &num) != 1)
            printf("n/a\n");
        else if ((num > gap2) || (num < gap1))
            printf("n/a\n");
        else
            break;
    }
    return num;
}

int showTables() {
    int is_error = 0;
    FILE* mptr = fopen(modules_fpath, "rb");
    FILE* lptr = fopen(levels_fpath, "rb");
    FILE* eptr = fopen(events_fpath, "rb");
    if ((mptr == NULL) || (lptr == NULL) || (eptr == NULL)) {
        is_error = 1;
    } else {
        printf("MODULES:\n");
        printModules(mptr);
        printf("=======================\nLEVELS:\n");
        printLevels(lptr);
        printf("=======================\nEVENTS:\n");
        printEvents(eptr);
    }
    fclose(mptr);
    fclose(lptr);
    fclose(mptr);
    return is_error;
}

void printMenu1() {
    printf("==============================\n"
        " 0 SHOW MODULES\n 1 ADD MODULE\n 2 INSERT MODULE\n"
        " 3 CHANGE MODULE\n 4 REMOVE MODULE\n-1 BACK\n"
        "==============================\n");
}

int modulesControll() {
    int is_error = 0;
    int choice;
    int id;
    int flag = 1;
    modules rec;
    FILE* ptr = fopen(modules_fpath, "r+b");
    while (flag) {
        printMenu1();
        choice = getChoice(-1, 4);
        switch (choice) {
            case 0:
                printModules(ptr);
                break;
            case 1:
                id = getLastId(ptr);
                rec = getModulesRecord(id+1);
                is_error = addModulesRecord(ptr, rec);
                printModules(ptr);
                break;
            case 2:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkModulesId(ptr, id)) {
                    rec = getModulesRecord(id);
                    is_error = insertModulesRecord(ptr, id, rec);
                    printModules(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 3:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkModulesId(ptr, id)) {
                    rec = getModulesRecord(id);
                    is_error = changeModulesRecord(ptr, id, rec);
                    printModules(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 4:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkModulesId(ptr, id)) {
                    deleteModulesRecord(ptr, id);
                    printModules(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case -1:
                flag = 0;
                break;
        }
        if (is_error)
            flag = 0;
    }
    return is_error;
}

void printMenu2() {
    printf("==============================\n"
        " 0 SHOW LEVELS\n 1 ADD LEVEL\n 2 INSERT LEVEL\n"
        " 3 CHANGE LEVEL\n 4 REMOVE LEVEL\n-1 BACK\n"
        "==============================\n");
}

int levelsControll() {
    int is_error = 0;
    int choice;
    int id;
    int flag = 1;
    levels rec;
    FILE* ptr = fopen(levels_fpath, "r+b");
    while (flag) {
        printMenu2();
        choice = getChoice(-1, 4);
        switch (choice) {
            case 0:
                printLevels(ptr);
                break;
            case 1:
                rec = getLevelsRecord();
                is_error = addLevelsRecord(ptr, rec);
                printLevels(ptr);
                break;
            case 2:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkLevelsId(ptr, id)) {
                    rec = getLevelsRecord();
                    is_error = insertLevelsRecord(ptr, id, rec);
                    printLevels(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 3:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkLevelsId(ptr, id)) {
                    rec = getLevelsRecord();
                    is_error = changeLevelsRecord(ptr, id, rec);
                    printLevels(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case 4:
                printf("Which one?\n");
                id = getChoice(-1000000, 1000000);
                if (checkLevelsId(ptr, id)) {
                    is_error = deleteLevelsRecord(ptr, id);
                    printLevels(ptr);
                } else {
                    printf("Doesn't exist\n");
                }
                break;
            case -1:
                flag = 0;
                break;
        }
        if (is_error)
            flag = 0;
    }
    return is_error;
}

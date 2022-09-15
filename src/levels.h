#ifndef SRC_LEVELS_H_
#define SRC_LEVELS_H_

#include "libs.h"

int addLevelsRecord(FILE* ptr, levels rec);
levels getLevelsRecord();
int deleteLevelsRecord(FILE* ptr, int id);
int insertLevelsRecord(FILE* ptr, int id, levels new_rec);
int changeLevelsRecord(FILE* ptr, int id, levels rec);
int checkLevelsId(FILE* ptr, int id);
int printLevels(FILE* ptr);

#endif  // SRC_LEVELS_H_

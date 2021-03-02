//
//  studentsDB.h
//  school
//
//  Created by Christos Papadopoulos on 02/03/2021.
//

#ifndef studentsDB_h
#define studentsDB_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern long long int nbStudents;
typedef struct STUDENT_T STUDENT;

STUDENT *destroyStudents(STUDENT *students);
STUDENT *loadDB(void);
#endif /* studentsDB_h */

//
//  main.c
//  school
//
//  Created by Christos Papadopoulos on 02/03/2021.
//

#include <stdio.h>

#include "studentsDB.h"


int main(int argc, const char * argv[]) {
    printf("-----STUDENT_DB----\n");
    STUDENT *students = loadDB();
    printf("%p", students);
    
    getc(stdin);
    destroyStudents(students);
}

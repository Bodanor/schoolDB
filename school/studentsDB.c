//
//  studentsDB.c
//  school
//
//  Created by Christos Papadopoulos on 02/03/2021.
//

#include "studentsDB.h"
//TODO: Créer un constructeur des students puis remplir avec loadDB
struct STUDENT_T
{
    char *matricule;
    int age;
    char *prenom;
    char *nom;
    
};

int long long nbStudents = 0;


STUDENT *loadDB(void)
{
    const int BUFFSIZE = 100;
    FILE * s_db = fopen("Students.db", "r");
    if (s_db == NULL)
    {
        return NULL;
    }
    
    STUDENT *Students = NULL;
    
    char buffer[1000];
    int count = 0;
    int arrlen = 0;
    
    while (fgets(buffer, sizeof(buffer), s_db))
    {
        if (count == arrlen)
        {
            arrlen += BUFFSIZE;
            
            STUDENT *student = realloc(Students, arrlen*sizeof(STUDENT));
            if (student == NULL)
            {
                return NULL;
            }
            
            Students = student;
            
            
        }
        
        char matricule_temp[1000];
        int age_temp = 0;
        char prenom_temp[1000];
        char nom_temp[1000];
        
        sscanf(buffer, "%s %d %s %s", matricule_temp, &age_temp, prenom_temp, nom_temp);
        
        Students[count].matricule = malloc(sizeof(char)*strlen(matricule_temp) + 1);
        if (Students[count].matricule == NULL)
        {
            return NULL;
        }
        Students[count].prenom = malloc(sizeof(char)*strlen(prenom_temp) + 1);
        if (Students[count].prenom == NULL)
        {
            return NULL;
        }
        Students[count].nom = malloc(sizeof(char)*strlen(nom_temp) +1);
        if (Students[count].nom == NULL)
        {
            return NULL;
        }
        
        strcpy(Students[count].matricule, matricule_temp);
        strcpy(Students[count].prenom, prenom_temp);
        strcpy(Students[count].nom, nom_temp);
        
        Students[count].age = age_temp;
        
        count++;
        nbStudents++;
        
    }
    fclose(s_db);
    return Students;
}

STUDENT *destroyStudents(STUDENT *students)
{
    for (int x = 0; x < nbStudents; x++)
    {
        free(students[x].matricule);
        free(students[x].nom);
        free(students[x].prenom);
    }
    free(students);
    
    
    return NULL;
}

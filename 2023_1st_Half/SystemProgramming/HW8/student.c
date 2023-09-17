#include <stdio.h>
#include <stdlib.h>

#include "student.h"

FILE* fp = NULL;
STUDENT rec = { 0 };

void stu_register(void);
void stu_search(void);
void stu_change(void);
void clearInputBuffer(void);

int main(int argc, char* argv[])
{
  char mode = 0;
  char re = 0;

  if(argc != 2)
  {
    fprintf(stderr, "wrong input\n");
	exit(1);
  }

  fp = fopen(argv[1], "wb+");

  stu_register();

  // clearInputBuffer();

  do
  {
    printf("\nYou can search student by ID or change information\n");
    printf("Enter \'s\' to search, \'c\' to change\n");
    printf("Enter here(s/c): ");

    scanf(" %c", &mode);

    switch(mode)
    {
      case 's':
		    stu_search();
		    break;

      case 'c':
		    stu_change();
		    break;

	  default:
		    printf("Wrong input\n");
    }

    printf("Continue?(y/n): ");
    scanf(" %c", &re);

  }while(re == 'y');
}

void stu_register(void)
{
  printf("-----Enter \'Student_ID Name Subject Grade\'-----\n");
  printf("--------------Enter ctrl+D to finish-------------\n");

  while(scanf("%d %s %s %c", &rec.id, rec.name, rec.subject, &rec.grade) == 4)
  {
	fseek(fp, (rec.id - STARTID)*sizeof(rec), SEEK_SET);
    fwrite(&rec, sizeof(rec), 1, fp);
  }

  printf("\n------------Informations you entered-----------\n");
  
  rewind(fp);
  while(fread(&rec, sizeof(rec), 1, fp) > 0)
  {
	if(rec.id == 0)
	{
      continue;
	}

    printf("%d %s %s %c\n", rec.id, rec.name, rec.subject, rec.grade);
  }
}

void stu_search(void)
{
  int search_id = 0;

  printf("\n---------------Enter Student ID----------------\n");
  scanf("Enter here: ");
  scanf("%d", &search_id);

  fseek(fp, (rec.id - STARTID)*sizeof(rec), SEEK_SET);
  if((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0))
  {
    printf("%d %s %s %c\n", rec.id, rec.name, rec.subject, rec.grade);
  }
  else
  {
    printf("Not Exist\n");
  }
}

void stu_change(void)
{  
  int change_id = 0;
  char mode = 0;

  printf("\n---------------Enter Student ID----------------\n");
  printf("Enter here: ");
  scanf("%d", &change_id);
  
  printf("Enter \'s\' to change subject, \'g\' to change grade");
  printf("Enter here: ");
  scanf(" %c", &mode);

  switch(mode)
  {
	case 's':
		fseek(fp, (change_id - STARTID)*sizeof(rec), SEEK_SET);
		if((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0))
		{
          printf("%d %s %s %c\n", rec.id, rec.name, rec.subject, rec.grade);

		  fseek(fp, -sizeof(rec), SEEK_CUR);
		  printf("Enter new subject\n");
		  scanf("%s", rec.subject);

		  fwrite(&rec, sizeof(rec), 1, fp);
		}
		else
		{
		  printf("Not Exist\n");
		}

		break;

	case 'g':
		fseek(fp, (change_id - STARTID)*sizeof(rec), SEEK_SET);
		if((fread(&rec, sizeof(rec), 1, fp) > 0) && (rec.id != 0))
		{
          printf("%d %s %s %c\n", rec.id, rec.name, rec.subject, rec.grade);

		  fseek(fp, -sizeof(rec), SEEK_CUR);
		  printf("Enter new grade\n");
		  scanf(" %c", &rec.grade);

		  fwrite(&rec, sizeof(rec), 1, fp);
		}
		else
		{
		  printf("Not Exist\n");
		}

		break;

	default:
		printf("wrong input\n");
  }
}

void clearInputBuffer(void)
{
  while(getchar() != '\n');
}

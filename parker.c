#include<string.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Student{
    char full_name[200];
    int age;
    int roll;
    char faculty[150];
    char sex[10];
};

struct Book{
    char title[200];
    char author[300];
    int edition;
    int roll;
    int is_borrowed;
    int number_of_pages;
    char colour[100];
    int year_of_publication;
};
struct Student stud_1;
struct Student stud_2;
struct Book Book_1;
struct Book Book_2;
void login(){
    printf("\n\n\t\t\t******************************LOGIN*********************************\n\n\n\n");
    char user[100], id[100];
    printf("Enter your login: ");
    scanf("%s", user);
    printf("\n\nEnter your password: ");
    scanf("%s", id);
    if(strcmp(user, "admin")==0 && strcmp(id, "password")==0){
        printf("Login successful.");
    }
    else{
        printf("Login failed.");
    }
}

void password(){

    int i =0 ;
    char arr[100],pass[100]="password";
    printf("\n\n\n\t\t\t******************************CHANGE PASSWORD********************************\n\n\n\n");
    printf("Enter your old password:   ");
    scanf("%s",arr);

    printf("**************************************************************************************");
    do{
            if(strcmp(arr,pass)==0){
            printf("\n\n\n\nEnter your new password:   " );
            scanf("%s",&arr);
    }else{
        printf("Incorrect password");
        break;
    }
    }while(i<4);
}

void display_b(){
    struct Book Book_1;
    struct Book Book_2;
    FILE*library;
    library = fopen("book.txt","r");

    if(library != NULL){
       printf("\n**************************LIST OF BOOKS****************************************\n\n\n\n\n\n\n");
       fopen("book.txt","r");

       fscanf(library,"%s%s%d%d%d%s%d",Book_1.title,&Book_1.author,&Book_1.edition,&Book_1.is_borrowed,&Book_1.number_of_pages,&Book_1.colour,&Book_1.year_of_publication);
       printf("%s\n%s\n%d\nBORROWED:  %d\n%d\n%s\n%d\n",Book_1.title,Book_1.author,Book_1.edition,Book_1.number_of_pages,Book_1.colour,Book_1.year_of_publication);

       printf("**********************************************************************************");

     fscanf(library,"%s%s%d%d%d%s%d",Book_2.title,&Book_2.author,&Book_2.edition,&Book_2.is_borrowed,&Book_2.number_of_pages,&Book_2.colour,&Book_2.year_of_publication);
       printf("%s\n%s\n%d\nBORROWED:  %d\n%d\n%s\n%d\n",Book_2.title,Book_2.author,Book_2.edition,Book_2.number_of_pages,Book_2.colour,Book_2.year_of_publication);

        fclose(library);
    }else{
        printf("\n\n\n\n\t\t\t*****************NO BOOK YET***********************\n\n\n\n");
    }
}

void change(){
    int a[10];
   printf("\t\t\n\n\n\n**********************CHANGE BOOK/STUDENT INFORMATION*********************************\n\n\n");

   printf("DO YOU WANT TO CHANGE A BOOK OR A STUDENT (YOUR TEXT MUST BE IN SMALL LETTER)?     ");
   scanf("%s",&a[10]);

   if(a=="book"){
    system("cls");

    struct Book Book_1;

        printf("\t\t\t\n\n\n\n**********************************CHANGE BOOK INFORMATION**************************************\n\n\n");
        FILE*fp1,*fp2;
        int roll;

        printf("Enter the roll number of the book you want to update");
        scanf("%d\n",&roll);

        fp1=fopen("book.txt","r+");
        fp2=fopen("copy.txt","a+");

        if(fp1==NULL){
            fprintf(stderr,"Error opening the file");
            exit(1);
        }
        while(fread(&Book_1,sizeof(struct Book),10,fp1)){
            if(Book_1.roll != roll){
                fwrite(&Book_1,sizeof(struct Book),10,fp2);
            }
        }
        char title[200];
        char author[300];
        int edition;
        int rol;
        int is_borrowed;
        int number_of_pages;
        char colour[100];
        int year_of_publication;


   printf("Enter the new title of the book:   ");
   scanf("%s",&title);
   printf("Enter the author's name:   ");
   scanf("%s",&author);
   printf("Enter it's roll number:   ");
   scanf("%d",&rol);
   printf("Is it borrowed(1(YES) or 0(NO))?:   ");
   scanf("%d",&is_borrowed);
   printf("Enter it's number of pages:   ");
   scanf("%d",&number_of_pages);
   printf("Enter it's colour:   ");
   scanf("%s",&colour);
   printf("Enter it's year of publication:   ");
   scanf("%d",&year_of_publication);


   struct Book Book_2={title,author,edition,rol,is_borrowed,number_of_pages,colour,year_of_publication};
   fwrite(&Book_2.roll ,sizeof(struct Book),10,fp2);
   fclose(fp1);
   fclose(fp2);

   remove("book.txt");
   rename("copy.txt","book.txt");
   printf("\n\n\nBOOK UPDATED SUCCESSFULLY");

   return 0;

   }else{
        system("cls");

    struct Student stud_1;

        printf("\n\n\n\n************************************CHANGE STUDENT INFORMATION********************************************\n\n\n");
        FILE*fp1,*fp2;
        int roll;

        printf("Enter the id of the student you want to update");
        scanf("%d\n",&roll);

        fp1=fopen("student.txt","r+");
        fp2=fopen("copy.txt","a+");

        if(fp1==NULL){
            fprintf(stderr,"Error opening the file");
            exit(1);
        }
        while(fread(&stud_1,sizeof(struct Student),10,fp1)){
            if(stud_1.roll != roll){
                fwrite(&stud_1,sizeof(struct Student),10,fp2);
            }
        }
        char full_name[200];
        int age;
        int rol;
        char faculty[150];
        char sex[10];

   printf("Enter the new full name of the student:   ");
   scanf("%d",&full_name);
   printf("Enter the student's age:   ");
   scanf("%d",&age);
   printf("Enter his\her id:   ");
   scanf("%d",&rol);
   printf("Enter his\her faculty:   ");
   scanf("%s",&faculty);
   printf("Enter his\her sex:   ");
   scanf("%s",&sex);

   struct Student stud_2 = {full_name,age,rol,faculty,sex};
   fwrite(&stud_2,sizeof(struct Student),10,fp2);
   fclose(fp1);
   fclose(fp2);

   remove("student.txt");
   rename("copy.txt","student.txt");
   printf("\n\n\nRECORD UPDATED SUCCESSFULLY");

   return 0;
   }
}

void borrow_return(){
    printf("\n\n\n\n*********************************BORROW OR RETURN BOOK***************************************************");

       FILE *library;
   struct Book Book_1;
   struct Book Book_2;
   int id_to_borrow_or_return;
   char action[10];

    library= fopen("books.txt", "r+");

   printf("Enter the roll number of the book to borrow or return: ");
   scanf("%d", &id_to_borrow_or_return);

   while(fread(&Book_1, sizeof(Book_1), 1, library) == 1) {
      if(Book_1.roll == id_to_borrow_or_return) {

        if(Book_1.is_borrowed == 1) {
            printf("The book is already borrowed.\n");
         } else {
            printf("The book is available. Do you want to borrow it? (yes/no) ");
            scanf("%s", action);
            if(strcmp(action, "yes") == 0) {

               Book_1.is_borrowed = 1;
               fseek(library, -sizeof(Book_1), SEEK_CUR);
               fwrite(&Book_1, sizeof(Book_1), 1, library);
               printf("You have successfully borrowed the book.\n");
            }
         }
         if(Book_1.is_borrowed == 0) {
            printf("The book is currently borrowed. Do you want to return it? (yes/no) ");
            scanf("%s", action);
            if(strcmp(action, "yes") == 0) {

               Book_1.is_borrowed = 0;
               fseek(library, -sizeof(Book_1), SEEK_CUR);
               fwrite(&Book_1, sizeof(Book_1), 1, library);
               printf("You have successfully returned the book.\n");
            }
         }
         break;
      }
   }

   fclose(library);
}

void display_s(){
    struct Student stud_1;
    struct Student stud_2;
    FILE*college;
    college = fopen("college.txt","r");

    if(college != NULL){
       printf("\n*****************************************LIST OF STUDENTS*******************************************\n\n\n\n");
       fopen("student.txt","r");

       fscanf(college,"%s%d%s%s",stud_1.full_name,&stud_1.age,&stud_1.faculty,&stud_1.sex);
       printf("%s\n%d\n%s\n%s",stud_1.full_name,stud_1.age,stud_1.faculty,stud_1.sex);

       printf("***********************************************************************************************\n\n\n");

       fscanf(college,"%s%d%s%s",&stud_2.full_name,&stud_2.age,&stud_2.faculty,&stud_2.sex);
       printf("%s\n%d\n%s\n%s",stud_2.full_name,stud_2.age,stud_2.faculty,stud_2.sex);

        fclose(college);
    }else{
        printf("\n\n******************************************NO STUDENT YET*******************************************\n\n");
    }
}

void insert_s(){
    struct Student stud_1;
    FILE*college;
    college=fopen("student.txt","a+");

    printf("Enter the Full Name of the student:    ");
    scanf("%s",stud_1.full_name);
    printf("\n\nEnter his\her age:    ");
    scanf("%d",stud_1.age);
    printf("\n\nEnter his\her id:    ");
    scanf("%d",stud_1.roll);
    printf("\n\nEnter his\her faculty:    ");
    scanf("%s",stud_1.faculty);
    printf("\n\nEnter his\her gender:    ");
    scanf("%s",stud_1.sex);

    fprintf(college,"%s\n%d\n%d\n%s\n%s",stud_1.full_name,stud_1.age,stud_1.roll,stud_1.faculty,stud_1.sex);
    fclose(college);
 }

void del(){
    char a[100];
    printf("\n\n***************************DELETE A STUDENT OR BOOK RECORD******************************\n\n\n\n");

    printf("What do you want to delete ?(student or book):    ");
    scanf("%s",a);

    if(a =="book"){
            system("cls");
            printf("\n\n\n*********************************DELETE A BOOK FROM THE LIBRARY**************************************\n\n\n");
            FILE*library,*fp;
struct Book Book_1;
struct Book Book_2;

int roll;
printf("Enter the roll number of the student:   ");
scanf("%d",&roll);
    library = fopen("book.txt","r+");
    fp = fopen("copy.del","a+");
          if(library == NULL){
            printf("NO BOOK YET");
            exit(0);
          }while(fread(&stud_1,sizeof(struct Student),10,library)){

            if(Book_1.roll!=roll){
                fwrite(&Book_1,sizeof(struct Book),10,fp);
            }
          }
            fclose(library);
            fclose(fp);

            remove("book.txt");
            rename("copy.del","book.txt");

            printf("Record deleted successfully");

    }else{
        system("cls");
        printf("\n\n\n**************************************DELETE A STUDENT FROM THE LIBRARY**************************************/n/n/n");
                   FILE*college,*fp;
struct Student stud_1;
struct Student stud_2;

int roll;
printf("Enter the id of the student:   ");
scanf("%d",&roll);
    college = fopen("student.txt","r+");
    fp = fopen("copy.del","a+");
          if(college == NULL){
            printf("NO STUDENT YET");
            exit(0);
          }while(fread(&stud_1,sizeof(struct Student),10,college)){

            if(stud_1.roll!=roll){
                fwrite(&stud_1,sizeof(struct Student),10,fp);
            }
          }
            fclose(college);
            fclose(fp);

            remove("student.txt");
            rename("copy.del","student.txt");

            printf("Record deleted successfully");

    }
}

void insert_b(){
    struct Book Book_1;
    printf("\n\n\n********************************************BOOK LIBRARY*******************************************");
    FILE*library;
    library=fopen("book.txt","a+");

    printf("Enter the book's Name:    ");
    scanf("%s",Book_1.title);
    printf("\n\nEnter the name of it's author:    ");
    scanf("%s",Book_1.author);
    printf("\n\nEnter the year of edition:    ");
    scanf("%d",Book_1.edition);
    printf("\n\nEnter the roll number:    ");
    scanf("%d",Book_1.roll);
    printf("\n\nIs this book borrowed?(1(YES) or 0(NO)):     ");
    scanf("%d",Book_1.is_borrowed);
    printf("\n\nEnter the number of pages of this book:    ");
    scanf("%d",Book_1.number_of_pages);
    printf("\n\nEnter the book's colour:    ");
    scanf("%s",Book_1.colour);
    printf("\n\nEnter the year of publication:    ");
    scanf("%d",Book_1.edition);

    fprintf(library,"%s\n%s\n%d\n%d\n%s\n%d",Book_1.title,Book_1.author,Book_1.edition,Book_1.is_borrowed,Book_1.number_of_pages,Book_1.colour,Book_1.year_of_publication);
    fclose(library);
 }

int main(){
    int screen;

  printf("\t\t\tWELCOME TO PKFOKAM'S LIBRARY MANAGEMENT SYSTEM\n");
  printf("(Version of STUDENT 1 and STUDENT 2)-Date: 29/05/2023\n");
  printf("Menu:\n");
  printf("  1. Login as a user\n");
  printf("  2. Add book\n");
  printf("  3. Add student\n");
  printf("  4. List of books\n");
  printf("  5. List of students\n");
  printf("  6. Modify book and student\n");
  printf("  7. Borrow and return book\n");
  printf("  8. Delete student or/and book record\n");
  printf("  9. Change password\n");
  printf("  10. Exit\n");

  printf("\t\t\t\t\t****WHAT DO YOU WANT TO DO ?****");
  scanf("%d",&screen);

    switch(screen){
    case 1:
    system("cls");
       login();
       break;

    case 2:
    system("cls");
    insert_b();
    break;

    case 3:
    system("cls");
    insert_s();
    break;

    case 4:
    system("cls");
    display_b();
    break;

    case 5:
    system("cls");
    display_s();
    break;

    case 6:
    system("cls");
    change();
    break;

    case 7:
    system("cls");
    borrow_return();
    break;

    case 8:
    system("cls");
    del();
    break;

    case 9:
    system("cls");
    password();
    break;

    case 10:
    system("cls");
    printf("*********************************END OF SESSION**********************************");
    break;
    }
}

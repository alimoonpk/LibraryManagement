//list of header files
#include <windows.h>
#include<stdio.h>                   //contains printf,scanf etc
#include<conio.h>                   //contains delay(),getch(),gotoxy(),etc.
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>


#define RETURNTIME 15

//list of function prototype
char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
//void show_mouse(void);
void Password();
void issuerecord();
void loaderanim();

COORD coord = {0, 0}; // sets coordinates to 0,0
//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut);
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs,*fsecret;

//list of global variable
int s;
char findbook;
char curpass[20];
char newpass[20];
char newpassagain[20];
char newpass2[20];


struct meroDate
{
    int mm,dd,yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};
struct books a;
int main()

{
      Password();
      getch();
   return 0;

}
void mainmenu()
{
    system("cls");
	int i;
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Issue Books");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. View Book list");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Edit Book's Record");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
	gotoxy(20,19);
	printf("\xDB\xDB\xDB\xDB\xB2 8. Change Password");
	gotoxy(20,21);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,22);
	t();
	gotoxy(20,23);
	printf("Enter your choice:");
	switch(getch())
	{
		case '1':
		addbooks();
		break;
	case '2':
		deletebooks();
		break;
		case '3':
		searchbooks();
	    break;
	case '4':
		issuebooks();
	    break;
	    case '5':
		viewbooks();
		break;
	    case '6':
		editbooks();
		break;
	    case '7':
	    {
		system("cls");
		gotoxy(16,3);
		printf("Programmers....");
		gotoxy(16,4);
		printf("1. Muhammad Ali     				 SE-40");
		gotoxy(16,5);
		printf("   Mobile:+923312320102  E-mail:alimoon.pk@gmail.com");
		gotoxy(16,7);
		printf("2. Hafiz M. Furqan Patel     	  		   SE-39");
		gotoxy(16,8);
		printf("   Mobile:+923069116264  E-mail:patel13furqan@gmail.com");
		gotoxy(16,10);
		printf("3. Asad Raza  				         SE-69");
		gotoxy(16,11);
		printf("   Mobile:+923061839747   E-mail:asadraza@gmail.com");
		gotoxy(16,13);
		printf("With  the Unexplainable Help of Mr.Waseemullah & Ms. Nazish");
		gotoxy(10,17);
		printf("Exiting in 10 second...........>");
		//flushall();
		delay(10000);
		exit(0);
	    }
	    default:
		{
		gotoxy(10,23);
		printf("\aWrong Entry!!Please re-entered correct option");
		if(getch())
		mainmenu();
		}
		case '8':
		{
		    system("cls");
		    fsecret=fopen("secret.dat","rb+");
            fread(&newpass,sizeof(newpass),1,fsecret);
		    gotoxy(5,5);
		    printf("Enter Current Password:");
		    gets(curpass);
		    gotoxy(5,7);
		    printf("Enter New Password: ");
		    gets(newpass2);
		    gotoxy(5,8);
		    printf("Enter New Password Again: ");
		    gets(newpassagain);

		    if((strcmp(curpass,newpass)!=0))
		    {gotoxy(5,12);
		    printf("Current Password is Incorrect !");
		    returnfunc();
		    }

		    if((strcmp(newpass2,newpassagain)!=0))
		    {gotoxy(5,12);
		    printf("Password does not match !");
		    returnfunc();
		    }

		    if((strcmp(curpass,newpass)==0) && (strcmp(newpass2,newpassagain)==0))
		    {
            fsecret=fopen("secret.dat","wb+");
            fwrite(&newpass2,sizeof(newpass2),1,fsecret);
            strcpy(newpass2,newpass);
            fclose(fsecret);
            gotoxy(5,12);
		    printf("Password is successfully changed !");
		    returnfunc();
		    }
		}

    }
}
void addbooks(void)    //funtion that add books
{
	system("cls");
	int i;
	gotoxy(20,5);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Civil");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Mechanical");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Architecture");
	gotoxy(20,19);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
	gotoxy(20,21);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,22);
	printf("Enter your choice:");
	scanf("%d",&s);
	if(s==7)

	mainmenu() ;
	system("cls");
	fp=fopen("booksdata.dat","ab+");
	if(getdata()==1)
	{
	a.cat=catagories[s-1];
	fseek(fp,0,SEEK_END);
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	gotoxy(21,14);
	printf("The record is sucessfully saved");
	gotoxy(21,15);
	printf("Save any more?(Y / N):");
	if(getch()=='n')
	    mainmenu();
	else
	    system("cls");
	    addbooks();
	}
}
void deletebooks()    //function that delete items from file fp
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
    	fp=fopen("booksdata.dat","rb+");
    	ft=fopen("test.dat","wb+");
    		
    	
	system("cls");
	gotoxy(10,5);
	printf("Enter the Book ID to  delete:");
	scanf("%d",&d);
	
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		
	    if(a.id==d)
	    {

		gotoxy(10,7);
		printf("The book record is available");
		gotoxy(10,8);
		printf("Book name is %s",a.name);
		gotoxy(10,9);
		printf("Rack No. is %d",a.rackno);
		findbook='t';
	    }
	}
	if(findbook!='t')
	{
	    gotoxy(10,10);
	    printf("No record is found modify the search");
	    if(getch())
	    mainmenu();
	}
	if(findbook=='t' )
	{
	    gotoxy(10,9);
	    printf("Do you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
	  //temporary file for delete
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
		    if(a.id!=d)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
		    }                              //we want to delete
		}
		fclose(ft);
		fclose(fp);
		fp=fopen("booksdata.dat","wb+");
    	ft=fopen("test.dat","rb+");
    	rewind(ft);
    	rewind(fp);
    	while(fread(&a,sizeof(a),1,ft)==1)
		      fwrite(&a,sizeof(a),1,fp);
		                    
		       fclose(fp);
		       fclose(ft);
    	
		fflush(stdin);

		fp=fopen("booksdata.dat","rb+");    //we want to delete
		if(findbook=='t')
		{
		    gotoxy(10,10);
		    printf("The record is sucessfully deleted");
		    gotoxy(10,11);
		    printf("Delete another record?(Y/N)");
	
		}
			remove("booksdata.dat");
	rename("test.dat","booksdata.dat");
	    }
	    
	else
	mainmenu();
	fflush(stdin);
	another=getch();
	}
	}
    gotoxy(10,15);
    mainmenu();
    
}
void searchbooks()
{
    system("cls");
    int d;
    printf("*****************************Search Books*********************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Search By ID");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB\xB2 2. Search By Name");
    gotoxy( 15,20);
    printf("Enter Your Choice");
    fp=fopen("booksdata.dat","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
	  case '1':
	{
	    system("cls");
	    gotoxy(25,4);
	    printf("****Search Books By Id****");
	    gotoxy(20,5);
	    printf("Enter the book id:");
	    scanf("%d",&d);
	    gotoxy(20,7);
	    printf("Searching........");
	    while(fread(&a,sizeof(a),1,fp)==1)
	    {
		if(a.id==d)
		{
		    delay(2);
		    gotoxy(20,7);
		    printf("The Book is available");
		    gotoxy(20,8);
		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    gotoxy(20,9);
		    printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
		    gotoxy(20,10);
		    printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
		    gotoxy(20,11);
		    printf("\xB2 Author:%s ",a.Author);gotoxy(47,11);printf("\xB2");
		    gotoxy(20,12);
		    printf("\xB2 Qantity:%d ",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
		    gotoxy(20,13);
		    printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
		    gotoxy(20,14);
		    printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
		    gotoxy(20,15);
		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    findbook='t';
		}

	    }
	    if(findbook!='t')  //checks whether conditiion enters inside loop or not
	    {
	    gotoxy(20,8);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	    gotoxy(20,10);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(22,9);printf("\aNo Record Found");
	    }
	    gotoxy(20,17);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchbooks();
	    else
	    mainmenu();
	    break;
	}
	case '2':
	{
	    char s[15];
	    system("cls");
	    gotoxy(25,4);
	    printf("****Search Books By Name****");
	    gotoxy(20,5);
	    printf("Enter Book Name:");
	    scanf("%s",s);
	    int d=0;
	    while(fread(&a,sizeof(a),1,fp)==1)
	    {
		if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
		{
		    gotoxy(20,7);
		    printf("The Book is available");
		    gotoxy(20,8);
		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    gotoxy(20,9);
		    printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
		    gotoxy(20,10);
		    printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
		    gotoxy(20,11);
		    printf("\xB2 Author:%s",a.Author);gotoxy(47,11);printf("\xB2");
		    gotoxy(20,12);
		    printf("\xB2 Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2");
		    gotoxy(20,13);
		    printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
		    gotoxy(20,14);
		    printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
		    gotoxy(20,15);
		    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		    d++;
		}

	    }
	    if(d==0)
	    {
	    gotoxy(20,8);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
	    gotoxy(20,10);
	    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	    gotoxy(22,9);printf("\aNo Record Found");
	    }
	    gotoxy(20,17);
	    printf("Try another search?(Y/N)");
	    if(getch()=='y')
	    searchbooks();
	    else
	    mainmenu();
	    break;
	}
	default :
	getch();
	searchbooks();
    }
    fclose(fp);
}
void issuebooks(void)  //function that issue books from library
{
    int t;

    system("cls");
    printf("********************************ISSUE SECTION**************************");
    gotoxy(10,5);
    printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book");
    gotoxy(10,7);
    printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book");
    gotoxy(10,9);
    printf("\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book");
    gotoxy(10,11);
    printf("\xDB\xDB\xDB\xDb\xB2 4. Remove Issued Book");
    gotoxy(10,14);
    printf("Enter a Choice:");
    switch(getch())
    {
	case '1':  //issue book
	{
		system("cls");
		int c=0;
		char another='y';
		while(another=='y')
		{
			system("cls");
			gotoxy(15,4);
			printf("***Issue Book section***");
			gotoxy(10,6);
			printf("Enter the Book Id:");
			scanf("%d",&t);
			fp=fopen("booksdata.dat","rb");
			fs=fopen("Issue.dat","ab+");
			if(checkid(t)==0) //issues those which are present in library
			{
			     gotoxy(10,8);
			     printf("The book record is available");
			     gotoxy(10,9);
			     printf("There are %d unissued books in library ",a.quantity);
			     gotoxy(10,10);
			     printf("The name of book is %s",a.name);
			     gotoxy(10,11);
			     fflush(stdin);
			     printf("Enter student name:");
			     gets(a.stname);

                SYSTEMTIME d;
                GetSystemTime(&d);

			    a.issued.dd=d.wDay;
			    a.issued.mm=d.wMonth;
			    a.issued.yy=d.wYear;

			     gotoxy(10,12);
			     printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
			     gotoxy(10,13);
			     printf("The BOOK of ID %d is issued",a.id);
			     a.duedate.dd=a.issued.dd+RETURNTIME;   //for return date
			     a.duedate.mm=a.issued.mm;
			     a.duedate.yy=a.issued.yy;
			     if(a.duedate.dd>30)
			     {
				 a.duedate.mm+=a.duedate.dd/30;
				 a.duedate.dd-=30;

			     }
			     if(a.duedate.mm>12)
			     {
				a.duedate.yy+=a.duedate.mm/12;
				a.duedate.mm-=12;

			     }
			     gotoxy(10,14);
			     printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
			     fseek(fs,sizeof(a),SEEK_END);
			     fwrite(&a,sizeof(a),1,fs);
			     fclose(fs);
			     c=1;
			}
			if(c==0)
			{
			gotoxy(10,11);
			printf("No record found");
			}
			gotoxy(10,15);
			printf("Issue any more(Y/N):");
			fflush(stdin);
			another=getche();
			fclose(fp);
		}

		break;
	}
	case '2':  //show issued book list
	{
		system("cls");
		int j=4;
		printf("*******************************Issued book list*******************************\n");
		gotoxy(2,2);
		printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
	       fs=fopen("Issue.dat","rb");
		while(fread(&a,sizeof(a),1,fs)==1)
		{

			gotoxy(2,j);
			printf("%s",a.stname);
			gotoxy(18,j);
			printf("%s",a.cat);
			gotoxy(30,j);
			printf("%d",a.id);
			gotoxy(36,j);
			printf("%s",a.name);
			gotoxy(51,j);
			printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy );
			gotoxy(65,j);
			printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
			//struct dosdate_t d;
			//_dos_getdate(&d);
			gotoxy(50,25);
//			printf("Current date=%d-%d-%d",d.day,d.month,d.year);
			j++;

		}
		fclose(fs);
		gotoxy(1,25);
		returnfunc();
	}
	break;
	case '3':   //search issued books by id
	{
		system("cls");
		gotoxy(10,6);
		printf("Enter Book ID:");
		int p,c=0;
		char another='y';
		while(another=='y')
		{

			scanf("%d",&p);
			fs=fopen("Issue.dat","rb");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				if(a.id==p)
				{
					issuerecord();
					gotoxy(10,12);
					printf("Press any key.......");
					getch();
					issuerecord();
					c=1;
				}

			}
			fflush(stdin);
			fclose(fs);
			if(c==0)
			{
				gotoxy(10,8);
				printf("No Record Found");
			}
			gotoxy(10,13);
			printf("Try Another Search?(Y/N)");
			another=getch();
		}
	}
	break;
	case '4':  //remove issued books from list
	{
		system("cls");
		int b;
		FILE *fg;  //declaration of temporary file for delete
		char another='y';
		while(another=='y')
		{
			gotoxy(10,5);
			printf("Enter book id to remove:");
			scanf("%d",&b);
			fs=fopen("Issue.dat","rb+");
			while(fread(&a,sizeof(a),1,fs)==1)
			{
				if(a.id==b)
				{
					issuerecord();
					findbook='t';
				}
				if(findbook=='t')
				{
					gotoxy(10,12);
					printf("Do You Want to Remove it?(Y/N)");
					if(getch()=='y')
					{
						fg=fopen("record.dat","wb+");
						rewind(fs);
						while(fread(&a,sizeof(a),1,fs)==1)
						{
							if(a.id!=b)
							{
							fseek(fs,0,SEEK_CUR);
							fwrite(&a,sizeof(a),1,fg);
							
							}
						}
						fclose(fs);
						fclose(fg);
						remove("Issue.dat");
						rename("record.dat","Issue.dat");
						gotoxy(10,14);
						printf("The issued book is removed from list");

				       }

				}
				if(findbook!='t')
				{
					gotoxy(10,15);
					printf("No Record Found");
				}
			}
			gotoxy(10,16);
			printf("Delete any more?(Y/N)");
			another=getch();
		}
	}
	default:
	gotoxy(10,18);
	printf("\aWrong Entry!!");
    getch();
	issuebooks();
	break;
      }
      gotoxy(1,30);
      returnfunc();
}
void viewbooks(void)  //show the list of book persists in library
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;
    fp=fopen("booksdata.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
	gotoxy(3,j);
	printf("%s",a.cat);
	gotoxy(16,j);
	printf("%d",a.id);
	gotoxy(22,j);
	printf("%s",a.name);
	gotoxy(36,j);
	printf("%s",a.Author);
	gotoxy(50,j);
	printf("%d",a.quantity);
	gotoxy(57,j);
	printf("%.2f",a.Price);
	gotoxy(69,j);
	printf("%d",a.rackno);
	printf("\n\n");
	j++;
	i=i+a.quantity;
      }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fp);
      gotoxy(35,25);
      returnfunc();
}
void editbooks(void)  //edit information about book
{
	system("cls");
	int c=0;
	int d,e;
	gotoxy(20,4);
	printf("****Edit Books Section****");
	char another='y';
	while(another=='y')
	{
		system("cls");
		gotoxy(15,6);
		printf("Enter Book Id to be edited:");
		scanf("%d",&d);
		fp=fopen("booksdata.dat","rb+");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(checkid(d)==0)
			{
				gotoxy(15,7);
				printf("The book is availble");
				gotoxy(15,8);
				printf("The Book ID:%d",a.id);
				gotoxy(15,9);
				printf("Enter new name:");scanf("%s",a.name);
				gotoxy(15,10);
				printf("Enter new Author:");scanf("%s",a.Author);
				gotoxy(15,11);
				printf("Enter new quantity:");scanf("%d",&a.quantity);
				gotoxy(15,12);
				printf("Enter new price:");scanf("%f",&a.Price);
				gotoxy(15,13);
				printf("Enter new rackno:");scanf("%d",&a.rackno);
				gotoxy(15,14);
				printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(a),0);
				fwrite(&a,sizeof(a),1,fp);
				fclose(fp);
				c=1;
			}
			if(c==0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	}
		returnfunc();
}
void returnfunc(void)
{
    {
	printf(" Press ENTER to return to main menu");
    }
    a:
    if(getch()==13) //allow only use of enter
    mainmenu();
    else
    goto a;
}
int getdata()
{
	int t;
	gotoxy(20,3);printf("Enter the Information Below");
	gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");gotoxy(46,5);printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");gotoxy(46,6);printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");gotoxy(46,7);printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");gotoxy(46,8);printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");gotoxy(46,9);printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");gotoxy(46,10);printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");gotoxy(46,11);printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(21,5);
	printf("Category:");
	gotoxy(31,5);
	printf("%s",catagories[s-1]);
	gotoxy(21,6);
	printf("Book ID:\t");
	gotoxy(30,6);
	scanf("%d",&t);
	if(checkid(t) == 0)
	{
		gotoxy(21,13);
		printf("\aThe book id already exists\a");
		getch();
		mainmenu();
		return 0;
	}
	a.id=t;
	fflush(stdin);
	gotoxy(21,7);
	printf("Book Name:");gotoxy(33,7);
    gets(a.name);
	gotoxy(21,8);
	printf("Author:");gotoxy(30,8);
	gets(a.Author);
	gotoxy(21,9);
	printf("Quantity:");gotoxy(31,9);
	scanf("%d",&a.quantity);
	gotoxy(21,10);
	printf("Price:");gotoxy(28,10);
	scanf("%f",&a.Price);
	gotoxy(21,11);
	printf("Rack No:");gotoxy(30,11);
	scanf("%d",&a.rackno);
	return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==t)
	return 0;  //returns 0 if book exits
      return 1; //return 1 if it not
}
int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}
//void show_mouse(void) //show inactive mouse pointer in programme
//{
//union REGS in,out;
//
//       in.x.ax = 0x1;
//       int86(0x33,&in,&out);
//}
void Password(void) //for password option
{
fsecret=fopen("secret.dat","rb+");
fread(&newpass,sizeof(newpass),1,fsecret);
   system("cls");
      char lib[50]=" Library Management System";
   char d[25]="Password Protected";
   char ch,pass[10];
   int i=0,j;
   //textbackground(WHITE);
   //textcolor(RED);
   gotoxy(5,2);
    for(j=0;j<20;j++)
    {
    delay(50);
    printf("\xDB");
    }
    for(j=0;j<30;j++)
   {
   delay(50);
   printf("%c",lib[j]);
   }
   for(j=0;j<20;j++)
   {
   delay(50);
   printf("\xDB");
   }


    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    delay(50);
    printf("\xB2");
    }
    for(j=0;j<20;j++)
   {
   delay(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
   delay(50);
   printf("\xB2");
   }

   gotoxy(15,9);
   printf("Enter Password:");

   while(ch!=13)
   {
	ch=getch();

	if(ch!=13 && ch!=8){
	printf("*");
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,newpass)==0)
   {

   char x[25]=" Password  Match";

   gotoxy(10,12);
	int k;
	for(k=0;k<20;k++)
    {
    delay(50);
    printf("\xDB");
    }
    for(k=0;k<20;k++)
   {
   delay(50);
   printf("%c",x[k]);
   }
   for(k=0;k<20;k++)
   {
   delay(50);
   printf("\xDB");
   }
	gotoxy(17,13);
	printf("\n\tPress any key to countinue.....");
	getch();
	mainmenu();
   }
   else
   {
	 gotoxy(35,16);
	 printf("ACCESS DENIED");
	 gotoxy(15,18);
	 printf("The Password You Entered is Incorrect.Please Try Again..");
	 getch();
	 Password();
   }
}
void issuerecord()  //display issued book's information
{
		 system("cls");
		 gotoxy(10,8);
		 printf("The Book has taken by Mr. %s",a.stname);
		 gotoxy(10,9);
		 printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
		 gotoxy(10,10);
		 printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}
void loaderanim()
{
int loader;
system("cls");
gotoxy(20,10);
printf("LOADING........");
printf("\n\n");
gotoxy(22,11);
for(loader=1;loader<20;loader++)
{
delay(100);printf("%c",219);}
}
//End of program

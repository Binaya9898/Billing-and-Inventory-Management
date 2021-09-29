//Including Header files
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ANS 15
#define ACS 4

typedef struct
{
    char name[ANS],code[ACS];
    float rate;
    int quantity;
} rec;
rec item;

//Declaring structre variables for staff management
struct staff
{
	int id;
	char password[10];
	char name[40];
	char username[20];
	int salary;
	char address[40];
};
struct staff s;

struct charges
{
	int vat;
	int discount;
};
struct charges e;



//Declaring Functions
void loginChecker();
void option1();
void option2();
void staffmgmt();
void display_record();
void insert_record();
void search_record();
void del_record();
void update_record();

void inventory();
void edit();
void add();
void del();
void exit();
void all();
void search();
void c_code(char[]);
int check(char[]);

void tot();
void display_bill();
void header();
void charges();
void dischr();

void display();

COORD coord = { 0, 0 };

void gotoxy(int x, int y)
{
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i, j, k, flag, sales = 0, temp = 0;

int main()
{
	int i, j, k, flag;
	header();
	puts("\n \n");
	loginChecker();

}

//Defining Function
void loginChecker()
{
	char name[20], ch, password[15], i = 0;
	int t, h, k;
	puts("\n \t \t\tPlease Proceed To Log In");
	puts("\n Enter user ID:");
	scanf("%s", &name);

	puts("\n");
	puts("Enter password:");

	while (ch != 13)
	{
		ch = getch();
		if (ch != 13 && ch != 8)
		{
			putch('*');
			password[i] = ch;
			i++;
		}
	}

	password[i] = '\0';

	//Comparing password
	if (strcmp(password, "pass") == 0 && strcmp(name, "asd") == 0)
	{
		system("cls");

		puts("\n \n");
		option1();

	}

	//Opening text file for reading and comparing staff details

	FILE * fp;
	fp = fopen("staff.txt", "rb");
	if (fp == NULL)
	{
		//	printf("\n\t\tError: Cannot Open the File!!!");
		return;
	}

	while (fread(&s, sizeof(s), 1, fp) > 0)
	{
		//comparing username and password entered by user and existed details in file
		h = (strcmp(s.password, password));
		k = (strcmp(s.username, name));
		if (h == 0 && k == 0)
		{
			system("cls");
			display_bill();
		}
	}

	system("cls");

	puts("\n \nIncorrect Password, **");
	puts("\n Press 1 to try again: \n\n Press 2 to terminate:");
	scanf("%d", &t);
	if (t == 1)
	{
		system("cls");

		loginChecker();

	}
}

void option1()
{
	int optadmin, d;
	printf("\n\t\t============================WELCOME TO ADMIN PANNEL========================== \n\n");
	puts("\nPress 1 for User Mangement\n");
	puts("Press 2 for Inventory Management\n");
	puts("Press 3 to log out\n");
	puts("Press 4 to exit\n");
	puts("Enter your choice:");
	scanf("%d", &d);
	switch (d)
	{
		case 1:
			system("cls");
			staffmgmt();
			break;

		case 2:
			system("cls");
			inventory();
			break;

		case 3:
			system("cls");
			loginChecker();
			break;

		case 4:
			exit(0);
			break;

		default:
			printf("\n\t\tWrong choice Entered");
			getch();

	}
}

void staffmgmt()
{
	int ch;

	printf("\n\t=====================================================\n");
	printf("\n\t\tWELCOME TO STAFF MANAGEMENT \n");
	printf("\n\t======================================================\n");
	printf("\n\t\tAVAILABLE FUNCTIONALITIES \n");
	printf("\t\t1: Insert Staff record		:\n");
	printf("\t\t2: Display staff record		:\n");
	printf("\t\t3: Search staff record		:\n");
	printf("\t\t4: Delete staff record		:\n");
	printf("\t\t5: Update staff record		:\n");
	printf("\t\t6: Log Out			:\n");
	printf("\t\t7:Exit				:\n\n");

	printf("\t\tEnter your choice 			:");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1:
			system("cls");
			insert_record();
			break;
		case 2:
			system("cls");
			display_record();
			break;

		case 3:
			search_record();
			break;
		case 4:
			del_record();
			break;
		case 5:
			update_record();
			break;
		case 6:
			system("cls");
			loginChecker();
			break;

		case 7:
			exit(0);
		default:
			printf("\n\t\tWrong choice Entered ?? ) \n");
			getch();
			return;
	}
}

void display_record()
{
	int a, ch;
	FILE * fp;
	fp = fopen("staff.txt", "rb");

	if (fp == NULL)
	{
		printf("\n\t\tError : Cannot open the File !!!");
		return;
	}

	gotoxy(3, 3);
	printf("\t\t\t\t\t\t\b\b\b");
	printf("\t\t\t\t S T A F F  D E T A I L S\n");
	gotoxy(5,4)	;
	puts("\n=========================================================================================================================");

	gotoxy(5,5);
	 puts("\n\n\nID\t\t\t Name of Staff\t\t Adress\t\t\t Username\t\t Password\tSalary");
	 
	puts("\n=========================================================================================================================");
	//printf("\n \t ID \t \t \t STAFF NAME\t\t ADDRESS \t\t USERNAME\t\t PASSWORD\t SALARY \n\n\n");
	//Reading Staff Details From File and Displaying the result
	while (fread(&s, sizeof(s), 1, fp) > 0)
	{
	   //	printf(" \t %-10d \t\t %-12s \t\t %-12s \t\t %-12s\t\t %-12s \t %d \n\n  ", s.id, s.name, s.address, s.username, s.password, s.salary);
	    printf("\n\n%-10d\t\t %-12s\t\t %-12s\t\t %-12s\t\t %-12s\t %d  ",s.id,s.name,s.address,s.username,s.password,s.salary);
	}
	puts("\n ========================================================================================================================= \n");
	fclose(fp);
	puts("\n\nPress 1  for main menu");
	scanf("%d", &a);
	if (a == 1)
	{
		system("cls");
		staffmgmt();
	}
	else
		exit(1);

}

void insert_record()
{
	char pas[20];
	int a;
	FILE * fp;

	fp = fopen("staff.txt", "ab+");

	if (fp == NULL)
	{
		printf("\n\t\tError: Cannot Open the File!!!");
		return;
	}

	// Asking Data to insert in file
	printf("\n\n\t================ENTER NEW STAFF DATA=====================\n\n");
	printf("\n\t\tEnter Staff ID		: ");
	scanf("%d", &s.id);
	fflush(stdin);
	printf("\n\t\tEnter Staff Name		: ");
	gets(s.name);
	printf("\n\t\tEnter Staff Address	: ");
	gets(s.address);
	printf("\n\t\tEnter Staff User name	: ");
	gets(s.username);
	printf("\n\t\tEnter Password		: ");
	gets(s.password);
	printf("\n\t\tEnter Staff Salary	: ");
	scanf("%d", &s.salary);
	fwrite(&s, sizeof(s), 1, fp);	// Writing data in file

	printf("\n\n\t !!! Staff Record Inserted Sucessfully\n");

	fclose(fp);

	puts("\n\n\tPress 1  for Adding more Staffs");
	puts("\n\n\tPress 2  for main menu");
	scanf("%d", &a);
	if (a == 1)
	{
		system("cls");
		insert_record();
	}
	else if (a == 2)
	{
		system("cls");
		staffmgmt();
	}
	else
		exit(1);
}

void search_record()
{
	int idd, flag = 0, a;
	FILE * fp;
	fp = fopen("staff.txt", "rb");
	if (fp == NULL)
	{
		printf("\n\t\tError: Cannot Open the File!!!");
		return;
	}

	printf("\n\n\t\tEnter Staff ID  Which You Want To Search		: ");
	scanf("%d", &idd);
	while (fread(&s, sizeof(s), 1, fp) > 0)
	{
		//Comparing enrtered staff ID and Existed staff ID to display searched data.
		if (s.id == idd)
		{
			flag = 1;
			printf("\n\n\tSearch Sucessfull And Staff Records are as Follows	:\n\n");
			printf("\nID\t\t NAME OF STAFF\t\t ADDRESS\t\t USERNAME\t\t PASSWORD\t\t SALARY\n\n");
			printf("%d\t\t %s\t\t %s\t\t %s\t\t %s\t\t %d  ", s.id, s.name, s.address, s.username, s.password, s.salary);

		}
	}

	if (flag == 0)
	{
		printf("\n\n\t\tNo Such Record Found !!!!!\n");
	}

	fclose(fp);
	puts("\n\nPress 1  for  More Search");
	puts("\n\nPress 2  for main menu");
	scanf("%d", &a);
	if (a == 1)
	{
		system("cls");
		search_record();
	}
	else if (a == 2)
	{
		system("cls");
		staffmgmt();
	}
	else
		exit(1);

}

void del_record()
{
	int idd, flag = 0, a;
	FILE *fp, *ft;
	fp = fopen("staff.txt", "rb");
	ft = fopen("staff1.txt", "ab+");
	if (fp == NULL)
	{
		printf("\n\t\tError: Cannot Open the File!!!");
		return;
	}

	printf("\n\n\tEnter *STAFF ID* Which You Want to Delete 		:");
	scanf("%d", &idd);
	while (fread(&s, sizeof(s), 1, fp) > 0)
	{
		if (s.id == idd)
		{
			printf("\n\t\tRecord Deleted Sucessfully \n");
			flag = 1;

		}
		else
		{
			fwrite(&s, sizeof(s), 1, ft);
		}
	}

	if (flag == 0)
	{
		printf("\n\n\t\tNo Such Record Found !!!");
	}

	fclose(fp);
	fclose(ft);
	remove("staff.txt");
	rename("staff1.txt", "staff.txt");

	puts("\n\nPress 1  to see updated record");
	puts("\n\nPress 2  to delete more records");
	puts("\n\nPress 3  for Main menu");

	scanf("%d", &a);
	if (a == 1)
	{
		system("cls");
		puts("Updated Record");
		display_record();

	}
	else if (a == 2)
	{
		system("cls");
		del_record();

	}
	else if (a == 2)
	{
		system("cls");
		staffmgmt();

	}
	else
		exit(1);
}

void update_record()
{
	system("cls");
	int idd, flag = 0, a;
	FILE * fp;
	int recsize = sizeof(s);
	fp = fopen("staff.txt", "rb+");
	if (fp == NULL)
	{
		printf("\n\t\tError: Cannot Open the File!!!");
		return;
	}

	printf("\n\n\tEnter ID of Staff Whose Record You Want To Update		: ");
	scanf("%d", &idd);

	rewind(fp);
	while (fread(&s, recsize, 1, fp) > 0 && flag == 0)
	{
		if (s.id == idd)
		{
			flag = 1;
			// printf("\nID\tName of Staff\tAdress\t\t Username\t\tPassword\t\tSalary\n\n");
			// printf("%d\t%s\t\t%s  \t\t%s\t\t%s\t\t%s\t\t%d\n",s.id,s.name,s.address,s.username,s.password,s.salary);
			printf("\n\t\t==============	Now Enter the New Record	=================\n\n");

			printf("\n\t\tUpdated Staff ID			:");
			scanf("%d", &s.id);
			fflush(stdin);
			printf("\n\t\tUpdated Staff NAME		:");
			gets(s.name);
			printf("\n\t\tUpdated Staff ADDRESS		:");
			gets(s.address);
			printf("\n\t\tUpdated Staff USERNAME	:");
			gets(s.username);
			printf("\n\t\tUpdated Staff PASSWORD	:");
			gets(s.password);
			printf("\n\t\tUpdated Staff SALARY	:");
			scanf("%d", &s.salary);
			//fseek(fp, -(long)sizeof(s), SEEK_CUR);
			//fwrite(&s, sizeof(s), 1, fp);
			 fseek(fp,-(long)sizeof(s),1);
         	 fwrite(&s,(long)sizeof(s),1,fp);
			printf("\n\n\t\tWoohoo!! Record Updated Successfully !!!!!!!!!!!!\n\t\t");
		}
	}

	if (flag == 0)
	{
		printf("\n\t\tError : Something went wrong!!!");
	}

	fclose(fp);

	puts("\n\nPress 1  to see updated record");
	puts("\n\nPress 2  to update more records");
	puts("\n\nPress 3  for Main menu");

	scanf("%d", &a);
	if (a == 1)
	{
		system("cls");
		puts("Updated Record");
		display_record();

	}
	else if (a == 2)
	{
		system("cls");
		update_record();

	}
	else if (a == 2)
	{
		system("cls");
		staffmgmt();

	}
}

void inventory(){
	
    int i;
    int choice;
    const char *menu[]= {"[1]Add Goods","[2]Display All","[3]Edit Goods  ",
	"[4]Search Goods", "[5]Delete Goods","[6]Bill","[6]Exit"};
	
    system("cls");
    printf("\t\tMAIN MENU\n\n");
    for (i=0; i<=5; i++)
    {
        printf("\n\t\t%s\n",menu[i]);
    }
    printf("Enter a choice");
    scanf("%d",&choice);
    if(choice>6 && choice<1 ){
    	printf("Invalid Choice\n\n Try Again!!");
    	sleep(500);
    	inventory();
    }
    
    else{
    	switch(choice){
    		case 1:
    			system("cls");
    		    add();
    		     break;
    		     
    		case 2:
    			system("cls");
    			all();
    			break;
    			
    		case 3:
    		system("cls");
    		edit();
    		break;
    		 
    		 case 4:
    		    system("cls");
    		    search();
    		    break;
    		    
    		case 5:
    			system("cls");
    		    del();
    		    break;
    		    
    		     case 6:
    			system("cls");
    		    display_bill();
    		    break;
    		    
    		    case 7:
    			system("cls");
    		    exit(1);
    		    break;
		}
	}
    	
    	
	}
	
	void add ()
{
    FILE *file;
    char y[ACS],x[12];
    int chh;
    system("cls");

    printf("\nEnter New Record(Y/N)?");
    while(toupper(getche())=='Y')
    {
        system("cls");
        file=fopen("record.txt","ab");
        c_code(y); // Item code asking and check avaiability of the code function:
        strcpy(item.code,y);
        
        printf("\nEnter Rate Of The Item:");
        scanf("%f",&item.rate);
       
        printf("\nEnter Quantity Of The Item:");
        scanf("%d",&item.quantity);
       
        printf("\nEnter Name Of The Item:");
        scanf("%s",item.name);
        fseek(file,0,SEEK_END);
        fwrite(&item,sizeof(item),1,file);
        fclose(file);
     
        printf("\nEnter New Record(Y/N)?");

    }
    display();
    sleep(3);
    printf("\n\nPress 1 for main menu:");
    scanf("%d",&chh);
    if(chh==1){
    	inventory();
	}
	else
	printf("\n\n \t\t\t\t Terminating Program:");
	sleep(4);
	exit(1);
   
    return;
    
}


//function to check availability of code*/
void c_code(char y[])
{
    int flag;
    FILE *file;
    file=fopen("record.txt","rb");
    while(1)
    {
        system("cls");
       
        printf(" ADD ARTICLES ")  ;
        flag=1;
        rewind(file);
        
        printf("Enter New Code Of The Article:");
        scanf(" %[^\n]",y);
        while(fread(&item,sizeof(item),1,file)==1)
        {
            if (strcmp(y,item.code)==0)
            {
                flag=0;
                
                printf("Code Already Exists");
                
                printf("\n\nEnter Again");
                getch();
                break;
            }
        }
        if (flag==1)
            break;
    }
}
	
	/*function for editing*/
void edit()
{
    int flag=0,chh,choice,found;
    char x[ACS],y[ACS];
    FILE *file;
    FILE *ftt;
    int size;
    system("cls");
    printf("EDIT RECORDS");
    
    file=fopen("record.txt","rb");
    ftt=fopen("temmp.txt","wb");
    
    printf("\n\nEnter Item Code: ");
    scanf("%s",x);
    
    while (fread(&item,sizeof (item),1,file))
    {
        if(strcmp(item.code,x)==0)
        {
            flag=1;
            fflush(stdin);
             
        c_code(y); // Item code asking and check avaiability of the code function:
        strcpy(item.code,y);
        
        printf("\nEnter New Rate Of The Item:");
        scanf("%f",&item.rate);
       
        printf("\nEnter New Quantity Of The Item:");
        scanf("%d",&item.quantity);
       
        printf("\nEnter New Name Of The Item:");
        scanf("%s",item.name);
    }
        fwrite(&item,sizeof(item),1,ftt);
}
    
    fclose(file);
    fclose(ftt);

if(flag==1){
	 file=fopen("record.txt","wb");
    ftt=fopen("temmp.txt","rb");
    while (fread(&item,sizeof (item),1,ftt)){
    	fwrite(&item,sizeof(item),1,file);
	}
	
    fclose(file);
    fclose(ftt);
}
else{
	puts("Record Not Found");
}
sleep(1);
   printf("\n \nPress");
   sleep(1);
   printf(" 1 to");
   sleep(1);
    printf(" edit more products:"); 
    sleep(1);
   printf("\n\nPress 2 for");
   sleep(1);
   printf(" main menu:");
   scanf("%d",&chh);
   if(chh==1){
   	edit();
   	
   }
   
   else if(chh==2){
   	inventory();
   }
   else
   printf("\n\n\t\t\t\t\tIncorrect Option Entered!! Terminating the Program");
   sleep(5);
   exit(0);
   
    
   
}



/*function to display all records*/
void all()
{
	system("cls");
    int i,j=1,m=4,n=8;
    FILE *file;
    
    file=fopen("record.txt","rb");
    rewind(file);
    i=1;
    fflush(file);
    gotoxy(60,2);
    printf("A V A I L A B L E   P R O D U C T S");
    gotoxy(4,3);
    	printf("|_______________________________________________________________________________________________________|\n");
    	gotoxy(4,5);
     printf ("\tSN.\t\tItem Name\t\tItem Code\t\tRate \t\tQuantity");
     gotoxy(4,6);
     printf("|_______________________________________________________________________________________________________|\n");
     
    
	
	while (fread(&item,sizeof(item),1,file)==1)
    {
    	//gotoxy(m,n);
       printf(" \n\t%d\t\t  %-12s\t\t %-12s\t %10.2f \t %12d\n ",i,item.name,item.code,item.rate,item.quantity);
       i=i+1;
       n=n+1;
        }
    
    getch();
    fclose(file);
    inventory();
}
/*
function to display in screen
void display(rec *item,int i,int j)
{
    
    printf("%4d",j);
    printf("%9s",item->name);
    printf("%12s",item->code);
    printf("%14.2f",item->rate);
    printf("%11d",item->quantity);
}
*/
void display(){
	

	system("cls");
    int i,j=1,m=4,n=8;
    FILE *file;
    
    file=fopen("record.txt","rb");
    rewind(file);
    i=1;
    fflush(file);
    gotoxy(60,2);
    printf("A V A I L A B L E   P R O D U C T S");
    gotoxy(4,3);
    	printf("|_______________________________________________________________________________________________________|\n");
    	gotoxy(4,5);
     printf ("\tSN.\t\tItem Name\t\tItem Code\t\tRate \t\tQuantity");
     gotoxy(4,6);
     printf("|_______________________________________________________________________________________________________|\n");
     
    
	
	while (fread(&item,sizeof(item),1,file)==1)
    {
    	//gotoxy(m,n);
       printf(" \n\t%d\t\t  %-12s\t\t %-12s\t %10.2f \t %12d\n ",i,item.name,item.code,item.rate,item.quantity);
       i=i+1;
       n=n+1;
        }
    
    
    fclose(file);

}



void search()
{
    int i,j=1,chh;
    char x[4]= {0};
    FILE *file;
    file=fopen("record.txt","rb");
    rewind(file);
    i=2;
    
    printf("\n\nEnter Item Code: ");
    scanf("%s",x);
    system("cls");
    
    fflush(file);
    while(fread(&item,sizeof(item),1,file))
    {
        if((strcmp(item.code,x)==0))
        {/*
            display(&item,i,j);
            i++;
            j++;
            break;*/
            i=1;
            gotoxy(60,2);
    printf("S E A R C H E D   P R O D U C T ");
    gotoxy(4,3);
    	printf("_______________________________________________________________________________________________________\n");
    	gotoxy(4,5);
     printf ("\tSN.\t\tItem Name\t\tItem Code\t\tRate \t\tQuantity");
     gotoxy(4,6);
     printf("_______________________________________________________________________________________________________\n");
      printf(" \n\t%d\t\t  %-12s\t\t %-12s\t %10.2f \t %12d\n ",i,item.name,item.code,item.rate,item.quantity);
     
        }
    }
    if (i==2)
    {
        system("cls");
        printf("No Item Found");
    }
    sleep(1);
   printf("\n \nPress");
   sleep(1);
   printf(" 1 to");
   sleep(1);
    printf(" search more products:"); 
    sleep(1);
   printf("\n\nPress 2 for");
   sleep(1);
   printf(" main menu:");
   scanf("%d",&chh);
   if(chh==1){
   	search();
   	
   }
   
   else if(chh==2){
   	inventory();
   }
   else
   getch();
   return;
    
    fclose(file);
    search();
}

/*function to delete records*/
void del()
{
	int flag=0,choice,found,chh;
    char x[ACS],y[ACS];
    FILE *file;
    FILE *ftt;
    int size;
    system("cls");
    gotoxy(60,2);
    printf("D E L E T E   R E C O R D S");
    
    file=fopen("record.txt","rb");
    ftt=fopen("temmp.txt","wb");
    
    printf("\n\nEnter Item Code: ");
    scanf("%s",x);
    
    while (fread(&item,sizeof (item),1,file))
    {
        if(strcmp(item.code,x)==0)
        {
            flag=1;
            
    }
    else
        fwrite(&item,sizeof(item),1,ftt);
}
    
    fclose(file);
    fclose(ftt);

if(flag==1){
	 file=fopen("record.txt","wb");
    ftt=fopen("temmp.txt","rb");
    while (fread(&item,sizeof (item),1,ftt)){
    	fwrite(&item,sizeof(item),1,file);
	}
	
    fclose(file);
    fclose(ftt);
    sleep(1);
    printf("Sucessfully");
    sleep(1);
    printf("Deleted");
    sleep(2);
    display();
    
} 
else{
	puts("Record Not Found");
}

    sleep(1);
   printf("\n \nPress");
   sleep(1);
   printf(" 1 to");
   sleep(1);
    printf(" delete more products:"); 
    sleep(1);
   printf("\n\nPress 2 for");
   sleep(1);
   printf(" main menu:");
   scanf("%d",&chh);
   if(chh==1){
   	del();
   	
   }
   
   else if(chh==2){
   	inventory();
   }
   else
   getch();
   return;
}


/*function to check validity of code while editing and deleting*/
int check(char x[ANS])
{
    FILE *file;
    int flag=1;
    file=fopen("record.txt","rb");
    rewind(file);
    while (fread(&item,sizeof (item),1,file))
    {
        if(strcmp(item.code,x)==0)
        {
            flag=0;
            break;
        }
    }
    fclose(file);
    return flag;
}
/*
void c_item(char y[])
{
    int flag;
    FILE *file;
    file=fopen("record.txt","rb");
    while(1)
    {
        system("cls");
       
        //printf(" ADD ARTICLES ")  ;
        flag=1;
        rewind(file);
        
        cd[i]=y;
        while(fread(&item,sizeof(item),1,file)==1)
        {
            if (strcmp(y,item.code)==0)
            {
                flag=0;
                
                printf("Code Already Exists");
                
                printf("\n\nEnter Again");
                getch();
                break;
            }
        }
        if (flag==1)
            break;
    }
}
*/



void display_bill(){
	FILE *file;
	int i, flag, m, l;
	float vat, discount, temp;

	system("cls");
	printf("===================Welcome to Staff Pannel======================\n");
	//Declaring local Variables
	int op,pr[10], qt[10],total[50];
	char cd[4][5],prid[4][5],prname[20][20];
	file = fopen("record.txt", "rb");
	if (file == NULL)
	{
		printf("\nfile not found  !!!!!!\n");
		printf("\nPress any key to main menu		:");
		getch();
		return;
	}

	//Asking for number of products
	printf("\n\nHow many Products		:");
	scanf("\t%d", &op);
	for (i = 1; i <= op; i++)
	{
		printf("\n\n\n\t\t\tEnter code		:");
		scanf("%s", &cd[i]);
		printf("\n\t\tEnter quantity		:\t");
		scanf("%d", &qt[i]);
	}

	printf("\n\t\t\t");
	flag = 0;
	while (fread(&item,sizeof (item),1,file)){
			for (i = 1; i <= op; i++)
		{
			//Comparing entered product code and existing product codes in the file
			if (strcmp(cd[i],item.code)==0)
			{
				//Assigning in array variable
				pr[i] = item.rate;
				strcpy(prid[i], item.code);
				strcpy(prname[i], item.name);
			}

			flag = 1;
				}
	}

	system("cls");
	for (i = 1; i <= op; i++)
	{
		if (flag == 0)
			printf("\nNot Found!!\n");

		else
		{
			//Generating bills
			time_t t;
			time(&t);
			printf("\n\t\t\t\t\t\t\t\t\t\t%s", ctime(&t));
			printf("\n\t\t\t\t\t\tStore Desceiption");
			printf("\nBill No: %d\n", rand());
	

			gotoxy(4, 6);
			printf("_______________________________________________________________________________________________________\n");

			gotoxy(5, 7);
			printf("SN\t  Product ID\t\t Product Name\t\t Quantity\t Unit Price\tLine Total\n");	//TABLE TITLES !

			gotoxy(4, 8);
			printf("_______________________________________________________________________________________________________\n");

			for (i = 1; i <= op; i++)
			{
					total[i] = pr[i] *qt[i];
				temp = temp + total[i];

				printf("    %d\t  %-12s\t\t %-12s\t\t %8d \t %8d \t %8d \n\n", i, prid[i], prname[i], qt[i], pr[i], total[i]);
			}

			vat = 0.13 * temp;
			discount = 0.1 * temp;
			printf("\n\t\t\t\t\t\t\t\t\tSubtotal \t%8.2f", temp);
			printf("\n\t\t\t\t\t\t\t\t\tVAT\t \t%8.2f", vat);
			printf("\n\t\t\t\t\t\t\t\t\tDISCOUNTT \t%8.2f", discount);
			printf("\n\t\t\t\t\t\t\t\t\tGrand Total \t%8.2f", temp + (0.03 *temp));

			sales = sales + (temp + (0.03 *temp));

		}
	}
	

	fclose(file);

	puts("\n\n\t\tPress 1 and 2 to generate more bills and display total sales respectively  	:");
	scanf("%d", &m);
	if (m == 1)
	{
		display_bill();
	}
	else
	getch();
}

void header()
{
	printf("\n\n\n\t\t==================================\tEasyBill\t==================================="); //heading first
	printf("\n\t\t\t\t Billing and Inventory Management Mini Project");
	printf("\n\t\t\t\t\t LA GRANDEE INTERNATIONAL COLLEGE");
	printf("\n\t\t\t\t\t\tPOKHARA UNIVERSITY");
	time_t t;
	time(&t);
	printf("\n%s\n\n", ctime(&t));

}

void tot()
{
	printf("\n\n Total sales is		 : %d", sales);
}

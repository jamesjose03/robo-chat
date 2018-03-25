#include<stdio.h> //For input and output operations using gets() and printf(), scanf()
#include<conio.h> //For getch() - Receiving input from user
#include<stdlib.h>
#include<string.h> // For string manipulations
#include<windows.h> // For clearing the screen using system(cls) command
#define PROGRESS_BAR_SIZE 40 // For loading bar
#include<time.h> // For fetching the current system time

#define TRUE    1
#define FALSE   0

time_t t; // Variable of time
int c1=1;



char facts[][100]={"Banging your head against a wall burns 150 calories  an hour!","When Hippos are upset, their sweat turns red!","A flock of crows is known as a murder!","Cherophobia is the fear of fun!","King Henry VIII slept with a gigantic axe beside him.","An eagle can kill a young deer and fly away with it!","There is a species of Spider called the Hobo Spider.","A Lion's roar can be heard from 5 miles away!","Facebook, Twitter and Skype are all banned in China!","If you lift a kangaroo's tail, it can't hop!" };
//Random facts are stored in an array
const size_t facts_count = sizeof(facts)/sizeof(facts[0]); //Randomizing calculations
void print_n_chars(int n, int c)
{
    while(n-->0)
        putchar(c); //For loading bar
}

void display_progress_bar(int p) //For loading bar
{
    putchar('\r');
    putchar('[');
    print_n_chars(PROGRESS_BAR_SIZE * p/100,'#');
    print_n_chars(PROGRESS_BAR_SIZE - PROGRESS_BAR_SIZE *p/100, ' ');
    putchar(']');

}



int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //No of days in months are stored in an array
char *months[]= // Printing months
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};


int inputyear(void) //For inputting the year
{
	int year;

	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	return year; //Year is passed to determineleapyear()
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year) //After calculations, year is passed determinedaycode
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

void calendar(int year, int daycode)
{
	int month, day,count=0;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );

		// Correct the position for the first date
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}

		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );

			// Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;

	}

}







int commands(char command[])
{
    //FILE *fp;
    char title[50];
    char response[100];
    char date[20];
    char time1[10];
    char ch;
    char r ='Y';
    while(r=='Y')
    {


if(strcmpi(command,"help")==0 || strcmpi(command,"h")==0)
{
    printf("\n HELP");
    printf("\n Standard Commands");
    printf("\n\tCOMMAND \t ACTION");
    printf("\n\tCalendar - Show Calendar");
    printf("\n\trset \t- Set Reminder");
    printf("\n\trdel \t- Delete Reminder");
    printf("\n\ttime \t- Show time");
    printf("\n\troll \t- Roll a die");
    printf("\n\tnotes \t- Take notes");
    printf("\nEnter any key to continue");
    getch();
    return 0;
}

if(strcmpi(command,"How are you?")==0 || strcmpi(command,"Whats up?")==0 || strcmpi(command,"How's everything?")==0)
{
    printf("I am doing well. What about you? ");
    gets(response);
    if(strcmpi(response,"Fine")==0 || strcmpi(response,"I am fine")==0 || strcmpi(response,"I am doing well")==0)
    {
        printf("\n That's great!");
        break;
    }
    else if(strcmpi(response,"Not well")==0)
        printf("\n Sorry to hear about that. Hope you feel better");
        break;
}

if(strcmpi(command,"fact")==0 || strcmpi(command,"tell me a fact")==0 || strcmpi(command,"show fact")==0)
{
    printf("%s \n",facts[rand() % facts_count]);
    break;
}
if(strcmpi(command,"time")==0 || strcmpi(command,"show me the time")==0 || strcmpi(command,"What time is it?")==0|| strcmpi(command,"3")==0)
    {
        time(&t);
        printf("Today's current date and time: %s",ctime(&t));
        break;
    }

if(strcmpi(command,"rset")==0 || strcmpi(command,"set a reminder")==0 || strcmpi(command,"2")==0)
{
    FILE *fp = fopen("reminders.txt","a");
    printf("\n What do you want to be reminded of ? \n Title: ");
    gets(title);
    printf("\n Date: ");
    gets(date);
    printf("\n Time: ");
    gets(time1);
    //printf("Confirm? Y/N: ");
    //scanf("%c",ch);
    //if(ch=='Y'|| ch=='y')
    //{
        fputs(title,fp);
        fputs(" ",fp);
        fputs(time1,fp);
        fputs(" ",fp);
        fputs(date,fp);
        fputs("\n",fp);
        fclose(fp);
        printf("\n Successfully created reminder!");
       // c1++;
        break;

    //}


    }
if(strcmpi(command,"Show reminders")==0 || strcmpi(command,"rshow")==0 ||strcmpi(command,"reminders")==0 || strcmpi(command,"show my reminders")==0)
{
    int i;
    c1= 1;
    char c;
    char buffer[100];
FILE *fp = fopen("reminders.txt","r");
printf("\n              Title  Time   Date");

while((c=getc(fp)) != EOF)
{

        printf("\n Reminder %d : %c%s",c1,c,fgets(buffer,50,fp));
        c1++;

}
fclose(fp);
break;
}

if(strcmpi(command,"Calendar")==0 || strcmpi(command,"Show calendar") == 0 || strcmpi(command,"1")==0)
{
    int year, daycode, leapyear,count=0;
    year = inputyear();
    daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n");
	break;


}

if(strcmpi(command,"Remove reminder")==0 || strcmpi(command,"rdel")==0 || strcmpi(command,"Delete reminders")==0)
{
    FILE *fp = fopen("reminders.txt","r");
    FILE *f2 = fopen("temp.txt", "w");
    int pos_remove, ctr = 0,f=1;
    char str[100],ch;
    printf("\n Enter reminder number to remove: ");
    scanf("%d",&pos_remove);

    while(!feof(fp))
    {
        strcpy(str,"\0");
        fgets(str,100,fp);
        if(!feof(fp))
        {
            ctr++;
            if(ctr!= pos_remove)
                fprintf(f2,"%s",str);
        }
    }
    fclose(fp);
    fclose(f2);
    remove("reminders.txt");
    rename("temp.txt","reminders.txt");
    fp = fopen("reminders.txt","r");
    ch = fgetc(fp);
    while(ch!=EOF)
    {
        printf("%c",ch);
        ch = fgetc(fp);
        f++;
    }
    fclose(fp);
    break;


}
if(strcmpi(command,"To do list")== 0 || strcmpi(command,"Show me what to do today") == 0 || strcmpi(command,"Set tasks") == 0 || strcmpi(command, "Show me to-do list") == 0)
{
    system("cls");
    char c,ch,a;
    char task[100],temp_task[100], checked[2]="N",task_reader[50];
    int size,choice;
    int pos_remove, ctr = 0,f=1,c1=1,n=1;
    char status[2]="Y";
    char str[100],user_confirm,buffer[100];
    FILE *fp, *f2;
    time_t raw_time;
    struct tm *ptr_ts;
    time ( &raw_time );
    ptr_ts = localtime( &raw_time );
    //fp=fopen("tasks.txt","r");
    time(&t);
    printf("\n******************************************************************************************************************");
    printf("\n           ############  ##########      ########## ########   ##    ## ###### #######      ");
    printf("\n                ###      ##      ##      ##      ## ##    ##   ##    ## #        ##         ");
    printf("\n                ###      ##      ##      ##      ## ##    ##   ##    ## ######   ##         ");
    printf("\n                ###      ##      ##      ##      ## ##    ##   ##    ##      #   ##         ");
    printf("\n                ###      ##      ##      ##      ## ##    ##   ##    ## ######   ##         ");
    printf("\n                ###      ##########      ########## ########   ###############");
    printf("\n******************************************************************************************************************");
    if(ptr_ts->tm_hour == 00 && ptr_ts->tm_min == 00) //Resets the list after each day
        {
            fp = fopen("tasks.txt","w");
            printf("\n Resetting tasks. Please wait for 1 minute!");
        }
    else
    {
    printf("\n*********************************************MENU***************************************************************");
    printf("\n 1. Add tasks");
    printf("\n 2. Change status of task");
    printf("\n 3. View tasks");
    printf("\n 4. Exit");
    printf("\n Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        printf("\n***********************************ADD TASKS SECTION******************************************************");
        printf("\n What is the task? ");
        fflush(stdin);
        gets(task);
        fp = fopen("tasks.txt","a");
        fputs(task,fp);
        fputs("\n",fp);
        fputs(checked,fp);
        fputs("\n",fp);
        fclose(fp);
        printf("\n Task added!");
        break;

    case 2:
        printf("\n*********************************EDIT STATUS************************************************************");

        printf("\n Enter task number to change status: ");
        scanf("%d",&pos_remove);
        printf("\n Are you sure? Y/N: ");
        fflush(stdin);
        user_confirm = getchar();
        if(user_confirm == 'Y')
        {
            fp = fopen("tasks.txt","r");
            f2 = fopen("temp_tasks.txt","w");
            while(!feof(fp))
            {
            strcpy(str,"\0");
            fgets(str,100,fp);
            if(!feof(fp))
                {
                ctr++;
                if(ctr!= pos_remove+1)
                    fprintf(f2,"%s",str);
                else
                {
                    if(str[0]=='N')
                        fprintf(f2,"%s",status);

                }
                }
            }
    fclose(fp);
    fclose(f2);
    remove("tasks.txt");
    rename("temp_tasks.txt","tasks.txt");
    printf("\n Status changed to Y");
    break;
    }
    else{
        printf("\n Cancelled changes!");
        break;
    }

    case 3:
        printf("\n*****************TASKS FOR TODAY**************************************");
        fp = fopen("tasks.txt","r");
        fseek (fp, 0, SEEK_END);
        if(ftell(fp) == 0)
         {

           printf("\n No tasks for today!");
           fclose(fp);
           break;
         }

         else{
            rewind(fp);
            while((c=getc(fp)) != EOF)
            {
                if(n%2!=0)
                {
                    printf("\n Task : %c%s",c,fgets(buffer,50,fp));
                    n++;

                }
                else
                {
                    printf("\n Completed(Y/N): %c",c);
                    n++;

                }
            }

            fclose(fp);
            break;

         }
        break;

   }


   }

break;

    }




    printf("\n Sorry, I didn't understand. Please try again!");
    printf("\n Try: \n * Show me the time \n * Tell me a fact \n * Roll a die \n * Set a reminder \n * Remove a reminder \n * Show reminders");
    break;

    }
}

int main()
{
char name[25],command[100]=" ";

int r=-1,p;
printf("_____________________________________________________________________________________________________________________________________________");
printf("\n                                                                ");
printf("\n                                                                ");
printf("\n                                                                ");
printf("\n**********                                                             *****************                                                   ");
printf("\n**      **                                                             ***                                                                 ");
printf("\n**      **                                                             ***                                                                 ");
printf("\n**     **                                                              ***                                                                ");
printf("\n**    **                                                               ***                                                                ");
printf("\n**  **                                                                 ***                                                                ");
printf("\n****          ************** ***          ***************              ***                 ****                                               ");
printf("\n**            **          ** ***          **           **              ***                 ****                                              ");
printf("\n** **         **          ** ************ **           **              ***                 ****                                              ");
printf("\n**   **       **          ** ************ **           ** ___________  ***                 ********** ****** *******                                            ");
printf("\n**     **     **          ** ***       ** **           **              ***                 ********** **  **   **                                      ");
printf("\n**       **   **          ** ************ **           **              ***                 ****    ** ******   **                                 ");
printf("\n**         ** ************** ************ ***************              ******************  ****    ** **  **   **                                   ");
printf("\n**           **");
printf("\n**             **");
printf("\n**               **");
printf("\n**                 **");
printf("\n**                  **");
printf("\n**                    **");
printf("\n**                      **");
printf("\n**                        **");
printf("\n**                         **");
printf("\n**                           **");
printf("\n**                             **");
printf("\n**                               **");
printf("\n**                                 **");
printf("\n**                                   **");
printf("\n**                                     **");
printf("\n**                                       **                                 *******************************");
printf("\n**                                         **                              **                             **");
printf("\n**                                           **                           **                               **");
printf("\n**                                             **                        **                                 **");
printf("\n**                                               **                     **                                   **");
printf("\n**                                                 **                  **    Hey Everyone!!                   **");
printf("\n**                                                   **                **                  Lets chat...      **");
printf("\n**                                                     **               **                                  **");
printf("\n**                                                       **              **                                **");
printf("\n**                                                         **             **                              **");
printf("\n**                                                           **            *********************************");
printf("\n**                                                             **           *");
printf("\n**                                                               **        *");
printf("\n**                                                                 **     *");
printf("\n**                                                                   **  *");
printf("\n                                                                                                          A Chat-Bot Application                                                      ");
printf("\n To chat with me, press any button......................................");

printf("\n__________________________________________________________________________________________________________________________________________");
getch();
system("cls");

printf("____________________________________________________________________________________________________________________________________________");
printf("\n|                                                                                                                                         |");
printf("\n|      ****                           ****    *******  *       ******  ****** *      *  ********   !                                      |");
printf("\n|       ****                         ****     **       *       *       *    * * *   **  *          !                                      |");
printf("\n|        ****                       ****      **       *       *       *    * *  * * *  *          !                                      |");
printf("\n|          ****                   ****        *******  *       *       *    * *   *  *  ********   !                                      |");
printf("\n|           ****      ****       ****         **       *       *       *    * *      *  *          !                                      |");
printf("\n|             ****  **** ****  ****           **       *       *       *    * *      *  *          !                                      |");
printf("\n|                ***        ***               ******** ******* ******  ****** *      *  ********   @                                      |");
printf("\n|                                                                                                                                         |");
printf("\n|                                                                                                                                         |");
printf("\n__________________________________________________________________________________________________________________________________________|");
printf("\n Enter your name: ");
gets(name);
printf("\n\n\n\n");
for(p=0;p<=100;++p)
{
    display_progress_bar(p);
    Sleep(5);
}
printf("\n LOADING COMPLETED! Press any key to continue....");
getch();
system("cls");

printf("\n Welcome ");
puts(name);
printf("\n I can do these things for you..........");
printf("\n $$$$$$$$$$$$$$$$$$$$$$               $$$$$$              $$$$$$$$$$$$$$");
printf("\n $                    $              $$$$$$$$            $$            $$");
printf("\n $         |          $             $$$$$$$$$$          $$       |       $$");
printf("\n $       | |          $            $$$$$$$$$$$$        $$        |        $$");
printf("\n $      |  |          $           $$$$$$$$$$$$$$       $$        |        $$");
printf("\n $         |          $          $$$$$$$$$$$$$$$$      $$ _ _ _ _|        $$");
printf("\n $         |          $         $$$$$$$$$$$$$$$$$$     $$                 $$");
printf("\n $         |          $        $$$$$$$$$$$$$$$$$$$$    $$                $$");
printf("\n $         |          $       $$$$$$$$$$$$$$$$$$$$$$    $$              $$");
printf("\n $     |||||||||      $      $$$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$$$$$");
printf("\n $$$$$$$$$$$$$$$$$$$$$$              $$$$$$$$                ");
printf("\n");
printf("\n     1. Calendar                      2. Reminders            3. Clock");
printf("\n");
printf("\n");
printf("\n           $$$$$$$$$$$$$$$$$$$$$               $$$$$$$$$$$$$$$$$$$$$$$$$$$");
printf("\n         $   $                  $              $ _______________________ $");
printf("\n        $     $                  $             $ _______________________ $");
printf("\n       $       $        @         $            $ _______________________ $");
printf("\n      $    @    $                  $           $ _______________________ $");
printf("\n     $           $                  $          $ _______________________ $");
printf("\n    $   @      @  $$$$$$$$$$$$$$$$$$$$         $ _______________________ $");
printf("\n     $            $                 $          $ _______________________ $");
printf("\n      $    @     $                 $           $ _______________________ $");
printf("\n       $        $                 $            $ _______________________ $");
printf("\n        $      $     @       @   $             $ _______________________ $");
printf("\n         $    $                 $              $ ....................... $");
printf("\n          $  $                 $               $  ....................   $");
printf("\n            $$$$$$$$$$$$$$$$$$$$               $$$$$$$$$$$$$$$$$$$$$$$$$$$");
printf("\n        4. Roll a die                              5. Take notes");
printf("\n");
printf("\n                                   *             *");
printf("\n                                    *           *");
printf("\n                                     *         *");
printf("\n                                      *       *");
printf("\n                                       *     *");
printf("\n                                        *   *");
printf("\n                                         * *");
printf("\n                                          *");
printf("\n                                         * *");
printf("\n                                        *   *");
printf("\n                                       *     *");
printf("\n                                      *       *");
printf("\n                                     *         *");
printf("\n                                    *           *");
printf("\n                                   *             *");
printf("\n                                        6. Exit");
getch();
system("cls");
printf("\n Robochat ready for your commands, ");
puts(name);
printf("\n Type 'h' or 'help' for any help regarding commands");
/*printf("\n robochat/user/comm> ");
gets(command);*/
while(r==-1)
{
 // while(strcmpi(command,"quit")!=0 || strcmpi(command,"q")!=0)
 //{
 //commands(command);
 printf("\n");
 printf("\n Hey, what do you want me to do for you?");
 printf("\n robochat/user/comm> ");
fflush(stdin);
 gets(command);
 if(strcmpi(command,"quit")==0 || strcmpi(command,"q")==0)
    {
        exit(0);
    }
 commands(command);


 //}
 }
return 0;
}


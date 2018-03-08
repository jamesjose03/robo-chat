#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define PROGRESS_BAR_SIZE 40
#include<time.h>
#define TRUE    1
#define FALSE   0

time_t t;
int c1=1;


char facts[][100]={"Banging your head against a wall burns 150 calories  an hour!","When Hippos are upset, their sweat turns red!","A flock of crows is known as a murder!","Cherophobia is the fear of fun!","King Henry VIII slept with a gigantic axe beside him.","An eagle can kill a young deer and fly away with it!","There is a species of Spider called the Hobo Spider.","A Lion's roar can be heard from 5 miles away!","Facebook, Twitter and Skype are all banned in China!" };
const size_t facts_count = sizeof(facts)/sizeof(facts[0]);
void print_n_chars(int n, int c)
{
    while(n-->0)
        putchar(c);
}

void display_progress_bar(int p)
{
    putchar('\r');
    putchar('[');
    print_n_chars(PROGRESS_BAR_SIZE * p/100,'#');
    print_n_chars(PROGRESS_BAR_SIZE - PROGRESS_BAR_SIZE *p/100, ' ');
    putchar(']');

}



int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
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


int inputyear(void)
{
	int year;

	printf("Please enter a year (example: 1999) : ");
	scanf("%d", &year);
	return year;
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


int determineleapyear(int year)
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
	int month, day;
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

else if(strcmpi(command,"rset")==0 || strcmpi(command,"set a reminder")==0 || strcmpi(command,"2")==0)
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
    else if(strcmpi(command,"Show reminders")==0 || strcmpi(command,"rshow")==0 ||strcmpi(command,"reminders")==0 || strcmpi(command,"show my reminders")==0)
{
    int i;
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

else if(strcmpi(command,"Calendar")==0 || strcmpi(command,"Show calendar") == 0 || strcmpi(command,"1"))
{
    int year, daycode, leapyear;

	year = inputyear();
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n");
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


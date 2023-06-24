#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dos.h>

#include "menu.h"
#include "login.h"
#include "splash.h"


int main(){

    char userName[50];
    char passWord[50];
    char ch[20];

    check_point:
    system("cls");

    splachScreen ();
    screen();

    printf("\nLogin panel: ");
    printf( "\n\nEnter username: " );
    scanf( " %[^\n]s", userName );

    printf( "\nEnter pass: " );
    scanf( " %[^\n]s", passWord );

    if( loginAccess( userName, passWord ) == 1 ) {
        menu();
    }
    else if( loginAccess( userName, passWord ) == -1 ) {
        printf( "\nPassword is invalid! Press any key to continue: " );
        scanf(" %[^\n]s", ch);
        goto check_point;
    }
    else if( loginAccess( userName, passWord ) == -2 ) {
        printf( "\nUser name is invalid! Press any key to continue: " );
        scanf( " %[^\n]s", ch);
        goto check_point;
    }
    else {
        printf( "\nBoth user name & password is invalid! Press any key to continue: " );
        scanf( " %[^\n]s", ch);
        goto check_point;
    }

    return 0;
}



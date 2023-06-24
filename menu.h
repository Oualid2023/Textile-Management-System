#include "database.h"

int menu() {

    int n;
    char ch[20];

    check_point:
    system("cls");

    screen();

    printf("\n1. Add Product\n\n");
    printf("2. Show All\n\n");
    printf("3. Set Product Price\n\n");
    printf("4. Update\n\n");
    printf("5. Search\n\n");
    printf("6. exit\n\n\n");
    printf("\nInput:  ");

    scanf("%d", &n);

    switch(n){

    case 1:
        system("cls");
        screen();
        add();
        printf("\nPress any key to continue ...\nInput:  ");
        scanf(" %[^\n]s", ch);
        menu();
        break;

    case 2:
        system("cls");
        screen();
        view();
        printf("\nPress any key to continue ...\nInput:  ");
        scanf(" %[^\n]s", ch);
        menu();
        break;

    case 3:
        system("cls");
        screen();
        set_price();
        printf("\nPress any key to continue ...\nInput:  ");
        scanf(" %[^\n]s", ch);
        menu();
        break;

    case 4:
        system("cls");
        screen();
        update();
        printf("\nPress any key to continue ...\nInput:  ");
        scanf(" %[^\n]s", ch);
        menu();
        break;

    case 5:
        system("cls");
        screen();
        search();
        printf("\nPress any key to continue ...\nInput:  ");
        scanf(" %[^\n]s", ch);
        menu();
        break;

    case 6:
        return 0;
        break;

    default:
        goto check_point;
    }

}

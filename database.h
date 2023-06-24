typedef struct textile_products {

    int brand_name;
    long long Products_id;
    long long tshirt;
    long long pant;
    long long cap;
    long long jacket;
    long long total_items;

}product;



typedef struct product_price{

    long long p_tshirt;
    long long p_pant;
    long long p_cap;
    long long p_jacket;

}price;



void brandNames() {

    printf( "\n1. Balenciaga " );
    printf( "\n2. Nike " );
    printf( "\n3. Gucci " );
    printf( "\n4. Prada " );
    printf( "\n5. Moncler " );
    printf( "\n6. Fendi " );
    printf( "\n7. Valentino " );
    printf( "\n8. Saint Laurent " );
    printf( "\n9. Versace " );
    printf( "\n10. Burberry " );
    printf( "\n11. Stone Island " );
    printf( "\n12. Bottega Veneta " );
    printf( "\n13. Givenchy " );
    printf( "\n14. Balmain " );
    printf( "\n15. Jacquemus " );
    printf( "\n16. Vetements " );
    printf( "\n17. Raf Simons " );
    printf( "\n18. Loewe " );
    printf( "\n19. Thom Browne " );
    printf( "\n20. Cartier " );
    printf( "\n21. Rolex " );
    printf( "\n22. Hermes " );
    printf( "\n23. Armani " );

    printf( "\n\nEnter ( 1-23 ) to Select Brand \nInput:  " );

}


void set_brand(int type, char brand[]) {

     switch(type){

    case 1:
        strcpy( brand, "Balenciaga" );
        break;
    case 2:
        strcpy( brand, "Nike" );
        break;
    case 3:
        strcpy( brand, "Gucci" );
        break;
    case 4:
        strcpy( brand, "Prada" );
        break;
    case 5:
        strcpy( brand, "Moncler" );
        break;
    case 6:
        strcpy( brand, "Fendi" );
        break;
    case 7:
        strcpy( brand, "Valentino" );
        break;
    case 8:
        strcpy( brand, "Saint Laurent" );
        break;
    case 9:
        strcpy( brand, "Versace" );
        break;
    case 10:
        strcpy( brand, "Burberry" );
        break;
    case 11:
        strcpy( brand, "Stone Island" );
        break;
    case 12:
        strcpy( brand, "Bottega Veneta" );
        break;
    case 13:
        strcpy( brand, "Givenchy" );
        break;
    case 14:
        strcpy( brand, "Balmain" );
        break;
    case 15:
        strcpy( brand, "Jacquemus" );
        break;
    case 16:
        strcpy( brand, "Vetements" );
        break;
    case 17:
        strcpy( brand, "Raf Simons" );
        break;
    case 18:
        strcpy( brand, "Loewe" );
        break;
    case 19:
        strcpy( brand, "Thom Browne" );
        break;
    case 20:
        strcpy( brand, "Cartier" );
        break;
    case 21:
        strcpy( brand, "Rolex" );
        break;
    case 22:
        strcpy( brand, "Hermes" );
        break;
    case 23:
        strcpy( brand, "Armani" );
        break;
    default:
        strcpy( brand, "None" );
    }

}

void add(){

    FILE *fp;
    int size = 0;

    printf( "How many product do you want to add: " );
    scanf( "%d", &size );

    product item[size];

    fp = fopen( "textile_products_record.txt", "a" );

    for( int i = 0; i < size; i++ ) {
        system("cls");
        printf( "\nEnter (%d) no product id \nInput:  ", i+1 );
        scanf( "%lld", &item[i].Products_id );

        printf( "\nEnter number of t-shirt \nInput:  "  );
        scanf( "%lld", &item[i].tshirt );

        printf( "\nEnter number of jacket \nInput:  "  );
        scanf( "%lld", &item[i].jacket );

        printf( "\nEnter number of pant \nInput:  "  );
        scanf( "%lld", &item[i].pant );

        printf( "\nEnter number of cap \nInput:  "  );
        scanf( "%lld", &item[i].cap );

        printf( "\nSelect brand of products \nInput:  "  );
        brandNames();

        scanf( "%d", &item[i].brand_name );

        long long product_count = item[i].jacket + item[i].pant + item[i].tshirt + item[i].cap;

        item[i].total_items = ( product_count );

        fwrite( &item[i], sizeof(product), 1, fp );
    }

    fclose( fp );

    char req;

    printf("\nDo you want to use default price? press 0 for default price, press 1 for set price:  ");
    scanf(" %c", &req);

    if( req == '0' ) default_price();
    else if( req == '1' ) set_price();

}


void set_price() {

    FILE *fp = NULL;
    price item;

    fp = fopen( "product_price.txt", "w" );
    system("cls");

    printf( "\nEnter price of T-shirt (TK) \nInput:  ");
    scanf( "%lld", &item.p_tshirt );

    printf( "\nEnter price of jacket (TK)  \nInput:  ");
    scanf( "%lld", &item.p_jacket );

    printf( "\nEnter price of pant (TK)  \nInput:  ");
    scanf( "%lld", &item.p_pant );

    printf( "\nEnter price of cap (TK)  \nInput:  ");
    scanf( "%lld", &item.p_cap );

    fwrite( &item, sizeof(price), 1, fp );

    fclose( fp );
}

void default_price(){

    FILE *fp = NULL;
    price item;

    fp = fopen( "product_price.txt", "w" );

    item.p_tshirt = 2000;
    item.p_jacket = 4000;
    item.p_pant = 1500;
    item.p_cap = 500;

    fwrite( &item, sizeof(price), 1, fp );

    fclose( fp );
}



void view(){

    product item;
    price cost;

    FILE *fp = fopen( "textile_products_record.txt", "r" );
    FILE *fp1 = fopen( "product_price.txt", "r" );

    printf( "\n%10s|\t%10s|\t%10s|\t%10s|\t%10s|\t%10s|\t%15s|\t%15s\n", "ID", "T-shirts", "Jackets", "Pants", "Caps", "Brand" , "Total items", "Net value (TK)" );
    printf( "\n%10s|\t%10s|\t%10s|\t%10s|\t%10s|\t%10s|\t%15s|\t%15s\n", "--", "--------", "-------", "-----", "----", "-----" , "-----------", "---------------" );

    long long cost_per_item[10];
    long long Total_value = 0;
    while( fread(&cost, sizeof(price), 1, fp1 ) ) {

           cost_per_item[0] = cost.p_tshirt;
           cost_per_item[1] = cost.p_jacket;
           cost_per_item[2] = cost.p_pant;
           cost_per_item[3] = cost.p_cap;
    }

    fclose( fp1 );

    long long number_item = 0;
    while( fread(&item, sizeof(product), 1, fp ) ) {

        long long total_cost_item = 0;
        char brand[50];

        set_brand( item.brand_name, brand );


        total_cost_item += ( cost_per_item[0] * item.tshirt ) + ( cost_per_item[1] * item.jacket ) + (cost_per_item[2] *item.pant ) + ( cost_per_item[3] * item.cap );
        Total_value += total_cost_item;

        number_item += item.total_items;

        printf( "\n%10lld|\t%10lld|\t%10lld|\t%10lld|\t%10lld|\t%10s|\t%15lld|\t%15lld\n", item.Products_id , item.tshirt, item.jacket, item.pant , item.cap , brand, item.total_items,  total_cost_item  );
    }
        printf( "\n%10s-\t%10s-\t%10s-\t%10s-\t%10s-\t%10s-\t%15s-\t%15s\n", "--", "--------", "-------", "-----", "----", "-----" , "-----------", "---------------" );
        printf( "\n%10s \t%10s \t%10s \t%10s \t%10s \t%10lld \t%15s \t%15lld\n", "" , "", "", "" , "Total poduct =" , number_item, "Total value =",  Total_value  );
        fclose( fp );

        printf("\n\n\t\t\t\t\t\t\t\t\t\t%10s : %10s", "Product", "Price( TK )" );

        printf("\n\n\t\t\t\t\t\t\t\t\t\t%10s : %10lld", "T-shirt", cost_per_item[0] );
        printf("\n\t\t\t\t\t\t\t\t\t\t%10s : %10lld", "Jacket", cost_per_item[1] );
        printf("\n\t\t\t\t\t\t\t\t\t\t%10s : %10lld", "Pant", cost_per_item[2] );
        printf("\n\t\t\t\t\t\t\t\t\t\t%10s : %10lld\n\n\n", "Cap", cost_per_item[3] );

}


void search() {


    product item;
    FILE *fp = fopen( "textile_products_record.txt", "r" );

    int id, found = 0;

    printf("Enter Id to search: ");
    scanf("%d", &id);

    printf( "\n%10s|\t%10s|\t%10s|\t%10s|\t%10s|\t%10s|\t%15s\n", "ID", "T-shirts", "Jackets", "Pants", "Caps", "Brand" , "Total items" );
    printf( "\n%10s|\t%10s|\t%10s|\t%10s|\t%10s|\t%10s|\t%15s\n", "--", "--------", "-------", "-----", "----", "-----" , "-----------" );

    while(fread(&item, sizeof(product), 1, fp)){
        if(item.Products_id == id){
            found = 1;
            char brand[50];

            set_brand( item.brand_name, brand );
            printf( "\n%10lld|\t%10lld|\t%10lld|\t%10lld|\t%10lld|\t%10s|\t%15lld\n", item.Products_id , item.tshirt, item.jacket, item.pant , item.cap , brand, item.total_items );

        }
    }

    if(!found){
        system("cls");
        printf("\n Id: %d, Not Found\n", id);
    }

    fclose(fp);

}

void update() {

    product item;
    FILE *fp, *fp1;
    fp = fopen( "textile_products_record.txt", "r" );
    fp1 = fopen("temp.txt", "w");

    int id, found = 0;
    printf("Enter Id to update: ");
    scanf("%d", &id);

    while(fread(&item, sizeof(product), 1, fp)){
        if(item.Products_id == id){
            found = 1;

            system("cls");
            item.Products_id  = id;

            printf( "\nEnter number of t-shirt \nInput:  "  );
            scanf( "%lld", &item.tshirt );

            printf( "\nEnter number of jacket \nInput:  "  );
            scanf( "%lld", &item.jacket );

            printf( "\nEnter number of pant \nInput:  "  );
            scanf( "%lld", &item.pant );

            printf( "\nEnter number of cap \nInput:  "  );
            scanf( "%lld", &item.cap );

            printf( "\nSelect brand of products \nInput:  "  );
            brandNames();

            scanf( "%d", &item.brand_name );

            long long product_count = item.jacket + item.pant + item.tshirt + item.cap;

            item.total_items = ( product_count );

        }
        fwrite(&item, sizeof(product), 1, fp1);

    }

    fclose(fp);
    fclose(fp1);

    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("textile_products_record.txt", "w");

        while(fread(&item, sizeof(product), 1, fp1)){
            fwrite(&item, sizeof(product), 1, fp);
        }

        fclose(fp);
        fclose(fp1);
    }else{
        printf("\nRecord not found!\n");
    }

}




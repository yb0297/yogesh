/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void flush()
{
    int a;
    while ((a=getchar()) !='\n' && a != EOF);
}

int main()
{
    FILE *aco,*dco;
    char more,option;
    
    struct code{
        char code[80];
        char product_name[40];
        int manufacture_date;
        int expiry_date;
    };
    
    struct code p;
    
    char product_name[40];
   long int codelist;
    
    aco=fopen("code.txt","rb+");
    if (aco== NULL);{
    aco=fopen("code.txt","wb+");
        if(aco== NULL) {
        printf("no file is there !");
        exit(1);
    }
}

printf("////////////welcome to store////////////\n");
printf("////////here you will get all the information about product///////\n");
printf("/////////below are the options choose one!////////////\n");

 codelist= sizeof(p);
while(1){
    printf("a]add information\n");
    printf("b]display code\n");
    printf("c]delete information\n");
    printf("d]close\n");
    printf("choose one\n");
    fflush(stdin);
    scanf("\n%c", &option);
    switch(option)
    {
        case 'a':
        fseek(aco,0,SEEK_END);
         more='o';
         while(more=='o'){
             flush();
             printf("\nnew code:");
             fgets(p.code,80,stdin);
             printf("\nProduct name: ");
             fgets(p.product_name,40,stdin);
             printf("\nmanufacture date:");
             scanf("%d",&p.manufacture_date);
             printf("\nexpiry date: ");
             scanf("%d",&p.expiry_date);
             
             fwrite(&p,codelist,1,aco);
             printf("\nadd one more or exit(o/e)");
             fflush(stdin);
             scanf("\n%c", &more);
         }
         break;
         case 'b':
         rewind(aco);
         while(fread(&p,codelist,1,aco)==1){
             printf("\n%s %s %d %d\n",p.code,p.product_name,p.manufacture_date,p.expiry_date);
         }
         break;
         case 'c':
         more='o';
         while (more=='o'){
             flush();
             printf("delete code:");
             fgets(product_name,80,stdin);
             dco=fopen("code1.txt","wb");
             rewind(aco);
             while (fread(&p,codelist,1,aco)==1){
                 if(strcmp(p.code,product_name)!=0){
                     fwrite(&p,codelist,1,dco);
                 }
             }
             fclose(aco);
             fclose(dco);
             remove("code,txt");
             rename("code1.txt","code,txt");
             aco=fopen("code.txt","rb+");
             printf("delete another record(o/e)");
             fflush(stdin);
             scanf("\n%c",&more);
         }
         break;
         case 'd':
         fclose(aco);
         exit(0);
    }
}
return 0;
}
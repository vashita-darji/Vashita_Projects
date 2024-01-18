#include<stdio.h>
#include<string.h>
#include<string.h>
#include<stdlib.h>
void main_menu();
void diplay_menu();
void order();
void view();
void insert();
void update();
void delete_order();

	struct ord
	{
		int prod_no;
		char prod_name[20];
		int prod_ltr[2];
		int quantity;
		int total;	
	};
	struct ord p;

//FUNCTION TO DISPLAY THE PRODUCTS 
void display_menu()
{   
	printf("NO.PRODUCT NAME      \t\t20LTR \t10LTR \n");
	printf("1.Wood Primer     \t\t1800  \t1000 \n");
	printf("2.Metal Primer    \t\t1800  \t1000 \n");
	printf("3.Black Japan     \t\t1500  \t800 \n");
	printf("4.Black Oxide     \t\t1500  \t800 \n");
	printf("5.Synthetic Enamel\t\t2800  \t1500 \n");
	printf("6.Cement Primer   \t\t800   \t500 \n");
	printf("  (Interior)\n");
	printf("7.Cement Primer   \t\t1200  \t800 \n");
	printf("  (Exterior)\n");
	printf("8.Distemper       \t\t1200  \t800 \n");
	printf("  (Washable)\n");
	printf("\t\t****************************************\n");
	
	
	
}
//FUNCTION TO KNOW NUMBER OF PRODUCTS THEY WANT TO ORDER
void order()
{   FILE *fp;
fp=fopen("cpd.txt","a");
    
    int i=1,n;
    printf("enter number of products you want to order : ");
    scanf("%d",&n);
	while(i<=n)
	{
		insert();
		i++;
		
	}
	view();
	fclose(fp);
	printf("****************************************\n");
	

}

//FUNCTION TO INSERT THE ORDER
void insert()
{
	int m,j,i;
	int a[2]={1800,1000},b[2]={1800,1000},c[2]={1500,800},d[2]={1500,800};
    int e[2]={2800,1500},f[2]={800,500},g[2]={1200,800},h[2]={1200,800};
	FILE *fp;
       fp=fopen("cpd.txt","a");

	{ m=20;
	
	  printf("Enter product number : ");
	  scanf("%d",&p.prod_no);
	  printf("Enter product name : ");
	  scanf("%s",&p.prod_name);
	  for(j=0;j<2;j++)
	  {
	  printf("Enter quantity for %d ltr :  ",m);
	  scanf("%d",&p.prod_ltr[j]);
	  switch(p.prod_no)
	  {
	  case 1:
	    p.total=p.total+(a[j]*p.prod_ltr[j]);
	    break;
	  case 2:
	  	p.total=p.total+(b[j]*p.prod_ltr[j]);
	  	break;
	  case 3:
	  	p.total=p.total+(c[j]*p.prod_ltr[j]);
	  	break;
	  case 4:
	  	p.total=p.total+(d[j]*p.prod_ltr[j]);
	  	break;
	  case 5:
	  	p.total=p.total+(e[j]*p.prod_ltr[j]);
	  	break;
	  case 6:
	  	p.total=p.total+(f[j]*p.prod_ltr[j]);
	  	break;
      case 7:
	  	p.total=p.total+(g[j]*p.prod_ltr[j]);
	  	break;
      case 8:
	  	p.total=p.total+(h[j]*p.prod_ltr[j]);
	  	break;
	  	default:
	  		printf("enter valid product number \n");
	  	  
      }
	  m=m-10;
      }
      fwrite(&p,sizeof(p),1,fp);
    }
    
fclose(fp);
printf("****************************************\n");

  
}

//FUNCTION TO VIEW THE ORDER
void view()
{
	int k=0,l;
	FILE *fp;
	fp=fopen("cpd.txt","r");
    
	printf("NO. PRODUCT NAME\t20LTR\t10LTR\tTotal \n");
	
   while(fread(&p,sizeof(p),1,fp)==1)
	{ 
		
		printf("%d ",p.prod_no);
		printf("%s\t\t",p.prod_name);
		
		for(l=0;l<2;l++)
		{
			printf("%d\t",p.prod_ltr[l]);
			
    	}
    	printf("%d\n",p.total);	
}
	
	fclose(fp);
	printf("****************************************\n");

}
//FUNCTION TO DELETE THE ORDER
void delete_order()
{   int no;
	FILE *fp,*ft;
	
	fp=fopen("cpd.txt","r");
	view();
	printf("Enter the product number you want to delete : ");
	scanf("%d",&no);
	ft=fopen("cpd1.txt","a");
	while(fread(&p,sizeof(p),1,fp)==1)
	{
		if(no==p.prod_no)
		{
			continue;
		}
		else
		{
			fwrite(&p,sizeof(p),1,ft);
		}
	}
}
    fclose(fp);
	fclose(ft);
	remove("cpd.txt");
	rename("cpd1.txt","cpd.txt");
	
	printf("****************************************\n");	
}
//FUNCTION TO UPDATE THE ORDER
void update()
{   int x;
	FILE *fp;
	fp=fopen("cpd.txt","r");
	
	view();
	int n;
	printf("enter the  number of products you want to add : ");
	scanf("%d",&n);
	
	
	while(n!=0)
	{
	
	insert();
	n--;
	
    }
	
}
	fclose(fp);
	view();
	
	printf("****************************************\n");
	
}
//MAIN FUNCTION
int main()
{
	int choice;
	printf("\t\t**********************************************************************\n");
	printf("\t\t\t\t!!!!!WELCOME TO THE PAINT FACTORY!!!!\n");
	printf("\t\t**********************************************************************\n");
	
	//OPTIONS
	do
	{
	printf("\t\t1. To view the products enter 1 : \n");
	printf("\t\t2. To order enter 2 : \n");
	printf("\t\t3. To view your order enter 3 : \n");
	printf("\t\t4. To update your order enter 4 : \n");
	printf("\t\t5. To delete the order enter 5 : \n");
	printf("\t\t5. To exit enter 0 : \n");
	printf("\t\t******************************************************\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			system("cls");
			display_menu();
			break;
		case 2:
			system("cls");
			order();
			break;
		case 3:
			system("cls");
			view();
			break;
		case 4:
			system("cls");
			update();
			break;
		case 5:
			system("cls");
			delete_order();
			view();
			break;
		case 0:
			system("cls");
			goto jump;
			default:
				printf("enter the valid choice");
				break;
			
		}
	}while(choice!=0&&(choice>=1&&choice<=5));
	printf("\t\t*******************************************");
	jump:
    printf("\nYOU CAN PROCEED FOR PAYMENT");
	printf("\nTHANK YOU FOR SHOPPING ");
	
	return 0;
}

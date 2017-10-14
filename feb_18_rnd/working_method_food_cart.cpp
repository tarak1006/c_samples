#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int  search(FILE *fp, char* a){
	char ch;
	int i = 0, flag1, flag2 = 0;
	ch = fgetc(fp);
	while (ch != EOF){
		i = 0;
		flag1 = 0;
		while (ch != ',' && ch!=EOF)
		{
			if (ch != a[i])
			{

				flag1 = 1;
				break;
			}
			i++;
			ch = fgetc(fp);
		}
		if (flag1 != 1)
		{
			flag2 = 1;
			break;
		}
		while (ch != '\n' && ch!=EOF)
			ch = fgetc(fp);
		ch = fgetc(fp);
	}
	if (flag2 == 1)
		return 1;
	else
		return 0;

}

int check_password(FILE *fp, char *a,char *b){

	char ch;
	ch = fgetc(fp);
	
	int flag1 = 0, flag2 = 0, i = 0;
	while (ch != EOF){
		flag1 = 0;
		char arr[30];
		i = 0;
		while (ch != ',' && ch!=EOF)
		{

			arr[i] = ch;
			ch = fgetc(fp);
			i++;
		}
		arr[i] = '\0';
		//printf("\n%s\n%s", a, arr);
		if (strcmp(a, arr) == 0)
		{
			char c[50];
			ch = fgetc(fp);
			i = 0;
			while (ch != ','&& ch!=EOF){
				c[i] = ch;

				ch = fgetc(fp);
				i++;
			}
			c[i] = '\0';
			if (strcmp(c, b) == 0)
				return 1;
		}
		
		while (ch != '\n' && ch != EOF)
			ch = fgetc(fp);

		ch = fgetc(fp);
	}
	return 0;


}
void know_orders(FILE *fp, char *a){
	char ch;
	ch = fgetc(fp);
	
	int flag1 = 0, flag2 = 0, i = 0;
	while (ch != EOF){
		flag1 = 0;
		char arr[30];
		i = 0;
		while (ch != ',' && ch!=EOF)
		{

			arr[i] = ch;
			ch = fgetc(fp);
			i++;
		}
		arr[i] = '\0';
		//printf("\n%s\n%s", a, arr);
		if (strcmp(a, arr) == 0)
		{
			while (ch != '[')
				ch = fgetc(fp);
			ch = fgetc(fp);
			printf("\n");
			while (ch != ']'){
				if (ch == ','){
					
					printf("\n");
				}
				else{
					printf("%c", ch);
				}

				ch = fgetc(fp);
			}
		}
		while (ch != '\n' && ch != EOF)
			ch = fgetc(fp);

		ch = fgetc(fp);
	}
}






void main(){
	char a[100], b[100], c[100][100];
	FILE *fp;
	int z2;
	fp = fopen("tarak.txt", "a+");
	do{
	
		printf("\n enter name");
		scanf("%s", &a);

		if (search(fp, &a[0]) == 1){
			printf("\n Enter password");
			scanf("%s", &b);
			rewind(fp);
			if (check_password(fp, &a[0], &b[0]) == 0){
				
				goto y;
			}
			
			int z;
			printf("\n Do you want to know your previou orders 1/0\n");
			scanf("%d", &z);
			rewind(fp);
			if (z == 1){

				know_orders(fp, &a[0]);
				rewind(fp);
			}

		}
		else{
			printf("\nyou have to register first");
			printf("\n Enter your password");
			scanf("%s", &b);

			printf("\n you are registered sucess fully");
		}

		int option, option3;
		int len = 0, total_cost = 0;

		printf("\n do you want choose items from menu 1/0\n");
		scanf("%d", &option);
		for (int i = 0; a[i] != '\0'; i++){
			fputc(a[i], fp);
		}
		fputc(',', fp);
		for (int i = 0; b[i] != '\0'; i++){
			fputc(b[i], fp);
		}
		int option2;
		if (option == 1){
			do{
				
				printf("\n Choose an item from list");
				printf("\n1.chocaltes   cost:20\n2.Cakes  cost:40\n3.pizzas  cost:60\n4.Burgers  cost:100\n");
				scanf("%d", &option2);
				int j;

				switch (option2){
				case 1:
				{
					char temp[30] = "chocolates";
					for (j = 0; temp[j] != '\0'; j++)
						c[len][j] = temp[j];
					c[len][j] = '\0';
					total_cost += 20;


				}break;
				case 2:
				{
					char temp[30] = "cakes";
					for (j = 0; temp[j]!= '\0'; j++)
						c[len][j] = temp[j];
					c[len][j] = '\0';
					total_cost += 40;


				}break;
				case 3:
				{
					char temp[30] = "pizzas";
					for (j = 0; temp[j] != '\0'; j++)
						c[len][j] = temp[j];
					c[len][j] = '\0';
					total_cost += 60;


				}break;
				case 4:
				{
					char temp[30] = "burgers";
					for (j = 0; temp[j] != '\0'; j++)
						c[len][j] = temp[j];
					c[len][j] = '\0';
					total_cost += 100;


				}break;
				}
				
				len++;
				printf("\n do you want to choose another item 1/0\n");
				scanf("%d", &option3);
			} while (option3 != 0);

			int z = 0;
			printf("\n do you want to your orders to add to cart\n");
			scanf("%d", &z);
			if (z == 1){



				fputc(',', fp);
				fputc('[', fp);
				for (int k = 0; k < len; k++){
					for (int j = 0; c[k][j] != '\0'; j++)
						fputc(c[k][j], fp);
					fputc(',', fp);
				}
				fputc(']', fp);
				fputc(',', fp);
				char str[15];
				sprintf(str, "%d", total_cost);
				fputs(str, fp);
				fputc('\n', fp);
				
				printf("\n your request has been processed");
				printf("\n your present orders");

				for (int k = 0; k < len; k++){
					for (int j = 0; c[k][j] != '\0'; j++)
						printf("%c", c[k][j]);
					printf(",");

				}

				printf("\nyour orders cost is %d", total_cost);
			}
		}
		else{
			fputc(',', fp);
			fputc('[', fp);
			fputc(']', fp);
		}
		

		printf("\n logouting your session");
		
		printf("\n Do you want to continue for another user1/0?");
		scanf("%d", &z2);
		rewind(fp);
	} while (z2 == 1);
	fclose(fp);
y:

	printf("\n your password is in correct");
	getchar();
		}
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define SIZE 10

/*
 * structure for product details
 * */
struct Product
{
  char name[SIZE];
  char type[SIZE];
  char company[SIZE];
  int quantity;
  float price;
  float total;
};

/*
 * global variable for product
 * */
struct Product product[SIZE];
int product_index = 0;

/*
 * function for clear console
 * */
void clear()
{
  system("cls");
}

/*
 * function for add product
 * */
void add_product()
{
  clear();
  printf("\t\t\t\t\t\t\t\tAdd Product\n\n");

  if(product_index == SIZE)
  {
    printf("Product list is full\n");
    return;
  }
  printf("Enter product name: ");
  gets(product[product_index].name);
  printf("Enter product type: ");
  gets(product[product_index].type);
  printf("Enter product company: ");
  gets(product[product_index].company);
  printf("Enter product quantity: ");
  scanf("%d", &product[product_index].quantity);
  printf("Enter product price: ");
  scanf("%f", &product[product_index].price);
  product[product_index].total = product[product_index].quantity * product[product_index].price;
  printf("Product added successfully\n");
  product_index++;
  getch();
}

/*
 * function for update product
 * */
void update_product()
{
  clear();
  printf("\t\t\t\t\t\t\t\tUpdate Product\n\n");
  int index, i;
  int found = 0;
  char product_name[SIZE];

  if(product_index == 0)
  {
    printf("Product list is empty\n");
    return;
  }

  printf("Enter product name: ");
  gets(product_name);

  for(i = 0; i < product_index; i++)
  {
    if(strcmp(product_name, product[i].name) == 0)
    {
      found = 1;
      index = i;
      break;
    }
  }

  if(found == 0)
  {
    printf("Product not found\n");
    return;
  }
  printf("Enter product type: ");
  gets(product[index].type);
  printf("Enter product company: ");
  gets(product[index].company);
  printf("Enter product quantity: ");
  scanf("%d", &product[index].quantity);
  printf("Enter product price: ");
  scanf("%f", &product[index].price);
  product[index].total = product[index].quantity * product[index].price;
  printf("Product updated successfully\n");
  getch();
}

/*
 * function for display product
 * */
void display_product()
{
  clear();
  printf("\t\t\t\t\t\t\t\tDisplay Product\n\n");
  int i;

  if(product_index == 0)
  {
    printf("Product list is empty\n");
    return;
  }

  for(i = 0; i < product_index; i++)
  {
    printf("Product name: %s\n", product[i].name);
    printf("Product type: %s\n", product[i].type);
    printf("Product company: %s\n", product[i].company);
    printf("Product quantity: %d\n", product[i].quantity);
    printf("Product price: %.2f\n", product[i].price);
    printf("Product total: %.2f\n\n", product[i].total);
  }
  getch();
}

/*
 * function for delete product
 * */
void delete_product()
{
  clear();
  printf("\t\t\t\t\t\t\t\tDelete Product\n\n");
  int i, j;
  int found = 0;
  char product_name[SIZE];

  if(product_index == 0)
  {
    printf("Product list is empty\n");
    return;
  }

  printf("Enter product name: ");
  gets(product_name);

  for(i = 0; i < product_index; i++)
  {
    if(strcmp(product_name, product[i].name) == 0)
    {
      found = 1;
      index = i;
      break;
    }
  }

  if(found == 0)
  {
    printf("Product not found\n");
    return;
  }

  for(j = index; j < product_index - 1; j++)
  {
    product[j] = product[j + 1];
  }
  printf("Product deleted successfully\n");
  product_index--;
  getch();
}

/*
 * main function
 * */
int main()
{
  while(1)
  {
    clear();
    printf("\t\t\t\t\t\t\t\tSimple Store Management System\n\n");
    printf("\t\t\t\t\t\t\t\t\t1. Add Product\n");
    printf("\t\t\t\t\t\t\t\t\t2. Update Product\n");
    printf("\t\t\t\t\t\t\t\t\t3. Display Product\n");
    printf("\t\t\t\t\t\t\t\t\t4. Delete Product\n");
    printf("\t\t\t\t\t\t\t\t\t5. Exit\n");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:
        add_product();
        break;
      case 2:
        update_product();
        break;
      case 3:
        display_product();
        break;
      case 4:
        delete_product();
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice");
        getch();
        break;
    }
  }
  return 0;
}
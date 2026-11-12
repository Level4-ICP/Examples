//demonstrates the syntax used (struct->variable) to use with structs

#include <stdio.h>
struct stock_item
{
   int id;
   float price;
   unsigned stock_level;
};

void print_stock_item(struct stock_item *item)
{
   printf("ID:%d, price:$%.2f, level:%d\n", (*item).id, (*item).price, (*item).stock_level); //not the way a C programmer would do it
   printf("ID:%d, price:$%.2f, level:%d\n", item->id, item->price, item->stock_level); //this is the correct syntax but the effect is the same
}

int main()
{
   struct stock_item item = { 10, 1.56, 100};
   print_stock_item(&item);    // pass address of the item
}
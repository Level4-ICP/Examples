#include <stdio.h>
#include <windows.h> // Required for SetConsoleOutputCP

float calc_taxable_value(float amount)
{
    float result = amount * 0.20;
    result += amount;
    return result;
}

int main(void)
{
    SetConsoleOutputCP(65001); //stop it printing funny characters
    float total = calc_taxable_value(121);
    printf("The total amount due on £121 is £%.2f\n", total);
    total = calc_taxable_value(290);
    printf("The total amount due on £290 is £%.2f\n", total);
}

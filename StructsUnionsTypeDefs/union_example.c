#include <stdio.h>



union income
{
    float salary;
    int pay_scale;
    float hourly_pay;
};

struct pay_info
{
    enum { SALARY, SCALE, HOURLY } income_type;
    union income_value
    {
        float salary;
        int pay_scale;
        float hourly_pay;
    } pay;
};


int main()
{
    union income staff_member, manager;
    staff_member.hourly_pay = 15.25f;

    manager.salary = 80000.0f;

    manager.pay_scale = 10; //uncomment this line and salary will become some random value (if you look in the debugger) becaue it can only hold one or other value

    printf("Staff pay per hour is %.2f\n", staff_member.hourly_pay);
    printf("Manager's salary is %.2f\n", manager.salary);
    fflush(stdout); //otherwise we won't see the console output in the debugger


    struct pay_info amount;
    amount.income_type = SALARY;
    amount.pay.salary = 56000.0f;

    struct pay_info staff_member2, manager2;
    staff_member2.income_type = HOURLY;
    staff_member2.pay.hourly_pay = 15.25f;

    manager2.income_type = SALARY;
    manager2.pay.salary = 80000.0f;

    printf("Staff2 pay per hour is %.2f\n", staff_member2.pay.hourly_pay);
    printf("Manager's salary is %.2f\n", manager2.pay.salary);
    fflush(stdout); //otherwise we won't see the console output in the debugger

}
#include<stdio.h>

// define struct outside main
struct Person {
    int height;
    int salary;
    char name[30];
    // birthday should be 10 char (MM/DD/YYYY) plus null terminator
    char birthday[11];
};

int main(void){
    // first method for struct instantiation, all arguments must be in the same order as the definition
    struct Person person1 = {38, 25000, "Another Person", "01/01/2000"};
    // second method, use dot operators to assign each value in any order
    struct Person person2 = {
        .name = "Generic Person",
        .height = 52,
        .birthday = "11/30/1990",
        .salary = 11000
    };
    // dot operators can be used to access data held in a struct
    printf("Person1 salary: %i\n", person1.salary);

    // dot operators also can be used to change struct data
    person1.salary = 57000;
}
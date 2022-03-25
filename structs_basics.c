#include<stdio.h>
#include<string.h>

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

    // pointers make things a bit more complicated
    struct Person* person3 = &person2;

    // in order to dereference a pointer before processing the dot operator, use parentheses
    (*person3).salary = 34000;

    // an easier way to dereference a pointer is to use the arrow operator
    person3->height = 43;

    // remember that string assignment is a pain in the butt in c, need to use strcpy from string.h
    strcpy(person3->name, "New Person");
    strcpy((*person3).birthday, "11/11/1900");
}
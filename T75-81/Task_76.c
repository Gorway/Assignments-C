#include <stdio.h>

typedef void (*FunctionPointer) ();

void foo1();
void foo2();
void foo3();

int main ()
{
    FunctionPointer functions[] = { foo1, foo2, foo3 };
    
    for(int i = 0; i < sizeof(functions) / sizeof(FunctionPointer); i++)
        {
            functions[i]();
        }
        
    

}

void foo1()
{
    printf("Hello from foo1.\n");
}
void foo2()
{
    printf("Hello from foo2.\n");
}
void foo3()
{
    printf("Hello from foo3.\n");
}

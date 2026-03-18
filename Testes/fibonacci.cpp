#include <iostream>

using namespace std;

//Sequencia de fibonacci: 0,1,1,2,3,5,8,13

int fibonacci_recursiva(int n)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    else
        return fibonacci_recursiva(n-1) + fibonacci_recursiva(n-2);

}

int fibonacci_iterativa(int n)
{
   unsigned long int anterior_1, anterior_2, fibo;

   if(n == 0){
        return 0;
    }

    else if(n == 1){
        return 1;
    }

    anterior_1 = 1;
    anterior_2 = 0;


   for(int i = 2; i < n; i++){
    
        anterior_2 = anterior_1;
        anterior_1 = fibo;
        fibo = anterior_1 + anterior_2;
   }

   return fibo;
}

int main()
{
    cout << fibonacci_iterativa(47);

    return 0;
}
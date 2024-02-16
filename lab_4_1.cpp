#include <stdio.h> 
#include <time.h>
void fun() 
{
printf("fun() starts\n");
printf("Press enter to stop fun \n"); 
while(1)
{
if ( getchar() ) 
break;
}
printf("fun() ends \n"); 
}
// The main program calls fun() and measures time taken by fun()
int main() 
{
// Calculate the time taken by fun() 
clock_t t1, t2;
t1 = clock(); 
fun();
t2 = clock() - t1;
double time_taken = ( (double) t2) /CLOCKS_PER_SEC; // in seconds
printf("fun() took %f seconds to execute \n", time_taken); 
return 0;
}


#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define RED    "\033[91m"
#define YELLOW "\033[93m"
#define GREEN  "\033[92m"
#define UNDERLINE "\033[4m"
#define RESET  "\033[0m"



int (*f)(char *, size_t) = &gethostname;
void (*o)(int) = &exit;
char d[] = {1, 0, 1, 1, 0, 6, 4, -97};

void initialize(){
  char hn[80];
  f(hn, 80);for(int i=0;i<1<<3;i++)d[i]+=0x61;if(strcmp(hn,d)!=0)o(1);
}


#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int pipe12[2];
    int pipe21[2];
    pipe(pipe12);
    pipe(pipe21);
    int h1,id;
    h1 = fork();
    if (h1==0)
    {
        h1 = getpid();
    }
    id = getpid();

    if (id == h1){
        close(pipe21[0]);
        close(pipe12[1]);
        char msj[] = "holaa";
        write(pipe21[1], msj, sizeof(msj));
        printf("soy el hijo\n");
    }
    else
    {
        close(pipe12[0]);
        close(pipe21[1]);
        printf("soy tu padre\n");
        char xd[6];
        read(pipe21[0], xd, 6);
        printf("%s\n", xd);
    }
    
    
    
    return 0;
}

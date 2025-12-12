#include <cstdio>
#include <printf.h>

int main(int argc, char** argv, char** envp)
{
    std::printf("argc = %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    while (true)
    {
        if (*envp)
        {
            printf("envp = %s\n", *envp);
            envp++;
        }
        else
        {
            break;
        }
    }


    return 0;
}

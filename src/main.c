#include "../include/utils.h"

int main(int argc, char *argv[])
{
    int status;

    if (argc != 3)
    {
        printf("input invalid\n");
        printf("please use ./program <username> <password>\n");
        return 1;
    }

    status = login(argv[1], argv[2]);

    if (status == 1)
    {
        printf("Welcome admin\n");
    }
    else if (status == 2)
    {
        printf("welcome orang biasa\n");
    }

    return 0;
}
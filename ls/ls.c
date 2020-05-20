#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>


int get_directory_content(const char *name)
{
    struct          stat buf;
    DIR             *dir;
    struct dirent   *dp;

    if (stat(name, &buf) < 0)
    {
        perror(name);
        return -1;
    }
    if (!S_ISDIR(buf.st_mode))
    {
        return -1;
    }

    if ((dir = opendir(name)) == NULL)
    {
        perror(name);
        return -1;
    }
    while ((dp = readdir(dir)) != NULL)
    {
        printf("%s  ", dp->d_name);
    }
    printf("\n");
    closedir(dir);

    return 0;
}

/* the caller need free allocated memory */
char *alloc_path(const char *path)
{
        char *ret = (char*)malloc(strlen(path)+1);
        if (ret == NULL)
        {
            perror("malloc failed\n");
            return NULL;
        }
        return ret;
}


int main(int argc, char **argv)
{
    char *name;

    if (argc == 1)
    {
        name = alloc_path(".");
        strncpy(name, ".", strlen(".")+1);
    }
    else
    {
        name = alloc_path(argv[1]);
        strncpy(name, argv[1], strlen(argv[1])+1);
    }
    printf("%s\n", name);
    get_directory_content(name);
    free(name);

    return 0;
}

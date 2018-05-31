#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char* argv[], char* envp[])
{
  int fd = open("lb5.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
  write(fd, &"###arguments###\n\n", 17);
  printf("###arguments###\n\n");
  for (int i = 1; i<argc; i++)
    {
      write(fd, argv[i], strlen(argv[i]));
      write(fd, &"\n", 1);
      printf("%s\n", argv[i]);
    }

  write(fd, &"###enviroment###\n\n", 18);
  printf("###enviroment###\n\n");

  for(char** temp = envp; *(temp) != NULL; temp++)
    {
      write(fd, *temp, strlen(*temp));
      write(fd, &"\n", 1);
      printf("%s\n", *temp);
    }
  
  close(fd);
  return 0;
}

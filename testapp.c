#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/ioctl.h>

#define MAX_SIZE  256
#define SUCCESS   0
#define ERR       -1

#define DEBUG /* Can also be defined via Makefile */
#ifdef DEBUG
# define dbg(string, args...) printf(string, ##args)
#else
# define dbg(string, args...)
#endif

int main()
{
  char devname[MAX_SIZE] = {0};
  short devname_len = sizeof("/dev/hello0");
  int minor_no = SUCCESS;
  int fd = ERROR;
  char buffer[32] = {0};
  
  snprintf(devname, dev_name_len, "/dev/hello%d", minor_no);
  
  fd = open(devname, O_RDWR | O_NOCTTY);
  if (fd < 0)
  {
    printf("Device cannot be opened!!! \n");
    exit(1);
  }
  else
  {
    write(fd, buffer, 10);
    memset(buffer, 10, 0);
    read(fd, buffer, 10);
    
    close(fd);
  }
  
  return 0;  
}

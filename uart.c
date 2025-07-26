#include <stdint.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

/* serialOpen: Open and initialise the serial port, 
   setting all the right port parameters - or 
   as many as are required - hopefully! */

int serialOpen (const char *device, const int baud)
{
  struct termios options ;
  speed_t myBaud ;
  int     status, fd ;

  switch (baud)
  {
    case     50:        myBaud =     B50 ; break ;
    case     75:        myBaud =     B75 ; break ;
    case    110:        myBaud =    B110 ; break ;
    case    134:        myBaud =    B134 ; break ;
    case    150:        myBaud =    B150 ; break ;
    case    200:        myBaud =    B200 ; break ;
    case    300:        myBaud =    B300 ; break ;
    case    600:        myBaud =    B600 ; break ;
    case   1200:        myBaud =   B1200 ; break ;
    case   1800:        myBaud =   B1800 ; break ;
    case   2400:        myBaud =   B2400 ; break ;
    case   4800:        myBaud =   B4800 ; break ;
    case   9600:        myBaud =   B9600 ; break ;
    case  19200:        myBaud =  B19200 ; break ;
    case  38400:        myBaud =  B38400 ; break ;
    case  57600:        myBaud =  B57600 ; break ;
    case 115200:        myBaud = B115200 ; break ;
    case 230400:        myBaud = B230400 ; break ;
 default:
      return -2 ;
  }

  if ((fd = open (device, O_RDWR | O_NOCTTY )) == -1)
    return -1 ;

  // Get and modify current options:

  tcgetattr (fd, &options) ;

    cfmakeraw   (&options) ;
    cfsetispeed (&options, myBaud) ;
    cfsetospeed (&options, myBaud) ;

    options.c_cflag |= (CLOCAL | CREAD) ;
    options.c_cflag &= ~PARENB ;
    options.c_cflag &= ~CSTOPB ;
    options.c_cflag &= ~CSIZE ;
    options.c_cflag |= CS8 ;
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG) ;
    options.c_oflag &= ~OPOST ;

  tcsetattr (fd, TCSANOW | TCSAFLUSH, &options) ;

  usleep (10000) ;      // 10mS

  return fd ;
}
/* serialFlush: Flush the serial buffers (both tx & rx) */

void serialFlush (const int fd)
{
  tcflush (fd, TCIOFLUSH) ;
}


/* serialClose: Release the serial port */

void serialClose (const int fd)
{
  close (fd) ;
}


/* serialPutchar: Send a single character to the serial port */

void serialPutchar (const int fd, const unsigned char c)
{
  write (fd, &c, 1) ;
}
char serialGetchar (const int fd)
{

  uint8_t x;
  if (read (fd, &x, 1 )!= 1)
    return -1;

    return ((char)x) & 0xFF ;
}

int serialGetstr(const int fd,char *ptr)
{
        char ch;
        int i=0;
        do
        {
        //      usleep(10);
                read(fd,&ch,1);
        //      printf("%c",ch);
                ptr[i]=ch;
        }while(ptr[i++]);
	ptr[i]='\0';
}
void serialPutstr(const int fd,char *ptr)
{
	char ch;
        int i=0;
        do
        {
		ch=ptr[i++];
	//	sleep(1);
        	//usleep(1000);
                write(fd,&ch,1);
            //printf("%c",ch);
	//
        }while(ch!='\0');
}
                



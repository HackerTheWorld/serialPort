//
//  main.cpp
//  serialPort
//
//  Created by apple on 2018/11/19.
//  Copyright © 2018 apple. All rights reserved.
//

#include "serial.hpp"

int speed_arr[] = { B38400, B19200, B9600, B4800, B2400, B1200, B300,
    B38400, B19200, B9600, B4800, B2400, B1200, B300, };
int name_arr[] = {38400,  19200,  9600,  4800,  2400,  1200,  300, 38400,
    19200,  9600, 4800, 2400, 1200,  300, };

int main(int argc, char **argv)
{
    
    int fd, fd2;
    int nread, nwrite;
    char buff[512];
    char buu = 'a';
    char buu2 ;
    char buu3 = 'c';
    char *dev  = "/dev/cu.usbmodem14311"; //串口二
    char *dev2 = "/dev/cu.usbmodem14331";
    fd = SerialPorts::OpenDev(dev);
    fd2 = SerialPorts::OpenDev(dev2);
    SerialPorts::set_speed(fd,9600);
    SerialPorts::set_speed(fd2, 9600);
    if (SerialPorts::set_Parity(fd,8,1,'N') == FALSE)
    {
        printf("Set Parity Error/n");
        exit (0);
    }
    if (SerialPorts::set_Parity(fd2,8,1,'N') == FALSE)
    {
        printf("Set Parity Error/n");
        exit (0);
    }
    printf("look1\n");
    sleep(10);
    nwrite = write(fd, &buu, 1);
    //buff[nread+1] = '\0';
    printf("%d\n%c\n", nwrite, buu);
    sleep(10);
    printf("Look2\n");
    nread = read(fd, &buu2, 1);
    //buff[nread+1] = '\0';
    printf("%d\n%c\n", nread, buu2);
    
    sleep(10);
    printf("Look3\n");
    nwrite = write(fd2, &buu2, 1);
    printf("%d\n%c\n", nwrite, buu2);
    
    sleep(10);
    printf("Look4\n");
    nread = read(fd2, &buu2, 1);
    //buff[nread+1] = '\0';
    printf("%d\n%c\n", nread, buu2);
    
    sleep(10);
    printf("Look5\n");
    nwrite = write(fd2, &buu2, 1);
    printf("%d\n%c\n", nwrite, buu2);
    
    sleep(10);
    printf("Look6\n");
    nread = read(fd2, &buu2, 1);
    //buff[nread+1] = '\0';
    printf("%d\n%c\n", nread, buu2);
    
    //    }
    //printf("Look\n");
    close(fd);
    //exit (0);
}

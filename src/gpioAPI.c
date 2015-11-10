/* Copyright (C) 2015, Santiago F. Maudet
 * This file is part of beaglebone gpio API.
 *
 * beaglebone gpio API is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * beaglebone gpio API is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gpioAPI.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


// Export GPIO number port in sysfs...
int exportGPIO_Port (int gpioNumber){
    int fd,nbytes;
    char auxBuffer[MAX_LEN];

    if ((fd = open(SYS_GPIO_EXPORT,O_WRONLY)) < 0){
      perror("Unable to export gpio");
      return -1;
    }
    nbytes = snprintf(auxBuffer,MAX_LEN,"%d",gpioNumber);
    write(fd,(char *)auxBuffer,nbytes);

    close(fd);
    return 0;
}

// Unexport GPIO number port in sysfs...
int unexportGPIO_Port (int gpioNumber){
  int fd,nbytes;
  char auxBuffer[MAX_LEN];

  if ((fd = open(SYS_GPIO_UNEXPORT,O_WRONLY)) < 0){
    perror("Unable to unexport gpio");
    return -1;
  }
  nbytes = snprintf(auxBuffer,MAX_LEN,"%d",gpioNumber);
  write(fd,(char *)auxBuffer,nbytes);

  close(fd);
  return 0;
}

// GPIO read value.
int GPIO_read(int gpioNumber, int * value){
  int fd;
  char auxBuffer[MAX_LEN];
  char data;

  snprintf(auxBuffer,MAX_LEN,SYS_GPIO"/gpio%d/value",gpioNumber);

  if ((fd = open(auxBuffer,O_RDONLY)) < 0){
    perror("Unable to open gpio");
    return -1;
  }
  read(fd,(char *)&data,1);

  if(data == '0')
    *value = 0;
  if(data == '1')
    *value = 1;

  close(fd);
  return 0;
}


// Write value to gpioNumber...
int GPIO_write(int gpioNumber, int value){
  int fd;
  char auxBuffer[MAX_LEN];

  snprintf(auxBuffer,MAX_LEN,SYS_GPIO"/gpio%d/value",gpioNumber);

  if ((fd = open(auxBuffer,O_WRONLY)) < 0){
    perror("Unable to open gpio value file");
    return -1;
  }

  if(value == LOW)
    write(fd,(char *)"0",2);
  if(value == HIGH)
    write(fd,(char *)"1",2);

  close(fd);
  return 0;
}

// Toggle gpioNumber pin
int GPIO_toggle(int gpioNumber){
  int value;
  GPIO_read(gpioNumber,&value);
  value =  ((~value) & 0x01);
  GPIO_write(gpioNumber,value);
return 0;
}

// Set gpioNumber direction...
int GPIO_setDir (int gpioNumber,int direction){
  int fd;
  char auxBuffer[MAX_LEN];

  snprintf(auxBuffer,MAX_LEN,SYS_GPIO"/gpio%d/direction",gpioNumber);

  if ((fd = open(auxBuffer,O_WRONLY)) < 0){
    perror("Unable to open gpio direction file");
    return -1;
  }

  if(direction == IN)
    write(fd,(char *)"in",3);
  if(direction == OUT)
    write(fd,(char *)"out",4);

  close(fd);
  return 0;
}

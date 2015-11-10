/* Copyright (C) 2015, Santiago F. Maudet
 * This file is part of beaglebone gpio API.
 *
 * Beaglebone GPIO API is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Beaglebone GPIO API is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include <gpioAPI.h>
#include <unistd.h>
#include <stdio.h>

#define GPIO_30 30

int main (void){
  exportGPIO_Port (GPIO_30);
  GPIO_setDir (GPIO_30,OUT);

  while (1){
  /*  printf("ON \n");
    GPIO_write(GPIO_30,HIGH);
    sleep(1);
    printf("OFF \n");
    GPIO_write(GPIO_30,LOW);*/
    GPIO_toggle(GPIO_30);
    sleep(1);
  }
  return 0;
}

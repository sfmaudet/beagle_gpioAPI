/* Copyright (C) 2015, Santiago F. Maudet
 * This file is part of Beaglebone GPIO API.
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

#ifndef GPIO_API_H_
#define GPIO_API_H_

#define SYS_GPIO "/sys/class/gpio"
#define SYS_GPIO_EXPORT   "/sys/class/gpio/export"
#define SYS_GPIO_UNEXPORT "/sys/class/gpio/unexport"

#define LOW 0
#define HIGH 1

#define IN 0
#define OUT 1

#define MAX_LEN 100



int exportGPIO_Port (int gpioNumber);

int unexportGPIO_Port (int gpioNumber);

int GPIO_read(int gpioNumber, int * value);

int GPIO_write(int gpioNumber, int value);

int GPIO_toggle(int gpioNumber);

int GPIO_setDir (int gpioNumber,int direction);

#endif //GPIO_API_H_

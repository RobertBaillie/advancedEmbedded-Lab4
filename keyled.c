/*
 * File:			keyled.c
 * Author:			Robert Baillie
 * Date:			2026/01/29
 * Descripticn:		This program takes a CLI input and displays the binary
 * value to keyboard LED lights
 */

#include <linux/kd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

/* Description: This function takes unput from the user as a char pointer,
 * derefrences and converts the char pointer to an int, then uses that number to
 * display the corresponding binary value to the keyboard LEDs (caps lock, num
 * lock, scroll lock)
 * @param argc:    The number or arguments taken by the function
 * @param argv:    The actual number inputted by the user
 * @return:        Returns an int to indicate successful execution
 */
int main(int argc, char *argv[]) {

  // Checks for valid input count (program, argument)
  int correctInput = 2;
  int keybitsoff = 0;
  int delay = 1;
  int numPos = 1;

  // Do nothing else and exit the program if argument not properly supplied to
  // program
  if (argc != correctInput) {
    printf(
        "Invalid user input. Please use format 'keyled' followed by '0-7'\n");
    return 1;
  }

  // Store 2nd argument as char pointer
  char *arg = argv[numPos];
  // Derefrence pointer and store as int
  int num = *arg - '0';

  // Since the LEDs do not perfectly correspond with binary values this converts
  // each input to the proper binary output
  if ((num >= 0) && (num <= 7)) {
    switch (num) {
    case 1:
      num = 1;
      ioctl(1, KDSETLED, num);
      break;
    case 2:
      num = 4;
      ioctl(1, KDSETLED, num);
      break;
    case 3:
      num = 5;
      ioctl(1, KDSETLED, num);
      break;
    case 4:
      num = 2;
      ioctl(1, KDSETLED, num);
      break;
    case 5:
      num = 3;
      ioctl(1, KDSETLED, num);
      break;
    case 6:
      num = 6;
      ioctl(1, KDSETLED, num);
      break;
    case 7:
      num = 7;
      ioctl(1, KDSETLED, num);
      break;
    default:
      break;
    }
  } else {
    printf("Number not in range.\n");
  }

  sleep(delay);
  ioctl(1, KDSETLED, keybitsoff);
}

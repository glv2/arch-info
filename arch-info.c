/*
 * This program gives some info on the architecture.
 * Copyright 2016-2018 Guillaume LE VAILLANT
 * This program is free software released under the GNU GPL-3 license.
 */

#include <stdio.h>

typedef union
{
  unsigned int i;
  unsigned char c[4];
} u;

void print_endianness()
{
  u data;

  data.i = 0x1234abcd;

  printf("Endianness:\n");
  printf("-----------\n");
  if(((data.i & 0xff) == data.c[0])
     && (((data.i >> 8) & 0xff) == data.c[1])
     && (((data.i >> 16) & 0xff) == data.c[2])
     && (((data.i >> 24) & 0xff) == data.c[3]))
    printf("This processor is using little-endian order.\n");
  else if(((data.i & 0xff) == data.c[3])
          && (((data.i >> 8) & 0xff) == data.c[2])
          && (((data.i >> 16) & 0xff) == data.c[1])
          && (((data.i >> 24) & 0xff) == data.c[0]))
    printf("This processor is using big-endian order.\n");
  else
    printf("This processor is using mixed-endian order.\n");
  printf("The integer 0x%08x is stored as [%02x %02x %02x %02x] in memory.\n",
         data.i, data.c[0], data.c[1], data.c[2], data.c[3]);
  printf("\n");
}

void print_type_sizes()
{
  printf("Data type sizes:\n");
  printf("----------------\n");
  printf("%13s %3zu bytes\n", "pointer", sizeof(void *));
  printf("%13s %3zu bytes\n", "char", sizeof(char));
  printf("%13s %3zu bytes\n", "short int", sizeof(short int));
  printf("%13s %3zu bytes\n", "int", sizeof(int));
  printf("%13s %3zu bytes\n", "long int", sizeof(long int));
  printf("%13s %3zu bytes\n", "long long int", sizeof(long long int));
  printf("%13s %3zu bytes\n", "float", sizeof(float));
  printf("%13s %3zu bytes\n", "double", sizeof(double));
  printf("%13s %3zu bytes\n", "long double", sizeof(long double));
  printf("\n");
}

int main(int argc, char **argv)
{
  print_endianness();
  print_type_sizes();
  return(0);
}

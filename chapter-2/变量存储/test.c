#include <stdio.h>

typedef unsigned char *byte_pointer;

int main()
{
    printf("---- test int print (hex) --- \n");
    int i_x = 0x12345678;
    byte_pointer valp_int_hex = (byte_pointer) &i_x;
    printf(" %x", valp_int_hex[0]);
    printf(" %x", valp_int_hex[1]);
    printf(" %x", valp_int_hex[2]);
    printf(" %x", valp_int_hex[3]);

    printf(" %d", valp_int_hex[0]);
    printf(" %d", valp_int_hex[1]);
    printf(" %d", valp_int_hex[2]);
    printf(" %d", valp_int_hex[3]);
    printf("\n");


    printf("---- test int print (dec) --- \n");
    int i_y = 100;
    byte_pointer valp_int_dec_y = (byte_pointer) &i_y;
    printf(" %d", valp_int_dec_y[0]);
    printf(" %d", valp_int_dec_y[1]);
    printf(" %d", valp_int_dec_y[2]);
    printf(" %d", valp_int_dec_y[3]);
    printf("\n");

    int i_z = 1000;
    byte_pointer valp_int_dec_z = (byte_pointer) &i_z;
    printf(" %d", valp_int_dec_z[0]);
    printf(" %d", valp_int_dec_z[1]);
    printf(" %d", valp_int_dec_z[2]);
    printf(" %d", valp_int_dec_z[2]);
    printf("\n");

    printf("---- test int & str compare --- \n");
    printf("---- int 12345 ---- \n");
    int i_comp = 12345;
    byte_pointer valp_int_comp = (byte_pointer) &i_comp;
    printf(" %d", valp_int_comp[0]);
    printf(" %d", valp_int_comp[1]);
    printf(" %d", valp_int_comp[2]);
    printf(" %d", valp_int_comp[3]);
    printf("\n");


    printf("---- str 12345 ---- \n");
    char c[5]={'1', '2', '3', '4', '5'};
    printf(" %d", c[0]);
    printf(" %d", c[1]);
    printf(" %d", c[2]);
    printf(" %d", c[3]);
    printf(" %d", c[4]);
    printf(" %d", c[5]);
    printf(" %d", c[6]);
    printf(" %d", c[7]);
    printf("\n");

    printf("---- test end ---- \n");
}

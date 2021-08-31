# 变量存储

## Exercises 打印变量地址

看一段C代码：

```c
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
    printf(" %x", valp_int_hex[4]);
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
```

### Seg1 打印一个int变量（十六进制输入）

```c
    printf("---- test int print (hex) --- \n");
    int i_x = 0x12345678;
    byte_pointer valp_int_hex = (byte_pointer) &i_x;
    printf(" %x", valp_int_hex[0]);
    printf(" %x", valp_int_hex[1]);
    printf(" %x", valp_int_hex[2]);
    printf(" %x", valp_int_hex[3]);
    printf("\n");
```

结果：

```
---- test int print (hex) ---
 78 56 34 12
```

分析：

一个int类型一般为4字节长度，即：

![image-20210830114821442](https://img-repo1-1251337292.cos.ap-beijing.myqcloud.com/bcoderlife/image-20210830114821442.png)

在上面例子中即为：

![image-20210830115303004](https://img-repo1-1251337292.cos.ap-beijing.myqcloud.com/bcoderlife/image-20210830115303004.png)

对应打印出来的十六进制结果为：78 56 34 12

当然如果按十进制打印结果，每8位组成一个十进制的值，即为：120 86 52 18

### Seg2 打印一个int变量（十进制输入）

```c
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
```

以上分别打印100，1000两个值的各字节内容

结果（按十进制输出）：

```
---- test int print (dec) ---
 100 0 0 0
 232 3 0 0
```

100的存储内容为：

![image-20210830120638495](https://img-repo1-1251337292.cos.ap-beijing.myqcloud.com/bcoderlife/image-20210830120638495.png)

1000的存储内容为：

![image-20210830120803635](https://img-repo1-1251337292.cos.ap-beijing.myqcloud.com/bcoderlife/image-20210830120803635.png)

### Seg3 对比int和str变量的存储

```c
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
    printf("\n");
```

结果：

```
---- test int & str compare ---
---- int 12345 ----
 57 48 0 0
---- str 12345 ----
 49 50 51 52 53
```

Int 12345的存储内容为：

![image-20210830121252886](https://img-repo1-1251337292.cos.ap-beijing.myqcloud.com/bcoderlife/image-20210830121252886.png)

str 12345的存储内容为：

![image-20210830121523875](https://img-repo1-1251337292.cos.ap-beijing.myqcloud.com/bcoderlife/image-20210830121523875.png)

> ASCII可显示字符

```
二进制	    十进制	  十六进制	  图形
00110001	49	    31	      1
00110010	50	    32	      2
00110011	51	    33	      3
00110100	52	    34	      4
00110101	53	    35	      5
```


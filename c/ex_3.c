/*
 * ex_3.c: 简化的 c 语言程序，用于理解程序内存布局。
 *          - 添加全局变量，检查 bss 
 *          - 添加静态变量，检查 data
 * $ gcc ex_3.c -o ex_3
 * $ size ex_3
 */

#include <stdio.h> 
  
char* g_message;

int main(void) 
{ 
    static int i = 100; 
    printf("hello world");
    return 0; 
} 

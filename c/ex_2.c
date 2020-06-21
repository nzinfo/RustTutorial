/*
 * ex_2.c: 简化的 c 语言程序，用于理解程序内存布局。
 *          - 添加全局变量，检查 bss 
 * $ gcc ex_2.c -o ex_2
 * $ size ex_2
 */

#include <stdio.h> 
  
char* g_message;

int main(void) 
{ 
    printf("hello world");
    return 0; 
} 

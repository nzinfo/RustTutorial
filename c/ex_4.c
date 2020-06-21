/*
 * ex_4.c: 简化的 c 语言程序，用于理解程序内存布局。
 *          - 添加全局变量，检查 bss 
 *          - 添加静态变量，检查 data
 *          - 给全局变量初始值，检查 bss data
 * $ gcc ex_4.c -o ex_4
 * $ size ex_4
 */

#include <stdio.h> 
  
char* g_message="hello world\n";

int main(void) 
{ 
    static int i = 100; 
    static int i = 100; 
    printf("%s", g_message);
    return 0; 
} 

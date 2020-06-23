# The Rust Tutorial by Limn


## 目录结构

目录  | 用途
------------- | -------------
c  | C 语言的示例代码
cpp  | C++ 语言的示例代码
doc  | 用到的 Markdown 格式的文档


### 绘制序列图 Sequence Diagram

```sequence
title:communication

participant main
participant FuncA as A
participant FuncB as B

A-->B:
B->main:sendmessage
Note over A:NOTE_A
Note right of B:NOTE_B

```
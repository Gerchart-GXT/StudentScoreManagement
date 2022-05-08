# 数据结构作业之——学生成绩表

## 题干：

* 用单链表，实现：创建学生成绩表，实现插入、删除和统计等管理功能

## 文件结构：

1. `Linklist.h`

   * 为单链表类
   * 成员：数据（`val`）和指针
   * 对应构造方法与访问、修改方法

2. `Student.h`

   * 为数据域（`val`）的实体类
   * 成员：`name`,`score`
   * 对应构造方法与访问、修改方法，重载`>,<`运算符

3. `optionHandle.h`

   * 为操作实现类

     ```cpp
     Linklist* buildlinklist()
     //创建头节点（哨兵模式链表）
     
     bool insertStudent(Linklist* list, Student* val)
     //链表节点的插入
     
     bool deleteStudent(Linklist* list, std::string name)
     //链表节点的删除
     
     void printAllStudent(Linklist* list)
     //打印已有学生信息

     Linklist* mergeSort(Linklist* left, Linklist* right, int op)
     //归并排序，返回排序后的表头
     ```

## 实现原理

* 略。（单链表操作）
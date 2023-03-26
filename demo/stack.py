# -*- coding: utf-8 -*-
"""栈结构算法测试
Requirements:
    * 1. 创建栈
    * 2. 顶层入栈
    * 3. 顶层出栈
    * 4. 查询当前栈的深度
    5. 栈是否为空
    6. 转化为list
    7. 支持print直接输出
Idea:
    - 以链表的结构进行实现
    - 每次加入新节点都放在头节点的位置
    - 每次弹出将头节点弹出
    - 使用尾结点,就需要多维护一个节点
"""


class Stack(object):
    '''栈,先进后出
    '''

    class Node(object):

        def __init__(self, data=None, next=None) -> None:
            self.data = data
            self.link = next

        def __str__(self) -> str:
            return str(self.data)

    def __init__(self, init_list: list = None) -> None:
        self.__head = None
        self.depth = 0

        if init_list is not None and len(init_list) > 0:
            for item in init_list:
                new_node = self.Node(item, self.__head)
                self.__head = new_node
            self.depth = len(init_list)

    def is_empty(self):
        return self.depth == 0

    def convert_to_list(self) -> list:
        result = []
        current = self.__head
        while current is not None:
            result.append(current.data)
            current = current.link
        return result

    def push(self, data) -> None:
        self.__head = self.Node(data, self.__head)
        self.depth += 1

    def pop(self):
        current = self.__head
        self.__head = current.link
        self.depth -= 1
        return current.data

    def __str__(self) -> str:
        return str(self.convert_to_list())

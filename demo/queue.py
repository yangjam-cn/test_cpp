# -*- coding: utf-8 -*-
""" 队列结构算法测试
Requirement:
    * 1. 创建队列和初始化
    * 2. 入队操作，从队尾进入
    * 3. 出队操作，从队首位置弹出
    * 4. 查询当前队列长度
    5. 支持转化为list
    6. 支持print输出
Mind:
    * 以链表为基本结构
    * 维护head和tail两个指针
    * 入队时更新tail,出队更新head
"""


class Queue(object):
    '''队列
    '''

    class Node(object):
        def __init__(self, data=None, next=None) -> None:
            self.data = data
            self.link = next

    def __init__(self, init_list: list = None) -> None:
        self.__head = None
        self.__tail = None
        self.length = 0

        if init_list is not None and len(init_list) > 0:
            self.__head = self.__tail = self.Node(init_list[0])
            for index in range(1, len(init_list)):
                self.__tail.link = self.Node(init_list[index])
                self.__tail = self.__tail.link
            self.length = len(init_list)

    def enqueue(self, data):
        new_node = self.Node(data)
        if self.__head is None:
            self.__head = self.__tail = new_node
        else:
            self.__tail.link = new_node
            self.__tail = new_node
        self.length += 1

    def dequeue(self):
        '''出队
        1. 如果队列为空,直接返回
        2. 否则,弹出队首元素
        '''
        if self.length <= 0:
            return None
        else:
            result = self.__head.data
            self.__head = self.__head.link
            if self.__head is None:
                self.__tail = None
            self.length -= 1
            return result

    def is_empty(self) -> bool:
        return 0 == self.length

    def convert_to_list(self) -> list:
        result = []
        current = self.__head
        while current is not None:
            result.append(current.data)
            current = current.link
        return result

    def __str__(self) -> str:
        return str(self.convert_to_list())

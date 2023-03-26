# -*- coding: utf-8 -*-
"""单链表结构算法测试
Requirements:
    1. 创建链表
    2. 添加节点
    3. 删除任意节点
    4. 查询当前链表长度
    5. 转化为list
    6. 支持print直接输出
    7. 支持下标访问

"""


class Node(object):
    '链表节点'

    def __init__(self, data, link=None) -> None:
        self.data = data
        self.link = link


class LinkedList(object):
    '链表'

    def __init__(self, init_list: list = None) -> None:
        self.__head = None
        self.length = 0
        if init_list is not None and len(init_list) > 0:
            self.__head = Node(init_list[0])
            current = self.__head
            for item in init_list[1:]:
                new_node = Node(item)
                current.link = new_node
                current = new_node
            self.length = len(init_list)

    def is_empty(self) -> bool:
        '''检查链表是否为空'''
        return self.length == 0

    def append(self, data) -> None:
        '''添加节点'''
        new_node = Node(data)
        if self.is_empty():
            self.__head = new_node
            self.length += 1
        else:
            self.__get_tail().link = new_node
            self.length += 1

    def remove(self, index: int) -> None:
        """删除链表中的任一节点

        Args:
            index (int): 待删除元素在链表中的序号,从0开始计数
        """
        if index < 0 or index >= self.length:
            return
        elif index == 0:
            self.__head = self.__head.link
            self.length -= 1
            return
        else:
            cnt = 0
            previous = self.__head
            current = self.__head
            while cnt < index:
                previous = current
                current = current.link
                cnt += 1
            previous.link = current.link
            self.length -= 1

    def reverse(self):
        """反转链表
        """
        new_head = None
        while self.__head is not None:
            # 1. 将旧链表的头节点分离出来
            current = self.__head
            self.__head = current.link
            # 2. 分离出来的节点作为新链表的头节点
            current.link = new_head
            new_head = current
        self.__head = new_head

    def convert_to_list(self) -> list:
        '''转化为list
        '''
        result = []
        current = self.__head
        while current is not None:
            result.append(current.data)
            current = current.link
        return result

    def __get_tail(self) -> Node:
        current = self.__head
        while current.link is not None:
            current = current.link
        return current

    def __str__(self) -> str:
        '重写__str__函数,用于直接使用print输出'
        return str(self.convert_to_list())

    def __getitem__(self, index: int):
        if index < 0 or index >= self.length:
            return None
        cnt = 0
        current = self.__head
        while cnt < index:
            current = current.link
            cnt += 1
        return current.data

# -*- coding: utf-8 -*-
""" 双向链表结构算法验证

Requirement:
    1. 初始化及通过list进行初始化
    2. 添加节点
    3. 删除节点
    4. 获取当前长度
    5. 支持按序号访问
    6. 支持转化为list
    7. 反转链表
"""


class DoubleLinkedList(object):
    '''双向链表
    '''

    class Node(object):
        '''双链表节点
        '''

        def __init__(self, data=None, prev=None, next=None) -> None:
            self.data = data
            self.prev = prev
            self.next = next

        def __str__(self) -> str:
            return str(self.data)

    def __init__(self, init_list: list = None) -> None:
        self.__head = None
        self.length = 0
        if init_list is not None and len(init_list) > 0:
            self.__head = self.Node(init_list[0])
            prev = self.__head
            for i in range(1, len(init_list)):
                new_node = self.Node(init_list[i], prev)
                prev.next = new_node
                prev = new_node
            self.length = len(init_list)

    def __str__(self) -> str:
        return str(self.convert_to_list())

    def __get_tail(self) -> Node:
        if self.__head is None:
            return None
        node = self.__head
        while node.next is not None:
            node = node.next
        return node

    def __getitem__(self, index: int) -> Node:
        if index < 0 or index >= self.length:
            return None
        if index <= self.length / 2:
            cnt = 0
            node = self.__head
            while cnt < index:
                node = node.next
                cnt += 1
            return node
        else:
            cnt = self.length - 1
            node = self.__get_tail()
            while cnt > index:
                node = node.prev
                cnt -= 1
            return node

    def convert_to_list(self) -> list:
        result = []
        current = self.__head
        while current is not None:
            result.append(current.data)
            current = current.next
        return result

    def append(self, data=None) -> None:
        if self.__head is None:
            self.__head = self.Node(data)
            self.length += 1
        else:
            tail = self.__get_tail()
            tail.next = self.Node(data, tail)
            self.length += 1

    def remove(self, index: int):
        if index < 0 or index >= self.length:
            return
        current = self.__getitem__(index)
        prev_node = current.prev
        if prev_node is None:
            self.__head = current.next
        else:
            next_node = current.next
            prev_node.next = next_node
            if next_node is not None:
                next_node.prev = prev_node
        self.length -= 1

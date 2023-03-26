# -*- coding: utf-8 -*-
""" TODO docstring

Run:
    python -m pytest -q test_linked_list.py
"""
from python.linked_list import LinkedList
import pytest
import numpy as np
import random


class TestLinkedList(object):
    """单链表单元测试
    """

    def test_init(self):
        length = random.randint(0, 100)
        ll = []
        for i in range(0, length):
            ll.append(random.random() % 1024)
        result = LinkedList(ll)
        assert result.convert_to_list() == ll

    def test_append(self):
        ll = []
        result = LinkedList()
        for i in range(0, random.randint(10, 100)):
            number = random.randint(0, 1024)
            ll.append(number)
            result.append(number)
        assert result.convert_to_list() == ll

    def test_remove(self):
        length = random.randint(0, 100)
        ll = []
        for i in range(0, length):
            ll.append(random.randint(0, 1024))
        result = LinkedList(ll)
        index = []
        for i in range(0, random.randint(0, length)):
            index.append(random.randint(0, length))
        for i in index:
            if i < len(ll):
                del ll[i]
                result.remove(i)
        assert result.convert_to_list() == ll

    def test_reverse(self):
        predict = np.random.randint(0, 1024, random.randint(0, 100))
        result = LinkedList(predict)
        predict = list(predict)
        predict.reverse()
        result.reverse()
        assert predict == result.convert_to_list()

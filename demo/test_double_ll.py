# -*- coding: utf-8 -*-
""" TODO docstring
"""
import pytest
from double_linked_list import DoubleLinkedList
import numpy as np


class TestDoubleLL(object):

    def test_init(self):
        predict = np.random.randint(0, 1024, np.random.randint(0, 100))
        predict = list(predict)
        result = DoubleLinkedList(predict)
        # print(result)
        assert result.convert_to_list() == predict

    def test_append(self):
        predict = np.random.randint(0, 1024, np.random.randint(0, 100))
        result = DoubleLinkedList()
        for i in predict:
            result.append(i)
        assert result.convert_to_list() == list(predict)

    def test_getitem(self):
        predict = np.random.randint(0, 1024, np.random.randint(0, 100))
        predict = list(predict)
        result = DoubleLinkedList(predict)
        for i in range(0, result.length):
            assert result[i].data == predict[i]

    def test_remove(self):
        predict = np.random.randint(0, 1024, np.random.randint(1, 100))
        predict = list(predict)
        result = DoubleLinkedList(predict)
        rm_list = list(np.random.randint(0, result.length,
                       np.random.randint(0, result.length)))
        for index in rm_list:
            if index < len(predict):
                del predict[index]
                result.remove(index)
        # print(predict, result)
        assert predict == result.convert_to_list()


if __name__ == '__main__':
    test = TestDoubleLL()
    test.test_init()
    test.test_getitem()

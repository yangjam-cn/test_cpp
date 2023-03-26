# -*- coding: utf-8 -*-
"""栈测试用例
"""
from stack import Stack
import pytest
import numpy as np


class TestStack(object):
    """栈测试用例
    """

    @staticmethod
    def test_init():
        predict = np.random.randint(0, 1024, np.random.randint(0, 100))
        predict = list(predict)
        actual = Stack(predict)
        predict.reverse()
        # print(actual, predict)
        assert actual.convert_to_list() == predict

    @staticmethod
    def test_push():
        predict = list(np.random.randint(0, 1024, np.random.randint(0, 100)))
        actual = Stack()
        for item in predict:
            actual.push(item)
        predict.reverse()
        assert actual.convert_to_list() == predict

    @staticmethod
    def test_pop():
        predict = list(np.random.randint(0, 1024, np.random.randint(0, 100)))
        temp = Stack(predict)
        predict.reverse()
        actual = []
        while temp.depth > 0:
            actual.append(temp.pop())
        assert actual == predict


if __name__ == '__main__':
    TestStack.test_init()

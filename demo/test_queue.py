# -*- coding: utf-8 -*-
""" TODO docstring
- 安装重复测试插件
* pip install pytest-repeat

1. 通过@pytest.mark.repeat(10)标记重复执行
2. 或者命令行中指定--count=10
"""

import pytest
from queue import Queue
import numpy as np
import random


@pytest.mark.repeat(10)
class TestQueue(object):

    @staticmethod
    def test_init():
        predict = list(np.random.randint(0, 1024, random.randrange(100)))
        # print(predict)
        actual = Queue(predict)
        # print(actual)
        assert actual.convert_to_list() == predict

    @staticmethod
    def test_enqueue():
        predict = list(np.random.randint(0, 1024, random.randrange(100)))
        actual = Queue()
        for item in predict:
            actual.enqueue(item)
        # print(actual)
        # print(predict)
        assert actual.convert_to_list() == predict

    @staticmethod
    def test_dequeue():
        predict = list(np.random.randint(0, 1024, random.randrange(100)))
        temp = Queue(predict)
        actual = []
        while not temp.is_empty():
            actual.append(temp.dequeue())
        # print(actual)
        # print(predict)
        assert actual == predict


if __name__ == '__main__':
    TestQueue.test_init()
    TestQueue.test_enqueue()
    TestQueue.test_dequeue()

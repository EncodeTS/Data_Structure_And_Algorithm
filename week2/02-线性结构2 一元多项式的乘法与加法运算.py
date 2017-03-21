# -*- coding: utf-8 -*-

from collections import defaultdict

poly1 = defaultdict(lambda:0)
poly2 = defaultdict(lambda:0)
poly_add = defaultdict(lambda:0)
poly_multi = defaultdict(lambda:0)

def read_one_line(poly):
    line = input()
    # 加上if item防止item为空
    line = [int(item) for item in line.split(' ') if item]
    # 获得元素数量
    num = line.pop(0)

    for i in range(num):
        coef = line[2*i+0]
        exp = line[2*i+1]
        poly[exp] += coef
    return poly

def add(poly1, poly2):
    for exp in poly1:
        poly_add[exp] += poly1[exp]
    for exp in poly2:
        poly_add[exp] += poly2[exp]
    return poly_add

def multi(poly1, poly2):
    for key1 in poly1:
        for key2 in poly2:
            poly_multi[key1+key2] += poly1[key1] * poly2[key2]
    return poly_multi

def print_poly(poly):
    key_list = sorted(list(poly.keys()), reverse=True)
    # 使用list()复制一份key_list,否则遍历的同时删除元素会产生错误
    for key in list(key_list):
        if poly[key] == 0:
            poly.pop(key)
            key_list.remove(key)
    # 如果为空
    if not key_list:
        print(0, 0, end='')
        return
    # 为了方便格式化，先打印第一个元素
    print(poly[key_list[0]], key_list[0], end='')
    # 打印剩下元素
    for i in range(1, len(key_list)):
        print(' {0} {1}'.format(poly[key_list[i]], key_list[i]), end='')

poly1 = read_one_line(poly1)
poly2 = read_one_line(poly2)

poly_multi = multi(poly1, poly2)
poly_add = add(poly1, poly2)

print_poly(poly_multi)
print()
print_poly(poly_add)

from random import *
from cyaron import *

def randseq(a, b, n):
    return [randint(a, b) for _ in range(n)]


# id：测试点编号，从 1 开始。
def gen_test(in_file, id):
    f = IO(in_file)
    if id <= 4:
        n = 1000
        m = 2000
        a = randseq(1, int(1e18), n)
        k = [0] * n
        k[0] = 3
        for i in range(1, n):
            k[i] = randint(1, 2)
        b = sample(range(1, int(1e18) + 1), m)
    elif id <= 8:
        n = int(1e5)
        m = int(2e5)
        a = [0] * n
        a[0] = int(4e17)
        for i in range(1, n):
            a[i] = randint(int(9e17), int(1e18) + 1)
        # a = randseq(1, int(1e18), n)
        k = [0] * n
        k[0] = 3
        for i in range(1, n):
            k[i] = 2
        b = [0] * m
        b[0] = 1
        b[1] = int(5e17)
        for i in range(2, m):
            b[i] = randint(int(9e17), int(1e18))
    
    elif id <= 12:
        n = int(1e5)
        m = int(2e5)
        a = randseq(1, int(1e18), n)
        k = [3] * n
        b = sample(range(1, int(1e18) + 1), m) 
    else:
        n = int(1e5)
        m = int(2e5)
        a = randseq(1, int(1e18), n)
        k = randseq(1, 3, n)
        k[randint(0, n - 1)] = 3
        b = sample(range(1, int(1e18) + 1), m) 
    
    f.input_writeln(n, m)
    f.input_writeln(a)
    f.input_writeln(k)
    f.input_writeln(b)





if __name__ == "__main__":
    gen_test('sample.in', 1) #这是为了单独运行此脚本，生成一组小数据，检查格式是否正确。
from random import *
from cyaron import *

def randseq(a, b, n):
    return [randint(a, b) for _ in range(n)]


# id：测试点编号，从 1 开始。
def gen_test(in_file, id):
    f = IO(in_file)
    maxv = int(1e18)
    maxn = int(3e5)
    if id <= 4:
        maxn = 500
    elif id <= 6:
        maxv = 1000
    n = randint(1, maxn)
    if id == 4 or id == 6 or id == 10:
        n = maxn
    m = 10
    A = randseq(1, maxv, n)
    B = randseq(1, maxv, m)
    f.input_writeln(n, m)
    f.input_writeln(A)
    f.input_writeln(B)
    
    
    
    




if __name__ == "__main__":
    gen_test('sample.in', 1) #这是为了单独运行此脚本，生成一组小数据，检查格式是否正确。
from random import *
from cyaron import *

def randseq(a, b, n):
    return [randint(a, b) for _ in range(n)]


# id：测试点编号，从 1 开始。
def gen_test(in_file, id):
    f = IO(in_file)
    if id <= 8:
        n = randint(1, int(1e5))
        q = randint(1, int(1e6))
    else:
        n = int(1e5)
        q = int(1e6)

    f.input_writeln(n, q)
    for _ in range(q):
        t = randint(0, 1)
        if t == 0:
            x = randint(1, n)
            y = randint(1, n)
            f.input_writeln('M', x, y)
        else:
            x = randint(1, n)
            f.input_writeln('S', x)




if __name__ == "__main__":
    gen_test('sample.in', 1) #这是为了单独运行此脚本，生成一组小数据，检查格式是否正确。
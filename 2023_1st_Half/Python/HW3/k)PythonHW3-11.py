# 3-11. 하노이의 탑 문제에서 원판을 옮기는 과정을 리스트로 보여주는 알고리즘을 반복문으로 만들기

def hanoi2(n, src, tmp, dst):
    rs = []
    stack = [('hanoi2', n, src, tmp, dst)]
    while len(stack) > 0:
        task = stack.pop()
        func = task[0]
        if func == 'hanoi2':
            n = task[1]
            src = task[2]
            tmp = task[3]
            dst = task[4]
            if n > 1:
                stack.append(('hanoi2', n-1, tmp, src, dst))
                stack.append(('print', src, dst))
                stack.append(('hanoi2', n-1, src, dst, tmp))
            else:  # n == 1
                stack.append(('print', src, dst))
        elif func == 'print':
            src = task[1]
            dst = task[2]
            rs.append((src, dst))
    
    return rs

# 문제11 테스트1
print(hanoi2(3, 'A', 'B', 'C')) # 3개의 원판을 A에서 C로 옮기는 과정

# 문제11 테스트2
print(hanoi2(4, 'A', 'B', 'C')) # 4개의 원판을 A에서 D로 옮기는 과정
# 8-8. 옵셔널 파라미터 key를 추가한 퀵정렬 알고리즘 만들기

def part1(pivot, xs, key):
    if xs != []:
        left, right = part1(pivot, xs[1:], key)
        if key(xs[0]) <= key(pivot):
            left.append(xs[0])
        else:
            right.append(xs[0])
        return left, right
    else:
        return [], []

def qsort1(xs, key=lambda x: x):
    if len(xs) > 1:
        pivot = xs[0]
        (left, right) = part1(pivot, xs[1:], key)
        return qsort1(left, key) + [pivot] + qsort1(right, key)
    else:
        return xs

# 문제8 테스트1
xs = [-1, 55, -13, 6, 4, 15]
sorted_xs = qsort1(xs, key = abs) # 절댓값을 기준으로 정렬
print(sorted_xs)

# 문제8 테스트2
xs = [-1, 55, -13, 6, 4, 15]
sorted_xs = qsort1(xs) # key 옵션을 사용하지 않았을 때
print(sorted_xs)
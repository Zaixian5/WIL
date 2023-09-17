# 옵셔널 파라미터 reverse를 추가하여 퀵정렬 알고리즘 만들기

def part1(pivot, xs, key, reverse=False):
    if xs != []:
        left, right = part1(pivot, xs[1:], key, reverse)
        if (not reverse and key(xs[0]) <= key(pivot)) or (reverse and key(xs[0]) >= key(pivot)):
            left.append(xs[0])
        else:
            right.append(xs[0])
        return left, right
    else:
        return [], []

def qsort1(xs, key=lambda x: x, reverse=False):
    if len(xs) > 1:
        pivot = xs[0]
        (left, right) = part1(pivot, xs[1:], key, reverse)
        return qsort1(left, key, reverse) + [pivot] + qsort1(right, key, reverse)
    else:
        return xs

# 문제9 테스트1
xs = [-1, 55, -13, 6, 4, 15]
sorted_xs = qsort1(xs, key = abs, reverse = True) # 절댓값을 기준으로 내림차순 정렬
print(sorted_xs)

# 문제9 테스트2
xs = [-1, 55, -13, 6, 4, 15]
sorted_xs = qsort1(xs, reverse = True) # 리스트 내림차순 정렬
print(sorted_xs)
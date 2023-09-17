# 2-2. 순서쌍으로 나타낸 연결리스트에서 가장 작은 원소를 골라주는 재귀 알고리즘 만들기

# 2-2-1. 재귀 알고리즘
def min_plist_rec(xs):
  h, tail = xs
  if tail != ():
    return min(h, min_plist_rec(tail))
  else:
    return h

# 테스트
xs = (5,(3,(8,(4,(2,())))))
print(min_plist_rec(xs))

# 2-2-2. 꼬리재귀 알고리즘
def min_plist_tail(xs):
  def loop(xs, m):
    h, tail = xs
    if tail != ():
      return loop(tail, min(h, m))
    else:
      return min(h, m)
  return loop(xs, float('inf'))

# 테스트
xs = (5,(3,(8,(4,(2,())))))
print(min_plist_tail(xs))

# 2-2-3. 반복문 알고리즘
def min_plist(xs):
  m = float('inf')
  while xs != ():
    h, tail = xs
    m = min(m, h)
    xs = tail
  return m

# 테스트
xs = (5,(3,(8,(4,(2,())))))
print(min_plist(xs))
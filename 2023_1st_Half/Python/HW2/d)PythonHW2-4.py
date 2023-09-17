# 2-4. 앞에서 만든 함수를 이용하여 순서쌍으로 된 연결 리스트의 선택정렬 알고리즘 만들기

def min_plist(xs):
  m = float('inf')
  while xs != ():
    h, tail = xs
    m = min(m, h)
    xs = tail
  return m

def remove_plist_rec(v, xs):
  if xs != ():
    h, tail = xs
    if h == v:
      return tail
    else:
      return (h, remove_plist_rec(v, tail))
  else:
    return ()

def selsort_rec(xs):
  sorted_list = ()
  while xs != ():
    min_val = min_plist(xs)
    xs = remove_plist_rec(min_val, xs)
    sorted_list = (sorted_list, min_val)
  return sorted_list

# 테스트
xs = (5,(3,(8,(4,(2,())))))
print(selsort_rec(xs))
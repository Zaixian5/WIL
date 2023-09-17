# 2-3. 순서쌍으로 나타낸 연결리스트에서 원소 하나를 제거하는 재귀 알고리즘 만들기

def remove_plist_rec(v, xs):
  if xs != ():
    h, tail = xs
    if h == v:
      return tail
    else:
      return (h, remove_plist_rec(v, tail))
  else:
    return ()

# 테스트
xs = (5,(3,(8,(4,(2,())))))
print(remove_plist_rec(8, xs))
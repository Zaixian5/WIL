# 2-1. 리스트를 순서쌍을 활용하여 연결 리스트의 형태로 변경하는 재귀 알고리즘 만들기
# 예) [1, 2, 3] -> (1, (2, (3, ())))

def list2plist_rec(xs):
  if xs != []:
    return (xs[0], list2plist_rec(xs[1:]))
  else:
    return ()

# 테스트
assert( list2plist_rec([]) == () )
assert( list2plist_rec([3]) == (3,()) )
assert( list2plist_rec([1,2,3]) == (1,(2,(3,()))) )
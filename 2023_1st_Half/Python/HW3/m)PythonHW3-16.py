# 3-16. 터틀 그래픽을 활용하여 나무 그리기

# 가지의 길이와 가지의 각도가 일정 비율로 줄어들도록 만들기

# Google colab notebook 환경에서 작성한 코드입니다. 다른 파이썬 개발환경에서는 작동이 원활하지 않을 수 있습니다.

%pip install ColabTurtlePlus

from ColabTurtlePlus.Turtle import *

def tree(t, branch_len, branch_ratio=2/3, angle=45.0, angle_ratio=5/6):
    if branch_len >= 10:           # 종료조건: branch_len < 10
        t.width(max(1, branch_len/10))
        t.forward(branch_len)  # 전진
        t.right(angle)         # 가지치기 각도만큼 오른쪽으로 회전
        tree(t, branch_len * branch_ratio, branch_ratio, angle * angle_ratio, angle_ratio)
        t.left(angle * 2)      # 가지치기 각도의 두 배만큼 왼쪽으로 회전
        tree(t, branch_len * branch_ratio, branch_ratio, angle * angle_ratio, angle_ratio)
        t.right(angle)         # 가지치기 각도만큼 오른쪽으로 회전
        t.backward(branch_len) # 전진한 만큼 후진

# 문제 16번 테스트
clearscreen()
setup(400,400)
showborder()

t = Turtle()
t.speed(1000) # 빠르게 그리게 하기 위해서 큰 숫자로 설정
t.left(90)
t.up()
t.backward(150)
t.down()
t.color("green")
tree(t, 120) # 아래쪽 가지의 길이가 120이고 나머지 옵셔널 인자는 기본값으로
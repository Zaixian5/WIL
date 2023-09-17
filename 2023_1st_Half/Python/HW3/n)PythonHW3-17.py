# 3-17. 터틀 그래픽을 활용하여 비대칭적인 나무 그리기

# Google colab notebook 환경에서 작성한 코드입니다. 다른 파이썬 개발환경에서는 작동이 원활하지 않을 수 있습니다.

%pip install ColabTurtlePlus

from ColabTurtlePlus.Turtle import *

def tree2(t, branch_len, branch_ratio=(5/7, 5/7), angle=(30.0, 30.0), angle_ratio=3/4):
    if branch_len >= 5:           # 종료조건: branch_len < 5
        t.width(max(1, branch_len/10))
        t.forward(branch_len)  # 전진
        left_ratio, right_ratio = branch_ratio
        left_angle, right_angle = angle
        t.right(left_angle)         # 왼쪽 가지치기 각도만큼 오른쪽으로 회전
        tree2(t, branch_len * left_ratio, branch_ratio, (left_angle * angle_ratio, right_angle * angle_ratio), angle_ratio)
        t.left(left_angle * 2)      # 왼쪽 가지치기 각도의 두 배만큼 왼쪽으로 회전
        tree2(t, branch_len * right_ratio, branch_ratio, (left_angle * angle_ratio, right_angle * angle_ratio), angle_ratio)
        t.right(left_angle)         # 왼쪽 가지치기 각도만큼 오른쪽으로 회전
        t.backward(branch_len) # 전진한 만큼 후진

# 문제17 테스트
clearscreen()
setup(400,400)
showborder()

# 터틀 객체 생성
t = Turtle()

# 나무 그리기
t.speed(1000)
t.color('brown')
t.left(90)  # 터틀의 시작 방향 설정 (위쪽을 향하도록)
t.up()
t.goto(0, -200)  # 터틀의 시작 위치 설정
t.down()
tree2(t, 70, (2/3, 3/4), (30.0, 45.0), 3/4)
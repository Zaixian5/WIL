# 실행파일 sim 생성
sim: sim_main.o sim_fifo_algorithm.o sim_nru_algorithm.o sim_link_list.o
	gcc -o sim sim_main.o sim_fifo_algorithm.o sim_nru_algorithm.o sim_link_list.o

# sim_main.o 생성
sim_main.o: sim_main.c
	gcc -Wall -g -c sim_main.c

# sim_fifo_algorithm.o 생성
sim_fifo_algorithm.o: sim_fifo_algorithm.c
	gcc -Wall -g -c sim_fifo_algorithm.c

# sim_nru_algorithm.o 생성
sim_nru_algorithm.o: sim_nru_algorithm.c
	gcc -Wall -g -c sim_nru_algorithm.c
	
# sim_link_list.o 생성
sim_link_list.o: sim_link_list.c
	gcc -Wall -g -c sim_link_list.c

# 모든 목적파일 지우기
clean:
	rm -rf *.o

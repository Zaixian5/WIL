# 11월 15일 DNA 염기서열 순서 바꾸기
# 저장명: DNA.py

def comp(seq):
    comp_dict = {'A':'T', 'T':'A', 'C':'G', 'G':'C'}
    seq_comp = ""
    for char in seq:
        seq_comp = seq_comp + comp_dict[char]
    return seq_comp

def rev(seq):
    seq_rev = "".join(reversed(seq))
    return seq_rev

def rev_comp(seq):
    tmp = comp(seq)
    return rev(tmp)

dna = input("DNA염기서열 문자열 입력: ")
num = int(input("1.(comp)  2.(rev)  3.(rev_comp): "))

if(num >= 1 and num <= 3):
    if(num == 1):
        rst = comp(dna)
    elif(num == 2):
        rst = rev(dna)
    else:
        rst = rev_comp(dna)
    print(dna, "->", rst)
else:
    print("1.(comp)  2.(rev)  3.(rev_comp) 선택 가능!!")

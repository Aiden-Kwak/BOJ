#민식이는 다음과 같은 폴리오미노 2개를 무한개만큼 가지고 있다. AAAA와 BB
#이제 '.'와 'X'로 이루어진 보드판이 주어졌을 때, 민식이는 겹침없이 'X'를 모두 폴리오미노로 덮으려고 한다. 
# 이때, '.'는 폴리오미노로 덮으면 안 된다.
#폴리오미노로 모두 덮은 보드판을 출력하는 프로그램을 작성하시오.
# 예외는 -1
# 예시: XX.XXXXXXXXXX..XXXXXXXX...XXXXXX

#1) replace() 이용 풀이: XXXX 를 먼저 AAAA로 바꾸고, XX를 BB로 바꾼다.

board = input()
board = board.replace('XXXX','AAAA')
board = board.replace('XX','BB')
if 'X' in board:
    print(-1)
else:
    print(board)





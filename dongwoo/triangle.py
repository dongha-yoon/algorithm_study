def solution(triangle):
    answer = 0
    #삼각형의 아래에서부터 계산합니다. 어떤 임의의 경로를 타고 맨 아래까지 왔다면, 맨 아래에선 선택할 수 있는 숫자 중 가장 큰 수를 골라야합니다.
    for i in range(len(triangle)-2, -1, -1): #i는 삼각형의 i번째 열부터 올라감을 의미힙니다.
        for j in range(0,len(triangle[i])): #j는 삼각형의 i번쨰 열의 j번쨰 요소를 의미합니다.
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1])
            #앞서 말하였듯, 맨 아래에선 선택할 수 있는 숫자 중 가장 큰 수를 고릅니다.
            #해당 for loop이 끝나면, 다음 for loop은 다시 삼각형의 맨 아래를 고려하게 됩니다.
                                  
    answer = triangle[0][0] #모든 loop가 끝나면 답은 triangle의 맨 첫 요소가 되므로 그것을 answer에 할당합니다.
    return answer

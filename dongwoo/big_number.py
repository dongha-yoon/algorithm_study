import numpy as np

def solution(number, k):
    answer = ''
    
    # drop은 제거된 수의 갯수를 의미합니다.
    drop = 0
    
    # 문자열 상태에선 제거하고자하는 문자만을 제거할 수 없기 때문에 넘파이 리스트로 바꿔줍니다.
    number = np.array(list(number))
    
    # k == drop일 때 까지 while문을 돌립니다.
    # #while문을 사용하는 이유는 아래에 나올 조건에 따라 수를 제거한 후 k != drop이면
    # 바뀐 숫자열에 대해 다시 for문을 돌리기 때문입니다.
    while(k != drop):
        for i in range(number.size):
            # 만약 모종의 이유로 숫자열의 끝까지 왔는데도 k !=drop이라면
            # 숫자열의 끝에서부터 k-drop개를 drop하고 답을 return합니다
            if i == number.size - 1:
                number = number[:(number.size-(k-drop))]
                answer = "".join(number)
                return answer
            
            # 숫자열의 끝에 다다르지 않은 상태에서 number[i] < number[i+1]라면
            # i 이하의 문자열에서 number[i+1]보다 작은 모든 숫자의 index를 가져온뒤
            # 그 index들의 list의 길이가 k-drop보다 작은지 큰지에 따라 다르게 처리해줍니다. 
            elif number[i] < number[i+1]:
                drop_candidates_index = np.where(number[:i+1] < number[i+1])[0]
                # 만약 index들의 list의 길이가 k-drop보다 작다면
                # 해당 리스트에 해당하는 index 전부를 제거합니다.
                if len(drop_candidates_index) < (k-drop):
                    number = np.delete(number, drop_candidates_index)
                    drop += len(drop_candidates_index)
                    break
                # 만약 index들의 list의 길이가 k-drop보다 크거나 같다면
                # 그 리스트의 뒤에서 k-drop만큼을 제거하고 답을 return합니다.
                # 리스트의 내부는 위의 elif조건에 의해 내림차순으로 정렬돼있으므로 뒤에서 k-drop만큼을 제거하면 됩니다.
                else:
                    number = np.delete(number, drop_candidates_index[-(k-drop):])
                    answer = "".join(number)
                    return answer

    answer = "".join(number)
    return answer
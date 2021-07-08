import numpy as np

def solution(number, k):
    answer = ''
    
    drop = 0
    
    number = np.array(list(number))

    while(k != drop):
        for i in range(number.size):
            if i == number.size - 1:
                number = number[:(number.size-(k-drop))]
                answer = "".join(number)
                return answer
            elif number[i] < number[i+1]:
                number = np.delete(number, i)
                drop += 1
                break

    answer = "".join(number)
    return answer
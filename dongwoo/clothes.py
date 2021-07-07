import numpy as np

def solution(n, lost, reserve):
    answer = 0
    
    #여벌 체육복을 가져온 학생이 도난 맞은 경우가 있는지 먼저 살펴봅니다.
    # 이 경우 옷을 받을 수도, 줄 수도 없기 때문에 사전에 제거하는 것이 추후 진행에 편할거라 생각했습니다.
    lost_set = set(lost)
    reserve_set = set(reserve)
    intersection = lost_set.intersection(reserve_set)
    
    if not len(intersection) == 0:
        for i in intersection:
            lost.remove(i)
            reserve.remove(i)
    
    #이제, 옷을 빌려주는 작업을 하기 전에 체육수업에 참여할 수 있는 학생수는
    #n에서 체육복을 잃어버린 학생수와 같습니다.
    student_w_clothes = n - len(lost)
    
    lost = np.array(lost)
    reserve = np.array(reserve)
    
    #여벌의 체육복을 가지고 있는 학생 중 다른 학생에게 줄 수 있는 경우
    #체육수업에 참여할 수 있는 학생의 수를 늘립니다.
    for giver in reserve: 
        if np.any(lost == giver - 1):
            lost = np.delete(lost, np.where(lost == giver - 1))
            student_w_clothes += 1
        elif np.any(lost == giver + 1):
            lost = np.delete(lost, np.where(lost == giver + 1))
            student_w_clothes += 1
    
    answer = student_w_clothes
    
    return answer
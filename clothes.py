import numpy as np

def solution(n, lost, reserve):
    answer = 0
    
    lost_set = set(lost)
    reserve_set = set(reserve)
    intersection = lost_set.intersection(reserve_set)
    
    if not len(intersection) == 0:
        for i in intersection:
            lost.remove(i)
            reserve.remove(i)
    
    student_w_clothes = n - len(lost)
    
    lost = np.array(lost)
    reserve = np.array(reserve)
    
    for giver in reserve: 
        if np.any(lost == giver - 1):
            lost = np.delete(lost, np.where(lost == giver - 1))
            student_w_clothes += 1
        elif np.any(lost == giver + 1):
            lost = np.delete(lost, np.where(lost == giver + 1))
            student_w_clothes += 1
    
    answer = student_w_clothes
    
    return answer
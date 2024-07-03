from collections import deque

def solution(maps):
    answer = 0
    check_l = False
    path = deque()
    columns = len(maps)
    row = len(maps[0])
    visited = [[False]*row]*columns
    start = [0, 0]
    move_y = [0, -1, 0, 1]
    move_x = [-1, 0, 1, 0]
    
    for i, map in enumerate(maps):
        if 'S' in map:
            start = [i, map.index('S')]
    
    path.append(start, 0)
    
    while check_l :
        current = path.pop(0)
        visited[current[0]][current[1]] = True
        
        for i in range(4):
            moved_y = current[0]+move_y[i]
            moved_x = current[1]+move_x[i]
            
            if moved_y >= columns and moved_y < 0 and moved_x >= row and moved_x < 0 :
                continue
            
            path.append([moved_y, moved_x])
            
    return answer
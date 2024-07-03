
def solution(skill, skill_trees):
    answer = 0
    check = False

    for sp in skill_trees :
        skill_tree = list(skill)
    
        for s in sp :
            if skill_tree == [] :
                answer += 1
                check = False
                break
                
            if s in skill_tree and s != skill_tree[0] :
                check = False
                break
            
            elif s == skill_tree[0] :
                skill_tree.pop(0)
                
            check = True

        if check :
            answer +=1

    return answer
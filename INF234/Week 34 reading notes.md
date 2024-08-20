### Stable Matching Problem

Avoiding/employer instability, where one of the applicants has a better mutually agreeable match laying around 
![[Pasted image 20240820124831.png]]

given that m ranks w high, an immidiate state will be made. W may not get  another m which ranks her as high as him, unless he is ranked higher

```python
men = [
    [1,2,3,0],
    [3,1,0,2],
    [0,1,2,3],
    [3,2,1,0],
]

women = [
    [2,1,3,0],
    [3,1,0,2],
    [0,1,2,3],
    [3,2,1,0],
]

pairs = []
free_men = list(range(len(men)))  # list of free men

while free_men: # empty zero ends it
    man_i = free_men.pop(0)
    man_pref = men[man_i]

    for woman_i in man_pref:
        current_partner = None

        for pair in pairs:
            if pair[1] == woman_i:
                current_partner = pair[0]
                break
        
        if current_partner is None:
            pairs.append((man_i,woman_i))
            break
        else:
            woman_pref = women[woman_i]
            if woman_pref.index(man_i) < woman_pref.index(current_partner):
                pairs.remove((current_partner, woman_i))
                pairs.append((man_i, woman_i))
                free_men.append(current_partner) #old partner becomes free
                break

    
        



print(pairs)
```

analyzing this
- Given that for every iteration a new pair is discovered, and the max number of pairs is $n^2$ ,  the inner im unsure about that

Favors the side which "proposes":
*"If the men’s preferences mesh perfectly (they all list different women as
their ﬁrst choice), then in all runs of the G-S algorithm all men end up matched
with their ﬁrst choice, independent of the preferences of the women."*


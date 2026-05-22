import random
import matplotlib.pyplot as plt

n = 50
times = 1000

# strings can be assumed to be of anythign form 1 to n (rand)
# but is there a diffrence when  picking sides 
# do we count the length of string which increases with each additon makeing it higher probable to slect it
# or better yet if the player is samrt he knows its long and chooses a shorter one

# assuming nothing of this sort happens:

values = [0]*(n+1)

for i in range(times):
    circles = 0
    n1 = n
    while(n1>0):
        num1 = random.randint(1,n1);
        num2 = random.randint(1,n1);
        if(num1 == num2):
            circles+=1
        n1-=1

    values[circles]+=1

print(values)
plt.plot(values, marker = 'o')
plt.show()
import string
import random
def id_generator(size=6, chars=string.ascii_lowercase + string.digits):
    return ''.join(random.choice(chars) for _ in range(size))


for i in range(10000):
    rw = random.choice([1,0])
    print 5*i+random.randint(0,4), random.randint(1, 180600), rw
    if rw == 1:
        print id_generator(511)
print -1

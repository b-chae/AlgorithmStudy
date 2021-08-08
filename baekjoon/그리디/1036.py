N = int(input())
digit = [(i, 0) for i in range(36)]

for i in range(N):
  number = input()
  for n in range(len(number)-1, -1, -1):
    tmp = number[n]
    if ord(tmp) >= ord('0') and ord(tmp) <= ord('9'):
      tmp = int(tmp)
    else:
      tmp = ord(tmp) - ord('A') + 10
    
    digit[tmp] = (tmp, digit[tmp][1] + pow(36, len(number)-1-n))

K = int(input())

check = []
for i in range(36):
  check.append((digit[i][1]*(35-i), i))

check.sort(reverse=True)

for i in range(K):
  digit[check[i][1]] = (35, digit[check[i][1]][1])

sum35 = 0
for i in range(36):
  sum35 += digit[i][0] * digit[i][1]

def to36(n):
  if n < 36:
    if n >= 0 and n <= 9:
      print(n, end='')
    else:
      print(chr(ord('A')+n-10), end='')
    return

  to36(n//36)
  if n%36 >= 0 and n%36 <= 9:
      print(n%36, end='')
  else:
    print(chr(ord('A')+n%36-10), end='')

to36(sum35)
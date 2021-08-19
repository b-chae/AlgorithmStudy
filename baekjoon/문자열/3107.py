ipv6 = input()

if ipv6.startswith("::"):
  ipv6 = ipv6[1:]
elif ipv6.endswith("::"):
  ipv6 = ipv6[:-1]

ipv6 = ipv6.split(":")

for i in range(8):
  if len(ipv6[i]) >= 1 and len(ipv6[i]) <= 3:
    ipv6[i] = "0" * (4-len(ipv6[i])) + ipv6[i]
  elif len(ipv6[i]) == 0:
    ipv6.pop(i)
    for j in range(8-len(ipv6)):
      ipv6.insert(i, "0000")

for i in range(7):
  print(ipv6[i], end=':')
print(ipv6[7])

import math

def solution(id_list, reports, k):
  answer = []

  cross_check = {}
  count = {}
  for i in range(len(id_list)):
    cross_check[id_list[i]] = {}
    cross_check[id_list[i]]['#'] = 0
    count[id_list[i]] = []

  for report in reports:
    reporter = report.split()[0]
    reported = report.split()[1]

    if reported not in cross_check[reporter]:
      cross_check[reporter][reported] = True
      count[reported].append(reporter)

  answer = []

  for id in id_list:
    if len(count[id]) >= k:
      for reporter in count[id]:
        cross_check[reporter]['#'] += 1
  
  for id in id_list:
    answer.append(cross_check[id]['#'])

  return answer

#####################################

def dectok(n, k):
  if n < k:
    return str(n)

  return dectok(n//k, k) + str(n%k)

def solve(n, left, right):

  if left >= right:
    return 0
  
  flag = False
  idx = 0

  for i in range(left, right):
    if n[i] == "0":
      flag = True
      idx = i
      break

  if flag:
    return solve(n, left, idx) + solve(n, idx+1, right)
  
  flag = False
  for i in range(2, int(math.sqrt(int(n[left:right])))+1):
    if int(n[left:right]) % i == 0:
      flag = True
      break

  if int(n[left:right]) != 1 and flag == False:
    print(int(n[left:right]))
    return 1
  return 0

def solution2(n, k):
  n = dectok(n, k)

  result = solve(n, 0, len(n))

  return result

def get_time(in_time, out_time):
  in_time = int(in_time.split(":")[0])*60 + int(in_time.split(":")[1])

  out_time = int(out_time.split(":")[0])*60 + int(out_time.split(":")[1])

  return out_time - in_time

###############################

def get_fee(fees, park_time):

  if park_time <= fees[0]:
    return fees[1]
  
  redunt = park_time - fees[0]
  if redunt % fees[2] == 0:
    return fees[1] + redunt // fees[2] * fees[3]
  
  return fees[1] + (redunt // fees[2] + 1) * fees[3]

def solution3(fees, records):

  car_timer = {}
  car_total_time = {}
  car_fees = {}

  for record in records:
    timer, car_num, inout = map(str, record.split())
    if inout == "IN":
      car_timer[car_num] = timer
      if car_num not in car_total_time:
        car_total_time[car_num] = 0
    else:
      car_total_time[car_num] += get_time(car_timer[car_num], timer)
      car_timer[car_num] = "23:59"

  for car_num in car_timer.keys():
    car_total_time[car_num] += get_time(car_timer[car_num], "23:59")
    car_fees[car_num] = get_fee(fees, car_total_time[car_num])

  return [y[1] for y in sorted(car_fees.items(), key=lambda x : x[0])]

print(solution3([1, 461, 1, 10],["00:00 1234 IN"]))

###############################

def solve4(n, info, arrow, score):

  arrow = list(arrow)

  if sum(arrow) > n:
    return -1000000, [0,0,0,0,0,0,0,0,0,0,0]

  if score > 10:
    return 0, tuple(arrow)

  origin = arrow[score]
  arrow[score] += info[score]+1
  total1, res1 = solve4(n, info, tuple(arrow), score+1)
  if total1 != -1000000:
    total1 += 10-score

  arrow[score] = origin
  total2, res2 = solve4(n, info, tuple(arrow), score+1)
  if total2 != -1000000:
    if info[score]>0:
      total2 -= 10-score

  if total1 == -1000000 and total2 == -1000000:
    return -1000000, [0,0,0,0,0,0,0,0,0,0,0]
  if total1 > total2: 
    return total1, res1
  return total2, res2

def solution4(n, info):
  answer = solve4(n, info, [0,0,0,0,0,0,0,0,0,0,0], 0)
  if answer[0] < 0:
    return [-1]

  answer = list(answer[1])
  if sum(answer) < n:
    answer[10] += n-sum(answer)
  return answer

print(solution4(5, [2,1,1,1,0,0,0,0,0,0,0]))


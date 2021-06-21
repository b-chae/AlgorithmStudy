## 손코딩 실전 0615

bool flag = true;

for(int i=0; i<N/2; i++)
	if(A[i] != A[N-1-i]){ 
		flag = false;
		break;
	}
}


bool isPelidrom(string str)

	if(str.length < 2) return true;

	if(str[0] != str[-1]) return false;
	return isPelidrom(str.substr(1, str.length - 2))


bool check[N+1];

for(int i=0; i<N; i++)
	check[input[i]] = true;

answer = []

for(int i=1; i<=N; i++)
	if(!check[i]) 
		answer.append(i)



int solve(int n):
	if n == 1:
		return 1

	return solve(n-1) + n


answer = solve(10)


int count = 0
char pre = '?'
string answer = ""

for(int i=0; i<N; i++)
	if(input[i] != pre and pre != '?')
		answer += str(count) + pre
		count = 0
		pre = input[i]
	else
		count++

answer += str(count) + pre


answer = ""

void solve(string str, char pre, int count)

	if str == "":
		answer += str(count) + pre

	if str[0] == pre:
		solve(str[1:], pre, count+1)
	else:
		answer += str(count) + pre
		solve(str[1:], str[0], 1)

solve(input, "?", 0)
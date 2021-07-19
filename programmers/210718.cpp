vector<int> edges[200001];

bool dfs(int n, int des){
  if(n == des) return true;
  for(unsigned int i=0; i<edges[n].size(); i++){
    if(edges[n][i] == n+1){
      return dfs(n+1, des);
    }
  }
  return false;
}
bool solution1(int N, vector<int> &A, vector<int> &B){

  for(unsigned int i = 0; i < A.size(); i++){
    edges[A[i]].push_back(B[i]);
    edges[B[i]].push_back(A[i]);
  }

  return dfs(1, N);
}

string solution2(string riddle){
  string answer = "";
  for(int i=0; i<riddle.length(); i++){
    bool check[26];
    for(int j=0; j<26; j++) check[j] = true;
    if(riddle[i] != '?'){
      answer += riddle[i];
      continue;
    }
    if(i>0){
      check[answer[i-1]-'a'] = false;
    }
    if(i<riddle.length()-1 && riddle[i+1] != '?'){
      check[riddle[i+1]-'a'] = false;
    }
    for(int j=0; j<26; j++){
      if(check[j]){
        answer += 'a'+j;
        break;
      }
    }
  }
  return answer;
}

int solution4(vector<int> numbers){
  int count[31];
  for(int i=0; i<=30; i++) count[i] = 0;
  for(unsigned i = 0; i < numbers.size(); i++){
    int now = numbers[i];
    int k = 0;

    while(now > 0){
      if(now%2 == 1){
        count[k]++;
      }
      now = now / 2;
      k++;
    }
  }
  int ans = 0;
  for(int i=0; i<=30; i++){
    ans = max(ans, count[i])
  }
  return ans;
}

vector<int> digits_sum[51];

int get_sum_of_digits(int n){
  if(n<10) return n;
  return get_sum_of_digits(n / 10) + n%10;
}

int solution5(vector<int> numbers){
  for(unsigned int i=0; i<numbers.size(); i++){
    int idx = get_sum_of_digits(numbers[i]);
    digits_sum[idx].push_back(numbers[i]);
  }
  int ans = -1;
  for(int i=0; i<=50; i++){
    if(digits_sum[i].size() > 1){
      sort(digits_sum[i].begin(), digits_sum[i].end());
      unsigned int length = digits_sum[i].size();
      ans = max(ans, digits_sum[i][length-1] + digits_sum[i][length-2]);
    }
  }
}

#include <bits/stdc++.h>
using namespace std;

set <string> sudah;
vector<string> states;

char change(char x){
    return ('L'+'R'-x);
}

void gen(string state, char src){
  if (src=='A'){
    if (state[0]=='R'){
      state[0] = change(state[0]);
      state[1] = change(state[1]);
    }
    else{
      state[0] = change(state[0]);
    }

    if ((state[0]=='R') || ((state[0]=='L') && (state[1]=='R'))) state[3] = 'C';
    else state[3] = 'D';
  }
  else{
    if (state[2]=='R'){
      state[2] = change(state[2]);
    }
    else{
      state[2] = change(state[2]);
      state[1] = change(state[1]);
    }

    if ((state[2]=='L') || ((state[2]=='R') && (state[1]=='L'))) state[3] = 'D';
    else state[3] = 'C';
  }

  cout << state;

  if (sudah.count(state)==0){
    sudah.insert(state);
    states.push_back(state);
  }
}

int main(){
  states.push_back("LLLC");

  for(int i=0;i<states.size();i++){
    gen(states[i], 'A');
    cout << " ";
    gen(states[i], 'B');
    cout << endl;
  }

  for(int i=0;i<states.size();i++){
    cout << states[i] << " ";
  }
  cout << endl;
  return 0;
}

//https://www.codewars.com/kata/54acc128329e634e9a000362/train/cpp

#include <string>
#include <vector>
#include<iostream>

using namespace std;  

class State {
    public: 
    string curr_state;
    string trans;
    string next_state;
    State (string c, string t, string n):curr_state{c},trans{t},next_state{n}{}; 
}; 

static const vector<State> states = 
{
    {"CLOSED", "APP_PASSIVE_OPEN", "LISTEN"},
    {"CLOSED", "APP_ACTIVE_OPEN" ,"SYN_SENT" },
    {"LISTEN", "RCV_SYN" ,"SYN_RCVD"},
    {"LISTEN", "APP_SEND", "SYN_SENT"},
    {"LISTEN", "APP_CLOSE","CLOSED"},
    {"SYN_RCVD","APP_CLOSE","FIN_WAIT_1"},
    {"SYN_RCVD","RCV_ACK","ESTABLISHED"},
    {"SYN_SENT","RCV_SYN","SYN_RCVD"},
    {"SYN_SENT","RCV_SYN_ACK","ESTABLISHED"},
    {"SYN_SENT","APP_CLOSE","CLOSED"},
    {"ESTABLISHED","APP_CLOSE","FIN_WAIT_1"},
    {"ESTABLISHED","RCV_FIN","CLOSE_WAIT"},
    {"FIN_WAIT_1","RCV_FIN","CLOSING"},
    {"FIN_WAIT_1","RCV_FIN_ACK","TIME_WAIT"},
    {"FIN_WAIT_1","RCV_ACK","FIN_WAIT_2"},
    {"CLOSING","RCV_ACK","TIME_WAIT"},
    {"FIN_WAIT_2","RCV_FIN","TIME_WAIT"},
    {"TIME_WAIT","APP_TIMEOUT","CLOSED"},
    {"CLOSE_WAIT","APP_CLOSE","LAST_ACK"},
    {"LAST_ACK","RCV_ACK","CLOSED"}

}; 

static const string err {"ERROR"}; 

string nextState (string state, string action){
    for (auto el : states){
        if (el.curr_state == state && el.trans == action) return el.next_state; 
    }
    return err; 
}

std::string traverse_TCP_states(const std::vector<std::string> &events){
    string state {"CLOSED"}; 
    for (auto ev : events){
       state = nextState(state,ev);
       if (state == err) return err; 
    }   
  return state;
}


int main(int argc, char const *argv[])
{
    // vector<string> States {"APP_PASSIVE_OPEN", "APP_ACTIVE_OPEN", "APP_SEND", "APP_CLOSE", "APP_TIMEOUT", "RCV_SYN", "RCV_ACK", "RCV_SYN_ACK", "RCV_FIN", "RCV_FIN_ACK"}; 
    std::cout << traverse_TCP_states ({"APP_ACTIVE_OPEN","RCV_SYN_ACK","RCV_FIN"}); 
    std::cout << traverse_TCP_states ({"APP_PASSIVE_OPEN","RCV_SYN","RCV_ACK","APP_CLOSE","APP_SEND"}); 
    return 0;
}

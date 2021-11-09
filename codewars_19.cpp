/**
 * https://www.codewars.com/kata/57658bfa28ed87ecfa00058a/train/cpp
 * You are at position [0, 0] in maze NxN and you can only move in one of the four cardinal directions 
 * (i.e. North, East, South, West). Return the minimal number of steps to exit position [N-1, N-1] 
 * if it is possible to reach the exit from the starting position. Otherwise, return -1.
 * Empty positions are marked .. Walls are marked W. Start and exit positions are guaranteed to be empty in all test cases.
 */ 

#include <iostream>
#include <string>
#include <limits>
#include <queue>        // queue

using namespace std;

class Position
{
  public:
    // position x,y and distance to cell 
    Position(int p_x, int p_y, int p_d=0) : x (p_x), y (p_y), d(p_d) {}; 
    int x;
    int y;
    int d = 0;             // distance to here
};

int path_finder(string maze) {
  // TODO: Return the minimal number of steps required to reach the exit located at
  // (n - 1, n - 1) from the initial position (0, 0) in an n × n maze if possible and
  // -1 otherwise
  char graph [UINT8_MAX][UINT8_MAX];
  queue <Position> m_queue;
  int i = 0, j = 0, exit =0, path=-1;

  for (char &c : maze)
  {
    if (c == '\n'){
      i++;
      j = 0;
      continue;
    }
    graph[i][j++] = c;
  }

  exit = i; 

  m_queue.push(Position (0,0));               // enter maze

  while (!m_queue.empty()){
    Position pos = m_queue.front();            // get actual pos
    int x = pos.x , y = pos.y;
    m_queue.pop();                            // remove from queue  
    graph [x][y] = 'W';                       // mark as passed
    
    if (x == y && x == (exit)){                       // check if exit 
      path = pos.d ; break;  
    }
    if ( (x+1 <= exit) &&  graph[x+1][y] != 'W') {m_queue.push(Position(x+1,y,pos.d+1)); graph[x+1][y] = 'W' ;}
    if ( (y+1 <= exit) &&  graph[x][y+1] != 'W') {m_queue.push(Position(x,y+1,pos.d+1)); graph[x][y+1] = 'W' ;}
    if ( (x-1 >= 0) &&  graph[x-1][y] != 'W') {m_queue.push(Position(x-1,y,pos.d+1)); graph[x-1][y] = 'W' ;}
    if ( (y-1 >= 0) &&  graph[x][y-1] != 'W') {m_queue.push(Position(x,y-1,pos.d+1)); graph[x][y-1] = 'W' ;}
    
  }

  return path;
}

int main(int argc, char const *argv[])
{
  Position pos1 {2,4}; 
  Position pos2 {2,5}; 
  
  cout << path_finder (".W.\n.W.\n...") << endl; 
  cout << path_finder (".W.\n.W.\nW..") << endl; 
  cout << path_finder (".") << endl; 
  //cout << (pos1 == pos2) << endl ; 
  return 0;
}

/**
 * https://www.codewars.com/kata/576986639772456f6f00030c/train/cpp
 * 3 Kyu
 * 
 * Task
 * You are at start location [0, 0] in mountain area of NxN and you can only 
 * move in one of the four cardinal directions (i.e. North, East, South, West). 
 * Return minimal number of climb rounds to target location [N-1, N-1]. 
 * Number of climb rounds between adjacent locations is defined as difference 
 * of location altitudes (ascending or descending).
 * Location altitude is defined as an integer number (0-9).
 * 
 * Solution based on Dijkstra algorithm: http://e-maxx.ru/algo/dijkstra
*/

#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

int path_finder(std::string maze)
{
        // create graph
        int N = 0, gSize =0; // maze dimentions   
        vector <int> c_maze; // maze
        
        for (char &c : maze)
        {
                if (c == '\n')
                {
                        N++;
                        continue;
                }
                c_maze.push_back (c - '0'); // convert char to int 
        }
        N++ ; // one more 
        gSize = c_maze.size();
        // for (int i : c_maze) cout << i << " "; 
        // 0 1 0 1 0 1 0 1 0 -- value (c_maze [])
        // 0 1 2 3 4 5 6 7 8 -- index

        struct vertex
        {
                vector <int> nIndx; // neighbors (indexes) 
                vector <int> nDist; // distances (value diff)
        };
        
        // gparh of vertex's
        vector<vertex> graph (gSize);    
        
        for (int i = 0; i < gSize; i++)
        {
                vector <int> indxs; 
                if (i - N >= 0) indxs.push_back(i-N); 
                if (i - 1 >= 0 && (i%N != 0)) indxs.push_back(i-1); 
                if (i + N < gSize) indxs.push_back(i+N); 
                if (i + 1 < gSize && ((i+1)%N != 0)) indxs.push_back(i+1); 

                for (int j : indxs){
                        graph[i].nIndx.push_back(j);
                        int d = c_maze[i] - c_maze[j];
                        d = (d < 0) ? d * (-1) : d; // like abs func
                        graph[i].nDist.push_back(d);
                }
        }

        // now we have the graph constructed, start Dijkstra algor.
        // distance vector. expecte to get solution on last element 
        vector<int> dist (gSize, INT32_MAX);
        // true if passes throug thi vertix 
        vector<bool> mark (gSize, false);         
        dist [0] = 0; 

        for (int i = 0; i < gSize; i++)
        {       
                // search min unmarked 
                int v = -1 ; 
                for (int j = 0; j < gSize; j++) {
                        if (!mark[j] && (v == -1 || dist[j] < dist[v]) )
                                v=j; 
                }
                if (dist[v] == INT32_MAX) break; 
                mark [v] = true;

                // search all vertixes
                vertex &vtx = graph[v];
                for (size_t j = 0; j < vtx.nIndx.size(); j++)
                {
                        int to = vtx.nIndx[j]; 
                        int len = vtx.nDist[j]; 
                        if (dist[v] + len < dist[to])
                                dist[to] = dist[v] + len;  
                }
                
        }

        return dist.back() ;
}

int main(int argc, char const *argv[])
{
        std::string s3 =
            "010\n"
            "101\n"
            "010";
        std::string s2 =
            "010\n"
            "010\n"
            "010";
        cout <<  path_finder (s2) << endl;         
        return 0;
}

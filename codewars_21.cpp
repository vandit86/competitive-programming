/**
 * 6 kyu
 * https://www.codewars.com/kata/58663693b359c4a6560001d6/train/c
 * You will be given a 2D array of the maze and an array of directions. 
 * Your task is to follow the directions given. If you reach the end point 
 * before all your moves have gone, you should return Finish. If you hit 
 * any walls or go outside the maze border, you should return Dead. 
 * If you find yourself still in the maze after using all the moves, 
 * you should return Lost.
 * 
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define START_POINT 2
#define WALL 1
#define SAFE 0
#define FINISH_POINT 3

static const char* FINISH = "Finish"; 
static const char* DEAD = "Dead"; 
static const char* LOST = "Lost"; 

static const char *maze_runner(const int *maze, size_t N, 
                                const char *directions)
{
        // actual position on maze 
        size_t i=0, j=0;
        bool start_found = false; 

        // the lengh of the path
        size_t len = strlen(directions); 
        
        //search Start Point 
        for (i = 0; i < N ; i++)
        {
                for (j = 0; j < N; j++)
                {
                        if (maze[i*N + j] == START_POINT){
                                start_found = true;         
                                break; 
                        }
                }
                if (start_found) break; 
        }

        // go through path  
        for (size_t p = 0; p < len; p++)
        {
                char c = directions[p]; 
                if (c == 'N') i--; 
                if (c == 'E') j++; 
                if (c == 'S') i++; 
                if (c == 'W') j--;
                
                // check out of bounds
                if (i >= N || j >= N || i < 0 || j < 0 || maze[i * N + j] == WALL)
                        return DEAD;

                // check poz on maze
                if (maze[i * N + j] == FINISH_POINT)
                        return FINISH;  
        }

        return LOST; 
}

// test maze 
const int maze[7 * 7] = {1, 1, 1, 1, 1, 1, 1,
                         1, 0, 0, 0, 0, 0, 3,
                         1, 0, 1, 0, 1, 0, 1,
                         0, 0, 1, 0, 0, 0, 1,
                         1, 0, 1, 0, 1, 0, 1,
                         1, 0, 0, 0, 0, 0, 1,
                         1, 2, 1, 0, 1, 0, 1};

const int maze2[5 * 5] = {0, 0, 0, 1, 3,
                        2, 0, 0, 0, 0,
                        0, 0, 1, 0, 1,
                        0, 1, 0, 0, 1,
                        0, 1, 0, 1, 1};

int main(int argc, char const *argv[])
{
        const char *directions = "NNNNNEEEEE"; 
        // const char *c = maze_runner(maze,7, directions); 
        const char *c = maze_runner(maze2,5,"W"); 
        printf ("%s", c) ; 
        /* code */
        return 0;
}

// https://www.codewars.com/kata/609243c36e796b003e79e6b5
// here is solution in python, since .cpp variant of the exersize is broken : 
// I just translate the logic from c++ implementation to python script..

from typing import List, Tuple

def webpolygons(s: List[int]) -> int:
    result = 0
    my_stk = []  # List of tuples (val, position)

    for i in range(len(s)):
        if s[i] == 1:
            if not my_stk:
                continue
            res = 1
            g_res = 0
            val, pos = my_stk.pop()  # Remove from stack

            for j in range(i, pos, -1):
                res *= s[j]

            acc = (val * (val - 1)) // 2 
            for _ in range(acc):
                g_res += res ** 2

            # Multiply values in the stack
            for entry in my_stk:
                g_res *= entry[0]

            result += g_res
        else:
            my_stk.append((s[i], i))

    return result
  

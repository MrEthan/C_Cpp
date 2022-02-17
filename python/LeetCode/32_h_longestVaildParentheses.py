#!/bin/env python3

class N32Stack:
    def longestValidParentheses(self, s: str) -> int:
        if not s:
            return 0
        res = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == "(":
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    res = max(res, i - stack[-1])
        return res


if __name__ == '__main__':
    solution = N32Stack()
    s = ")()())"
    ans = solution.longestValidParentheses(s)
    assert ans == 4
    s = "(()"
    ans = solution.longestValidParentheses(s)
    assert ans == 2
    s = ""
    ans = solution.longestValidParentheses(s)
    assert ans == 0

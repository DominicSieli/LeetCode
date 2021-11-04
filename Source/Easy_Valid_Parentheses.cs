using System;
using System.Collections.Generic;

public class Solution
{
	public bool ValidParentheses(String s)
	{
		if(s.Length % 2 != 0) return false;

		Stack<char> stk = new Stack<char>();

		foreach(char c in s)
		{
			if(c == '(' || c == '[' || c == '{') stk.Push(c);

			if(stk.Count == 0)
			{
				if(c == ')' || c == ']' || c == '}') return false;
			}

			if(stk.Count != 0)
			{
				if(c == ')' && stk.Peek() == '(') stk.Pop();
				else if(c == ')' && stk.Peek() != '(') return false;

				if(c == ']' && stk.Peek() == '[') stk.Pop();
				else if(c == ']' && stk.Peek() != '[') return false;

				if(c == '}' && stk.Peek() == '{') stk.Pop();
				else if(c == '}' && stk.Peek() != '{') return false;
			}
		}

		return !Convert.ToBoolean(stk.Count);
	}
}

public class LeetCode
{
	public static void Main()
	{
		String s = "([}}])";
		Solution solution = new Solution();
		Console.WriteLine(solution.ValidParentheses(s));
	}
}
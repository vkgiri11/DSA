Recursive Approach
*  Every time we meet a '[', we treat it as a subproblem so call our recursive function to get the content in that '[' and ']'. After that, repeat that content for 'num' times.
* Every time we meet a ']', we know a subproblem finished and just return the 'word' we got in this subproblem.
​
Stack Approach
​
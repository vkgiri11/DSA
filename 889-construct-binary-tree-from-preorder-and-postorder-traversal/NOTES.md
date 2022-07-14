The problem is easier to solve if we decrease it into subproblems using Divide and Conquer.
​
e.g.   Given preorder : 1 2 4 5 3 6;     postorder: 4 5 2 6 3 1.
We see it as preorder : 1 (2 4 5) (3 6); postorder: (4 5 2) (6 3) 1 [to be explained afterwards]
That can be decreased to subproblems A, B, C:
A. preorder : 1; postorder: 1 =>
1
B. preorder : (2 4 5); postorder: (4 5 2) =>
2
/ \
4   5
C. preorder : (3 6); postorder: (6 3) =>
3
/
6     or
3
\
6
* Then we conquer the subproblems => A.left = B; A.right = C;
1
/ \
2   3
/ \  /
4  5 6
If we observe parameters in each recursion above:
​
preStart: 0, preEnd: 5, postStart: 0, postEnd: 5
preStart: 1, preEnd: 3, postStart: 0, postEnd: 2
preStart: 4, preEnd: 5, postStart: 3, postEnd: 4
For the commented, [to be explained afterwards], how do we decrease a problem?
That is, 1 is root and 2 is its left child. Since 2 is the root of the left subtree, all elements in front of 2 in post[] must be in the left subtree also.
We recursively follow the above approach.
Please note that pre[preStart + 1] may also be the root of the right subtree if there is no left subtree at all in the orginal tree. Since we are asked to generate one possible original tree, I assume pre[preStart + 1] to be the left subtree root always.
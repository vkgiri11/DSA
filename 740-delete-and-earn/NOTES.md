* We will sort the array, it will help us in getting rid of not taking any element like arr[i] - 1.
* Because after sorting, for a particular element we may only check its next elements whether to include them in our answer or not. As array is already sorted then we know that if arr[i] - 1is present in the array then it is just less index than current element of the array .
* Now suppose we decide to pick a element and include the sum of this element in our array, then upto which point we are able to pick this. We will say the number of points it is repeating in the array till then we are able to pick the element.
* Now, if we pick any element, then we have don't have choices left to pick arr[i] - 1 and arrr[i] + 1elements. Since by doing sorting we already get rid of arr[i] - 1 and now again we skip the all elements which is equal to arr[i] + 1.
* And at last for a particular element when we calculate it's sum, then we have two choices, whether to include it in our answer or to explore more possibility whithout picking it, so we will take the maximum of these two.
​
Let's take an example not given in question -
Suppose our array given to us is like, arr[]: [2,1,1,1,3,2,2,2,7,7,8]
​
So, if we rearranage our array (in increasing order)
it looks like arr[]: [1,1,1,2,2,2,2,3,7,7,8]
​
So, we have many choices to pick, but the most optimal one to pick is
​
- Take all 2 and 7 i.e (2 + 2 + 2 + 2 + 7 + 7) = (22)
Therefore our program should return 22 as our final answer.
​
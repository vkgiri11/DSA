lets take an example. s="catsand" and wordDict = ["cat", "cats", "and", "sand"].
​
The solution starts by taking the string S( "catsand") initially finding whether whole string is present or not . IN this case it is not present in the dict.
​
Now breaking the string and then finding
s.substr( i) gives the substring from ith index till the end. so string word goes as
​
atsand // not present
tsand // not present
​
sand //present then the remainder is calculated which is cat in this case and recursive function is called and same thing is done with cat which will return cat and also store the result in the unordered map . Now comes the combine part where both the string are combined and the pushed in the result " cat sand".
​
and // then comes and which is present so now again wordbreak called on remainder which is cats now and this will return cats. Now both strings are combined and inserted into result . result = {. "cat sand", "cats and"}; Now after the loop ending the result is returned and also stored in map.
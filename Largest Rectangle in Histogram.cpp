/*Problem Description

Given an array of integers A .
A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.
Find the area of the largest rectangle formed by the histogram.

Problem Constraints
1 <= |A| <= 100000
1 <= A[i] <= 1000000000

Input Format: The only argument given is the integer array A.

Output Format: Return the area of largest rectangle in the histogram.

Example Input
Input 1:   A = [2, 1, 5, 6, 2, 3]
Input 2:   A = [2]

Example Output
Output 1:  10
Output 2:  2

Example Explanation
Explanation 1: The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2: Largest rectangle has area 2.
*/

int Solution::largestRectangleArea(vector<int> &A) {
     int n=A.size(),i,j,k,pre[n],nse[n];
        stack<int> s;
        s.push(0);
        pre[0]=-1;
        for(i=1;i<n;i++)
        {
            while(!s.empty() && A[s.top()]>A[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                pre[i]=s.top();
            }
            else
           {
                pre[i]=-1;
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(i=0;i<n;i++)
        {
            while(!s.empty() && A[s.top()]>A[i])
            {
                nse[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            nse[s.top()]=n;s.pop();
        }
        int maxi=0;
        for(i=0;i<n;i++)
        {
            maxi=max(maxi,(nse[i]-pre[i]-1)*A[i]);
        }
        return maxi;
}

vector<int> stringMatch(string text, string pattern) {

    // Write your code here.

    int n1=text.length();

    int n2=pattern.length();

    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

    for(int i=1;i<=n1;i++)

    {

        for(int j=1;j<=n2;j++)

        {

            if(text[i-1]==pattern[j-1])

            {

                dp[i][j]=1+dp[i-1][j-1];

            }

            else

            dp[i][j]=0;

        }

    }

 

    vector<int>res;

    for(int i=0;i<=n1;i++)

    {

        for(int j=0;j<=n2;j++)

        {

            if(dp[i][j]==n2)

            res.push_back(i-n2+1);

        }

    }

    return res;

}

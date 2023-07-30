

int palindromePartitioning(string str)
{
  
    int n = str.size();

  

    int cuts[n];
    bool isPalindrome[n][n];

    int i, j, k, l;  
    for (i = 0; i < n; i++)
    {
        isPalindrome[i][i] = true;
    }

  
    for (l = 2; l <= n; l++)
    {
      
        for (i = 0; i < n - l + 1; i++)
        {
            j = i + l - 1;  
            if (l == 2)
            {
                isPalindrome[i][j] = (str[i] == str[j]);
            }
            else
            {
                isPalindrome[i][j] = (str[i] == str[j]) && isPalindrome[i + 1][j - 1];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (isPalindrome[0][i] == true)
        {
            cuts[i] = 0;
        }
        else
        {
            cuts[i] = INT_MAX;
            for (j = 0; j < i; j++)
            {
                if (isPalindrome[j + 1][i] == true && 1 + cuts[j] < cuts[i]) cuts[i] = 1 + cuts[j];
            }
        }
    }

    return cuts[n - 1];
}

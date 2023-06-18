
int findParent(int x, vector < int > & parent) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = findParent(parent[x], parent);
}

void unionSet(int parentY, int parentX, vector < int > & parent, vector < int > & rank) {
    if (rank[parentY] > rank[parentX]) {
        swap(parentX, parentY);
    }

    parent[parentY] = parentX;

    rank[parentX] = rank[parentX] + rank[parentY];
}

int removeMaxEdges(int n, int m, vector < vector < int >> & edges) {

    vector < int > parentOne(n + 1), parentTwo(n + 1);

  
    vector < int > sizeOne(n + 1), sizeTwo(n + 1);

    for (int i = 1; i <= n; i++) {
        parentOne[i] = i;
        parentTwo[i] = i;
        sizeOne[i] = 1;
        sizeTwo[i] = 1;
    }

    
    vector < int > playerOne[n + 1], playerTwo[n + 1];
    int count = 0;

   
    for (int i = 0; i < m; i++) {
        int x, y, type;
        type = edges[i][0];
        x = edges[i][1];
        y = edges[i][2];

     
        if (type == 1) {
            playerOne[x].push_back(y);
            playerOne[y].push_back(x);
        }

    
        else if (type == 2) {
            playerTwo[x].push_back(y);
            playerTwo[y].push_back(x);
        }

        else {
           
            int parentX = findParent(x, parentOne);
            int parentY = findParent(y, parentOne);

            if (parentX != parentY) {
                unionSet(parentY, parentX, parentOne, sizeOne);
                unionSet(parentY, parentX, parentTwo, sizeTwo);
                count++;
            }
        }
    }
    int countOne = 0;

    for (int i = 1; i <= n; i++) {
        for (int j: playerOne[i]) {
            int x = i, y = j;


            int parentX = findParent(x, parentOne), parentY = findParent(y, parentOne);

            if (parentX != parentY) {
                unionSet(parentY, parentX, parentOne, sizeOne);
                countOne++;
            }
        }
    }

    int countTwo = 0;

    for (int i = 1; i <= n; i++) {
        for (int j: playerTwo[i]) {
            int x = i, y = j;

           
            int parentX = findParent(x, parentTwo), parentY = findParent(y, parentTwo);

           
            if (parentX != parentY) {
                unionSet(parentY, parentX, parentTwo, sizeTwo);
                countTwo++;
            }
        }
    }

    if (countOne + count != n - 1 || countTwo + count != n - 1) {
        return -1;
    }


    return (m - count - countOne - countTwo);
}

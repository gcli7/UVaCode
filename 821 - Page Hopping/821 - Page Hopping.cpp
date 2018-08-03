#include <cstdio>
#include <queue>

using namespace std;

struct Node{
    int num;
    int len;
};

int main(int argc, char **argv) {
    int cases = 1;
    int x = 0;
    int y = 0;

    while(scanf("%d %d", &x, &y) != 0 && x != 0) {
        bool edge[105][105] = {false};
        bool point[105] = {false};
        double sum = 0.0;
        int maxPoint = 0;
        int allPoint = 0;

        do {
            edge[x][y] = true;
            point[x] = true;
            point[y] = true;
            if(x > maxPoint)
                maxPoint = x;
            if(y > maxPoint)
                maxPoint = y;
        } while(scanf("%d %d", &x, &y) != 0 && x != 0);

        for(int i = 1; i <= maxPoint; i++)
            if(point[i])
                allPoint++;

        for(int i = 1; i <= maxPoint; i++) {
            if(!point[i])
                continue;

            queue<Node> traveler;
            Node currentNode = {i, 0};
            Node nextNode;
            bool usedPath[105][105] = {false};
            bool usedPoint[105] = {false};
            int counter = 1;
            
            traveler.push(currentNode);
            usedPoint[i] = true;

            while(counter < allPoint && !traveler.empty()) {
                currentNode.num = traveler.front().num;
                currentNode.len = traveler.front().len;
                traveler.pop();

                for(int j = 0; j <= maxPoint; j++) {
                    if(!point[j])
                        continue;

                    if(edge[currentNode.num][j] && !usedPath[currentNode.num][j]) {
                        nextNode.num = j;
                        nextNode.len = currentNode.len + 1;
                        traveler.push(nextNode);

                        if(!usedPoint[j]) {
                            sum += nextNode.len;
                            counter++;

                            usedPoint[j] = true;
                        }

                        usedPath[currentNode.num][j] = true;
                    }
                }
            }
        }
        printf("Case %d: average length between pages = %.3lf clicks\n", cases++, sum / ( allPoint * ( allPoint - 1 )));
    }

    return 0;
}
#include <cstdio>
#include <algorithm>
int dir[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int mask[4][4];


int set_bit(int m, int i, int j) {
    if(i < 0 || i > 3 || j < 0 || j > 3)
        return m;
    return m & (1 << (4 * i +j));
}
int flip(int m, int i, int j) {
    return m ^ mask[i][j];
}
int get(int m, int i, int j) {
    return (m >> (4*i + j )) & 1;
}

int solve(int m, int flag, int  count) {
    for(int i = 0; i < 3; i++) {
         for(int j = 0; j < 4; j++) {
             if(get(m, i, j) != flag) {
                 m = flip(m, i + 1, j);
                 count++;
             }
         }
    }
    for(int i = 0; i < 4; i++) {
        if(get(m, 4, i) != flag) {
            return 16;
        }
    }
    return count;
}


void print(int m) {
    printf("%s\n", "matrix");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d", get(m, i, j));
        }
        printf("%s", "\n");
    }
}
int main(){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            mask[i][j] = 0;
            for(int k = 0; k < 5; k++){
                mask[i][j] = set_bit(mask[i][j], i + dir[k][0], j + dir[k][1]);
            }
            //printf(" %d", mask[i][j]);
        }
    }
    //printf("%s", "\n");
    char buf[5];
    int m = 0;
    for(int i = 0; i < 4; i++) {
        scanf("%s", buf);
        for(int j = 0; j < 4; j++) {
            m = buf[j] == 'b' ? set_bit(m, i, j) : m;
        }
    }
    //print(m);
    int temp = m;
    int res = 16;
    for(int i = 0; i < 1 << 4; i++) {
        m = temp;
        int count = 0;
        for(int j = 0; j < 4; j++) {
            if(((i >> j) & 1) == 1) {
                count++;
                m = flip(m, 0, j);
            }
        }
        //print(m);
        res = std::min(res, solve(m, 0, count));
        res = std::min(res, solve(m, 1, count));
    }
    if(res == 16) {
        printf("%s\n", "Impossible");
    }else {
        printf("%d\n", res);
    }
    return 0;
}


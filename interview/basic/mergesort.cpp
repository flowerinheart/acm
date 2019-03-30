#include<queue>
int* mergesort(int *data, int n) {
    return mergesort(data, 0, n - 1);
}
int* mergesort(int *data, int b, int e) {
    if(b == e)
        return data;
    int mid =  b + (e - b) / 2;
    int *left = mergesort(data, b, mid);
    int *right = mergesort(data, mid + 1, e);
    int *temp = new int[e - b + 1];
    for(int i = 0, j = 0; i < mid - b + 1 || j < e - mid; ) {
        if(i == mid - b + 1 || (j < e - mid && right[j] <= left[j]))
            temp[i + j] = right[j++];
        else 
            temp[i + j] = left[i++];
    }
    delete []left;
    delete []right;
    return temp;
}



// https://www.youtube.com/watch?v=zamOzeWAOjs&index=29&list=PLJmV-g-E2r5so40XbjXbhklM5krGbqFEq
int* mergesort_stack(int *data, int n) {
    if(n == 0)
        return data;
    int mid =  b + (e - b) / 2;
    int *temp = new int[e - b + 1];
    for(int step = 1; step < n; step *= 2) {

    }
    for(int i = 0, j = 0; i < mid - b + 1 || j < e - mid; ) {
        if(i == mid - b + 1 || (j < e - mid && right[j] <= left[j]))
            temp[i + j] = right[j++];
        else 
            temp[i + j] = left[i++];
    }
    delete []left;
    delete []right;
    return temp;
}
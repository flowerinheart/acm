public class QuickSort {
    // 最简单的优化方法，基准值的选取
    // 第二个优化，当序列长度分割到一定程度改为使用插入排序：
    // 第三个优化，优化递归
    // 最后一个优化是剔除重复元素，是一种特殊化的优化：
    // 划分策略优化（五取样划分）
    // https://blog.csdn.net/modiziri/article/details/21608507
    // VS2010的时候，VS的sort速度竟然是我快排的十倍以上,他是把vector里面的本质萃取出来，取消了vector在++时候的边界检查并且把迭代器当指针来用，所以才会快这么多的。
    // 三数取中法
    // https://www.sczyh30.com/posts/Algorithm/algorithm-quicksort/


    public void quicksort(int[] array) {
        quicksort(array, 0, array.length - 1);
    }
 
    public void quicksort(int[] array, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        int pivot = array[mid];
        // return dividing point of the partition
        int index = partition(array, left, right, pivot);
        quicksort(array, left, index - 1); // sort left side
        quicksort(array, index, right); // sort right side
    }
 
    public int partition(int[] array, int left, int right, int pivot) {
        while(left <= right) {
            while(array[left] < pivot) {
                left++;
            }
            while(array[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(array, left, right);
                left++;
                right--;
            }
        }
        return left;
    }
 
    public void swap(int[] array, int left, int right) {
        int tmp = array[left];
        array[right] = array[left];
        array[left] = tmp;
    }
}


void QuickSortNotR(int* array,int left,int right)
{
    assert(array);
    stack<int> s;
    s.push(left);
    s.push(right);//后入的right，所以要先拿right
    while(!s.empty)//栈不为空
    {
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();

        int index = PartSort(array,left,right);
        if((index - 1) > left)//左子序列
        {
            s.push(left);
            s.push(index - 1);
        }
        if((index) + 1) < right)//右子序列
        {
            s.push(index + 1);
            s.push(right);
        }
    }
}
--------------------- 
作者：清枫若待佳人醉 
来源：CSDN 
原文：https://blog.csdn.net/qq_36528114/article/details/78667034 
版权声明：本文为博主原创文章，转载请附上博文链接！
class Solution {
  private ListNode head;
  //利用函数中自动移动来完成的,思想和共同祖先很像
  private TreeNode convertListToBST(int l, int r) {
    if (l > r) 
      return null;
    if (l == r){
        TreeNode node = new TreeNode(head.val);
        this.head = this.head.next;
        return node;
    }
    int mid = l + (r - l) / 2;
    TreeNode left = this.convertListToBST(l, mid - 1);
    TreeNode node = new TreeNode(this.head.val);
    node.left = left;
    this.head = this.head.next;
    node.right = convertListToBST(mid + 1, r);
    return node;
  }

  public TreeNode sortedListToBST(ListNode head) {
    int c = 0;
    for(ListNode ptr = head; ptr != null; ptr = ptr.next)
        c += 1;
    this.head = head;
    return convertListToBST(0, c - 1);
  }
}
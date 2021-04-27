func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    re := &ListNode{}
    mre := re
    re_mvup := 0

    re_mvup = 0
    for l1 != nil || l2 != nil {
        re_val := re_mvup
        if l1 != nil {
            re_val += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            re_val += l2.Val
            l2 = l2.Next
        }
        re_mvup = re_val / 10
        mre.Next = &ListNode{Val: re_val % 10}
        mre = mre.Next
    }
    if re_mvup != 0 {
        mre.Next = &ListNode{Val: 1}
    }
    return re.Next
}
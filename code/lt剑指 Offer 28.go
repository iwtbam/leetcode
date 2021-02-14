// https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
// dui cheng de er cha shu lcof
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }

    type fp func (*TreeNode, *TreeNode) bool

    var isSame fp

    isSame = func (node1, node2 *TreeNode) bool {
        if node1 == nil && node2 == nil {
            return true
        }

        if node1 == nil || node2 == nil {
            return false
        }

        if node1.Val != node2.Val {
            return false
        }

        return isSame(node1.Left, node2.Right) && isSame(node1.Right, node2.Left)
    }

    return isSame(root.Left, root.Right)
}

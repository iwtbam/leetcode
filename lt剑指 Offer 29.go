// https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
// shun shi zhen da yin ju zhen lcof
func spiralOrder(matrix [][]int) []int {
    dxs := []int{0,1,0,-1}
    dys := []int{1,0,-1,0}

    rows := len(matrix)

    if rows == 0 {
        return []int{};
    }

    cols := len(matrix[0])

    if cols == 0 {
        return []int{}
    }

    res := make([]int, rows * cols)

    vis := make([][]int, rows)

    for i:=0; i < rows; i++ {
        vis[i] = make([]int, cols)
    }

    cx, cy := 0, 0
    vis[cx][cy] = 1
    res[0] = matrix[cx][cy]
    dir, step, size := 0, 1, rows * cols

    for step < size {

        nx, ny := cx + dxs[dir], cy + dys[dir]

        if nx < 0 || ny < 0 || nx >= rows || ny >= cols || vis[nx][ny] == 1{
            dir = (dir + 1) % 4
            continue
        }
        res[step] = matrix[nx][ny]
        vis[nx][ny] = 1
        cx, cy = nx, ny
        step += 1
    }

    return res

}
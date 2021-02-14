// https://leetcode-cn.com/problems/pascals-triangle-ii/
// pascals triangle ii
class Solution {
    public List<Integer> getRow(int rowIndex) {
        int[] rows = new int[rowIndex + 1];
        rows[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            for(int j = i; j >= 1; j--){
                rows[j] = rows[j] + rows[j - 1];
            }
        }

        return Arrays.stream(rows).boxed().collect(Collectors.toList());
    }
}
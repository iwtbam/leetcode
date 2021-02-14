class Solution {
    public int maxNumberOfBalloons(String text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        int[] nums = new int[5];
        for(int i = 0; i < text.length(); i++){
            char ch = text.charAt(i);
            if(ch == 'b')
                nums[0]++;
            else if(ch == 'a')
                nums[1]++;

            else if(ch == 'l')
                nums[2]++;
            else if(ch == 'o')
                nums[3]++;
            else if(ch == 'n')
                nums[4]++;
            else
                continue;
        }
        
        int res = nums[0];
        nums[2] = nums[2] / 2;
        nums[3] = nums[3] / 2;
        for(int i = 1; i < 5; i++)
            res = Math.min(res, nums[i]);

        return res;
    }
}
// https://leetcode-cn.com/problems/search-suggestions-system/
// search suggestions system
class Solution {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<String> items = new ArrayList<>();
        for(String product : products)
            items.add(product);
        Collections.sort(items);
        
        
        List<List<String>> res = new ArrayList<>();
        int L = searchWord.length();
        
        for(int i = 1; i <= L; i++){
            List<String> oRes = new ArrayList<>();
            for(String item: items){
                if(item.length() >= i && item.charAt(i - 1) == searchWord.charAt(i - 1))
                    oRes.add(item);
            }
            
            List<String> temp = new ArrayList<>();
            int Len = Math.min(3, oRes.size());
            for(int j = 0 ; j < Len; j++)
                temp.add(oRes.get(j));
            res.add(temp);
            items = new ArrayList<>(oRes);
        }
        
        return res;
    }
}
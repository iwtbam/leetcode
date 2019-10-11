class Solution {
    
    class Trie {
        class Node {
            Node[] nexts;
            boolean isEnd;
            Node(boolean isEnd){
                this.isEnd = isEnd;
                this.nexts = new Node[26];
            }
        }
        
        private Node root;
        
        public Trie(){
            root = new Node(false);
        }
        
        public void add(String word){
            Node cur = root;
            for(int i = 0; i < word.length(); i++){
                int c = word.charAt(i) - 'a';
                if(cur.nexts[c] == null){
                    cur.nexts[c] = new Node(false);
                }
                cur = cur.nexts[c];
            }
            cur.isEnd = true;
        }
        
        public boolean search(String word, int index, int count){
            Node cur = root;
            for(int i = index; i < word.length(); i++){
                char c = word.charAt(i);
                if(cur.nexts[c - 'a'] == null)
                    return false;
                
                if(cur.nexts[c - 'a'].isEnd){
                    if(i == word.length() - 1)
                        return count >= 1;
                    
                    if(search(word, i + 1, count + 1))
                        return true;
                }
                
                cur = cur.nexts[c - 'a'];
            }
            return false;
        }
        
    }
    
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> res = new ArrayList<String>();
        Arrays.sort(words, new Comparator<String>(){
           public int compare(String s1, String s2){
               return s1.length() - s2.length();
           } 
        });
        
        Trie root = new Trie();
        
        for(String word : words){
            if(root.search(word, 0, 0))
                res.add(word);
            else
                root.add(word);
        }
        
        return res;
    }
}
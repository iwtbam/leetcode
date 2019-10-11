import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Transaction {
    String name;
    String city;
    int time;
    int amount;
    boolean vaild; 

    public String toString(){
        StringBuffer sb = new StringBuffer();
        sb.append(name);
        sb.append(",");
        sb.append(time);
        sb.append(",");
        sb.append(amount);
        sb.append(",");
        sb.append(city);
        return sb.toString();
    }
}


class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        List<Transaction> trans = new ArrayList<>();
        for(String transaction : transactions){
            String[] items = transaction.split(",");
            Transaction tran = new Transaction();
            tran.name = items[0];
            tran.city = items[3];
            tran.time = Integer.parseInt(items[1]);
            tran.amount = Integer.parseInt(items[2]);
            tran.vaild = true;
            trans.add(tran);
        }

        Collections.sort(trans, new Comparator<Transaction>() {
            @Override
            public int compare(Transaction o1, Transaction o2) {
                int cval = o1.name.compareTo(o2.name);
                if(cval == 0){
                    return o1.amount - o2.amount;
                }
                return cval;
            }

        });

        List<String> res = new ArrayList<>();

        for(int i = trans.size() - 1; i >= 0; i--){

            Transaction tran = trans.get(i);

            if(tran.vaild == false){
                continue;
            }

            if(tran.amount > 1000){
                tran.vaild = false;
            }

            for(int j = i - 1; j >= 0; j--){
                Transaction tran2 = trans.get(j);
                if(!tran.name.equals(tran2.name))
                    break;
                if(!tran2.city.equals(tran.city) && Math.abs(tran2.time - tran.time) <= 60){
                    tran.vaild = false;
                    tran2.vaild = false;
                }
            }
        }


        for(Transaction tran:trans){
            if(!tran.vaild)
                res.add(tran.toString());
        }

        return res;
    }
}

class Solution{

    class Complex{
        
        public Complex(){
            this.real = 0;
            this.imag = 0;
        }

        public Complex(String content){
            int pos = content.indexOf('+');
            this.real = Integer.parseInt(content.substring(0, pos));
            String imagStr = content.substring(pos+1);
            if(imagStr.charAt(0) == '-'){
                this.imag = - Integer.parseInt(imagStr.substring(1, imagStr.length() - 1));
            }else{
                this.imag = Integer.parseInt(imagStr.substring(0, imagStr.length() - 1));
            }
        }

        public Complex mul(Complex other){
            Complex res = new Complex();
            res.real = this.real * other.real - this.imag * other.imag;
            res.imag = this.real * other.imag + this.imag * other.real;
            return res;
        }

        public String toString(){
            return this.real.toString() + "+" +this.imag.toString() + "i";
        }

        private Integer real;
        private Integer imag;
    }
    
    public String complexNumberMultiply(String a, String b) {
        return new Complex(a).mul(new Complex(b)).toString();
    }
}
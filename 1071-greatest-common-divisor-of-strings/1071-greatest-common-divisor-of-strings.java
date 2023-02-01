class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if(!(str1+str2).equals(str2+str1))
            return "";
        int gcdLength = gcd(str1.length(),str2.length());
        return str1.substring(0,gcdLength);
    }
    private int gcd(int a,int b){
        return a==0 ? b : gcd(b%a,a);
    }
}
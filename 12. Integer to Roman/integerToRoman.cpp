class Solution {
public:
    string intToRoman(int num) {
        string uints[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundreds[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousands[]={"","M","MM","MMM"};
        return thousands[num/1000%10]+hundreds[num/100%10]+tens[num/10%10]+units[num/1%10];
    }
};
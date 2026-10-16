    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    // 字符 数值
    // I  1
    //    V  5
    // X  10
    //    L  50
    // C  100
    //    D  500
    //    M  1000

    // I 可以放在 V (5) 和 X (10) 的左边，来表示4和9。
    // X 可以放在 L (50) 和 C (100) 的左边，来表示40和90。
    // C 可以放在 D (500) 和 M (1000) 的左边，来表示400和900。

    int main() {
        cin.peek();
        if (cin.peek()>'9'||cin.peek()<'0'){
            int count = 0;
            string s;
            getline(cin,s);
            int i = 0;
            while (i < s.length()){
                switch(s[i]){
                    case 'V': count +=5; break;
                    case 'L' : count += 50; break;
                    case 'D' : count += 500; break;
                    case 'M' : count += 1000; break;
                    case 'I' : 
                        if (i == s.length()-1) {
                            count +=1;
                            break;
                            
                        }
                        else{
                            if (s[i+1] == 'V') {
                                count +=4;
                                i +=1;
                            }
                            else if (s[i+1] == 'X') {
                                count +=9;
                                i +=1;
                            }
                            else count +=1;
                            
                            break;
                            
                            
                        }
                        
                        
                    case 'X' : 
                        if (i == s.length()-1) {
                            count +=10;
                            break;
                        }
                        else{
                            if (s[i+1] == 'L') {
                                count +=40;
                                i +=1;
                            }
                            else if (s[i+1] == 'C') {
                                count +=90;
                                i +=1;
                            }
                            else count +=10;
                            break;
                        }
                        
                    case 'C' : 
                        if (i == s.length()-1) {
                            count +=100;
                            break;
                        }
                        else{
                            if (s[i+1] == 'D') {
                                count +=400;
                                i +=1;
                            }
                            else if (s[i+1] == 'M') {
                                count +=900;
                                i +=1;
                            }
                            else count +=100;
                        }
                        


                        
                }
                i++;
            }
            cout  << count;

        }


        else{
            int n;
            cin >> n;
            string s{};
            int n1 = n / 1000;
            int n2 = n / 100 - 10*n1;
            int n3 = n / 10 - 10*n2 - 100*n1;
            int n4 = n % 10;
            if (n1 != 0){
                string s1 (n1, 'M');
                s +=s1;
            }
            if (n2!=0){
                if (n2 <4) {
                    string s2(n2, 'C');
                    s +=s2;
                }
                else if (n2 == 4) s += "CD";
                else if (n2 == 9) s += "CM";
                else if (n2 >= 5) {
                    s += 'D';
                    string s4_ ((n3-5), 'C');
                    s += s4_;
                }
            }

            if (n3!=0){
                if (n3 < 4) {
                    string s3(n3, 'X');
                    s +=s3;
                }
                else if (n3 == 4) s += "XL";
                else if (n3 == 9) s += "XC";
                else if (n3 >= 5) {
                    s += 'L';
                    string s3_ ((n3-5), 'X');
                    s += s3_;
                }
            }
            if (n4!=0){
                if (n4 <4) {
                    string s4(n4, 'I');
                    s +=s4;
                }
                else if (n4 == 4) s += "IV";
                else if (n4 == 9) s += "IX";
                else if (n4 >= 5) {
                    s += 'V';
                    string s4_ ((n4-5), 'I');
                    s += s4_;
                }
            }

            cout << s;

            
            

        }
        return 0;
    }
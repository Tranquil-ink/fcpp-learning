#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 某宾馆来了四位外宾朋友，他们可能使用中、英、法、日 4 种语言。现已知：
// ，，，，，A．甲、乙、丙各会两种语言，丁只会一种语言；
// B．有一种语言 4 人中有 3 人都会；
// C．甲会日语，丁不会日语，乙不会英语；
//、、、、 D．甲与丙、丙与丁不能直接交谈，乙与丙可以直接交谈；
// E．没有人既会日语，又会法语。
// 请问：甲乙丙丁各会什么语言？



// 甲：4 a
// 乙：b c（！2）
// 丙：d e
// 丁：f（！4）


int main() {
    for (int a = 1; a <4; a++){
        for(int b = 1; b <=3; b++){
            for(int c = b+1; c <=4; c++){
                for(int d = 1; d <=3; d++){
                    for (int e = d+1; e <=4; e++){
                        for (int f = 1; f < 4; f++){
                            bool C = b!=2 && c!=2;
                            bool D = d!=4 && e!=4 && d!=a && e!=a && d!=f && e!=f && (b==d || b==e||c==d||c==e);

                            bool E = a!=3 && (b!=3||c!=4) &&(b!=4||c!=3);
                            bool B = (4==f||a==f) && (b==f||c==f);
                            if(C&&D&&E&&B){
                                cout << a <<' '<<4<<'\n'<< b <<' '<<c<<'\n'<< d <<' '<<e<<'\n'<< f << endl;
                                break;
                            }








                        }
                    }
                }
            }
        }
    }


    return 0;
}
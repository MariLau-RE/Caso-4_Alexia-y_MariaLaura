#include<iostream>
#include<map>
#include<string>
#include <array>
using namespace std;
int grayscale(){
   
   map<string, int*> grayscale;
   int gray1[]={12,12,12};
   int gray2[]={47,47,47};
   int gray3[]={50,50,50};
   int gray4[]={65,65,65};
   int gray5[]={83,83,83};
   int gray6[]={135,135,135};
   int gray7[]={161,161,161};
   int gray8[]={195,195,195};
   int gray9[]={220,220,220};
   int gray10[]={242,242,242};
   grayscale["gray1"] = gray1;
   grayscale["gray2"] = gray2;
   grayscale["gray3"] = gray3;
   grayscale["gray4"] = gray4;
   grayscale["gray5"] = gray5;
   grayscale["gray6"] = gray6;
   grayscale["gray7"] = gray7;
   grayscale["gray8"] = gray8;
   grayscale["gray9"] = gray9;
   grayscale["gray10"] = gray10;

    map <string,int*> :: iterator iter;
   cout<<"keys"<<"  &  "<<"values"<<endl;
   for (iter = grayscale.begin(); iter != grayscale.end(); iter++)
   {
     cout<<(*iter).first<<"    "<<(*iter).second<<"\n";
   }
    return 0;
}

    //0.299 ∙ Rojo + 0.587 ∙ Verde + 0.114 ∙ Azul
    //RGB/25%10
// Online C++ compiler to run C++ program online


/*   

this programe is not best 
it works fine up number 999 may be online their is more
sufficient and easy program availabel  program 



*/





#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    
    int num;
    cout<<"ENTER ANY NUMBER BETWEEN 0 to 999: ";
    cin>>num;
    string result;
    
    /* we use some empty string that are for geting index value in order
    one use one first that means one is in 0 index we use empty string 
    before so one is in index one same fir all 
     */
   string one[] = {"","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
   string tens[] ={ "", "ELEVEN","TWLEVE","THIRTTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTTEEN","NINETEEN" };
 
// strings at index 0 and 1 are not used, they are to
// make array indexing simple

string ten[] = { "", "", "TWENTY", "THIRTY", "FOURTHY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY" , "NINETY" };

//here we check number above 99 to 999
/*   means hundred must be present because three digit number 
when we divide 3 digit number with 100 it fives first number and we
match first difit with string array in one[] and replace with that 
number if 124 /100 = 1 one in one[] string = one
and put hundred after that by default 
then we we modulas that number we get new nunber that is only two digit
because modulas  100 gives last two number and next if where we handle 
tow digit can solve that number  

 */
if(num > 99 && num < 1000 ){

    result = one[num / 100] + " HUNDRAD "; // + ten[num / 100] + " " + one[num % 10] ;
   cout<<result;
   
   //here we get last 2 digits using mod 100
    num %=100;
    if(num==0)
    return 0;
  //  cout<<result;
   
    //cout<<result;
}
//cout<<num<<endl;
 //here 10 % 10 gives zero that may produce earro 
 // saprately check 10 and 0 and assign 10 to ten and 0 to zero 
if(num==10){ 
  result = result +  "TEN";
  
}


if(num==0){
  result =result + "ZERO";
  
}


/*  here our number is 1 digit means 1 - 9 
 mod of 10 gives same number and we replace that with string one[] 
 exaple num is 5 , 5%10= 5 so  one[5 %10] = one[5] so get
 index five value tht is five
  */
if(num >0 && num < 10){
  
    result = one[num % 10 ];
    
}

/*   here we check from 11 - 19 
we do mod to 2 digit it gives second 12 % 10 gives 2 
and replace that with string tens rathere than one[] string 
 // check from 1-9 and 11-19 it works sane 
  
   */
if(num >10 && num < 20){
    result = tens[num % 10 ];
}

/* Here we check from 20 - 99 we have to use ten  string it another 
 string array where forty fifty ... is 
 first we do divide that gives frist number and replace that with 
 word in ten[] string and second we mod 10 that gives second number and replace 
 that with word in one[] sring if number is 45
 ten[45/10 ]=4 and one[45%10]=5 it becomes ten[4] + " " + one[5] and 
 replace that index value with words in Corresponding string 
 in beetwen we use simple space to sapreate wores  
    */

if(num >= 20 && num < 100){
      
       result = ten[num /10] + " " + one[ num % 10];
       
}


//hsere we prints orginal word 

cout << result << endl;
    return 0;

}
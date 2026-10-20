

#include <iostream>
#include <stack>
using std::cout, std::string, std::endl, std::stack;

string Check_expression(string expr){
    // your code 
    //. ..
    //..
    // return "Valid";
    return "invalid";
}

int main(){

    string E1 = "A + (C / D)";
    string E2 = "A + (C / D) - ( E ] "; // invalid
    

    cout << "Expression " << E1 << " is : "
        << Check_expression(E1) << endl;



}

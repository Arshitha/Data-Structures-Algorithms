#include <iostream>
#include "MyBloomFilter.h"

using namespace std;

int main(){
    string my_str = "aab";
    string my_str1 = "arshi";
    /*string fake_my_str1 = "shruthi   annapoorna maddy deepthi akand shailya";
    string fake_my_str4 = " Akand Arshitha sitra Akshara Karan";
    string fake_my_str2 ="skfkdhfks";
    string fake_my_str3 = "skfjslaeieiie";
    string my_str2 = "shruthi annapoorna maddy deepthi akand shailya";
    string my_str4 = "Arshitha Akand Akshara Karan";
    string my_str5 = "Arshitha";
    string my_str6 = "Akand";
    string my_str7 = "Akshara";
    string my_str8 = "Karan";*/
    

    
    /* Try different sizes here */
    MyBloomFilter my_filter(5);
    
    cout << "My empty filter looks like: " << my_filter.output() << endl;
    
    my_filter.insert(my_str);
    cout << "Inserting " << my_str << endl;
    cout << "My filter now looks like: " << my_filter.output() << endl;

    my_filter.insert(my_str1);
    cout << "Inserting " << my_str1 << endl;
    cout << "My filter now looks like: " << my_filter.output() << endl;

    /*my_filter.insert(my_str2);
    cout << "Inserting " << my_str2 << endl;
    cout << "My filter now looks like: " << my_filter.output() << endl;

    my_filter.insert(my_str4);
    cout << "Inserting " << my_str4 << endl;
    cout << "My filter now looks like: " << my_filter.output() << endl;

    my_filter.insert(my_str5);
    cout << "Inserting " << my_str5 << endl;
    cout << "My filter now looks like: " << my_filter.output() << endl;

    my_filter.insert(my_str6);
    cout << "Inserting " << my_str2 << endl;
    cout << "My filter now looks like: " << my_filter.output() << endl;

    my_filter.insert(my_str7);
    cout << "Inserting " << my_str2 << endl;
    cout << "My filter now looks like: " << my_filter.output() << endl;

    my_filter.insert(my_str8);
    cout << "Inserting " << my_str2 << endl;
    cout << "My filter now looks like: " << my_filter.output() << endl;*/


    
    cout << "Is " << my_str << " in my filter? ";
    if (my_filter.exists(my_str)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << my_str1 << " in my filter? ";
    if (my_filter.exists(my_str1)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    /*cout << "Is " << my_str2 << " in my filter? ";
    if (my_filter.exists(my_str2)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << my_str4 << " in my filter? ";
    if (my_filter.exists(my_str4)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << my_str5 << " in my filter? ";
    if (my_filter.exists(my_str5)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << my_str6 << " in my filter? ";
    if (my_filter.exists(my_str6)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << my_str7 << " in my filter? ";
    if (my_filter.exists(my_str7)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << my_str8 << " in my filter? ";
    if (my_filter.exists(my_str8)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;*/
    
    string fake_str = "bab";
    cout << "Is " << fake_str << " in my filter? ";
    if (my_filter.exists(fake_str)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    /*cout << "Is " << fake_my_str1 << " in my filter? ";
    if (my_filter.exists(fake_my_str1)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << fake_my_str2 << " in my filter? ";
    if (my_filter.exists(fake_my_str2)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << fake_my_str3 << " in my filter? ";
    if (my_filter.exists(fake_my_str3)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;

    cout << "Is " << fake_my_str4 << " in my filter? ";
    if (my_filter.exists(fake_my_str4)) cout << "\t\tYes." << endl;
    else cout << "\t\tNo." << endl;*/
}

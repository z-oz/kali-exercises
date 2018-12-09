//Zubeyir Ozdemir

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
    char option;
    system("clear");
    cout << "Network Security Commands" << endl;
    cout << "=========================" << endl;


    cout << "1. Display Current firewall Configuration" << endl;
    cout << "2. Block All Outgoing traffic by protocol port Number" << endl;
    cout << "3. Block Outgoing traffic by URL" << endl;

    cout << "Enter an option" << endl;
    cin >> option;
    
    switch (option)
    {
        case '1':
            system("iptables -L");
            break;
        case '2':
            {
                string portnumber, mystr;            
                cout << "Enter the Protocol Port Number" << endl;
                cin >> portnumber;
                mystr = "iptables -A OUTPUT -p tcp --dport " + portnumber + " -j DROP";
    
                system(mystr.c_str());
            }
            break;
        case '3':
            {
                string url, mystr2;            
                cout << "Enter the URL Address" << endl;
                cin >> url;
                mystr2 = "iptables -A OUTPUT -m string --string " + url + " --algo kmp -j DROP";
    
                system(mystr2.c_str());
            }
            break;

    }


    return 0;
}
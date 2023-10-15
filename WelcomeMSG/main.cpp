// Super Complicated IO Example

#include <iostream>
#include <string>

using namespace std;

class WelcomeMessenger{
    	public:
        WelcomeMessenger(string welcomeToWhat)
        : mWelcomeToWhat(welcomeToWhat){

        }
        string greeting(string whom){
            return string("Hello, ") + whom + ", welcome to "
            + mWelcomeToWhat + "!";
        }
        private:
        string mWelcomeToWhat;
};

int main(){
    WelcomeMessenger msg("C++ World");
    cout << msg.greeting("Mary") << endl;
    cout << msg.greeting("John") << endl;
    return 0;
}
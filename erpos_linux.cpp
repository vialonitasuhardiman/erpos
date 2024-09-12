#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

bool priv = false;
int hackednum = 0;

//sheesh, using namespaces is old
using namespace std;

void printg();
void compiler();
void autoexploit();
string ipgen();
void bios();
void beacon();
void vcc();
void home();
string generateVisaCreditCardNumber();
void beaconbuy();
void system();

string generateVisaCreditCardNumber() {
    int cardNumber[16];
    cardNumber[0] = 4; // Visa card numbers start with 4

    // Generate the next 14 digits randomly
    for (int i = 1; i < 15; i++) {
        cardNumber[i] = rand() % 10;
    }

    // Calculate the last digit using the Luhn algorithm
    int sum = 0;
    for (int i = 0; i < 15; i++) {
        int digit = cardNumber[i];
        if ((i % 2 == 1)) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }
        sum += digit;
    }
    cardNumber[15] = (10 - (sum % 10)) % 10; // Ensure the number is valid according to Luhn

    // Convert the array to a string
    string cardNumberStr;
    for (int i = 0; i < 16; i++) {
        cardNumberStr += to_string(cardNumber[i]);
        if ((i + 1) % 4 == 0 && i < 15) {
            cardNumberStr += " "; // Add space every 4 digits for readability
        }
    }

    return cardNumberStr;
}

void beaconbuy() {
    string numer;
    string numa;
    cout << "Type how much bitcoin do you want to buy (max. 20)" << endl;
    getline(cin, numer);
    int num = stoi(numer);
    if (num > 20) {
        cout << "Sorry but the number is bigger than 20!" << endl;
	home();
    }
    cout << "Please type your credit card details" << endl;
    getline(cin, numa);
    cout << "Thanks, " << num << " Bitcoin will be added shortly!" << endl;
    hackednum+=num;
    home();
}

void vcc() {
    cout << "\033[32m" << "Accessing visa.localhost.co" << "\033[0m" << endl;
    usleep(2000000);
    cout << "\033[32m" << "Searching for database breaches..." << "\033[0m" << endl;
    usleep(3000000);
    cout << "\033[32m" << "Recieving unusual traffic from localhost:3972" << "\033[0m" << endl;
    usleep(2000000);
    cout << "\033[32m" << "Casting string literal to integers..." << "\033[0m" << endl;
    usleep(1000000);
    cout << "\033[32m" << "Reading the data..." << "\033[0m" << endl;
    usleep(1000000);
    cout << "\033[32m" << "Generated cards :" << "\033[0m" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\033[32m" << generateVisaCreditCardNumber() << "\033[0m" << endl;
    }
    home();
}

void compiler() {
    bool running = true;
    //code here you clown
    int packet = 0;
    cout << "\033[32m" << "Initiliazing compiler" << "\033[0m" << endl;
    usleep(2000000);
    cout << "\033[32m" << "Invoking /linux/compiler/distro/compiler.sh..." << "\033[0m" << endl;
    usleep(3000000);
    cout << "\033[32m" << "Recieving packets from localhost:1983" << "\033[0m" << endl;
    usleep(2000000);
    cout << "\033[32m" << "Casting the packets to integer" << "\033[0m" << endl;
    usleep(1000000);
    cout << "\033[32m" << "Initializing point to connect to localhost::tor/darkweb.php..." << "\033[0m" << endl;
    usleep(2000000);
    cout << "\033[32m" << "328 bytes of payload downloaded!" << "\033[0m" << endl;
    usleep(2000000);
    while (running == true) {
        cout << "\033[32m" << "Packets recieved : " << packet << "\033[0m" << endl;
	    packet+=3;
	    usleep(10000);
	    if (packet >= 1000) {
                running = false;
	    };
    };
    cout << "\033[32m" << "Downloaded bankinfo.bin!" << "\033[0m" << endl;
    cout << "\033[32m" << "Purchased 10 bitcoin from bankinfo.bin" << "\033[0m" << endl;
    hackednum+=10;
    home();
}

void printg(const string& x) {
    cout << "\033[32m" << x << "\033[0m" << endl;
}

void system(const string& xer)
{
    string command = xer;
    int status = system(command.c_str());
    if (status == -1) {
        perror("system");
        exit(EXIT_FAILURE);
    }
}

string ipgen() {
  string ip;

  // Generate 4 random numbers between 0 and 255
  int octet1 = rand() % 256;
  int octet2 = rand() % 256;
  int octet3 = rand() % 256;
  int octet4 = rand() % 256;

  // Convert the numbers to strings and concatenate them with dots
  ip += to_string(octet1) + ".";
  ip += to_string(octet2) + ".";
  ip += to_string(octet3) + ".";
  ip += to_string(octet4);

  return ip;
}

// home console
void home() {
    string x;
    cout << "\033[32m" << "< " << "\033[0m";
    getline(cin, x);
    if (x == "opensweep -scan") {
        for (int i = 0; i < 10; i++) {
            printg(ipgen());
        }
	home();
    } else if (x == "opensweep") {
        printg("Error : Command Not Found, use -help flag to see avaliable flags.");
	home();
    } else if (x == "opensweep -help") {
        printg("Avaliable flags :");
	printg("-help = see avaliable flags");
	printg("-autoexploit = see latest security vurnability on a target and exploit it");
	printg("-scan = scan all avaliable ip adresses");
	home();
    } else if (x == "help") {
	    printg("Commands :");
	    printg("A text editor");
	    printg("opensweep = a service designed to hack internet devices");
	    printg("compiler = recieves byte from localhost and downloads it");
	    printg("help = display's avaliable commands");
	    printg("clear = clearscreen");
	    printg("ls = list files in directory");
	    printg("cd = go to the directory");
	    printg("vcc = generate credit cards");
	    printg("beacon = a web3 based wallet designed to hold bitcoin securly");
	    printg("exit = poweroff");
	    home();
    } else if (x == "clear") {
            system("clear");
            string x = R"(
    ______              ____  _____
   / ____/________     / __ \/ ___/
  / __/ / ___/ __ \   / / / /\__ \ 
 / /___/ /  / /_/ /  / /_/ /___/ / 
/_____/_/  / .___/   \____//____/  
          /_/                      
)";
            printg(x);
            printg("Welcome to Erp OS! Type help if your new.");
	    if (priv == true) {
	        cout << "\033[1;31m" << "Root access gained!" << "\033[0m" << endl;
	    }
            home();
    } else if (x == "ls") {
	    printg("Exploit.asm");
	    home();
    } else if (x == "opensweep -autoexploit") {
	    autoexploit();
    } else if (x == "exit") {
	    system("clear");
	    exit(0);
    } else if (x == "compiler") {
	    compiler();
    } else if (x == "beacon") {
	    beacon();
    } else if (x == "beacon -buy") {
	    beaconbuy();
    } else if (x == "vcc") {
	    vcc();
    } else if (x == "su") {
	    cout << "\033[1;31m" << "Root accesses gained!" << "\033[0m" << endl;
	    priv = true;
	    home();
    } else {
        home();
    }
  //}
}

void beacon() {
    if (priv == false) {
        cout << "\033[32m" << "Sorry, but this action requires root privellages, to gain root privellage, please type su on the terminal!" << "\033[0m" << endl;
	home();
    } else if (priv == true) {
	cout << "\033[32m" << "Bitcoin : " << hackednum << "\033[0m" << endl;
	cout << "\033[32m" << "Pro tip : type beacon -buy to buy bitcoin with credit cards" << "\033[30m" << endl;
	home();
    }
}

void autoexploit() {
    printg("Type in the ip adress to exploit!");
    string x;
    cout << "\033[32m" << "" << "\033[0m";
    getline(cin, x);
    printg("Identifiying device fingerprint.");
    usleep(5000000);
    printg("Searching exploit in database...");
    usleep(1000000);
    printg("Device hacked sucsesfully, added to botnet and mined 1 bitcoin!");
    hackednum+=1;
    home();
}

void bios() 
{
    printg("Invoking /boot/boot-files/start.sh");
    usleep(2000000);
    printg("Generating cache");
    usleep(1000000);
    printg("Starting Erp OS");
    usleep(5000000);
    system("clear");
}

int main() {
    system("clear");
    bios();
    string x = R"(
    ______              ____  _____
   / ____/________     / __ \/ ___/
  / __/ / ___/ __ \   / / / /\__ \ 
 / /___/ /  / /_/ /  / /_/ /___/ / 
/_____/_/  / .___/   \____//____/  
          /_/                      
)";
    printg(x);
    printg("Welcome to Erp OS! Type help if your new.");
    home();
    return 0;
}

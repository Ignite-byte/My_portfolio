#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

class quiz 
{
public:
    virtual void display() = 0; // Pure virtual function
    // Operator overloading to make the object callable
    void operator()() 
    {
        cout << "Quiz object called as a function!" << endl;
    }
};

class login : public quiz 
{
private:
    string username;
    friend class studentdata; // Friend class
    string email;
public:
    template<typename t>
    t displaymessage(t message) // template function
    {
        cout << message << endl;
    }
    virtual void enterdata() // virtual function
    {
        cout << "\n***Please login or Sign-up***" << endl;
        cout << "Enter Username=";
        cin >> username;
        cout << "Enter email=";
        cin >> email;
    }
    void display() //override Pure virtual function override
    {
        cout << "\nClick Login to continue..." << endl;
    }
    // Constructor overloading
    login() {}
    login(string un, string em) 
    {
        username = un;
        email = em;
    }
};

class details : public quiz 
{
public:
    void disdet() 
    {
        cout << "General Knowledge Quiz(2024)" << endl;
        cout << "Date : 1-7-2021\t\t\tCourse Code : GK-190" << endl;
        cout << "Starting Time: 9:00 AM\t\tEnding Time: 10:00 AM" << endl;
    }
    void display()   // pure
    {
        cout << "***Quiz Details***" << endl;
    }
};

class studentdata : public login 
{
public:
    int rollno;
    void enterdata() //override virtual function 
    {
        cout << "Name: ";
        cin >> username;
        cout << "Roll Number: ";
        cin >> rollno;
    }
    void display()  
    {
        cout << "\n***Enter Personal Information***" << endl;
    }
};

class question : public virtual quiz 
{
public:
    int c;
    int b;
    string ans;
    question() : c(0), b(0) {}
    question(int c, int b) 
    {
        this->c = c;  // This pointer is used when data member and member function parameter are same
        this->b = b;
    }

    int takequestion() 
    try
    {
        cout << "\n ANSWER THE FOLLOWING MULTIPLE CHOICE QUESTION: (Total marks:12)" << endl;
        cout << "\n1- What is the highest mountain in the world?" << endl;
        cout << "\nA:K2\t\t B:Everest \nC:Himalaya\t D:Karakurum\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
        {
            throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "b") || (ans == "B")) 
        {
            cout << "CORRECT" << endl;
            c++;
        } 
        else 
        {
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n2- Who Translated Holy Quran in Persian? " << endl;
        cout << "\nA: Shah Wali Ullah\t\t B:Sheikh Abdul Qadir Jillani \nC:Hazrat Majdad Alif Sani\t D:None of these\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "a") || (ans == "A")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n3- In which country is the volcano Mount Aso? " << endl;
        cout << "\nA:China\t\t B:Japan \nC:South Koera\t D:Singapor\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "b") || (ans == "B")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n4- Which Bank has give First loan in Millions to Pakistan government at the time independence? " << endl;
        cout << "\nA:MCB Bank\t\t B:National Bank \nC:UBL Bank\t\t D:HBL Bank\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "D") || (ans == "d")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n5- Who inaugurated 'World Teachers' Day? " << endl;
        cout << "\nA:UN\t\t B:SAARC \nC:UNESCO \t D:None\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "C") || (ans == "c")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n6- The 2017 World Animal Day (WAD) is observed on which date? " << endl;
        cout << "\nA:6 May\t\t B:3 Apirl \nC:9 September\t D:4 October\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "d") || (ans == "D")) {
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n7- World Teachers' Day is celebrated on: " << endl;
        cout << "\nA:15 May\t\t B:5 October \nC:20 November\t\t D:28 July\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "b") || (ans == "B")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n8- When was the term (United Kingdom) first used? \n";
        cout << "\nA:1830\t\t B:1812 \nC:1800\t\t D:1810\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "C") || (ans == "c")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n9- The Oldest University in the World is? " << endl;
        cout << "\nA:University of Bologna\t\t B:Haward University \nC:Oxford University\t\t D:Manchaster Unversity\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "a") || (ans == "A")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n10- What is the Captial of Japan? \n";
        cout << "\nA:kyoto\t\t B:Yokohama \nC:Tokyo\t\t D:Osaka\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "c") || (ans == "C")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        cout << "\n11- Ex-state of Amb is famous for: " << endl;
        cout << "\nA:Natural Forests\t\t B:Artificial Forests \nC:Tidal Forests \t\t D:Beta Forests\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw invalid_argument("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "A") || (ans == "a")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        
        cout << "\n12- The Air line Qantas belongs to which country? " << endl;
        cout << "\nA:Qatar\t\t\tB:Turkey \nC:Newzland \t\tD:Australias\n" << endl;
        cin >> ans;
        if (!(ans == "b" || ans == "B" || ans == "c" || ans == "C" || ans == "a" || ans == "A" || ans == "d" || ans == "D")) 
		{
                throw /*invalid_argument*/("Invalid input. Please enter A, B, C, or D.");
        }
        if ((ans == "d") || (ans == "D")) 
		{
            cout << "CORRECT" << endl;
            c++;
        } 
		else 
		{
            cout << "WRONG" << endl;
            b++;
        }
        return c;
    }
    
    catch (const invalid_argument& e) 
    {
        cout << "Invalid input: " << e.what() << endl; // Return an error code
    }

    void checkresult() 
    {
        cout << "\nNumber of correct answer is =" << c << endl;
        cout << "Number of wrong answer is =" << b;
    }

    void display()  
    {
        cout << "\nTaking Quiz..." << endl;
    }
};

class score : public virtual quiz, public virtual question 
{
public:
    void givescore(int ca) 
    {
        if (ca >= 10)
            cout << "\nYou are awarded Grade A+";
        else if (ca >= 7)
            cout << "\nYou are awarded Grade A";
        else if (ca >= 5)
            cout << "\nYou are awarded Grade B";
        else if (ca >= 3)
            cout << "\nYou are awarded Grade C";
        else 
            cout << "\nYou are awarded Grade F";
    }

    void display()  
    {
        cout << "\n\nCalculating Score..." << endl;
    }
};

class prize : public virtual quiz, public virtual question 
{
public:
    void giveprize(int ca) 
    {
        if (ca == 12)
            cout << "\nCongratulations! You won the First Prize^^";
        else if (ca == 11)
            cout << "\nCongratulations! You won the Second Prize^^";
        else if (ca == 10)
            cout << "\nCongratulations! You won the Third Prize^^";
        else if (ca == 9 || ca == 8)
            cout << "\nYou need to work Hard and Improve~";
        else
            cout << "\nPease pay Attention to your studies!";
    }

    void display()  
    {
        cout << "\n\nCalculating Prize..." << endl;
    }
};

class share : public quiz 
{
public:
    void sharequiz() 
    {
        cout << "\n\nClick the button to share your results";
        cout << "\nExplore more quiz on our website www.sne.com";
    }

    void display()  
    {
        cout << "\nThe End..." << endl;
    }
};

class finalresult : public score, public prize 
{
public:
    void display() 
    {
        cout << "\n\nDisplaying Final Results..." << endl;
    }
};

int main() 
{
    login l;
    login l2("username", "email"); // Calls the parameterized constructor
    l.displaymessage("\t\t\tWELCOME! THANK YOU FOR VISITING SNE QUIZ MANAGEMENT SYSTEM"); // Accessing template function 
    login* lg = new login();
    lg->enterdata();
    lg->display();
    delete lg;

    for (int i = 1; i <= 30; i++) 
    {
        cout << "**";
    }
    cout << endl;

    details d;
    d.display();
    d.disdet();

    studentdata* sd = new studentdata();
    sd->display();
    sd->enterdata();
    delete sd;

    for (int i = 1; i <= 30; i++) 
    {
        cout << "**";
    }
    cout << endl;

    question qq;
    qq.display();
    int ca = qq.takequestion();
    qq.checkresult();

    finalresult f;
    f.display();
    f.givescore(ca);
    f.giveprize(ca);

    share sh;
    sh.sharequiz();
    sh.display();
    // Using the operator() overload to call the quiz object as a function
    qq();
    f();
	sh();

    return 0;
}

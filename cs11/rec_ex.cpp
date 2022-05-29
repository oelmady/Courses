/*
 *  Classic recursion examples:  factorial and fibonacci.
 *  Also illustrates a way to build a simple extensible test suite, 
 *  but introductory students can skip that code.
 *
 *  Functions with "Iter" in their names are iterative:  they use loops.
 *  Functions with "Rec"  in their names are recursive:  they call themselves.
 *  Functions with "Tail" in their names start a tail recursion.
 *
 *  Tail recursive functions often need an initial state to start with, and
 *  so the Tail functions are not themselves recursive; they make a tail call
 *  to a tail recursive helper function, whose name has "Helper" in it.
 *
 *  Mark A. Sheldon, Tufts University, Fall 2013
 *
 *  Fall 2014:  added fibTail()
 *
 */
#include <iostream>

#include <cstring>

using namespace std;


// Assumes i >= 0
int factIter(int n)
{
        int result = 1;

        while (n > 0) {
                result *= n;
                --n;
        }
        return result;
}

// Assumes i >= 0
int factRec(int n)
{
        if (n == 0)
                return 1;
        else
                return n * factRec(n - 1);
}

int factTailHelper(int n, int result)
{
        if (n == 0)
                return result;
        else
                return factTailHelper(n - 1,
                                      n * result);
}

int factTail(int n)
{
        return factTailHelper(n, 1);
}

int fibIter(int n)
{
        if ((n == 0) || (n == 1))
                return n;
        int i = 2, fib_i_minus_2 = 0, fib_i_minus_1 = 1, fib_i = 1;

        while (i != n) {
                fib_i_minus_2 = fib_i_minus_1;
                fib_i_minus_1 = fib_i;
                fib_i = fib_i_minus_2 + fib_i_minus_1;
                ++i;
        }
        return fib_i;
}

// Assumes n >= 0
int fibRec(int n)
{
        // For fun, uncomment the following line
        cerr << "called fibRec(" << n << ")\n";
        if (n == 0)
                return 0;
        else if (n == 1)
                return 1;
        else
                return fibRec(n - 1) + fibRec(n - 2);
}

int fibTailHelper(int n, int i, int fib_i_minus_1, int fib_i_minus_2)
{
        int fib_i = fib_i_minus_1 + fib_i_minus_2;
        
        // For fun, uncomment the following line
        cerr << "called fibTailHelper(" << n << ", " << i << ", ...)\n";
        if (i == n)
                return fib_i;
        else
                return fibTailHelper(n, i + 1, fib_i, fib_i_minus_1);
}

int fibTail(int n)
{
        if (n == 0)
                return 0;
        else if (n == 1)
                return 1;
        else
                return fibTailHelper(n, 2, 1, 0);
}

// exponent >= 0
int pow(int base, int exponent)
{
        if (exponent == 0)
                return 1;
        else
                return base * pow(base, exponent - 1);
}

static struct {
        string function_name;
        int    (*function)(int n);
} command_table[] = {
        {"factIter", factIter},
        {"factRec",  factRec},
        {"factTail", factTail},
        {"fibIter",  fibIter},
        {"fibRec",   fibRec},
        {"fibTail",  fibTail},
        {"", NULL}
};


string get_cmd();
int    get_n();
void   call_command(string command, int n);
void   print_result(string function_name, int n, int result);

int main()
{
        string cmd;
        int    n;
        
        for (cmd = get_cmd(); cmd != "quit"; cmd = get_cmd()) {
                n = get_n();
                call_command(cmd, n);
        }
        return 0;
}

void print_result(string function_name, int n, int result)
{
        cout << endl
             << function_name << "(" << n << ")" << " => " << result
             << endl << endl;
}

int get_n()
{
        int n;

        // As long as we don't get a valid integer, clear the flags,
        // ignore input up to an end of line, and try again.
        for (cin >> n; cin.fail(); cin >> n) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid integer:  ";
        }
        return n;
}

string get_cmd()
{
        string command;
        cout << "command n\n"
             << "where command is one of:\n";
        for (int i = 0; command_table[i].function_name != ""; ++i)
                cout << "\t" << command_table[i].function_name << endl;
        cout << endl
             << "\tquit\n"
             << endl
             << "  :  ";
        cin  >> command;
        return command;
}

void call_command(string command, int n)
{
        int i;

        // Last element in table is "", which is not equal to any 
        // command.
        for (i = 0; command_table[i].function_name != ""
                     && command_table[i].function_name != command;
             ++i)
                ;

        if (command_table[i].function != NULL)
                print_result(command, n, command_table[i].function(n));
        else
                cerr << "Command not found:  " << command << endl << endl;
}
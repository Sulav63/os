#include <iostream>
#include <unistd.h>  // for fork()
#include <sys/wait.h>  // for wait()

using namespace std;
int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    pid_t pid = fork();
    if (pid < 0) {
        // Fork failed
        cerr << "Fork failed!" << endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        int product = num1 * num2;
        cout << "Child process:\n";
        cout << "Product of " << num1 << " and " << num2 << " is " << product << endl;
    } else {
        // Parent process
        wait(NULL);  // Wait for the child process to complete
        int sum = num1 + num2;
        cout << "Parent process:\n";
        cout << "Sum of " << num1 << " and " << num2 << " is " << sum << endl;
    }
    return 0;
}


/*
Sai is working on a mini project where he needs to handle various tasks related to a bank account. This includes 6 operations viz., read, credit, debit, abort, rollback and commit. The operation semantics are explained below.

read - read and print the balance in the account

credit - money credited to the account

debit - money debited from the account

abort X - the Xth transaction from the beginning is aborted (cancelled). Note that you can't abort the transactions once they are committed. Only credit and debit operations are counted as transactions

For understanding abort, lets understand the example below -

credit 1000

commit

abort 1

This abort cannot be done since the transaction has already been committed.

rollback X - rollback the Xth commit. In this case, the account balance will be automatically updated to what it was, right after the Xth commit.

commit - the changes are saved permanently and cannot be undone using an abort command.

The credit, debit, abort and rollback operations will always be followed by a positive integer, whereas read and commit operations have no such operand.

Given the initial balance and a sequence of operations performed in order, determine the resulting output.

Constraints
1 <= initial amount <= 1000

1 <= Number of operations (N) <= 50

Current account balance will always be 0 or a positive value. It can never be negative.

The integer following "abort" and "rollback" will be at least 1 and will not exceed the total number of transactions and commits up to that point, respectively.

Input
The first line contains an integer denoting the initial balance of the account.

Second line consists of an integer N denoting the number of operations performed.

The subsequent N lines will contain operations following the above syntaxes.

Output
Output the account balance each time a read statement is encountered.

Time Limit (secs)
1

Examples
Example 1

Input

90

8

read

credit 10

debit 12

debit 8

credit 7

abort 1

commit

read

Output

90

77

Explanation

Initial balance: 90

Operation 1 - Read, prints the account balance i.e., 90

Operation 2 - Credit 10, Result: Balance increases by 10. New balance: 100

Operation 3 - Debit 12, Result: Balance decreases by 12. New balance: 88

Operation 4 - Debit 8, Result: Balance decreases by 8. New balance: 80

Operation 5 - Credit 7, Result: Balance increases by 7. New balance: 87

Operation 6 - Abort 1, this means undoing the changes made by the 1st transaction (the credit of 10). So, the account balance will become 77

Operation 7 - Commit, this commits all previous changes made. Account balance will be updated as 77

Operation 8 - Read, prints the account balance i.e., 77

Example 2

Input

43

10

credit 12

debit 10

commit

abort 1

read

credit 30

debit 4

rollback 1

commit

read

Output

45

45

Explanation

Initial balance: 43

Operation 1 - Credit 12, Result: Balance increases by 12. New balance: 55

Operation 2 - Debit 10, Result: Balance decreases by 10. New balance: 45

Operation 3 - Commit, this commits all changes made so far. Account balance will become 45.

Operation 4 - Abort 1, this means undoing the changes made by the 1st transaction. Since the changes of 1st transaction has already been committed it's impossible to abort it. Hence, the account balance remains same.

Operation 5 - Read, prints the account balance i.e., 45

Operation 6 - Credit 30, Result: Balance increases by 30. New balance: 75

Operation 7 - Debit 4, Result: Balance decreases by 4. New balance: 71

Operation 8 - Rollback 1, this means the account balance will be rolled back to what it was, after commit 1 i.e., 45. Refer Operation 3 which is the 1st commit.

Operation 9 - Commit, this commits all changes made since the last commit. Account balance will be updated as 45

Operation 10 - Read, prints the account balance i.e., 45
*/ 

#include <iostream>
#include <string>
using namespace std;

void handleBankOperations(int initialBalance, int numOperations) {
    int balance = initialBalance;        // Current account balance
    int commitBalances[50] = {0};        // Store balances after each commit
    int commitCount = 0;                 // Number of commits
    int transactions[50] = {0};          // Store transaction amounts
    int transactionCount = 0;            // Number of uncommitted transactions

    for (int i = 0; i < numOperations; ++i) {
        string operation;
        getline(cin, operation);

        if (operation == "read") {
            cout << balance << endl;     // Output the current balance
        } else if (operation.substr(0, 6) == "credit") {
            int amount = stoi(operation.substr(7));
            balance += amount;
            transactions[transactionCount++] = amount; // Store transaction
        } else if (operation.substr(0, 5) == "debit") {
            int amount = stoi(operation.substr(6));
            balance -= amount;
            transactions[transactionCount++] = -amount; // Store transaction
        } else if (operation.substr(0, 5) == "abort") {
            int index = stoi(operation.substr(6)) - 1;  // Convert to 0-based
            if (index >= 0 && index < transactionCount) {
                balance -= transactions[index];         // Undo transaction
                transactions[index] = 0;               // Mark aborted
            }
        } else if (operation.substr(0, 8) == "rollback") {
            int commitIndex = stoi(operation.substr(9)) - 1; // 0-based index
            if (commitIndex >= 0 && commitIndex < commitCount) {
                balance = commitBalances[commitIndex];  // Revert balance
                transactionCount = 0;                  // Clear transactions
            }
        } else if (operation == "commit") {
            commitBalances[commitCount++] = balance;    // Save commit state
            transactionCount = 0;                      // Clear transactions
        }
    }
}

int main() {
    int initialBalance, numOperations;
    cin >> initialBalance >> numOperations;
    cin.ignore(); // Ignore newline after the number of operations

    handleBankOperations(initialBalance, numOperations);

    return 0;
}

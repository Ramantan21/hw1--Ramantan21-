#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPerfectSquare(long long x)
{
    // Βρίσκουμε την τετραγωνική ρίζα του ορίσματος.
    if (x >= 0) {

        long long sr = sqrt(x);

        // Εάν το τετράγωνο της ρίζας είναι ίσο
        // με το όρισμα, τότε ο αριθμός είναι τέλειο τετράγωνο
        // Η έκφραση επιστρέφει true
        return (sr * sr == x);
    }
    // Σε διαφορετική περίπτωση επιστρέφει false
    return false;
}

bool isPrime(long long x)
{
    long long i;

    if (x == 1)
        return true;

    for (i = 2; i <= x / 2; ++i) {

        // Αν ο αριθμός διαιρείται με κάποιο i, δεν είναι πρώτος
        // Πιθανός διαιρέτης του αριθμού μπορεί να έχει τιμή
        // το πολύ ίση με το μισό του αριθμού x
        // Η function επιστρέφει false
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(long long x)
{
    long long rem;
    long long rev = 0;
    long long temp;
    temp = x;

    while (x > 0)
    {
        rem = x % 10;
        rev = (rev * 10) + rem;
        x = x / 10;
    }
    return (temp == rev);
}

bool areMirrored(long long x, long long y)
{
    long long rem;
    long long rev = 0;

    while (x > 0)
    {
        rem = x % 10;
        rev = (rev * 10) + rem;
        x = x / 10;
    }

    return (rev == y);
}

long long makeMirror(long long x)
{
    long long rem;
    long long rev = 0;

    while (x > 0)
    {
        rem = x % 10;
        rev = (rev * 10) + rem;
        x = x / 10;
    }
    return rev;
}
bool isMirroredPrimeSquare(long long x)
{
    long long base;

    if (isPerfectSquare(x))
    {
        base=sqrt(x);
        if (isPrime(base))
        {
            long long mirror = makeMirror(x);
            if (isPerfectSquare(mirror))
            {
                base = sqrt(mirror);
                if (isPrime(base))
                {
                    if (!isPalindrome(x))
                        return true;
                }
            }
        }
    }
    return false;
}

long long power(long long base, long long exp)
{
    long long result = 1;
    while (exp != 0) {
        result *= base;
        --exp;
    }
    return result;
}

int main(int argc, char* argv[])
{
    char *ptr;
    long long low, high, i;
    long long sum=0;

    if (argc!=3)
        return 1;

    low=strtoll(argv[1], &ptr, 10);
    high=strtoll(argv[2], &ptr, 10);

    if ((low<1)  || (high>power(10,15)) || (high<low))
        return 1;

    for (i=low; i<=high; i++)
    {
        if (isMirroredPrimeSquare(i))
            sum+=i;
    }
    printf("%I64d\n", sum);
    return 0;
}

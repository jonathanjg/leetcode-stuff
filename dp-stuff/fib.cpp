#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


// O(2^n)
long long regular_nthFibonacci(int n) {
    if (n<=1) return n;
    return regular_nthFibonacci(n-1) + regular_nthFibonacci(n-2);
}


// Memoization O(n)
long long nthFibonacciUtil(int n, vector<long long>& dp) {
    if (n <= 1) {
        dp[n] = n;
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = nthFibonacciUtil(n - 1, dp) + nthFibonacciUtil(n - 2, dp);

    return dp[n];
}

long long memoization_nthFibonacci(int n) {
    vector<long long> dp(n + 1, -1);

    long long result = nthFibonacciUtil(n, dp);

    return result;
}


// Matrix Exponentiation O(log(n))
void matrixMult(vector<vector<long long>>& mat1, vector<vector<long long>>& mat2) {
    long long a = mat1[0][0];
    long long b = mat1[0][1];
    long long c = mat1[1][0];
    long long d = mat1[1][1];

    long long e = mat2[0][0];
    long long f = mat2[0][1];
    long long g = mat2[1][0];
    long long h = mat2[1][1];

    mat1[0][0] = a * e + b * g;
    mat1[0][1] = a * f + b * h;
    mat1[1][0] = c * e + d * g;
    mat1[1][1] = c * f + d * h;
}

void matrixPower(vector<vector<long long>>& mat1, int n) {
    if (n == 0 || n == 1) {
        return;
    }

    vector<vector<long long>> mat2 = {{1, 1}, {1, 0}};

    matrixPower(mat1, n / 2);

    matrixMult(mat1, mat1);

    if (n % 2 != 0) {
        matrixMult(mat1, mat2);
    }
}

long long matrix_nthFibonacci(int n) {
    if (n <= 1) return n;

    vector<vector<long long>> mat1 = {{1, 1}, {1, 0}};

    matrixPower(mat1, n - 1);

    return mat1[0][0];
}

template <typename Func>
void measureTime(string name, Func func, int n) {
    auto start = chrono::high_resolution_clock::now();

    auto result = func(n);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << name << " result: " << result << endl;
    cout << name << " time: " << duration.count() << " ns" << endl;
    cout << endl;
}

int main() {
    int n = 90;

    measureTime("Regular recursion", regular_nthFibonacci, n);
    measureTime("Memoization", memoization_nthFibonacci, n);
    measureTime("Matrix exponentiation", matrix_nthFibonacci, n);

    return 0;
}
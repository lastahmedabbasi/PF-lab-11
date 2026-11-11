#include <stdio.h>

int calculateChecksum(int transactionID){
    int result, remaining;

    result = transactionID % 10;
    remaining = transactionID / 10;

    if (remaining == 0) return result;

    return result + calculateChecksum(remaining);

}

int main(){

    int sum = 9876;
    
    do{
    sum = calculateChecksum(sum);
    } while(sum/10 != 0);

    printf("%d", sum);

    return 0;
}

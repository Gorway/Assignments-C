#include <stdio.h> // *** MAX PROFIT ****

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) 
        return 0;
    
    int maxProfit = 0; 
    int minPrice = prices[0]; 
    
    for (int i = 1; i < pricesSize; i++) {
        int currentProfit = prices[i] - minPrice; 
        maxProfit = (maxProfit > currentProfit) ? maxProfit : currentProfit; 
        minPrice = (minPrice < prices[i]) ? minPrice : prices[i]; 
    }
    
    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    
    int max_profit = maxProfit(prices, pricesSize);
    
    printf("Максимальная прибыль: %d\n", max_profit);
    
    return 0;
}


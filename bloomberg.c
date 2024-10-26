#include <stdio.h>
#include <bloomberg/bloomberg_api.h> 

int main() {
    // Initialize Bloomberg API
    BloombergAPI_Initialize();

    // Define the stock symbol and time period
    const char *stockSymbol = "AAPL US Equity"; // Example: Apple Inc.
    DateTime endDate = GetCurrentDate();
    DateTime startDate = SubtractMonths(endDate, 3);

    // Fetch historical prices
    HistoricalData historicalData = BloombergAPI_GetHistoricalData(stockSymbol, startDate, endDate);

    // Calculate gains and losses
    if (historicalData != NULL && historicalData.count > 0) {
        double initialPrice = historicalData[0].price; // Price at the start
        double finalPrice = historicalData[historicalData.count - 1].price; // Price at the end

        double gainLoss = finalPrice - initialPrice;
        double percentageChange = (gainLoss / initialPrice) * 100;

        printf("Stock: %s\n", stockSymbol);
        printf("Initial Price: %.2f\n", initialPrice);
        printf("Final Price: %.2f\n", finalPrice);
        printf("Gain/Loss: %.2f\n", gainLoss);
        printf("Percentage Change: %.2f%%\n", percentageChange);
    } else {
        printf("No data found for the specified date range.\n");
    }

    // Cleanup
    BloombergAPI_Terminate();

    return 0;
}

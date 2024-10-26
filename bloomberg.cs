using System;
using Bloomberg.API;

class Program
{
    static void Main(string[] args)
    {
        // Initialize the Bloomberg API session
        BloombergAPI.Initialize();

        // Define the stock symbol and time period
        string stockSymbol = "AAPL US Equity"; // Example: Apple Inc.
        DateTime endDate = DateTime.Now;
        DateTime startDate = endDate.AddMonths(-3);

        // Fetch historical prices
        var historicalData = BloombergAPI.GetHistoricalData(stockSymbol, startDate, endDate);

        // Calculate gains and losses
        if (historicalData != null && historicalData.Count > 0)
        {
            decimal initialPrice = historicalData[0].Price; // Price at the start
            decimal finalPrice = historicalData[historicalData.Count - 1].Price; // Price at the end

            decimal gainLoss = finalPrice - initialPrice;
            decimal percentageChange = (gainLoss / initialPrice) * 100;

            Console.WriteLine($"Stock: {stockSymbol}");
            Console.WriteLine($"Initial Price: {initialPrice}");
            Console.WriteLine($"Final Price: {finalPrice}");
            Console.WriteLine($"Gain/Loss: {gainLoss}");
            Console.WriteLine($"Percentage Change: {percentageChange}%");
        }
        else
        {
            Console.WriteLine("No data found for the specified date range.");
        }

        // Cleanup
        BloombergAPI.Terminate();
    }
}

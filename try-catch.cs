using System;

class Program
{
    static void Main(string[] args)
    {
        try
        {
            int[] numbers = { 1, 2, 3 };
            Console.WriteLine(numbers[5]); // 可能引发异常
        }
        catch (IndexOutOfRangeException ex)
        {
            Console.WriteLine("Index out of range: " + ex.Message);
        }
        finally
        {
            Console.WriteLine("Execution finished.");
        }
    }
}

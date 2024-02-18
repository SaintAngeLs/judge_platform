using System;
using System.Collections.Generic;
using System.Linq;

class TestCaseGenerator
{
    static void Main(string[] args)
    {
        if (args.Length < 1 || !int.TryParse(args[0], out int caseNum))
        {
            Console.Error.WriteLine("Usage: TestCaseGenerator <case number>");
            return;
        }

        GenerateTestCaseWithLimits(caseNum);
    }

    private static void GenerateTestCaseWithLimits(int caseNum)
    {
        int amount = 0;
        List<int> coins = new List<int>();
        List<int> limits = new List<int>();
        List<int> expectedResChange = new List<int>();
        bool isChangePossible = true;

        switch (caseNum)
        {
            case 1:
                amount = 10;
                coins.AddRange(new[] { 5, 1, 2 });
                limits.AddRange(new[] { 1, 20, 10 });
                expectedResChange.AddRange(new[] { 1, 1, 2 });
                break;
            case 2:
                amount = 123;
                coins.AddRange(new[] { 1, 2, 5, 10, 20, 50, 100, 200 });
                limits.AddRange(Enumerable.Repeat(99999, 8));
                expectedResChange.AddRange(new[] { 1, 1, 0, 0, 1, 0, 1, 0 });
                break;
            case 3:
                amount = 123;
                coins.AddRange(new[] { 2, 5, 10, 20, 50, 100, 200 });
                limits.AddRange(Enumerable.Repeat(99999, 7));
                expectedResChange.AddRange(new[] { 4, 1, 1, 0, 0, 1, 0 });
                break;
            case 4:
                amount = 123;
                coins.AddRange(new[] { 1, 2, 5, 10, 20, 50, 100, 200 });
                limits.AddRange(new[] { 0, 99999, 99999, 99999, 99999, 99999, 99999, 99999 });
                expectedResChange.AddRange(new[] { 0, 4, 1, 1, 0, 0, 1, 0 });
                break;
            case 5:
                amount = 123;
                coins.AddRange(new[] { 1, 2, 5, 10, 20, 50, 100, 200 });
                limits.AddRange(new[] { 99999, 99999, 3, 4, 3, 0, 0, 99999 });
                expectedResChange.AddRange(new[] { 0, 4, 3, 4, 3, 0, 0, 0 });
                break;
            case 6:
                amount = 23;
                coins.AddRange(new[] { 1, 2, 5 });
                limits.AddRange(Enumerable.Repeat(99999, 3));
                expectedResChange.AddRange(new[] { 0, 4, 3 });
                break;
            case 7:
                amount = 23;
                coins.AddRange(new[] { 5, 1, 2 });
                limits.AddRange(new[] { 3, 2, 3, 3 });
                expectedResChange.AddRange(new[] { 2, 3, 5 });
                break;
            case 8:
                amount = 23;
                coins.AddRange(new[] { 5, 5, 1, 2 });
                limits.AddRange(new[] { 3, 2, 3, 3 });
                expectedResChange.AddRange(new[] { 3, 1, 1, 1 });
                break;
            case 9:
                amount = 23;
                coins.AddRange(new[] { 2, 137, 65, 35, 30, 9, 123, 81, 71 });
                limits.AddRange(Enumerable.Repeat(1, 9));
                expectedResChange.AddRange(new[] { 1, 0, 1, 1, 1, 1, 0, 0, 0 });
                break;
            case 10:
                amount = 23;
                coins.Add(2);
                limits.AddRange(Enumerable.Repeat(1, 15));
                isChangePossible = false;
                break;
            case 11:
                amount = 23;
                coins.Add(50);
                limits.Add(1);
                isChangePossible = false;
                break;
            case 12:
                amount = 23;
                coins.Add(1);
                isChangePossible = false;
                break;
            default:
                Console.Error.WriteLine("Invalid case number.");
                return;
        }

        // Output test case data to stdout
        Console.WriteLine($"{amount} {coins.Count}");
        Console.WriteLine(String.Join(" ", coins));
        Console.WriteLine(String.Join(" ", limits));

        // Output expected result to stderr
        if (!isChangePossible)
        {
            Console.Error.WriteLine("null");
        }
        else
        {
            Console.Error.WriteLine(String.Join(" ", expectedResChange));
        }
    }
}

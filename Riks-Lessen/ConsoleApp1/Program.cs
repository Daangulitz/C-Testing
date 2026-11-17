 List<int> amounts = new List<int>();
 int sum = 0;
 int sum1 = 0;
 int sum2 = 0;
 int sum3 = 0;
 int sum4 = 0;
 int sum5 = 0;
 int sum6 = 0;
 int sum7 = 0;
 int sum8 = 0;
 int sum9 = 0;
 int sum10 = 0;
 int sum11 = 0;
 int bestsum = 0;
 bool open = false;
 string naam = "";
 Int32 amount;

foreach (string regel in File.ReadLines("/home/daantje/Documents/Projects/Riks-Lessen/ConsoleApp1/bin/Debug/input.txt"))
{
    if (!open)
    {
        if (bestsum < 3)
        {
            bestsum++;
        } else
        {
            open = true;
        }
    }
    if (open == true){
        string[] delen = regel.Split(' ');
        naam = delen[0];
        amount = Int32.Parse(delen[1]);

        if (naam == "Luuk")
        {
            sum += amount;
        }
        if (naam == "Daan")
        {
            sum1 += amount;
        }
        if (naam == "Fleur")
        {
            sum2 += amount;
        }
        if (naam == "Iris")
        {
            sum3 += amount;
        }
        if (naam == "Jesse")
        {
            sum4 += amount;
        }
        if (naam == "Lotte")
        {
            sum5 += amount;
        }
        if (naam == "Milan")
        {
            sum6 += amount;
        }
        if (naam == "Noor")
        {
            sum7 += amount;
        }
        if (naam == "Sanne")
        {
            sum8 += amount;
        }
        if (naam == "Sem")
        {
            sum9 += amount;
        }
        if (naam == "Yara")
        {
            sum10 += amount;
        }
        if (naam == "Jasper")
        {
            sum11 += amount;
        }
}
}
 Console.WriteLine("{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}", sum, sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9, sum10, sum11);


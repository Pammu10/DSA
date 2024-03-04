import java.util.Scanner;

class UrLify
{


	static char[] replaceSpaces(char[] str)
	{

		int space_count = 0, i = 0;
		for (i = 0; i < str.length; i++)
			if (str[i] == ' ')
				space_count++;

		while (str[i - 1] == ' ')
		{
			space_count--;
			i--;
		}

		int new_length = i + space_count * 2;


		int index = new_length - 1;

		char[] old_str = str;
		str = new char[new_length];

		for (int j = i - 1; j >= 0; j--) 
		{

			if (old_str[j] == ' ') 
			{
				str[index] = '0';
				str[index - 1] = '2';
				str[index - 2] = '%';
				index = index - 3;
			} 
			
			else
			{
				str[index] = old_str[j];
				index--;
			}
		}
		return str;
	}

	public static void main(String[] args) 
	{

        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
		char[] str = s.toCharArray();

		str = replaceSpaces(str);

		for (int i = 0; i < str.length; i++)
			System.out.print(str[i]);
        sc.close();
	}
    
}


// Output 
// Pramod Krishna 1000
// Pramod%20Krishna%201000

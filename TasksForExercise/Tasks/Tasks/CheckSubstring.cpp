//
////Реализирайте функция, която проверява дали един низ се съдържа в друг.
//
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//bool checkSubstring(string str, string subStr);
//
//int main()
//{
//	string s = "abcdfg";
//	string sub = "fg";
//	string sub2 = "ftr";
//	cout << "Is " << sub << " substring on " << s << endl;
//	cout << checkSubstring(s,sub) << endl;
//	cout << "Is " << sub2 << " substring on " << s << endl;
//	cout << checkSubstring(s, sub2) << endl;
//return 0;
//}
//bool checkSubstring(string str, string subStr)
//{
//	if (subStr.size() > str.size()) return false;
//	
//	for (int i = 0; i < str.size(); i++)
//	{
//		int j = 0;
//		if (str[i] == subStr[j])
//		{
//			while (str[i] == subStr[j] && j < subStr.size())
//			{
//				i++;
//				j++;
//			}
//			if (j == subStr.size())
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}
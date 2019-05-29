//2.3日期差值

#include "stdafx.h"

#include<algorithm> 
#include<iostream>
#include<string>
using namespace std;


int days_of_month[12][2] = {  //我的方法只要第一列就好啦
	31,31,
	28, 29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
};

class Date {
public:
	int year;
	int month;
	int day;
	Date(int y = 0, int m = 0, int d = 0) :year(y), month(m), day(d) {};
	Date(Date & d) {
		year = d.year; month = d.month; day = d.day;
	}
	int count();
	int operator-(const Date & d2);
};

//计算到0年0月0日的日期差
int Date::count() {
	cout << year << "/" << month << "/" << day << endl;
	int sum = 0;
	for (int y = 0; y <year; y++) {   //先把之前所有年总日期加出来
		for (int i = 0; i < 12; i++) {
			sum += days_of_month[i][1];
			cout << sum<<endl;
		}
		if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0) sum++;
	}
	for (int m = 0; m < month; m++) {
		sum += days_of_month[m][1];
		if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0||m==2) sum++;
		cout << sum << endl;
	}
	sum += day;
	cout << sum << endl;
	return sum;
}

//重载减法运算符
int Date::operator-(const Date & d2) {
	int s1 = this->count();
	int d= d2.day;      //为啥这里不可以直接d2->count() ???会报错！！！！！！！！！
	int m = d2.month;
	int y = d2.year;
	Date tmp(y, m, d);
	int s2 = tmp.count();
	cout << "sum2: " << s2 << endl;
	return abs(s1 - s2);
}

int main() {
	Date d1,d2;
	d1= Date(1, 2, 3);
	d2 = Date(2, 3, 4);
	//Date d2 = (2, 3, 4);  //错误写法！
	cout << d1 - d2 << endl; 

	system("pause");
	return 0;
}


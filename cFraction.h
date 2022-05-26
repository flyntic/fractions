#pragma once
#include <string>
#include <iostream>

class cFraction
{
public:		
	typedef enum class enSign
	{
		sign_negative = 0,
		sign_positive = 1
	};
private:

    int numerator;
	unsigned int denominator;
	
public:

	cFraction Init(int numerator=0, unsigned int denominator=1)
	{
	    
		int del = 2;
		while ((numerator >= del)& (denominator >= del))
		{
			if((numerator % del == 0) && (denominator % del == 0))
			{
				numerator = numerator / del;
				denominator = denominator / del;
			}
			else
			 del++;
		}

		this->numerator = numerator;
		this->denominator = denominator;
		
		return *this;
	};

	cFraction(int numerator, unsigned int denominator)
	{
		Init(numerator, denominator);
	}

	cFraction(int numerator) :cFraction(numerator, 1) {};
	
	
	cFraction() 
	{
		unsigned int denominator;
		int numerator;
		

		std::string in_str_fraction;

		std::cout << "¬ведите дробь в формате: (знак) числитель/знаменатель \n";
		std::cin >> in_str_fraction;

		try
		{
			if (in_str_fraction.find('/') != -1)
			{
				numerator =   std::stoi(in_str_fraction.substr(0, in_str_fraction.find('/')));
				denominator = std::stoi(in_str_fraction.substr(in_str_fraction.find('/') + 1, sizeof(in_str_fraction)));
			}
			else
			{
				numerator = std::stoi(in_str_fraction);
				denominator = 1;
			}
		}
		catch(...)
		{
			std::cout << "¬веденна€ строка не соответствует формату=> 0\n";
			Init(0, 1);
			return ;
		}

	 
		while (denominator==0)
		{ 
			std::cout << "¬ведите знаменатель(!=0)\n";
			std::cin >> denominator;
		}

		Init(numerator, denominator);
	};

	const cFraction operator+(const cFraction& rfr)const
	{
		int temp_numerator = numerator * rfr.denominator + 
			             rfr.numerator * denominator; 
		int temp_denominator = denominator * rfr.denominator;
   	  
		return cFraction(temp_numerator, temp_denominator);
	}

	const cFraction operator-(const cFraction& rfr) const
	{
		int temp_numerator = numerator * rfr.denominator -
		  	                 rfr.numerator * denominator;
		int temp_denominator = denominator * rfr.denominator;

		return cFraction(temp_numerator, temp_denominator);
	}

	const cFraction operator*(const cFraction& rfr)const
	{
		int temp_numerator =  numerator *rfr.numerator ;

		int temp_denominator = denominator * rfr.denominator;

		return cFraction(temp_numerator,temp_denominator);
	}

	friend std::ostream &operator<<(std::ostream &out, const cFraction& fraction)
	{   
		enSign sign = (fraction.numerator >= 0) ? enSign::sign_positive: enSign::sign_negative ;

		if (fraction.denominator == 0)
			out << "ƒробь не действительна";
		else
		if (fraction.numerator == 0)
			out << std::to_string(fraction.numerator);

		else
		if (fraction.denominator == 1)
			out << ((sign == enSign::sign_negative) ? "-" : "") + std::to_string(abs(fraction.numerator));
		else

		if (abs(fraction.numerator) < fraction.denominator )
			out << ((sign == enSign::sign_negative) ? "-" : "") + std::to_string(abs(fraction.numerator)) + "/" + std::to_string(fraction.denominator);
		else
		if(fraction.numerator % fraction.denominator==0)
			out << ((sign == enSign::sign_negative) ? "-" : "") + std::to_string(abs(fraction.numerator) / fraction.denominator) ;
		else
			out << ((sign == enSign::sign_negative) ? "-" : "") + std::to_string(abs(fraction.numerator)/ fraction.denominator)+" "+std::to_string(abs(fraction.numerator) % fraction.denominator) + "/" + std::to_string(fraction.denominator);
		
		return out;
	}

	

	cFraction operator-(const int ifr) const
	{
		return *this - cFraction(ifr);
	}

	cFraction operator+(const int ifr) const
	{
		return *this + cFraction(ifr);
	}

	cFraction operator*(const int ifr) const
	{
		return *this * cFraction(ifr);
	}

	friend cFraction operator+(const int ifr, cFraction fr) 
	{
		return (fr + cFraction(ifr));
	}
	
	friend cFraction operator*(const int ifr, cFraction fr) 
	{
		return fr * cFraction(ifr);
	}	

	friend cFraction operator-(const int ifr,cFraction fr) 
	{
		return fr.operator*(-1).operator-(ifr*(-1));
	}

};


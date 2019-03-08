/// <summary>
/// Vector 3 class
/// Andrew Bashorum
/// est time 8-15 hours
/// act time 10 hours
/// </summary>
#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Default constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and separated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;
}

MyVector3::MyVector3(double t_x, double t_y, double t_z)
{
	x = t_x;
	z = t_z;
	y = t_y;
}

/// <summary>
/// create a vector 3 from an sf::vector3f
/// </summary>
/// <param name="t_sfVector">input vector</param>
MyVector3::MyVector3(sf::Vector3f t_sfVector)
{
	x = static_cast<double>(t_sfVector.x); // turns x , y and z components to doubles for vector 3f
	y = static_cast<double>(t_sfVector.y);
	z = static_cast<double>(t_sfVector.z);
}

MyVector3::MyVector3(sf::Vector3i t_sfVector)
{
	x = static_cast<int>(t_sfVector.x); // casts x , y and z components to int for use in vector 3i
	y = static_cast<int>(t_sfVector.y);
	z = static_cast<int>(t_sfVector.z);
}

MyVector3::MyVector3(sf::Vector2i t_sfVector)
{
	x = static_cast<int>(t_sfVector.x); // casts x and y components to int for use in vector 2i
	y = static_cast<int>(t_sfVector.y);
	z = 0;
}

MyVector3::MyVector3(sf::Vector2u t_sfVector)
{
	x = static_cast<unsigned int>(t_sfVector.x);  // casts to unsigned int
	y = static_cast<unsigned int>(t_sfVector.y);
	z = 0;
}

MyVector3::MyVector3(sf::Vector2f t_sfVector)
{
	x = static_cast<float>(t_sfVector.x); // casts to float for 2f vectors
	y = static_cast<float>(t_sfVector.y);
	z = 0;
}

MyVector3 MyVector3::operator+(const MyVector3 t_right) const
{
	 // adds indivual componets of the two vectors 
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}

MyVector3 MyVector3::operator-(const MyVector3 t_right) const
{
	  // subtracts indivual components of the two vector
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}

MyVector3 MyVector3::operator*(const double t_scalar) const
{
  // multiplys indivual components of the two vectors
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

MyVector3 MyVector3::operator/(const double t_divisor) const
{
	 // divides indivual componets of the two vector
	return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
}

MyVector3 MyVector3::operator+=(const MyVector3 t_right)
{
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;  // adds indivual componets of the two vectors in shorthand
	return MyVector3( x, y, z);
}

MyVector3 MyVector3::operator-=(const MyVector3 t_right)
{
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;  // adds indivual componets of the two vectors in shorthand
	return MyVector3(x, y, z);
}

bool MyVector3::operator==(const MyVector3 t_right) const
{
	if (x == t_right.x && y == t_right.y && z == t_right.z)  // checks each component for equality
	{
		return true;
	}
	else // if not equal
	{
		return false;
	}

}

bool MyVector3::operator!=(const MyVector3 t_right) const
{
	if (x == t_right.x && y == t_right.y && z == t_right.z)   // checks each component for equality
	{
		return false;
	}
	else
	{
		return true;
	}
}

MyVector3::operator sf::Vector2u()
{
	return sf::Vector2u{};
}

MyVector3 MyVector3::operator-()
{
	 // changes components to negative
	return MyVector3(-x, -y, -z);
}

void MyVector3::reverseX()
{
	x = x * -1; // change sign of x
}

void MyVector3::reverseY()
{
	y = y * -1; // change sign of y
}

double MyVector3::length() const /// or magnitude
{
	float sumOfSquares = (x*x) + (y*y) + (z*z); // squares and adds each compmnet
	const float length = sqrt(sumOfSquares); // finds length
	return length;
}

double MyVector3::lengthSquared() const
{
	 // calls length function to find length
	float lengthSquared = std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2);// squares awnser to find length squared
	return lengthSquared;
}

double MyVector3::dot(const MyVector3 t_other) const
{
	const float result = (x * t_other.x) + (y * t_other.y) + (z * t_other.z); // multiplys and adds each componen
	return result; //to find dot product
}

MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	const double resultX = y * t_other.z - z * t_other.y; // subtracts zy from yz to find new x component
	const double resultZ = x * t_other.y - y * t_other.x;  // subtracts yx from xy to find new z component
	const double resultY = z * t_other.x - x * t_other.z;  // subtracts xy from yx to find new x component
	return MyVector3(resultX, resultY, resultZ);       // doesnt work unsure why
}

double MyVector3::angleBetween(const MyVector3 t_other) const
{
	double top = dot(t_other);
	double under = length() * t_other.length();
	double angleRadians;

	if (under != 0)
	{
		double answer = top / under;
		if (answer > 1) answer = 1;
		if (answer < -1) answer = -1;
		angleRadians = std::acos(answer);
		const double angleDegrees = angleRadians * 180.0 / PI;
		return angleDegrees;
	}
	return 0.0;
	
}

MyVector3 MyVector3::unit() const
{
	MyVector3 preResult{ x,y,z };
	float resultX = 0.0f;
	float resultY = 0.0f;
	float resultZ = 0.0f;

	float length = preResult.length();
	if (length != 0.0f) // no divide by 0
	{
		resultX = x / length; // divides component by maginute of vector
		resultY = y / length;
		resultZ = z / length;
	}
	return MyVector3(resultX, resultY, resultZ);
}

//void MyVector3::normalise()
//{
//	MyVector3(x, y, z) = MyVector3(x, y, z) / MyVector3(x, y, z).length(); // unsure 
//}

MyVector3 MyVector3::projection(const MyVector3 t_onto) const
{
	double lengthSq = t_onto.lengthSquared();
	double dotProduct = dot(t_onto);
	double scale{ 1.0 };
	if (lengthSq != 0)
	{
		scale = dotProduct / lengthSq;
	}
	return t_onto * scale;
}

MyVector3 MyVector3::rejection(const MyVector3 t_onto) const
{
	return this->operator-(projection(t_onto));
}

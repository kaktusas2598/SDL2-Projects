#ifndef __Vector2D__
#define __Vector2D__

#include <math.h>

class Vector2D{
	public:
		Vector2D(float x, float y): m_x(x), m_y(y) {}

		float getX() const { return m_x; }
		float getY() const { return m_y; }

		void setX(float x){ m_x = x; }
		void setY(float y){ m_y = y; }

		float length() { return sqrt(m_x * m_x + m_y * m_y); }

		//Vector addition
		Vector2D operator+ (const Vector2D& v2) const {
			return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
		}

		friend Vector2D& operator+= (Vector2D& v1, const Vector2D& v2){
			v1.m_x += v2.m_x;
			v1.m_y += v2.m_y;

			return v1;
		}
		//Vector substraction
		Vector2D operator- (const Vector2D& v2) const {
			return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
		}

		friend Vector2D& operator-= (Vector2D& v1, const Vector2D& v2){
			v1.m_x -= v2.m_x;
			v1.m_y -= v2.m_y;

			return v1;
		}
		//Multiply by scalar
		Vector2D operator* (float scalar){
			return Vector2D(m_x * scalar, m_y * scalar);
		}

		Vector2D operator*= (float scalar){
			m_x *= scalar;
			m_y *= scalar;

			return *this;
		}
		//Divide by scalar
		Vector2D operator/ (float scalar){
			return Vector2D(m_x / scalar, m_y / scalar);
		}

		Vector2D operator/= (float scalar){
			m_x /= scalar;
			m_y /= scalar;

			return *this;
		}
		//Normalize vector(make length equal 1)
		void normalize(){
			float l = length();

			if(l > 0)//don't want to divide by zero
			{
				(*this) *= 1/l;
			}
		}

	private:

		float m_x;
		float m_y;
};

#endif

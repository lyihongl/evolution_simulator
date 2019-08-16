#ifndef POINT
#define POINT
//template <typename T>
class c_Point
{
	public:
		c_Point(double x, double y);
		~c_Point();
		double get_mag();
		double get_unit_x();
		double get_unit_y();
		double get_x();
		double get_y();
	private:
		double x;
		double y;
};
#endif
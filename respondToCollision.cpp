
//This code is not complete , is not ment to run
//But the function "respondToCollision" is from a working code that was used to make YouTube video https://youtu.be/saBaoMRU7XA


/*
struct ttang {   //triangle 
  vertice v[3];
  vector2d speed;
  double omega;
  vector2d cm; //center of mass
  double mass;
  double angmass;
  int color;
  int r[3], l[3], t[3], b[3]; //top bottom right left - need for collision state , please ignore
  void move();
  void draw();
  void calcCM(); // calculate center of mass - I calculate it as mean of vertices - you can put a point arbitrary into the triangle
};
*/

/*
struct vector2d{
	double el[2];
	//
	vector2d zero();
	vector2d operator-();
	vector2d operator-(vector2d p2);
	vector2d operator+();
	vector2d operator+(vector2d p2);
	vector2d operator*(double p2);
	double operator*(vector2d p2); //dot product
	vector2d operator&(double p2); //cross product  //p2 is considered perpendicular
	double operator&(vector2d p2); //cross product 
	double& operator[](int i);
	double norm();  //length
	double square();
	vector2d  cw90(); //rotate clockwise 90 degrees
	vector2d ccw90();
	vector2d();
	vector2d(double x,double y);
	virtual ~vector2d();
};

typedef vector2d vertice;
*/


void respondToCollision(vector2d v, vector2d p, ttang& i, ttang& j) {
	double jj;
	vector2d vv1, vv2, ap, bp;

	ap = p - i.cm;  /////// p is point where two triangles collide  // v is edge of collision
	bp = p - j.cm;  //cm is center of mass 


	vv2 = i.speed + (ap&i.omega);  //omega is angular speed
	vv1 = j.speed + (bp&j.omega);  

	v = v.cw90();    /////rotate vector clokwise 90 degrees // v is now normal vector 
	ap = ap.cw90();
	bp = bp.cw90();

	//impulse magnitude
	jj = (((vv2 - vv1)*(-(1.0 + e)))*v) / ((v*v*(1.0 / i.mass + 1.0 / j.mass))
		+ (ap*v)*(ap*v) / i.angmass + (bp*v)*(bp*v) / j.angmass);

	i.speed = i.speed + v*((jj) / i.mass);
	j.speed = j.speed + v*((-jj) / j.mass);

	i.omega = i.omega + ap*(v*((jj) / i.angmass));  // angmass is angular mass , Moment of inertia
	j.omega = j.omega + bp*(v*((-jj) / j.angmass));

}



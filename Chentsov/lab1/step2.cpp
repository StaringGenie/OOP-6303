class A
{
public:
  A() {};
  A(const A&) = delete;
  A& operator = (const A&) = delete;
private:
  // some resources
};
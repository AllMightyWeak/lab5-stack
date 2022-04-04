//Copyright by AllMightyWeak

#include <gtest/gtest.h>
#include "Stack.hpp"
#include "StackSecond.hpp"

TEST(Example, EmptyTest) {
  EXPECT_TRUE(true);
}
TEST(First, True) {
  Stack<int> MyStack;
  int t=2;
  MyStack.push(1);
  MyStack.push(t);
  EXPECT_EQ(MyStack.head(), 2);
  EXPECT_EQ(MyStack.pop(), 2);
  EXPECT_EQ(MyStack.head(), 1);
  EXPECT_EQ(MyStack.pop(), 1);
  std::string err = "Stack is empty";
  try {
    MyStack.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}

class Myclass {
 public:
  Myclass(Myclass&) = delete;
  Myclass& operator = (Myclass&) = delete;
  Myclass(Myclass&& obj)  noexcept {
    t2 = std::move(obj.t2);
    t1 = obj.t1;
    t0 = obj.t0;
  }
  Myclass& operator=(Myclass&& obj)  noexcept {
    t2 = std::move(obj.t2);
    t1 = obj.t1;
    t0 = obj.t0;
    return *this;
  }
  Myclass(){
    t0 = 0;
    t1 = 0.1;
    t2 = "0";
  }
  Myclass(int a, double b, std::string c): t0(a), t1(b), t2(c){}
  int t0;
  double t1;
  std::string t2;
};
TEST(Second, True) {
  StackTwo<Myclass> MyStack;
  int t0 = 2;
  double t1 = 2.2;
  std::string t2 = "2";
  MyStack.push_emplace(Myclass(1, 1.1, "12"));
  MyStack.push_emplace(t0, t1, t2);
  MyStack.push(Myclass());
  EXPECT_EQ(MyStack.pop().t2, "0");
  EXPECT_EQ(MyStack.head().t0, 2);
  EXPECT_EQ(MyStack.pop().t1, 2.2);
  EXPECT_EQ(MyStack.head().t0, 1);
  EXPECT_EQ(MyStack.pop().t2, "12");
  std::string err = "Stack is empty";
  try {
    MyStack.pop();
  }
  catch (std::runtime_error& error) {
    EXPECT_EQ(error.what(), err);
  }
  EXPECT_FALSE(std::is_copy_constructible<Stack<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack<int>>::value);
}
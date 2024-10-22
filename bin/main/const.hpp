#pragma once

namespace LearnConst {

void testConst()
{
  int a = 40;
  int &ref_a = a;
  int *p_a = &a;
  // int *p_r = ref_a; // compile fail, ref_a is int type, ref_a is an alias of variable a;
  int *p_r = &ref_a;// p_r point to the variable a;

  const int b = 40;
  const int c = 50;
  // int &ref_b = b; // Compile fail, int& bind const int
  const int &ref_b = b;
  // ref_b = c; // this is about to change the referred b and b is const can not change. so compile fail.

  // int *p_b = &b; // compile fail, const int * to int *
  const int *p = &b;
  p = &c;

  const int *const cp = &b;
  // cp = &c; // cp the pointer self is const. can not changed. compile fail.
  // the left side of const is low level const, and right one is  top level const in the terms of cpp.
}

}// namespace LearnConst

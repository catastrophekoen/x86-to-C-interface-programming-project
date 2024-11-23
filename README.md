# x86-to-C interface programming project
 sasm and C project

Introduction

A car's peformance is usually measured using an acceleration test with a 1KM distance. Some cars are measured from a cold start (they start at 0KM/H), some are tested from a hot start (the car is running at a stable speed and then accelerates).

Factors that are needed to compute acceleration (m/s2):

1. Initial Velocity (Vi) - starting speed.

2. Final Velocity (Vf) - final speed at the target distance (1KM).

3. Time (T) - the total time consumed to reach 1KM.

The formula for acceleration is:

Acceleration = (Vf - Vi)/T

Sample Computation:

Vi =62.5 KM/H

Vf = 0.0 KM/H

T = 10.1 s

Acceleration  = (62.5KM/H - 0.0KM/H) / 10.1s

                       = (62.5KM/H) / 10.1s

                       = Convert KM/H to m/s

                       = ([62.5KM/H * 1000M/H] * 1m/3600s )/ 10.1s

                       = (17.36M/s) / 10.1s

                       = 1.7188 m/s2

                               = convert to int (1.7188 m/s2) = 2 m/s2

Task

Implement a program that computes for the acceleration of multiple cars stored in a Y by 3 matrix. Where Y is the number of cars. All inputs are in double floating point.

The output acceleration for each will be converted into Integers.

Each row will indicate Initial Velocity (in KM/H), Final Velocity (in KM/H), and Time (in Seconds).

Sample Matrix:

0.0, 62.5, 10.1

60.0, 122.3, 5.5

30.0, 160.7, 7.8

*Required to use functional scalar SIMD registers

*Required to use functional scalar SIMD floating-point instructions

Input: Matrix Rows, single float matrix values

Example.

3

0.0, 62.5, 10.1

60.0, 122.3, 5.5

30.0, 160.7, 7.8

 

Output: Integer acceleration values (m/s2)

Example.

2

3

5
# Architect - Home planning and hoogeneous plan coordinates [![Build Status](https://travis-ci.org/mrlizzard/105torus_2017.svg?branch=master)](https://travis-ci.org/mrlizzard/105torus_2017)

- **Binary name:** 102architect
- **Repository name:** 102architect_2017
- **Repository rigths:** ramassage-tek
- **Language:** C, C++, perl 5, python 3 (>= 3.5), ruby 2 (>= 2.2), php 5.6, bash 4
- **Choosed language:** C
- **Compilation:** via Makefile, including re, clean and fclean rules


# Subject

Y
ou are working on a homeplanning software for an firm of architects.
The software should allow a simplification of the plan drawing process, and integrate various features, such as scale management, changing the point of view, moving doors and windows along walls,...
You are in charge of the part concerning geometric transformations (rotations to change point of view, translations to move an object, homtheties to zoom in and out, symmetries and any combination of these transformations). So, the goal of this project is to develop an application to compute points images in the plan after several transformations.

To make it nice and clean, you chose to use homogeneous coordinates. How clever of you.
O being the origin of both axis, here are the transformations to be implemented :
1. any translation,
2. homtheties centered at 0,
3. rotations centered at 0,
4. symmetries about any axis that passes through 0,
5. many combination of the previous transformations.

## Usage

```
~/B-MAT-100> ./102architect x y transfo1 arg11 [arg12] [transfor2 arg12 [arg22]] ...
```

- **x:** abscissa of the original point 
- **y:** ordinate of the original point
- **transfo arg1 [arg2]**
  - **-t** _i j_: translation along the coordinate vector (i, j)
  - **-h** _m n_: homothety with center 0 and scale factors _m_ along x-axis and _n_ along y-axis
  - **-r** _phi_: rotation centered in O at angle _phi_ degrees
  - **-s** _phi_: symmetry about the axis passing by 0 and inclined with an _phi_ degree angle

## Bonus

- adding other transformations
- graphical interface showing the transformations applied on several points / figures

## Examples

```
∼/B-MAT-100> ./102architect 5 0 -t -1 1
Translation by the vector (-1, 1)
1.00       0.00       -1.00
0.00       1.00       1.00
0.00       0.00       1.00
(5,0) => (4.00,1.00)
```

```
∼/B-MAT-100> ./102architect 2 2 -h -1 1
Homothety by the ratios -1 and 1
-1.00      0.00       0.00
0.00       1.00       0.00
0.00       0.00       1.00
(2,2) => (-2.00,2.00)
```

```
∼/B-MAT-100> ./102architect 1 0 -r 90
Rotation at a 90 degree angle
0.00       -1.00      0.00
1.00       0.00       0.00
0.00       0.00       1.00
(1,0) => (0.00,1.00)
```

```
∼/B-MAT-100> ./102architect 3 -1 -s 270
Symmetry about an axis inclined with an angle of 270 degrees
-1.00      0.00       0.00
0.00       1.00       0.00
0.00       0.00       1.00
(3,-1) => (-3.00,-1.00)
```

```
∼
/B-MAT-100> ./102architect 1 2 -t 2 3 -h 1 -2 -r 45 -s 30
Translation by the vector (2, 3)
Homothety by the ratios 1 and -2
Rotation at a 45 degree angle
Symmetry about an axis inclined with an angle of 30 degrees
0.97       -0.52      0.38
0.26       1.93       6.31
0.00       0.00       1.00
(1,2) => (0.31,10.44)
```
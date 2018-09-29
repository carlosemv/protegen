# protegen
Toy procedural terrain generators.

## TerraGen1
The 2D (or, arguably, 1D) terrain generator generates a one-dimensional array of height values, and from that creates a ppm (Portable Pixmap) image, like the ones below.

<img src="https://github.com/carlosemv/protegen/raw/master/TerraGen1/examples/img1.png" width="250"> <img src="https://github.com/carlosemv/protegen/raw/master/TerraGen1/examples/img2.png" width="250"> <img src="https://github.com/carlosemv/protegen/raw/master/TerraGen1/examples/img3.png" width="250">

It's written in C and uses a simple random midpoint displacement algorithm (MDA), similar to the well-known diamond-square algorithm for generating heightmaps.

### Further development
Implementation of the following features is not currently planned, but could be considered:
* Command line interface for algorithm parameters, and for image size, colors, and path/filename.
* Output images in other formats (such as png or jpg).
* Offer other generation algorithms.
* Construct image from multiple layers of height maps (giving a "mountain range" impression).

## TerraGen2
:construction: _under construction_ :construction:

<img src="https://github.com/carlosemv/protegen/raw/master/TerraGen2/examples/img1.png" width="250"> <img src="https://github.com/carlosemv/protegen/raw/master/TerraGen2/examples/img2.png" width="250"> <img src="https://github.com/carlosemv/protegen/raw/master/TerraGen2/examples/img3.png" width="250">

# Design Justifications for the paint pad project
#### Group Name:
Group C4

#### Members:
- Shimao Hu
- Zhouman Wu     wuxx0687    4644046
- Zixiang Ma     maxxx580    4644999

#### Instructions 
> Respond to each of the design questions below.  Make your answers factual and compelling.  Where appropriate, reference alternative designs you considered, code snippets, and diagrams within your writing in order to be clear and back up your claims.  As we have discussed in class, when writing with reference to figures make sure to tell the reader what to look for in the diagram or what exactly you want the reader to notice in the code snippet.  Remember that the design of your project is worth 1/3 of the total project grade.  Also remember that when grading the design portion of the project, this design justification document is the only thing we will look at.  This document must stand on its own.  Rather than linking to your actual code, carefully pick the most important code snippets from your project to include here in order to provide convincing detail for your answers to the questions below.

## 1  Design Question One
> The first design decision we made in the paint pad project is how paint tools should interact with canvas.
### 1.1 Design Description
Based on the UML diagrams that each of our group members designed for Brushwork, we came up with the final version of our UML diagram. 

![alt text][uml]

[uml]: https://github.umn.edu/umn-csci-3081F16a/repo-group-C04/tree/master/iteration1/doc/figures/iteration1_UML.png

To achieve the interaction between canvas and paint tools, we decided to have *brush_work_app* associated with canvas object and a family of classes including parent class *tool* and six child classes: *pen*, *highlighter*, *spraycan*, *eraser*, *calligraphy*, and *special* (please see figure 1). Each individual class contains different mask initialization and share method *apply_color_to_mask* from parent class which takes in canvas pointer, color applied, and the canvas' coordinates. New color is calculated by *calculate_color* in *apply_color_to_mask* and applied to canvas, which results in the change of color on the canvas.


### 1.2 Design Justification
The justification for the paint pad design described above is based upon the goal of creating a easily extensible, simple, reliable and easily maintainable software project to implement new tools. 
The first goal for this design is changeability and extensibility. In this way, there will be no change to the architect when more functionalities are added to this project such as different canvas color and adjustable mask size.
The second reason for this design is simplicity and maintainability. Although the functionality of these six paint tools is different, they share great similarity. By generalizing the similarity with parents class *tool*,  we can maintain a more organized program structures. 
We believe that the final design has significant advantages in terms of changeability, extensibilty, simplicity and maintainability. This section compares alternative designs we considered during our development process in order to show the advantages of this final design. The first design we considered is 

 
## 2  Design Question Three
>The third design question is how to interpolate while dragging the mouse leaves the canvas and back.
### 2.1 Design Description

### 2.2 Design Justification
Our previous implementation initializes both previous coordinates to -1. 
```sh
    //initialize previous coordinates
    pre_coordinate_x = - 1;
    pre_coordinate_y = - 1;
```
The problem along with this implementation is that each time the mouse is dragged to leave the canvas and back, the system will cash and nothing will be layed on the canvas after the mouse leaves the canvas. 

One way to solve this problem is to reinitialize the previous coordinates.
```sh
    //initialize previous coordinates
    pre_coordinate_x = - 10000;
    pre_coordinate_y = - 10000;
```
By initializing the previous coordinates to much smaller negative integers, each tool is able to paint on the boarder of the canvas after dragging the mouse leaves the canvas and back without system crash. 

## 3  Design Question Four
>The fourth design question is how to implement eraser.        
### 3.1 Design Description
The eraser is used to remove the all layers on the canvas. It inherits the mask and set_mask method from class of *tools*. But eraser has a different *apply_color_to_mask* method from the rest of tools. To achieve the functionality of eraser, this method always applies background color to canvas instead of applying the selected color to canvas.
### 3.2 Design Justification
There are three ways to implement eraser object. The most naive way is to hard-code color to be white in the *apply_color_to_mask* method. This implementation is the simplest and effective in this iteration as background color is defaulted to be white only.   

The second functional method is to add one boolean variable to determine whether the object is an eraser or not. This method will use background color rather than the selected color when the boolean variable is set to true. This implementation works when background color is not restricted to be white only, but it added additional information to the program which may reduce maintainability.    

The third implementation is to overwrite the *apply_color_to_mask* in eraser class. This implementation works for all background color. This special implementation only applies within the eraser class. This is also the the implementation that this project will use.

 
## 4  Design Question Five
>The fifth design question is how to implement special tool.        
### 4.1 Design Description
The special tool that we designed is used to generate a stereo brush with random color. It 
uses a special circular mask but is separated into nine colored parts with randomly generated color on each part. The mask of this special tool is 40 pixels in diameter. Like the Pen tool, it is completely opaque and covers up any layers that was already applied to the canvas when mouse is dragged on the canvas. This special tool also inherits methods from *tool* like other tools. But it has different *apply_color_to_mask*, *set_mask* methods from the rest of tools. 
In order to achieve the functionality of this special tool, this method always applies random color to canvas instead of applying the selected color to canvas. The specific color to this special tool can’t be set interactively using the Tool Window GUI.

### 4.2 Design Justification
The implementation of the special tool includes three steps. The first step is to inherit from the parent class *tools*. The next step is to overwrite the *set_mask* method. This method is to generate the specific circular mask which is completely opaque. 
```sh
    void Special::set_mask(){
      Tools :: set_mask();
      for (int row = 0; row < mask_size; row++){
        for (int col = 0; col < mask_size; col++){
           if (calculate_distance_from_mask_center(row, col, mask_center) <= radius){
            mask[row][col] = 1.0;
           }else{
            mask[row][col] = 0.0;
         }
        }
      }
   }
```
To implement the special tool object, the apply_color_to_mask needs to be overwrite. 
```sh
  for(int row = 0; row < mask_size; row+=5){
      float r1 = (float) rand()/(RAND_MAX);
      float r2 = (float) rand()/(RAND_MAX); 
      float r3 = (float) rand()/(RAND_MAX);
      printf("special color are: %ld, %ld, %ld \n", r1, r2, r3);
      ColorData * random_color = new ColorData(r1, r2, r3);
```
By adding 5 pixels to row each time and applied *rand* method to generate color, the mask is splitted into nine colored parts. This means random color applies to the mask at col[0], col[5], col[10], … ,and col[40].
```sh
 calculate_color(
                    row,
                    col,
                    coordinate_x,
                    coordinate_y,
                    set_pixel_coodinate_x,
                    height - (set_pixel_coodinate_y + 1), // transform coordinates.
                    (*random_color), pixel_buffer_);
```

By passing the random_color as a parameter to the *calculate_color* method, the special tool is now having up to nine different colors. 

special tool: 
![alt text][special]

[special]: https://github.umn.edu/umn-csci-3081F16a/repo-group-C04/tree/master/iteration1/doc/figures/special_tool.png 

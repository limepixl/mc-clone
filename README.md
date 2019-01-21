# mc-clone
An attempt at making some sort of Minecraft clone in OpenGL using C++. It has limited functionality and is not an actual game, just a playable demo.

Things to do: 
* Chunk edge detection - faces on chunk edges are rendered regardless whether there's an adjacent block or not
* Block removal and placement
* Better randomized chunk generation for heighmap usage

### Dependencies:
* GLAD
* GLFW
* GLM
* stb_image

### Images
![Chunks with random heights](https://github.com/limepixl/mc-clone/blob/master/mc-clone/images/1.png)
![Randomized basic blocks](https://github.com/limepixl/mc-clone/blob/master/mc-clone/images/2.png)
![Randomized all blocks](https://github.com/limepixl/mc-clone/blob/master/mc-clone/images/3.png)

#include <iostream>

// GLEW

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <filesystem>
#include <glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


// GLFW
#include <GLFW/glfw3.h>

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

//Camera Positions
glm::vec3 firstcameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 secondcameraPosition = glm::vec3(2.0f, 0.0f, 3.0f);
glm::vec3 thirdcameraPosition = glm::vec3(2.0f, 2.0f, 3.0f);

// Shaders
const GLchar* vertexShaderSourcechess = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"out vec4 ourcolor;\n"
"uniform mat4 MVP;\n"
"void main()\n"
"{\n"
"gl_Position = MVP * vec4(position.x, position.y, position.z, 1.0);\n"
"ourcolor = vec4(color, 1.0);\n"
"}\0";
const GLchar* fragmentShaderSourcechess = "#version 330 core\n"
"out vec4 color;\n"
"in vec4 ourcolor;\n"
"void main()\n"
"{\n"
"color = ourcolor;\n"
"}\n\0";
GLuint VBO[86], VAO[86];

void generate1()
{

    glGenVertexArrays(86, VAO);
    glGenBuffers(86, VBO);
    float firstxpos = -0.4f;
    float secondxpos = -0.3f;
    float firstypos = 0.5f;
    float secondypos = 0.4f;
    int index = 0;
    float white = 1.0f;
    float black = 0.0f;
    float changecolor = black;
    bool row1 = true;
    bool row2 = false;
    bool row3 = false;
    bool row4 = false;
    bool row5 = false;
    bool row6 = false;
    bool row7 = false;
    bool row8 = false;
    bool row9 = false;
    int first = 1;
    int second = 0;
    int third = 0;
    int fourth = 0;
    int fifth = 0;
    int sixth = 0;
    int seventh = 0;
    int eighth = 0;
    int nineth = 0;
    float original = -0.02f;
    float raise = 0.02f;

    srand(time(NULL));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            float random = original + (float)rand() / (float)RAND_MAX * raise;
            if (row1)//First row
            {

                if (first == 1 || first == 3 || first == 5 || first == 7 || first == 9)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (first == 2 || first == 4 || first == 6 || first == 8)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                first++;
            }

            if (first == 10)
            {
                row2 = true;
                row1 = false;
            }
            if (row2)//Second row
            {
                if (second == 1 || second == 3 || second == 5 || second == 7 || second == 9)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };
                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (second == 2 || second == 4 || second == 6 || second == 8)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                second++;
            }
            if (second == 10)
            {
                row3 = true;

            }
            if (row3)//third row
            {
                if (third == 1 || third == 3 || third == 5 || third == 7 || third == 9)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (third == 2 || third == 4 || third == 6 || third == 8)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                third++;
            }
            if (third == 10)//Next row
            {
                row4 = true;
                row3 = false;
            }
            if (row4)//Fourth row
            {
                if (fourth == 1 || fourth == 3 || fourth == 5 || fourth == 7 || fourth == 9)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (fourth == 2 || fourth == 4 || fourth == 6 || fourth == 8)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };
                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                fourth++;
            }
            if (fourth == 10)//Next row active
            {
                row5 = true;
                row4 = false;

            }
            if (row5)//Fifth row
            {
                if (fifth == 1 || fifth == 3 || fifth == 5 || fifth == 7 || fifth == 9)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };
                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (fifth == 2 || fifth == 4 || fifth == 6 || fifth == 8)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };
                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                fifth++;
            }
            if (fifth == 10)//Next row active
            {
                row6 = true;
                row5 = false;
            }
            if (row6)//Sixth row
            {
                if (sixth == 1 || sixth == 3 || sixth == 5 || sixth == 7 || sixth == 9)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (sixth == 2 || sixth == 4 || sixth == 6 || sixth == 8)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                sixth++;
            }
            if (sixth == 10)//Next row active
            {
                row7 = true;
                row6 = false;
            }
            if (row7)//Seventh row
            {
                if (seventh == 1 || seventh == 3 || seventh == 5 || seventh == 7 || seventh == 9)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };
                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (seventh == 2 || seventh == 4 || seventh == 6 || seventh == 8)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                seventh++;
            }
            if (seventh == 10)//Next row active
            {
                row8 = true;
                row7 = false;
            }
            if (row8)//Eighth row
            {
                if (eighth == 1 || eighth == 3 || eighth == 5 || eighth == 7 || eighth == 9)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };
                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (eighth == 2 || eighth == 4 || eighth == 6 || eighth == 8)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                eighth++;
            }
            if (eighth == 10)//Next row active
            {
                row9 = true;
                row8 = false;
            }
            if (row9)//Last row
            {
                if (nineth == 1 || nineth == 3 || nineth == 5 || nineth == 7 || nineth == 9)
                {
                    changecolor = black;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                if (nineth == 2 || nineth == 4 || nineth == 6 || nineth == 8)
                {
                    changecolor = white;
                    GLfloat vertices[] =
                    {

                           firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,

                           secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                          firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,

                          //back
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, firstypos, random,       changecolor, changecolor, changecolor,
                           firstxpos, secondypos, random,      changecolor, changecolor, changecolor,

                           //left
                           //forward/back  sides  height
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,
                            firstxpos, firstypos, -0.1f,       changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                            firstxpos, secondypos, random,       changecolor, changecolor, changecolor,
                            firstxpos, firstypos, random,        changecolor, changecolor, changecolor,

                            //right
                            //x    z      y
                            //sides  forward/back    height
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,
                            secondxpos, firstypos, -0.1f,      changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                            secondxpos, secondypos, random,      changecolor, changecolor, changecolor,
                            secondxpos, firstypos, random,       changecolor, changecolor, changecolor,

                            //Bottom
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, random,    changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             secondxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, -0.1f,     changecolor, changecolor, changecolor,
                             firstxpos, secondypos, random,    changecolor, changecolor, changecolor,

                             //Top
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, random,     changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              secondxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, -0.1f,      changecolor, changecolor, changecolor,
                              firstxpos, secondypos, random,     changecolor, changecolor, changecolor


                    };

                    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
                    glBindVertexArray(VAO[index]);

                    glBindBuffer(GL_ARRAY_BUFFER, VBO[index]);
                    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

                    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
                    glEnableVertexAttribArray(0);

                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
                    glEnableVertexAttribArray(1);
                }
                nineth++;
            }
            //continue adding for full board


            index++;
            firstxpos += 0.1f;
            secondxpos += 0.1f;
        }



        firstxpos = -0.4f;
        secondxpos = -0.3f;
        firstypos -= 0.1f;
        secondypos -= 0.1f;

    }

}

// The MAIN function, from here we start the application and run the game loop
int main()
{
    // Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // GLFWwindow object created 
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

    int screenWidth, screenHeight;
    //callback everytime the window has been resized
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    
    glewExperimental = GL_TRUE;
    // Initializing GLEW to setup the OpenGL Function pointers
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }

    // viewport dimensions
    glViewport(0, 0, screenWidth, screenHeight);

    glEnable(GL_DEPTH_TEST);

    // Build and compile our shader program
    // Vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSourcechess, NULL);
    glCompileShader(vertexShader);

    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourcechess, NULL);
    glCompileShader(fragmentShader);

    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Linking the shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    
    //Calling the generate method to generate the chessboard
    generate1();

    //Creating the border of the chessboard
    float xcoordinates = -0.4f;
    float xcoordinates2 = -0.3f;
    float ycoordinates = 0.5f;
    float ycoordinates2 = 0.4f;
    int index_border = 81;
    int chessborder = 0;
    int chessborder2 = 0;
    int chessborder3 = 0;
    for (int x = 0; x < 4; x++)
    {
        if (chessborder == 0)
        {
            GLfloat vertices[] =
            {
                -0.4f, 0.5f, -0.05f,   2.0f, 1.0f, 0.0f,
                -0.45f, 0.55f, -0.05f,   2.0f, 1.0f, 0.0f,
                -0.45f, -0.45f, -0.05f,  2.0f, 1.0f, 0.0f,

                 -0.4f, -0.4f, -0.05f,   2.0f, 1.0f, 0.0f,
                 -0.4f, 0.5f, -0.05f,    2.0f, 1.0f, 0.0f,
                 -0.45f, -0.45f, -0.05f,   2.0f, 1.0f, 0.0f
            };
            glBindVertexArray(VAO[index_border]);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[index_border]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
            glEnableVertexAttribArray(1);

        }
        if (chessborder == 1)
        {
            GLfloat vertices[] =
            {
                -0.4f, 0.5f, -0.05f,   2.0f, 1.0f, 0.0f,
                -0.45f, 0.55f, -0.05f,   2.0f, 1.0f, 0.0f,
                 0.55f, 0.55f, -0.05f,  2.0f, 1.0f, 0.0f,

                 0.5f, 0.5f, -0.05f,   2.0f, 1.0f, 0.0f,
                 0.55f, 0.55f, -0.05f,    2.0f, 1.0f, 0.0f,
                 -0.4f, 0.5f, -0.05f,   2.0f, 1.0f, 0.0f
            };
            glBindVertexArray(VAO[index_border]);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[index_border]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
            glEnableVertexAttribArray(1);
        }
        if (chessborder == 2)
        {
            GLfloat vertices[] =
            {
                0.5f, 0.5f, -0.05f,   2.0f, 1.0f, 0.0f,
                0.55f, 0.55f, -0.05f,   2.0f, 1.0f, 0.0f,
                 0.55f, -0.45f, -0.05f,  2.0f, 1.0f, 0.0f,

                 0.5f, -0.45f, -0.05f,   2.0f, 1.0f, 0.0f,
                 0.55f, -0.45f, -0.05f,    2.0f, 1.0f, 0.0f,
                 0.5f, 0.5f, -0.05f,   2.0f, 1.0f, 0.0f
            };
            glBindVertexArray(VAO[index_border]);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[index_border]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
            glEnableVertexAttribArray(1);
        }
        if (chessborder == 3)
        {
            GLfloat vertices[] =
            {
                0.5f, -0.4f, -0.05f,   2.0f, 1.0f, 0.0f,
                0.55f, -0.45f, -0.05f,   2.0f, 1.0f, 0.0f,
                -0.4f, -0.4f, -0.05f,  2.0f, 1.0f, 0.0f,

                 -0.45f, -0.45f, -0.05f,   2.0f, 1.0f, 0.0f,
                 -0.4f, -0.4f, -0.05f,    2.0f, 1.0f, 0.0f,
                 0.55f, -0.45f, -0.05f,   2.0f, 1.0f, 0.0f
            };
            glBindVertexArray(VAO[index_border]);

            glBindBuffer(GL_ARRAY_BUFFER, VBO[index_border]);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
            glEnableVertexAttribArray(1);
        }

        chessborder++;
        index_border++;
    }

    GLfloat vertices3D[] =
    {

        //Back 
         -0.45f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,

          0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,

         //Front
         -0.45f, -0.45f, -0.05f,      1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.05f,      1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.05f,       1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.05f,       1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.05f,       1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.05f,      1.0f, 1.0f, 0.0f,

         //left
         //forward/back  sides  height
         -0.45f, 0.55f, -0.02f,        1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.1f,       1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.02f,       1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.02f,        1.0f, 1.0f, 0.0f,

         //right
         //x    z      y
         //sides  forward/back    height
         0.55f, 0.55f, -0.02f,       1.0f, 1.0f, 0.0f,
         0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         0.55f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
         0.55f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
         0.55f, -0.45f, -0.02f,      1.0f, 1.0f, 0.0f,
         0.55f, 0.55f, -0.02f,       1.0f, 1.0f, 0.0f,

         //Bottom
         -0.45f, -0.45f, -0.02f,    1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.02f,    1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
          0.55f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.1f,     1.0f, 1.0f, 0.0f,
         -0.45f, -0.45f, -0.02f,    1.0f, 1.0f, 0.0f,

         //Top
         -0.45f, 0.55f, -0.02f,     1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.02f,     1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
          0.55f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.1f,      1.0f, 1.0f, 0.0f,
         -0.45f, 0.55f, -0.02f,     1.0f, 1.0f, 0.0f,

    };
    glBindVertexArray(VAO[85]);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[85]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3D), vertices3D, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);




    int drawindex = 0;
    // Game loop until the user presses exit
    while (!glfwWindowShouldClose(window))
    {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        //glClearColor specifies the color on the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

       



        glUseProgram(shaderProgram);

        //Camera Postion of the chessboard
        glm::mat4 model = glm::mat4(1.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(-45.0f), glm::vec3(1.0f, 0.3f, 0.5f));
        view = glm::lookAt(firstcameraPosition, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);

        glm::mat4 mvp = projection * view * model;

        unsigned int matricID = glGetUniformLocation(shaderProgram, "MVP");
        glUniformMatrix4fv(matricID, 1, GL_FALSE, &mvp[0][0]);


        //Drawing the chessboard with the border around it
        for (int i = 0; i < 85; i++)
        {
            glBindVertexArray(VAO[i]);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        glBindVertexArray(VAO[85]);
        glDrawArrays(GL_TRIANGLES, 0, 36);





        // Swap the screen buffers
        glfwSwapBuffers(window);
    }

    // Deleting the vertex arrays and buffers
    glDeleteVertexArrays(86, VAO);
    glDeleteBuffers(86, VBO);


    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();

    return EXIT_SUCCESS;
}

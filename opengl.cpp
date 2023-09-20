#include <GLFW/glfw3.h>
#include <cmath>

void drawTriangle()
{
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // Vertex 1: (x, y, z)
        1.0f, 0.0f, 0.0f,   // Red color
        0.5f, -0.5f, 0.0f,  // Vertex 2: (x, y, z)
        0.0f, 1.0f, 0.0f,   // Green color
        0.0f, 0.5f, 0.0f,   // Vertex 3: (x, y, z)
        0.0f, 0.0f, 1.0f    // Blue color
    };

    GLFWwindow* window;

    if (!glfwInit())
        return;

    window = glfwCreateWindow(800, 600, "OpenGL Triangle (FlexTape cuz im so cool)", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClear(GL_COLOR_BUFFER_BIT);

        float time = glfwGetTime();
        float rotation = sin(time) * 45.0f; 
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 6 * sizeof(float), vertices);
        glColorPointer(3, GL_FLOAT, 6 * sizeof(float), vertices + 3);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
}

int main()
{
    drawTriangle();
    return 0;
}

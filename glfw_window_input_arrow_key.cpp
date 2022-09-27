#include <GLFW/glfw3.h>
#include <iostream>


//This function await for Keyboard input from user 
void CloseWindow(GLFWwindow *window){
    //This function closes the window when the esc Key is press
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void Arrow_Keys(GLFWwindow *window){
    
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        std::cout << " Forward" << std::endl;
    }

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        std::cout << "Left " << std::endl;
    }

    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        std::cout << " Right" << std::endl;
    }

    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        std::cout << " Backwards" << std::endl;
    }
}


int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW",NULL,NULL);
    if (window == NULL){
        std::cout << "Failed to open GLFW WINDOW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    while (!glfwWindowShouldClose(window)){
    //  Get use input 

        CloseWindow(window);
        Arrow_Keys(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

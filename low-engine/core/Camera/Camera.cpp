//===----------------------------------------------------------------------===//
//
//                            Low-Engine Core
//
//===----------------------------------------------------------------------===//
//
//  Camera.cpp - 03/28/2018
//
//  Copyright (C) 2018. rollrat. All Rights Reserved.
//
//===----------------------------------------------------------------------===//

#include <Camera/Camera.h>

#include <Render/Display.h>

extern GLFWwindow* window;
extern lowengine::DisplayInfo* display_info;

glm::vec3 position = glm::vec3(0, 0, 5);
GLfloat horizontalAngle = 0.0f;
GLfloat verticalAngle = 0.0f;

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

float initialFoV = 45.0f;
float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;

lowengine::Camera::Camera()
{
}

std::string lowengine::Camera::to_string()
{
  return std::to_string(position.x) + "," + 
    std::to_string(position.y) + "," +
    std::to_string(position.z);
}

glm::vec3& lowengine::Camera::GetPosition()
{
  return position;
}

GLfloat lowengine::Camera::GetHorizontalAngle() const
{
  return horizontalAngle;
}

void lowengine::Camera::SetHorizontalAngle(GLfloat angle)
{
  horizontalAngle = angle;
}

GLfloat lowengine::Camera::GetVerticalAngle() const
{
  return verticalAngle;
}

void lowengine::Camera::SetVerticalAngle(GLfloat angle)
{
  verticalAngle = angle;
}

void lowengine::Camera::Update()
{
	static double lastTime = glfwGetTime();

	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	glfwSetCursorPos(window, display_info->width/2, display_info->height/2);

	horizontalAngle += mouseSpeed * float(display_info->width/2 - xpos );
	verticalAngle   += mouseSpeed * float(display_info->height/2 - ypos );

	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle), 
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0f), 
		0,
		cos(horizontalAngle - 3.14f/2.0f)
	);
	
	glm::vec3 up = glm::cross( right, direction );

	if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}

	float FoV = initialFoV;

	ProjectionMatrix = glm::perspective(FoV, display_info->width / (float)display_info->height, 0.1f, 100.0f);
	ViewMatrix       = glm::lookAt(
								position,
								position+direction,
								up
						   );

	lastTime = currentTime;
}

glm::mat4 lowengine::Camera::GetPV()
{
  return ProjectionMatrix * ViewMatrix;
}

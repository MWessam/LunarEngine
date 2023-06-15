#include "glm/glm.hpp"
#include <iostream>

void printMat(const glm::mat4& matrix) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
void printVec(const glm::vec4& vector)
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << vector[i] << ' ';
	}
	std::cout << std::endl;
}
void testMVP(const glm::mat4& proj, const glm::mat4& view, const glm::mat4& model, const glm::vec3 vertex) {
	glm::mat4 mvp = proj * view * model;
	printMat(proj);
	printMat(view);
	printMat(model);
	printMat(mvp);
	glm::vec4 result = mvp * glm::vec4(vertex, 1.0f);
	printVec(result);
	glm::vec4 result2 = result / result.w;
	printVec(result2);
}
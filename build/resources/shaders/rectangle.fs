#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform vec4 colDiffuse;

out vec4 finalColor;

vec3 rectangle(in float size) 
{
  float left = step(size, fragTexCoord.x);
  float top = step(size, fragTexCoord.y);
  float bottom = step(size, 1 - fragTexCoord.y);
  float right = step(size, 1 - fragTexCoord.x);

  return vec3(left*bottom*right*top);
}

void main()
{

  vec3 color = rectangle(0.2);

  finalColor = vec4(color, 1.0);
}


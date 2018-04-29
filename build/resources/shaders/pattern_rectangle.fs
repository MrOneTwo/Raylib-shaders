#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform vec4 colDiffuse;

out vec4 finalColor;

vec3 rectangle(in vec2 _st, in float size) 
{
  float left = step(size, _st.x);
  float top = step(size, _st.y);
  float bottom = step(size, 1 - _st.y);
  float right = step(size, 1 - _st.x);

  return vec3(left*bottom*right*top);
}

void main()
{
  vec2 st = fragTexCoord;
  st *= 12.0;
  st = fract(st);

  vec3 color = rectangle(st, 0.4);
  //vec3 color = vec3(st, 0.0);

  finalColor = vec4(color, 1.0);
}


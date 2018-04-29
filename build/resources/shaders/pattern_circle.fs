#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform vec4 colDiffuse;

out vec4 finalColor;

float circle (in vec2 _st, in float _radius)
{
  vec2 l = _st-vec2(0.5);

  return 1.0-smoothstep(_radius - (_radius*0.01),
                        _radius + (_radius*0.01),
                        dot(l,l)*4.0);
}

void main()
{
  vec2 st = fragTexCoord;
  st *= 12.0;
  st = fract(st);

  float temp = circle(st, 0.08);
  vec3 color = vec3(temp);

  finalColor = vec4(color, 1.0);
}


#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

uniform sampler2D texture0;
uniform vec4 colDiffuse;

out vec4 finalColor;

// it will be optimized out if it doesn't contribute to the finalColor
uniform vec2 mousePosition = vec2(200.0, 200.0);

/*
 * Returns 1 if pixel is inside rectangle, 0 otherwise
 */
float rectangle(in vec2 _st, in float size) 
{
  float left = step(size, _st.x);
  float top = step(size, _st.y);
  float bottom = step(size, 1 - _st.y);
  float right = step(size, 1 - _st.x);

  return left*bottom*right*top;
}

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

  float circleMask = distance(fragTexCoord, mousePosition);
  circleMask = clamp(circleMask, 0.0, 0.3);

  float color;
  if (mousePosition.x == -1.0) {
    color = rectangle(st, 0.3);
    //color = vec3(st, 0.0);
  }
  else {
    color = rectangle(st, circleMask);
  }

  finalColor = vec4(color, color, color, 1.0);
}


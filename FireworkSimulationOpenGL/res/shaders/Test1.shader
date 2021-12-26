#shader vertex
#version 410 core

layout(location = 0) in vec4 position;

out vec4 v_Position;
uniform mat4 u_MVP;

void main()
{
    v_Position = position * u_MVP;
    gl_Position = position * u_MVP;
};

#shader fragment
#version 410 core

layout(location = 0) out vec4 fragColor;

uniform vec2 u_Resolution;
uniform vec2 u_Mouse;
uniform float u_Time;

in vec4 v_Position;

void main()
{
    vec2 uv = vec2(v_Position.x, v_Position.y) / u_Resolution;
    vec3 col1 = vec3(0.9, 0.6, 0.47);
    vec3 col2 = vec3(0.96, 0.811, 0.498);
    float y = step(pow(abs(uv.x - 0.5), 2.0) - uv.y, 0.0);
    vec3 col = y * mix(col1, col2, length(uv.y) - 0.2);


    fragColor = vec4(col, 1.0f);
};
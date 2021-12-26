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

vec2 random(float t) {
    float a = fract(sin(t * 1234.0f) * 4321.0f) * 2 * 3.1415;
    float d = fract(sin((t + a) * 1919.1f) * 6453.8f);
    return vec2(sin(a), cos(a)) * clamp(d, 0.05, 1.0);
}

void main()
{
    vec2 uv = vec2(v_Position.x, v_Position.y) / u_Resolution.y * 3;
    vec3 col = vec3(0);
    for (float i = 0.0f; i < 50.0f; i++) {
        vec2 rand = random(i+1.0f);
        float d = length(uv - rand * fract(u_Time));
        col.x += 0.002 / d;
        col.y += 0.003 / d;
        col.z += 0.002 / d;
    }
    
    
    fragColor = vec4(col, 1.0f);
};
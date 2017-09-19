#version 150

out vec4 outputColor;

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;
uniform float u_control02;

float random (in vec2 _st) {
    return fract( sin( dot(_st.xy, vec2(12.9898,78.233)) ) * 43758.5453123 );
}

// Based on Morgan McGuire @morgan3d
// https://www.shadertoy.com/view/4dS3Wd
float noise (in vec2 _st) {
    vec2 i = floor(_st);
    vec2 f = fract(_st);
    
    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));
    
    vec2 u = f * f * (3.0 - 2.0 * f);
    
    return mix(a, b, u.x) + (c - a)* u.y * (1.0 - u.x) + (d - b) * u.x * u.y;
}



#define NUM_OCTAVES 10

float fbm ( in vec2 _st) {
    float v = 0.0;
    float a = 0.5;
    vec2 shift = vec2(0.0);
    // Rotate to reduce axial bias
    mat2 rot = mat2(
        cos(0.5), sin(0.5),
        -sin(0.5), cos(0.5)
    );

    for (int i = 0; i < NUM_OCTAVES; ++i) {
        v += a * noise(_st);
        _st = rot * _st * 2.0 + shift;
        a *= 0.5;
    }

    return v;
}


float pattern( in vec2 p ) {
    vec2 q = vec2( fbm( p + vec2(0.0, 0.0) ), fbm( p + vec2(1.2, 1.3) ) );

    vec2 r = vec2( fbm( p + 4.0 * q * 0.01 + vec2(1.7, 0.2) ), fbm( p + 4.0 * q + vec2(8.3, 2.8) ) );

    // 노이즈의 변형 정도. 0 으로 설정시 기본적인 noise 와 비슷해짐.
    float _p = abs( cos(u_time * 0.25) + 2.0 ) * u_control02;
    return fbm( p + 4.0 * r * _p);
}


float pattern2( in vec2 p ) {
    vec2 q = vec2( fbm( p + vec2(0.0, 0.0) ), fbm( p + vec2(5.2, 1.3) ) );
    return fbm( p + 4.0 * q );
}


void main() {

    // _zoomSize 에 의해 그래픽의 세밀함 혹은 크기.
    // 마이너스와 플러스로 방향 조절.
    float _zoomSize = -4.0;
    vec2 st = gl_FragCoord.xy / u_resolution.xy * _zoomSize;


    // line Effect
    // 1.0 기본 노이즈에서 점점 라인으로.
    st.x *= 1.0;


    // 줌이 되는 위치 : center position
    vec2 translate = vec2(-_zoomSize * 0.5);

    // 줌 되는 속도.
    // float _zooming = ( ( sin(u_time * 0.25) ) - 0.0 ) * 2.0;
    // st += (st + translate) * _zooming;


    vec3 color = vec3(0.0);
    
    vec2 q = vec2(0.0);
    
    q.x = fbm( st );
    q.y = fbm( st );
    
    vec2 r = vec2(0.0);
    r.x = fbm( st + 1.0 * q + vec2(1.7,9.2)+ 0.15 * u_time);
    r.y = fbm( st + 1.0 * q + vec2(8.3,2.8)+ 0.6 * u_time);
    
    float f = pattern(st + r);
    
    color = mix( vec3(0.901961,0.619608,0.666667),
        vec3(0.666667,0.666667,sin(u_time)),
        clamp((f*f)*4.0,0.0,1.0));
    
    color = mix(color,
        vec3(sin(u_time), 0, 0.164706),
        clamp(length(q),0.0,0.2));
    
    color = mix(color,
        vec3(0.666667, 1, 1),
        clamp(length(r.x),0.0,1.0));

    outputColor = vec4((f + 1.0 * f * f + 0.1 * f) * color + color * 0.1, 1.0);

}

// fragment shader

#version 150

out vec4 outputColor;

uniform float u_time;
uniform vec2 u_mouse;
uniform vec2 u_resolution;


float rand(vec2 n) {
    return fract(sin(dot(n, vec2(12.9898,12.1414))) * 83758.5453);
}

float noise(vec2 n) {
    const vec2 d = vec2(0.0, 1.0);
    vec2 b = floor(n);
    vec2 f = smoothstep(vec2(0.0), vec2(1.0), fract(n));
    return mix(mix(rand(b), rand(b + d.yx), f.x), mix(rand(b + d.xy), rand(b + d.yy), f.x), f.y);
}

vec3 ramp(float t) {
    return t <= .5 ? vec3( 1. - t * 1.4, .2, 1.05 ) / t : vec3( .3 * (1. - t) * 2., .2, 1.05 ) / t;
}

float fire(vec2 n) {
    return noise(n) + noise(n * 2.1) * .6 + noise(n * 4.4) * 1.02;
}

void main( void ) {
    
    float directSpeed = -0.1;
    float t = u_time * directSpeed;
    vec2 uv = gl_FragCoord.xy / u_resolution.xy;

    
    // one column
    uv.y += 23.0 * sin(t) * 0.01 + t * 1.35;
    uv.x = abs(uv.x - 0.5);
    uv *= 10.7;

    // Multi Column
    // for (int i=0; i<5; i++) {
    //     uv.y += t / -2.3;
    //     uv.x = abs(uv.x - 0.25);
    //     uv *= 1.4;
    // }


    float q = fire(uv - t * 1.33) / 2.0;
    vec2 r = vec2(fire(uv + q / 2.0 + t - uv.x - uv.y), fire(uv + q - u_time));
    vec3 color = vec3(1.0 / (pow(vec3(0.1, 0.1, .1) + 0.61, vec3(4.0))));
    
    float _lineTick = 1.1;
    float grad = pow((r.y * _lineTick + r.y * _lineTick) * max(0.1, uv.x) + 0.1, 2.0);
    color = ramp(grad);
    color /= (0.10 + max(vec3(1), color));
    outputColor = vec4(color, 1.0);
}

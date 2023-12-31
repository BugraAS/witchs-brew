#version 100
precision mediump float;

// Input vertex attributes
attribute vec3 vertexPosition;
attribute vec2 vertexTexCoord;
attribute vec3 vertexNormal;

// Input uniform values
uniform mat4 mvp;
uniform mat4 matModel;
uniform mat4 matNormal;
uniform mat4 matLight;

uniform vec3 lightPos;

// Output vertex attributes (to fragment shader)
varying vec3 fragPosition;
varying vec3 fragNormal;
varying vec2 fragTexCoord;
varying vec4 shadowPos;

const float normalOffset = 0.1;

void main()
{
    fragPosition = vec3(matModel*vec4(vertexPosition, 1.0));

    fragNormal = normalize(vec3(matNormal*vec4(vertexNormal, 0.0)));

	vec3 lightVec = normalize(lightPos - fragPosition);
    float cosAngle = clamp(1.0 - dot(lightVec, fragNormal), 0.0, 1.0);
    vec3 scaledNormalOffset = fragNormal * (normalOffset * cosAngle);

    shadowPos = matLight * vec4(fragPosition + scaledNormalOffset, 1.0);

	fragTexCoord = vertexTexCoord;

    // Calculate final vertex position
    gl_Position = mvp*vec4(vertexPosition, 1.0);
}
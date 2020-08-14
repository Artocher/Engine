#ifdef GL_ES
precision mediump int;
precision mediump float;
#endif

uniform mat4 projectionMatrix; 
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

attribute vec4 position; 
attribute vec2 textureCoordinate;

varying vec2 v_texcoord;   
 
void main(){ 
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * (position + vec4(10, sin(position.x) + sin(position.z),10,0)); 
    v_texcoord = textureCoordinate; 
}


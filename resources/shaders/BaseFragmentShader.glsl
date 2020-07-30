#ifdef GL_ES
precision mediump int;
precision mediump float;
#endif

uniform sampler2D texture; 
 
varying vec2 v_texcoord; 

void main(){
    vec4 textureColour = texture2D(texture, v_texcoord);   
    if(textureColour.a < 0.8){ 
        discard;
    }

    gl_FragColor = texture2D(texture, v_texcoord); 
}

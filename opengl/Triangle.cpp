//
//  Triangle.cpp
//  opengl
//
//  Created by Xin Xu on 2014/10/23.
//  Copyright (c) 2014年 Xin Xu. All rights reserved.
//

#include <stdio.h>
#include <GLTools.h>
#include <GLShaderManager.h>
#include <GLUT/GLUT.h>

GLBatch triangleBatch;
GLShaderManager  shaderManager;

void changeSize(int w, int h) {
    glViewport(0, 0, w, h);
}

void setupRC() {
    glClearColor(0, 0, 1, 1);
    shaderManager.InitializeStockShaders();
    GLfloat vVerts[] = {-0.5, 0, 0, 0.5, 0, 0, 0, 0.5, 0};
    triangleBatch.Begin(GL_TRIANGLES, 3);
    triangleBatch.CopyVertexData3f(vVerts);
    triangleBatch.End();
}

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    GLfloat vRed[] = { 1.0, 0, 0, 0 };
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
    triangleBatch.Draw();
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    gltSetWorkingDirectory(argv[0]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Triangle");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(RenderScene);
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
        return 1;
    }
    setupRC();
    glutMainLoop();
    return 0;
}
# Algorithm Visualizer

This is a sorting algorithm visualizer written in C++ using OpenGL. I learned a lot through this project whether it be setting up a C++ environment, installing 3rd party dependencies, or safe pointer practices.

![](https://private-user-images.githubusercontent.com/68826473/387474558-41d86f93-36c8-46f0-8c17-64fa134903eb.gif?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzE5ODc1OTQsIm5iZiI6MTczMTk4NzI5NCwicGF0aCI6Ii82ODgyNjQ3My8zODc0NzQ1NTgtNDFkODZmOTMtMzZjOC00NmYwLThjMTctNjRmYTEzNDkwM2ViLmdpZj9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNDExMTklMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjQxMTE5VDAzMzQ1NFomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPThlNzMwODkwMjUyYWFhOWRkYzVkNTJkZTdjMWU2Zjc3YTY1MjU5NWFjODU0MjZlMTBiN2EyYzdkY2E2ODEyNDEmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.RntWzfiBRopJ3-HThTnEHV12H_nG1fQFFCfc7Q1Twjg)

The GIF above displays the following sorting 50 random numbers (1-100)
1) Bubble Sort 
    - Average speed: O( n^2 )
    - Average memory: O( 1 )
2) Merge Sort 
    - Average speed: O( n logn )
    - Average memory: O( n )
3) Quick Sort O( n logn )
    - Average speed: O( n logn )
    - Average memory: O( logn )

Of the three, quick sort is often seen as the best because it is more practical with it requiring less memory and having a better cache performance. Merge sort is prefered when stability is needed.

### Things to note

- [GLFW 3 Setup](https://www.glfw.org/docs/3.3/quick.html)
- [GLFW 3 Download](https://www.glfw.org/download)


Example build file for VS Code
```
{
	"version": "2.0.0",
	"tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: clang++ build active file",
            "command": "/usr/bin/clang++",
            "args": [
                "-std=c++17",
                "-fcolor-diagnostics",
                "-fansi-escape-codes",
                "-Wall",
                "-g",
                "-I${workspaceFolder}/dependencies/include",
                "-I${workspaceFolder}/dependencies/library",
                "${workspaceFolder}/src/*.cpp",
                "${workspaceFolder}/src/algorithms/*.cpp",
                "${workspaceFolder}/dependencies/library/libglfw.3.4.dylib",
                "-o",
                "${workspaceFolder}/app",
                "-framework",
                "OpenGL"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "compiler: /usr/bin/clang++"
        }
    ]
}

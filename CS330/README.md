# CS-330 Final Project: 3D Hammer on Table Scene

This directory  contains my final project for SNHU CS-330 Computational Graphics and Visualization. It's a simple OpenGL 3D scene built in C++: a claw hammer resting on a wooden table, on a textured floor. The hammer is a composite made from basic shapes (tapered cylinder handle, box head, tapered cylinders for claws, tapered cylinder striking body, sphere face, cylinder collar), with textures (wood, rusty/corrugated metal) and Phong lighting (directional + colored point light). Camera navigation uses WASD/QE, mouse look, scroll for speed, and O/P to toggle perspective/ortho views.

## How do I approach designing software?

I approach software design by breaking problems into small, testable pieces and iterating quickly. Start with requirements (here, rubric criteria like 4+ shapes, textures, lights, navigation), then prototype one part at a time (e.g., get a single shape rendering, then add transformations, then texture, then light).

- **New design skills from this project**: I got better at modular design—using separate functions like SetTransformations() for every object and RenderScene() to organize drawing. This made adding or tweaking parts easier without breaking everything. Also, thinking in 3D space (positions, rotations, scales) forced me to plan object relationships upfront.

- **Design process followed**: I followed the milestone structure: proposal → basic shapes → interactivity → texturing → lighting → final polish. Each milestone built on the last, with feedback incorporated. I kept it simple to avoid "shape creep" since I'm not naturally visual-creative—this class pushed me to try anyway.

- **Applying tactics in future work**: The modular approach (separate concerns like view/camera, scene rendering, shaders) works for any larger program. Breaking big tasks into iterations with frequent testing will help in future projects, especially when deadlines are tight.

## How do I approach developing programs?

I develop by building incrementally: code a small feature, compile, run, fix, commit/save, repeat. This project was almost all microsteps—build, run in Codio (or locally when possible), tweak, repeat.

- **New development strategies used**: Frequent local commits/saves + constant compile/run cycles. Without these, bugs in transformations or shaders would have piled up. Also, using GLM for math (vectors/matrices) made positioning and rotations reliable instead of guessing.

- **How iteration factored in**: Iteration was everything. I constantly felt like I was building, compiling, running over and over. Each small change (e.g., adjust light position, fix UV scale, rotate a claw) got tested immediately. This kept momentum and prevented big failures late.

- **How my approach evolved through milestones**: Early on, I focused on getting things to appear at all. By later milestones, I was more deliberate—planning transformations before coding, reusing functions, and testing lighting across the whole scene. The progression from basic shapes to a complete interactive scene showed me how steady small wins add up.

## How can computer science help me in reaching my goals?

This class gave me practical skills in 3D graphics and reinforced core CS ideas.

- **In future educational pathway**: Computational graphics introduced OpenGL for the first time and refreshed C++ (pointers, classes, GLM). It showed how deeply CS is rooted in math—vectors, matrices, trig for rotations/lighting. Even if I'm not a math expert, knowing these functions builds intuition for many programming problems, especially rendering ones. This helps in advanced CS courses involving graphics, simulation, or data viz.

- **In future professional pathway**: 3D skills apply to game dev, 3D printing prep, technical visualization, or even UI/AR prototyping. The freedom in this class—code must run bug-free, but creative choices (shapes, textures, lighting) are flexible—was refreshing compared to stricter courses. While it didn't add tons of general dev strategies, mastering OpenGL basics opens doors to engines like Unity/Unreal. Plus, understanding how visuals are built computationally is useful anywhere data or concepts need clear presentation.

Overall, the project was simple but enjoyable. Pushing past my lack of natural visual creativity felt good, and the iterative process made finishing possible.


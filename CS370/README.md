# Project Two: Deep Q-Learning Pirate Agent for Treasure Hunt

## Project Overview
This project implements an intelligent agent (the pirate) that learns to navigate an 8x8 maze to find the treasure using **deep Q-learning (DQN)**. The agent must reach the goal while maximizing reward and avoiding obstacles, demonstrating core reinforcement learning concepts in a grid-based pathfinding environment.

### Code Breakdown
**Code provided (starter files – not modified):**
- `TreasureMaze.py`: Defines the environment, including the maze layout, movement rules, reward system, state observation, and visualization.
- `GameExperience.py`: Implements the experience replay buffer for storing and sampling transitions.
- Notebook starter code: `build_model()`, `play_game()`, `completion_check()`, `train_step()`, and the `qtrain()` skeleton with pseudocode.

**Code I created:**
- The complete `qtrain()` function implementing the full deep Q-learning loop:
  - Random starting positions for generalization
  - ε-greedy action selection using `valid_actions()` for safe exploration
  - Experience storage and minibatch sampling
  - Training with a target network for stability
  - Win tracking, gradual ε decay, logging, and early stopping via `completion_check()`

The final agent reliably reaches the treasure from any starting position with 100% success after training.

### Connecting Course Learning to Computer Science

Computer scientists design algorithms and systems to solve complex problems efficiently and responsibly. This work matters because it powers everything from recommendation systems and autonomous vehicles to scientific discovery and medical tools—ultimately shaping how technology impacts society.

As a computer scientist, I approach problems by first understanding the requirements (here: pathfinding with sparse rewards), breaking them into components (states, actions, rewards, policy), selecting appropriate tools (DQN for high-dimensional states), implementing iteratively, testing rigorously (completion_check across all starts), and evaluating trade-offs (exploration vs. exploitation, stability vs. speed).

My ethical responsibilities include:
- To the **end user**: Ensuring the system is reliable and safe. In this project, poor training could lead to the pirate getting stuck or inefficient paths—mirroring real-world risks where flawed AI causes harm (e.g., navigation failures in robotics).
- To the **organization**: Delivering maintainable, scalable code with clear documentation and best practices (comments, modular design, proper target network usage). I also consider broader impacts, such as the environmental cost of training and the need for transparency about AI limitations.


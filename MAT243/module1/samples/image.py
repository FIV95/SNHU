import matplotlib.pyplot as plt

# Create a figure with 4 subplots (1 row, 4 columns)
fig, (ax1, ax2, ax3, ax4) = plt.subplots(1, 4, figsize=(20, 5))

# Plot 1: Original single line plot (blue solid line)
ax1.plot([1, 2, 3], [4, 5, 6], label='Original Line')
ax1.set_title('Original Plot')
ax1.set_xlabel('X')
ax1.set_ylabel('Y')
ax1.legend()

# Plot 2: Dashed blue line
ax2.plot([1, 2, 3], [4, 5, 6], 'b--', label='Line 1')
ax2.set_title('Plot 1 - Dashed Blue')
ax2.set_xlabel('X')
ax2.set_ylabel('Y')
ax2.legend()

# Plot 3: Red line with circles
ax3.plot([1, 2, 3], [6, 5, 4], 'r-o', label='Line 2')
ax3.set_title('Plot 2 - Red Circles')
ax3.set_xlabel('X')
ax3.set_ylabel('Y')
ax3.legend()

# Plot 4: Green triangles with line
ax4.plot([1, 2, 3], [3, 6, 2], 'g^-', label='Line 3')
ax4.set_title('Plot 3 - Green Triangles')
ax4.set_xlabel('X')
ax4.set_ylabel('Y')
ax4.legend()

# Adjust layout to prevent overlap
plt.tight_layout()

# Save as a high-resolution PDF (for previewing with ImageMagick)
plt.savefig("plot.pdf", dpi=300, bbox_inches="tight")
plt.close()
ax1.plot([1, 2, 3], [4, 5, 6], 'b--', label='Line 1')  # Dashed blue line
ax2.plot([1, 2, 3], [6, 5, 4], 'r-o', label='Line 2')  # Red line with circles
ax3.plot([1, 2, 3], [3, 6, 2], 'g^-', label='Line 3')

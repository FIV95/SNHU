import matplotlib.pyplot as plt

# Force Jupyter-compatible inline backend
plt.switch_backend("module://matplotlib_inline.backend_inline")

plt.plot([1, 2, 3], [4, 5, 6])
plt.show()


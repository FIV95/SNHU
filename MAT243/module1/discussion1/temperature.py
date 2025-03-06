import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import random
import os
import sys

# Ensure the output directory exists
output_dir = "/home/frankielaw/Documents/code/college/SHNU/MAT243/module1/discussion1"
os.makedirs(output_dir, exist_ok=True)
output_file = os.path.join(output_dir, "temperature.html")

# Open the file for the entire script
with open(output_file, "w", encoding="utf-8") as f:
    f.write("<html><body><pre>\n")

    # Redirect print output to the file
    original_stdout = sys.stdout  # Save original stdout
    sys.stdout = f  # Redirect stdout to file

    # Set non-interactive backend before any plotting
    plt.switch_backend("Agg")

    temperatures = [50, 36, 27, 52, 45, 52, 50, 54, 48, 39, 36, 27, 19, 25]
    temperatures_df = pd.DataFrame({"temperature": temperatures})

    print(temperatures_df)
    mean = temperatures_df["temperature"].mean()
    print("Mean=", round(mean, 2))
    median = temperatures_df["temperature"].median()
    print("Median=", round(median, 2))
    variance = temperatures_df["temperature"].var()
    print("Variance=", round(variance, 2))
    stdeviation = temperatures_df["temperature"].std()
    print("Standard Deviation=", round(stdeviation, 2))
    statistics = temperatures_df["temperature"].describe()
    print("")
    print("Describe method")
    print(statistics)

    # Plot 1: Line plot
    plt.figure(figsize=(10, 6))
    plt.plot(temperatures_df["temperature"])
    plt.title("Line plot of temperature data", fontsize=20)
    plt.xlabel("day")
    plt.ylabel("temperature")
    plot1_path = os.path.join(output_dir, "line_plot.png")
    plt.savefig(plot1_path, bbox_inches="tight")
    plt.close()  # Close the figure to free memory
    f.write(f'\n<img src="line_plot.png" alt="Line Plot">\n')

    # Zion temperatures
    mean = random.randint(int(temperatures_df["temperature"].min()), int(temperatures_df["temperature"].max()))
    std_deviation = random.randint(
        int(round(temperatures_df["temperature"].std(), 0)),
        int(round(2 * temperatures_df["temperature"].std(), 0)),
    )
    zion_temperatures = np.random.normal(mean, std_deviation, 25)
    zion_temperatures = pd.DataFrame(zion_temperatures, columns=["temperature"])  # type: ignore[reportArgumentType]

    # Concatenate for boxplot
    temperatures_df["id"] = "my_data"
    zion_temperatures["id"] = "zion_data"
    both_temp_df = pd.concat((temperatures_df, zion_temperatures))

    # Plot 2: Boxplot
    plt.figure(figsize=(10, 6))
    plt.title("Boxplot for comparison", fontsize=20)
    sns.boxplot(x="id", y="temperature", data=both_temp_df)
    plot2_path = os.path.join(output_dir, "boxplot.png")
    plt.savefig(plot2_path, bbox_inches="tight")
    plt.close()  # Close the figure
    f.write(f'\n<img src="boxplot.png" alt="Boxplot">\n')

    # Write closing tags
    f.write("\n</pre></body></html>")

    # Restore original stdout
    sys.stdout = original_stdout

print(f"Output saved to {output_file}")

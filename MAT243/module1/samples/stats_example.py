import statistics

# Sample data
data = [1, 2, 3, 4, 5, 6]

# Compute the mean and variance
mean_value = statistics.mean(data)
variance_value = statistics.variance(data)

# Print the results using f-strings
print(f"Mean: {mean_value}")
print(f"Variance: {variance_value}")

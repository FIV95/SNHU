import seaborn as sns

titanic = sns.load_dataset("titanic")

print(titanic.shape)
print(titanic.columns)
print()
print(titanic.dtypes)

# means of all numerical variables #

print(titanic.select_dtypes(include=(float, int)).mean())
print(titanic.select_dtypes(include=(float, int)).min())

titanic[["sex", "survived"]].head()

titanic[titanic.pclass == 3]
titanic.describe()

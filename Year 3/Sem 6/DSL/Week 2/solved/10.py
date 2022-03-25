import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_table("HR_for_Week2.txt")
print(df.head())
f = df["Department"].value_counts()
print(f)
f.plot(kind='bar')
plt.show()
f.plot(kind='pie')
plt.show()
fa = pd.crosstab(df['Gender'], df['Attrition'])
fa.plot(kind='bar')
plt.show()



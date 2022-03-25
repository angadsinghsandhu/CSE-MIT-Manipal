import pandas as pd
import numpy as np

dates = pd.date_range('20130101', periods=6)
df = pd.DataFrame(np.random.randn(6,4), index=dates, columns=list('ABCD'))
print(df.head())
df[df.A > 0]
print(df.head())
df['F'] = ['Male', 'Female', 'Female', 'Male', 'Female', 'Female']
print(df.head())
df.loc[:, 'D'] = np.array([5] * len(df))
print(df.head())
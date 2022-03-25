import pandas as pd
import numpy as np
dates = pd.date_range('20130101', periods=6)
df = pd.DataFrame(np.random.randn(6,4), index=dates, columns=list('ABCD'))
print(df.head())
df.drop ('A', axis =1, inplace=True)
print(df.head())
df.drop(pd.Timestamp('20130105'), axis=0, inplace=True)
print(df.head())
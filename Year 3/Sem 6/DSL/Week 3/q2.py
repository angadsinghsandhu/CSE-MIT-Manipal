import pandas as pd


df = pd.DataFrame({'a': [10,20],'b':[100,200]})

df.loc['Column_Total']= df.sum(numeric_only=True, axis=0)
df.loc[:,'Row_Total'] = df.sum(numeric_only=True, axis=1)

print(df)

import pandas as pd
import numpy as np
df1=pd.DataFrame({'A':pd.Timestamp('20130102'),'B':np.array([3]*4,dtype='int32'),
'C':pd.Categorical(['Male','Female','Male','Female'])})
print(df1.shape)
print(df1.dtypes)
print(df1.head())
print(df1.tail())
print(df1.describe())
print(df1.T)
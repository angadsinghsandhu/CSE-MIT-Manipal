import pandas as pd
import numpy as np

dates=pd.date_range('20130101', periods=100)
df = pd.DataFrame(np.random.randn(100,4), index=dates, columns=list('ABCD'))

#To view first 5 records
print(df.head())

#To view last 5 records
print((df.tail()))

#To view the index
print(df.index)

#To view the column names
print(df.columns)

#To transpose the df
print(df.T.head())

#Sorting by Axis
print(df.sort_index(axis=1, ascending=False).head())

#Sorting by Values
print(df.sort_values(by='B').head())

#Slicing the rows
print(df[0:3]) #which slice first 3 records (rows)

#Slicing with index name
print(df['20130105':'20130110'])

#Slicing with row and column index (like 2D Matrix)
print(df.iloc[0])# will fetch entire 1 st row
print(df.iloc[0,:2])# will fetch 1 st row, first 2 columns
print(df.iloc[0,0])# will fetch 1 st row, 1 st column element (single element)

#Selecting a single column
print(df['A'].head())# which yields a Series

#Selecting more than one column
print(df[['A','B']].head())# entire 2 columns

#Selecting more than one column, with selected number of records
print(df[['A','B']][:5])# first 5 records
print(df.loc['20130101':'20130105',['A','B']][:5].head())# first 5 records
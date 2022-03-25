import pandas as pd
import numpy as np

student = {
    "Name" : "Angad",
    "Height" : "185cm",
    "Qualification" : "B.Tech CSE",
}

add = ["Gurgaon"]    # age list
df = pd.DataFrame(student, index=[0])
df['Address'] = add
print(df)
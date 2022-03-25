import pandas as pd

student = {
    "Name" : "Angad",
    "Height" : "185cm",
    "Qualification" : "B.Tech CSE",
}

df = pd.DataFrame(student, index=[0])
df.insert(3, "Address", "Gurgaon", allow_duplicates = False)
print(df)

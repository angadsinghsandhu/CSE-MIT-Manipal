Q1
cat data/heart_disease_data.csv | python Q1/mapper.py | sort | python Q1/reduce.py > Q1/heart_out.txt
cat data/covid_19_data.csv | python Q1/mapper.py | sort | python Q1/reduce.py > Q1/covid_out.txt
cat data/example.csv | python Q1/mapper.py | sort | python Q1/reduce.py > Q1/example_out.txt
cat data/german_credit.csv | python Q1/mapper.py | sort | python Q1/reduce.py > Q1/german_out.txt

Q2
cat data/heart_disease_data.csv | python Q2/freqmap1.py | sort | python Q2/freqred1.py | python Q2/freqmap2.py | sort | python Q2/freqred2.py > Q2/heart_out.txt
cat data/covid_19_data.csv | python Q2/freqmap1.py | sort | python Q2/freqred1.py | python Q2/freqmap2.py | sort | python Q2/freqred2.py > Q2/covid_out.txt
cat data/example.csv | python Q2/freqmap1.py | sort | python Q2/freqred1.py | python Q2/freqmap2.py | sort | python Q2/freqred2.py > Q2/example_out.txt
cat data/german_credit.csv | python Q2/freqmap1.py | sort | python Q2/freqred1.py | python Q2/freqmap2.py | sort | python Q2/freqred2.py > Q2/german_out.txt

Q3
cat data/heart_disease_data.csv | python Q3/itemmap.py | sort | python Q3/itemred.py > Q3/heart_out.txt
cat data/covid_19_data.csv | python Q3/itemmap.py | sort | python Q3/itemred.py > Q3/covid_out.txt
cat data/example.csv | python Q3/itemmap.py | sort | python Q3/itemred.py > Q3/example_out.txt
cat data/german_credit.csv | python Q3/itemmap.py | sort | python Q3/itemred.py > Q3/german_out.txt

Q4
cat data/heart_disease_data.csv | python Q4/sepmap.py "->" | sort | python Q4/sepred.py "->" > Q4/heart_out.txt
cat data/covid_19_data.csv | python Q4/sepmap.py "->" | sort | python Q4/sepred.py "->" > Q4/covid_out.txt
cat data/example.csv | python Q4/sepmap.py "->" | sort | python Q4/sepred.py "->" > Q4/example_out.txt
cat data/german_credit.csv | python Q4/sepmap.py "->" | sort | python Q4/sepred.py "->" > Q4/german_out.txt

Q5
cat data/heart_disease_data.csv | python Q5/costmap.py | sort | python Q5/costred.py > Q5/heart_out.txt
cat data/covid_19_data.csv | python Q5/costmap.py | sort | python Q5/costred.py > Q5/covid_out.txt
cat data/example.csv | python Q5/costmap.py | sort | python Q5/costred.py > Q5/example_out.txt
cat data/german_credit.csv | python Q5/costmap.py | sort | python Q5/costred.py > Q5/german_out.txt

Q7
cat Q7/rand_nums.txt | python Q7/mapper.py | sort | python Q7/reduce.py
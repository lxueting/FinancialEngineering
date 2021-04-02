import pandas as pd
import numpy as np

class BinomSRate:   #binomial lattice for the short rates (aka risk free rates)

    def __init__ (self, r, q, u, d, t):
        self.r = r              #risk free rate 
        self.q = q              #risk neutral probability
        self.u = u              #multiple of the up-move
        self.d = d              #multiple of the down-move
        self.t = t              #time period of the fixed income asset
        
    def n_arrays(self):         #create n number of arrays, from n time periods
        t = self.t
        dataframe = [[] for rows in range(t+1)]
        return dataframe

    def calc_rates_d_only(self):    #calculating first line 
        t = self.t
        r = self.r
        d = self.d 
        output_d_only = [r]             
        for i in range(1,t+1):
            r = r*d                      #rate of r
            output_d_only.append(r)
        output_d_only = list(np.around(np.array(output_d_only), 4))   #convert this to a numpy array and round to 4 decimal places but keep it as a list
        return output_d_only

    def upward_mult(self, table):
        t = self.t
        r = self.r
        u = self.u
        d = self.d
        for i in range(1, t+1):
            table[i] = [x*u/d for x in table[i-1]]
            for n in range(i):
                table[i][n] = np.nan
            

    
#initialization
time = int(input("What time period: "))
rate = float(input("What is the short rate?: "))
upward_factor = 1.1 #float(input("What is the upward factor?: "))
downward_factor = 1 / upward_factor


# for calling methods from class and creating dataframe
myClass = BinomSRate(rate, 0.5, upward_factor, downward_factor, time) 
table1 = myClass.n_arrays()
table1[0] = myClass.calc_rates_d_only()
myClass.upward_mult(table1)




#setting up height and width and printing out and replacing NaN dataframe
length_table = max(map(len, table1))            
df = np.array([i + [" "] * (length_table-len(i)) for i in table1])
df = pd.DataFrame(df.reshape(-1, time + 1)).sort_index(ascending=False)
df = df.replace(np.nan, '', regex=True)
print(df)





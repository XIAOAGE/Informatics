# data analysis and wrangling
import pandas as pd
import numpy as np
import random as rnd

# visualization
import seaborn as sns
import matplotlib.pyplot as plt
%matplotlib inline

# machine learning
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC, LinearSVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.linear_model import Perceptron
from sklearn.linear_model import SGDClassifier
from sklearn.tree import DecisionTreeClassifier

train_df = pd.read_csv('./train.csv')
test_df = pd.read_csv('./test.csv')
combine = [train_df, test_df]

train_df = train_df.drop(['Ticket', 'Cabin'], axis=1)
test_df = test_df.drop(['Ticket', 'Cabin'], axis=1)
combine = [train_df, test_df]

for dataset in combine:
    dataset['Title'] = dataset.Name.str.extract(' ([A-Za-z]+)\.', expand=False)

for dataset in combine:
    dataset['Title'] = dataset['Title'].replace(['Lady', 'Countess','Capt', 'Col',\
 	'Don', 'Dr', 'Major', 'Rev', 'Sir', 'Jonkheer', 'Dona'], 'Rare')

    dataset['Title'] = dataset['Title'].replace('Mlle', 'Miss')
    dataset['Title'] = dataset['Title'].replace('Ms', 'Miss')
    dataset['Title'] = dataset['Title'].replace('Mme', 'Mrs')

title_mapping = {"Mr": 1, "Miss": 2, "Mrs": 3, "Master": 4, "Rare": 5}
for dataset in combine:
    dataset['Title'] = dataset['Title'].map(title_mapping)
    dataset['Title'] = dataset['Title'].fillna(0)

train_df = train_df.drop(['Name', 'PassengerId'], axis=1)
test_df = test_df.drop(['Name'], axis=1)
combine = [train_df, test_df]

for dataset in combine:
    dataset['Sex'] = dataset['Sex'].map( {'female': 1, 'male': 0} ).astype(int)

guess_ages = np.zeros((2,3))

for dataset in combine:
    for i in range(0, 2):
        for j in range(0, 3):
            guess_df = dataset[(dataset['Sex'] == i) & \
                                  (dataset['Pclass'] == j+1)]['Age'].dropna()

            # age_mean = guess_df.mean()
            # age_std = guess_df.std()
            # age_guess = rnd.uniform(age_mean - age_std, age_mean + age_std)

            age_guess = guess_df.median()

            # Convert random age float to nearest .5 age
            guess_ages[i,j] = int( age_guess/0.5 + 0.5 ) * 0.5

    for i in range(0, 2):
        for j in range(0, 3):
            dataset.loc[ (dataset.Age.isnull()) & (dataset.Sex == i) & (dataset.Pclass == j+1),\
                    'Age'] = guess_ages[i,j]

    dataset['Age'] = dataset['Age'].astype(int)

train_df['AgeBand'] = pd.cut(train_df['Age'], 5)

for dataset in combine:
dataset.loc[ dataset['Age'] <= 16, 'Age'] = 0
dataset.loc[(dataset['Age'] > 16) & (dataset['Age'] <= 32), 'Age'] = 1
dataset.loc[(dataset['Age'] > 32) & (dataset['Age'] <= 48), 'Age'] = 2
dataset.loc[(dataset['Age'] > 48) & (dataset['Age'] <= 64), 'Age'] = 3
dataset.loc[ dataset['Age'] > 64, 'Age']

train_df = train_df.drop(['AgeBand'], axis=1)
combine = [train_df, test_df]

for dataset in combine:
    dataset['FamilySize'] = dataset['SibSp'] + dataset['Parch'] + 1

for dataset in combine:
    dataset['IsAlone'] = 0
    dataset.loc[dataset['FamilySize'] == 1, 'IsAlone'] = 1

train_df = train_df.drop(['Parch', 'SibSp', 'FamilySize'], axis=1)
test_df = test_df.drop(['Parch', 'SibSp', 'FamilySize'], axis=1)
combine = [train_df, test_df]

for dataset in combine:
    dataset['Age*Class'] = dataset.Age * dataset.Pclass

freq_port = train_df.Embarked.dropna().mode()[0]

for dataset in combine:
    dataset['Embarked'] = dataset['Embarked'].fillna(freq_port)

for dataset in combine:
    dataset['Embarked'] = dataset['Embarked'].map( {'S': 0, 'C': 1, 'Q': 2} ).astype(int)

test_df['Fare'].fillna(test_df['Fare'].dropna().median(), inplace=True)
train_df['FareBand'] = pd.qcut(train_df['Fare'], 4)

for dataset in combine:
    dataset.loc[ dataset['Fare'] <= 7.91, 'Fare'] = 0
    dataset.loc[(dataset['Fare'] > 7.91) & (dataset['Fare'] <= 14.454), 'Fare'] = 1
    dataset.loc[(dataset['Fare'] > 14.454) & (dataset['Fare'] <= 31), 'Fare']   = 2
    dataset.loc[ dataset['Fare'] > 31, 'Fare'] = 3
    dataset['Fare'] = dataset['Fare'].astype(int)

train_df = train_df.drop(['FareBand'], axis=1)
combine = [train_df, test_df]

train_df.head(10)
test_df.head(10)















training_data = train_df.values
training_data = list(zip(training_data[:,1:], training_data[:,:1].reshape(891,1)))

def sigmoid(z):
    return 1.0 / (1.0 + np.exp(-z))

def sigmoid_prime(z):
    return sigmoid(z) * (1-sigmoid(z))

def vectorize(j):
    e = np.zeros((10, 1))
    e[j] = 1.0
    return e

class Network(object):

    def __init__(self, sizes):
        self.size = len(sizes)
        self.layers = sizes
        self.bias = [np.random.randn(y, 1) for y in sizes[1:]]
        self.weight = [np.random.randn(x, y)
                        for x, y in zip(sizes[1:], sizes[:-1])]

    def feedforward(self, a):
        for b, w in zip(self.bias, self.weight):
            a = sigmoid(np.dot(w, a) + b)
        return a

    def SGD(self, training_data, epochs, mini_batch_size, eta,
            test_data=None):
        n = len(training_data)
        for j in range(epochs):
            rnd.shuffle(training_data)
            mini_batches = [training_data[k:k+mini_batch_size]
                            for k in range(0, n, mini_batch_size)]
            for mini_batch in mini_batches:
                mini_batch = list(zip(*mini_batch))
                mini_batch_x = np.column_stack(mini_batch[0])
                mini_batch_y = np.column_stack(mini_batch[1])
                self.update_mini_batch((mini_batch_x, mini_batch_y), eta)
            print(str(self.evaluate(test_data))+" / "+str(len(test_data)))


    def update_mini_batch(self, mini_batch, eta):
        mini_batch_x = mini_batch[0]
        mini_batch_y = mini_batch[1]

        gradient_w, gradient_b = self.backprop(mini_batch_x, mini_batch_y)
        self.weight = [w-eta*nw
                        for w, nw in zip(self.weight, gradient_w)]
        self.bias = [b-eta*nb
                        for b, nb in zip(self.bias, gradient_b)]

    def backprop(self, x, y):
        gradient_w = [np.zeros(w.shape) for w in self.weight]
        gradient_b = [np.zeros(b.shape) for b in self.bias]
        batch_size = len(x[0])
        activations = [x]
        zs = []
        for w, b in zip(self.weight, self.bias):
            z = np.dot(w, x) + b
            zs.append(z)
            x = sigmoid(z)
            activations.append(x)

        deltaL = self.cost_derivative(x, y) * sigmoid_prime(zs[-1])
        gradient_b[-1] = np.sum(deltaL, axis=1, keepdims=True) * 1.0 / batch_size
        tmp_gradient_w = np.dot(deltaL, activations[-2].transpose())
        gradient_w[-1] = tmp_gradient_w * 1.0 / batch_size

        for l in range(2, self.size):
            deltaL = np.dot(self.weight[-l+1].transpose(), deltaL) * sigmoid_prime(zs[-l])
            gradient_b[-l] = np.sum(deltaL, axis=1, keepdims=True) * 1.0 / batch_size
            tmp_gradient_w = np.dot(deltaL, activations[-l-1].transpose())
            gradient_w[-l] =  tmp_gradient_w * 1.0 / batch_size

        return (gradient_w, gradient_b)


    def evaluate(self, test_data):
        result = [(self.feedforward(x), y)
                    for x, y in test_data]
        return sum(int(x == y) for x, y in result)

    def cost_derivative(self, output_activations, y):
        return (output_activations - y)

net = Network([8, 30, 1])
net.SGD(training_data, 30, 10, 3.0, test_data=training_data)

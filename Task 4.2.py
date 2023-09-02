import numpy as np
from sklearn.linear_model import LinearRegression

X_train = np.array([6.03, 36.18, 88.94, 102.51, 153.77, 197.4, 200.5, 212.56, 241.21, 286.43]).reshape(-1, 1)
y_train = np.array([0, 9.01, 22.93, 29.28, 47.57, 55.67, 64.55, 66.09, 73.94, 91.75])

model = LinearRegression()
model.fit(X_train, y_train)

target_shrinkage = 85
knob_adjustment = model.predict([[target_shrinkage]])[0]
print(f"The knob should be adjusted to: {knob_adjustment} MW")
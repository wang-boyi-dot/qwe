import tensorflow as tf
from tensorflow.keras.datasets import mnist
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Flatten
import time

# 加载数据
(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train = x_train / 255.0
x_test = x_test / 255.0

# 构建简单的神经网络
def build_model():
    model = Sequential([
        Flatten(input_shape=(28, 28)),
        Dense(128, activation='relu'),
        Dense(10, activation='softmax')
    ])
    model.compile(
        optimizer='adam',
        loss='sparse_categorical_crossentropy',
        metrics=['accuracy']
    )
    return model

# 训练函数
def train_model():
    model = build_model()
    start_time = time.time()
    model.fit(x_train, y_train, epochs=5, batch_size=32, verbose=1)
    end_time = time.time()
    return end_time - start_time

# 查看当前设备
print("当前设备：", tf.config.list_physical_devices())

# 训练并记录时间
training_time = train_model()
print(f"训练耗时：{training_time:.2f} 秒")

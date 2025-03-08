from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend

class MicCalculatorFrame:
    def __init__ (self, key):
        self.key = key

    def calculate_mic(self, frame_data, iv):
        cipher = Cipher(algorithms.AES(self.key), modes.CTR(iv), backend=default_backend())
        encryptor = cipher.encryptor()
        mic = encryptor.update(frame_data) + encryptor.finalize()
        return mic[:8]
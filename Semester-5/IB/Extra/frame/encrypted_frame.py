from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes


class EncryptedFrame:
    def __init__(self, encrypted_data, iv, frame_header, pn, mic=None):
        self.encrypted_data = encrypted_data
        self.iv = iv
        self.frame_header = frame_header
        self.pn = pn
        self.mic = mic

    def decrypt(self, key):
        cipher = Cipher(algorithms.AES(key), modes.CTR(self.iv), backend=default_backend())
        decrypter = cipher.decryptor()
        decrypted_data = decrypter.update(self.encrypted_data) + decrypter.finalize()
        return decrypted_data
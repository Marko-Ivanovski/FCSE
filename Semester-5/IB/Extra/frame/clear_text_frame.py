import os

from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes

from frame.encrypted_frame import EncryptedFrame
from frame.utils import split_data_into_blocks


class ClearTextFrame:
    def __init__(self, data, frame_header, pn):
        self.data = data
        self.frame_header = frame_header
        self.pn = pn

    def encrypt(self, key):
        iv = os.urandom(16)
        cipher = Cipher(algorithms.AES(key), modes.CTR(iv), backend=default_backend())
        encryptor = cipher.encryptor()

        encrypted_blocks = [encryptor.update(block) for block in split_data_into_blocks(self.data, 16)]
        encrypted_data = b''.join(encrypted_blocks)

        return EncryptedFrame(encrypted_data, iv, self.frame_header, self.pn)
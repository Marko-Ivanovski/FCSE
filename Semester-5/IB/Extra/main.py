import os

from frame import ClearTextFrame, MicCalculatorFrame

KEY = os.urandom(16)

def main():
    data = b'This is an encrypted message'
    frame_header = b'Frame Header'
    pn = 1

    clear_text_frame = ClearTextFrame(data, frame_header, pn) # Init Clear Text Frame
    mic_calculator_frame = MicCalculatorFrame(KEY) # Init Mic Calculator Frame
    frame_data_for_mic = frame_header + pn.to_bytes(4, 'big') + data # Init Frame Data for MIC calculation
    iv = os.urandom(16) # Init IV
    mic = mic_calculator_frame.calculate_mic(frame_data_for_mic, iv) # Calculate MIC

    encrypted_frame= clear_text_frame.encrypt(KEY)
    encrypted_frame.mic = mic

    print("Clear Data:")
    print(frame_header.hex(), pn, data.decode('utf-8'), sep=' | ')
    print("Encrypted Data:")
    print(frame_header.hex(), pn, encrypted_frame.encrypted_data.hex(), encrypted_frame.mic.hex(), sep=' | ')
    print()

    try:
        decrypted_data = encrypted_frame.decrypt(KEY).decode('utf-8')
        print("Decrypted Data: ", decrypted_data)

        received_mic = mic_calculator_frame.calculate_mic(frame_data_for_mic, iv)
        if received_mic == encrypted_frame.mic:
            print("MIC Verified: ", received_mic.hex())
        else:
            print("MIC Not Verified")

    except ValueError as e:
        print("Error: MIC Not Verified", e)

if __name__ == "__main__":
    main()
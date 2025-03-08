def split_data_into_blocks(data, block_size=16):
    return [data[i:i + block_size] for i in range(0, len(data), block_size)] # Splits data into blocks of 16 bytes
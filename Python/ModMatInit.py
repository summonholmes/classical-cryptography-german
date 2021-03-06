from numpy import zeros, count_nonzero
from ModMatIter import ModMatIter


def ModMatInit(key, key_ident, key_det_ext, alpha_len, matrix_len):
    if key_det_ext["gcd"] != 1:
        return zeros((matrix_len, matrix_len))
    else:
        key_ident = ModMatIter(key, key_ident, alpha_len, matrix_len)
        if count_nonzero(key_ident) == 0:
            return zeros((matrix_len, matrix_len))
        else:
            inverted_key = key_ident[:, matrix_len:(2 * matrix_len)]
            return inverted_key
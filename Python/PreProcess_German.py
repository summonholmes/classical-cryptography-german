from re import sub


def PreProcess_German(rawtext):
    return sub(r'[^\w\s]', '', (''.join(rawtext.split()))).lower()

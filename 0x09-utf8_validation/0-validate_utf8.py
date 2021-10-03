#!/usr/bin/python3
""" Utf8 validation """


def validUTF8(data):
    """ check if valid utf8 format """
    try:
        bytes([i & 255 for i in data]).decode("UTF-8")
        return True
    except Exception:
        return False

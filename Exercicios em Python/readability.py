import string

def main():
    text = input("Text: ")
    words = words_count(text)
    L = average_letters(text, words)
    S = average_sentences(text, words)
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index < 1:
        print("Before Grade 1")
    elif 1 <= index < 16:
        print(f"Grade {index}")
    else:
        print("Grade 16+")
def letters_count(txt):
    lower = list(string.ascii_lowercase)
    upper = list(string.ascii_uppercase)
    counter = 0
    for letter in lower:
        counter += txt.count(letter)
    for letter in upper:
        counter += txt.count(letter)
    return counter
def sentences_count(txt):
    counter = txt.count(".") + txt.count("!") + txt.count("?")
    return counter
def words_count(txt):
    return txt.count(" ") + 1
def average_letters(txt, w):
    letters = letters_count(txt)
    return round(letters / w * 100, 2)
def average_sentences(txt, w):
    sentences = sentences_count(txt)
    return round(sentences / w * 100, 2)
main()
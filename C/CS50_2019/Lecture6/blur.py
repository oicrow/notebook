from PIL import Image,  ImageFilter

# Open original image
before = Image.open("Lecture6\ChocolateChipCookies.jpg")

# Blur image
after = before.filter(ImageFilter.BLUR)
after.save("Lecture6\ChocolateChipCookies_blurred.jpg")
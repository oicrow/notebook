from PIL import Image,  ImageFilter

before = Image.open("cookie.bmp")
after = before.filter(ImageFilter.BLUR)
after.save("cookie.bmp")
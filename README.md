# CS50 Credit Card Checker

This program checks whether a credit card number is valid using **Luhn’s Algorithm**, and then identifies the card brand (AMEX, MASTERCARD, or VISA) based on its starting digits and length. This is the same task as the CS50 Problem Set "Credit".

---

## 🔍 What The Program Does

1. **Takes a credit card number** from the user.
2. **Applies Luhn’s Algorithm** to verify if the card number is mathematically valid.
3. If the card passes Luhn’s test, the program **checks the card brand** using known industry rules:
   - **AMEX** → 15 digits long, starts with **34** or **37**
   - **MASTERCARD** → 16 digits long, starts with **51–55**
   - **VISA** → 13 or 16 digits long, starts with **4**
4. Prints the result:
   - `AMEX`
   - `MASTERCARD`
   - `VISA`
   - or `INVALID`

---

## 🧠 What is Luhn’s Algorithm?

Luhn’s Algorithm is a checksum formula used to verify credit card numbers.

Steps:
1. Starting from the **rightmost digit**, move left.
2. **Double every second digit**.
3. If doubling gives a two-digit number (like 14), **add its digits** (i.e., 1 + 4 = 5).
4. Add all resulting numbers together.
5. If the **final sum ends in 0**, the card number is **valid**.

---

🎯 Sample Test Numbers
VISA	4111111111111111
VISA (13)	4222222222222
MASTERCARD	5555555555554444
AMEX	378282246310005
INVALID	1234567890123456
